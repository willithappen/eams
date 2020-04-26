class CfgPatches {
    class EAMS {
        units[] = {};
        weapons[] = {};
        requiredAddons[] = {"A3_characters_f","A3_characters_f_beta","ace_main","A3_Structures_F_EPA_Items_Medical","A3_Props_F_Orange_Humanitarian_Garbage"};
        author = "willithappen";
    };
};

#include "\z\ace\addons\main\script_macros.hpp"
#include "functions\revive\defines.hpp"
#include "functions\hitpoint_macro.hpp"
#include "functions\eams_medical_items.hpp"

class cfgWeapons {
ADD_EAMS_MEDICAL_ITEMS();
};

class cfgVehicles {
	class Man;
	class CAManBase: Man {
		class HitPoints {
			//Script Macro addition of arms and legs inspired by https://github.com/acemod/ACE3/blob/master/addons/medical_engine/script_macros_config.hpp
			// Knowledge of total hitpoints and final hitpoint https://github.com/DomT602/Altis_Scriptorium/blob/master/Modded_Framework/DEV/config.cpp
			// Thanks to ACE's knowledge and DomT602
            ADD_HITPOINTS_EAMS(1,1);
        };
		class ACE_Actions {
			class ACE_Torso {
				condition = "isPlayer _target && IS_MP";
				class EAMS_Action_Stabilize {
					displayName = "Stabilize";
					condition = "[_target,_player] call eams_fnc_StabilizeIsValid";
					statement = QUOTE(\
						SET_BEING_STABILIZED(_target,true);\
						_player playAction 'medicStart';\
						_duration = eams_revive_duration/8;\
						if (CAN_USE_MEDIKIT(_player)) then {\
							_duration = eams_revive_durationMedic/2;\
						};\
					[_duration, [_player,_target], {STABILIZE_COMPLETE(_args select 0,_args select 1)}, {STABILIZE_FAILED(_args select 0,_args select 1)}, 'Stabilizing...'] call ace_common_fnc_progressBar
				);
				};
				class EAMS_Action_Revive {
				 displayName = "Revive";
				 condition = "[_target,_player] call eams_fnc_reviveIsValid";
				 statement = QUOTE(\
					 SET_BEING_REVIVED(_target,true);\
					 _player playAction 'medicStart';\
					 _duration = eams_revive_duration;\
					 if (CAN_USE_MEDIKIT(_player)) then {\
						 _duration = eams_revive_durationMedic;
					 };\
				 [_duration, [_player,_target], {REVIVE_COMPLETE(_args select 0,_args select 1)}, {REVIVE_FAILED(_args select 0,_args select 1)}, 'Reviving...'] call ace_common_fnc_progressBar
					);
				};
				class EAMS_Action_Chest {
				 displayName = "Bandage Chest";
				 condition = "[_target,'hitBody'] call eams_fnc_canHealLimb";
				 statement = "[_target,'hitBody',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'hitBody',_this select 3] call eams_fnc_modifyColor);
				};
			};
			class ACE_Head {
				condition = "isPlayer _target && IS_MP";
				class EAMS_Action_Head {
				 displayName = "Bandage Head";
				 condition = "[_target,'hitHead'] call eams_fnc_canHealLimb";
				 statement = "[_target,'HitHead',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'HitHead',_this select 3] call eams_fnc_modifyColor);

				};
			};
			class ACE_ArmLeft {
				condition = "isPlayer _target && IS_MP";
				class EAMS_Action_ArmLeft {
				 displayName = "Bandage Arm";
				 condition = "[_target,'HitLeftArm'] call eams_fnc_canHealLimb";
				 statement = "[_target,'HitLeftArm',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'HitLeftArm',_this select 3] call eams_fnc_modifyColor);

				};
			};
			class ACE_ArmRight {
				condition = "isPlayer _target && IS_MP";
				class EAMS_Action_ArmRight {
				 displayName = "Bandage Arm";
				 condition = "[_target,'HitRightArm'] call eams_fnc_canHealLimb";
				 statement = "[_target,'HitRightArm',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'HitRightArm',_this select 3] call eams_fnc_modifyColor);

				};
			};
			class ACE_LegLeft {
				condition = "isPlayer _target && IS_MP";
				class EAMS_Action_LegLeft {
				 displayName = "Bandage Leg";
				 condition = "[_target,'HitLeftLeg'] call eams_fnc_canHealLimb";
				 statement = "[_target,'hitLeftLeg',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'hitLeftLeg',_this select 3] call eams_fnc_modifyColor);

				};
			};
			class ACE_LegRight {
				condition = "isPlayer _target && IS_MP";
				class EAMS_Action_LegRight {
				 displayName = "Bandage Leg";
				 condition = "[_target,'hitRightLeg'] call eams_fnc_canHealLimb";
				 statement = "[_target,'hitRightLeg',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'hitRightLeg',_this select 3] call eams_fnc_modifyColor);

				};
			};
		};
		class ACE_SelfActions {
			class EAMS_MedicalRadial {
				displayName = "Medical";
				condition = "isPlayer _target && IS_MP";
				statement = "";
				showDisabled = 0;
				class EAMS_MedicalRadial_Patch {
					displayName = "Patch Minor Wounds";
					condition = "[_player,'patch'] call eams_fnc_canHealLimb && ((getDammage _player) > 0)";
					statement = "_player setdamage 0";
					icon = QUOTE(eams\data\ui\x_1.paa);
				};
				class EAMS_MedicalRadial_Head {
					displayName = "Bandage Head";
					condition = "[_player,'hitHead'] call eams_fnc_canHealLimb";
					statement = "[_player,'HitHead',_player] call eams_fnc_DoHealLimb";
					icon = QUOTE(eams\data\ui\x_0.paa);
   				 modifierFunction = QUOTE([_target,'HitHead',_this select 3] call eams_fnc_modifyColor);
				};
				class EAMS_MedicalRadial_Chest {
				displayName = "Bandage Chest";
				 condition = "[_player,'hitBody'] call eams_fnc_canHealLimb";
				 statement = "[_player,'hitBody',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'hitBody',_this select 3] call eams_fnc_modifyColor);
				};
				class EAMS_MedicalRadial_ArmLeft {
				displayName = "Bandage Left Arm";
				 condition = "[_player,'HitLeftArm'] call eams_fnc_canHealLimb";
				 statement = "[_player,'HitLeftArm',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'HitLeftArm',_this select 3] call eams_fnc_modifyColor);
				};
				class EAMS_MedicalRadial_ArmRight {
				displayName = "Bandage Right Arm";
				 condition = "[_player,'HitRightArm'] call eams_fnc_canHealLimb";
				 statement = "[_player,'HitRightArm',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'HitRightArm',_this select 3] call eams_fnc_modifyColor);
				};
				class EAMS_MedicalRadial_LegLeft {
				displayName = "Bandage Left Leg";
				 condition = "[_player,'HitLeftLeg'] call eams_fnc_canHealLimb";
				 statement = "[_player,'hitLeftLeg',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'hitLeftLeg',_this select 3] call eams_fnc_modifyColor);
				};
				class EAMS_MedicalRadial_LegRight {
					displayName = "Bandage Right Leg";
				 condition = "[_player,'hitRightLeg'] call eams_fnc_canHealLimb";
				 statement = "[_player,'hitRightLeg',_player] call eams_fnc_DoHealLimb";
				 icon = QUOTE(eams\data\ui\x_0.paa);
				 modifierFunction = QUOTE([_target,'hitRightLeg',_this select 3] call eams_fnc_modifyColor);
				};
			};
		};
	};
	//Suggested armor values from ACE_medical_engine CfgVehicles and based on ACE HitPoint Armor Values
	// BluFor
    class B_Soldier_base_F;
    class B_Soldier_04_f: B_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };
    class B_Soldier_05_f: B_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };

    // Indep
    class I_Soldier_base_F;
    class I_Soldier_03_F: I_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };
    class I_Soldier_04_F: I_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };

    // OpFor
    class SoldierEB;
    class O_Soldier_base_F: SoldierEB {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };
    class O_Soldier_02_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };
    class O_officer_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,2);
        };
    };
    class O_Soldier_diver_base_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };

    // Virtual Reality
    class B_Soldier_VR_F: B_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };
    class B_Protagonist_VR_F: B_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };
    class O_Soldier_VR_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };
    class I_Soldier_VR_F: I_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };
    class I_Protagonist_VR_F: I_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };
    class O_Protagonist_VR_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };
    class C_man_1;
    class C_Protagonist_VR_F: C_man_1 {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };

    // Civilians
    class C_Soldier_VR_F: C_man_1 {
        class HitPoints {
            ADD_HITPOINTS_EAMS(1,1);
        };
    };

    // APEX
    class O_V_Soldier_Viper_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(3,3);
        };
    };
    class O_V_Soldier_base_F: O_Soldier_base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(3,3);
        };
    };

    // Enoch
    class I_E_Man_Base_F;
    class I_E_Uniform_01_coveralls_F: I_E_Man_Base_F {
        class HitPoints {
            ADD_HITPOINTS_EAMS(2,2);
        };
    };
};

class cfgFunctions {
	class eams {
		class Revive {
			file = "EAMS\functions\revive";
				class disableRevive {};
				class reenableRevive {};
				class reviveInit {};
				class reviveSettings
				{
					preInit=1;
				};
				class useBandage {};
				class canHealLimb {};
				class doHealLimb {};
				class modifyColor {};
				class stabilizeComplete {};
				class stabilizeFailed {};
				class reviveComplete {};
				class reviveFailed {};
				class reviveEnabled {};
				class reviveAllowed {};
				class reviveIsValid {};
				class collectNearbyValues {};
				class nearPlayer {};
				class handleDisconnect {};
				class reviveBleedOut {};
				class reviveOnState {};
				class reviveOnStateJIP {};
				class reviveOnBeingRevived {};
				class reviveOnForcingRespawn {};
				class reviveEhKilled {};
				class reviveEhRespawn {};
				class reviveEhHandleDamage {};
				class reviveDebug {};
				class reviveDamageReset {};
				class stabilizeIsValid {};
				class stabilizeAllowed {};
				class ReviveStabilize {};
				class ReviveOnBeingStabilized {};
				class requestData {};
				class transmitData {};
			};
		};
	};
