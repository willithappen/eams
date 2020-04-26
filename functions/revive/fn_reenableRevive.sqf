#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Enable revive on given unit. Revive system needs to be initialized and running.

	Parameters:
		_this select 0: OBJECT - affected unit

	Returns:
	nothing

	Example:
	[player] call eams_fnc_reenableRevive;
*/

params[["_unit",objNull,[objNull]]]; if (isNull _unit) exitWith {};

//revive system is disabled
if (REVIVE_MODE == REVIVE_MODE_DISABLED) exitWith {["[x] Revive needs to be properly initialized (on mission start)."] call bis_fnc_logFormat;};

//enable revive
ENABLE_REVIVE(_unit,true);

private _state = switch (lifeState _unit) do
{
	case "HEALTHY";
	case "INJURED":
	{
		STATE_RESPAWNED
	};
	case "INCAPACITATED":
	{
		STATE_INCAPACITATED
	};
	default
	{
		STATE_DEAD
	};
};

//disable built-in death messages
if (eams_revive_killfeedShow && !eams_revive_hudLocked) then
{
	private _hud = shownHUD; _hud set [9, false]; showHUD _hud;
};

//event handlers
#include "_eventHandlers_add.inc"

//reset revive states
SET_STATE(_unit, _state);