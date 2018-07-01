#include "stdafx.h"
#include <iostream>

class EgyediID
{
private:
	static int s_generaltID;
	int ID;

public:
	void generalID() { ID = s_generaltID++; }
	int lekerID() { return ID; }
};

int EgyediID::s_generaltID = 1;

int main()
{
	EgyediID elso;
	EgyediID masodik;
	EgyediID harmadik;

	elso.generalID();
	masodik.generalID();
	harmadik.generalID();

	std::cout << elso.lekerID() << "/" << masodik.lekerID() << "/" << harmadik.lekerID() << "/" << elso.lekerID() << '\n';

	EgyediID negyedik;
	negyedik.generalID();
	std::cout << negyedik.lekerID() << '\n';

	return 0;
}