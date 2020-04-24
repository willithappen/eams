#include "defines.inc"

params ["_unit","","_damage","_source","","_index","","_hitPoint"];

//ignore damage under the threshold
if (_damage < 0.05) exitWith {0};

if (alive _unit) then
{
	if (IS_DISABLED(_unit)) then
	{
		//to fix issue where vehicle destruction can happen after player receives damage and get incapacitated
		if (pams_revive_unconsciousStateMode != 0 && {!alive vehicle _unit}) exitWith
		{
			//pams_revive_deathReason = DEATH_REASON_NONE;
			_damage = 100;
		};

		if (pams_revive_bleeding && {_index == -1}) then
		{
			private _damagePrev = damage _unit;
			private _damageRecieved = _damage - _damagePrev;

			private _damageBleed = _unit getVariable [VAR_DAMAGE_BLEED,0];
			private _damageAccumulated = (_unit getVariable [VAR_DAMAGE,0]) + _damageRecieved;

			_unit setVariable [VAR_DAMAGE,_damageAccumulated];

			if (_damageBleed + _damageAccumulated > 0.99) then
			{
				_damage = _damage max 100;
			}
			else
			{
				_damage = MAX_SAFE_DAMAGE min _damage;
			};
		}
		else
		{
			_damage = MAX_SAFE_DAMAGE min _damage;
		};
	}
	else
	{
	//incapacitation mode: basic
		if ((_unit getHitPointDamage "EAMS_Incapacitated") >= 0.88) exitWith {
			private _isCrash = vehicle _unit == _source;
			//make incapacitated unit covered by blood, needed for smooth secure transition (which is actually kill)
			//_unit setDamage MAX_SAFE_DAMAGE;

			//incapacitate unit
			if (!IS_DISABLED(_unit) || isNull _source || {!pams_revive_killfeedShow || {_isCrash}}) then
			{
				SET_STATE(_unit,STATE_INCAPACITATED);
			}
			else
			{
				if (!IS_DISABLED(_unit)) then {SET_STATE(_unit,STATE_INCAPACITATED);};
			};
		_damage = MAX_SAFE_DAMAGE min _damage;
		};
		_damage = MAX_SAFE_DAMAGE min _damage;
	};
};
_damage
