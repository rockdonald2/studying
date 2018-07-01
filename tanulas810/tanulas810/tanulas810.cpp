#include "stdafx.h"
#include <iostream>

/*

Const class objects and member functions,
	Const classes,
		A sima, alapvető adattípusokhoz hasonlóan a példázott class objectek is lehetnek constok a 'const' kulcsszóval.
			Az inicializálást ekkora a konstruktőr végzi.

		Azután miután egy konstans class object inicializálva lett a konstruktőr által, bármiféle módosítás a tag változókra
			nézve nem engedélyezett, mivel ez megsérteni a konstansság szabályát. Ez magába foglalja a közvetlen módon való
				módosítást(ha a tag változó publikus) vagy lehívni olyan tag funkciót ami módosítja a tag változókat.

	Const member functions,
		a const tag funkció egy olyan tag funkció amely garantálja, hogy semmilyen módon nem módosítja az objectet, vagy hív le
			olyan nem-konstans tag funkciót ami módosíthatja az objectet.
		const objectek csakis const tag funkciót hívhatnak le.
		olyan tag funkciókon amelyek a class meghatározáson kivül vannak meghatározva, a const kulcsszót mind a function 
			prototypeon a class meghatározásban, mind a funkció meghatározásban kell használni.
		a const kulcsszót a paraméterek után de a funkció body előtt kell írni. 
		továbbá, minden const tag funkció ami módosítani probálja a tag változót vagy lehív egy nem-konstans tag funkciót compile
			error okoz.
		! szabály, tegyél bármely tag funkciót konstanssá ami nem módosítja a class object állását.


	Const references,
		habár példázni konstans class objectet egy mód arra, hogy const objecteket hozzunk létre, egy másik gyakori út
			egy object továbbadása egy funkcióhoz const hivatkozás által.
		ez megelőzi a szükségtelen másolat létrehozását.
		azonban vigyázz, amikor egy konstans objectet használsz paraméterként, az összes tag funkció amit lehívsz a objectre
			const kell legyen.

			lásd pl. neten.

	Overloading const and non-const function,
		utoljára, bár nem túl gyakori, lehetséges overloadolni egy funkciót egy olyan módon, hogy létezzen egy const és
			egy nem-const változata úgyanannak a funkciónak.
		a const változat le lesz hívva minden const objectre, a nem-const mindem nem-const objectre.
			lásd pl. neten.
		ez így sokkal rugalmasabb lesz, mivel a nem-const változat használható írás-olvasásra, így akár módosíthatja is
			az értéket, de a const használható akár const akár nem-const objectre, és visszaad egy const hivatkozást.


	Összegző!
		! - minden tag funkciót ami nem módosítja a class object állását tegyél const-tá.
*/