#include "stdafx.h"
#include <iostream>

/*

Nagyon gyakori mutatót vagy egy hivatkozást hozzárendelni egy structhoz(vagy classhoz).

	Ahogy korábbról már tudjuk, kiválaszthatod egy struct tagját a member selection operátorral, ami egy .

	De ez a séma mükődik mutatók, vagy hivatkozások esetében is.

	! lásd példa


	Mivel a dereferencelt mutató általi member selection furán nézd ki, a C++ biztosít egy másik módot ennek a használatára
		Ez a second member selection operator ( -> )

		! szabály, ha mutatót használsz member selectionre használd a fenti operátort.

*/