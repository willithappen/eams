// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_HITZONES         17
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102
#define CT_ITEMSLOT         103
#define CT_CHECKBOX         77

// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C

#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0
#define ST_UPPERCASE      0xC0
#define ST_LOWERCASE      0xD0

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4
#define MB_ERROR_DIALOG   8

// Xbox buttons
#define KEY_XINPUT                0x00050000
#define KEY_XBOX_A                KEY_XINPUT + 0
#define KEY_XBOX_B                KEY_XINPUT + 1
#define KEY_XBOX_X                KEY_XINPUT + 2
#define KEY_XBOX_Y                KEY_XINPUT + 3
#define KEY_XBOX_Up               KEY_XINPUT + 4
#define KEY_XBOX_Down             KEY_XINPUT + 5
#define KEY_XBOX_Left             KEY_XINPUT + 6
#define KEY_XBOX_Right            KEY_XINPUT + 7
#define KEY_XBOX_Start            KEY_XINPUT + 8
#define KEY_XBOX_Back             KEY_XINPUT + 9
#define KEY_XBOX_LeftBumper       KEY_XINPUT + 10
#define KEY_XBOX_RightBumper      KEY_XINPUT + 11
#define KEY_XBOX_LeftTrigger      KEY_XINPUT + 12
#define KEY_XBOX_RightTrigger     KEY_XINPUT + 13
#define KEY_XBOX_LeftThumb        KEY_XINPUT + 14
#define KEY_XBOX_RightThumb       KEY_XINPUT + 15
#define KEY_XBOX_LeftThumbXRight  KEY_XINPUT + 16
#define KEY_XBOX_LeftThumbYUp     KEY_XINPUT + 17
#define KEY_XBOX_RightThumbXRight KEY_XINPUT + 18
#define KEY_XBOX_RightThumbYUp    KEY_XINPUT + 19
#define KEY_XBOX_LeftThumbXLeft   KEY_XINPUT + 20
#define KEY_XBOX_LeftThumbYDown   KEY_XINPUT + 21
#define KEY_XBOX_RightThumbXLeft  KEY_XINPUT + 22
#define KEY_XBOX_RightThumbYDown  KEY_XINPUT + 23

// Fonts
#define GUI_FONT_NORMAL			PuristaMedium
#define GUI_FONT_BOLD			PuristaSemibold
#define GUI_FONT_THIN			PuristaLight
#define GUI_FONT_MONO			EtelkaMonospacePro
#define GUI_FONT_NARROW			EtelkaNarrowMediumPro
#define GUI_FONT_CODE			LucidaConsoleB
#define GUI_FONT_SYSTEM			TahomaB

// Grids
#define GUI_GRID_CENTER_WAbs		((safezoneW / safezoneH) min 1.2)
#define GUI_GRID_CENTER_HAbs		(GUI_GRID_CENTER_WAbs / 1.2)
#define GUI_GRID_CENTER_W		(GUI_GRID_CENTER_WAbs / 40)
#define GUI_GRID_CENTER_H		(GUI_GRID_CENTER_HAbs / 25)
#define GUI_GRID_CENTER_X		(safezoneX + (safezoneW - GUI_GRID_CENTER_WAbs)/2)
#define GUI_GRID_CENTER_Y		(safezoneY + (safezoneH - GUI_GRID_CENTER_HAbs)/2)


///////////////////////////////////////////////////////////////////////////
/// Base Classes
///////////////////////////////////////////////////////////////////////////
class EAMS_RscText {
	type = 0;
	idc = -1;
	colorBackground[] =
	{
		0,
		0,
		0,
		0
	};
	colorText[] =
	{
		1,
		1,
		1,
		1
	};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 1;
	colorShadow[] =
	{
		0,
		0,
		0,
		0.5
	};
	font = "PuristaMedium";
	SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing = 1;
};
class EAMS_RscLEFT {
	type = CT_STATIC;
	idc = ST_LEFT;
	style = ST_LEFT;

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 10 * GUI_GRID_CENTER_W;
	h = 2 * GUI_GRID_CENTER_H;

