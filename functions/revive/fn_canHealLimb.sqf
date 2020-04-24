#include "defines.inc"
/*
	Author: willithappen

	Description:
	Checks if necessary limb/limb group is above the threshold to be 'bandaged'
	Exits with True

	Parameters:
	0: unit
	1: LIMB FAKE
		head
		chest
		arms
		legs
	Nn: REAL LIMB
		hitface/hitneck/hithead
		hitpelvis/hitabdomen/hitdiaphragm/hitchest/hitbody
		hitArms/hitHands
		hitLegs

	Example: [_target,'head'] call pams_fnc_canHealLimb; -- Returns true or false
	Example: [_target,'hitArms',true] call pams_fnc_canHealLimb; -- Returns a Number
	Returns:
	none
&& ((CAN_USE_EAMSITEM2(_player,_target,'EAMS_BasicBandage') || CAN_USE_EAMSITEM2(_player,_target,'EAMS_BasicBandage_Half'))))
*/
params ['_target','_limb',['_limbTrue',false],['_player',ObjNull]];
if !(isPlayer _target) exitWith {false};
_realLimbs = false;
_sd = false;
if (_limbTrue) exitWith {_target getHitPointDamage _limb};
if !(_limbTrue) then {
	switch (_limb) do {
		case 'head': {
			_damageTotal = 0;
			{
				_damage = _target getHitPointDamage _x;
				_damageTotal = _damageTotal + _damage;
			}forEach ['hitFace','hitNeck','hitHead'];
			if (_damageTotal >= 0.05) then {_sd = true};
		};
		case 'patch' do {
		if (((_target getHitPointDamage 'HitHead') < 0.05) &&
		((_target getHitPointDamage 'HitBody') < 0.05) &&
		((_target getHitPointDamage 'hitLeftArm') < 0.05) &&
		((_target getHitPointDamage 'hitRightArm') < 0.05) &&
		((_target getHitPointDamage 'hitLeftLeg') < 0.05) &&
		((_target getHitPointDamage 'hitRightLeg') < 0.05) && (CAN_USE_EAMSITEM(_target,'EAMS_Epinephrine'))) then {_sd = true};
		};
		case 'hitHead': {
			_damage = _target getHitPointDamage 'hitHead';
		if (_damage >= 0.05) then {_sd = true};
		};
		case 'chest': {
			_damageTotal = 0;
			{
				_damage = _target getHitPointDamage _x;
				_damageTotal = _damageTotal + _damage;
			}forEach ['hitpelvis','hitabdomen','hitdiaphragm','hitchest','hitBody'];
			if (_damageTotal >= 0.05) then {_sd = true};
		};
		case 'hitBody': {
			_damage = _target getHitPointDamage 'hitBody';
		if (_damage >= 0.1) then {_sd = true};
		};
		case 'arms': {
			_damageTotal = 0;
			{
				_damage = _target getHitPointDamage _x;
				_damageTotal = _damageTotal + _damage;
			}forEach ['hitArms','hitHands'];
			if (_damageTotal >= 0.05) then {_sd = true};
		};
		case 'legs': {
			_damageTotal = 0;
			{
				_damage = _target getHitPointDamage _x;
				_damageTotal = _damageTotal + _damage;
			}forEach ['hitLegs'];
			if (_damageTotal >= 0.05) then {_sd = true};
		};
		case 'HitLeftArm': {
				_damage = _target getHitPointDamage 'HitLeftArm';
			if (_damage >= 0.05) then {_sd = true};
		};
		case 'HitRightArm': {
				_damage = _target getHitPointDamage 'HitRightArm';
			if (_damage >= 0.05) then {_sd = true};
		};
		case 'HitLeftLeg': {
				_damage = _target getHitPointDamage 'HitLeftLeg';
			if (_damage >= 0.05) then {_sd = true};
		};
		case 'hitRightLeg': {
				_damage = _target getHitPointDamage 'hitRightLeg';
			if (_damage >= 0.05) then {_sd = true};
		};
	};
};
if (((CAN_USE_EAMSITEM2(_player,_target,'EAMS_BasicBandage')) || (CAN_USE_EAMSITEM2(_player,_target,'EAMS_BasicBandage_Half'))) && _sd) exitWith {true};
false
