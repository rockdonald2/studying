#include "stdafx.h"
#include <iostream>

struct Szemely
{
	int kor;
	double suly;
};

void funkcio()
{
	Szemely szemely;
	szemely.kor = 5; // member selection

	Szemely &hiv = szemely;
	hiv.kor = 5; // hivatkozás általi member selection

	Szemely *mut = &szemely;
	(*mut).kor = 5; // mutató általi member selection, fontos először dereferencelni kell
	mut->kor = 5; // a két sor ugyanazt jelenti, ez a second member selection
}