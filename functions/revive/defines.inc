/*--------------------------------------------------------------------------------------------------

	SYSTEM SETTINGS

--------------------------------------------------------------------------------------------------*/
#define REVIVE_SIDES						[WEST,EAST,RESISTANCE,CIVILIAN]
#define REVIVE_SIDES_TXT					['West','East','Guer','Civ']
#define REVIVE_DISTANCE						4
#define REVIVE_DISTANCE_BODY_CENTER			3.5

//behavior settings
#define REVIVE_MEDIKIT_MULTIPLIER			2		//multiplier acting on revive time if the player has a medikit
#define DEFAULT_REVIVE_TIME					6		//default time (in seconds) that it takes to revive a unit
#define DEFAULT_FORCE_RESPAWN_TIME			3		//default time (in seconds) that it takes to force respawn
#define DEFAULT_BLEEDOUT_TIME				120		//default time (in seconds) that it takes to bleed out

//damage model
#define MAX_SAFE_DAMAGE						0.975
#define EAMS_TRANSMIT_DISTANCE				3.75

#define RATING_KILL							200
#define RATING_TEAMKILL						-1000
#define RATING_EXECUTE						-400
#define RATING_REVIVE						RATING_KILL
#define RATING_SECURE						RATING_KILL

/*--------------------------------------------------------------------------------------------------

	INIT MODES

--------------------------------------------------------------------------------------------------*/
#define REVIVE_MODE_AUTODETECT					-1	//Revive2 compatability solution
#define REVIVE_MODE_DISABLED					0
#define REVIVE_MODE_ENABLED_ALL_PLAYERS			1
#define REVIVE_MODE_ENABLED_INDIVIDUAL_PLAYERS	2

#define REVIVE_MODE								(missionNamespace getVariable ['eams_revive_mode',REVIVE_MODE_DISABLED])

/*--------------------------------------------------------------------------------------------------

	PLAYER VARIABLE NAMES

--------------------------------------------------------------------------------------------------*/
//unit variable names
#define VAR_REVIVE_ENABLED				'EAMS_Rev_Var_enabled'

//broadcasted unit variables
#define VAR_TRANSFER_STATE				'EAMS_Rev_Var'
#define VAR_TRANSFER_FORCING_RESPAWN	'EAMS_Rev_VarF'
#define VAR_TRANSFER_BEING_REVIVED		'EAMS_Rev_VarB'
#define VAR_TRANSFER_BEING_STABILIZED	'EAMS_Rev_VarS'
#define VAR_BLOOD_LEVEL					'EAMS_Rev_VarL'

//local unit variables
#define VAR_STATE						'EAMS-ReviveState'
#define VAR_STATE_TARGET				'EAMS-ReviveState-Target'
#define VAR_STATE_PREV					'EAMS_Rev_Var_statePrev'

#define VAR_BEING_REVIVED				'EAMS_Rev_Var_being_revived'
#define VAR_BEING_STABILIZED			'EAMS_Rev_Var_being_stabilized'
#define VAR_FORCING_RESPAWN				'EAMS_Rev_Var_forcing_respawn'

//#define VAR_DAMAGE						'EAMS_Rev_Var_damage'
#define VAR_DAMAGE_BLEED				'EAMS-ReviveBleed'

#define VAR_CAMERA_VIEW					'EAMS_Rev_Var_camera'

#define VAR_INCAPACITATED_POS			'EAMS_Rev_Var_incap_pos'
#define VAR_INCAPACITATED_BACKUPPOS		'EAMS_Rev_Var_incap_backuppos'
#define VAR_INCAPACITATED_DIR			'EAMS_Rev_Var_incap_dir'
#define VAR_INCAPACITATED_BODY			'EAMS_Rev_Var_incap_corpse'
//In Order - [[head,wounds],[chest,wounds],[leftArm,wounds],[rightArm,wounds],[leftLeg,wounds],[rightLeg,wounds]]
#define EAMS_LIMBS						[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]]
#define EAMS_BLOODRATIO					[4750]
// [MIN,AVG,MAX]
#define EAMS_HEARTRATE					[60,0,100]


#define AI_PROTECTION_ACTIVATE(unit)	if (!captive unit) then {unit setCaptive true;unit setVariable ['EAMS_Rev_Var_captiveForced',true];} else {unit setVariable ['EAMS_Rev_Var_captiveForced',false];}
#define AI_PROTECTION_DEACTIVATE(unit)	if (unit getVariable ['EAMS_Rev_Var_captiveForced',false]) then {unit setVariable ['EAMS_Rev_Var_captiveForced',false];unit setCaptive false;}

/*--------------------------------------------------------------------------------------------------

	GENERAL 'QUALITY OF LIFE' MACROS

--------------------------------------------------------------------------------------------------*/
#define GET_UNIT_VAR(unit)				([unit,'EAMS_U-'] call bis_fnc_objectVar)
#define GET_UNIT(unitVar)				(missionNamespace getVariable [unitVar,objNull])

#define IN_VEHICLE(unit)				(vehicle unit != unit)

#define ENABLE_REVIVE(unit,state)		(unit setVariable [VAR_REVIVE_ENABLED, state, true])
#define REVIVE_ENABLED(unit)			(unit getVariable [VAR_REVIVE_ENABLED, false])
#define REVIVE_ALLOWED(unit)			([unit] call eams_fnc_reviveAllowed)
#define STABILIZE_ALLOWED(unit)			([unit] call eams_fnc_stabilizeAllowed)
#define REVIVE_ALLOWED2(unit,target)	([unit,target] call eams_fnc_reviveAllowed)
#define STABILIZE_ALLOWED2(unit,target)	([unit,target] call eams_fnc_stabilizeAllowed)
#define IS_MP							isMultiplayer

