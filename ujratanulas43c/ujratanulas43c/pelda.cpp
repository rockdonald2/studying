#include "stdafx.h"
#include <iostream>
#include "sajatMuveletek.h" // a muveletek namespacehez
#include <string>

double lekerSzam()
{
	std::cout << "Irj be egy szamot: ";
	double szam;
	std::cin >> szam;

	return szam;
}

char kivalasztMuvelet()
{
	std::cout << "Valasz ki egy muveletet az alabbiak kozul: osszeadas(1), kivonas(2), szorzas(3), osztas(4), hatvanyozas(5), gyokvonas(6)";
	char muvelet;
	std::cin >> muvelet;

	return muvelet;

}


int main()
{
	using namespace sajatMuveletek;

	double szam1 = lekerSzam();
	double szam2 = lekerSzam();

	int muvelet = kivalasztMuvelet();

	using std::cout;
	if (muvelet == '1')
		 cout << osszeadas(szam1, szam2);
	if (muvelet == '2')
		 cout << kivonas(szam1, szam2);
	if (muvelet == '3')
		 cout << szorzas(szam1, szam2);
	if (muvelet == '4')
		 cout << osztas(szam1, szam2);
	if (muvelet == '5')
		cout << "Error 404! Nem talalhato!";
	if (muvelet == '6')
		cout << "Error 404! Nem talalhato!";
		

	cout << "\n";

	return 0;



}