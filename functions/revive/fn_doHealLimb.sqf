#include "defines.inc"
/*
	Author: willithappen

	Description:
	Heals necesarry limb to required amount
	Exits with True

	Parameters:
	0: unit
	1: LIMB FAKE
		head
		chest
		arms
		legs
	Nn: REAL LIMB
		hitface/hitneck/hithead
		hitpelvis/hitabdomen/hitdiaphragm/hitchest/hitbody
		hitArms/hitHands
		hitLegs

	Example: [_target,'head'] call pams_fnc_canHealLimb; -- Returns true or false
	Example: [_target,'hitArms',true] call pams_fnc_canHealLimb; -- Returns a Number
	Returns:
	none
*/
params ['_injured','_limb',['_healer',objNull]];

_sd = false;
//systemChat str(_limb);
_healer playAction 'medicStart';
_duration = pams_revive_duration/7;
if (CAN_USE_MEDIKIT(_healer)) then {
	_duration = pams_revive_durationMedic/3;
};
_currentDamage = _injured getHitPointDamage _limb;
	if (_currentDamage <= 0.349) then {
		damageToHeal = 0;
		//systemChat format ["%1 Damage and Current %2 N2",damageToHeal,_currentDamage];
		//Does Healer have a half piece to use?
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage_Half')) then {
			_healer removeItem 'EAMS_BasicBandage_Half'} else {
			//Does Injured have a half piece to use?
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage_Half')) then {_injured removeItem 'EAMS_BasicBandage_Half'} else {
				//Does healer have a full piece to use? Convert to a half piece if so
				if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer)} else {
					//Does injured have a full piece to use? Convert to a half piece if so
					if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured)};
				};
			};
		};
	};
	if ((_currentDamage > 0.349) && (_currentDamage <= 0.49)) then {
		damageToHeal = _currentDamage - 0.3;
		//systemChat format ["%1 Damage and Current %2 N2",damageToHeal,_currentDamage];
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured)};
		};
	};
	if (_currentDamage > 0.49) then {
		damageToHeal = _currentDamage - 0.5;
		//systemChat format ["%1 Damage and Current %2 N2",damageToHeal,_currentDamage];
		if (CAN_USE_EAMSITEM(_healer,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_healer)} else {
			if (CAN_USE_EAMSITEM(_injured,'EAMS_BasicBandage')) then {EAMS_BANDAGESPLIT_BASIC(_injured)};
		};
	};
//systemChat format ["%1 Damage and Current %2 N3",damageToHeal,_currentDamage];
_hitPointDamage = {_this select 0 setHitPointDamage [_this select 1,_this select 2];};
[_duration,[_injured,_limb,_healer,damageToHeal],
{
	params ["_args"];
	(_args select 2) playAction 'MedicStop';

	[_args, {
		(_this select 0) setHitPointDamage [_this select 1, _this select 3];
	}] remoteExecCall ["BIS_FNC_CALL",0];
},
{
	params ["_args"];
	(_args select 2) playAction 'medicStop';
}, 'Bandaging...'] call ace_common_fnc_progressBar;

if (_sd) exitWith {true};
false
