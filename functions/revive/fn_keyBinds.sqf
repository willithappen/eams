//Include ArmA 3 DIK Codes to save using Numbers for Keybinding
#include "\a3\editor_f\Data\Scripts\dikCodes.h"
["EAMS - Keybindings","OpenMedicalUI","Open Treatment Menu",{if (eams_ReviveMode) exitWith {[cursorTarget,player] spawn eams_fnc_ui_treatmentMenu}},{},[DIK_H,[false,false,false]]] call CBA_fnc_AddKeybind;
