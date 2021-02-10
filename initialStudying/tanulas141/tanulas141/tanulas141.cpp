#include "pch.h"
#include <iostream>

/*

A 3 error kezelési módszer mellett(exit, assert, cerr) létezik az exception(kivétel) is.
	- az exit() úgye a program bezárási funkció
	- a cerr hasonló a cout-hoz, error szöveget ír ki
	- az assert pedig egyfajta védnök, leellenőrzi egy logikai állításban az adatokat, ha nem megfelelőek error üzenetet ír ki.

*/

/*

Amikor újrahasznosítható kódot írunk a legfontosabb az error kezelések
	Az egyik leggyakoribb formája a return kódok használata
		lásd pl.

	! de ez egyben az egyik legrosszabb is, mivel ez a fajta error kezelés bonyolultan kapcsolódik a kód normális lefolyásához
		- így korlatozó mint arra nézve, hogy hogyan néz ki a kód, és hogy hogyan lehet a hibákat ésszerűen kezelni

*/

/*

Ekkor jönnek képbe a kivételek, amelyek egy mechanizmust biztosítanak, hogy szétválasszuk a hibák kezelését vagy más hasonló kivételes eseteket a kód tipikus
	lefolyásától.

*/