#include "defines.inc"
disableSerialization;
_display = findDisplay 3267;
if !(isNull _display) exitWith {};
params ["_target","_player"];
//systemChat format ["%1-%2",_target,_player];
if (isNull _target) exitWith {
	UINameSpace setVariable ["EAMS-CurrentPatient",_player];
	createDialog "EAMS_GUI_TreatmentMenuBase";
	ctrlSetText [1001,format['Currently Treating: %1',name (uiNameSpace getVariable ['EAMS-CurrentPatient',objNull])]];
	_woundsArray = player getVariable [format ["EAMS-%1Wounds","Basic"],[0,0,0,0,0,0]];
	missionNameSpace setVariable ["EAMS-BasicWounds-Target",_woundsArray];
	["hitchest"] call eams_fnc_ui_treatmentMenu_state;
};
if ((_target distance _player) > 4) exitWith {};

UINameSpace setVariable ["EAMS-CurrentPatient",_target];
createDialog "EAMS_GUI_TreatmentMenuBase";
ctrlSetText [1001,format['Currently Treating: %1',name (uiNameSpace getVariable ['EAMS-CurrentPatient',objNull])]];
REQUEST_DATA(_player,_target,"EAMS-BasicWounds");
["hitchest"] call eams_fnc_ui_treatmentMenu_state;
