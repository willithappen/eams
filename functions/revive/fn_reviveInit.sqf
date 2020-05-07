#include "defines.inc"
params ["_value"];
if (allDisplays isEqualTo [findDisplay 0]) exitWith {};
//if !(isMultiplayer) exitWith {diag_log "EAMS ERROR: EAMS will not function outside of multiplayer"};
//_LIST OF PROJECTILES__
//[configFile >> "CfgAmmo" >> "TYPE", true] call BIS_FNC_ReturnParents;
//BulletBase --> Rifle/Pistol
//ShellBase --> NLAW/RocketLauncher
//GrenadeBase --> Grenade
//ignore damage under the threshold
//private _woundType = "";
//if (isNil "EAMS_ReviveEnabled") then {EAMS_ReviveEnabled = false};
eams_ReviveMode = EAMS_ReviveEnabled;
if !(eams_ReviveMode) exitWith {diag_log "EAMS RPT: Medical Not Enabled"};
diag_log format ["EAMS RPT: Medical Enabled at %1",diag_tickTime];
//Values for everything

eams_revive_duration = 120; // Revive Duration normal
eams_revive_medicSpeedMultiplier = 12; // 12x Normal Value
eams_revive_durationMedic = eams_revive_duration/eams_revive_medicSpeedMultiplier;
eams_revive_bleedOutDuration = 600; // 10 minute bleed out delay
if (isServer) then {
	addMissionEventHandler ["EntityRespawned", {
	 params ["_entity", "_corpse"];
	 if !(isPlayer _entity) exitWith {};
	SET_STATE(_entity,STATE_RESPAWNED);
	}];
};


eams_fatalDamageGlobal = 9.25;
if (!hasInterface || {side player == sideLogic} || (typeOf player == "VirtualCurator_F")) exitWith {};

//Values for PLAYERS BELOW

if (isNull player) then {waitUntil{!isNull player}};
//Values for Player once player exists
[] call eams_fnc_reviveDamageReset;
EAMS_nearPlayers = [];
EAMS_IsInjured = false;
private _playerVar = GET_UNIT_VAR(player);
//_nearbyHandler = [{[] call eams_fnc_collectNearbyValues}, 1, [player]] call CBA_fnc_addPerFrameHandler;
player setVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
/*--------------------------------------------------------------------------------------------------

	EVENT HANDLERS

--------------------------------------------------------------------------------------------------*/
#include "_eventHandlers_add.inc"
