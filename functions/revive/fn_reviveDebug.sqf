#include "defines.inc"

#define MODE_START		1
#define MODE_STOP		0

private _mode = param [0, MODE_START, [123]];
private _script = missionNamespace getVariable ["bis_debugScript",scriptNull];

if (_mode == MODE_STOP) exitWith
{
	if (!isNull _script) then
	{
		terminate _script;
		hintSilent "";
		bis_debugScript = scriptNull;
	};
};

if (_mode == MODE_START && {!isNull _script}) exitWith {};

_script = [] spawn
{
	scriptName "eams_fnc_reviveDebug";

	private _fn_getUnitInfo =
	{
		if (isNull _this) exitWith {[]};

		private _unit = _this;
		private _info = [];

		{
			_info pushBack _x;
		}
		forEach
		[
			format["var: %1", _unit call bis_fnc_objectVar],
			format["name: %1", name _unit],
			format["state: %1", ["RESPAWNED","REVIVED","INCAPACITATED","DYING","DEAD","DOWNED"] select (GET_STATE(_unit))],
			format["being revived: %1", IS_BEING_REVIVED(_unit)],
			format["forcing respawn: %1", IS_FORCING_RESPAWN(_unit)]
		];

		_info
	};

	while {true} do
	{
		sleep 0.1;

		{
			player reveal [_x, 4];
		}
		forEach allUnits;

		private _info = ["--- PLAYER ---"] + (player call _fn_getUnitInfo);

		if (!isNull cursorTarget && {cursorTarget isKindOf "Man"}) then
		{
			_info pushBack "";
			_info pushBack "--- TARGET ---";
			_info = _info + (cursorTarget call _fn_getUnitInfo);
		};

		private _text = "";

		{
			_text = _text + _x + "<br/>";
		}
		forEach _info;

		hintSilent parseText _text;
	};
};

missionNamespace setVariable ["bis_debugScript",_script];