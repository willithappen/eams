params ["_transmitter","_reciever","_variable"];
_variableResult = missionNameSpace getVariable _variable;
[_transmitter,_reciever,_variable,_variableResult] remoteExecCall ["eams_fnc_recieveData",_reciever];
