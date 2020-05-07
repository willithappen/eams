#include "defines.inc"

//["[ ] ON RESPAWN: %1",_this] call bis_fnc_logFormat;

params [["_unit", objNull, [objNull]]];
SET_STATE(_unit,STATE_RESPAWNED);
_unit setCaptive false;
_unit setVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];

true
