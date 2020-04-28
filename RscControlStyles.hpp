class RscTestControlStyles
{
	idd = 998;
	enableSimulation = 1;
	onLoad = "_this call compile preprocessFileLineNumbers 'RscTestControlStyles.sqf';";

	class ControlsBackground
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
			colorBackground[] = {1,1,1,1};
			colorText[] = {0,0,0,0};
			font = GUI_FONT_NORMAL;
			sizeEx = GUI_GRID_CENTER_H;
			text = "";
			moving = 1;
		};
	};
	class Controls
	{
		class _ST_LEFT
		{
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
		class _ST_RIGHT: _ST_LEFT
		{
			idc = ST_RIGHT;
			style = ST_RIGHT;
			text = "ST_RIGHT";
			y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_CENTER: _ST_LEFT
		{
			idc = ST_CENTER;
			style = ST_CENTER;
			text = "ST_CENTER";
			y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_MULTI: _ST_LEFT
		{
			idc = ST_MULTI;
			style = ST_MULTI;
			text = "ST_MULTI\nST_MULTI";
			y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_TITLE_BAR: _ST_LEFT
		{
			idc = ST_TITLE_BAR;
			style = ST_TITLE_BAR;
			text = "ST_TITLE_BAR";
			y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_PICTURE: _ST_LEFT
		{
			idc = ST_PICTURE;
			style = ST_PICTURE;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
			y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_PICTURE_video: _ST_LEFT
		{
			idc = ST_PICTURE + 1000;
			style = ST_PICTURE;
			text = "\A3\Missions_F_Bootcamp\video\VR_BOOT.ogv";
			colorText[] = {1,1,1,1};
			y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 8 * GUI_GRID_CENTER_W;
			h = 5 * GUI_GRID_CENTER_H;

			autoplay = 1;
			loops = 1;
		};
		class _ST_FRAME: _ST_LEFT
		{
			idc = ST_FRAME;
			style = ST_FRAME;
			text = "ST_FRAME";
			x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_BACKGROUND: _ST_FRAME
		{
			idc = ST_BACKGROUND;
			style = ST_BACKGROUND;
			text = "ST_BACKGROUND";
			y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_GROUP_BOX: _ST_FRAME
		{
			idc = ST_GROUP_BOX;
			style = ST_GROUP_BOX;
			text = "ST_GROUP_BOX";
			y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_GROUP_BOX2: _ST_FRAME
		{
			idc = ST_GROUP_BOX2;
			style = ST_GROUP_BOX2;
			text = "ST_GROUP_BOX2";
			y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_HUD_BACKGROUND: _ST_FRAME
		{
			idc = ST_HUD_BACKGROUND;
			style = ST_HUD_BACKGROUND;
			text = "ST_HUD_BACKGROUND";
			y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_TILE_PICTURE: _ST_FRAME
		{
			idc = ST_TILE_PICTURE;
			style = ST_TILE_PICTURE;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
			y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			tileW = 10;
			tileH = 2;
		};
		class _ST_WITH_RECT: _ST_FRAME
		{
			idc = ST_WITH_RECT;
			style = ST_WITH_RECT;
			text = "ST_WITH_RECT";
			y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_LINE: _ST_FRAME
		{
			idc = ST_LINE;
			style = ST_LINE;
			text = "ST_LINE";
			y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_UPPERCASE
		{
			idc = ST_UPPERCASE;
			style = ST_UPPERCASE;
			type = CT_SHORTCUTBUTTON; // Type
			text = "st_UPPERCASE";

			x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 10 * GUI_GRID_CENTER_W;
			h = 2 * GUI_GRID_CENTER_H;

			colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
			colorBackground2[] = {0,0,0,1}; // Selected fill color
			colorBackgroundFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground2)
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color

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

			shortcuts[] = {KEY_XBOX_A, DIK_RETURN, DIK_SPACE, DIK_NUMPADENTER}; // DIK codes of keyoboard shortcuts
			textureNoShortcut = "#(argb,8,8,3)color(1,1,1,0)"; // Icon displayed on ShortcutPos position when no shortcut key is found

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
				left = 0; // Left border
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
		class _ST_LOWERCASE: _ST_UPPERCASE
		{
			idc = ST_LOWERCASE;
			style = ST_LOWERCASE;
			text = "st_LOWERCASE";
			y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_SHADOW: _ST_LEFT
		{
			idc = ST_SHADOW;
			style = ST_SHADOW;
			text = "ST_SHADOW";
			x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_NO_RECT: _ST_SHADOW
		{
			idc = ST_NO_RECT;
			style = ST_NO_RECT;
			text = "ST_NO_RECT";
			y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _ST_KEEP_ASPECT_RATIO: _ST_SHADOW
		{
			idc = ST_KEEP_ASPECT_RATIO;
			style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
			y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
		};
		class _SL_HORZ
		{
			type = CT_SLIDER;
			idc = CT_SLIDER + SL_HORZ;
			style = SL_HORZ;

			x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 10 * GUI_GRID_CENTER_W; // Width
			h = 1 * GUI_GRID_CENTER_H; // Height

			color[] = {0,0,0,1}; // Text color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorActive[] = {1,0.5,0,1}; // Text selection color

			tooltip = "SL_HORZ"; // Tooltip text
		};
		class _SL_VERT: _SL_HORZ
		{
			idc = CT_SLIDER + SL_VERT;
			style = SL_VERT;

			x = 35 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 1 * GUI_GRID_CENTER_W; // Width
			h = 10 * GUI_GRID_CENTER_H; // Height

			tooltip = "SL_VERT"; // Tooltip text
		};
		class _ST_HORIZONTAL
		{
			type = CT_PROGRESS;
			idc = CT_PROGRESS + ST_HORIZONTAL;
			style = ST_HORIZONTAL;

			x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 10 * GUI_GRID_CENTER_W; // Width
			h = 1 * GUI_GRID_CENTER_H; // Height

			texture = "#(argb,8,8,3)color(1,1,1,1)"; // Bar texture
			colorBar[] = {0,0,0,1}; // Bar color
			colorFrame[] = {0,0,0,1}; // Frame color

			tooltip = "ST_HORIZONTAL"; // Tooltip text
		};
		class _ST_VERTICAL: _ST_HORIZONTAL
		{
			idc = CT_PROGRESS + ST_VERTICAL;
			style = ST_VERTICAL;

			x = 37 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 1 * GUI_GRID_CENTER_W; // Width
			h = 10 * GUI_GRID_CENTER_H; // Height

			tooltip = "ST_VERTICAL"; // Tooltip text
		};
	};
};