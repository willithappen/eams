#include "defines.inc"

//["[ ] ON RESPAWN: %1",_this] call bis_fnc_logFormat;

params [["_unit", objNull, [objNull]]];

if (REVIVE_ENABLED(_unit)) then
{
	SET_STATE(_unit, STATE_RESPAWNED);
};

true
