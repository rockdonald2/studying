#include "stdafx.h"
#include <iostream>

/*int main()
{
	std::cout << 2 + 3; // 2 + 3 kiértékelődik 5-re, és az értékek a kiértékelés után törlődnek

	// de ha

	const int &hiv = 2 + 3; // mivel most az eredmény hozzá van kötve egy konstans hivatkozáshoz, az r-érték élettartama kibővül

	std::cout << hiv; // ezért itt is használható

	return 0;
} // és egészen idáig tart*/

void irdKi(const int &x)
{
	std::cout << x;
}

int main()
{
	int a = 1;
	irdKi(a); // non-konstans l-érték

	const int b = 2; 
	irdKi(b); // konstans l-érték

	irdKi(3); // betü r-érték

	irdKi(2 + b); // kifejezés értéke szerinti r-érték

	return 0;
}