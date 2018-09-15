#include "pch.h"
#include <iostream>

/*

Az előzö fejezetben megtanultad, hogy hogyan használd az öröklést.
	Ebben a fejezetben megtanuljuk használni az öröklés egyik legfontosabb nézőpontját --  a virtuális funkciókat

	De miért is van rájuk szükség?

		Az öröklés során megtanultad, hogy egy származtatott class több részből tevődik össze: egy rész minden alap class számára,
			és egy a származtatott class számára.

			- amikor létrehozunk egy 'Derived' class objectet két részből fog állni:
				egy 'Base' részből ami először jön létre, és egy 'Derived' részből ami másodikként jön létre.
				! emlékezz, az öröklés egy 'az egy' kapcsolattípust jelent azaz a Derived az egy Base


Pointers, references and derived classes,
	Egyértelmű, hogy létre tudunk hozni 'Derived' mutatókat, illetve hivatkozásokat adott 'Derived' objectre.

	! azonban, képesek vagyunk 'Base' mutatókat, illetve hivatkozásokat létrehozni is.
		- ebben az esetben az ilyen módon létrehozott mutatók, vagy hivatkozásokat csak azokat a tagokat látják amelyek a 'Base' classból
			vagy azokból a classokból származnak amelyeket a 'Base' örököl.
				- így nem lehet a Derived::getValueDoubled() funkciót sem lehívni.


Use for pointers and references to base classes,
	először, például akarsz írni egy olyan funkciót ami kiírja az állat nevét és az általa kiadott hangot.
		- ez a megoldás nélkül több tíz különböző paraméterű de azonos felépítésű overloadolt funkciót kéne alkoss
		- ezzel megtudod oldani a problémát, de egy gondtól ígyis szenvedni fog, ez pedig, hogy mindig a base classhoz
			tartozó tagokat hívja le, például egy funkció esetében.

	másodszor, tegyük fel, hogy van 3 macskád és 3 kutyád, és tárolni akarod őket egy arrayben könnyű elérés miatt
		- ez a megoldás nélkül külön kéne helyezni őket, két különböző típusú arraybe
		- ez a megoldással pedig egyetlen arraybe tudod helyezni egy mutató segítségével.
		- de úgyanaz a probléma

*/