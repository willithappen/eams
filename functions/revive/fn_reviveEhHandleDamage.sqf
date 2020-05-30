/*params ["_unit", "", "_damage", "", "_projectile", "", "", "_hitPoint"];
_edges = ["hitabdomen","hitdiaphragm","hitchest"];
if (_hitPoint in _edges) then {_hitPoint = "hitbody"};
if (_damage < 0.15) exitWith {0};
_hit = toLower _hitPoint;
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
if (_hit in _validHitPoints) then {
	_damageFinal = 0;
	if ((_hit isEqualTo "hithead") && (_damage > 2.5)) then {_damageFinal = 2.5} else {_damageFinal = _damage};
	diag_log format ["Unit really took %1 but we are passing %2 to %3",_damage,_damageFinal,_hitPoint];
	[_hit,_damageFinal,_projectile] call EAMS_fnc_handleWounding;
};
0
*/

/*When damage is taken. Acknowledge the frame the damage was taken. Create an array for that frameNumber that will house all the damage taken in that frame.
Using CBA Events, waitUntil no new elements are added in the array by waiting x frames (can be very very low). Sort the array (can be done for multi layer arrays correctly as it uses first number to sort by first.
Element with highest number is what we want to capture and use as damage to pass to the rest of our scripts.
*/
params ["_unit", "", "_damage", "", "_projectile", "", "", "_hitPoint"];
_edges = ["hitabdomen","hitdiaphragm","hitchest"];
if (_hitPoint in _edges) then {_hitPoint = "hitbody"};
if (_damage < 0.15) exitWith {0};
_hit = toLower _hitPoint;
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
if (_hit in _validHitPoints) then {
	[_damage,_hit,diag_tickTime,_projectile] spawn {
		params ["_damage","_hit","_frame","_projectile"];
		_frameApprox = parseNumber (_frame toFixed 1);
		//systemChat format ["SKIPPED %1 to %2 at %3",_damage,_hit,_frameApprox];
		_array = player getVariable [format ["EAMS_ComputeHighest_%1",_frameApprox],[]];
		if ((count _array) <= 1) exitWith {
			_array = _array + [[_damage,_hit,_frameApprox,_projectile]];
			player setVariable [format ["EAMS_ComputeHighest_%1",_frameApprox],_array];
		};
		_array = _array + [[_damage,_hit,_frameApprox,_projectile]];
		_array sort false;
		player setVariable [format ["EAMS_ComputeHighest_%1",_frameApprox],_array];
		//systemChat str (_array);

	};
};
0
