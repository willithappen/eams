#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Returns is revive is enabled or not for the unit.

	Parameters:
	0: OBJECT - unit that is checked

	Returns:
	True if revive is enabled, false if not.

	Example
	[player] call pams_fnc_reviveEnabled;
*/

params[["_unit",objNull,[objNull]]];

REVIVE_ENABLED(_unit)