#include "stdafx.h"
#include <iostream>

/*

Public and private members,
	A publikus tagok(public members), olyan sturct vagy class tagok amelyek a class vagy struct-on kivülről is elérhetőek.
		Minden struct tag alapból publikus.
			lásd pl.
	A privát tagok, azok a class tagok amelyek csak más class tagok érhetnek el.
		Minden class tag alapból privát.
			lásd pl.
		Alapból ugye privátak, de a 'public' kulcsszó kifejezett használatával publikussá tehetők a tagok.
			A 'public' kulcsszó egy hozzáférési pontosító, ezen kivül még kettő van 'private' és 'protected'.
				Ezek a kulcsszók meghatározzák, hogy kinek van hozzáférése az adott class tagokhoz amelyek a pontosító után
					következnek. A 'public' és 'private' kulcsszóval tehetjük publikussá, vagy priváttá az őket követő tagokat,
					a 'protected' kulcsszóval majdnem úgyanúgy viselkedik mint a 'private'.

*/

/*

Mixing access specifiers,
	A classok tudnak(és majdnem mindig meg is teszik), hogy különböző hozzáférési pontosításokat használnak az egyes tagokhoz.
		Nem létezik erre való korlátozás.
		Általánosságban, a tag változók privátak, és a tag funkciók publikusak.

			lásd pl.

*/