//We need to discover how the armor values affect the number given in depends and how that can then interact in reaching a total of 1 in INCAPACITATED
#define ADD_HITPOINTS_EAMS(armorLeg,armorArm)\
class HitFace {\
		armor = 1;\
		material = -1;\
		name = "face_hub";\
		passThrough = 0.8;\
		radius = 0.08;\
		explosionShielding = 0.1;\
		minimalHit = 0.01;\
	};\
	class HitNeck: HitFace {\
		armor = 1;\
		material = -1;\
		name = "neck";\
		passThrough = 0.8;\
		radius = 0.1;\
		explosionShielding = 0.5;\
		minimalHit = 0.01;\
	};\
	class HitHead: HitNeck {\
		armor = 1;\
		material = -1;\
		name = "head";\
		passThrough = 0.8;\
		radius = 0.2;\
		explosionShielding = 0.5;\
		visual = "camo_head";\
		minimalHit = 0.01;\
		depends = "HitFace max HitNeck";\
	};\
	class HitPelvis: HitHead {\
		armor = 6;\
		material = -1;\
		name = "pelvis";\
		passThrough = 0.8;\
		radius = 0.24;\
		explosionShielding = 6;\
		visual = "injury_body";\
		minimalHit = 0.01;\
		depends = "0";\
	};\
	class HitAbdomen: HitPelvis {\
		armor = 1;\
		material = -1;\
		name = "spine1";\
		passThrough = 0.8;\
		radius = 0.16;\
		explosionShielding = 1;\
		visual = "injury_body";\
		minimalHit = 0.01;\
	};\
	class HitDiaphragm: HitAbdomen {\
		armor = 1;\
		material = -1;\
		name = "spine2";\
		passThrough = 0.6;\
		radius = 0.18;\
		explosionShielding = 6;\
		visual = "injury_body";\
		minimalHit = 0.01;\
	};\
	class HitChest: HitDiaphragm {\
		armor = 1;\
		material = -1;\
		name = "spine3";\
		passThrough = 0.5;\
		radius = 0.18;\
		explosionShielding = 6;\
		visual = "injury_body";\
		minimalHit = 0.01;\
	};\
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
	class HitArms {\
		armor = 3;\
		material = -1;\
		name = "arms";\
		depends = "(hitLeftArm + hitRightArm) * 0.5";\
		visual = "injury_hands";\
		passThrough = 0.1;\
		radius = 0.1;\
		explosionShielding = 1;\
		minimalHit = 0.01;\
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
	class HitLegs {\
		armor = 3;\
		material = -1;\
		name = "legs";\
		depends = "(HitLeftLeg + HitRightLeg) * 0.5";\
		visual = "injury_legs";\
		passThrough = 0.1;\
		radius = 0.14;\
		explosionShielding = 1;\
		minimalHit = 0.1;\
	};\
	class EAMS_Incapacitated {\
		armor = 1000;\
		depends = "(hitLegs * 0.15) + (hitArms * 0.20) + (hitBody * 0.45) + (HitHead * 0.55) + (Total * 0.35)";\
		explosionShielding = 1;\
		material = -1;\
		minimalHit = 0;\
		name = "";\
		passThrough = 0;\
		radius = 0;\
		visual = "";\
	};\
    class Incapacitated {\
		armor = 1000;\
		depends = "0";\
		explosionShielding = 1;\
		material = -1;\
		minimalHit = 0;\
		name = "";\
		passThrough = 0;\
		radius = 0;\
		visual = "";\
    }
