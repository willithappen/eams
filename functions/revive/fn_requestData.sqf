params ["_requester","_requestee","_variable"];
_variableResult = _requestee getVariable _variable;
[_requester,_requestee,_variable,_variableResult] remoteExecCall ["eams_fnc_transmitData",_requester];
