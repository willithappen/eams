#include "defines.inc"

params[["_unit", objNull, [objNull]], ["_killer", objNull, [objNull]], ["_instigator", objNull, [objNull]]];
SET_STATE(_unit,STATE_DEAD);
_unit setCaptive false;
_unit setVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
true
