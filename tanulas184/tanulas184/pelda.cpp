#include "pch.h"
#include <iostream>
#include <sstream> // stringstream

int main()
{
	using namespace std;

	// egyik mód, hogy adatot helyezz a stringstreambe
	stringstream os;
	os << "en garde!" << endl; // belehelyezzük az os stringstreambe az "en garde!" stringet 

	// második mód, hogy adatot helyezz a stringstreambe
	stringstream os1;
	os1.str("en garde!");

	// egyik mód, hogy adatot szerezz a stringstreamből
	cout << os.str();

	// másik mód
	string strValue1;
	string strValue2;
	os1 >> strValue1;
	os1 >> strValue2;
	cout << strValue1 << " " << strValue2 << '\n';

		// az str() funkció a teljes stringet visszaadja a streamből
		// >> végig iterálja a stringet, minden következő >> visszaadja a következő kivehető értéket a streamből


	stringstream os3;
	int nValue = 12345;
	double dValue = 67.89;
	os3 << nValue << " " << dValue;

	string strValue3, strValue4;
	os3 >> strValue3 >> strValue4;

	cout << strValue3 << " " << strValue4 << endl;

	stringstream os4;
	os4 << "12345 67.89";
	int nValue1;
	double dValue1;

	os4 >> nValue1 >> dValue1;

	cout << nValue1 << " " << dValue1;

	os.str(""); // üresíti a buffert
	os1.str(string()); // üresíti a buffert
	os.clear(); // reseteli az error flageket

	return 0;
}
