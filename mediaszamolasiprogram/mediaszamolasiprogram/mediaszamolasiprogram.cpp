#include "stdafx.h"
#include <iostream>

// akarok írni egy programot ami lekér jegyeket ( max 15öt ) és átlagot számol belőlük.

int szamokLekerese()
{
	double ossz = 0;
	for (int szamlalo = 0; szamlalo < 15; ++szamlalo)
	{
		std::cout << "Ird be a jegyeidet: " << "( vagy 0at ahhoz, hogy befejezd es atlagot vonj ) ";
		double szam;
		std::cin >> szam;

			// ha 0 ír:

			if (szam == 0)
				break;

			ossz += szam;
				
			
	}

	std::cout << "A szamok osszege: " << ossz << '\n';

	return ossz;
}

int hanySzamArany()
{
	std::cout << "Ird be hany szambol akarsz aranyt vonni: ";
	int hsa;
	std::cin >> hsa;

	return hsa;
}

int main()
{
	int hsa;
	hsa = hanySzamArany();
	double ossz;
	ossz = szamokLekerese();
		
	std::cout << "Ha beirtad minden jegyedet, azok atlaga: " << ossz / hsa << '\n';

	return 0;
}