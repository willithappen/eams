#include "defines.inc"
disableSerialization;
params ["_selection"];
uiNameSpace setVariable ["EAMS-SelectedBodyPart",_selection];
lbClear 1100;
ctrlSetText [1607,""];
_validHitPoints = ["hithead","hitchest","hitleftarm","hitrightarm","hitleftleg","hitrightleg"];
_woundsArray = missionNameSpace getVariable ["EAMS-BasicWounds-Target",[0,0,0,0,0,0]];
//[head,chest,larm,rarm,lleg,rleg]
_hitPointID = _validHitPoints find _selection;
_woundValue = _woundsArray select _hitPointId;

_woundFloor = floor _woundValue;
_woundMinor = _woundValue - _woundFloor;
lbAdd [1100,format ["%1x Velocity Wounds",_woundFloor]];
if (_woundMinor > 0) then {
	_woundMinorCount = ceil _woundMinor;
	lbAdd [1100,format ["%1x Minor Wound",_woundMinorCount]];
};
//"EAMS_GUI_TM_SelectBandage" ctrlSetEventHandler ["OnButtonClick","systemChat str(_woundValue)"];


if (_selection isEqualTo "hitchest") then {
	_switchStateStabilize = _woundsArray findIf {_x > 1.75};
	_switchStateRevive = _woundsArray findIf {_x > 0};
	if (_switchStateStabilize == -1) then {
		ctrlSetText [1607,"Stabilize"];
	};
	if (_switchStateRevive == -1) then {
		ctrlSetText [1607,"Revive"];
	};
};
