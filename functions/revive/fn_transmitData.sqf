params ["_requester","_requestee","_variable","_variableResult"];
systemChat format ["Transmit: %1",_variableRecieved];
missionNameSpace setVariable [format ["%1-%2",_requestee,_variable],_variableResult];
