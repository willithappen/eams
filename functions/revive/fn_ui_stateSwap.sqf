#define NO_CHANGE								0
#define TO_STABLE								1
#define TO_REVIVED								2
#define TO_DEAD									3
#define TO_INCON								4
#define TO_GREEN								5
#include "defines.inc"
params ["_unit","_stateToSet"];
switch (_stateToSet) do {
	case NO_CHANGE: {};
	case TO_STABLE: {
		player playAction 'medicStart';
		_duration = eams_revive_duration/8;
		if (CAN_USE_MEDIKIT(player)) then {
			_duration = eams_revive_durationMedic/2;
		};\
	[_duration, [player,_unit], {STABILIZE_COMPLETE(_args select 0,_args select 1); [_args select 1,player] spawn eams_fnc_ui_treatmentMenu;}, {STABILIZE_FAILED(_args select 0,_args select 1)}, 'Stabilizing...',{true},["isNotDragging","notOnMap","isNotInside"]] call ace_common_fnc_progressBar
	};
	case TO_REVIVED: {
		player playAction 'medicStart';
		_duration = eams_revive_duration;
		if (CAN_USE_MEDIKIT(player)) then {
			_duration = eams_revive_durationMedic;
		};
	[_duration, [player,_unit], {REVIVE_COMPLETE(_args select 0,_args select 1); [_args select 1,player] spawn eams_fnc_ui_treatmentMenu;}, {REVIVE_FAILED(_args select 0,_args select 1)}, 'Reviving...',{true},["isNotDragging","notOnMap","isNotInside"]] call ace_common_fnc_progressBar
	};
	case TO_DEAD: {};
	case TO_INCON: {};
	case TO_GREEN: {SET_STATELOCAL(player,STATE_STABILIZED)};
};
