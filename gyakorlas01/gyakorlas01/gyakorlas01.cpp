#include "stdafx.h"
#include <iostream>

/*0000000000*/

// faktoriális függvény
using namespace std;
int factorial(int value)
{
	if (value == 1)
		return 1;
	else
		return value * factorial(value - 1);
}

// egy olyan függvény amely befogad egy számot paraméterként és visszaadja a szám összes számjegyének összegét
int sumDigit(int value)
{
	if (value < 10)
		return value;
	else
		return (value % 10) + sumDigit(value / 10);
}

int main(int argc, char* argv[])
{
	cout << factorial(3) << '\n';
	cout << sumDigit(357) << '\n';

	return 0;
}
