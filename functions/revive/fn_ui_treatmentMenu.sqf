#include "defines.inc"
disableSerialization;
_display = findDisplay 3267;
if !(isNull _display) exitWith {};
params ["_target","_player"];
_acceptableDistance = 3.35;
if ((lifeState player == "INCAPACITATED") || (visibleMap) || (eyePos player select 2 < 0)) exitWith {};
//systemChat format ["%1-%2",_target,_player];

if ((isNull _target) || ((_target distance _player) >= _acceptableDistance)) exitWith {
	UINameSpace setVariable ["EAMS-CurrentPatient",_player];
	_woundsArray = player getVariable [format ["EAMS-%1Wounds","Basic"],[0,0,0,0,0,0]];
	missionNameSpace setVariable ["EAMS-BasicWounds-Target",_woundsArray];
	createDialog "EAMS_GUI_TreatmentMenuBase";
	//["hitbody",_player] spawn eams_fnc_ui_treatmentMenu_state;
};
if !((((_target distance _player) > _acceptableDistance) && (_target isKindOf 'Man')) || !(_target in playableUnits)) exitWith {
	UINameSpace setVariable ["EAMS-CurrentPatient",_target];
	REQUEST_DATA(_player,_target,"EAMS-BasicWounds");
	_woundsArray = missionNameSpace getVariable ["EAMS-BasicWounds-Target",[0,0,0,0,0,0]];
	uisleep 0.14;
	createDialog "EAMS_GUI_TreatmentMenuBase";
};
