#include "defines.inc"
if (!hasInterface || {side player == sideLogic} || (typeOf player == "VirtualCurator_F")) exitWith {};
disableSerialization;
_display = findDisplay 3267;
if !(isNull _display) exitWith {};
params ["_target","_player"];
_acceptableDistance = 3.35;
if ((lifeState player == "INCAPACITATED") || (visibleMap) || (eyePos player select 2 < 0)) exitWith {};
//systemChat format ["%1-%2",_target,_player];

if ((isNull _target) || ((_target distance _player) >= _acceptableDistance) || !(_target isKindOf 'Man')) exitWith {
	UINameSpace setVariable ["EAMS-CurrentPatient",_player];
	_allWounds = player getVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
	missionNameSpace setVariable ["EAMS-AllWounds-Target",_allWounds];
	createDialog "EAMS_GUI_TreatmentMenuBase";
	//["hitbody",_player] spawn eams_fnc_ui_treatmentMenu_state;
};
if !((((_target distance _player) > _acceptableDistance) && (_target isKindOf 'Man')) || !(_target in playableUnits)) exitWith {
	_isStable = IS_STABLE(_target);
	_isDisabled = IS_DISABLED(_target);
	_isActive = IS_ACTIVE(_target);
	UINameSpace setVariable ["EAMS-CurrentPatientStatus",[_isStable,_isDisabled,_isActive]];
	UINameSpace setVariable ["EAMS-CurrentPatient",_target];
	REQUEST_DATA(_player,_target,"EAMS-AllWounds");
	createDialog "EAMS_GUI_TreatmentMenuBase";
};
