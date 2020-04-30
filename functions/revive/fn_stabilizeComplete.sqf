#include "defines.inc"
/*
	Author: willithappen - based on scripts by Jiri Wainar (Bohemia Interactive)

	Description:
	Code to indicate that the player has been stabilized succesfully and send necesarry state change.

	Parameters:
	0: _player - The unit doing the healing (should be local)
	1: _target - the unit being healed (is not local to the _player)

	Returns:
	none
*/
params ['_player','_target'];
SET_BEING_STABILIZED(_target,false);
//stop revive animation
_player playAction 'medicStop';
SET_STATE(_target,STATE_STABILIZED);
//remove Morphine from target or player inventory
if (CAN_USE_EAMSITEM(_healer,'EAMS_Epinephrine')) then {
	_healer removeItem 'EAMS_Epinephrine'} else {
	if (CAN_USE_EAMSITEM(_target,'EAMS_Epinephrine')) then {
		_target removeItem 'EAMS_Epinephrine'
	};
};
