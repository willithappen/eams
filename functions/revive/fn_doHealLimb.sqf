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
params ['_injured','_limb',['_healer',player]];
_sd = false;
//systemChat str(_limb);
_anim = "";
if (_injured isEqualTo _healer) then {
 _anim = ["AinvPknlMstpSlayWrflDnon_medic","AinvPpneMstpSlayWrflDnon_medic"] select (stance _healer == "PRONE");
} else {
 _anim = ["AinvPknlMstpSlayWrflDnon_medicOther","AinvPpneMstpSlayWrflDnon_medicOther"] select (stance _healer == "PRONE");
};
_healer playmove _anim;
_duration = eams_revive_duration/9.75;
if (CAN_USE_MEDIKIT(_healer)) then {
	_duration = eams_revive_durationMedic/1.3;
};
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_woundsArray = missionNameSpace getVariable ["EAMS-BasicWounds-Target",[0,0,0,0,0,0]];
//[head,chest,larm,rarm,lleg,rleg]
_hitPointID = _validHitPoints find _limb;
_woundValue = _woundsArray select _hitPointId;
_damageToHeal = 0;
	if ((_woundValue > 0) && !(_woundValue < 1)) then {
		_damageToHeal = _woundValue - 1;
		//systemChat format ["%1 Damage and Current %2 N2",damageToHeal,_currentDamage];
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured)};
		};
	} else {
		if ((_woundValue > 0) && (_woundValue < 1)) then {
			_damageToHeal = 0;
			if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer)} else {
				if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured)};
			if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage_Half')) then {_healer removeItem 'EAMS_BasicBandage_Half'} else {
				if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage_Half')) then {_injured removeItem 'EAMS_BasicBandage_Half'};
			};
		};
	};
};

_woundsArray set [_hitPointID,_damageToHeal];
missionNameSpace setVariable ["EAMS-BasicWounds-Target",_woundsArray];
systemChat format ["%1,%2,%3 will take %4 to set %5 -- set %6 to %7",name _injured,_limb,name _healer,_duration, _woundsArray, _woundValue, _damageToHeal];
[_duration,[_injured,_healer,_woundsArray],{
	params ["_args"];
	systemChat format ["%1 equal to %2",_args select 0,_args select 1];
	if !((_args select 0) isEqualTo (_args select 1)) then {
		RETURN_DATA(_args select 1,_args select 0,"EAMS-BasicWounds-Target")
	} else {
		player setVariable [format ["EAMS-%1Wounds","Basic"],_args select 2];
	};
	},{},'Bandaging...'] call ace_common_fnc_progressBar;

if (_sd) exitWith {true};
false
