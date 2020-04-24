#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Disable revive on given unit.

	Parameters:
		_this select 0: OBJECT - affected unit

	Returns:
	nothing

	Example:
	[player] call pams_fnc_disableRevive;
*/
/*
params[["_unit",objNull,[objNull]]]; if (isNull _unit) exitWith {};

//reset revive states
SET_STATE(_unit, STATE_RESPAWNED);

//kill incapacitated players
if (lifeState _unit == "INCAPACITATED") then {_unit setDamage 1;};

//re-enable built-in death messages
if (pams_revive_killfeedShow && !pams_revive_hudLocked) then
{
	private _hud = shownHUD; _hud set [9, true]; showHUD _hud;
};

//remove event handlers
#include "_eventHandlers_remove.inc"

ENABLE_REVIVE(_unit,false);
*/
