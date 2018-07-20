#include "stdafx.h"
#include <iostream>

/*

Operator overloading,
	a C++-ban az operátorok funkciókként vannak beépítve.
	a funkció overloadolást használva az operátor funkciókon, meghatározhatod a saját verzióidat az operátorokból, hogy azzal
	dolgozz a különböző adattípusokkal.
		operátor overloadnak hívjuk azt a folyamatot amikor funkció overloadolást használsz, hogy operátorokat overloadolj.

*/


/*

Operators as functions,
	az első két példában operátor overloadolást láthatunk, mivel létezik egy operátor+ int operándusokhoz, és double operándusokhoz.
	az utolsó példában pedig mivel egy felhasználó által meghatározott adattípusról, classról, van szó, így az operátor+-nak nincs
	megfelelő verziója, meghatározása, hogy ezt a fajta adattípust kezelje.

*/

void funkcio()
{
	int x = 2;
	int y = 3;
	std::cout << x + y << '\n';
}

void funkcio2()
{
	double w = 2.0;
	double z = 3.0;
	std::cout << w + z << '\n';
}

#include <string>
class String
{
public:
	std::string m_string;

	String(std::string string) : m_string(string)
	{}
};

void funkcio3()
{
	String string1 = static_cast<std::string>("Hello,");
	String string2 = static_cast<std::string>("World.\n");
	//std::cout << string1 + string2; // error
}


/*

Resolving overloaded operators,
	amikor kiértékelődik egy kifejezés ami tartalmaz egy operátort, a compiler a következő szabályokat használja:
		- ha minden operándus alapvető adattípusból származik, a compiler megkeresi és lehívja a megfelelő beépített verziót, ha létezik.
			ha nem létezik, compiler errort dob.
		- ha bármely tagja az operándusoknak felhasználó által meghatározott adattípusból származik, a compiler megpróbál keresni
			egy megfelelő overloaded operátort amit lehívhat, ha nem talál egyet, megpróbálja átalakítani egy vagy több operándust
			alapvető adattípusba, hogy használhassa a megfelelő beépített operátort(overloaded typecast). Ha ez se sikerül, error.

*/


/*

What are the limitations on operator overloading?
	! majdnem minden operátor overloadolható a C++-ban, kivétel a kondició(?:), sizeof, scope(::), member selector(.),
		member pointer selector(.*)
	csak olyan operátorokat tudsz overloadolni amik már léteznek, nem hozhatsz létre újakat, vagy nevezhetsz át meglévőket.
	legalább egy operándus minden overloadolt operátorban felhasználó által meghatározott típusból kell legyen.
	nem lehetséges megváltoztatni az operándusok számát amit az operátor támogat.
	minden operátor megtartja a saját asszociativitási és precedenciai szabályait, és ezt nem lehet megváltoztani.
		
*/