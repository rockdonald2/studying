#ifndef DATUM_H
#define DATUM_H

class Datum
{
private:
	int m_ev;
	int m_honap;
	int m_nap;

public:
	Datum(int ev, int honap, int nap);

	void allitDatum(int ev, int honap, int nap);

	int lekerEv() { return m_ev; }
	int lekerHonap() { return m_honap; }
	int lekerNap() { return m_nap; }
};

#endif