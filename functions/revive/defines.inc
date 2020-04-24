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
#define MAX_SAFE_DAMAGE						0.965

/*--------------------------------------------------------------------------------------------------

	DEATH MESSAGES

--------------------------------------------------------------------------------------------------*/
//kill-feed messages
#define MSG_SECURED							'%1 was secured'
#define MSG_SECURED_BY						'%1 was secured by %2'
#define MSG_INCAPACITATED					(localize 'STR_A3_Revive_MSG_INCAPACITATED')				//%1 was incapacitated
#define MSG_INCAPACITATED_BY				(localize 'STR_A3_Revive_MSG_INCAPACITATED_BY')				//%1 was incapacitated by %2
#define MSG_INCAPACITATED_BY_FF				(localize 'STR_A3_Revive_MSG_INCAPACITATED_BY_FF')			//%1 was incapacitated by %2 (friendly fire)
#define MSG_KILLED							(localize 'STR_A3_Revive_MSG_KILLED')						//%1 was killed
#define MSG_KILLED_BY						(localize 'STR_A3_Revive_MSG_KILLED_BY')					//%1 was killed by %2
#define MSG_KILLED_BY_FF					(localize 'STR_A3_Revive_MSG_KILLED_BY_FF')					//%1 was killed by %2 (friendly fire)
#define MSG_EXECUTED						(localize 'STR_A3_Revive_MSG_EXECUTED')						//%1 was executed
#define MSG_EXECUTED_BY						(localize 'STR_A3_Revive_MSG_EXECUTED_BY')					//%1 was executed by %2
#define MSG_EXECUTED_BY_FF					(localize 'STR_A3_Revive_MSG_EXECUTED_BY_FF')				//%1 was executed by %2 (friendly fire)
#define MSG_REVIVED							(localize 'STR_A3_Revive_MSG_REVIVED')						//%1 was revived
#define MSG_REVIVED_BY						(localize 'STR_A3_Revive_MSG_REVIVED_BY')					//%1 was revived by %2
#define MSG_FORCED_RESPAWN					(localize 'STR_A3_Revive_MSG_FORCED_RESPAWN')				//%1 forced respawn
#define MSG_BLEDOUT							(localize 'STR_A3_Revive_MSG_BLEDOUT')						//%1 bled out
#define MSG_DROWNED							(localize 'STR_A3_Revive_MSG_DROWNED')						//%1 drowned
#define MSG_DIED							(localize 'STR_A3_Revive_MSG_DIED')							//%1 died
#define MSG_SUICIDED						(localize 'STR_A3_Revive_MSG_SUICIDED')						//%1 suicided
#define	MSG_NAME_TEMPLATE_AI				(localize 'STR_A3_Revive_MSG_NAME_TEMPLATE_AI')				//%1 (AI)

//for everyone
#define DEATH_REASON_UNKNOWN				-1
#define DEATH_REASON_NONE					0
#define DEATH_REASON_EXECUTED				1
#define DEATH_REASON_SUICIDED				2
#define DEATH_REASON_SECURED				3

//for friendlies only (>10)
#define DEATH_REASON_BLEEDOUT				11
#define DEATH_REASON_FORCED_RESPAWN			12
#define DEATH_REASON_DROWNED				13

#define RATING_KILL							200
#define RATING_TEAMKILL						-1000
#define RATING_EXECUTE						-400
#define RATING_REVIVE						RATING_KILL
#define RATING_SECURE						RATING_KILL

/*--------------------------------------------------------------------------------------------------

	REVIVE ALLOW CHECK

--------------------------------------------------------------------------------------------------*/
/*
#define TXT_REQUIRE_MEDIC						'<t color='#ffae00'>Medic</t> Required'
#define TXT_REQUIRE_MEDIKIT						'<t color='#ffae00'>Medikit</t> Required'
#define TXT_REQUIRE_FAK							'<t color='#ffae00'>First Aid Kit</t> Required'
#define TXT_REQUIRE_MEDIKIT_OR_FAK				'<t color='#ffae00'>Medikit</t> or <t color='#ffae00'>First Aid Kit</t> Required'
*/

