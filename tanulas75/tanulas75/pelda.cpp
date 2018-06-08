#include "stdafx.h"
#include <iostream>

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	int x = 5;
	int y = 2;

	std::cout << min(x, y) << '\n';
	/*
	Lényegében, mielőtt megtörténne a funkció lehívás a compiler észreveszi, hogy ez a funkció egy 'inline' funkció,
		és az egész funkció tartalmát átmásolja ide
			mintha ezt írtam volna: 5 > 2 ? 2 : 5;
	*/

	return 0;
}