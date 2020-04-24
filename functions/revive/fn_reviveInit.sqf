#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Initialize the Revive system on all machines.

	Returns:
	True if successful, false if not.
*/

#define DEBUG_LOG	bis_fnc_logFormat

//load "mode" but prioritize the server param
private _paramMode = missionNamespace getVariable["pams_reviveParam_mode",-100];
private _mode = if (_paramMode == -100) then {getMissionConfigValue ["PAMS_ReviveMode",REVIVE_MODE_DISABLED]} else {_paramMode};

//compatability fix for Revive2 settings (based on respawn templates)
if (_mode == REVIVE_MODE_DISABLED) then
{
	private _templates = [];

	{
		_templates append (getArray (missionConfigFile >> ("respawnTemplates" + _x)));
	}
	forEach ([""] + REVIVE_SIDES_TXT);

	if ({_x == "Revive"} count _templates > 0) then {_mode = REVIVE_MODE_AUTODETECT};
};

//exit if not in the multiplayer game
if (!IS_MP || {_mode == REVIVE_MODE_DISABLED}) exitWith {};

//[call] add public variable event handler (localy) to the given player
pams_fnc_reviveInitAddPlayer =
{
	if (!REVIVE_ENABLED(player)) exitWith {};

	private["_units","_unitVar","_xUnitVar"];

	if (isNil "pams_revive_handledUnits") then
	{
		pams_revive_handledUnits = [];
	};

	if (count _this == 0) then
	{
		_units = [] call bis_fnc_listPlayers;
	}
	else
	{
		_unitVar = param [0,"",[""]];
		_units = [missionNamespace getVariable [_unitVar,objNull]];

		private _state = (player getVariable [VAR_TRANSFER_STATE, STATE_RESPAWNED]) param [0, STATE_RESPAWNED, [123]];

		if (_state == STATE_INCAPACITATED) then		//we don"t know the STATE yet, need to use VAR_TRANSFER_STATE
		{
			//["[x] Incapacitated unit "%1" will NOT collide with JIPed unit "%2".",player,_unitVar] call DEBUG_LOG;

			player disableCollisionWith GET_UNIT(_unitVar);
		};
	};

	_units = _units - [player,objNull];

	{
		_xUnitVar = _x call bis_fnc_objectVar;

		if !(_xUnitVar in pams_revive_handledUnits) then
		{
			pams_revive_handledUnits pushBackUnique _xUnitVar;

			//add event handler for monitoring player"s state by other players
			VAR_TRANSFER_STATE addPublicVariableEventHandler [_x,
			{
				_this call pams_fnc_reviveOnState;
			}];

			//add event handler for monitoring player"s "forcing respawn" flag by other players
			VAR_TRANSFER_FORCING_RESPAWN addPublicVariableEventHandler [_x,
			{
				_this call pams_fnc_reviveOnForcingRespawn;
			}];

			//add event handler for monitoring player"s "being revived" flag by other players
			VAR_TRANSFER_BEING_REVIVED addPublicVariableEventHandler [_x,
			{
				_this call pams_fnc_reviveOnBeingRevived;
			}];
		};
	}
	forEach _units;
};

//[call] remove player from array of handled units
pams_fnc_reviveInitRemovePlayer =
{
	private _t = diag_tickTime + 5;
	private _disconnected = param [0,"",[""]];

	waitUntil{!isNil "pams_revive_handledUnits" || {diag_tickTime > _t}};

	//["[ ] Un-registered disconnected unit: %1",_disconnected] call DEBUG_LOG;

	if !(isNil "pams_revive_handledUnits") then
	{
		pams_revive_handledUnits = pams_revive_handledUnits - [_disconnected];
	};

	if !(isNil "pams_revive_incapacitatedUnits") then
	{
		pams_revive_incapacitatedUnits = pams_revive_incapacitatedUnits - [_disconnected];
	};
	if !(isNil "pams_revive_unstableUnits") then
	{
		pams_revive_unstableUnits = pams_revive_unstableUnits - [_disconnected];
	};

	missionNamespace setVariable [_disconnected, nil];
};

