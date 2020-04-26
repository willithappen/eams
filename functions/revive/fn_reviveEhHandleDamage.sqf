#include "defines.inc"
/* __LIST OF PROJECTILES__
[configFile >> "CfgAmmo" >> "TYPE", true] call BIS_FNC_ReturnParents;
BulletBase --> Rifle/Pistol
ShellBase --> NLAW/RocketLauncher
GrenadeBase --> Grenade
*/
//ignore damage under the threshold
if (_damage < 0.05) exitWith {0};
params ["_unit", "", "_damage", "", "_projectile", "", "", "_hitPoint"];
_parent = [configFile >> "CfgAmmo" >> _projectile, true] call BIS_FNC_ReturnParents;
_bullet = _par findIf {_x isEqualTo "BulletBase"};
if (_bullet != -1) then {};
//SET_STATE(_unit,STATE_INCAPACITATED);

0
