#include "pch.h"
#include <iostream>

/*

Ebben a leckében megtanuljuk, hogy hogyan használjuk az operátort<< öröklés és virtuális funkciók esetében,
	lásd pl
		- az ilyen fajta felosztás felesleges, ezért tanuljuk meg, hogy hogyan kell rendesen outputolni.


The challenges with operator<<,
	ha a hagyományos módon overloadoljuk ezt az operátort jól fog mükődni olyan esetekben mikor nem jelennek meg
		virtuális funkciók, azonban virtuális funkció esetében nem fog virtualizáció alkalmazni mert az overload
		maga nem virtuális.


Can we make operator<< virtual,
	a rövid válasz az, hogy nem, és ennek több oka is van.

	1) első ilyen oka az, hogy csak tag funkció lehetnek overrideolva, és az operator<< overloadja friend funkcióval van.
	2) a két overload paraméterei különböznek


The solution,
	a megoldás meglepően egyszerű.

	elsőként, felállítunk egy friend overloadot hagyományos módon, de ahelyett, hogy az operátorra hagynánk, hogy elvégezze
		a kiírást, eldelegáljuk azt egy olyan tag funkcióra ami már overrideolható, ami virtualizálható.

			lásd pl.

*/