#include "stdafx.h"
#include <iostream>

void foo(int &x)
{
	x = x + 1;
}

void goo(int *&ptr) // mutatót továbbadni hivatkozás által
{
	ptr = nullptr; // megváltoztatja a tényleges mutatót egy null mutatóvá
}

void kiIrElemek(int(&array)[4]) // kifejezetten megkell határoznunk az array hosszát amikor továbbadjuk mint hivatkozás
{
	int hossz = sizeof(array) / sizeof(array[0]); // ezt megtudjuk tenni, mivel ismerjük az array információit
		// ergó, tudjuk milyen hosszú, nem épült le mutatóvá mintha csak érték szerint adtuk volna tovább

	for (int index = 0; index < hossz; ++index)
		std::cout << array[index] << '\n';
}

int main()
{
	int x = 5;

	std::cout << "Az x jelenlegi erteke = " << x << '\n';

	foo(x);

	std::cout << "Az x a funkcioban valo hivatkozas utan = " << x << '\n';

	int *ptr = &x;

	std::cout << "A mutato: " << (ptr ? "nem-null" : "null") << '\n'; // először mivel az x = 5, ezért nem-null
	goo(ptr); // továbbadjuk a ptr mutatót ami az x-re mutat, majd megváltozatja a mutató címét null-ra
	std::cout << "A mutato a tovabbadas utan: " << (ptr ? "nem-null" : "null") << '\n'; // mivel most a ptr nullptr, ezért null

	int array[] = { 110, 30, 22, 11 };
	kiIrElemek(array);



	return 0;
}