if (isServer) then
{
	//["[ ] CLEARING DEBUGVIEW: %1","DBGVIEWCLEAR"] call DEBUG_LOG;

	//handle disconnect
	addMissionEventHandler ["HandleDisconnect",
	{
		_playerVar = [_this select 0] call bis_fnc_objectVar;
		[_playerVar] remoteExec ["pams_fnc_reviveInitRemovePlayer"];
	}];
};

//exit if dedicated server, headless client or spectator detected
if (!hasInterface || {side player == sideLogic}) exitWith {};

//make sure player exists
if (isNull player) then {waitUntil{!isNull player}};

//exit if spectator is detected
if (side player == sideLogic) exitWith {};

//autodetect individual settings; Revive2 compatability feature
if (_mode == REVIVE_MODE_AUTODETECT) then
{
	//check global respawn templates
	private _templates = getArray (missionConfigFile >> "respawnTemplates");
	if ({_x == "Revive"} count _templates > 0) exitWith {_mode = REVIVE_MODE_ENABLED_ALL_PLAYERS};

	//not in global respawn templates, it needs to be in the side specific respawn templates
	_mode = REVIVE_MODE_ENABLED_INDIVIDUAL_PLAYERS;

	//check side specific respawn templates
	private _sideIndex = REVIVE_SIDES find (side player);
	if (_sideIndex == -1) exitWith {};
	private _sideTxt = REVIVE_SIDES_TXT select _sideIndex;
	_templates = getArray (missionConfigFile >> ("respawnTemplates" + _sideTxt));
	if ({_x == "Revive"} count _templates > 0) exitWith {ENABLE_REVIVE(player,true)};
};

//enable revive for player if its enabled globaly
if (_mode == REVIVE_MODE_ENABLED_ALL_PLAYERS) then
{
	ENABLE_REVIVE(player,true);
};

if (!REVIVE_ENABLED(player)) exitWith {/*["[ ] Revive is NOT enabled for player: %1",player] call DEBUG_LOG;*/};

//["[ ] Revive is enabled for player: %1",player] call DEBUG_LOG;

//get unique player variable
private _playerVar = GET_UNIT_VAR(player);

//global variables used in the system locally (not broadcasted)
pams_revive_handledUnits = [];					//variable names of units covered by the revive system; units with disabled revive excluded
//pams_revive_incapacitatedUnits = [];				//variable names of units that are waiting for revive
//pams_revive_unstableUnits = [];						//variable names of units waiting to be stabilized
pams_revive3d_unitsToProcess = [];				//variable names of units that need to be pre-processed for draw 3d
pams_revive3d_unitsPreprocessed = [];				//variable names of units that were preprocessed for draw 3d
pams_revive3d_fadeMult = ICON_ALPHA / (ICON_VISIBLE_RANGE_MAX - ICON_VISIBLE_RANGE);

//create PP effects
pams_revive_ppColor = ppEffectCreate ["ColorCorrections", 1632];
pams_revive_ppVig = ppEffectCreate ["ColorCorrections", 1633];
pams_revive_ppBlur = ppEffectCreate ["DynamicBlur", 525];

//detect difficulty settings
pams_revive_3rdPersonViewAllowed = (difficultyOption "thirdPersonView") == 1;

