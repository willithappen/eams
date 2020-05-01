#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Make a unit bleed out over time while incapacitated.

	Parameters:
		_this select 0: OBJECT - Unit that is bleeding out

	Returns:
	True if successful, false if not.
*/
params ["_unit"];
if (isNull _unit || {!local _unit}) exitWith {};

//not bleeding yet
eams_revive_bleeding = false;

//init blood and damage
_unit setVariable [VAR_DAMAGE_BLEED, 0];
//_unit setVariable [VAR_DAMAGE, 0];

//bleed out
_unit spawn
{
	scriptName "eams_fnc_reviveBleedOut: bleeding";

	private _unit = _this;

	sleep 0.1;	//delay the bleeding so all the dmg is properly recieved BEFORE bleeding mechannics start

	eams_revive_bleeding = true;

	//define the bleed out time
	private _timeStart = time;
	private _timeTotal = eams_revive_bleedOutDuration;
	private _blood = 1;
	private _bleed = 0;
	private _damage = 0;
	private _bloodLevel = 0;
	private _bloodLevelPrev = 0;
	waitUntil
	{
		sleep 0.1;

		if (eams_revive_bleeding) then {
		//calculate damage & blood
		//_damage = _unit getVariable [VAR_DAMAGE,0];
		_bleed = (time - _timeStart) / _timeTotal;

		//player incapacitated under water or in burning vehicle dies faster
		if (eyePos _unit select 2 < 0 || {!alive vehicle player}) then {_bleed = _bleed * 5;};

		_blood = 1 - _bleed;

		//get & set bleedout state

			_bloodLevel = floor(_blood * 5); if (_bloodLevel > 3) then {_bloodLevel = 3;};

			if (_bloodLevel != _bloodLevelPrev) then
			{
				_bloodLevelPrev = _bloodLevel;

				_unit setVariable [VAR_BLOOD_LEVEL,_bloodLevel];
			};
		};
		if (IS_DISABLEDLOCAL(_unit)) then
		{
			_unit setVariable [VAR_DAMAGE_BLEED, _bleed];
		};
		//ToDo: Make array of checks for weird cases where animation can wig out
		if (animationState player in ["unconscious","amovpknlmstpsnonwnondnon","unconsciousoutprone","amovpercmstpsraswrfldnon","amovppnemstpsraswrfldnon","amovpknlmstpsraswrfldnon","amovpknlmstpsraswlnrdnon_amovpknlmstpsraswrfldnon_end","ainvpknlmstpsnonwrfldnon_medicend","ainvpknlmstpsnonwrfldr_medic2"]) then {
	     player switchAction ""; player switchMove "unconsciousrevivedefault";
	    };
		//wait for unit to bleeding out be revived
		_unit != player || {_blood <= 0  || {!alive _unit || {IS_NOTSAFEMOVELOCAL(_unit)}}}
	};

	//kill unit if it bled out
	if (_unit == player && {alive _unit && {_blood <=0 }}) then
	{
		_unit setDamage 1;
	};
};
