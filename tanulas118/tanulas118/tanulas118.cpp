#include "pch.h"
#include <iostream>

/*

Changing an inherited member's access level,
	a C++ lehetővé teszi számunkra, hogy megváltoztassuk egy örökölt tag hozzáférési pontosítóját.
		ezt úgy tesszük meg, hogy használunk egy using deklarácíót együtt a class nevével, a scope qualifier operátorral, valamint
			a taggal(funkciók esetében zárójel nélkül) az új hozzáférés neve alatt.
			lásd pl.


			! fontos megjegyzések, csak olyan tagnak tudod megváltoztani a hozzáférését, amit az öröklödő class normális esetben eltud érni.
				a C++11 után a megfelelő megváltoztatási mód ez, azonban régebbi kódokban található egy fajta "access declaration" ami úgyanolyan mint ez,
					csak elhagyja az using kulcsszót.


Hiding functionality,
	a C++-ban nincs mód arra, hogy eltávolítsunk, vagy korlátozzunk funkcionalítást a base classból, anélkül, hogy modósítanánk a forráskódját.
	azonban a derived classban lehetőség van arra, hogy elrejtsük a funkcionalítást, így nem érhető el derived objecteken keresztül.

		ezt úgy tesszük, hogy megváltoztatjuk a hozzáférését, publicról privátra.


		úgyanakkor, funkciók esetében simán törölhetjük is, a funkció = delete metódussal.
	

*/