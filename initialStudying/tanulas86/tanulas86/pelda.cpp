#include "stdafx.h"
#include <iostream>

#include <string>

class Felhasznalo
{
private:
	int m_id;
	std::string m_nev;

public:
	Felhasznalo(int id = 0, const std::string &nev = "") : m_id(id), m_nev(nev)
	{
		std::cout << "Felhasznalo: " << m_nev << ", id: " << m_id << "\n";
	}

	Felhasznalo(const std::string &nev="") : Felhasznalo(0, nev)
	{}
};

int main()
{
	Felhasznalo zsolt{ "zsolt" };

	return 0;
}