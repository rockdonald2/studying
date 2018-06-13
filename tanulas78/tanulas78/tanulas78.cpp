#include "stdafx.h"
#include <iostream>


/*

Function pointers,
	olyan mutatók amelyek nem változók memória címére, hanem funkciók memória címére mutatnak.

	a funkcióknak megvan a saját l-értékű funkció típusuk, például az alábbi példánál egy olyan funkció típus amely
		visszaad egy integert, és nem fogad be semmilyen paramétert.
		úgyanúgy ahogy a változók, a funkciók is kijelölt címmel rendelkeznek a memóriában.

		amikor lehívják a funkciót ( az () operátorral ), akkor a végrehajtás a funkció címére ugrik amelyet lehívtak.

*/

int foo()
{
	return 5;
}


/*

Pointers to functions,
	a séma amellyel egy nem-konstans funkció mutatót hozhatunk létre a következő:
		int (*fcnPtr)();

		ebben a kódrészletben a fcnPtr egy mutató egy funkcióra amely nem fogad be egy paramétert sem, és visszaad egy integert.
			a fcnPtr mutathat bármely funkcióra amely teljesíti ezeket a kritériumokat.

			! a zárójel kötelező az elsőbbségi szabály miatt.

	a séma amellyel egy konstans funkció mutatót hozhatunk létre a következő:
		int (*const fcnPtr)();

			! ha a const-ot az 'int' elé rakod akkor egy olyan funkció mutatót hozunk létre amely egy const int-et ad vissza.
		
*/


/*

Assigning a function to a function pointer,
	a funkció mutatókat lehet egy funkcióval inicializálni.

		lásd pl.

	! fontos, a funkció mutató típusa megkell egyezzen a funkció típusával.

	! nem úgy mint alapvető típusok esetében, a C++ magától értetődöen átalakít egy funkciót funkció mutatóvá ha szükséges.
		de, nem fog magától átalakítani egy funkció mutatót void mutatóvá, vagy fordítva.

*/


/*

Calling a function using a function pointer,
	a másik elsődleges dolog amire használnak egy funkció mutatót, hogy lehívják vele a tényleges funkciót.
		erre két mód van. 

		1) kifejezett dereference által
		2) magától értetődö dereference által

		! megjegyezni, alapértelmezett paraméterek nem mükődnek a mutatón keresztül lehívott funkciók esetében.

*/


/*

Passing function as arguments to other functions,
	az egyik leghasznosabb dolog amit tehetünk funkció mutatókkal, hogy más funkciókat adjunk tovább funkcióknak mint érvek.

		pl. gondolj egy sorting funkcióra, ami ugye egy array-t rendez.
				ezzel a fenti ténnyel, könnyen továbbadható egy érv ami alapján megváltoztatható a felhasználó által
					,hogy növekvő vagy csökkenő sorrendben rendezze az arrayt.

					lásd pl.

*/

/*

Providing default functions,
	akár egy ilyen funkció mutató paraméternek is meghatározhatunk alapértelmezett értéket.
		így például ha a felhasználó csak simán kéri le a 'selectionRendezes'-t akkor az alapértelmezett müvelet fog végrehajtódni.

Making function pointers prettier with typedefs or type aliases,
	a funkció mutató sémája eléggé csúnya.
		ezért a jobb olvashatóság miatt ajánlott saját 'alisokat' meghatározni nekik.

*/


/*

std::function,
	egy alternatív megoldás arra, hogy létrehozzunk és tároljunk funkció mutatókat az std::function.
		ami a <functional> headerben található meg.

			sémája: std::function<returnTípus(paraméterek)>név;

*/