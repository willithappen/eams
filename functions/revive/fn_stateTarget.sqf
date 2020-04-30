#include "defines.inc"
params ["_target"];
REQUEST_DATA(player,_target,VAR_STATE);
_var = missionNameSpace getVariable [VAR_STATE_TARGET, STATE_RESPAWNED];
_var
