#include "defines.inc"
disableSerialization;
waitUntil { !isNull findDisplay 3267 };
params ["_selection",["_target",uiNameSpace getVariable ['EAMS-CurrentPatient',objNull]]];
waitUntil { !isNull _target};
waituntil {
	_woundsArray = missionNameSpace getVariable ["EAMS-AllWounds-Target",[0]];
	count _woundsArray > 1
};
_woundsArray = missionNameSpace getVariable ["EAMS-AllWounds-Target",[0]];
//_allWounds = player getVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
ctrlSetText [1001,format['Currently Treating: %1',name _target]];
uiNameSpace setVariable ["EAMS-SelectedBodyPart",_selection];
lbClear 1100;
ctrlSetText [1607,""];
_sumArray = {
params ["_type","_array"];
_sum = 0;
_arrSel = _array select _type;
{
_sum = _sum + _x;
}forEach _arrSel;
_sum
};
 _contusions = [0,_woundsArray] call _sumArray;
 _velocities = [1,_woundsArray] call _sumArray;
 _avulsions = [2,_woundsArray] call _sumArray;
 _abrasions = [3,_woundsArray] call _sumArray;
 _damagesTotal = [0,0,0,0,0,0];
 {
 	{
		_newValue = 0;
 		_newValue = (_damagesTotal select _forEachIndex) + _x;
 		_damagesTotal set [_forEachIndex,_newValue];
 	}forEach (_woundsArray select _forEachIndex);
 }forEach _woundsArray;
_establishTextColors = {
	params ["_woundsArray","_damagesTotal"];
	//IDCS: head, chest, larm, rarm, lleg, relg
	_idc = [1600,1605,1601,1602,1603,1604];
	//COLORS: Green,Yellow,Orange,Red
	_newValue = 0;
	_colors = [[0.133,0.871,0.035,1],[0.114,0.69,0.722,1],[0.929,0.855,0.02,1],[0.929,0.855,0.02,1],[0.929,0.855,0.02,1],[0.969,0.58,0,1],[0.969,0.58,0,1],[0.969,0.58,0,1],[1,0,0,1]];
	{
		_ceil = 0;
		_damage = _damagesTotal select _forEachIndex;
		_ceil = ceil _damage;
		if (_ceil > 8) then {_ceil = 8};
		_color = _colors select _ceil;
		((findDisplay 3267) displayCtrl _x) ctrlSetTextColor _color;
	}forEach _idc;
};
//systemChat format ["%1 is the array prior to color",_woundsArray];
[_woundsArray,_damagesTotal] spawn _establishTextColors;
if ((_selection isEqualTo "hitbody") && !(_target isEqualTo player)) then {
	_switchStateStabilize = _damagesTotal findIf {_x > 1.75};
	_switchStateRevive = _damagesTotal findIf {_x > 0};
	if !(lifeState _target == "INCAPACITATED") then {
	ctrlEnable [1607,false];ctrlSetText [1607,"ALIVE"];
	ctrlEnable [1607,false];
	} else {
		_patientStatus = UINameSpace getVariable "EAMS-CurrentPatientStatus";
		_isStable = _patientStatus select 0;
		_isDisabled = _patientStatus select 1;
		_isActive = _patientStatus select 2;
		if ((_isDisabled) && !(CAN_USE_EAMSITEM2(player,_target,'EAMS_Epinephrine'))) then {ctrlSetText [1607,"NO EPI"];ctrlEnable [1607,false];
		} else {
			if ((_switchStateStabilize == -1) && (_isDisabled) && !(_isStable) && (CAN_USE_EAMSITEM2(player,_target,'EAMS_Epinephrine'))) then {
				ctrlSetText [1607,"Stabilize"];
				UINameSpace setVariable ["EAMS-Pulloutofstate",1];
				ctrlEnable [1607,true];
			} else {
				if ((_switchStateRevive == -1) && (_isStable) && (CAN_USE_EAMSITEM2(player,_target,'EAMS_Epinephrine'))) then {
					ctrlSetText [1607,"Revive"];
					UINameSpace setVariable ["EAMS-Pulloutofstate",2];
					ctrlEnable [1607,true];
				} else {
					if (_isStable) then {ctrlSetText [1607,"STABLE"]; ctrlEnable [1607,false]};
					if !(_switchStateStabilize == -1) then {ctrlSetText [1607,"Too Hurt"];ctrlEnable [1607,false]};
				};
			};
		};
	};
} else {ctrlEnable [1607,false];};

_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_PrettyHitPoints = ["Head","Chest","Left Arm","Right Arm","Left Leg","Right Leg"];
//[head,chest,larm,rarm,lleg,rleg]
_hitPointID = _validHitPoints find _selection;
_prettyName = _PrettyHitPoints select _hitPointId;
_totalDamage = _contusions + _velocities + _avulsions + _abrasions;
_limbDamage = _damagesTotal select _hitPointId;
_woundFloor = floor _limbDamage;
_woundMinor = _limbDamage - _woundFloor;
if ((_woundFloor == 0) && (_woundMinor == 0)) exitWith {
	ctrlSetText [1606,"BANDAGED"];
	ctrlEnable [1606,false];
	((findDisplay 3267) displayCtrl 1606) ctrlSetTextColor [0.322,0.988,0.012,1];
	lbAdd [1100,format ["%1 has no wounds.",_prettyName]];
};
lbAdd [1100,"0x Contusions"];
lbAdd [1100,"0x Velocity Wounds"];
lbAdd [1100,"0x Avulsions"];
lbAdd [1100,"0x Abrasions"];
{
	{
		_wounds = [_woundsArray select 0,_woundsArray select 1,_woundsArray select 2,_woundsArray select 3];
		_woundTypeSelection = _wounds select _forEachIndex;
		_limbDamage = _woundTypeSelection select _hitPointId;
		_limbFloor = floor _limbDamage;
		_limbMinor = _limbDamage - _limbFloor;
		//systemChat format ["from %1",_limbDamage];
		((findDisplay 3267) displayCtrl 1100) lbSetText [_forEachIndex, format ["%1x %2s",_limbFloor, _x]];
		if ((_limbFloor < 1) && (_limbMinor > 0)) then {((findDisplay 3267) displayCtrl 1100) lbSetText [_forEachIndex, format ["Minor %1", _x]];};
		_text = lbText [1100,_forEachIndex];
		_splitArr = _text splitString "x ";
		_num = _splitArr select 0;
		if (_num isEqualTo "0") then {((findDisplay 3267) displayCtrl 1100) lbSetText [_forEachIndex, format ["No %1s", _x]];};
	}forEach ["Contusion","Velocity Wound","Avulsion","Abrasion"];
}forEach _woundsArray;
/*if (_woundMinor > 0) then {
	_woundMinorCount = ceil _woundMinor;
	if (_woundFloor < 1) then {
		lbClear 1100;
	};
	lbAdd [1100,format ["%1x Minor Wound",_woundMinorCount]];
};*/
if ((CAN_USE_EAMSITEM2(player,_target,'EAMS_BasicBandage')) || ((CAN_USE_EAMSITEM2(player,_target,'EAMS_BasicBandage_Half')) && (_woundMinor > 0))) then {
	ctrlEnable [1606,true];
	ctrlSetText [1606,"BANDAGE"];
} else {
	((findDisplay 3267) displayCtrl 1606) ctrlSetTextColor [1,0,0,1];
	ctrlEnable [1606,false];
	ctrlSetText [1606,"NO BANDAGE"];
};
