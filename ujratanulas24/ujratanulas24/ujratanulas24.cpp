#include "stdafx.h"
#include <iostream>



/*

ide tartoznak az egész számok, az integer type variable, ami csak egész számokat tudnak tárolni.

5 típusú integer type van: char(character), int (integer), short, long, long long
			a különbség abban lelhető, hogy különböző bit méretet foglalnak el, különböző nagyságú adatot tárolhatnak.
*/


/*char c;
short int si;
short s;          // kettő ugyanaz, a rövidet preferáld
int i;
long long int lli;
long long ll;
long int li;
long i;
				// gyakran a megnevezésük helyett úgy utalunk rájuk, hogy megnevezzük mekkora bit számot az a típus használ fel
			//pl. long helyett "32-bit integer"


/*

egy változó n számú bittel, képes 2^n különböző értéket felvenni, de azt hogy melyik értékeket a változó skálájának hívjuk.

két dolog alapján határozzuk meg, a mérete(bit), és a jele(signed, unsigned)

*/

/*signed char c;
signed int i;
signed short s;
signed long l;
signed long long ll;

			// egy 1 bites signed egész számnak a skálája -128tól 127ig

unsigned char c;
unsigned int i;
unsigned short s;
unsigned long l;
unsigned long long ll;

			// csak pozítiv számokat képesek tárolni, ennek a skálája 0tól 255ig terjed.


/*

túlcsordulás(overflow) akkor jelentkezik, ha túl nagy számot probálunk behelyettesíteni az adott skálába,
	akkor jelentkezik amikor bitek vesznek el, mert a változóhoz nem volt elég memória juttatva, hogy tárolja őket.

*/