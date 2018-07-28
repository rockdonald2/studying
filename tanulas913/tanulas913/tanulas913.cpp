#include "stdafx.h"
#include <iostream>

/*

Alapértelmezetten, a C++ bármely konstruktőrt magától értetődö átalakítás operátornak tekint.

	lásd pl.

	habár a makeNegative() funkció a Fraction paramétert vár, a 6-os integert értéket adtuk meg.
		mivel a Fraction classnak van egy konstruktőre ami képes befogadni egy integert, a compiler magától értetődöen átalakítja a 6-os értéket
			egy Fraction objectté.
				ezt csinálja amikor a copy inicializálja makeNegative() f paramétert a Fraction(int, int) konstruktőrrel.


	Olyan konstruktőröket amelyek képesek magától értetődö átalakítást végezni converting konstruktőrnek hívunk.
		C++11 előtt csak egyetlen paraméterrel tudták ezt végezni.
		C++11 után több paraméterrel is tudják végezni.

*/


/*

Explicit keyword,
	a magától értetődö átalakítás használatának ez esetben van értelme, azonban más esetekben nem kivánatos lehet, vagy akár váratlan viselkedést
		is okozhat.

		az olyan konstruktőrök amelyeket az explicit kulcsszóval jelölünk nem képesek ilyen átalakítást végezni.

		lásd pl.

		! úgyanakkor, ez az explicit kulcsszó csak a magától értetődöket blokkolja, a static_cast<>()-ot nem.


Delete keyword,
	azonban ebben az esetben mi tényleg meg akarjuk tiltani, hogy egy 'x' char átlegyen alakítva MyString-é.
		1) létrehozunk egy MyString(char) konstruktőrt és priváttá tesszük.
		2) második mód a 'delete' kulcsszó, lásd pl.
			-amikor egy funkciót e módon 'kitörlünk' bármiféle használata a funkciónak compiler errornak számít.
			-bármely copy konstruktőrt is, vagy overloadolt operátort is törölni lehet, megelőzve azok használatát.

*/