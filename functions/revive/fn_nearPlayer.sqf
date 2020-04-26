/* ----------------------------------------------------------------------------
Function: EAMS_fnc_nearPlayer
Description:
    Check whether these are any players within a certain distance of the player.
Parameters:
    _player     - the entity to check the distance from. <OBJECT>
    _distance - the desired distance. <NUMBER>
Returns:
    true if there are any players within the given distance of the unit, false if there aren't. <BOOLEAN>
Examples:
    (begin example)
        [unit, distance] call CBA_fnc_nearPlayer
    (end)
Original Author: Original script by CBA https://github.com/CBATeam/CBA_A3/blob/fbd59d2ac1f85da79ea18a53b2d14e3ea285f60a/addons/common/fnc_nearPlayer.sqf
EAMS Version that discards the player by willithappen
---------------------------------------------------------------------------- */
params [["_distance", 0]];

private _position = player call CBA_fnc_getPos;
private _return = false;

{
    if (_position distance _x < _distance) exitWith {
        _return = true;
    };
} forEach (([] call CBA_fnc_players) - [player]);

_return
