#include "stdafx.h"
#include <iostream>

/*

Recursion functions,
	a C++-ban egy olyan funkció amely önmagát hívja le.

		lásd pl.

			ez egy rosszul megírt rekurzív funkció, amely már a compile idején egy warning-ot dob, jelez arra, hogy
				mivel ahogy a rakás mükődik, ez a funkció nem fog soha semmit visszaadni, ez által a rakásról levenni,
				csak újabb elemeket a rakásra helyezni, így idővel kifogy a rakás memóriából, 
				rakás túlfolyás(stack overflow) jelentkezik.

*/


/*

Recursive termination conditions,
	ahogy a fenti példa bemutatta egy rekurzív funkcióhoz csatolnunk kell egy olyan kondicíót amit ha teljesít abbahagyja	
		önmagát lehívni. Ez a rekurzív terminációs kondicíó. Ha nincs ilyen "örökké" fog futni, azaz míg kinem fogy a rakás memóriából.

		ahogy behelyeztük az if állítást amikor a szamlalo eléri a 0-át már nem az if állítást fog végrehajtódni.
			hanem, kiírja a 'lekerul 1'-et és befejeződik. Ebben a pillanatban a szamoljLe(1) lekerül a rakásról,
			majd átadja az irányítást a szamoljLe(2)-nek, az meg onnan folytatja a végrehajtást ahol a szamoljLe(1)
			abbahagyta és 'lekerul 2'-t ír ki, és befejeződik. A rekurzív funkció hívásai sorban lekerülnek a rakásról
			amíg az összes esete letörlödik.

			! a 'felkerul' esetek azért történnek előre haladó sorrendben mert a rekurzív funkció hívás előtt vannak,
				a 'lekerul' pedig azért van fordított sorrendben mert a rekurzív funkció után fordulnak elő.

*/


/*

Recursive algorithms,
	a legtöbb rekurzív algoritmusban, néhány input triviális output-ot eredményez.
		pl. a osszegAddig(1)-nek az eredménye 1 ami fejben is kiszámolható.
			az ilyen eseteket hívjuk alap esetnek(base case) és ezek mükődnek befejezési kondicíóként az algoritmusoknak.
			amikor alap esetek keresünk gyakran használjuk a 0, 1, "", ", null inputokat.

*/


/*

Fibonacci numbers,
	az egyik leghíresebb matematikai rekurzív algoritmus a fibonacci sorozat.
	minden egyes fibonacci szám annak a négyzetnek az oldal hossza amelyben a szám megjelenik.

*/


/*

Recursive vs iterative,
	az esetek nagy többségében minden olyan funkció amely rekurzíót használ, megoldható ismétlődéssel is, akár for looppal,
		vagy while looppal.

		általánosban:
			- a rekurzív kódot sokkal egyszerűbb beépíteni.
			- a rekurzív mélység limitálható(pl. nincs mód arra, hogy olyan inputot adjunk meg amely azt okozza, hogy
				100,000 szintet menjen le a rekurzíó)
			- az ismétlődő változata az algoritmusnak igényeli, hogy egy rakás adatot kezeljünk.
			- ez nem egy teljesítmény kritikus része a kódnak.

		! szabály, általánosságban használd inkább az ismétlődést mint a rekurzíót, kivéve ha a rekurzíónak igazán értelme van.

*/