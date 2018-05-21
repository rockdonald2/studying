#include "stdafx.h"
#include <iostream>

/*

Annak ellenére, hogy a char (karakter) típus egy egész szám(és követi annak minden szabályát) másképp használjuk.

	a char képes tárolni egy 1 byte-os(8bit) egész számot.
	de ahelyett, hogy számként kezelné gyakran az értéke egy ASCII karaktert értelmez.

		ASCII(AMERICAN STANDARD CODE FOR INFORMATION INTERCHANGE), definiálja az összes angol karaktert, plusz néhány szimbólumot.
				pl. 'a' = 97, 'b' = 98.
					a char-okat mindig ' ' közé tesszük.

*/


char ch1(97); // iniciálja a 97-es egész számmal = a
char ch2('a'); // iniciálja az 'a' karakterrel(97) = a ( 'a' egy code point)

// char ch3(5);
// char ch4('5');  ! A kettő nem ugyanaz !


/*

lehetséges a char-okat számként kiírni cout-tal egy static_cast paranccsal
		ennek a sémája: static_cast<ujtipus>(kifejezes)

*/



/*

vannak olyan karakterek amelyekhez különleges értelmek vannak definiálva, ezeket escape sequences-nek nevezzük.

		ilyen \n ami egy új sort eredményez.
		a \t ami egy tab-ot szóval egy nagyobb szoközt iktat be.


*/

/*

std::endl; vs \n

		a kettő ugyanazt csinálja, de!
			használd std::endl-t, amikor megakarsz bizonyosodni arról, hogy az outpot azonnali output
				teljesitmény gondokat okozhat

			minden másban \n!

*/