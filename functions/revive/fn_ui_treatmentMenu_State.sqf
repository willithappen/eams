#include "defines.inc"
disableSerialization;
params ["_selection"];
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
_woundsArray = missionNameSpace getVariable ["EAMS-BasicWounds-Target",[0,0,0,0,0,0]];
//[head,chest,larm,rarm,lleg,rleg]
_hitPointID = _validHitPoints find _selection;
_woundValue = _woundsArray select _hitPointId;
_prettyName = _PrettyHitPoints select _hitPointId;
[_woundsArray] call _establishTextColors;
if (_selection isEqualTo "hitbody") then {
	_switchStateStabilize = _woundsArray findIf {_x > 1.75};
	_switchStateRevive = _woundsArray findIf {_x > 0};
	if (_switchStateStabilize == -1) then {
		ctrlSetText [1607,"Stabilize"];
	};
	if (_switchStateRevive == -1) then {
		ctrlSetText [1607,"Revive"];
	};
};
_woundFloor = floor _woundValue;
_woundMinor = _woundValue - _woundFloor;
if (_woundFloor == 0) exitWith {
	lbAdd [1100,format ["%1 has no wounds.",_prettyName]];
};
lbAdd [1100,format ["%1x Velocity Wounds",_woundFloor]];
if (_woundMinor > 0) then {
	_woundMinorCount = ceil _woundMinor;
	if (_woundFloor < 1) then {lbClear 1100};
	lbAdd [1100,format ["%1x Minor Wound",_woundMinorCount]];
};
//"EAMS_GUI_TM_SelectBandage" ctrlSetEventHandler ["OnButtonClick","systemChat str(_woundValue)"];
