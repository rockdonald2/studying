#include "stdafx.h"
#include <iostream>

void foo(int *x) // ahol a *x egy mutat� az x v�ltoz�ra
{
	*x = 6; // dereference majd megv�ltoztatja az �rt�k�t
}

void kiIrArray(const int *array, int hossz)
{
	if (!array) // ha az array null, akkor kor�n befejezi.
		return;

	for (int index = 0; index < hossz; ++index)
		std::cout << array[index] << ' ';
}

void null(int *idg)
{
	// �tall�tsuk, hogy az idg mutat� m�sra muttasson, de nem v�ltoztatjuk meg az idg �rt�k�t amire mutat.
	idg = nullptr;
}

void null2(int *&idg) // ami �gy egy hivatkoz�s az idg mutat�ra, azaz ha megv�ltozik az eredeti is v�ltozik
{
	idg = nullptr;
}

int main()
{
	int x = 5;

	std::cout << "Az x erteke = " << x << '\n';
	foo(&x); // haszn�ljuk az &(address of) oper�tort, mivel a c�m�t adjuk tov�bb
	std::cout << "Az x erteke a tovabbadas utan = " << x << '\n';

	int array[4] = { 90, 22, 65, 72 };
	kiIrArray(array, 4); // nem kell & oper�tort, mivel az array le�p�l egy mutat�v�

	kiIrArray(nullptr, 0);

	int *ptr = &x;
	null(ptr);

	if (ptr)
		std::cout << *ptr;
	else
		std::cout << "null";

	null2(ptr); // azaz az idg egy hivatkoz�s lesz a ptr-re.

	if (ptr)
		std::cout << *ptr;
	else
		std::cout << "null";

	return 0;
}