	text = "ST_LEFT";
	sizeEx = GUI_GRID_CENTER_H;
	font = GUI_FONT_NORMAL;
	lineSpacing = 1;
	colorText[] = {0,0,0,1};
	colorBackground[] = {1,0.5,0,1};
};
class EAMS_RscRIGHT: EAMS_RscLEFT
{
	idc = ST_RIGHT;
	style = ST_RIGHT;
	text = "ST_RIGHT";
	y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class EAMS_RscFRAME: EAMS_RscLEFT
{
	idc = ST_FRAME;
	style = ST_FRAME;
	text = "ST_FRAME";
	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class EAMS_RscSTATIC
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_STATIC; // Type
	style = ST_LEFT + ST_MULTI; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 1; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color

	text = "CT_STATIC"; // Displayed text
	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 1; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
	lineSpacing = 1; // When ST_MULTI style is used, this defines distance between lines (1 is text height)
	fixedWidth = 1; // 1 (true) to enable monospace
	colorText[] = {1,1,1,1}; // Text color
	colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	moving = 0; // 1 (true) to allow dragging the whole display by the control

	autoplay = 0; // Play video automatically (only for style ST_PICTURE with text pointing to an .ogv file)
	loops = 0; // Number of video repeats (only for style ST_PICTURE with text pointing to an .ogv file)

	tileW = 1; // Number of tiles horizontally (only for style ST_TILE_PICTURE)
	tileH = 1; // Number of tiles vertically (only for style ST_TILE_PICTURE)

};
class EAMS_RscBUTTON
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_BUTTON; // Type
	style = ST_LEFT; // Style
	default = 1; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
	colorBackgroundDisabled[] = {0,0,0,0.5}; // Disabled fill color
	colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
	colorFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground)

	text = "CT_BUTTON"; // Displayed text
	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 1; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	borderSize = 0.001; // Left color width (border is a stripe of the control height on the left side)
	colorBorder[] = {1,1,1,1}; // Left border color

	colorShadow[] = {0,0,0,0.2}; // Background frame color
	offsetX = 0.0075; // Horizontal background frame offset
	offsetY = 0.01; // Vertical background frame offset
	offsetPressedX = 0.0075; // Horizontal background offset when pressed
	offsetPressedY = 0.01; // Horizontal background offset when pressed

	period = 1; // Oscillation time between colorBackground and colorFocused when selected
	periodFocus = 2; // Unknown?
	periodOver = 0.5; // Unknown?

	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down
};
class EAMS_RscEDIT
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_EDIT; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	text = "CT_EDIT"; // Displayed text
	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {0,0,0,1}; // Text and frame color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text and frame color
	colorSelection[] = {1,0.5,0,1}; // Text selection color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	canModify = 1; // True (1) to allow text editing, 0 to disable it
	autocomplete = "scripting"; // Text autocomplete, can be "scripting" (scripting commands) or "general" (previously typed text)
};
class EAMS_RscSLIDER_Value: EAMS_RscSTATIC // Slider value (see below)
{
	idc = 1200;
	style = ST_CENTER;
	blinkingPeriod = 0;
	x = 8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 6.75 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 3 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height
	colorBackground[] = {0,0,0,0};
	fixedWidth = 0;
};
class EAMS_RscSLIDER
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	idc = CT_SLIDER; // Control identification (without it, the control won't be displayed)
	type = CT_SLIDER; // Type
	style = SL_HORZ; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 7 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	color[] = {0,0,0,1}; // Text color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color
	colorActive[] = {1,0.5,0,1}; // Text selection color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	class Title // Link to a title (obsolete?)
	{
		idc = -1; // Control IDC (has to be defined ABOVE the slider control)
		colorBase[] = {1,1,1,1}; // Text color
		colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
	};
	class Value // Link to a control which will show slider value
	{
		idc = 1200; // Control IDC (has to be defined ABOVE the slider control)
		format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
		type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
		colorBase[] = {1,1,1,1}; // Text color
		colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
	};
};
class EAMS_RscCOMBO
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	idc = CT_COMBO; // Control identification (without it, the control won't be displayed)
	type = CT_COMBO; // Type
	style = ST_LEFT + LB_TEXTURES; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
	colorSelectBackground[] = {1,0.5,0,1}; // Selected item fill color

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text and frame color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color
	colorSelect[] = {1,1,1,1}; // Text selection color

	pictureColor[] = {1,0.5,0,1}; // Picture color
	pictureColorSelect[] = {1,1,1,1}; // Selected picture color
	pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
	arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

	wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
	maxHistoryDelay = 1; // Time since last keyboard type search to reset it

	soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
	soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
	soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

	// Scrollbar configuration (applied only when LB_TEXTURES style is used)
	class ComboScrollBar
	{
		width = 0; // Unknown?
		height = 0; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color
	};
};
class EAMS_RscLISTBOX
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_LISTBOX; // Type
	style = ST_LEFT + LB_TEXTURES; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 11 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 3 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
	colorSelectBackground[] = {1,0.5,0,1}; // Selected item fill color
	colorSelectBackground2[] = {0,0,0,1}; // Selected item fill color (oscillates between this and colorSelectBackground)

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text and frame color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color
	colorSelect[] = {1,1,1,1}; // Text selection color
	colorSelect2[] = {1,1,1,1}; // Text selection color (oscillates between this and colorSelect)
	colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)

	pictureColor[] = {1,0.5,0,1}; // Picture color
	pictureColorSelect[] = {1,1,1,1}; // Selected picture color
	pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	period = 1; // Oscillation time between colorSelect/colorSelectBackground2 and colorSelect2/colorSelectBackground when selected

	rowHeight = 1.5 * GUI_GRID_CENTER_H; // Row height
	itemSpacing = 0; // Height of empty space between items
	maxHistoryDelay = 1; // Time since last keyboard type search to reset it
	canDrag = 1; // 1 (true) to allow item dragging

	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

	// Scrollbar configuration (applied only when LB_TEXTURES style is used)
	class ListScrollBar
	{
		width = 0; // Unknown?
		height = 0; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color
	};
};
class EAMS_RscTOOLBOX
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_TOOLBOX; // Type
	style = ST_CENTER; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 2 * GUI_GRID_CENTER_H; // Height

	colorSelectedBg[] = {1,0.5,0,1}; // Fill color

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text color
	colorTextSelect[] = {1,1,1,1}; // Selected text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	rows = 2; // Number of rows
	columns = 2; // Number of columns
	strings[] = {$STR_A3_RADIO_A,$STR_A3_RADIO_B,$STR_A3_RADIO_C,$STR_A3_RADIO_D}; // Options (added row by row)
	values[] = {1,2,3,4};

	color[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorSelect[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorTextDisable[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorDisable[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
};
class EAMS_RscCHECKBOXES
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_CHECKBOXES; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 2 * GUI_GRID_CENTER_H; // Height

	colorSelectedBg[] = {1,0.5,0,1}; // Selected fill color

	text = "CT_CHECKBOXES"; // Displayed text
	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,0.5}; // Text color
	colorTextSelect[] = {1,1,1,1};  // Checked text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	rows = 2; // Number of rows
	columns = 2; // Number of columns
	strings[] = {"A","B","C","D"}; // Options (added row by row)
	checked_strings[] = {$STR_A3_RADIO_A,$STR_A3_RADIO_B,$STR_A3_RADIO_C,$STR_A3_RADIO_D}; // Options (added row by row)
	values[] = {1,2,3,4};

	color[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorSelect[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorTextDisable[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorDisable[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
};
class EAMS_RscPROGRESS
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_PROGRESS; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	texture = "#(argb,8,8,3)color(1,1,1,1)"; // Bar texture
	colorBar[] = {1,1,1,1}; // Bar color
	colorFrame[] = {0,0,0,1}; // Frame color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color
};
class EAMS_RscHTML
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_HTML; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1.5 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color

	colorText[] = {1,1,1,1}; // Text color
	colorBold[] = {1,1,1,1}; // <b> text color
	colorLink[] = {1,1,1,1}; // <a> text color
	colorLinkActive[] = {1,0.5,0,1}; // Active <a> text color
	colorPicture[] = {1,1,1,1}; // Picture color
	colorPictureBorder[] = {0,0,0,0}; // Picture border color
	colorPictureLink[] = {1,1,1,1}; // <a> picture color
	colorPictureSelected[] = {1,1,1,1}; // Active <a> picture color

	prevPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa"; // Pagination arrow for previous page
	nextPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa"; // Pagination arrow for next page

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	filename = "a3\ui_f\data\html\RscFeedback.html";

	class P // Paragraph style
	{
		font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
		fontBold = GUI_FONT_BOLD; // Vold font from CfgFontFamilies
		sizeEx = GUI_GRID_CENTER_H; // Text size
		align = "left"; // Text align (can be "left", "center" or "right")
	};
	class H1:P{}; // Header 1 style (uses same attributes as P)
	class H2:P{}; // Header 2 style (uses same attributes as P)
	class H3:P{}; // Header 3 style (uses same attributes as P)
	class H4:P{}; // Header 4 style (uses same attributes as P)
	class H5:P{}; // Header 5 style (uses same attributes as P)
	class H6:P{}; // Header 6 style (uses same attributes as P)
};
//class CT_STATIC_SKEW not implemented
class EAMS_RscACTIVETEXT
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_ACTIVETEXT; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	text = "CT_ACTIVETEXT"; // Displayed text
	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - directional, color cannot be changed, 2 - black outline)
	color[] = {1,1,1,1}; // Text color
	colorActive[] = {1,0.5,0,1};  // Checked text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	soundClick[] = {"",1,1}; // Sound played after control is activated in format {file, volume, pitch}
	soundEnter[] = {"",1,1}; // Sound played when mouse cursor enters the control
	soundPush[] = {"",1,1}; // Sound played when the control is pushed down
	soundEscape[] = {"",1,1}; // Sound played when the control is released after pushing down
};
class EAMS_RscTREE
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_TREE; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 3 * GUI_GRID_CENTER_H; // Height

	colorBorder[] = {0,0,0,1}; // Frame color

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
	colorSelect[] = {1,0.5,0,1}; // Selected item fill color (when multiselectEnabled is 0)
	colorMarked[] = {1,0.5,0,0.5}; // Marked item fill color (when multiselectEnabled is 1)
	colorMarkedSelected[] = {1,0.5,0,1}; // Selected item fill color (when multiselectEnabled is 1)

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 1; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text color
	colorSelectText[] = {1,1,1,1}; // Selected text color (when multiselectEnabled is 0)
	colorMarkedText[] = {1,1,1,1}; // Selected text color (when multiselectEnabled is 1)

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	multiselectEnabled = 1; // Allow selecting multiple items while holding Ctrl or Shift
	expandOnDoubleclick = 1; // Expand/collapse item upon double-click
	hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa"; // Expand icon
	expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa"; // Collapse icon
	maxHistoryDelay = 1; // Time since last keyboard type search to reset it

	// Scrollbar configuration
	class ScrollBar
	{
		width = 0; // Unknown?
		height = 0; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color
	};

	colorDisabled[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
	colorArrow[] = {0,0,0,0}; // Does nothing, but must be present, otherwise an error is shown
};
class EAMS_RscSTRUCTURED_TEXT
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_STRUCTURED_TEXT; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color

	text = "<img image='\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa' size='0.5' />CT_<t size='0.8' underline='1' color='#ffff8000' font='PuristaBold' shadow='1' shadowColor='#000000'>STRUCTURED</t>_TEXT"; // Displayed text
	size = GUI_GRID_CENTER_H; // Text size

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	class Attributes
	{
		align = "left"; // Text align
		color = "#ffffff"; // Text color
		size = 1; // Text size
		font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	};
};
//class CT_CONTEXT_MENU not implemented in class Controls
class EAMS_RscCONTROLS_GROUP
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_CONTROLS_GROUP; // Type
	style = LB_TEXTURES; // Style
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 3 * GUI_GRID_CENTER_H; // Height

	class Controls
	{
		class EAMS_RscSTATIC: EAMS_RscSTATIC
		{
			idc = 1;
			style = ST_PICTURE;
			blinkingPeriod = 0;
			x = 0;
			y = 0;
			w = 20 * GUI_GRID_CENTER_W;
			h = 5 * GUI_GRID_CENTER_H;
			text = "#(ai,512,512,1)perlinNoise(512,128,0,1)";
		};
	};
	// Scrollbar configuration (applied only when LB_TEXTURES style is used)
	class VScrollBar
	{
		width = 0.021; // Unknown?
		height = 0; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color

		autoScrollEnabled = 1; // 1 to enable automatic scrolling
		autoScrollDelay = 1; // Time after autoscroll is initiated
		autoScrollRewind = 1; // Repeat the autoscroll once it's finished
		autoScrollSpeed = 1; // Autoscroll speed
	};
	class HScrollBar
	{
		width = 0; // Unknown?
		height = 0.028; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color
	};
};
class EAMS_RscSHORTCUTBUTTON
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_SHORTCUTBUTTON; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
	colorBackground2[] = {0,0,0,1}; // Selected fill color
	colorBackgroundFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground2)
	colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color

	text = "CT_SHORTCUTBUTTON"; // Displayed text
	size = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 1; // Shadow (0 - none, 1 - directional, color cannot be changed, 2 - black outline)
	color[] = {1,1,1,1}; // Text color
	color2[] = {1,1,1,1}; // Selected fill color
	colorFocused[] = {1,1,1,1}; // Selected text color (oscillates between this and color2)
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color

	animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)"; // Background texture
	animTextureOver = "#(argb,8,8,3)color(1,1,1,1)"; // Mouse over background texture
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)"; // Mouse pressed background texture
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)"; // Focused background texture
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)"; // Disabled background texture
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)"; // Unknown?

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	period = 1; // Oscillation time between color2/colorBackground2 and colorFocused/colorBackgroundFocused when selected
	periodFocus = 1; // Oscillation time between color2/colorBackground2 and colorFocused/colorBackgroundFocused when focused
	periodOver = 0.5; // Oscillation time between color2/colorBackground2 and colorFocused/colorBackgroundFocused during mouse hover

	shortcuts[] = {KEY_XBOX_A}; // DIK codes of keyoboard shortcuts
	textureNoShortcut = "#(argb,8,8,3)color(1,1,1,1)"; // Icon displayed on ShortcutPos position when no shortcut key is found

	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

	class Attributes
	{
		align = "left"; // Text align
		color = "#ffffff"; // Text color
		font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
		shadow = 0; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
	};
	class HitZone // Clickable area
	{
		left = 0; // Left border
		top = 0; // Top border
		right = 0; // Right border
		bottom = 0; // Bottom border
	};
	class TextPos // Text position inside button
	{
		left = GUI_GRID_CENTER_W; // Left border
		top = 0; // Top border
		right = 0; // Right border
		bottom = 0; // Bottom border
	};
	class ShortcutPos // Shortcut icon position (e.g., XboX A button), based on keys in shortcuts[] attribute
	{
		left = 0; // Horizontal coordinates
		top = 0; // Horizontal coordinates
		w = GUI_GRID_CENTER_W; // Width
		h = GUI_GRID_CENTER_H; // Height
	};
};
//class CT_HITZONES not implemented in class Controls
//class CT_XKEYDESC not implemented in class Controls
class EAMS_RscXBUTTON
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_XBUTTON; // Type
	style = ST_LEFT; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorBackground[] = {0,0,0,0}; // Fill color
	colorActiveBackground[] = {1,0.5,0,1}; // Selected fill color (rendered below colorBackground)
	colorActiveBackground2[] = {0,0,0,1}; // Selected fill color (oscillates between this and colorActiveBackground)
	colorDisabled[] = {0,1,1,1};

	text = "CT_XBUTTON"; // Displayed text
	size = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	color[] = {1,1,1,1}; // Text color
	colorActive[] = {1,1,1,1}; // Selected text color
	colorActive2[] = {1,1,1,1}; // Selected text color (oscillates between this and colorActive)

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	period = 1; // Oscillation time between colorBackground and colorFocused when selected

	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down
};
class EAMS_RscXLISTBOX
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_XLISTBOX; // Type
	style = SL_HORZ + ST_CENTER + LB_TEXTURES; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 17 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	color[] = {1,1,1,1}; // Arrow color
	colorActive[] = {1,0.5,0,1}; // Selected arrow color

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text color
	colorSelect[] = {1,0.5,0,1}; // Selected text color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture

	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

};
class EAMS_RscXSLIDER
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_XSLIDER; // Type
	style = SL_HORZ; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	color[] = {1,1,1,1}; // Text and arrow color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
	colorActive[] = {1,0.5,0,1}; // Text selection color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
	thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)


	class Title // Link to a title (obsolete?)
	{
		idc = -1; // Control IDC (has to be defined ABOVE the slider control)
		colorBase[] = {1,1,1,1}; // Text color
		colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
	};
	class Value // Link to a control which will show slider value
	{
		idc = -1; // Control IDC (has to be defined ABOVE the slider control)
		format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
		type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
		colorBase[] = {1,1,1,1}; // Text color
		colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
	};
};
class EAMS_RscXCOMBO // Xbox combo box, cannot be controlled with mouse
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_XCOMBO; // Type
	style = ST_LEFT + LB_TEXTURES; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	colorSelectBackground2[] = {0,0,0,1}; // Selected fill color (oscillates between this and List >> colorSelectBackground)

	colorBorder[] = {1,0,1,1}; // Unknown?
	colorSelectBorder[] = {1,1,1,1}; // Selected arrow color
	colorDisabledBorder[] = {0,1,1,1}; // Unknown?

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text color
	colorSelect[] = {1,1,1,1}; // Selected text color
	colorSelect2[] = {1,1,1,1}; // Selected text color (oscillates between this and colorSelect)
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
	soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
	soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

	// List title (not moved when display is dragged)
	class Title
	{
		text = "CT_XCOMBO";
		x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
		y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
		w = 10 * GUI_GRID_CENTER_W; // Width
		h = 1 * GUI_GRID_CENTER_H; // Height

		colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
		colorSelectBackground[] = {1,0.5,0,1}; // Selected item fill color

		colorBorder[] = {0,0,0,1}; // Border color
		colorSelectBorder[] = {0,0,0,1}; // Selected border color
		colorDisabledBorder[] = {1,1,1,1}; // Disabled border color

		font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
		size = GUI_GRID_CENTER_H; // Text size
		colorText[] = {1,1,1,1}; // Text color
		colorSelect[] = {1,1,1,1}; // Selected text color
		colorDisabled[] = {1,1,1,0.5}; // Disabled text color
	};
	// Item list displayed when arrow right is pressed while the control is in focus (not moved when display is dragged)
	class List
	{
		x = 22 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
		y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
		w = 10 * GUI_GRID_CENTER_W; // Width
		h = 5 * GUI_GRID_CENTER_H; // Height

		colorBackground[] = {0.2,0.2,0.2,1}; // List fill color
		colorSelectBackground[] = {1,0.5,0,1}; // Selected item fill color (oscillates between this and colorSelectBackground2 in control root)

		colorBorder[] = {1,1,1,1}; // List scrollbar color (combined with Scrollbar >> color)

		rowHeight = 1 * GUI_GRID_CENTER_H; // Row height
		sizeEx = GUI_GRID_CENTER_H; // Text size
		colorText[] = {1,1,1,1}; // Text color
		colorSelect[] = {1,1,1,1}; // Selected text color (oscillates between this and colorSelect2 in control root)
	};
	// Scrollbar configuration (applied only when LB_TEXTURES style is used)
	class ScrollBar
	{
		width = 0; // Unknown?
		height = 0; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color (combined with List >> colorBorder)
	};
};
//class CT_ANIMATED_TEXTURE not implemented in class Controls
//class CT_LINEBREAK not implemented in class Controls
//class CT_USER not available without engine support
class EAMS_RscMAP
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_MAP_MAIN; // Type
	style = ST_PICTURE; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 29 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 6 * GUI_GRID_CENTER_H; // Height

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	colorText[] = {0,0,0,1}; // Text color

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	moveOnEdges = 1; // Move map when cursor is near its edge. Discontinued.

	// Rendering density coefficients
	ptsPerSquareSea =	5;	// seas
	ptsPerSquareTxt =	20;	// textures
	ptsPerSquareCLn =	10;	// count-lines
	ptsPerSquareExp =	10;	// exposure
	ptsPerSquareCost =	10;	// cost

	// Rendering thresholds
	ptsPerSquareFor =	9;	// forests
	ptsPerSquareForEdge =	9;	// forest edges
	ptsPerSquareRoad =	6;	// roads
	ptsPerSquareObj =	9;	// other objects

	scaleMin = 0.001; // Min map scale (i.e., max zoom)
	scaleMax = 1.0; // Max map scale (i.e., min zoom)
	scaleDefault = 0.16; // Default scale

	alphaFadeStartScale = 0.1; // Scale at which satellite map starts appearing
	alphaFadeEndScale = 0.01; // Scale at which satellite map is fully rendered
	maxSatelliteAlpha = 0.85; // Maximum alpha of satellite map

	text = "#(argb,8,8,3)color(1,1,1,1)"; // Fill texture
	colorBackground[] = {1,1,1,1}; // Fill color

	colorOutside[] = {0,0,0,1}; // Color outside of the terrain area (not sued when procedural terrain is enabled)
	colorSea[] = {0.4,0.6,0.8,0.5}; // Sea color
	colorForest[] = {0.6,0.8,0.4,0.5}; // Forest color
	colorForestBorder[] = {0.6,0.8,0.4,1}; // Forest border color
	colorRocks[] = {0,0,0,0.3}; // Rocks color
	colorRocksBorder[] = {0,0,0,1}; // Rocks border color
	colorLevels[] = {0.3,0.2,0.1,0.5}; // Elevation number color
	colorMainCountlines[] = {0.6,0.4,0.2,0.5}; // Main countline color (every 5th)
	colorCountlines[] = {0.6,0.4,0.2,0.3}; // Countline color
	colorMainCountlinesWater[] = {0.5,0.6,0.7,0.6}; // Main water countline color (every 5th)
	colorCountlinesWater[] = {0.5,0.6,0.7,0.3}; // Water countline color
	colorPowerLines[] = {0.1,0.1,0.1,1}; // Power lines color
	colorRailWay[] = {0.8,0.2,0,1}; // Railway color
	colorNames[] = {1.1,0.1,1.1,0.9}; // Unknown?
	colorInactive[] = {1,1,0,0.5}; // Unknown?
	colorTracks[] = {0.8,0.8,0.7,0.2}; // Small road border color
	colorTracksFill[] = {0.8,0.7,0.7,1}; // Small road color
	colorRoads[] = {0.7,0.7,0.7,1}; // Medium road border color
	colorRoadsFill[] = {1,1,1,1}; // Medium road color
	colorMainRoads[] = {0.9,0.5,0.3,1}; // Large road border color
	colorMainRoadsFill[] = {1,0.6,0.4,1}; // Large road color
	colorGrid[] = {0.1,0.1,0.1,0.6}; // Grid coordinate color
	colorGridMap[] = {0.1,0.1,0.1,0.6}; // Grid line color

	fontLabel = GUI_FONT_NORMAL; // Tooltip font from CfgFontFamilies
	sizeExLabel = GUI_GRID_CENTER_H * 0.5; // Tooltip font size

	fontGrid = GUI_FONT_SYSTEM; // Grid coordinate font from CfgFontFamilies
	sizeExGrid = GUI_GRID_CENTER_H * 0.5; // Grid coordinate font size

	fontUnits = GUI_FONT_SYSTEM; // Selected group member font from CfgFontFamilies
	sizeExUnits = GUI_GRID_CENTER_H * 0.5; // Selected group member font size

	fontNames = GUI_FONT_NARROW; // Marker font from CfgFontFamilies
	sizeExNames = GUI_GRID_CENTER_H * 0.5; // Marker font size

	fontInfo = GUI_FONT_NORMAL; // Unknown?
	sizeExInfo = GUI_GRID_CENTER_H * 0.5; // Unknown?

	fontLevel = GUI_FONT_SYSTEM; // Elevation number font
	sizeExLevel = GUI_GRID_CENTER_H * 0.5; // Elevation number font size

	showCountourInterval = 1; // Show Legend

	class Task
	{
		icon = "#(argb,8,8,3)color(1,1,1,1)";
		color[] = {1,1,0,1};

		iconCreated = "#(argb,8,8,3)color(1,1,1,1)";
		colorCreated[] = {0,0,0,1};

		iconCanceled = "#(argb,8,8,3)color(1,1,1,1)";
		colorCanceled[] = {0,0,0,0.5};

		iconDone = "#(argb,8,8,3)color(1,1,1,1)";
		colorDone[] = {0,1,0,1};

		iconFailed = "#(argb,8,8,3)color(1,1,1,1)";
		colorFailed[] = {1,0,0,1};

		size = 8;
		importance = 1; // Required, but not used
		coefMin = 1; // Required, but not used
		coefMax = 1; // Required, but not used
	};
	class ActiveMarker
	{
		color[] = {0,0,0,1}; // Icon color
		size = 2; // Size in pixels
	};
	class Waypoint
	{
		coefMax = 1; // Minimum size coefficient
		coefMin = 4; // Maximum size coefficient
		color[] = {0,0,0,1}; // Icon color
		icon = "#(argb,8,8,3)color(0,0,0,1)"; // Icon texture
		importance = 1; // Drawing importance (when multiple icons are close together, the one with larger importance is prioritized)
		size = 2; // Size in pixels
	};
	class WaypointCompleted: Waypoint{};
	class CustomMark: Waypoint{};
	class Command: Waypoint{};
	class Bush: Waypoint{};
	class Rock: Waypoint{};
	class SmallTree: Waypoint{};
	class Tree: Waypoint{};
	class BusStop: Waypoint{};
	class FuelStation: Waypoint{};
	class Hospital: Waypoint{};
	class Church: Waypoint{};
	class Lighthouse: Waypoint{};
	class Power: Waypoint{};
	class PowerSolar: Waypoint{};
	class PowerWave: Waypoint{};
	class PowerWind: Waypoint{};
	class Quay: Waypoint{};
	class Transmitter: Waypoint{};
	class Watertower: Waypoint{};
	class Cross: Waypoint{};
	class Chapel: Waypoint{};
	class Shipwreck: Waypoint{};
	class Bunker: Waypoint{};
	class Fortress: Waypoint{};
	class Fountain: Waypoint{};
	class Ruin: Waypoint{};
	class Stack: Waypoint{};
	class Tourism: Waypoint{};
	class ViewTower: Waypoint{};
};
class EAMS_RscMAP_MAIN: EAMS_RscMAP
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_MAP_MAIN; // Type
	style = ST_PICTURE; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 29 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 8 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 6 * GUI_GRID_CENTER_H; // Height

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	showCountourInterval = 1; // Show Legend

	class Legend
	{
		x = 30 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
		y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
		w = 8 * GUI_GRID_CENTER_W; // Width
		h = 4 * GUI_GRID_CENTER_H; // Height

		colorBackground[] = {1,1,1,1}; // Fill color

		font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
		sizeEx = 0.8 * GUI_GRID_CENTER_H; // Text size
		color[] = {0,0,0,1}; // Text color

	};
};
class EAMS_RscLISTNBOX
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	 idc = -1; // Control identification (without it, the control won't be displayed)
	type = CT_LISTNBOX; // Type
	style = ST_LEFT + LB_TEXTURES; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 29 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 10 * GUI_GRID_CENTER_W; // Width
	h = 3 * GUI_GRID_CENTER_H; // Height

	colorSelectBackground[] = {1,0.5,0,1}; // Selected item fill color
	colorSelectBackground2[] = {0,0,0,1}; // Selected item fill color (oscillates between this and colorSelectBackground)

	sizeEx = GUI_GRID_CENTER_H; // Text size
	font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
	shadow = 0; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
	colorText[] = {1,1,1,1}; // Text and frame color
	colorDisabled[] = {1,1,1,0.5}; // Disabled text color
	colorSelect[] = {1,1,1,1}; // Text selection color
	colorSelect2[] = {1,1,1,1}; // Text selection color (oscillates between this and colorSelect)
	colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	columns[] = {0.1,0.4}; // Horizontal coordinates of columns (relative to list width, in range from 0 to 1)

	drawSideArrows = 1; // 1 to draw buttons linked by idcLeft and idcRight on both sides of selected line. They are resized to line height
	idcLeft = 1000; // Left button IDC
	idcRight = 1001; // Right button IDC

	period = 1; // Oscillation time between colorSelect/colorSelectBackground2 and colorSelect2/colorSelectBackground when selected

	rowHeight = GUI_GRID_CENTER_H; // Row height
	maxHistoryDelay = 1; // Time since last keyboard type search to reset it

	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

	// Scrollbar configuration (applied only when LB_TEXTURES style is used)
	class ListScrollBar
	{
		width = 0; // Unknown?
		height = 0; // Unknown?
		scrollSpeed = 0.01; // Unknown?

		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

		color[] = {1,1,1,1}; // Scrollbar color
	};
};
class EAMS_RscLISTNBOX_RIGHT: EAMS_RscBUTTON
{
	idc = 1000;
	text = "<";
	borderSize = 0;
	colorShadow[] = {0,0,0,0};
};
class EAMS_RscLISTNBOX_LEFT: EAMS_RscLISTNBOX_RIGHT
{
	idc = 1001;
	text = ">";
};
//class CT_ITEMSLOT not available without engine support
class EAMS_RscCHECKBOX
{
	 // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	idc = CT_CHECKBOX; // Control identification (without it, the control won't be displayed)
	type = CT_CHECKBOX; // Type
	style = ST_LEFT + ST_MULTI; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = 29 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
	y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
	w = 1 * GUI_GRID_CENTER_W; // Width
	h = 1 * GUI_GRID_CENTER_H; // Height

