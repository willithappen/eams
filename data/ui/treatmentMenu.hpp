/* #Hadydy
$[1.063,["EAMS_TreatmentMenu",[["safezoneX","safezoneY","safezoneW","safezoneH"],"safezoneW / 40","safezoneH / 25","GUI_GRID"],0,0,0],[1800,"EAMS_GUI_TM_Frame",[1,"EAMS Treatment Menu (GUI v1)",["0.3 * safezoneW + safezoneX","0.24 * safezoneH + safezoneY","0.4 * safezoneW","0.52 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1001,"EAMS_GUI_TM_TreatingName",[1,"Treating: TREATMENT",["0.3 * safezoneW + safezoneX","0.26 * safezoneH + safezoneY","0.2 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1600,"EAMS_GUI_TM_SelectHead",[1,"Head",["0.4 * safezoneW + safezoneX","0.36 * safezoneH + safezoneY","0.05 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1601,"EAMS_GUI_TM_SelectArmL",[1,"Left Arm",["0.35 * safezoneW + safezoneX","0.4 * safezoneH + safezoneY","0.05 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1602,"EAMS_GUI_TM_SelectArmR",[1,"Right Arm",["0.45 * safezoneW + safezoneX","0.4 * safezoneH + safezoneY","0.05 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1603,"EAMS_GUI_TM_SelectLegL",[1,"Left Leg",["0.35 * safezoneW + safezoneX","0.48 * safezoneH + safezoneY","0.05 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1604,"EAMS_GUI_TM_SelectLegR",[1,"Right Leg",["0.45 * safezoneW + safezoneX","0.48 * safezoneH + safezoneY","0.05 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1605,"EAMS_GUI_TM_SelectChest",[1,"Chest",["0.4 * safezoneW + safezoneX","0.44 * safezoneH + safezoneY","0.05 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1100,"EAMS_GUI_TM_StateBox",[1,"",["0.525 * safezoneW + safezoneX","0.36 * safezoneH + safezoneY","0.15 * safezoneW","0.16 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1606,"EAMS_GUI_TM_SelectBandage",[1,"Bandage",["0.525 * safezoneW + safezoneX","0.54 * safezoneH + safezoneY","0.0625 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],[1607,"EAMS_GUI_TM_SelectExtraAction",[1,"Stabilize",["0.6125 * safezoneW + safezoneX","0.54 * safezoneH + safezoneY","0.0625 * safezoneW","0.04 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]]
*/
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by CAPT Will, v1.063, #Hadydy)
////////////////////////////////////////////////////////

class EAMS_GUI_TreatmentMenuBase {
	idd= 3267;
	class ControlsBackground {
		class Background {
			idc = -1;
			type = CT_STATIC;
			style = ST_LEFT;
			x = 0.3 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.4 * safezoneW;
			h = 0.52 * safezoneH;
			colorBackground[] = {0.4,0.6,0.6,0.05};
			colorText[] = {0,0,0,0};
			font = "RobotoCondensedBold";
			sizeEx = GUI_GRID_CENTER_H;
			text = "";
			moving = 1;
			default = 0; // Control selected by default (only one within a display can be used)
		};
	};
	class Controls {
		class EAMS_GUI_TM_Frame: EAMS_RscFrame
		{
			idc = 1800;
			text = "EAMS Treatment Menu (GUI v1)"; //--- ToDo: Localize;
			x = 0.3 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.4 * safezoneW;
			h = 0.52 * safezoneH;
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_TreatingName: EAMS_RscText
		{
			idc = 1001;
			text = "Treating: Not Defined"; //--- ToDo: Localize;
			colorBackground[] = {0,0,0,0};
			x = 0.3 * safezoneW + safezoneX;
			y = 0.26 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.04 * safezoneH;
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectHead: EAMS_RscButton
		{
			idc = 1600;
			text = "Head"; //--- ToDo: Localize;
			x = 0.4 * safezoneW + safezoneX;
			y = 0.36 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "['hithead'] call eams_fnc_ui_treatmentMenu_state;";
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectArmL: EAMS_RscButton
		{
			idc = 1601;
			text = "Left Arm"; //--- ToDo: Localize;
			x = 0.35 * safezoneW + safezoneX;
			y = 0.4 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "['hitleftarm'] call eams_fnc_ui_treatmentMenu_state;";
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectArmR: EAMS_RscButton
		{
			idc = 1602;
			text = "Right Arm"; //--- ToDo: Localize;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.4 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "['hitrightarm'] call eams_fnc_ui_treatmentMenu_state;";
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectLegL: EAMS_RscButton
		{
			idc = 1603;
			text = "Left Leg"; //--- ToDo: Localize;
			x = 0.35 * safezoneW + safezoneX;
			y = 0.48 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "['hitleftleg'] call eams_fnc_ui_treatmentMenu_state;";
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectLegR: EAMS_RscButton
		{
			idc = 1604;
			text = "Right Leg"; //--- ToDo: Localize;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.48 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "['hitrightleg'] call eams_fnc_ui_treatmentMenu_state;";
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectChest: EAMS_RscButton
		{
			idc = 1605;
			text = "Chest"; //--- ToDo: Localize;
			x = 0.4 * safezoneW + safezoneX;
			y = 0.44 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "['hitchest'] call eams_fnc_ui_treatmentMenu_state;";
			default = 1; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_StateBox: EAMS_RscLISTBOX
		{
			idc = 1100;
			//idd = 3267;
			text = "Wounds";
			x = 0.525 * safezoneW + safezoneX;
			y = 0.36 * safezoneH + safezoneY;
			w = 0.15 * safezoneW;
			h = 0.16 * safezoneH;
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectBandage: EAMS_RscButton
		{
			idc = 1606;
			text = "Bandage"; //--- ToDo: Localize;
			x = 0.525 * safezoneW + safezoneX;
			y = 0.54 * safezoneH + safezoneY;
			w = 0.0625 * safezoneW;
			h = 0.04 * safezoneH;
			onButtonClick = "[uiNameSpace getVariable ['EAMS-CurrentPatient',player],uiNameSpace getVariable ['EAMS-SelectedBodyPart','hitChest']] call eams_fnc_doHealLimb;";
			default = 0; // Control selected by default (only one within a display can be used)
		};
		class EAMS_GUI_TM_SelectExtraAction: EAMS_RscButton
		{
			idc = 1607;
			text = "Stabilize"; //--- ToDo: Localize;
			x = 0.6125 * safezoneW + safezoneX;
			y = 0.54 * safezoneH + safezoneY;
			w = 0.0625 * safezoneW;
			h = 0.04 * safezoneH;
			default = 0; // Control selected by default (only one within a display can be used)
		};
	};
};