//init missin specific revive settings
pams_revive_mode = _mode;
pams_revive_requiredTrait = if ((missionNamespace getVariable["pams_reviveParam_requiredTrait",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveRequiredTrait",0]} else {missionNamespace getVariable["pams_reviveParam_requiredTrait",-100]};
pams_revive_requiredItems = if ((missionNamespace getVariable["pams_reviveParam_requiredItems",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveRequiredItems",0]} else {missionNamespace getVariable["pams_reviveParam_requiredItems",-100]};

pams_revive_medicSpeedMultiplier = if ((missionNamespace getVariable["pams_reviveParam_medicSpeedMultiplier",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveMedicSpeedMultiplier",2]} else {missionNamespace getVariable["pams_reviveParam_medicSpeedMultiplier",-100]};
pams_revive_unconsciousStateMode = if ((missionNamespace getVariable["pams_reviveParam_unconsciousStateMode",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveUnconsciousStateMode",0]} else {missionNamespace getVariable["pams_reviveParam_unconsciousStateMode",-100]};
pams_revive_duration = if ((missionNamespace getVariable["pams_reviveParam_duration",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveDelay",DEFAULT_REVIVE_TIME]} else {missionNamespace getVariable["pams_reviveParam_duration",-100]};
pams_revive_bleedOutDuration = if ((missionNamespace getVariable["pams_reviveParam_bleedOutDuration",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveBleedOutDelay",DEFAULT_BLEEDOUT_TIME]} else {missionNamespace getVariable["pams_reviveParam_bleedOutDuration",-100]};
pams_revive_forceRespawnDuration = if ((missionNamespace getVariable["pams_reviveParam_forceRespawnDuration",-100]) == -100) then {getMissionConfigValue ["PAMS_ReviveForceRespawnDelay",DEFAULT_FORCE_RESPAWN_TIME]} else {missionNamespace getVariable["pams_reviveParam_forceRespawnDuration",-100]};

if (pams_revive_forceRespawnDuration <= 0) then {pams_revive_forceRespawnDuration = DEFAULT_FORCE_RESPAWN_TIME};
if (pams_revive_bleedOutDuration <= 0) then {pams_revive_bleedOutDuration = DEFAULT_BLEEDOUT_TIME};
if (pams_revive_duration <= 0) then {pams_revive_duration = DEFAULT_REVIVE_TIME};
pams_revive_durationMedic = pams_revive_duration / pams_revive_medicSpeedMultiplier;

//init & reset damage data
[] call pams_fnc_reviveDamageReset;

//register everyone localy to player
[] call pams_fnc_reviveInitAddPlayer;

//register player to everyone ingame
[_playerVar] remoteExec ["pams_fnc_reviveInitAddPlayer"];

//setup other players localy for JIPing player; didJIP condition removed to make the code more robust
{
	private _xUnit = GET_UNIT(_x);

	[VAR_TRANSFER_STATE, _xUnit getVariable [VAR_TRANSFER_STATE, STATE_RESPAWNED], _xUnit] call pams_fnc_reviveOnStateJIP;
	[VAR_TRANSFER_FORCING_RESPAWN, _xUnit getVariable [VAR_TRANSFER_FORCING_RESPAWN, false], _xUnit] call pams_fnc_reviveOnForcingRespawn;
	[VAR_TRANSFER_BEING_REVIVED, _xUnit getVariable [VAR_TRANSFER_BEING_REVIVED, false], _xUnit] call pams_fnc_reviveOnBeingRevived;
}
forEach pams_revive_handledUnits;


/*--------------------------------------------------------------------------------------------------

	KILL-FEED

--------------------------------------------------------------------------------------------------*/
pams_revive_killfeedShow = false;
pams_revive_hudLocked = isArray (missionConfigFile >> "showHUD");

[] spawn
{
	sleep 1;

	pams_revive_killfeedShow = [false,true] select (difficultyOption "deathMessages") && {shownHUD param [9,true]};

	//disable built-in death messages
	if (pams_revive_killfeedShow && !pams_revive_hudLocked) then
	{
		private _hud = shownHUD; _hud set [9, false]; showHUD _hud;
	};
};


/*--------------------------------------------------------------------------------------------------

	EVENT HANDLERS

--------------------------------------------------------------------------------------------------*/
#include "_eventHandlers_add.inc"

/*--------------------------------------------------------------------------------------------------

	ACE ACTIONS

--------------------------------------------------------------------------------------------------*/
#include "_addAction_stabilize.inc"
