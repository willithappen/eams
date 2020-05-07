/*
#include "defines.inc"
if (isNull player) exitWith {};
if !([EAMS_TRANSMIT_DISTANCE] call EAMS_fnc_nearPlayer) exitWith {EAMS_NearPlayers = []};
if (count EAMS_NearPlayers == 0) exitWith {false};
private _nearPlayersNew = [];
private _nearPlayersOld = EAMS_nearPlayers;
private _position = player call CBA_fnc_getPos;
{
 if (_position distance _x <= 3) then {
 _nearPlayersNew pushBack _x;
 };
} forEach (([] call CBA_fnc_players) - [player]);
ToDo - Future (Only conduct variable grabs when there is a new unit nearby/player moves around)
_nearPlayersNew sort true;
_nearPlayersOld sort true;
if (_nearPlayersNew isEqualTo _nearPlayersOld) exitWith {false};

EAMS_nearPlayers = _nearPlayersNew;
*/
