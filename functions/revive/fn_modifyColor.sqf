/*
https://github.com/acemod/ACE3/blob/08a7d2706e9778b054ef1cb1d61e3768607ac4c3/addons/medical_gui/functions/fnc_modifyAction.sqf
Based on content by ACE3 Medical GUI that changes their interaction menu ICON
*/

params ["_target","_part","_ActionData"];
_damage = _target getHitPointDamage _part;
private _dmgratio = 0;
if ((_damage < 0.05) && (_damage > 0)) then {private _dmgratio = 0; _actionData set [2, format ["eams\data\ui\x_%1.paa",_dmgratio]];};
if ((_damage < 0.349) && (_damage > 0.05)) then {private _dmgratio = 1; _actionData set [2, format ["eams\data\ui\x_%1.paa",_dmgratio]];};
if ((_damage < 0.49) && (_damage >= 0.349)) then {private _dmgratio = 2; _actionData set [2, format ["eams\data\ui\x_%1.paa",_dmgratio]];};
if ((_damage < 0.75) && (_damage >= 0.5)) then {private _dmgratio = 3; _actionData set [2, format ["eams\data\ui\x_%1.paa",_dmgratio]];};
if (_damage >= 0.75) then {private _id = 4; _actionData set [2, format ["eams\data\ui\x_%1.paa",_dmgratio]];};
