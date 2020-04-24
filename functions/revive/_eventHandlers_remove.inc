player removeEventHandler ["HandleDamage",player getVariable ["pams_revive_ehHandleDamage",-1]];
player removeEventHandler ["Dammaged",player getVariable ["pams_revive_ehDammaged",-1]];
player removeEventHandler ["HandleHeal",player getVariable ["pams_revive_ehHandleHeal",-1]];
player removeEventHandler ["Killed",player getVariable ["pams_revive_ehKilled",-1]];
player removeEventHandler ["Respawn",player getVariable ["pams_revive_ehRespawn",-1]];