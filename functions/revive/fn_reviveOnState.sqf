#include "defines.inc"
/*
	Author: willithappen - based on scripts by Jiri Wainar (Bohemia Interactive) and the ArmA 3 Revive System

	Description:
	Used to execute specific code localy on every client whenever unit"s state changes.

	Parameters:
		_this select 0: STRING - Variable that carries the state value over the network, defined by macro VAR_TRANSFER_STATE.
		_this select 1: SCALAR - State.
		_this select 2: OBJECT - Unit to set the status for.


	Returns:
	True if successful, false if not.

	States:
		#define STATE_RESPAWNED			0
		#define STATE_REVIVED			1
		#define STATE_INCAPACITATED		2
		#define STATE_DEAD				3
*/

//["[ ] %1",_this] call bis_fnc_logFormat;

private ["_unitVar","_statePrev","_playerVar","_source","_reason"];

private _state 	= param [1, STATE_RESPAWNED, [123,[]]];
private _unit  	= param [2, objNull, [objNull]];

if (isNull _unit) exitWith {};

_unitVar = GET_UNIT_VAR(_unit);
_playerVar = GET_UNIT_VAR(player);

//store previous state
_statePrev = GET_STATE(_unit);

//stop if state didn"t change
if (_statePrev == _state) exitWith {};

//set the actual state
_unit setVariable [VAR_STATE, _state];

