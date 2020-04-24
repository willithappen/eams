#include "defines.inc"

#define DEBUG_LOG		bis_fnc_logFormat

params ["_unit"];

if (!REVIVE_ENABLED(_unit)) exitWith {};

_unit spawn
{
	scriptName "pams_fnc_reviveEhHandleHeal";

	private _t = time + 10;
	private _damage = damage _this;

	waitUntil{damage _this < _damage || {time > _t}};

	//make ANY heal a full heal
	[] call pams_fnc_reviveDamageReset;
};

false