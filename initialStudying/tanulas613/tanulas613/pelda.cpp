#include "stdafx.h"
#include <iostream>



void pelda1()
{
	int x = 5;
	void *ptr = &x;

	int *intPtr = static_cast<int*>(ptr);

	std::cout << *intPtr << '\n';
}

int main()
{
	pelda1();

	return 0;
}

/*
QUIZ,
	mi a különbség a void pointer és a null pointer között?
		void pointer, egy olyan mutató amely bármely adattípusra mutathat,
		a null pointer, egy olyan mutató amely semmire sem mutat.


*/