#define TXT_REQUIRE_MEDIC						'Medic Required'
#define TXT_REQUIRE_MEDIKIT						'Medikit Required'
#define TXT_REQUIRE_FAK							'First Aid Kit Required'
#define TXT_REQUIRE_MEDIKIT_OR_FAK				'Medikit or First Aid Kit Required'

#define TXT_REVIVE_SYSTEM_DISABLED				'Revive System Disabled'
#define TXT_REVIVE_DISABLED						'Revive Disabled'

//target independent (< -10)
#define ALLOW_CHECK_REQUIRE_MEDIC				-13
#define ALLOW_CHECK_REQUIRE_MEDIKIT				-2
#define ALLOW_CHECK_REQUIRE_FAK					-3
#define ALLOW_CHECK_REQUIRE_MEDIKIT_OR_FAK		-4
#define ALLOW_CHECK_REVIVE_SYSTEM_DISABLED		-11
#define ALLOW_CHECK_REVIVE_DISABLED				-12
#define ALLOW_CHECK_NULL						-14			//player is not pointing at the target or player is NULL (?)

//will not consume FAK (> 10)
#define ALLOW_CHECK_OK_USE_FAK					1
#define ALLOW_CHECK_OK							11
#define ALLOW_CHECK_OK_USE_MEDIKIT				12

/*--------------------------------------------------------------------------------------------------

	INIT MODES

--------------------------------------------------------------------------------------------------*/
#define REVIVE_MODE_AUTODETECT					-1	//Revive2 compatability solution
#define REVIVE_MODE_DISABLED					0
#define REVIVE_MODE_ENABLED_ALL_PLAYERS			1
#define REVIVE_MODE_ENABLED_INDIVIDUAL_PLAYERS	2

#define REVIVE_MODE								(missionNamespace getVariable ['pams_revive_mode',REVIVE_MODE_DISABLED])

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
#define VAR_STATE						'EAMS_Rev_Var_state'
#define VAR_STATE_PREV					'EAMS_Rev_Var_statePrev'

#define VAR_BEING_REVIVED				'EAMS_Rev_Var_being_revived'
#define VAR_BEING_STABILIZED			'EAMS_Rev_Var_being_stabilized'
#define VAR_FORCING_RESPAWN				'EAMS_Rev_Var_forcing_respawn'

#define VAR_DAMAGE						'EAMS_Rev_Var_damage'
#define VAR_DAMAGE_BLEED				'EAMS_Rev_Var_bleed'
#define VAR_ACTION_ID_REVIVE			'EAMS_Rev_Var_actionID_revive'
#define VAR_ACTION_ID_STABILIZE			'EAMS_Rev_Var_actionID_stabilize'
#define VAR_ACTION_ID_RESPAWN			'EAMS_Rev_Var_actionID_respawn'
#define VAR_ACTION_ID_SECURE			'EAMS_Rev_Var_actionID_secure'

#define VAR_CAMERA_VIEW					'EAMS_Rev_Var_camera'

#define VAR_INCAPACITATED_POS			'EAMS_Rev_Var_incap_pos'
#define VAR_INCAPACITATED_BACKUPPOS		'EAMS_Rev_Var_incap_backuppos'
#define VAR_INCAPACITATED_DIR			'EAMS_Rev_Var_incap_dir'
#define VAR_INCAPACITATED_BODY			'EAMS_Rev_Var_incap_corpse'

#define AI_PROTECTION_ACTIVATE(unit)	if (!captive unit) then {unit setCaptive true;unit setVariable ['EAMS_Rev_Var_captiveForced',true];} else {unit setVariable ['EAMS_Rev_Var_captiveForced',false];}
#define AI_PROTECTION_DEACTIVATE(unit)	if (unit getVariable ['EAMS_Rev_Var_captiveForced',false]) then {unit setVariable ['EAMS_Rev_Var_captiveForced',false];unit setCaptive false;}

/*--------------------------------------------------------------------------------------------------

	GENERAL 'QUALITY OF LIFE' MACROS

--------------------------------------------------------------------------------------------------*/
#define GET_UNIT_VAR(unit)				([unit] call bis_fnc_objectVar)
#define GET_UNIT(unitVar)				(missionNamespace getVariable [unitVar,objNull])