switch (_state) do
{
	case STATE_INCAPACITATED:
	{
		private _sidePlayer = side group player;
		private _sideUnit = side group _unit;

		//flag player as being incapacitated
		_unit setVariable ["eams_revive_incapacitated", true];
		_unit setVariable ["eams_revive_unstable", true];
		_unit setVariable ["ACE_isUnconscious",true];
		//display "incapacitated" message in kill-feed

		if (local _unit) then
		{
			//apply unconscious state
			_unit setUnconscious true;
			_damageGrace = [_unit] spawn {params ["_unit"];_unit allowDamage false; uiSleep 1.5; _unit allowDamage true;};
			//prevent AI from shooting the unit
			AI_PROTECTION_ACTIVATE(_unit);


			//store player"s camera so we can restore it if player is revived
			player setVariable [VAR_CAMERA_VIEW,cameraView];

			// disable talking (direct)
			player setVariable ["tf_voiceVolume", 0, true];
			// mute hearing
			player setVariable ["tf_globalVolume", 0.3];
			// disable talking (radio)
			player setVariable ["tf_unable_to_use_radio", true];
			player setVariable ["ACE_isUnconscious",true];

			//start bleeding
			[_unitVar] call eams_fnc_reviveBleedOut;

			//disable player"s action menu
			{inGameUISetEventHandler [_x, "true"]} forEach ["PrevAction", "NextAction"];
		};

		//make unit play dead/unconscious animation in vehicles
		if (IN_VEHICLE(_unit)) then
		{
			_unit playAction "Unconscious";
		};
	};
	case STATE_DEAD:
	{
		//eams_revive_incapacitatedUnits = eams_revive_incapacitatedUnits - [_unitVar];
		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];

		//flag unit as being NOT incapacitated
		_unit setVariable ["eams_revive_incapacitated", false];
		_unit setVariable ["eams_revive_unstable", false];

		_unit setVariable ["ACE_isUnconscious",false];
		//init and show dead icon for everyone but player
		if (!local _unit) then
		{
			//init icon for everyone but player
			if (lifeState _unit != "INCAPACITATED") then
			{
				//[ICON_STATE_ADD, _unitVar] call eams_fnc_reviveIconControl;
			};

			//reset "being revived" and "forcing respawn" flags locally
			SET_BEING_REVIVED_LOCAL(_unit, false);
			SET_FORCING_RESPAWN_LOCAL(_unit, false);

		}
		else
		{
			//not bleeding
			eams_revive_bleeding = false;
			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			player setVariable ["tf_unable_to_use_radio", false];
			player setVariable ["ACE_isUnconscious",false];

			//reset "being revived" and "forcing respawn" flags
			if (IS_BEING_REVIVED(_unit)) then {SET_BEING_REVIVED(_unit, false);};
			if (IS_FORCING_RESPAWN(_unit)) then {SET_FORCING_RESPAWN(_unit, false);};
		};
	};
	case STATE_REVIVED:
	{
		if ((_statePrev == STATE_DEAD) || (_statePrev == STATE_REVIVED) || (_statePrev == STATE_RESPAWNED)) exitWith {};

		//eams_revive_incapacitatedUnits = eams_revive_incapacitatedUnits - [_unitVar];
		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];
		//flag unit as being NOT incapacitated
		_unit setVariable ["eams_revive_incapacitated", false];
		_unit setVariable ["eams_revive_unstable", false];
		_unit setVariable ["ACE_isUnconscious",false];
		//display "revived" message in kill-feed; only if revived unit is friendly

		if (local _unit) then
		{
			systemChat str(_unit);
			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			player setVariable ["tf_unable_to_use_radio", false];
			player setVariable ["ACE_isUnconscious",false];
			//not bleeding
			eams_revive_bleeding = false;

			//remove unconscious state
			_unit setUnconscious false;

			//allow AI shooting the unit
			AI_PROTECTION_DEACTIVATE(_unit);

			//hotfix: revived while performing an action & playing animation
			_unit playAction "Stop";

			//hotfix: revived while having no weapon or binocular
			if ({currentWeapon player == _x} count ["",binocular player] > 0) then
			{
				[] spawn
				{
					sleep 0.1;
					if (({currentWeapon player == _x} count ["",binocular player] > 0) && {IS_ACTIVE(player)}) then {player playAction "Civil";};
				};
			};

			//reset blood level and stored bleed damage
			_unit setVariable [VAR_DAMAGE_BLEED, 0];
			//_unit setVariable [VAR_DAMAGE, 0];

			//reset "being revived" and "forcing respawn" flags
			if (IS_BEING_REVIVED(_unit)) then {SET_BEING_REVIVED(_unit, false);};
			if (IS_FORCING_RESPAWN(_unit)) then {SET_FORCING_RESPAWN(_unit, false);};

			//enable player"s action menu
			{inGameUISetEventHandler [_x, ""]} forEach ["PrevAction", "NextAction"];

			//restore player"s camera
			if (cameraView != (player getVariable [VAR_CAMERA_VIEW, "internal"])) then
			{
				[] spawn
				{
					titleCut ["","BLACK OUT",0.5];
					sleep 0.5;
					player switchCamera (player getVariable [VAR_CAMERA_VIEW, "internal"]);
					titleCut ["","BLACK IN",0.5];
				};
			};

			//ALWAYS heal to full
			[] call eams_fnc_reviveDamageReset;
		}
		else
		{
			//reset "being revived" and "forcing respawn" flags locally
			SET_BEING_REVIVED_LOCAL(_unit, false);
			SET_FORCING_RESPAWN_LOCAL(_unit, false);
		};
	};
	case STATE_STABILIZED:
	{
		if (_statePrev != STATE_INCAPACITATED) exitWith {};

		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];

		//flag unit as being NOT unstable
		_unit setVariable ["eams_revive_unstable", false];

		if (local _unit) then
		{
			//not bleeding
			eams_revive_bleeding = false;
			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			//player setVariable ["tf_unable_to_use_radio", false];
			//allow AI shooting the unit
			//WILL RE-ENABLE AT LATER TIME
			//AI_PROTECTION_DEACTIVATE(_unit);

			//reset blood level and stored bleed damage
			//_unit setVariable [VAR_DAMAGE_BLEED, 0];
			//_unit setVariable [VAR_DAMAGE, 0];

			//reset "stabilized flag"
			if (IS_BEING_STABILIZED(_unit)) then {IS_BEING_STABILIZED(_unit, false);};
		}
		else
		{
			//reset "being stabilized"
			SET_BEING_STABILIZED_LOCAL(_unit, false);
			//remove stabilize action
		};
	};
	case STATE_RESPAWNED:
	{
		//eams_revive_incapacitatedUnits = eams_revive_incapacitatedUnits - [_unitVar];
		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];
		//flag player as being NOT incapacitated
		_unit setVariable ["eams_revive_incapacitated", false];
		_unit setVariable ["eams_revive_unstable", false];

		if (local _unit) then
		{
			//allow AI shooting the unit
			AI_PROTECTION_DEACTIVATE(_unit);

			//reset death reason
			eams_revive_deathReason = DEATH_REASON_UNKNOWN;

			//not bleeding
			eams_revive_bleeding = false;

			//reset blood level and stored bleed damage
			_unit setVariable [VAR_DAMAGE_BLEED, 0];
			//_unit setVariable [VAR_DAMAGE, 0];

			//reset "being revived" and "forcing respawn" flags
			if (IS_BEING_REVIVED(_unit)) then {SET_BEING_REVIVED(_unit, false);};
			if (IS_FORCING_RESPAWN(_unit)) then {SET_FORCING_RESPAWN(_unit, false);};

			//enable player"s action menu
			{inGameUISetEventHandler [_x, ""]} forEach ["PrevAction", "NextAction"];

			//remove user action
			private _actionID = _unit getVariable [VAR_ACTION_ID_RESPAWN,-1];
			if (_actionID != -1) then {[_unit,_actionID] call bis_fnc_holdActionRemove;};
			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			player setVariable ["tf_unable_to_use_radio", false];
			player setVariable ["ACE_isUnconscious",false];
			//reset wound data
			[] call eams_fnc_reviveDamageReset;
		}
		else
		{
			//reset "being revived" and "forcing respawn" flags locally
			SET_BEING_REVIVED_LOCAL(_unit, false);
			SET_FORCING_RESPAWN_LOCAL(_unit, false);
		};
	};
	default
	{
	};
};
