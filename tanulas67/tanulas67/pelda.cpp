#include "stdafx.h"
#include <iostream>

int main()
{
	int x = 5;
	std::cout << x << '\n';
	std::cout << &x << '\n'; // address-of
	std::cout << *&x << '\n'; // dereference

	int ertek = 5;
	int *mutato = &ertek; // iniciaizálunk egy mutato nevü mutatót az ertek memória címével.
	std::cout << mutato << '\n'; // a memória cím amire mutat
	std::cout << *mutato << '\n'; // a memória cím értéke amire mutat

	int ertek1 = 5;
	int ertek2 = 7;

	int *ptr;

	ptr = &ertek1;
	std::cout << *ptr << '\n'; // = 5;

	ptr = &ertek2;
	std::cout << *ptr << '\n'; // = 7;

	int ertek3 = 10;
	int *ptr2 = &ertek3;

	*ptr2 = 12;
	std::cout << ertek3 << '\n';

	return 0;
}