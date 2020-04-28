//We need to discover how the armor values affect the number given in depends and how that can then interact in reaching a total of 1 in INCAPACITATED
#define ADD_HITPOINTS_EAMS(armorLeg,armorArm)\
	class HitLeftArm {\
        armor = 2;\
        material = -1;\
        name = "hand_l";\
        passThrough = 0.1;\
        radius = 0.08;\
        explosionShielding = 1;\
        visual = "injury_hands";\
        minimalHit = 0.01;\
    };\
    class HitRightArm: HitLeftArm {\
        name = "hand_r";\
    };\
    class HitLeftLeg {\
        armor = 2;\
        material = -1;\
        name = "leg_l";\
        passThrough = 0.1;\
        radius = 0.15;\
        explosionShielding = 1;\
        visual = "injury_legs";\
        minimalHit = 0.01;\
    };\
    class HitRightLeg: HitLeftLeg {\
        name = "leg_r";\
    };\
	class EAMS_Incapacitated {\
		armor = 1000;\
		depends = "((hitLeftLeg + hitRightLeg) * 0.15) + ((hitLeftArm + hitRightArm) * 0.20) + (hitBody * 0.45) + (HitHead * 0.55) + (Total * 0.35)";\
		explosionShielding = 1;\
		material = -1;\
		minimalHit = 0;\
		name = "";\
		passThrough = 0;\
		radius = 0;\
		visual = "";\
	}