/*--------------------------------------------------------------------------------------------------

	REQUIREMENTS

--------------------------------------------------------------------------------------------------*/
#define CAN_USE_MEDIKIT(unit)			(unit getUnitTrait 'Medic' && {'EAMS_MedicBag' in items unit})
#define CAN_USE_MEDIKIT2(unit,target)	(unit getUnitTrait 'Medic' && {('EAMS_MedicBag' in items unit || {(!isNull target && {'EAMS_MedicBag' in items target})})})
#define CAN_USE_EAMSITEM(unit,type) 	(type in items unit)
#define CAN_USE_EAMSITEM2(unit,target,type)		(type in items unit || {(!isNull target && {type in items target})})
#define EAMS_SET_RETURNITEM(unit,item)	unit setVariable ['EAMS-ReturnItem',item]
#define EAMS_SET_RETURNITEM2(unit,item,value)	unit setVariable ['EAMS-ReturnItem',item]; unit setVariable ['EAMS-ReturnItem-Split',true]
#define EAMS_RETURNITEM(unit)					unit addItem (unit getVariable ['EAMS-ReturnItem','EAMS_BasicBandage']); if (unit getVariable ['EAMS-ReturnItem-Split',false]) then {unit removeItem 'EAMS_BasicBandage_Half'}
#define EAMS_BANDAGESPLIT_BASIC(unit) 	unit removeItem 'EAMS_BasicBandage';unit addItem 'EAMS_BasicBandage_Half'
#define CAN_STABILIZE(target) 			([target] call eams_fnc_StabilizeIsValid)

/*--------------------------------------------------------------------------------------------------

	PLAYER ACTION FLAGS

--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------

	REMOTE VARIABLE TRANSMISSION

--------------------------------------------------------------------------------------------------*/
#define REQUEST_DATA(requester,requestee,variable) [requester,requestee,variable] remoteExecCall ['eams_fnc_requestData',requestee]
#define RETURN_DATAXTRA(transmitter,reciever,variable,type,selID,damage) [transmitter,reciever,variable,type,selID,damage] remoteExecCall ['eams_fnc_returnData',transmitter]
#define RETURN_DATAXTRATAKE(transmitter,reciever,variable,type,selID,damage,takeaway) [transmitter,reciever,variable,type,selID,damage,takeaway] remoteExecCall ['eams_fnc_returnData',transmitter]
#define RETURN_DATA(transmitter,reciever,variable) [transmitter,reciever,variable] remoteExecCall ['eams_fnc_returnData',transmitter]
/*--------------------------------------------------------------------------------------------------

	PLAYER STATES

--------------------------------------------------------------------------------------------------*/
#define STATE_RESPAWNED								0
#define STATE_REVIVED								1
#define STATE_INCAPACITATED							2
#define STATE_DEAD									3
#define STATE_STABILIZED							4

#define GET_STATE_STR(state)						format['%1(%2)',['RESPAWNED','REVIVED','INCAPACITATED','DEAD','STABILIZED'] select state,state]

#define SET_STATE(unit,state)						['',state,unit] remoteExecCall ['eams_fnc_reviveOnState',unit];missionNameSpace setVariable [VAR_STATE, state, true]; RETURN_DATA(player,unit,VAR_STATE)
#define SET_STATE_XTRA(unit,state,source)			['',[state,source],unit] call eams_fnc_reviveOnState;unit setVariable [VAR_TRANSFER_STATE, [state,source], true]
#define SET_STATE_XTRA2(unit,state,source,reason)	['',[state,source,reason],unit] call eams_fnc_reviveOnState;unit setVariable [VAR_TRANSFER_STATE, [state,source,reason], true]

#define GET_STATE(unit)								(unit getVariable [VAR_STATE, STATE_RESPAWNED])
#define GET_STATE_TARGET(target)					[target] call eams_fnc_stateTarget
#define IS_DISABLED(target)							(GET_STATE_TARGET(target) == STATE_INCAPACITATED)
#define IS_DISABLEDLOCAL(unit)						(GET_STATE(unit) == STATE_INCAPACITATED)
#define IS_STABLE(target)							(GET_STATE_TARGET(target) == STATE_STABILIZED)
#define IS_STABLELOCAL(unit)						(GET_STATE(unit) == STATE_STABILIZED)
#define IS_NOTSAFEMOVE(target)						(!IS_DISABLED(unit) && {!IS_STABLE(unit)})
#define IS_NOTSAFEMOVELOCAL(unit)					(!IS_DISABLEDLOCAL(unit) && {!IS_STABLELOCAL(unit)})
#define IS_ACTIVE(target)							(GET_STATE_TARGET(target) < STATE_INCAPACITATED)
#define IS_ACTIVELOCAL(unit)							(GET_STATE(unit) < STATE_INCAPACITATED)
#define IS_HEALTHY(unit)							[unit,'patch'] call eams_fnc_canHealLimb
/*--------------------------------------------------------------------------------------------------

	EAMS Defines

--------------------------------------------------------------------------------------------------*/
#define STABILIZE_COMPLETE(unit,target)								([unit,target] call eams_fnc_stabilizeComplete)
#define STABILIZE_FAILED(unit,target)								([unit,target] call eams_fnc_stabilizeFailed)
#define REVIVE_COMPLETE(unit,target)								([unit,target] call eams_fnc_ReviveComplete)
#define REVIVE_FAILED(unit,target)									([unit,target] call eams_fnc_ReviveFailed)
#define EAMS_GET_WOUNDSSELF(space,type)								space getVariable [format ['EAMS-%1Wounds',str(type)],[0,0,0,0,0,0]]
