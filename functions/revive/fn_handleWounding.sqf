#include "defines.inc"
/* __LIST OF PROJECTILES__
[configFile >> "CfgAmmo" >> "TYPE", true] call BIS_FNC_ReturnParents;
BulletBase --> Rifle/Pistol
ShellBase --> NLAW/RocketLauncher
GrenadeBase --> Grenade
*/
//[["hitface","hitneck","hithead","hitpelvis","hitabdomen","hitdiaphragm","hitchest","hitbody","hitarms","hithands","hitlegs","incapacitated","hitleftarm","hitrightarm","hitleftleg","hitrightleg","eams_incapacitated"],
params ["_hitPoint","_damage","_projectile"];
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_hitPointID = _validHitPoints find _hitPoint;
// Bruises = Other -- Velocity = Gunshots -- Avulsions = Explosions/Grenades -- Abrasions = Bruises/FallDamage
//																	Bruises		Velocity     Avulsions     Abrasions
_allWounds = player getVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];

_woundArray = _allWounds select 0;
_woundGroup = 0;
//_parent = [configFile >> "CfgAmmo" >> _projectile, true] call BIS_FNC_ReturnParents;
//_base = _parent select 2;
_damageType = "unknown";
if (isText (configFile >> "CfgAmmo" >> _projectile >> "EAMS_damageType")) then {
    _damageType = getText (configFile >> "CfgAmmo" >> _projectile >> "EAMS_damageType");
} else {
    _damageType = "unknown";
};
diag_log format ["EAMS Client: Player taken damage of type %1",_damageType];
switch (_damageType) do {
	case "BulletDamage": {_woundArray = _allWounds select 1; _woundGroup = 1;};
	case "ExplosiveDamage": {_woundArray = _allWounds select 2; _woundGroup = 2;};
	case "unknown": {_woundArray = _allWounds select 0; _woundGroup = 0;};
	default {_woundArray = _allWounds select 0; _woundGroup = 0;};
};
_damageCurrent = _woundArray select _hitPointID;
_damageNew = _damageCurrent + 1;
if ((_woundGroup != 0) && (_woundGroup != 2) && (_damage >= 1)) then {
	_damageCurrentAbrasion = _woundArray select 3;
	_damageDifference = _damage - 1;
	_damageAbrasionNew = _damageDifference + _damageCurrentAbrasion;
	(_allWounds select 3) set [_hitPointID,_damageAbrasionNew];
	_allWounds set [3,_allWounds select 3];
};
/*
if ((_woundGroup != 0) && (_woundGroup != 2) && (_damage < 1.5)) then {
	_minorAbrasion = random _damageDifference;
	(_allWounds select 3) set [_hitPointID,_minorAbrasion];
	_allWounds set [3,_allWounds select 3];
};
*/
_woundArray set [_hitPointID,_damageNew];
_allWounds set [_woundGroup,_woundArray];
diag_log format ["EAMS Client: %1 %2 %3 %4",_damageCurrent,_damageNew,_woundArray,_allWounds];
//Should the current state of the player also result in them being knocked out?
//Additional damage can then occur after being knocked out, this will only extend the length of time they are knocked out, not renock them out
_sumArray = {
	params ["_type","_array"];
	_sum = 0;
	_arrSel = _array select _type;
	{
		_sum = _sum + _x;
	}forEach _arrSel;
	_sum
};
_shouldKO = {
  params ["_array"];
   _contusions = [0,_array] call _sumArray;
   _velocities = [1,_array] call _sumArray;
   _avulsions = [2,_array] call _sumArray;
   _abrasions = [3,_array] call _sumArray;
   _totalDamage = (_contusions / 3) + _velocities + (_avulsions / 3) + (_abrasions / 2);
  _result = false;
  _extreme = false;
  if (_totalDamage >= eams_fatalDamageGlobal) then {_result = true};
  if (_totalDamage >= eams_fatalDamageGlobal * 2) then {_extreme = true};
  [_result,_extreme]
};
_KO = [_allWounds] call _shouldKO;
if (_KO select 0) then {
	SET_STATELOCAL(player,STATE_INCAPACITATED);
};
if (_KO select 1) then {
	player setDamage 1;
};
_contusions = [0,_allWounds] call _sumArray;
_velocities = [1,_allWounds] call _sumArray;
_avulsions = [2,_allWounds] call _sumArray;
_abrasions = [3,_allWounds] call _sumArray;
_totalDamage = (_contusions / 3) + _velocities + (_avulsions / 3) + (_abrasions / 2);
//   [10] call BIS_fnc_bloodEffect; Light splatter
//   [50] call BIS_fnc_bloodEffect;
//    [100] call BIS_fnc_bloodEffect; heavy splatter
if ((_totalDamage > 0) && !(eams_isInjured)) then {
 [] spawn {
  waitUntil {
   eams_isInjured = true;
   sleep 1;
   _isHealed = {
    params ["_array"];
    _result = false;
	_sumArray = {
    params ["_type","_array"];
    _sum = 0;
    _arrSel = _array select _type;
    {
    _sum = _sum + _x;
    }forEach _arrSel;
    _sum
    };
     _contusions = [0,_array] call _sumArray;
     _velocities = [1,_array] call _sumArray;
     _avulsions = [2,_array] call _sumArray;
     _abrasions = [3,_array] call _sumArray;
     _totalDamage = _contusions + _velocities + _avulsions + _abrasions;
    if (_totalDamage == 0) then {_result = true};
    [_result,_totalDamage]
   };
   _allWounds = player getVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
   _healed = [_allWounds] call _isHealed;
    [(_healed select 1) * 10] call BIS_fnc_bloodEffect;
   (_healed select 0)
  };
  eams_isInjured = false;
 };
};
player setVariable [format ["EAMS-%1Wounds","All"],_allWounds];
//_parent = [configFile >> "CfgAmmo" >> _projectile, true] call BIS_FNC_ReturnParents;
//_bullet = _par findIf {_x isEqualTo "BulletBase"};
//_wounds = EAMS_GET_WOUNDSSELF("basic");
