#include "defines.inc"
//[["hitface","hitneck","hithead","hitpelvis","hitabdomen","hitdiaphragm","hitchest","hitbody","hitarms","hithands","hitlegs","incapacitated","hitleftarm","hitrightarm","hitleftleg","hitrightleg","eams_incapacitated"],
params ["_hitPoint","_damage","_projectile"];
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_hitPointID = _validHitPoints find _hitPoint;
_woundState = player getVariable [format ["EAMS-%1Wounds","Basic"],[0,0,0,0,0,0]];
_damageCurrent = _woundState select _hitPointID;
_damageNew = _damageCurrent + _damage;
_woundState set [_hitPointID,_damageNew];
player setVariable [format ["EAMS-%1Wounds","Basic"],_woundState];

//Should the current state of the player also result in them being knocked out?
//Additional damage can then occur after being knocked out, this will only extend the length of time they are knocked out, not renock them out
_shouldKO = {
	params ["_head","_chest","_armL","_armR","_legL","_legR"];
	_result = false;
	_totalDamage = _head + _chest + _armL + _armR + _legL + _legR;
	if (_totalDamage >= EAMS_FATALDAMAGE) then {_result = true};
	_result
};
_KO = (_woundState) call _shouldKO;
diag_log str(_KO);
if (_KO) then {
	SET_STATE(_unit,STATE_INCAPACITATED);
};

//_parent = [configFile >> "CfgAmmo" >> _projectile, true] call BIS_FNC_ReturnParents;
//_bullet = _par findIf {_x isEqualTo "BulletBase"};
//_wounds = EAMS_GET_WOUNDSSELF("basic");
