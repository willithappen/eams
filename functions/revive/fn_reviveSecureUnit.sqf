#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Make player secured (killed without execution penalties) by _source unit.
*/

private _unit = param [0,objNull,[objNull]];
private _source = param [1,objNull,[objNull]];

if (local _unit) then
{
	//set death reason
	pams_revive_deathReason = DEATH_REASON_SECURED;
	pams_revive_deathSource = _source;

	titleCut ["","BLACK OUT",0.5];
	sleep 0.5;

	//switch animation & kill unit
	_unit switchMove "revive_secured";
	_unit setDamage 1;

	titleCut ["","BLACK IN",0.5];
}
else
{
	_unit switchMove "revive_secured";
};


