class RscTestControlTypes
{

	idd = 999; // Display identification
	enableSimulation = 1; // 1 (true) to allow world simulation to be running in the background, 0 to freeze it
	enableDisplay = 0; // 1 (true) to allow scene rendering in the background

	onLoad = "_this call compile preprocessFileLineNumbers 'RscTestControlTypes.sqf';";
	onUnload = "systemChat str ['onUnload',_this]; false";
	onChildDestroyed = "systemChat str ['onChildDestroyed',_this]; false";

	class ControlsBackground // Background controls (placed behind Controls)
	{
		class Background
		{
			idc = -1;
			type = CT_STATIC;
			style = ST_LEFT;
			x = GUI_GRID_CENTER_X;
			y = GUI_GRID_CENTER_Y;
			w = GUI_GRID_CENTER_WAbs;
			h = GUI_GRID_CENTER_HAbs;
			colorBackground[] = {0.5,0.5,0.5,1};
			colorText[] = {0,0,0,0};
			font = GUI_FONT_NORMAL;
			sizeEx = GUI_GRID_CENTER_H;
			text = "";
			moving = 1;
		};
	};
	class Controls // Main controls
	{
		class _CT_STATIC
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_STATIC; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_STATIC"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			moving = 0; // 1 (true) to allow dragging the whole display by the control

			autoplay = 0; // Play video automatically (only for style ST_PICTURE with text pointing to an .ogv file)
			loops = 0; // Number of video repeats (only for style ST_PICTURE with text pointing to an .ogv file)

