#include "stdafx.h"
#include <iostream>

/*

break statement,
	a break állítás egy do, for, switch, vagy while loopot kényszerít, hogy leálljon. 

*/

/*

switch esetében ezzel a break állítással jelezzük, hogy az adott case befejeződött.

*/

/*

egy loop esetében a break állítással azonnal leállíthatjuk azt.

*/


/*

break vs return,
	break esetében a funkció végrehajtási a loopot követő legelső állításnál folytatódik.
	return esetében a teljes funkció véget ér, és a végrehajtás ott folytatódik ahol a funkciót lehívták.

*/


/*

continue statement,
	a continue állítás ad egy kényelmes útat arra, hogy egy loop body végére ugorjunk a jelenlegi ismétlésnél.
	ez hasznos mikor hamarabb akarunk leállítani egyes ismétléseket.

		! csakis for esetében, while esetében végtelenné teszi a loopot.
			! do while esetében a do-t követő while-ba kell incrementelni a loop változót, ekkor rendesen fog mükődni.

*/