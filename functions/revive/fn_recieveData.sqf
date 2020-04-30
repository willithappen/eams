params ["_transmitter","_reciever","_variable","_variableResult",["_singlevalue",false],["_value",0],["_selection",0]];
if !(_singlevalue) then {
	systemChat format ["Recieving: %1",_variable];
	systemChat format ["Recieving: %1",_variableResult];
	_v = _variable splitString "-";
	_v deleteAt 2;
	_var = _v joinString "-";
	systemChat format ["Recieving: %1",_var];
	systemChat str(player);
	player setVariable [_var,_variableResult];
} else {
	systemChat format ["Recieving Single Value: %1",_variable];
	systemChat format ["Recieving Single: %1",_variableResult];
	_v = _variable splitString "-";
	_v deleteAt 2;
	_var = _v joinString "-";
	_arrayPlayer = player getVariable _var;
	systemChat format ["Recieving Single: %1 to set %2 at array #%3 to %4",_var, _arrayPlayer, _selection, _value];
	_arrayPlayer set [_selection,_value];
	player setVariable [_arrayPlayer,_variableResult];
};
