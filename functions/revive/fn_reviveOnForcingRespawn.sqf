#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Used to execute specific code localy on every client whenever "forcing respawn" flag changes.

	Parameters:
		_this select 0: STRING - Variable that carries the "being revived" flag over the network, defined by macro VAR_TRANSFER_FORCING_RESPAWN.
		_this select 1: BOOL - Flag state - true or false.
		_this select 2: OBJECT - Unit to set the flag for.

	Returns:
	True if successful, false if not.
*/

#define DEBUG_LOG	bis_fnc_logFormat

private ["_unit","_state"];

_state = param [1, false, [true]];
_unit  = param [2, objNull, [objNull]];

if (isNull _unit) exitWith {false};

private _unitVar = GET_UNIT_VAR(_unit);

//store previous flag
private _statePrev = IS_FORCING_RESPAWN(_unit);

//stop if state didn"t change
if (_statePrev isEqualTo _state) exitWith {};

//["[ ] %1 -> %2",_statePrev,_state] call bis_fnc_logFormat;

//set the actual state
_unit setVariable [VAR_FORCING_RESPAWN, _state];

//being revived icon has priotity over the forcing respawn icon
if (IS_BEING_REVIVED(_unit)) exitWith {};
/*
//show icon indicating player is forcing respawn
if (_state && {!local _unit}) then
{
	[ICON_STATE_FORCING_RESPAWN, _unitVar] call pams_fnc_reviveIconControl;
};
*/
true
