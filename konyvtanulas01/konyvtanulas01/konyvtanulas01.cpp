#include "stdafx.h"
#include <iostream>

/*

Encapsulation(egységbe zárás) - 
	egy alapelv amelyben az adatstruktúra és a tulajdonságai valamint a rajta végzett műveletek egy helyen vannak, egy struktúra
		részeként. Az egységbe záró adatstruktúra neve az osztály(class).

	Az osztályoknak ugye lehetnek példányai(instance), amelyek mint önálló egyedek jelennek meg, ezeket objektumoknak(object) nevezzük.
		egy egyszerű példa alapján:
			- egy labdajáték esetén az osztályok az ellenfél, az ütő, a labda.
			- az objektumok pedig ezek példányai: az a labda amivel éppen játszunk, az ütők, illetve az adott ellenfelek.

Data hiding(adatrejtés) -
	ezzel vagyunk képesek biztosítani azt, hogy az objektum megtudja védeni önmagát, tudja védeni tulajdonságait a program többi
		része ne férhessen hozzá.

		! fontos megjegyezni, hogy az adatrejtésnek kritikus szerepe van a program komplexitás kezelésében is.
			- elég ismernünk az objektum látható műveleteit ahhoz, hogy felhasználhassuk a rendszer megvalósításában, nem szükséges
				a belső felépítését.

Az objektumok közötti kapcsolatok: a kapcsolat nézőponttól függően lehet általánosítás vagy specializáció.
	- kiemelkedően fontos mivel két tulajdonsággal rendelkezik: a speciálisabb osztály rendelkezik az általánosabb osztály
		tulajdonságaival és műveleteivel, úgymond örökli(inherit) azokat.
		továbbá, a másik tulajdonság a behelyettesíthetőség(substitutability). Egy speciálisabb osztály objektuma bárhol
			felhasználható, ahol egy általános osztály objektuma, azaz a speciálisabb osztály példányai helyettesíthetik az
			általánosabbakéit.

Az objektumorientáltság egy paradigma, vagyis szemléletmód amely során:
	- a rendszer funkcióit egymással együttmüködő objektumok valósítják meg.


	Érdekes: magas szintű nyelvek esetében komplexebbek feladatokat oldhatunk meg áttekinthetőbben(pl. c++), de ilyen magas
		szinten nem lehetséges a megfelelő optimalizálás.
			assembly nyelven gyorsabb kódot lehet írni, de C++ esetében áttekinthetőbbet.

*/