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
		_unit setVariable ["ACE_isUnconscious",true,true];
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
			player setVariable ["ACE_isUnconscious",true,true];

			//start bleeding
			[player] call eams_fnc_reviveBleedOut;

			//disable player"s action menu
			{inGameUISetEventHandler [_x, "true"]} forEach ["PrevAction", "NextAction"];
		};

		//make unit play dead/unconscious animation in vehicles
		if (IN_VEHICLE(_unit)) then
		{
			_unit switchAction "Unconscious";
			if ((vehicle player != player) && (getDammage vehicle player == 1)) then {moveOut player};
		};
	};
	case STATE_DEAD:
	{
		//eams_revive_incapacitatedUnits = eams_revive_incapacitatedUnits - [_unitVar];
		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];

		//flag unit as being NOT incapacitated
		player setVariable ["eams_revive_incapacitated", false];
		player setVariable ["eams_revive_unstable", false];

		player setVariable ["ACE_isUnconscious",false,true];
		{inGameUISetEventHandler [_x, ""]} forEach ["PrevAction", "NextAction"];
		//init and show dead icon for everyone but player
			//not bleeding
			eams_revive_bleeding = false;
			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			player setVariable ["tf_unable_to_use_radio", false];
			player setVariable ["ACE_isUnconscious",false,true];
			AI_PROTECTION_DEACTIVATE(player);

	};
	case STATE_REVIVED:
	{
		if ((_statePrev == STATE_DEAD) || (_statePrev == STATE_REVIVED) || (_statePrev == STATE_RESPAWNED)) exitWith {};

		//eams_revive_incapacitatedUnits = eams_revive_incapacitatedUnits - [_unitVar];
		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];
		//flag unit as being NOT incapacitated
		_unit setVariable ["eams_revive_incapacitated", false];
		_unit setVariable ["eams_revive_unstable", false];
		_unit setVariable ["ACE_isUnconscious",false,true];
		//display "revived" message in kill-feed; only if revived unit is friendly
		AI_PROTECTION_DEACTIVATE(_unit);
		_unit switchMove "Stop";
		_unit switchMove "";
		if (local _unit) then
		{
			systemChat str(_unit);
			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			player setVariable ["tf_unable_to_use_radio", false];
			player setVariable ["ACE_isUnconscious",false,true];
			//not bleeding
			eams_revive_bleeding = false;

			//remove unconscious state
			_unit setUnconscious false;

			//allow AI shooting the unit
			AI_PROTECTION_DEACTIVATE(_unit);

			//hotfix: revived while performing an action & playing animation
			_unit switchMove "Stop";
			_unit switchMove "";

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

			//enable player"s action menu
			{inGameUISetEventHandler [_x, ""]} forEach ["PrevAction", "NextAction"];

			//ALWAYS heal to full
			[] call eams_fnc_reviveDamageReset;
		};
	};
	case STATE_STABILIZED:
	{
		if (_statePrev != STATE_INCAPACITATED) exitWith {};

		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];

		//flag unit as being NOT unstable
		_unit setVariable ["eams_revive_unstable", false];
		AI_PROTECTION_DEACTIVATE(_unit);
		if (local _unit) then {
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
			_unit setVariable [VAR_DAMAGE_BLEED, 0];
			//_unit setVariable [VAR_DAMAGE, 0];

		};
	};
	case STATE_RESPAWNED:
	{
		//eams_revive_incapacitatedUnits = eams_revive_incapacitatedUnits - [_unitVar];
		//eams_revive_unstableUnits = eams_revive_unstableUnits - [_unitVar];
		//flag player as being NOT incapacitated
		_unit setVariable ["eams_revive_incapacitated", false];
		_unit setVariable ["eams_revive_unstable", false];
		AI_PROTECTION_DEACTIVATE(_unit);
		if (local _unit) then
		{
			//allow AI shooting the unit

			//not bleeding
			eams_revive_bleeding = false;

			//reset blood level and stored bleed damage
			player setVariable [VAR_DAMAGE_BLEED, 0];
			//_unit setVariable [VAR_DAMAGE, 0];

			//enable player"s action menu
			{inGameUISetEventHandler [_x, ""]} forEach ["PrevAction", "NextAction"];

			// enable talking (direct)
			player setVariable ["tf_voiceVolume", 1, true];
			// unmute hearing
			player setVariable ["tf_globalVolume", 1];
			// enable talking (radio)
			player setVariable ["tf_unable_to_use_radio", false];
			player setVariable ["ACE_isUnconscious",false,true];
			//reset wound data
			[] call eams_fnc_reviveDamageReset;
			AI_PROTECTION_DEACTIVATE(player);
		};
	};
	default
	{
	};
};
