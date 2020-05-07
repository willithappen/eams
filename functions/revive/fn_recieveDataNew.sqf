#include "defines.inc"
params ["_transmitter","_reciever","_variable","_woundValue","_woundKindSelection","_hitPointID","_variableResult"];
diag_log format ["Recieving Variable %1",_variable];
diag_log format ["Variable is: %1",_variableResult];
_v = _variable splitString "-";
_v deleteAt 2;
_var = _v joinString "-";
_arrayPlayer = player getVariable _var;
diag_log format ["Recieving: %1 to set %2 at array #%3 to %4",_var, _arrayPlayer, _woundValue, _woundKindSelection];
_woundTypeToEdit = _arrayPlayer select _woundKindSelection;
_currentValue = _woundTypeToEdit select _hitPointID;
if (_currentValue == 0) then {{EAMS_RETURNITEM(player); systemChat "Your bandage has been returned"} remoteExecCall ["bis_fnc_call",_transmitter]};
_newValue = _currentValue - 1;
if (_newValue < 0) then {_newValue = 0};
_woundTypeToEdit set [_hitPointID,_newValue];
_arrayPlayer set [_woundKindSelection,_woundTypeToEdit];
player setVariable ["EAMS-AllWounds",_arrayPlayer];
