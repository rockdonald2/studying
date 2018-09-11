#include "pch.h"
#include <iostream>

/*

Adding new functionality to a derived class,
	az első leckében megtanultuk, hogy az öröklés által egy olyan előnyhöz jutunk, hogy képesek vagyunk már megint kódot újrahasználni.

	képes vagy örököltetni egy meglépő alap funkcionalítást, majd új funkcionalítást beépíteni, módosítani vagy akár elrejteni.

		lásd pl.

		- ebben az esetben ugye közvetlen hozzáférésünk van a Base forráskódjához, így adva hozzá plusz funkcionalítást.
			de mivan akkor ha nem tudjuk, vagy akarjuk modosítani a Base kódját?
				mivel a fenti példában protected kulcsszóval van védve az m_value változó a Derived classnak közvetlen hozzáférése van.
				így beépítjük a Derived classba az m_value elérését.


		ez a funkció által a Derived classból származó objectek képesek elérni az m_value értékét.
		de a Base classból származó objectek nem.

*/