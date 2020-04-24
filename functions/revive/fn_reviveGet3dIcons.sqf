#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Returns structured text that can be displayed in "Hold Action" tech as animated unconscious state icon.

	Parameters:
	OBJECT - unconscious unit

	Returns:
	Structured text with animated unconscious state "Hold Action" icon.

	Example:
	_structuredText = _unit call pams_fnc_reviveGet3dIcons;
*/

private _selected = if (group player != group _unit) then
{
	if (pams_revive_timer == 0 || {isNil{_this getVariable "pams_fnc_reviveGet3dIcons_textures"}}) then
	{
		switch (true) do
		{
			case (!alive _this):
			{
				TEXTURES_3D_DEAD
			};
			case (IS_BEING_REVIVED(_this)):
			{
				TEXTURES_3D_BEING_REVIVED
			};
			case (IS_FORCING_RESPAWN(_this)):
			{
				TEXTURES_3D_FORCING_RESPAWN
			};
			case ((_this getVariable [VAR_BLOOD_LEVEL,3]) == 0):
			{
				TEXTURES_3D_DYING
			};
			case ((_this getVariable [VAR_BLOOD_LEVEL,3]) == 1):
			{
				[TEXTURES_3D_DYING,TEXTURES_3D_UNCONSCIOUS] select pams_revive_timerCounter2
			};
			case ((_this getVariable [VAR_BLOOD_LEVEL,3]) == 2):
			{
				[TEXTURES_3D_DYING,TEXTURES_3D_UNCONSCIOUS,TEXTURES_3D_UNCONSCIOUS] select pams_revive_timerCounter3
			};
			default
			{
				TEXTURES_3D_UNCONSCIOUS
			};
		};
	}
	else
	{
		//death texture should be replaced immediatelly; no transition
		if (!alive _this) then
		{
			TEXTURES_3D_DEAD
		}
		//use running set until the loop ends; frame == 0
		else
		{
			_this getVariable "pams_fnc_reviveGet3dIcons_textures";
		};
	};
}
else
{
	if (pams_revive_timer == 0 || {isNil{_this getVariable "pams_fnc_reviveGet3dIcons_textures"}}) then
	{
		switch (true) do
		{
			case (!alive _this):
			{
				TEXTURES_3D_GROUP_DEAD
			};
			case (IS_BEING_REVIVED(_this)):
			{
				TEXTURES_3D_GROUP_BEING_REVIVED
			};
			case (IS_FORCING_RESPAWN(_this)):
			{
				TEXTURES_3D_GROUP_FORCING_RESPAWN
			};
			case ((_this getVariable [VAR_BLOOD_LEVEL,3]) == 0):
			{
				TEXTURES_3D_GROUP_DYING
			};
			case ((_this getVariable [VAR_BLOOD_LEVEL,3]) == 1):
			{
				[TEXTURES_3D_GROUP_DYING,TEXTURES_3D_GROUP_UNCONSCIOUS] select pams_revive_timerCounter2
			};
			case ((_this getVariable [VAR_BLOOD_LEVEL,3]) == 2):
			{
				[TEXTURES_3D_GROUP_DYING,TEXTURES_3D_GROUP_UNCONSCIOUS,TEXTURES_3D_GROUP_UNCONSCIOUS] select pams_revive_timerCounter3
			};
			default
			{
				TEXTURES_3D_GROUP_UNCONSCIOUS
			};
		};
	}
	else
	{
		//death texture should be replaced immediatelly; no transition
		if (!alive _this) then
		{
			TEXTURES_3D_GROUP_DEAD
		}
		//use running set until the loop ends; frame == 0
		else
		{
			_this getVariable "pams_fnc_reviveGet3dIcons_textures";
		};
	};
};


_this setVariable ["pams_fnc_reviveGet3dIcons_textures",_selected];

_selected