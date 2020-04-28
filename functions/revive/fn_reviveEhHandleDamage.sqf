params ["_unit", "", "_damage", "", "_projectile", "", "", "_hitPoint"];
if (_damage < 0.05) exitWith {0};
_hit = toLower _hitPoint;
_validHitPoints = ["hithead","hitchest","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
if (_hit in _validHitPoints) then {
	if ((_hit isEqualTo "hithead") && (_damage > 2)) then {_damage = 1.5};
	[_hit,_damage,_projectile] call EAMS_fnc_handleWounding;
};
0
