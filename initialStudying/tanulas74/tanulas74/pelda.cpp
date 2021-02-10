#include "stdafx.h"
#include <iostream>

void foo(int *x) // ahol a *x egy mutató az x változóra
{
	*x = 6; // dereference majd megváltoztatja az értékét
}

void kiIrArray(const int *array, int hossz)
{
	if (!array) // ha az array null, akkor korán befejezi.
		return;

	for (int index = 0; index < hossz; ++index)
		std::cout << array[index] << ' ';
}

void null(int *idg)
{
	// átallítsuk, hogy az idg mutató másra muttasson, de nem változtatjuk meg az idg értékét amire mutat.
	idg = nullptr;
}

void null2(int *&idg) // ami így egy hivatkozás az idg mutatóra, azaz ha megváltozik az eredeti is változik
{
	idg = nullptr;
}

int main()
{
	int x = 5;

	std::cout << "Az x erteke = " << x << '\n';
	foo(&x); // használjuk az &(address of) operátort, mivel a címét adjuk tovább
	std::cout << "Az x erteke a tovabbadas utan = " << x << '\n';

	int array[4] = { 90, 22, 65, 72 };
	kiIrArray(array, 4); // nem kell & operátort, mivel az array leépül egy mutatóvá

	kiIrArray(nullptr, 0);

	int *ptr = &x;
	null(ptr);

	if (ptr)
		std::cout << *ptr;
	else
		std::cout << "null";

	null2(ptr); // azaz az idg egy hivatkozás lesz a ptr-re.

	if (ptr)
		std::cout << *ptr;
	else
		std::cout << "null";

	return 0;
}