#define IN_VEHICLE(unit)				(vehicle unit != unit)

#define ENABLE_REVIVE(unit,state)		(unit setVariable [VAR_REVIVE_ENABLED, state, true])
#define REVIVE_ENABLED(unit)			(unit getVariable [VAR_REVIVE_ENABLED, false])
#define REVIVE_ALLOWED(unit)			([unit] call pams_fnc_reviveAllowed)
#define STABILIZE_ALLOWED(unit)			([unit] call pams_fnc_stabilizeAllowed)
#define REVIVE_ALLOWED2(unit,target)	([unit,target] call pams_fnc_reviveAllowed)
#define STABILIZE_ALLOWED2(unit,target)	([unit,target] call pams_fnc_stabilizeAllowed)
#define IS_MP							isMultiplayer

/*--------------------------------------------------------------------------------------------------

	REQUIREMENTS

--------------------------------------------------------------------------------------------------*/
#define CAN_USE_MEDIKIT(unit)			(unit getUnitTrait 'Medic' && {'EAMS_MedicBag' in items unit})
#define CAN_USE_MEDIKIT2(unit,target)	(unit getUnitTrait 'Medic' && {('EAMS_MedicBag' in items unit || {(!isNull target && {'EAMS_MedicBag' in items target})})})
#define CAN_USE_FAK(unit)				('FirstAidKit' in items unit)
#define CAN_USE_FAK2(unit,target)		('FirstAidKit' in items unit || {(!isNull target && {'FirstAidKit' in items target})})

#define CAN_USE_EAMSITEM(unit,type) 	(type in items unit)
#define CAN_USE_EAMSITEM2(unit,target,type)		(type in items unit || {(!isNull target && {type in items target})})
#define EAMS_BANDAGESPLIT_BASIC(unit) 	unit removeItem 'EAMS_BasicBandage';unit addItem 'EAMS_BasicBandage_Half'
#define CAN_STABILIZE(target) 			([target] call pams_fnc_StabilizeIsValid)

/*--------------------------------------------------------------------------------------------------

	PLAYER ACTION FLAGS

--------------------------------------------------------------------------------------------------*/
#define IS_BEING_REVIVED(unit)					(unit getVariable [VAR_BEING_REVIVED, false])
#define IS_BEING_STABILIZED(unit)				(unit getVariable [VAR_BEING_STABILIZED, false])
#define IS_FORCING_RESPAWN(unit)				(unit getVariable [VAR_FORCING_RESPAWN, false])

#define SET_BEING_REVIVED(unit,state)			['',state,unit] call pams_fnc_reviveOnBeingRevived;unit setVariable [VAR_TRANSFER_BEING_REVIVED, state, true]
#define SET_BEING_STABILIZED(unit,state)		['',state,unit] call pams_fnc_reviveOnBeingStabilized;unit setVariable [VAR_TRANSFER_BEING_STABILIZED, state, true]
#define SET_FORCING_RESPAWN(unit,state)			['',state,unit] call pams_fnc_reviveOnForcingRespawn;unit setVariable [VAR_TRANSFER_FORCING_RESPAWN, state, true]

#define SET_BEING_REVIVED_LOCAL(unit,state)		['',state,unit] call pams_fnc_reviveOnBeingRevived;unit setVariable [VAR_TRANSFER_BEING_REVIVED, state]
#define SET_BEING_STABILIZED_LOCAL(unit,state)	['',state,unit] call pams_fnc_reviveOnBeingStabilized;unit setVariable [VAR_TRANSFER_BEING_STABILIZED, state]
#define SET_FORCING_RESPAWN_LOCAL(unit,state)	['',state,unit] call pams_fnc_reviveOnForcingRespawn;unit setVariable [VAR_TRANSFER_FORCING_RESPAWN, state]

/*--------------------------------------------------------------------------------------------------

	PLAYER STATES

--------------------------------------------------------------------------------------------------*/
#define STATE_RESPAWNED								0
#define STATE_REVIVED								1
#define STATE_INCAPACITATED							2
#define STATE_DEAD									3
#define STATE_STABILIZED							4

#define GET_STATE_STR(state)						format['%1(%2)',['RESPAWNED','REVIVED','INCAPACITATED','DEAD','STABILIZED'] select state,state]

