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

#include "data\ui\parentClasses.hpp"
#include "data\ui\treatmentMenu.hpp"

class cfgWeapons {
ADD_EAMS_MEDICAL_ITEMS();
};

class cfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_Actions {
			class ACE_MainActions {
				class EAMS_OpenPatientMedicalMenu {
					displayName = "Open Patient Medical";
					condition = "alive _target";
					exceptions[] = {"isNotDragging", "isNotCarrying","isNotInside"};
					statement = QUOTE([_target,player] spawn eams_fnc_ui_treatmentMenu);
					icon = "eams\data\ui\x_1.paa";
				};
				class ACE_LoadPatient {
					displayName = "Load Patient";
					condition = QUOTE(((_target getVariable ['ACE_isUnconscious',false]) && (alive _target) && (vehicle _target == _target)));
					exceptions[] = {"isNotDragging", "isNotCarrying"};
					statement = QUOTE([_player, _target] call eams_fnc_ace_loadUnit);
					icon = "eams\data\ui\x_0.paa";
					insertChildren = QUOTE(call eams_fnc_ace_addLoadPatientActions);
				};
				class ACE_UnloadPatient {
					displayName = "Unload Patient";
					condition = QUOTE(((_target getVariable ['ACE_isUnconscious',false]) && (alive _target) && (vehicle _target == _target)));
					exceptions[] = {"isNotDragging", "isNotCarrying", "isNotInside"};
					statement = QUOTE([_player, _target] call eams_fnc_ace_unloadUnit);
					icon = "eams\data\ui\x_0.paa";
				};
			};
		};
		class HitPoints {
			//Script Macro addition of arms and legs inspired by https://github.com/acemod/ACE3/blob/master/addons/medical_engine/script_macros_config.hpp
			// Knowledge of total hitpoints and final hitpoint https://github.com/DomT602/Altis_Scriptorium/blob/master/Modded_Framework/DEV/config.cpp
			// Thanks to ACE's knowledge and DomT602
            ADD_HITPOINTS_EAMS(1,1);
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
				class keyBinds {
					preInit=1;
				};
				class reviveSettings {
					postInit=1;
				};
				class reviveInit {
					postInit=1;
				};
				class UI_TreatmentMenu {};
				class UI_treatmentMenu_State {};
				class UI_stateSwap {};
				class stateTarget {};
				class handleWounding {};
				class disableRevive {};
				class reenableRevive {};
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
				class reviveDamageReset {};
				class stabilizeIsValid {};
				class stabilizeAllowed {};
				class ReviveStabilize {};
				class ReviveOnBeingStabilized {};
				class requestData {};
				class transmitData {};
				class returnData {};
				class recieveData {};

				class ace_loadUnit {};
				class ace_unloadUnit {};
				class ace_addLoadPatientActions {};
			};
		};
	};
