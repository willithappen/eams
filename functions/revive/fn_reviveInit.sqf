#include "defines.inc"
params ["_value"];
if (allDisplays isEqualTo [findDisplay 0]) exitWith {};
//if !(isMultiplayer) exitWith {diag_log "EAMS ERROR: EAMS will not function outside of multiplayer"};
//_LIST OF PROJECTILES__
//[configFile >> "CfgAmmo" >> "TYPE", true] call BIS_FNC_ReturnParents;
//BulletBase --> Rifle/Pistol
//ShellBase --> NLAW/RocketLauncher
//GrenadeBase --> Grenade
//ignore damage under the threshold
//private _woundType = "";
//if (isNil "EAMS_ReviveEnabled") then {EAMS_ReviveEnabled = false};
eams_ReviveMode = EAMS_ReviveEnabled;
if !(eams_ReviveMode) exitWith {diag_log "EAMS RPT: Medical Not Enabled"};
diag_log format ["EAMS RPT: Medical Enabled at %1",diag_tickTime];
//Values for everything

eams_revive_duration = 120; // Revive Duration normal
eams_revive_medicSpeedMultiplier = 12; // 12x Normal Value
eams_revive_durationMedic = eams_revive_duration/eams_revive_medicSpeedMultiplier;
eams_revive_bleedOutDuration = 600; // 10 minute bleed out delay
eams_blood_volume_initial = 4750; //Represented as ml. Average person has between 4.5 and 5.5 litres of blood volume. Possibly randomize this?
eams_blood_volume_max = 5500; //Represented as ml. Average person has between 4.5 and 5.5 litres of blood volume. Possibly randomize this?
if (isServer) then {
	addMissionEventHandler ["EntityRespawned", {
	 params ["_entity", "_corpse"];
	 if !(isPlayer _entity) exitWith {};
	SET_STATE(_entity,STATE_RESPAWNED);
	}];
};
eams_fatalDamageGlobal = 9.55;
if (!hasInterface || {side player == sideLogic} || (typeOf player == "VirtualCurator_F")) exitWith {};

//Values for PLAYERS BELOW

if (isNull player) then {waitUntil{!isNull player}};
//Values for Player once player exists
[] call eams_fnc_reviveDamageReset;
EAMS_nearPlayers = [];
EAMS_IsInjured = false;
private _playerVar = GET_UNIT_VAR(player);
//_nearbyHandler = [{[] call eams_fnc_collectNearbyValues}, 1, [player]] call CBA_fnc_addPerFrameHandler;
player setVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
addMissionEventHandler ["eachFrame", {
	_lastFrame = missionNameSpace getVariable ["EAMS_TimeChecked",0];
	_timeAtFrame = parseNumber (diag_tickTime toFixed 1);
	if (_lastFrame == _timeAtFrame) exitWith {};
	missionNameSpace setVariable ["EAMS_TimeChecked",_timeAtFrame];
	_checkedTime = _timeAtFrame - 0.2;
	_computeVariable = format ["EAMS_ComputeHighest_%1",_checkedTime];
	_variable = player getVariable [_computeVariable,[]];
	if ((count _variable) > 0) then {
		_arrayDissect = _variable select 0;
		_damage = _arrayDissect select 0;
		_hit = _arrayDissect select 1;
		_projectile = _arrayDissect select 3;
		systemChat str (_arrayDissect);
		[_hit,_damage,_projectile] call EAMS_fnc_handleWounding;
	};
}];
/*--------------------------------------------------------------------------------------------------

	EVENT HANDLERS

--------------------------------------------------------------------------------------------------*/
#include "_eventHandlers_add.inc"
