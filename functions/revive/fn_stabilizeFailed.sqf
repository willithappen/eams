#include "defines.inc"
/*
	Author: willithappen - based on scripts by Jiri Wainar (Bohemia Interactive)

	Description:
	Indicates the stabilize was not successful (due to exiciting the command in some way)

	Parameters:
	0: _player - The unit doing the healing (should be local)
	1: _target - the unit being healed (is not local to the _player)

	Returns:
	none
*/
params ['_healer','_target'];
_healer playAction 'medicStop';
