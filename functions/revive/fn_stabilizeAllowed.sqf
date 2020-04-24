#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Returns true if unit is in general able to revive someone.

	Parameters:
	0: OBJECT - unit performing revive
	1: OBJECT - unit that will be revived

	Returns:
	SCALAR (check defines.inc for exact values)
	> 0: unit is able to perform revive action
	< 0: unit is NOT able to perform revive action

	Example:
	_reviveAllowed = [_unit,_target] call pams_fnc_reviveAllowed;
*/

params[["_unit",objNull,[objNull]],["_target",objNull,[objNull]]];

//revive system is disabled
if (REVIVE_MODE == REVIVE_MODE_DISABLED) exitWith {ALLOW_CHECK_REVIVE_SYSTEM_DISABLED};

//player is not pointing at the target or player is NULL (?)
if (isNull _unit || isNull _target) exitWith {ALLOW_CHECK_NULL};

//unit doesn"t have revive enabled or either unit or target are NULL
if (!REVIVE_ENABLED(_unit)) exitWith {ALLOW_CHECK_REVIVE_DISABLED};

//unit doesn"t have required trait "medic"
private _isMedic = _unit getUnitTrait "Medic";
if (pams_revive_requiredTrait == 1 && {!_isMedic}) exitWith {ALLOW_CHECK_REQUIRE_MEDIC};

//equipment not required
if (pams_revive_requiredItems == 0) exitWith {ALLOW_CHECK_OK};
