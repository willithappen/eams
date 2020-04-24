#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Check if player can perform stabilize action on given unit.

	Parameters:
	0: OBJECT - unconscious unit

	Returns:
	BOOL - is player able to revive the unit and is the unit revivable?

	Example:
	_reviveIsValid = [_unit] call pams_fnc_StabilizeIsValid;
*/
params
[
	["_unit",objNull,[objNull]],
	["_player",ObjNull,[ObjNull]]
];

//no valid unit or required key is not pressed
if (isNull _unit) exitWith {false};

//check side; can revive only friendlies
if (side group player getFriend side group _unit < 0.6) exitWith {false};

//check distance
if (player distance _unit > REVIVE_DISTANCE) exitWith {false};

//check validity of player
if ((lifeState _unit != "INCAPACITATED") || (!IS_DISABLED(_unit))) exitWith {false};

//Checks if unit is mostly healed
if !(IS_HEALTHY(_unit)) exitWith {false};
true
