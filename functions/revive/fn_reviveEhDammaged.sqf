#include "defines.inc"

/*
unit: Object - Object the event handler is assigned to
hitSelection: String - Name of the selection where the unit was damaged
damage: Number - Resulting level of damage
hitPartIndex: Number - hit index of the hit selection
hitPoint: String - hit point Cfg name
shooter: Object - shooter reference (to get instigator use getShotParents on projectile)
projectile: Object - the projectile that caused damage
*/

params ["_unit", "", "_damage","","_hitPoint","_source"];
