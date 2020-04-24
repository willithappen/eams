#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Used to execute state specific code localy on client that is JIPping.

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

private ["_unit","_state","_unitVar","_statePrev","_playerVar","_source"];

_state = param [1, STATE_RESPAWNED, [123,[]]];
_unit  = param [2, objNull, [objNull]];

if (isNull _unit) exitWith {false};

if (_state isEqualType []) then
{
	_source	= _state param [1, objNull, [objNull]];
	_state 	= _state param [0, STATE_RESPAWNED, [123]];
}
else
{
	_source	= objNull;
};

_unitVar = GET_UNIT_VAR(_unit);
_playerVar = GET_UNIT_VAR(player);

switch (_state) do
{
	case STATE_INCAPACITATED:
	{
		private["_sidePlayer","_sideUnit"];

		_sidePlayer = side group player;
		_sideUnit = side group _unit;

		//flag player as being incapacitated
		_unit setVariable ["pams_revive_incapacitated", true];
		_unit setVariable ["pams_revive_unstable", true];

		//init icon
		//[ICON_STATE_ADD, _unitVar] call pams_fnc_reviveIconControl;

		//update pool of incapacitated units
		if (_playerVar != _unitVar && {_sidePlayer getFriend _sideUnit > 0 && {_sideUnit getFriend _sidePlayer > 0}}) then
		{
			//pams_revive_incapacitatedUnits pushBackUnique _unitVar;
			//pams_revive_unstableUnits pushBackUnique _unitVar;
		};

		//show incapacitated icon for everyone but player
		//[ICON_STATE_INCAPACITATED, _unitVar] call pams_fnc_reviveIconControl;

		//create revive & secure actions
	};
	case STATE_DEAD:
	{
		//pams_revive_incapacitatedUnits = pams_revive_incapacitatedUnits - [_unitVar];
		//pams_revive_unstableUnits = pams_revive_unstableUnits - [_unitVar];

		//flag player as being NOT incapacitated and NOT unstable
		_unit setVariable ["pams_revive_incapacitated", false];
		_unit setVariable ["pams_revive_unstable", false];
		//reset "being revived" and "forcing respawn" flags
		SET_BEING_REVIVED_LOCAL(_unit, false);
		SET_FORCING_RESPAWN_LOCAL(_unit, false);

		//init icon
		//[ICON_STATE_ADD, _unitVar] call pams_fnc_reviveIconControl;

		//init and show dead icon for everyone but player
		//[ICON_STATE_DEAD, _unitVar] call pams_fnc_reviveIconControl;
	};
	case STATE_RESPAWNED;
	case STATE_REVIVED:
	{
		//pams_revive_incapacitatedUnits = pams_revive_incapacitatedUnits - [_unitVar];
		//pams_revive_unstableUnits = pams_revive_unstableUnits - [_unitVar];

		//flag player as being NOT incapacitated
		_unit setVariable ["pams_revive_incapacitated", false];
		_unit setVariable ["pams_revive_unstable", false];
		//reset "being revived" and "forcing respawn" flags
		SET_BEING_REVIVED_LOCAL(_unit, false);
		SET_FORCING_RESPAWN_LOCAL(_unit, false);
	};
	case STATE_STABILIZED:
	{
		//pams_revive_unstableUnits = pams_revive_unstableUnits - [_unitVar];

		//flag player as being NOT incapacitated
		_unit setVariable ["pams_revive_unstable", false];

		//reset "being revived" and "forcing respawn" flags
		SET_BEING_STABILIZED_LOCAL(_unit, false);
	};
	default
	{
	};
};


//set the actual state
GET_UNIT(_unitVar) setVariable [VAR_STATE, _state];
