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
	mi a k�l�nbs�g a void pointer �s a null pointer k�z�tt?
		void pointer, egy olyan mutat� amely b�rmely adatt�pusra mutathat,
		a null pointer, egy olyan mutat� amely semmire sem mutat.


*/