			tileW = 1; // Number of tiles horizontally (only for style ST_TILE_PICTURE)
			tileH = 1; // Number of tiles vertically (only for style ST_TILE_PICTURE)

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onVideoStopped = "systemChat str ['onVideoStopped',_this]; false";
		};
		class _CT_BUTTON
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_BUTTON; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_BUTTON"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			borderSize = 0.01; // Left color width (border is a stripe of the control height on the left side)
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onButtonClick = "systemChat str ['onButtonClick',_this]; false";
			onButtonDown = "systemChat str ['onButtonDown',_this]; false";
			onButtonUp = "systemChat str ['onButtonUp',_this]; false";
		};
		class _CT_EDIT
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_EDIT; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_EDIT"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			canModify = 1; // True (1) to allow text editing, 0 to disable it
			autocomplete = "scripting"; // Text autocomplete, can be "scripting" (scripting commands) or "general" (previously typed text)

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";
		};
		class _CT_SLIDER_Value: _CT_STATIC // Slider value (see below)
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
		class _CT_SLIDER
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
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

			tooltip = "CT_SLIDER"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onSliderPosChanged = "systemChat str ['onSliderPosChanged',_this]; false";
		};
		class _CT_COMBO
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
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

			tooltip = "CT_COMBO"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onLBSelChanged = "systemChat str ['onLBSelChanged',_this]; false";
		};
		class _CT_LISTBOX
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_LISTBOX; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_LISTBOX"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onLBSelChanged = "systemChat str ['onLBSelChanged',_this]; false";
			onLBDblClick = "systemChat str ['onLBDblClick',_this]; false";
			onLBDrag = "systemChat str ['onLBDrag',_this]; false";
			onLBDragging = "systemChat str ['onLBDragging',_this]; false";
			onLBDrop = "systemChat str ['onLBDrop',_this]; false";
		};
		class _CT_TOOLBOX
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_TOOLBOX; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_TOOLBOX"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onToolBoxSelChanged = "systemChat str ['onToolBoxSelChanged',_this]; false";
		};
		class _CT_CHECKBOXES
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_CHECKBOXES; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_CHECKBOXES"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onCheckBoxesSelChanged = "systemChat str ['onCheckBoxesSelChanged',_this]; false";
		};
		class _CT_PROGRESS
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_PROGRESS; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_PROGRESS"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
		};
		class _CT_HTML
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_HTML; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_HTML"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onHTMLLink = "systemChat str ['onHTMLLink',_this]; false";
		};
		//class CT_STATIC_SKEW not implemented
		class _CT_ACTIVETEXT
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_ACTIVETEXT; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_ACTIVETEXT"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			soundClick[] = {"",1,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"",1,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"",1,1}; // Sound played when the control is pushed down
			soundEscape[] = {"",1,1}; // Sound played when the control is released after pushing down

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onButtonClick = "systemChat str ['onButtonClick',_this]; false";
			onButtonDown = "systemChat str ['onButtonDown',_this]; false";
			onButtonUp = "systemChat str ['onButtonUp',_this]; false";
		};
		class _CT_TREE
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_TREE; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_TREE"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onTreeSelChanged = "systemChat str ['onTreeSelChanged',_this]; false";
			onTreeLButtonDown = "systemChat str ['onTreeLButtonDown',_this]; false";
			onTreeDblClick = "systemChat str ['onTreeDblClick',_this]; false";
			onTreeExpanded = "systemChat str ['onTreeExpanded',_this]; false";
			onTreeCollapsed = "systemChat str ['onTreeCollapsed',_this]; false";
			//onTreeMouseMove = "systemChat str ['onTreeMouseMove',_this]; false"; // Causing CTD
			//onTreeMouseHold = "systemChat str ['onTreeMouseHold',_this]; false"; // Causing CTD
			onTreeMouseExit = "systemChat str ['onTreeMouseExit',_this]; false";
		};
		class _CT_STRUCTURED_TEXT
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_STRUCTURED_TEXT; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_STRUCTURED_TEXT"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
		};
		//class CT_CONTEXT_MENU not implemented in class Controls
		class _CT_CONTROLS_GROUP
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_CONTROLS_GROUP; // Control identification (without it, the control won't be displayed)
			type = CT_CONTROLS_GROUP; // Type
			style = LB_TEXTURES; // Style
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 10 * GUI_GRID_CENTER_W; // Width
			h = 3 * GUI_GRID_CENTER_H; // Height

			class Controls
			{
				class _CT_STATIC: _CT_STATIC
				{
					idc = CT_CONTROLS_GROUP_CT_STATIC
					style = ST_PICTURE;
					blinkingPeriod = 0;
					x = 0;
					y = 0;
					w = 20 * GUI_GRID_CENTER_W;
					h = 5 * GUI_GRID_CENTER_H;
					text = "#(ai,512,512,1)perlinNoise(512,128,0,1)";
					tooltip = "CT_CONTROLS_GROUP"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";
		};
		class _CT_SHORTCUTBUTTON
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_SHORTCUTBUTTON; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_SHORTCUTBUTTON"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onButtonClick = "systemChat str ['onButtonClick',_this]; false";
			onButtonDown = "systemChat str ['onButtonDown',_this]; false";
			onButtonUp = "systemChat str ['onButtonUp',_this]; false";
		};
		//class CT_HITZONES not implemented in class Controls
		//class CT_XKEYDESC not implemented in class Controls
		class _CT_XBUTTON
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_XBUTTON; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_XBUTTON"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			period = 1; // Oscillation time between colorBackground and colorFocused when selected

			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onButtonClick = "systemChat str ['onButtonClick',_this]; false";
			onButtonDown = "systemChat str ['onButtonDown',_this]; false";
			onButtonUp = "systemChat str ['onButtonUp',_this]; false";
		};
		class _CT_XLISTBOX
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_XLISTBOX; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_XLISTBOX"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture

			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onLBSelChanged = "systemChat str ['onLBSelChanged',_this]; false";
			onLBDblClick = "systemChat str ['onLBDblClick',_this]; false";
		};
		class _CT_XSLIDER
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_XSLIDER; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_XSLIDER"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onSliderPosChanged = "systemChat str ['onSliderPosChanged',_this]; false";
		};
		class _CT_XCOMBO // Xbox combo box, cannot be controlled with mouse
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_XCOMBO; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_XCOMBO"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onLBSelChanged = "systemChat str ['onLBSelChanged',_this]; false";
			onLBDblClick = "systemChat str ['onLBDblClick',_this]; false";
			onLBListSelChanged = "systemChat str ['onLBListSelChanged',_this]; false";
		};
		//class CT_ANIMATED_TEXTURE not implemented in class Controls
		//class CT_LINEBREAK not implemented in class Controls
		//class CT_USER not available without engine support
		class _CT_MAP
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_MAP; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_MAP"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onDraw = "";
		};
		class _CT_MAP_MAIN: _CT_MAP
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_MAP; // Control identification (without it, the control won't be displayed)
			type = CT_MAP_MAIN; // Type
			style = ST_PICTURE; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 29 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 8 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 10 * GUI_GRID_CENTER_W; // Width
			h = 6 * GUI_GRID_CENTER_H; // Height

			tooltip = "CT_MAP_MAIN"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onDraw = "";
		};
		class _CT_LISTNBOX
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_LISTNBOX; // Control identification (without it, the control won't be displayed)
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

			tooltip = "CT_LISTNBOX"; // Tooltip text
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

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onLBSelChanged = "systemChat str ['onLBSelChanged',_this]; false";
			onLBDblClick = "systemChat str ['onLBDblClick',_this]; false";
		};
		class _CT_LISTNBOX_RIGHT: _CT_BUTTON
		{
			idc = 1000;
			text = "<";
			borderSize = 0;
			colorShadow[] = {0,0,0,0};
		};
		class _CT_LISTNBOX_LEFT: _CT_LISTNBOX_RIGHT
		{
			idc = 1001;
			text = ">";
		};
		//class CT_ITEMSLOT not available without engine support
		class _CT_CHECKBOX
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
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

			tooltip = "CT_CHECKBOX"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			//Sounds
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

			onCanDestroy = "systemChat str ['onCanDestroy',_this]; true";
			onDestroy = "systemChat str ['onDestroy',_this]; false";
			onMouseEnter = "systemChat str ['onMouseEnter',_this]; false";
			onMouseExit = "systemChat str ['onMouseExit',_this]; false";
			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";
		};
	};
	class Objects // UI objects
	{
		class _CT_OBJECT
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_OBJECT; // Control identification (without it, the control won't be displayed)
			type = CT_OBJECT; // Type
			style = ST_LEFT; // Style
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			model = "\a3\Ui_f\objects\Watch.p3d"; // Displayed model
			scale = 2; // Model scale

			x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			z = 1; // Depth coordinates
			//position[] = {0,0,1}; // Alternative XYZ coordinates, where XY is center of the screen

			direction[] = {0,0,1}; // Model vector dir
			up[] = {0,1,0}; // Model vector up

			tooltip = "CT_OBJECT"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onObjectMoved = "systemChat str ['onObjectMoved',_this]; false";
		};
		class CT_OBJECT_ZOOM
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_OBJECT_ZOOM; // Control identification (without it, the control won't be displayed)
			type = CT_OBJECT_ZOOM; // Type
			style = ST_LEFT; // Style
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			model = "\a3\Ui_f\objects\Compass.p3d"; // Displayed model
			scale = 2; // Model scale

			x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			z = 1; // Depth coordinates
			//position[] = {0,0,1}; // Alternative XYZ coordinates, where XY is center of the screen

			xBack = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal background coordinates
			yBack = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical background coordinates
			zBack = 2; // Depth background coordinates
			//positionBack[] = {0,0,2}; // Alternative XYZ coordinates, where XY is center of the screen

			enableZoom = 1; // Allow foreground/background transformation
			zoomDuration = 0.5; // Speed of foreground/background transformation
			inBack = 0; // Start in back (Back coordinates are used)

			direction[] = {0,1,1}; // Model vector dir
			up[] = {0,1,0}; // Model vector up

			tooltip = "CT_OBJECT_ZOOM"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			onSetFocus = "systemChat str ['onSetFocus',_this]; false";
			onKillFocus = "systemChat str ['onKillFocus',_this]; false";
			onKeyDown = "systemChat str ['onKeyDown',_this]; false";
			onKeyUp = "systemChat str ['onKeyUp',_this]; false";
			onMouseButtonDown = "systemChat str ['onMouseButtonDown',_this]; false";
			onMouseButtonUp = "systemChat str ['onMouseButtonUp',_this]; false";
			onMouseButtonClick = "systemChat str ['onMouseButtonClick',_this]; false";
			onMouseButtonDblClick = "systemChat str ['onMouseButtonDblClick',_this]; false";
			onMouseZChanged = "systemChat str ['onMouseZChanged',_this]; false";
			onMouseMoving = "";
			onMouseHolding = "";

			onObjectMoved = "systemChat str ['onObjectMoved',_this]; false";
		};
		class _CT_OBJECT_CONTAINER
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_OBJECT_CONTAINER; // Control identification (without it, the control won't be displayed)
			type = CT_OBJECT_CONTAINER; // Type
			style = ST_LEFT; // Style
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			model = "\A3\Misc_F\Helpers\UserTexture1m.p3d"; // Displayed model
			scale = 0.2; // Model scale

			x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			z = 1; // Depth coordinates
			//position[] = {0,0,1}; // Alternative XYZ coordinates, where XY is center of the screen

			xBack = 25 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal background coordinates
			yBack = 12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical background coordinates
			zBack = 2; // Depth background coordinates
			//positionBack[] = {0,0,2}; // Alternative XYZ coordinates, where XY is center of the screen

			enableZoom = 1; // Allow foreground/background transformation
			zoomDuration = 0.5; // Speed of foreground/background transformation
			inBack = 0; // Start in back (Back coordinates are used)

			direction[] = {1,0,0.5}; // Model vector dir
			up[] = {0.5,1,0}; // Model vector up

			tooltip = "CT_OBJECT"; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			class Areas // Configurable UI areas. Normally interactive controls (buttons, listboxes, ...) are not interactive here.
			{
				class UserTexture
				{
					selection = "usertexture"; // Model selection on which the UI will be rendered
					class Controls
					{
						class _CT_STATIC
						{
							idc = 1100; // Control identification (without it, the control won't be displayed)
							type = CT_STATIC; // Type
							style = ST_LEFT + ST_CENTER + ST_MULTI; // Style

							x = 0; // Horizontal coordinates (relative to the selection area)
							y = 0; // Vertical coordinates (relative to the selection area)
							w = 1; // Width (relative to the selection area)
							h = 1; // Height (relative to the selection area)

							colorBackground[] = {0,0,0,1}; // Fill color

							text = "\nCT_OBJECT\n_CONTAINER"; // Displayed text
							sizeEx = 6 * GUI_GRID_CENTER_H; // Text size
							font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
							colorText[] = {1,1,1,1}; // Text color
							lineSpacing = 1; // When ST_MULTI style is used, this defines distance between lines (1 is text height)
						};
					};
				};
			};
		};
		//class CT_OBJECT_CONT_ANIM discontinued, crashes the game now
	};
};