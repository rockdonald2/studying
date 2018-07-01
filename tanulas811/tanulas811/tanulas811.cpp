#include "stdafx.h"
#include <iostream>

/*

Static member variables,
	korábban megtanultad, hogy egy static változó megtartja értékét és nem semmisül meg még a scopeból való kilépés után sem.
	a 'static' kulcsszónak globális változók esetében az a szerep, hogy internal linkage-t ad nekik, ami azt jelenti, hogy
		elérhetetlenné teszi, hogy külső fájlok használják/lássák.

	a C++ bemutatott két újabb felhasználást a 'static' kulcsszónak classokon belül: static tag változók/funkciók.

	lásd a pl.
		amikor létrehozunk egy class objectet, minden object megkapja a saját kicsi másolatát a tag változókból.
		a példában létrehoztunk két objectet a 'Valami' classból, és így két másolatával rendelkezünk az m_ertek-nek
			elso.m_ertek, és masodik.m_ertek. Az elso object m_ertekje és a masodik object m_ertekje eltérő egymástól.
		normál tag változókat statická tehetünk a 'static' kulcsszóval, és ez azt jelenti, hogy az objectek között megosztódik
			ez a tag változó.
				lásd újra példa static tag változóval.
		mivel az s_ertek egy static tag változó ezért az megvan osztva az összes class object között.
			azaz, az elso.s_ertek = a masodik.s_ertek.
			a fenti példa bemutatja, hogy az elso object által megváltoztatott s_ertek a masodik object által is elérhető.

*/


/*

Static members are not associated with class objects,
	habár a static tag változókat elérheted objecten keresztül is, azonban a static tagok akkor is létrejönnek ha egyetlen object
		sincs példázva a classból. Úgyanúgy mint a globális változók, létrejönnek amikor a program elindul, és megsemmisülnek
		amikor véget ér.

	következésképpen, jobb úgy gondolni a static tagokra mint a class részére, sem mint az object részére. Mivel az s_ertek
		önállóan is létezik függetlenül bármilyen class objecttől, közvetlenül is elérhető a scope resolution operátorral(::).

*/


/*

Defining and initializing static member variables,
	amikor meghatározunk egy static változót egy classon belül, azt mondjuk a compilernek, hogy létezik egy static tag változó,
		de tulajdonképpen nem határozzuk meg(csak úgy mint egy forward declaration).
	mivel, a static tag változók nem részei az egyedülálló class objecteknek, kifejezetten megkell őket határoznod a classon kivül,
		a global scopeba.
		lásd a pl.-ba
		az a sor két célt is szolgál:
			előszöris példázza a static tag változót, és opcionálisan még inicializálja is.
				ha nem használunk inicializáló értékét az alapértelmezett lesz ami a 0.
			! a static tag változó meghatározása nem függ a hozzáférési kontrolloktól, meghatározhatod akkor is ha private, vagy
				esetleg protected a classban.
			ha a class megvan határozva egy .h fáljban, a static tag meghatározása a .cpp fájlba kerül ahol a class többi része
				is meghatározódik.

*/


/*

Inline initialization of static member variables,
	van néhány kivétel a fentihez.
		először, ha a static tag egy const integral típus(ide tartozik még a char, bool) vagy egy const enum, a static tag abban a helyben
			inicializálható a class meghatározásban.
		másodszor, bármely típusú static constexpr tag inicializálható a class meghatározásban. 
		

*/