["eams_setHitPointDamage", {
    params ["_target", "_limb", "_dmg"];
    _target setHitPointDamage [_limb, _dmg];
}] call CBA_fnc_addEventHandler;