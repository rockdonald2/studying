#include "pch.h"
#include <iostream>

//

#include <string>
#include <fstream>
#include <cstdlib>

/*int main()
{
	using namespace std;

	ofstream outf("Sample.dat");

	if (!outf)
	{
		cerr << "File could not be opened for writing" << endl;
		exit(-1);
	}

	outf << "This is line 1" << endl;
	outf << "This is line 2" << endl;
	outf << "This is line 3" << endl;

	outf.seekp(0, ios::end);
	cout << outf.tellp() << '\n';
}*/

int main()
{
	using namespace std;

	fstream iofile("Sample.dat", ios::in | ios::out);

	if (!iofile)
	{
		cerr << "Sample.dat could not be opened!" << endl;
		exit(-1);
	}

	char chChar; // karakterről karakterre vizsgáljuk a fájlt

	while (iofile.get(chChar))
	{
		switch (chChar)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			
			// lépjen vissza egy karaktert
			iofile.seekg(-1, ios::cur);

			// mivel volt seek nyugodtan írhatunk, a betű helyére #-t írunk
			iofile << '#';

			// ezután visszamennénk read módba
			// de nem akarjuk mozgatni a file pointert
			iofile.seekg(iofile.tellg(), ios::beg); // szóval ezt használjuk

			break;
		}
	}

	return 0;
}