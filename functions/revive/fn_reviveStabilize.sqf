#include "defines.inc"
/*
	Author: Jiri Wainar

	Description:
	Used to execute specific code localy on every client whenever "being revived" flag changes.

	Parameters:
		_this select 0: STRING - Variable that carries the "being revived" flag over the network, defined by macro VAR_TRANSFER_BEING_REVIVED.
		_this select 1: BOOL - Flag state - true or false.
		_this select 2: OBJECT - Unit to set the flag for.

	Returns:
	True if successful, false if not.
*/
