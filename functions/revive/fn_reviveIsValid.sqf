#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Check if player can perform revive action on given unit.

	Parameters:
	0: OBJECT - unconscious unit

	Returns:
	BOOL - is player able to revive the unit and is the unit revivable?

	Example:
	_reviveIsValid = [_unit] call pams_fnc_reviveIsValid;
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

//check life state
if (lifeState _unit != "INCAPACITATED" || ((!IS_DISABLED(_unit)) && (!IS_STABLE(_unit)))) exitWith {false};

//Checks if unit is mostly healed
if (!IS_STABLE(_unit)) exitWith {false};
//Checks if unit has morphine available
if (!CAN_USE_EAMSITEM2(_player,_unit,'EAMS_Epinephrine')) exitWith {false};
true
