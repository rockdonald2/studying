#include "stdafx.h"
#include <iostream>

/*class Datum
{
private:
	int m_ev;
	int m_honap;
	int m_nap;

public:
	Datum(int ev, int honap, int nap)
	{
		allitDatum(ev, honap, nap);
	}

	void allitDatum(int ev, int honap, int nap)
	{
		m_ev = ev;
		m_honap = honap;
		m_nap = nap;
	}

	int lekerEv() { return m_ev; }
	int lekerHonap() { return m_honap; }
	int lekerNap() { return m_nap; }
};

int main()
{
	Datum ma(2018, 6, 30);
	std::cout << ma.lekerEv() << "/" << ma.lekerHonap() << "/" << ma.lekerNap() << "\n";

	return 0;
}*/


/*class Datum
{
private:
	int m_ev;
	int m_honap;
	int m_nap;

public:
	// csak forward declaration
	Datum(int ev, int honap, int nap);

	// csak forward declaration
	void allitDatum(int ev, int honap, int nap);

	int lekerEv() { return m_ev; }
	int lekerHonap() { return m_honap; }
	int lekerNap() { return m_nap; }
};


// konstruktőr 
Datum::Datum(int ev, int honap, int nap)
{
	allitDatum(ev, honap, nap);
}

// tag funkció
void Datum::allitDatum(int ev, int honap, int nap)
{
	m_ev = ev;
	m_honap = honap;
	m_nap = nap;
}

int main()
{
	Datum ma(2018, 6, 30);
	std::cout << ma.lekerEv() << "/" << ma.lekerHonap() << "/" << ma.lekerNap() << "\n";

	return 0;
}*/


class Szamologep
{
private:
	int m_ertek;

public:
	Szamologep(int ertek);

	Szamologep& osszead(int ertek);
	Szamologep& kivon(int ertek);
	Szamologep& szoroz(int ertek);

	int lekerErtek() { return m_ertek; }
};

Szamologep::Szamologep(int ertek) : m_ertek(ertek)
{}

Szamologep& Szamologep::osszead(int ertek)
{
	m_ertek += ertek;
	return *this;
}

Szamologep& Szamologep::kivon(int ertek)
{
	m_ertek -= ertek;
	return *this;
}

Szamologep& Szamologep::szoroz(int ertek)
{
	m_ertek *= ertek;
	return *this;
}

int main()
{
	Szamologep kiszamol(5);
	kiszamol.kivon(3).szoroz(2);
	std::cout << kiszamol.lekerErtek() << '\n';

	return 0;
}