	//Colors
	color[] = {1,1,1,0.7}; // Texture color
	colorFocused[] = {1,1,1,1}; // Focused texture color
	colorHover[] = {1,1,1,1}; // Mouse over texture color
	colorPressed[] = {1,1,1,1}; // Mouse pressed texture color
	colorDisabled[] = {1,1,1,0.2}; // Disabled texture color

	//Background colors
	colorBackground[] = {0,0,0,0}; // Fill color
	colorBackgroundFocused[] = {0,0,0,0}; // Focused fill color
	colorBackgroundHover[] = {0,0,0,0}; // Mouse hover fill color
	colorBackgroundPressed[] = {0,0,0,0}; // Mouse pressed fill color
	colorBackgroundDisabled[] = {0,0,0,0}; // Disabled fill color

	//Textures
	textureChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";		//Texture of checked CheckBox.
	textureUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";		//Texture of unchecked CheckBox.
	textureFocusedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";	//Texture of checked focused CheckBox (Could be used for showing different texture when focused).
	textureFocusedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";	//Texture of unchecked focused CheckBox.
	textureHoverChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureHoverUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	texturePressedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	texturePressedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureDisabledChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureDisabledUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";

	tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
	tooltipColorText[] = {1,1,1,1}; // Tooltip text color
	tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

	//Sounds
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down
};
