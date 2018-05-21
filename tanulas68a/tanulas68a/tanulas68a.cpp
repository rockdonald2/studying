#include "stdafx.h"
#include <iostream>

/*

mutató számtan, valamint az array indexelése,
	mutató számtan,
		a C++ engedélyezi, hogy matematikai összeadást, vagy kivonást végezzünk el a mutatókon.
			ha a mutató egy integerre mutat, akkor a mutató+1 a soron következő integer címe lesz a memóriában ami a mutató után jön.
				a mutató-1 pedig a mutató-t megelőzö integer címe lesz.

			! fontos megjegyezni, hogy a mutató+1 nem a mutató után következő memória címet adja vissza, hanem
				abból az adattípusból a memóriában levő következő darabot amire a mutató mutat.
					pl. lásd példa!

		amikor számoljuk egy mutató számtani műveletének eredményét, a compiler mindig beszorozza az integer operándust annak az adattípus
			-nak a méretével amelyre mutat. Ezt hívjuk skálázásnak.

*/

/*

az array elemek egymás után vannak behelyezve a memóriába,
	a fenti skálázással vannak elhelyezve az array elemek a memóriába,
		szóval veszi az első elem, azaz a 0-ás index, memória címét, és skálázzal 1-el, 2-vel, n-el
			ahol n az array hossza.

				pl. sor[2] lényegében = *(sor + 2)
						szóval amikor a compiler lássa az index operátor[], átalakítja az arrayt egy mutatóvá, majd végrehajtja a számtani
						műveletet, és mikor visszadja dereferenceli.
*/