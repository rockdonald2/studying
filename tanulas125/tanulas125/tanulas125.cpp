#include "pch.h"
#include <iostream>

/*

Ahhoz, hogy a C++ beépítse a virtuális funkciókat egy speciális fajtájú late bindingot alkalmaz amit úgy hívunk virtual table.
	A virtual table egy összesítő táblázat a funkciókból, amit arra használnak, hogy funkció hívásokat oldjanak meg late binding módon.

	minden olyan class ami használ virtuális funkciót(vagy olyan classból van származtatva ami használ virtuális funkciót) rendelkezik virtual tablelel.
	a virtual table lényegében egy static array amit a compiler hoz létre compile idején.
	ebben az arrayben minden egyes virtuális funkciónak van egy belépése ami lehívható a class objectjei által.
	minden egyes ilyen belépő lényegében egy funkció mutató ami a legszármaztatotabb funkcióra mutat ami elérhető a class által.
	azonkivül, a compiler hozzáad egy rejtett mutatót is a base classhoz, amit mi *__vptr-nek hívunk
	a *__vptr mutató akkor jön létre amikor a classot esetezzük, és automatikusan a virtual table-re mutat
	nem úgy mint a *this mutató ez a mutató egy valódi mutat
	ez azt jelenti, hogy ez a mutató öröklődik.
	
*/