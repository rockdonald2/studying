#include "stdafx.h"
#include <iostream>
#include "Datum.h"

Datum::Datum(int ev, int honap, int nap)
{
	allitDatum(ev, honap, nap);
}

void Datum::allitDatum(int ev, int honap, int nap)
{
	m_ev = ev;
	m_honap = honap;
	m_nap = nap;
}