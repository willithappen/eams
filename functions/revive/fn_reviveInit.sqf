#include "defines.inc"
params ["_value"];
eams_ReviveMode = _value;
if (!(_value) || !(IS_MP)) exitWith {false};

//Values for everything

if (isServer) exitWith {
	waitUntil {diag_tickTime > 5};
	if (isNil "eams_arr_players") then {
		//Players on mission start
		eams_arr_players = [] CBA_fnc_players;
	};
};

eams_revive_duration = 120; // Revive Duration normal
eams_revive_medicSpeedMultiplier = 12; // 12x Normal Value
eams_revive_durationMedic = eams_reviveDuration/eams_revive_medicSpeedMultiplier;
eams_revive_bleedOutDuration = 600; // 10 minute bleed out delay
if (!hasInterface || {side player == sideLogic}) exitWith {};

//Values for PLAYERS BELOW

if (isNull player) then {waitUntil{!isNull player}};
//Values for Player once player exists
[] call eams_fnc_reviveDamageReset;
EAMS_nearPlayers = [];
_nearbyHandler = [{[] call eams_fnc_collectNearbyValues}, 1, [player]] call CBA_fnc_addPerFrameHandler;
[player,"EAMS_U-"] call BIS_fnc_objectVar;
_varString = player;

addMissionEventHandler ["Map", {
	params ["_mapIsOpened", "_mapIsForced"];
	if ((_mapIsOpened) && (IS_DISABLED(player))) exitWith {openMap false};
}];
/*--------------------------------------------------------------------------------------------------

	EVENT HANDLERS

--------------------------------------------------------------------------------------------------*/
#include "_eventHandlers_add.inc"
