params ["_requester","_requestee","_variable","_variableResult"];
diag_log format ["Transmit: %1",_variable];
missionNameSpace setVariable [format ["%1-Target",_variable],_variableResult];
