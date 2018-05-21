#include "stdafx.h"
#include <iostream>

/*

using statements,
	ez egy egyszerűsítő fogalom
		pl. using namespace std; segítségével nem kell folyamatosan cout, illetve cin elé kiírni a namespace-t is.
			vagy
			using std::cout; ez esetben a cout lesz preferálva az std namespaceből akármikor megjelenne a cout szó a kódban.

	ha a using állítást egy blokkba használjuk akkor az csak a blokkon belül lesz érvényes(normál scope szabályokkal).
		soha ne rakd a using állításokat a global namespace-be(a funkciókon kivül) mivel így drasztikusan megnő a naming conflict veszélye.

		a teljes directivere vonatkozó using állításokat(pl. using namespace std;) lehetőleg teljesen felejtsd el(using directives típus), 
		de a másik fajta szabadon használható(using std::cout;).

		fontos dolog, hogy semmilyen módon nem lehet lecserélni, vagy véget vetni egy ilyen állításnak, kivéve ha kisebb blokkba szorítjuk.

*/