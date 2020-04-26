#include "defines.inc"
/*
	Author: willithappen

	Description:
	Heals necesarry limb to required amount
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
params ['_injured','_limb',['_healer',objNull]];

_sd = false;
//systemChat str(_limb);
_anim = "";
if (_injured isEqualTo _healer) then {
 _anim = ["AinvPknlMstpSlayWrflDnon_medic","AinvPpneMstpSlayWrflDnon_medic"] select (stance _healer == "PRONE");
} else {
 _anim = ["AinvPknlMstpSlayWrflDnon_medicOther","AinvPpneMstpSlayWrflDnon_medicOther"] select (stance _healer == "PRONE");
};
_healer playmove _anim;
_duration = eams_revive_duration/9;
if (CAN_USE_MEDIKIT(_healer)) then {
	_duration = eams_revive_durationMedic/2;
};
_currentDamage = _injured getHitPointDamage _limb;
	if (_currentDamage > 0) then {
		damageToHeal = 0;
		//systemChat format ["%1 Damage and Current %2 N2",damageToHeal,_currentDamage];
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured)};
		};
	};
//systemChat format ["%1 Damage and Current %2 N3",damageToHeal,_currentDamage];
[_duration,[_injured,_limb,_healer,damageToHeal],
{
	params ["_args"];
	//(_args select 2) playAction 'MedicStop';

	[_args, {
		(_this select 0) setHitPointDamage [_this select 1, _this select 3];
	}] remoteExecCall ["BIS_FNC_CALL",_args select 0];
},
{
	params ["_args"];
	//(_args select 2) playAction 'medicStop';
}, 'Bandaging...'] call ace_common_fnc_progressBar;

if (_sd) exitWith {true};
false
