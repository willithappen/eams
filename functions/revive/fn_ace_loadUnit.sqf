/*
 * Author: Glowbal
 * Loads an unconscious or dead patient in the given or nearest vehicle.
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 * 2: Vehicle <OBJECT> (default: objNull)
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorObject] call ace_medical_treatment_fnc_loadUnit
 *
 * Public: No
 */

params ['_medic', '_patient', ['_vehicle', objNull]];

_vehicle = _patient spawn ace_common_fnc_nearestVehiclesFreeSeat;

private _call = [_medic, _patient,_vehicle] spawn ace_common_fnc_loadPerson;
waitUntil {vehicle _patient != _patient};


if (!isNull _call) then {
    private _patientName = [_patient, false, true] call ace_common_fnc_getName;
    private _vehicleName = getText (configFile >> 'CfgVehicles' >> typeOf _vehicle >> 'displayName');
    [['Loaded %1 into: %2', _patientName, _vehicleName], 3] spawn ace_common_fnc_displayTextStructured;
} else {
	private _patientName = [_patient, false, true] call ace_common_fnc_getName;
	[['Cannot load %1 - Not close enough to a vehicle', _patientName], 3] spawn ace_common_fnc_displayTextStructured;
};
