params ["_transmitter","_reciever","_variable","_woundValue","_woundKindSelection","_hitPointID"];
_variableResult = missionNameSpace getVariable _variable;
[_transmitter,_reciever,_variable,_woundValue,_woundKindSelection,_hitPointID,_variableResult] remoteExecCall ["eams_fnc_recieveDataNew",_reciever];
