#include "stdafx.h"
#include <iostream>

// Quiz

/*

Hozz létre egy struct-ot, hogy tároljon egy osztást.
	struct-nak tartalmaznia kell egy integer számlálót és egy integer nevezőt tagokként.
		hozz létre két osztási változót, és olvass be értékeket a felhasználotól hozzájuk.

		hozz létre egy funkciót multiply névvel, amely fogja mindkét töredéket, összeszoroza őket, és kiírja a számot decimálisan.

*/

struct Osztas
{
	double szamlalo;
	double nevezo;
};

void ketOsztasSzorzata(Osztas osztas1, Osztas osztas2)
{
	std::cout << "Ket osztasnak a szorzata = " << static_cast<float>(osztas1.szamlalo * osztas2.szamlalo) / (osztas1.nevezo * osztas2.nevezo) << "\n";
}

int main()
{
	Osztas osztas1;
	Osztas osztas2;


	int x;
	std::cout << "Ird be az elso osztasodnak a szamlalojat: ";
	std::cin >> x;
	osztas1.szamlalo = x;
	int y;
	std::cout << "Ird be az elso osztasodnak a nevezojet: ";
	std::cin >> y;
	osztas1.nevezo = y;


	int a;
	std::cout << "Ird be a masodik osztasodnak a szamlalojat: ";
	std::cin >> a;
	osztas2.szamlalo = a;
	int b;
	std::cout << "Ird be a masodik osztasodnak a nevezojet: ";
	std::cin >> b;
	osztas2.nevezo = b;

	ketOsztasSzorzata(osztas1, osztas2);

	return 0;

}