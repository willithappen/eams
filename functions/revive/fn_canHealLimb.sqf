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

	Example: [_target,'head'] call eams_fnc_canHealLimb; -- Returns true or false
	Example: [_target,'hitArms',true] call eams_fnc_canHealLimb; -- Returns a Number
	Returns:
	none
&& ((CAN_USE_EAMSITEM2(_healer,_target,'EAMS_BasicBandage') || CAN_USE_EAMSITEM2(_healer,_target,'EAMS_BasicBandage_Half'))))
*/
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

	Example: [_target,'head'] call eams_fnc_canHealLimb; -- Returns true or false
	Example: [_target,'hitArms',true] call eams_fnc_canHealLimb; -- Returns a Number
	Returns:
	none
*/
params ['_target','_limb',['_healer',objNull]];
if !(isPlayer _target) exitWith {false};
_sd = false;
_eamsYes = false;
if (_limb isEqualTo 'patch') then {
	_damages = (['HitHead', 'HitBody', 'hitLeftArm', 'hitRightArm', 'hitLeftLeg', 'hitRightLeg'] apply {_target getHitPointDamage _x});
	if (selectMax _damages < 0.08) then {
		if !(isNull _healer) then {
			if (CAN_USE_EAMSITEM2(_healer,_target,'EAMS_Epinephrine')) then {_eamsYes = true; _sd = true;};
		} else {
			if (CAN_USE_EAMSITEM(_target,'EAMS_Epinephrine')) then {_eamsYes = true; _sd = true;};
		};
	};
} else {
	_damage = _target getHitPointDamage _limb;
	if (_damage > 0) then {_sd = true};
	if (isNull _healer) then {
		if ((CAN_USE_EAMSITEM2(_healer,_target,'EAMS_BasicBandage')) || (CAN_USE_EAMSITEM2(_healer,_target,'EAMS_BasicBandage_Half'))) then {_eamsYes = true} else {_eamsYes = false};
	} else {
		if ((CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) || (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage_Half'))) then {_eamsYes = true} else {_eamsYes = false};
	};
};
if (_sd && _eamsYes) exitWith {true};
false
