#define ADD_EAMS_MEDICAL_ITEMS()\
class CBA_MiscItem;\
class CBA_MiscItem_ItemInfo;\
class EAMS_ItemCore: CBA_MiscItem {};\
class EAMS_BloodBag: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen / Bohemia Interactive";\
	scope = 2;\
	displayName = "Blood IV (1000ml)";\
	descriptionShort = "Use to replace blood loss<br/>Usable on: Self, Others";\
	model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";\
	picture = "\eams\data\icons\IVBag_ICO.paa";\
	mass = 7;\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 7;\
	};\
};\
class EAMS_BloodBag_500: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen / Bohemia Interactive";\
	scope = 2;\
	displayName = "Blood IV (500ml)";\
	descriptionShort = "Use to replace blood loss<br/>Usable on: Self, Others";\
	model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";\
	picture = "\eams\data\icons\IVBag_ICO.paa";\
	mass = 3.5;\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 3.5;\
	};\
};\
class EAMS_BloodBag_250: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen";\
	scope = 2;\
	displayName = "Blood IV (250ml)";\
	descriptionShort = "Use to replace blood loss<br/>Usable on: Self, Others";\
	model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";\
	picture = "\eams\data\icons\IVBag_ICO.paa";\
	mass = 1.75;\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 1.75;\
	};\
};\
class EAMS_BasicBandage: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen / Bohemia Interactive";\
	scope = 2;\
	displayName = "Basic Bandage";\
	descriptionShort = "Use to treat wounds.<br/>Usable on: Self, Others";\
	model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";\
	picture = "\eams\data\icons\Bandage_Basic_ICO.paa";\
	mass = 1.75;\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 1.75;\
	};\
};\
class EAMS_BasicBandage_Half: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen / Bohemia Interactive";\
	scope = 1;\
	displayName = "Basic Bandage (Half)";\
	descriptionShort = "Use to treat wounds.<br/>Usable on: Self, Others";\
	model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F";\
	picture = "\eams\data\icons\Bandage_Basic_ICO";\
	mass = 0.85;\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 0.85;\
	};\
};\
class EAMS_Epinephrine: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen / Bohemia Interactive";\
	scope = 2;\
	displayName = "Epinephrine Autoinjector";\
	descriptionShort = "Used to wake a patient up and revive<br/>Usable on: Self, Others";\
	model = "a3\Props_F_Orange\Humanitarian\Garbage\MedicalGarbage_01_Injector_F";\
	picture = "\eams\data\icons\Injector_Epinephrine_ICO";\
	mass = 0.5;\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 0.5;\
	};\
};\
class EAMS_MedicBag: EAMS_ItemCore {\
	author = "Easy ArmA Medical System - willithappen / Bohemia Interactive";\
	scope = 2;\
	displayName = "Medic Bag";\
	descriptionShort = "Use to speed up healing of wounds<br/>Usable on: Self, Others";\
	model = "\A3\Props_F_Orange\Humanitarian\Camps\FirstAidKit_01_closed_F";\
	picture = "\eams\data\icons\MedicBag_ICO";\
	class ItemInfo: CBA_MiscItem_ItemInfo {\
		mass = 10;\
	};\
}
