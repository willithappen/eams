params ["_unit", "", "_damage", "", "_projectile", "", "", "_hitPoint"];
_edges = ["hitabdomen","hitdiaphragm","hitchest"];
if (_hitPoint in _edges) then {_hitPoint = "hitbody"};
if (_damage < 0.05) exitWith {0};
_hit = toLower _hitPoint;
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
if (_hit in _validHitPoints) then {
	_damageFinal = 0;
	if ((_hit isEqualTo "hithead") && (_damage > 2)) then {_damageFinal = 1.5} else {_damageFinal = _damage};
	systemChat format ["Unit really took %1 but we are passing %2 to %3",_damage,_damageFinal,_hitPoint];
	[_hit,_damageFinal,_projectile] call EAMS_fnc_handleWounding;
};
0
