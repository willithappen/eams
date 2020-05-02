#include "defines.inc"
params ["_transmitter","_reciever","_variable","_variableResult",["_singlevalue",false],["_value",0],["_selection",0],["_takeNotSet",false]];
if !(_singlevalue) then {
	diag_log format ["Recieving: %1",_variable];
	diag_log format ["Recieving: %1",_variableResult];
	_v = _variable splitString "-";
	_v deleteAt 2;
	_var = _v joinString "-";
	diag_log format ["Recieving: %1",_var];
	diag_log str(player);
	player setVariable [_var,_variableResult];
} else {
	diag_log format ["Recieving Single Value: %1",_variable];
	diag_log format ["Recieving Single: %1",_variableResult];
	_v = _variable splitString "-";
	_v deleteAt 2;
	_var = _v joinString "-";
	_arrayPlayer = player getVariable _var;
	diag_log format ["Recieving Single: %1 to set %2 at array #%3 to %4",_var, _arrayPlayer, _selection, _value];
	if (_takeNotSet) then {
		_currentValue = _arrayPlayer select _selection;
		if (_currentValue == 0) then {{EAMS_RETURNITEM(player); systemChat "Your bandage has been returned"} remoteExecCall ["bis_fnc_call",_transmitter]};
		_newValue = _currentValue - 1;
		if (_newValue < 0) then {_newValue = 0};
		_arrayPlayer set [_selection,_newValue];
		player setVariable [_var,_arrayPlayer];
	} else {
		_arrayPlayer set [_selection,_value];
		player setVariable [_var,_arrayPlayer];
	};
};
