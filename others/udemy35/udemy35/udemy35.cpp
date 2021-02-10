#include "pch.h"
#include <iostream>

//

#include <algorithm> // std::max
#include <cmath> // std::pow
#include <iomanip> // std::setprecision

using namespace std;
int main()
{
	// inicializ�ljuk az a, b �s maximum �rt�keket
	int a{ 5 }, b{ 7 }, maximum{ 0 };

	// meghat�rozzuk a max t�nyleges �rt�k�t az std::max f�ggv�nnyel
	maximum = max(a, b);

	swap(a, b); // megcser�lj�k a k�t �rt�ket

	// !! a = 7;
	double cubic;
	cubic = pow((double)(a), 1.0 / 3);

	cout << cubic << endl;
	cout << setprecision(10) << cubic << endl;
	cout << setprecision(3) << cubic << endl;

	return 0;
}