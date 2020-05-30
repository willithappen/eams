#include "defines.inc"
params ["_unit","_corpse"];
SET_STATELOCAL(player,STATE_RESPAWNED);
player setCaptive false;
player setVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
_corpse removeAllEventHandlers "handleDamage";
true
