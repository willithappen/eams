params ["_transmitter","_reciever","_variable","_variableResult"];
systemChat format ["Recieving: %1",_variable];
systemChat format ["Recieving: %1",_variableResult];
_v = _variable splitString "-";
_v deleteAt 2;
_var = _v joinString "-";
systemChat format ["Recieving: %1",_var];
systemChat str(player);
player setVariable [_var,_variableResult];
