#include "defines.inc"
/*
	Author: Jiri Wainar - Stabilization added by willithappen

	Description:
	Used to execute specific code localy on every client whenever "being stabilized" flag changes.

	Parameters:
		_this select 0: STRING - Variable that carries the "being revived" flag over the network, defined by macro VAR_TRANSFER_BEING_STABILIZED.
		_this select 1: BOOL - Flag state - true or false.
		_this select 2: OBJECT - Unit to set the flag for.

	Returns:
	True if successful, false if not.
*/

#define DEBUG_LOG	bis_fnc_logFormat

//["[ ] this: %1",_this] call DEBUG_LOG;

private ["_unit","_state"];

_state = param [1, false, [true]];
_unit  = param [2, objNull, [objNull]];

if (isNull _unit) exitWith {false};

private _unitVar = GET_UNIT_VAR(_unit);

//store previous flag
private _statePrev = IS_BEING_STABILIZED(_unit);

//stop if state didn"t change
if (_statePrev isEqualTo _state) exitWith {};

//["[ ] %1 -> %2",_statePrev,_state] call DEBUG_LOG;

//set the actual state
_unit setVariable [VAR_BEING_STABILIZED, _state];

//show icon indicating player is being revived by someone
/*
if (_state && {!local _unit}) then
{
	[ICON_STATE_BEING_STABILIZED, _unitVar] call pams_fnc_reviveIconControl;
};
*/
true
