#include "defines.inc"
/*
	Author: willithappen

	Description:
	Resets player"s damage data and recieved damage. Works only locally for player.

	Parameters:
	none

	Returns:
	nothing

	Example:
	[] call eams_fnc_reviveDamageReset;
*/

if (isNull player) exitWith {};

player setDamage 0;
player setVariable [format ["EAMS-%1Wounds","All"],[[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]];
