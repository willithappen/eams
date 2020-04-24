player setVariable ["pams_revive_ehHandleDamage", player addEventHandler ["HandleDamage",pams_fnc_reviveEhHandleDamage]];
player setVariable ["pams_revive_ehDammaged", player addEventHandler ["Dammaged",pams_fnc_reviveEhDammaged]];
player setVariable ["pams_revive_ehHandleHeal", player addEventHandler ["HandleHeal",pams_fnc_reviveEhHandleHeal]];
player setVariable ["pams_revive_ehKilled", player addEventHandler ["Killed",pams_fnc_reviveEhKilled]];
player setVariable ["pams_revive_ehRespawn", player addEventHandler ["Respawn",pams_fnc_reviveEhRespawn]];