#define SET_STATE(unit,state)						['',state,unit] call pams_fnc_reviveOnState;unit setVariable [VAR_TRANSFER_STATE, state, true]
#define SET_STATE_XTRA(unit,state,source)			['',[state,source],unit] call pams_fnc_reviveOnState;unit setVariable [VAR_TRANSFER_STATE, [state,source], true]
#define SET_STATE_XTRA2(unit,state,source,reason)	['',[state,source,reason],unit] call pams_fnc_reviveOnState;unit setVariable [VAR_TRANSFER_STATE, [state,source,reason], true]

#define GET_STATE(unit)								(unit getVariable [VAR_STATE, STATE_RESPAWNED])
#define IS_DISABLED(unit)							(GET_STATE(unit) == STATE_INCAPACITATED)
#define IS_STABLE(unit)								(GET_STATE(unit) == STATE_STABILIZED)
#define IS_NOTSAFEMOVE(unit)						(!IS_DISABLED(unit) && {!IS_STABLE(unit)})
#define IS_ACTIVE(unit)								(GET_STATE(unit) < STATE_INCAPACITATED)
#define IS_HEALTHY(unit)							(((unit getHitPointDamage 'Incapacitated') <= 0.35))
/*--------------------------------------------------------------------------------------------------

	EAMS Defines

--------------------------------------------------------------------------------------------------*/
#define STABILIZE_COMPLETE(unit,target)								([unit,target] call pams_fnc_stabilizeComplete)
#define STABILIZE_FAILED(unit,target)								([unit,target] call pams_fnc_stabilizeFailed)
#define REVIVE_COMPLETE(unit,target)								([unit,target] call pams_fnc_ReviveComplete)
#define REVIVE_FAILED(unit,target)									([unit,target] call pams_fnc_ReviveFailed)
/*--------------------------------------------------------------------------------------------------

	ICON STATES

--------------------------------------------------------------------------------------------------*/
#define ICON_STATE_ADD						-1
#define ICON_STATE_REMOVE					-2
#define ICON_STATE_FORCING_RESPAWN			-3
#define ICON_STATE_BEING_REVIVED			-4
#define ICON_STATE_BEING_STABILIZED			-5

#define ICON_STATE_INCAPACITATED			STATE_INCAPACITATED
#define ICON_STATE_STABILIZED				STATE_STABILIZED
#define ICON_STATE_DEAD						STATE_DEAD

/*--------------------------------------------------------------------------------------------------

	ICON SETTINGS

--------------------------------------------------------------------------------------------------*/
//icon values
#define ICON_USERACTION_REVIVE				'\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_revive_ca.paa'
#define ICON_USERACTION_STABILIZE			'\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_passleadership_ca.paa'
#define ICON_USERACTION_REVIVE_MEDIC		'\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_reviveMedic_ca.paa'
#define ICON_USERACTION_RESPAWN				'\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_forceRespawn_ca.paa'
#define ICON_USERACTION_SECURE				'\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_secure_ca.paa'

#define ICON_VISIBLE_RANGE 					150		//up to this range icon is at full alpha
#define ICON_VISIBLE_RANGE_MAX 				175		//behind this range icon is not visible
#define ICON_SIZE							1.3
#define ICON_TEXT_SIZE						0.035
#define ICON_ALPHA							0.85

#define VAR_ICON_COLOR						'EAMS_Rev_Var_icon_color'
#define VAR_ICON_TEXT						'EAMS_Rev_Var_icon_text'
#define VAR_ICON_IS_ACTIVE					'EAMS_Rev_Var_icon_isActive'	//used in draw frame code to determine visualization and drawing of side arrows
#define VAR_ICON_IN_GROUP					'EAMS_Rev_Var_icon_inGroup'		//used in draw frame code to determine if unit is in teh same group as player

#define ICON_COLOR_DISABLED					[0.9,0.9,0.9,ICON_ALPHA]
#define ICON_COLOR_ACTIVE					[1,0.3,0.3,ICON_ALPHA]
#define ICON_COLOR_ACTIVE_ALT				[1,0.6,0.3,ICON_ALPHA]		//used for revive when victim's FAK is used
