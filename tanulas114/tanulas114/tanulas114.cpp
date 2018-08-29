#include "pch.h"
#include <iostream>

/*

Szóval, az ez előtt leckében megtanultam, hogy hogyan inicializálódnak a származtatott classok.

	- ebben a leckében a konstruktőrök szerepéről lesz szó.

	lásd pl. a Base-Derived class

		egy nem származtatott class csak a saját tagjaiért kell aggódjon,
			ez teljesen normális
		azonban, egyetlen fő eltérés van a származtatott classal szemben,
			mielőtt a Derived class konstruktőre végrehajtódna, a Base class konstruktőrje hajtódik végre,
				majd az irányítás visszatér a Derived class konstruktőrjéhez.

	
Initializing base class members,
	egyik hátulütője a jelenlegi Derived konstruktőrünknek, hogy semmi lehetőség nincs arra, hogy a Base classhoz tartozó
		m_id változót inicializáljuk.

		- rengeteg kezdő programozó, úgy próbálja ezt megoldani, hogy egy új id paramétert add hozzá, majd az m_id-t
			inicializálja vele, azonban ez nem fog mükődni
		- a helyes megoldás az, hogy hozzáadjuk az id paramétert, de a Base(id) konstruktőrt hívjuk le inicializálási
			listában.

			! azért nem mükődik az első megoldás mert, egy classon belül csak a nem származtatott változókat lehet
				inicializálási listában inicializálni

			! azért ez a helyes megoldás mert, minden eddigi példában a Base class része az alapértelmezett konstruktőrrel
				jött létre, és miért?, mert nem mondtuk neki, hogy másképpen tegye.
				az inicializálási listában a konstruktőr lehívásával meg lehet határozni melyik konstruktőrt akarjuk használni


Now we can make our variables private,
	mostmár, hogy tudjuk hogyan kell a Base részét is inicializálni úgy ahogy mi akarjuk, nincs értelme publikusként
		tartani a változókat

		! fontos megjegyezni, mivel a privát változókat csak az úgyanazon classon belül található tag funkciók érhetik el,
			ezért a származtatott classok sem érhetik el, ők is elérési funkciókat kell használjanak

			lásd pl.


Inheritance chains,
	! fontos megjegyezni, láncok esetében a gyerek class, csak az ő szülő classának tudja lehívni a konstruktőrjét
		egy A-B-C inheritance chain esetében, a C csakis a B konstruktőrt hívhatja le, és a B az A-t,
			nincs közvetlen lehetőség arra, hogy a C az a A konstruktőrjét használja

Destructors,
	úgyanúgy mükődik, csak pont fordított sorrendben.
		először C destruktőr, majd B végül A.

*/