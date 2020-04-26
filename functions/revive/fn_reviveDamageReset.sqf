#include "defines.inc"
/*
	Author: Jiri Wainar

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

{player setHitPointDamage [_x,0]} forEach (getAllHitPointsDamage player select 0);
player setDamage 0;