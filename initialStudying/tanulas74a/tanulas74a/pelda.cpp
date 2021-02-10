#include "stdafx.h"
#include <iostream>

/*int ertekDupla(int x)
{
	x = x * 2;
	return x; // érték szerinti visszaadás
}

int* elosztArray(int meret)
{
	return new int[meret]; // cím szerinti visszaadás
}

#include <array>

int& lekerElem(std::array<int, 25> &array, int index)
{
	return array[index]; // hivatkozás szerinti visszaadás
}

int main()
{
	int x = 5;
	std::cout << ertekDupla(x);

	int *array = elosztArray(25);

	// ..

	delete[] array;

	std::array<int, 25> array1 = { 0 };
	lekerElem(array1, 1) = 5;

	return 0;
}*/

//

/*int returnByValue()
{
	return 5;
}

int& returnByReference()
{
	static int x = 5; // a static bebiztosítja, hogy nem lesz megsemmisülve a funkció végén.
	return x;
}

int main()
{
	int value = returnByReference(); // A
	int &ref = returnByValue(); // B
	const int &cref = returnByValue(); // C

	/*
	A) esetben hozzárendelünk egy hivatkozás return-t egy nem-hivatkozás változóhoz.
		Mivel 'value' nem egy hivatkozás, ezért a return érték belemásolódik a 'value'-ba, pont mintha sima return by Value lenne.
	*/

	/*
	B) esetben nem fog mükődni, mivel az érték amit visszaad a 'returnByValue()' egy r-érték, azaz nincs címe, így
		nem rendelhető hozzá egy hivatkozáshoz.
	*/

	/*
	C) esetben mükődni fog, a konstans hivatkozáshoz hozzá fog rendelődni az érték amit a 'returnByValue()' visszaad.
		konstans hivatkozás képes r-értéket tárolni, mert a konstans hivatkozás által miután hozzárendelődik az érték
			a hivatkozáshoz, kibővíti az élettartamát, hogy megegyezzen a hivatkozással.
	

}*/

//

/*struct S
{
	int m_x;
	short m_y;
};

S returnStruct()
{
	S s;
	s.m_x = 5;
	s.m_y = 2;
	return s;
}

int main()
{
	S s = returnStruct();

	std::cout << s.m_x << ' ' << s.m_y << '\n';

	return 0;
}*/

//

/*#include <tuple>

std::tuple<int, double> returnStruct() // visszaad egy tuple-t ami tartalmaz egy int-et és egy double-t
{ 
	return std::make_tuple(5, 6.7); // használjuk az std::make_tuple() funkciót mint egy rövidítés ahhoz, hogy létrehozzunk
									// egy tuple-t amit visszaadunk.
}

int main()
{
	std::tuple<int, double> s = returnStruct(); // lekérjük a tuple-t
	std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << '\n';
		// használjuk az std::get<n>(m) funkciót ahhoz, hogy lekérjük az 'm' tupleból az n-ik elemet.

	return 0;
}*/
