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
/* Animation Lengths
AinvPknlMstpSlayWrflDnon_medic
AinvPpneMstpSlayWrflDnon_medic
AinvPknlMstpSlayWrflDnon_medicOther
AinvPpneMstpSlayWrflDnon_medicOther
*/
_anim = "";
_priorAnimation = animationState player;
if (_injured isEqualTo _healer) then {
 _anim = ["AinvPknlMstpSlayWrflDnon_medic","AinvPpneMstpSlayWrflDnon_medic"] select (stance _healer == "PRONE");
} else {
 _anim = ["AinvPknlMstpSlayWrflDnon_medicOther","AinvPpneMstpSlayWrflDnon_medicOther"] select (stance _healer == "PRONE");
};
[_healer, _anim] call ace_common_fnc_doAnimation;
_duration = eams_revive_duration/9;
if (CAN_USE_MEDIKIT(_healer)) then {
	_duration = eams_revive_durationMedic/2.2;
};
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_woundsArray = missionNameSpace getVariable ["EAMS-AllWounds-Target",0];
if ((count _woundsArray) <= 1) exitWith {systemChat "Something has gone wrong ;( while healing a limb, it appears the array doesn't exist?"};
//[head,chest,larm,rarm,lleg,rleg]
_woundValue = -1;
_hitPointID = _validHitPoints find _limb;
_whatNeedsHealing = {
	params ["_array"];
	_value = -1;
	_exit = -1;
	{
		_type = _array select _forEachIndex;
		_value = _type select _hitPointID;
		if (_value > 0) exitWith {_exit = [_value,_forEachIndex]};

	}forEach ["Contusion","Velocity Wound","Avulsion","Abrasion"];
	_exit
};
_woundSelect = [_woundsArray] call _whatNeedsHealing;
if ((_woundSelect select 0) == -1) exitWith {systemChat "Nothing needs a heal, this shouldn't of come up, put in a bug report with your .rpt!!!!!!!!"; diag_log format ["%1 _injured -- %2 _woundSelect %3 _woundsArray",_injured,_woundSelect,_woundsArray]};
_woundValue = _woundSelect select 0;
_woundKindSelection = _woundSelect select 1;
_healingXtraSpeed = 0;
switch (_woundKindSelection) do {
	case 0: {_healingXtraSpeed = 1.5;};
	case 1: {_healingXtraSpeed = 0;};
	case 2: {_healingXtraSpeed = 1;};
	case 3: {_healingXtraSpeed = 2;};
	default {_healingXtraSpeed = 0;};
};
diag_log format ["%1 value and %2 kind",_woundSelect,_woundKindSelection];
//_woundValue = _woundsArray select _hitPointId;
_limbHealedDamage = 0;
_healTime = _duration;
if ((_woundValue > 0) && !(_woundValue < 1)) then {
		_healTime = _duration - _healingXtraSpeed;
		//systemChat format ["%1 Damage and Current %2 N2",damageToHeal,_currentDamage];
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {_healer removeItem 'EAMS_BasicBandage'; EAMS_SET_RETURNITEM(_healer,'EAMS_BasicBandage',false)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {_injured removeItem 'EAMS_BasicBandage'; EAMS_SET_RETURNITEM(_injured,'EAMS_BasicBandage',false)};
		};
	} else {
if ((_woundValue > 0) && (_woundValue < 1)) then {
		_healTime = _duration/3.35;
		_healTime = _healTime - _healingXtraSpeed;
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage_Half')) then {_healer removeItem 'EAMS_BasicBandage_Half';EAMS_SET_RETURNITEM(_healer,'EAMS_BasicBandage_Half',false)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage_Half')) then {_injured removeItem 'EAMS_BasicBandage_Half';EAMS_SET_RETURNITEM(_injured,'EAMS_BasicBandage_Half',false)};
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer);EAMS_SET_RETURNITEM2(_healer,'EAMS_BasicBandage',true)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured); EAMS_SET_RETURNITEM2(_injured,'EAMS_BasicBandage',true)};
		};
	};
};
if (_healTime <= 0) then {_healTime = 1.5};
	/*
		if ((_woundValue > 0) && (_woundValue < 1)) then {
			_limbHealedDamage = 0;
			if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer);EAMS_SET_RETURNITEM2(_healer,'EAMS_BasicBandage',true)} else {
				if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured); EAMS_SET_RETURNITEM2(_injured,'EAMS_BasicBandage',true)};
			if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage_Half')) then {_healer removeItem 'EAMS_BasicBandage_Half';EAMS_SET_RETURNITEM(_healer,'EAMS_BasicBandage')} else {
				if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage_Half')) then {_injured removeItem 'EAMS_BasicBandage_Half';EAMS_SET_RETURNITEM(_injured,'EAMS_BasicBandage')};
			};
		};
	};
*/
};

//systemChat format ["%1,%2,%3 will take %4 to set %5 -- set %6 to %7",name _injured,_limb,name _healer,_duration, _woundsArray, _woundValue, _limbHealedDamage];
//[_healTime,[_injured,_healer,_woundsArray,_hitPointID,_limbHealedDamage,_priorAnimation],
[_healTime,[_injured,_healer,_woundValue,_woundKindSelection,_hitPointID,_priorAnimation],
{
	params ["_args"];
	_injured = _args select 0;
	_healer = _args select 1;
	_woundValue = _args select 2;
	_woundKindSelection = _args select 3;
	_hitPointID = _args select 4;
	_priorAnimation = _args select 5;
	if !((_injured) isEqualTo (_healer)) then {
		/* OLD METHOD OTHER
		missionNameSpace setVariable ["EAMS-BasicWounds-Target",_args select 2];
		_args select 2 set [_args select 3,_args select 4];
		RETURN_DATAXTRATAKE(_args select 1,_args select 0,"EAMS-allWounds-Target",true,_args select 4, _args select 3,true);
		*/
		RETURN_DATANEW(_healer,_injured,"EAMS-AllWounds-Target",_woundValue,_woundKindSelection,_hitPointID)
	} else {
		/*OLD METHOD PLAYER
		_arrayPlayer = player getVariable "EAMS-AllWounds";
		_currentValue = _arrayPlayer select (_args select 3);
		_newValue = _currentValue - 1;
		systemChat str(_newValue);
		if (_newValue < 0) then {_newValue = 0};
		_arrayPlayer set [_args select 3,_newValue];
		player setVariable ["EAMS-BasicWounds",_arrayPlayer];
		*/
		_arrayPlayer = player getVariable "EAMS-AllWounds";
		_woundTypeToEdit = _arrayPlayer select _woundKindSelection;
		_currentValue = _woundTypeToEdit select _hitPointID;
		_newValue = _currentValue - 1;
		if (_newValue < 0) then {_newValue = 0};
		_woundTypeToEdit set [_hitPointID,_newValue];
		_arrayPlayer set [_woundKindSelection,_woundTypeToEdit];
		player setVariable ["EAMS-AllWounds",_arrayPlayer];
	};
	[player, _priorAnimation,2] call ace_common_fnc_doAnimation;
	waitUntil { !isNull findDisplay 46 };
	[_injured,_healer] spawn {[_this select 0,_this select 1] spawn eams_fnc_ui_treatmentMenu;};
},{
	if ((_args select 0) isEqualTo (_args select 1)) then {EAMS_RETURNITEM(_args select 1)} else {EAMS_RETURNITEM(_args select 0)};
	   },'Bandaging...',{true},["isNotDragging","notOnMap","isNotInside"]] spawn ace_common_fnc_progressBar;
