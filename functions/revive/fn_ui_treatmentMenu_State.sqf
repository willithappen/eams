#include "defines.inc"
disableSerialization;
waitUntil { !isNull findDisplay 3267 };
params ["_selection",["_target",uiNameSpace getVariable ['EAMS-CurrentPatient',objNull]]];
waitUntil { !isNull _target};
waituntil {
	_woundsArray = missionNameSpace getVariable ["EAMS-BasicWounds-Target",[0]];
	count _woundsArray > 1
};
_woundsArray = missionNameSpace getVariable ["EAMS-BasicWounds-Target",[0]];
ctrlSetText [1001,format['Currently Treating: %1',name _target]];
uiNameSpace setVariable ["EAMS-SelectedBodyPart",_selection];
lbClear 1100;
ctrlSetText [1607,""];
_establishTextColors = {
	params ["_damageArray"];
	//IDCS: head, chest, larm, rarm, lleg, relg
	_idc = [1600,1605,1601,1602,1603,1604];
	//COLORS: Green,Yellow,Orange,Red
	_colors = [[0.322,0.988,0.012,1],[0.969,0.925,0.086,1],[0.969,0.584,0.086,1],[1,0,0,1]];
	{
		_ceil = 0;
		_damage = _damageArray select _forEachIndex;
		_ceil = ceil _damage;
		if (_ceil > 3) then {_ceil = 3};
		_color = _colors select _ceil;
		((findDisplay 3267) displayCtrl _x) ctrlSetTextColor _color;
	}forEach _idc;
};
_validHitPoints = ["hithead","hitbody","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_PrettyHitPoints = ["Head","Chest","Left Arm","Right Arm","Left Leg","Right Leg"];
//[head,chest,larm,rarm,lleg,rleg]
_hitPointID = _validHitPoints find _selection;
_woundValue = _woundsArray select _hitPointId;
_prettyName = _PrettyHitPoints select _hitPointId;
[_woundsArray] spawn _establishTextColors;
if ((_selection isEqualTo "hitbody") && !(_target isEqualTo player)) then {
	_switchStateStabilize = _woundsArray findIf {_x > 1.75};
	_switchStateRevive = _woundsArray findIf {_x > 0};
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
_woundFloor = floor _woundValue;
_woundMinor = _woundValue - _woundFloor;
if ((_woundFloor == 0) && (_woundMinor == 0)) exitWith {
	ctrlSetText [1606,"BANDAGED"];
	ctrlEnable [1606,false];
	((findDisplay 3267) displayCtrl 1606) ctrlSetTextColor [0.322,0.988,0.012,1];
	lbAdd [1100,format ["%1 has no wounds.",_prettyName]];
};
lbAdd [1100,format ["%1x Velocity Wounds",_woundFloor]];
if (_woundMinor > 0) then {
	_woundMinorCount = ceil _woundMinor;
	if (_woundFloor < 1) then {
		lbClear 1100;
	};
	lbAdd [1100,format ["%1x Minor Wound",_woundMinorCount]];
};
if ((CAN_USE_EAMSITEM2(player,_target,'EAMS_BasicBandage')) || ((CAN_USE_EAMSITEM2(player,_target,'EAMS_BasicBandage_Half')) && (_woundFloor < 1))) then {
	ctrlEnable [1606,true];
	ctrlSetText [1606,"BANDAGE"];
} else {
	((findDisplay 3267) displayCtrl 1606) ctrlSetTextColor [1,0,0,1];
	ctrlEnable [1606,false];
	ctrlSetText [1606,"NO BANDAGE"];
};
