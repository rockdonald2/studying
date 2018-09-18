#include "pch.h"
#include <iostream>

/*

A következő két leckében arról lesz szó hogyan is vannak a virtuális funkciók beépítve ebbe a nyelvbe.

	- amikor egy c++ program lefuttatódik szekvenciálisan futtatódik le, és mindig a main() funkció tetejétől kezdi.	
	- - amikor egy funkció hívás jelenik meg, a jelenlegi futtatási pont átkerül a lehívott funkció tetejére.
	? de honnan tudja a CPU, hogy oda kell ugornia?

	amikor lefordítodik(compile) egy program, az átalakul egy vagy több sor gépnyelvre.
		továbbá, minden egyes ilyen sornak megvan a maga szekvenciális memória címe, és nincs ez másként a funkciókkal se.

		amikor egy funkció hívás megjelenik valójában nem ugrik sehova, csak a soron következő szekvenciális memóriacím tartalmára ugrik.

Binding
	a kötés az a folyamat ami során egyéni azonosítók(legyenek azok változók vagy funkciónevek) átalakulnak címekké.


Early binding,
	a legtöbb funkció hívás amivel a compiler találkozik közvetlen funkció hívás, ami direkt módon hív le egy funkciót.

	a direkt funkció hívások egy olyan fajta módon lehetnek megoldva amit úgy hívunk, hogy kórai kötés(early binding)
		- ami azt jelenti, hogy a compiler közvetlen módon képes összekapcsolni az azonosító nevet a memória címmel.
			továbbmagyarázva, ez az jelenti, hogy amikor a compiler találkozik egy ilyen funkció hívással, a funkció hívást
				kicseréli a gépnyelvi utasítással, ami arra utasítsa a CPU-t, hogy arra a funkció címére ugorjon.


Late binding,
		néhány programban nem lehetség runtime idejéig kikövetkeztetni, hogy melyik funkció fog lehívódni. Ez a late binding(késői kötés).

		- a C++-ban egy mód arra, hogy késői kötés idézzünk elé, hogy használjuk a funkció mutatókat.
		A funkció mutató egy olyan mutató ami egy funkcióra mutat és nem egy változóra.

		a funkció amire a funkció mutató mutat lehívhat a function call operátorral(()).

		- ezt a fajta lehívást másképp indirekt funkció hívásnak is nevezzük.

*/