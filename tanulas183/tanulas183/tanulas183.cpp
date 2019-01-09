#include "pch.h"
#include <iostream>

/*

Ebben a leckében az iostream output classjának vizsgáljuk meg a funkcionalításait

The insertion operator,
	az insertion operátort<< használjuk, hogy információt rakjunk bele egy output streambe
	- a C++-nak beépített insertion operátorjai vannak minden beépített adattípushoz, többihez overloadolni kell

	- mind az istream, mind az ostream az ios classból van származtatva, az ios egyik dolga, hogy irányítsa
		a formatálási beállításokat az outputhoz

Formatting,
	két lehetőség van arra, hogy cseréljünk a formatálási beállításokon: flagek és manipulátorok
	- a flagekre úgy kell tekinteni mint bool változókra, amelyeket ki-be lehet kapcsolni
	- a manipulátorok pedig olyan objectek amelyeket a streambe helyezünk, hogy befolyásoljuk hogyan vannak
		a dolgok inputolva vagy outputolva

	- ahhoz, hogy bekapcsoljunk egy flaget használjuk a setf() funkciót, a megfelelő flag-el mint paraméter
		alapértelmezettként a C++ nem mutatja a + jelt a pozítiv számok előtt, de ha használjuk az std::ios::showpos-t
			áttudjuk ezt írni
			lásd pl.
			- lehetőség van arra, hogy több flaget határozzunk meg használva az OR| operátort
			- az unsetf()-el pedig kikapcsolhatjuk a flaget

	a legtrükössebb dolog a setf() használatával az, hogy rengeteg flag különböző csoportokba tartozik,
		amit format groupoknak nevezünk
		- a format group az egy olyan flag csoport ami hasonló formatálási beállításokat hajt végre (gyakran
			egymást kizárják)
			pl. a basefield format group tartalmazza az "oct", "dec", "hex" flageket, ami irányítja az int értékek
				alapját, alapértelmezettként a "dec" flag van beállítva
					lásd pl.
					- az ok amiért nem működik az, hogy a setf() ugyan bekapcsolja a flaget,
						de nem elég okos ahhoz, hogy kikapcsolja az egymást kizáró flageket
						amikor std::hex-et bekapcsoltuk az std::dec is bekapcsolva maradt,
							és az std::dec-nek volt elsőbbsége
							- két megoldása van a problémának
								az első megoldás fura lehet a setf() unsetf()-el
								a második megoldás pedig az, hogy manipulátort használunk
									ők már képesek kikapcsolni az egymást kizáró flageket
									lásd pl.

		- általánosságban, a manipulátorok használata sokkal könnyebb mint a flagek
			- rengeteg beállítás mindkét formában megtalálható, de néhány csak egyik vagy másikban

Useful formatters,
	
		flag: boolalpha (ha bekapcsolva true vagy false-t ír, ha nincs 0 vagy 1)
		manipulator: boolalpha - true/false
					 noboolalpha - 0/1
					 - mindig a 0/1 az alapértelmezett

		flag: showpos (ha bekapcsolva + prefix a pozítiv számok elé)
		manipulator: showpos
					 noshowpos

		flag: uppercase (ha bekapcsolva nagybetűket használ)
		manipulator: uppercase
					 nouppercase

		flag: basefield group: dec, hex, oct, (none)
			balról jobbra: decimal értékekben ír ki, hexadecimal értékben ír ki, octal értékben ír ki,
				vagy az érték első karakterei szerint írja ki
		manipulator: dec, hex, oct


Precision, notation, and decimal points,
	manipulátorokat, vagy flageket használva lehetséges, hogy megváltoztassuk a tizedespontosságot, valamint formátumot
		amiben a float számot kivannak írva

		flag: floatfield group: fixed, scientific, (none), showpoint
			decimális jelölést használ, tudományos jelölést használ, fixed-t használ néhány számjegy esetében,
				tudományost másképp, mindig mutatja a tizedespontot, és a követő nullákat
		manipulator: fixed, scientific, showpoint, noshowpoint, setprecision(int)
			- az utolsó meghatározza a tizedespontosságot (iomanip.h)

		tag funkciók: precision() - visszaadja a jelenlegi tizedespontosságot
					  precision(int) - beállítja a tizedespontosságot, visszaadja a régit

			! ha a pontosság kisebb mint számjegyek száma, a szám kerekítve lesz

Width, fill characters, and justification,
	általában amikor számokat írsz ki, a számok nem törődnek a körülöttük levő hellyel
	- azonban lehetséges, hogy meghatározzuk, hogy bal vagy jobb oldali rendezési legyenek kiírva a számok
	- ahhoz, hogy ezt tegyük először meghatározunk egy field width-et, ami meghatározza a output helyek számát
		egy értékre nézve
		- ha a tényleges szám nagyobb mint a field width, nem lesz a szám megcsonkítva, hanem overflow történik

		flag: adjustfield group: internal(balra az előjel, jobbra szám), left, right
		manipulator: internal, left, right, setfill(char)(kitöltő karakter meghatározása (iomanip.h)),
			setw(int)(field width meghatározása (iomanip.h))
		
		tag funkciók: fill() - visszaadja a jelenlegi kitöltő karaktert
					  fill(char) - fill karakter beállítása, visszaadja a régit
					  width() - visszaadja a jelenlegi field width-et
					  width(int) - beállítja a field width-et, visszaadja a régit

*/