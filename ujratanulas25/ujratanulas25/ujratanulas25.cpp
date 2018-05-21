#include "stdafx.h"
#include <iostream>

/*

ide tartoznak a lebegőpont(floating point) típusú változók.

	ezek a változók képesek valós számok tárolására, olyan mint 3.14, vagy -3.33, 4320.0
	
		skálája változó, float lehet 4 byte, double 8 byte, a long double 16 byte.

*/


float fErtek;
double dErtek;
long double ldErtek;

int x(5); // 5 mint egész szám
double y(5.0); // 5.0 egy floating point szám ( nincs suffix-ja, útótagja, így alapból double típusú)
float z(5.0f); // 5.0 egy floating point szám ( f útótag azt jelenti, hogy lebegő(float) típusú.


/*

floating point típus képes tudományos jelöléssel ellátott számokat tárolni

*/

double d1(5000.0);
double d1(5e3);

double d3(0.05);
double d3(5e-2);

/*

szabály:		inkább használj doublet, mert float pontatlanabb

	másik gond: a kerekítés, 

*/

#include <iostream>
#include <iomanip> // for std::setprecision()

int main()
{
	std::cout << std::setprecision(17);

	double d1(1.0);
	std::cout << d1 << std::endl;

	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1); // should equal 1.0
	std::cout << d2 << std::endl;
}

// 1
// 0.99999999999999989

/*

konkluzió: 
		a floating point számok megfelelőek nagyon nagy számok, vagy nagyon kicsi számok tárolására
			beletartozva a tizedes számokat, addig amíg meghatározott számú szignifikáns számjegyei vannak(pontosság miatt)

		a floating point számoknak gyakran van kicsi kerekítési hibái, ezért az összehasonlítások nem mindig a várt eredményt mutatják
			ha matematikai műveleteket végzel, a kerekítési hiba nőni fog.

*/


/*

QUIZ:

	34.50 = 3.450e1   4
	0.004000 = 4.000e-3 7
	123.005 = 1.23005e2 6
	146000 = 1.46e5 3
	146000.001 = 1.46000001e5 9
	0.0000000008 = 8e-10 1
	34500.0 = 3.45000e4 6


*/