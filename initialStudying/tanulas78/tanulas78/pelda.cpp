#include "stdafx.h"
#include <iostream>

/*
int goo()
{
	return 7;
}

int hoo()
{
	return 9;
}

int joo(int x)
{
	return x;
}

int main()
{
	int(*fcnPtr)(); // funkció mutató

	fcnPtr = goo; // most a 'goo' funkcióra mutat
	fcnPtr = hoo; // most már a 'hoo' funkcióra mutat

	/*
	! gyakori hiba, hogy a funkció után odaírjuk a ()-et is, ha oda írjuk akkor a return value-val inicializáljuk, ha nem akkor
		a memória címével.
	*/
/*
	int(*fcnPtr2)(int) = joo; // hozzárendelem a funkció mutatót a 'joo' funkcióhoz
	(*fcnPtr2)(5); // lehívom a joo(5) funkciót a mutatón keresztül. ( kifejezett )
	fcnPtr2(5); // lehívom a joo(5) funkciót a mutatón keresztül ( magától értetődö )

	return 0;
}*/

/*
#include <utility>
#include <functional>



bool novekvo(int x, int y)
{
	return x > y; // csere ha az első elem nagyobb mint a második
}

bool csokkeno(int x, int y)
{
	return x < y; // csere ha az első elem kisebb mint a második
}

// használunk egy funkció mutatót amely felhasznál két integert és visszaad egy bool értéket.
// alapértelmezett érték(ha nem funkció mutatón keresztül hívja le) a növekvő sorrend
void selectionRendezes(int *array, int hossz, std::function<bool(int, int)>osszehasonlitasMenete = novekvo)
{
	for (int startIndex = 0; startIndex < hossz; ++startIndex)
	{
		int legjobbIndex = startIndex;

		for (int jelenlegiIndex = startIndex + 1; jelenlegiIndex < hossz; ++jelenlegiIndex)
		{
			// itt jön képbe a funkció mutató
			if (osszehasonlitasMenete(array[legjobbIndex], array[jelenlegiIndex]))
				legjobbIndex = jelenlegiIndex;
		}

		std::swap(array[startIndex], array[legjobbIndex]);
	}

}

void kiirArray(int *array, int hossz)
{
	for (int index = 0; index < hossz; ++index)
		std::cout << array[index] << ' ';
}

int main()
{
	int array[] = { 3, 1, 2, 7, 8, 4, 5, 9, 6 };
	int hossz = sizeof(array) / sizeof(array[0]);

	// rendezzük az arrayt növekvő sorrendbe a 'novekvo' funkciót használva
	selectionRendezes(array, hossz, novekvo);
	kiirArray(array, hossz);

	std::cout << '\n';

	// rendezzük az arrayt csökkenő sorrendbe a 'csokkeno' funkciót használva
	selectionRendezes(array, hossz, csokkeno);
	kiirArray(array, hossz);

	return 0;
}*/


// quiz

/*
készíts egy rövid programot amelyben kéred a felhasználót, hogy írjon be két integer inputot, majd egy matematikai müveletet.
	biztosítsd, hogy az input helyes!
*/

// lekéri a számot.
int lekerSzam()
{
	while (true)
	{
		std::cout << "Irj be egy szamot: ";
		int szam;
		std::cin >> szam;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Helytelen input!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');

			return szam;
		}
	}
}

// lekéri a müveletet
char lekerMuvelet()
{
	while (true)
	{
		std::cout << "Irj be egy matematikai muveletet a kovetkezokbol +, -, *, / : ";
		char mu;
		std::cin >> mu;

		std::cin.ignore(32767, '\n');

		if (mu == '+' || mu == '-' || mu == '*' || mu == '/')
			return mu;
		else
			std::cout << "Helytelen input!\n";
	}
}

/*
írj funkciókat amely összeadást, kivonást, szorzást, és osztást végeznek. Két paramétert kéne használjanak, 
és egy integert visszaadni.
*/

int osszead(int x, int y)
{
	return x + y;
}

int kivon(int x, int y)
{
	return x - y;
}

int szoroz(int x, int y)
{
	return x * y;
}

int oszt(int x, int y)
{
	return x / y;
}


/*
készíts egy typedef-t egy funkció mutatóhoz amely használ két int paramétert és visszaad egy integert.
*/

typedef int (*szamtaniFunkcio)(int, int);

/*
írj egy funkciót amely fogja a müvelet változást és visszaadja a megfelelő funkciót mutatóként
*/

#include <functional>

szamtaniFunkcio lekerSzamtaniFunkcio(char mu)
{
	switch (mu)
	{
	default:
	case '+': return osszead;
	case '-': return kivon;
	case '*': return szoroz;
	case '/': return oszt;
	}
}

std::function<int(int, int)>szamtaniFunkcio1(char mu)
{
	switch (mu)
	{
	default:
	case '+': return osszead;
	case '-': return kivon;
	case '*': return szoroz;
	case '/': return oszt;
	}
}

/*
modosítsd a main() funkciót, hogy lehívja a lekerSzamtaniFunkcio-t. Hívd le a return értékkel a többi inputot 
és írd ki az eredményt.
*/

int main()
{
	int szam1 = lekerSzam();
	char mu = lekerMuvelet();
	int szam2 = lekerSzam();

	szamtaniFunkcio fcn = lekerSzamtaniFunkcio(mu);
	std::cout << szam1 << ' ' << mu << ' ' << szam2 << ' '  << '=' << ' ' << szamtaniFunkcio1(mu)(szam1, szam2) << '\n';
	std::cout << szam1 << ' ' << mu << ' ' << szam2 << ' ' << '=' << ' ' << fcn(szam1, szam2) << '\n';


	return 0;
}