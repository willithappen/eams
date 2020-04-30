params ["_transmitter","_reciever","_variable",["_singlevalue",false],["_value",0],["_selection",0]];
if !(_singleValue) then {
	_variableResult = missionNameSpace getVariable _variable;
	[_transmitter,_reciever,_variable,_variableResult] remoteExecCall ["eams_fnc_recieveData",_reciever];
} else {
	_variableResult = missionNameSpace getVariable _variable;
	[_transmitter,_reciever,_variable,_variableResult,true,_value,_selection] remoteExecCall ["eams_fnc_recieveData",_reciever];
};
