#include "pch.h"
#include <iostream>

// 

#include <fstream>
#include <cstdlib> // exit()
#include <string>

int main()
{
	using namespace std;

	// az ofstream fájlokra való írásra használjuk
	// csinálunk egy sample.dat fájlt
	ofstream outf("Sample.dat");

	// ha nem tudtuk megnyitni az output fájl streamet írásra
	if (!outf)
	{
		// kiír egy error üzenetet és kilép
		cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
		exit(-1);
	}

	// beírjuk ezt a két sort a fájlba
	outf << "This is line 1" << endl;
	outf << "This is line 2" << endl;

	outf.close(); // bezárjuk a fájlt

	// az ifstream-t használjuk fájlok beolvasására
	// beolvassuk a sample.dat fájl
	ifstream inf("Sample.dat");

	// ha nem tudtuk megnyitni az output file stream-t olvasásra
	if (!inf)
	{
		// error üzenet, és kilép
		cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
		exit(-1);
	}

	// ameddig van mit beolvasni
	while (inf)
	{
		std::string strInput;
		// inf >> strInput; // ha ezt használjuk kimaradnak a whitespacek és minden szó külön sorba kerül
		getline(inf, strInput); // ha ezt használjuk megmaradnak a whitespacek, minden sor 1 sor
		cout << strInput << endl;
	}

	// megnyitjuk újra a fájlt, összefüzés módban
	outf.open("Sample.dat", ios::app);

	// ha nem tudtuk megnyitni az output fájl streamet írásra
	if (!outf)
	{
		// kiír egy error üzenetet és kilép
		cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
		exit(-1);
	}

	outf << "This is line 3" << endl;
	outf << "This is line 4" << endl;

	return 0;

	// amikor az outf kimegy scopeból, az ofstream destruktőr bezárja a fájlt
	// inf-el ugyanez a helyzet
}