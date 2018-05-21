#include "stdafx.h"
#include <iostream>

// csinálj egy programot, ami lekéri a felhasználó bruttó fizetését, valamit az adott ország adókulcsát, és kiszámolja kézbe kapható nettó összeget.
	// pluszpont: írja ki felosztva mindhármat  pipa
	// pluszpont 2: írja ki a reálbért, az átlagár lekérése után.  pipa
	// pluszpont 3: készítsd fel a program rossz inputok fogadására, és kezelésére.


double lekerFizetes()
{
	std::cout << "Ird be az ehavi brutto fizeteseted: ";
	double bruttFizetes;
	std::cin >> bruttFizetes;

	return bruttFizetes;
}

double lekerAdoKulcs()
{
	std::cout << "Ird be az orszagodban fizetesekre ervenyes adokulcsot: ";
	double adoKulcs;
	std::cin >> adoKulcs;

	return adoKulcs;
}

double kiszamolNettoFizetes(double bruttFizetes, double adoKulcs)
{
	std::cout << "A kezbe kapott osszeged a kovetkezo kell legyen: ";

	double nettoFizetes = (bruttFizetes - (bruttFizetes * (adoKulcs / 100)));

	std::cout << nettoFizetes << "\n";

	return nettoFizetes;
}

double lekerAtlagAr()
{
	std::cout << "Ird be az orszagod atlagarat: ";
	double atlagAr;
	std::cin >> atlagAr;

	return atlagAr;
}

double kiszamolRealBer(double nettoFizetes, double atlagAr)
{
	double realBer = (nettoFizetes / atlagAr);
	
	std::cout << "A fizetesed realber erteke: " << realBer <<"\n";

	return realBer;
}

int main()
{
	double fizetes = lekerFizetes();
	double adoKulcs = lekerAdoKulcs();

	double nettoFizetes = kiszamolNettoFizetes(fizetes, adoKulcs); // hogy később is használható legyen.
	double atlagAr = lekerAtlagAr();

	double realBer = kiszamolRealBer(nettoFizetes, atlagAr); // hogy később is használható legyen.

	std::cout << "Irj be egy \"e\" betut, hogy lasd felosztva: ";
	char karakter;
	std::cin >> karakter;

	std::cout << "\n";



		if (karakter == 'e')
		{
			using std::cout;

			double bruttoFizetes = fizetes;
			double fizetesAdoKulcs = adoKulcs;
			double nettoBer = nettoFizetes;
			double orszagAtlagAr = atlagAr;
			double fizetesVasarloEro = realBer;

			cout << bruttoFizetes << "\t" << "Brutto fizetesed" << "\n"
				<< fizetesAdoKulcs << "\t" << "Fizetesed adokulcsa" << "\n"
				<< nettoBer << "\t" << "Kezbe kapott bered" << "\n"
				<< orszagAtlagAr << "\t" << "Orszagod atlag ara" << "\n"
				<< fizetesVasarloEro << "\t" << "Fizetesed vasarlo ereje" << "\n";

			cout << "\n";

		}

		else
		{
			std::cout << "Rossz karaktert irtal be, program leall.\n";
			return 0;
		}


	std::cout << "Irj be egy \"q\"-t, hogy kilepj! ";
	char kilepoKarakter;
	std::cin >> kilepoKarakter;

	if (kilepoKarakter == 'q')
		return 0;
	else
		return 0;

}