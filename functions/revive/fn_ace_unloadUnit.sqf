/*
 * Author: Glowbal
 * Unloads an unconscious or dead patient from their vehicle.
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, bob] call ace_medical_treatment_fnc_unloadUnit
 *
 * Public: No
 */

params ['_medic', '_patient'];
[_patient] call ace_common_fnc_unloadPerson;
_patient switchMove "unconsciousrevivedefault";
