#include "stdafx.h"
#include <iostream>

/*

bináris átalakítás,
		szóval, binárist decimálissá átalakítani tök egyszerű, a kettő hatványait használod.
			pl: 0111 0101 = 0*128 + 1*64 + 1*32 + 1*16 + 0*8 + 1*4 + 0*2 + 1*1 = 117


		decimálist binárissá, két módszer van,
			az egyik szerint osztod kettővel, a maradék 1-et vagy 0-át írod fel alúlról felfelé

			a másik alapján, veszed a kettő legnagyobb hatványát ami még kisebb mint a szám amit át akarsz alakítani,
				majd, a kettő hatványát kivonod a számból, majd megnézed, hogy az eggyel kisebb hatvány nagyobb-e vagy egyenlő mint a megkapott szám
					ha nem 0, ha igen 1,
						és ezt folytatatod míg el nem jutsz 0-ig.

						a maradékokat pedig kitöltöd nullával.

					
			pl:
					148
						148 >= 128 1
						20 >= 64 0
						20 >= 32 0      szóval, 10010100
						20 >= 16 1
						4 >= 8 0
						4 >= 4 1


összeadás:
	simán felírod egymás alá, és összeadogatod oszlopokként jobbról balra, figyelve, hogy vidd tovább az esetleges 1-eket.

		pl:
					1011 0011
					0000 0001

					1011 0100


negatív számok:
	ezek eddig csak unsigned egész számok voltak , amik csak pozítivak lehetnek.
		a signed számok lehetnek negatívak is, amit a két kiegészítő(two complement) szabállyal alakítunk át,
			ami szerint a legjobb baloldalibb(legfontosabb) bit-et használjuk az előjel meghatározására, ez az előjel bit.
				0 pozítiv, 1 negatív.

				pozitív signed számok úgyanúgy vannak raktározva mint az unsigned számok

				negatív signed számok pedig úgy vannak raktározva, hogy invertáljva a pozítiv számot, majd hozzá az 1-et.

				pl:
					5 = 0000 0101
					invertáljuk: 1111 1010
					hozzá adunk 1-et: 1111 1011 = -5

					76 = 0100 1100
					invert: 1011 0011
					+1 = 1011 0100 = -76

					tehát 1011 0011
						  0000 0001

						  1011 0100


signed szám átalakítása decimálissá:
	először nézd meg az előjel bitet, ha 0 úgyanúgy mint az unsigned számokat
									  ha 1, akkor invertálod, majd hozzá adsz 1-et, és azután alakítod decimálissá negatív előjellel.

						pl: 1001 1110 = negatív mert 1

						szóval, invert: 0110 0001
								+1: 0110 0001
									0000 0001
									0110 0010 és alakít = 64+32+2 = -98


MIÉRT SZÁMIT A TíPUS?
	minden szám két féle értéket raktározhat, a típusától függően, a 1011 0100 lehet 180 vagy -76
		ha unsigned típus akkor 180, ha signed típus -76

		*/


/*

0100 1101 = 64 + 8 + 4 + 1 = 77

93, unsigned, 8 bit = 0101 1101

-93, signed, 8 bit = 1010 0011

1010 0010, unsigned = 128 + 32 + 2 = 162

1010 0010, signed = 0101 1110 = 64 + 16 + 8 + 4 + 2 = -94



*/