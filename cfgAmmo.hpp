// Wounds handling per bullet based similarly from ACE3 assigned damage type https://github.com/acemod/ACE3/blob/master/addons/medical_damage/functions/fnc_woundsHandler.sqf
// https://github.com/acemod/ACE3/blob/master/addons/medical_damage/CfgAmmo.hpp

class CfgAmmo {
    class BulletCore;
    class BulletBase: BulletCore {
        EAMS_damageType = "BulletDamage";
    };
    class ShotgunCore;
    class ShotgunBase: ShotgunCore {
        EAMS_damageType = "BulletDamage";
    };

    class Default;
    class FuelExplosion: Default {
        EAMS_damageType = "ExplosiveDamage";
    };
    class Grenade: Default {
        EAMS_damageType = "ExplosiveDamage";
    };
    class GrenadeCore;
    class GrenadeBase: GrenadeCore {
        EAMS_damageType = "ExplosiveDamage";
    };

    class MineCore;
    class MineBase: MineCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class PipeBombCore;
    class PipeBombBase: PipeBombCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class DirectionalBombCore;
    class DirectionalBombBase: DirectionalBombCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class BoundingMineCore;
    class BoundingMineBase: BoundingMineCore {
        EAMS_damageType = "ExplosiveDamage";
    };

    class RocketCore;
    class RocketBase: RocketCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class MissileCore;
    class MissileBase: MissileCore {
        EAMS_damageType = "ExplosiveDamage";
    };

    class SubmunitionCore;
    class SubmunitionBase: SubmunitionCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class SubmunitionBullet: SubmunitionBase {
        EAMS_damageType = "BulletDamage";
    };

    class ShellCore;
    class ShellBase: ShellCore {
        EAMS_damageType = "ExplosiveDamage";
    };

    // There is no BombBase so we modify these separately
    class BombCore;
    class Bo_Mk82: BombCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class LaserBombCore;
    class ammo_Bomb_LaserGuidedBase: LaserBombCore {
        EAMS_damageType = "ExplosiveDamage";
    };
    class BombDemine_01_Ammo_F: BombCore {
        EAMS_damageType = "ExplosiveDamage";
    };

    // Autocannon rounds are special (#7401)
    class B_19mm_HE: BulletBase {
        EAMS_damageType = "ExplosiveDamage";
    };
    class B_20mm: BulletBase {
        EAMS_damageType = "ExplosiveDamage";
    };
    class B_25mm: BulletBase {
        EAMS_damageType = "ExplosiveDamage";
    };
    class B_35mm_AA: BulletBase {
        EAMS_damageType = "ExplosiveDamage";
    };

    // These are also special
    class Gatling_30mm_HE_Plane_CAS_01_F: BulletBase {
        EAMS_damageType = "ExplosiveDamage";
    };
};
