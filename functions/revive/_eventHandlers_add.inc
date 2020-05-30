player setVariable ["eams_revive_ehHandleDamage", player addEventHandler ["HandleDamage",eams_fnc_reviveEhHandleDamage]];
//player setVariable ["eams_revive_ehDammaged", player addEventHandler ["Dammaged",eams_fnc_reviveEhDammaged]];
//player setVariable ["eams_revive_ehHandleHeal", player addEventHandler ["HandleHeal",eams_fnc_reviveEhHandleHeal]];
player setVariable ["eams_revive_ehRespawn", player addEventHandler ["Respawn",eams_fnc_reviveEhRespawn]];
