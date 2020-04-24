#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Check if player can perform secure action on given unit.

	Parameters:
	0: OBJECT - unconscious unit

	Returns:
	BOOL - is player able to secure the unit?

	Example:
	_reviveIsValid = [_unit] call pams_fnc_reviveIsValidSecure;
*/

params
[
	["_unit",objNull,[objNull]]
];

//no valid unit or out of range
if (isNull _unit || {player distance _unit > REVIVE_DISTANCE}) exitWith {false};

//check validity of player
if (IN_VEHICLE(player)) exitWith {false};

//check side; can secure only enemies
if (side group player getFriend side group _unit >= 0.6) exitWith {false};

//check life state
if (lifeState _unit != "INCAPACITATED" || {!IS_DISABLED(_unit)}) exitWith {false};

//check positioning
_pos = unitAimPositionVisual _unit;
_dist = (_pos distance player) max 1;

if (_dist > REVIVE_DISTANCE_BODY_CENTER) exitWith {false};

//get position on the screen & exit if it is not on the screen
_pos = worldToScreen _pos; if (count _pos == 0) exitWith {false}; _pos set [2,0];

//determine interaction size based on distance
_interact = 0.8/_dist;

//["[ ] _dist: %4 | _pos: %1 | screen distance: %2 | _interact: %3",_pos,_pos distance [0.5,0.5,0],_interact,_dist] call bis_fnc_logFormat;

//unit must be in the center of the screen
if (_pos distance [0.5,0.5,0] > _interact) exitWith {false};

true