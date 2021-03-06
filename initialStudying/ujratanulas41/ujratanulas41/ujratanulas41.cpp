#include "stdafx.h"
#include <iostream>

/*

Amikor változokról beszélünk fontos megemlíteni a változók scopeját, és durationjét.
	egy változó scopja meghatározza hol elérhető az adott változó.
	egy változó durationje meghatározza mikor jön létre és mikor semmisül meg az adott változó.
		! gyakran egymástól függnek.

Egy funkción belül meghatározott változó egy helyi(local) változó, aminek automatic durationje és block(local) scopeja van.
	azaz, az automatic duration szerint akkor jön létre mikor definiálják és akkor semmisül meg mikor kilép az adott blokkból amiben létrejött.
		  a block scope szerint csak az adott blokkban ahol létrehozták érhető el.

Befészkelt blokkokban létrehozott változók akkor semmisülnek meg amikor a befészkelt blokk véget ér.

Külső blokkban létrehozott változók a befészkelt blokkban is elérhetők.

*/


/*

fontos megjegyezni, hogy egy változónak egy befészkelt blokkon belül lehet ugyanaz a neve mint egy külső blokkban található változónak,
	ezt hívjuk árnyékolásnak, vagy név elrejtésnek.
		fontos !, fontos initializálni, mert ha nem akkor nem fog megfelelően mükődni

		szabály, jobb elkerülni ezt az árnyékolást.

*/


/*

szabály, a változókat mindig a lehető legkisebb scope-ban határozd meg!
	tehát, ha a külső blokkban van szükséged a változóra ott határozd meg,
		ha a befészkelt blokkban, akkor ott.

*/

/*

funkció paraméterek-nek is block scopeja van.

*/