#include "pch.h"
#include <iostream>

/*

Ahhoz, hogy a C++ megoldjon néhány kihívást az örökléssel kapcsolatban bevezetett két új különleges azonosítót: override és final.


Override specifier,
	az előzö leckében kikőtöttük, hogy egy funkció csak akkor számít overridenak, ha az aláírása, valamint return típusa megegyezik.
		ez figyelmetlen hibákhoz vezethet, például amikor overridenak akarunk egy funkciót de rossz return típust adunk meg.

		lásd pl.
		- ebben az esetben könnyű észrevenni a hibát és orvosolni, azonban egy összetettebb program esetében amikor nincs egyértelmű print,
			fájdalmas lehet megtalálni a hibát

			! ez a probléma megoldására hozták létre az override pontosítót, az 'override' kulcsszót tesszük oda ahova a const járna funkció esetében,
				így bebiztosítva, hogy az a funkció bizony override kell legyen a másik virtuális funkcióval.
				! szabály, használd minden virtuális funkció esetében az override pontosítót, hogy bebiztosítsd magad


Final specifier,
	pont az override pontosító elentétje, olyan virtuális funkció esetében használjuk amit meg akarunk jelölni utolsóként, azaz többet ne lehessen
		overrideolni.

		- oda helyezzük ahova az override-ot.

		! ezt a pontosítot lehet használni classok esetében is, hogy meggátoljuk az öröklést arról a classról
			- ez esetben a class neve után helyezzük el


Covariant return type,
	van egy különleges eset amely során egy származtatott class virtuális funkciója overridenak számit, úgyis, hogy nem azonos return típusuk van.
		! ha a return típus egy hivatkozás vagy egy mutató egy classra, override funkció képesek hivatkozást vagy mutatót visszaadni egy származtatott
			classra -- ezt hívjuk kovariáns return típusnak.

*/