#include "stdafx.h"
#include <iostream>

/*

Néhány a leggyakrabban használt operátorok közül a számtani operátorok: + - * /
	mind a négy úgyanolyan módon van overloadolva, valamint két operándust vesznek be, azaz binéris operátorok.

	- három féle mód van operátor overloadolásra: friend funkció, tag funkció, normál funkció.

*/


/*

Overloading operators using friend functions,
	lásd pl.

Friend functions can be defined inside the class,
	akár a classon belül is meghatározhatod, de nem ajánlott.

Overloading operators for operands of different types,
	szóval, amikor az operándusok ugyanazon adattípusból származnak, nem számít a paraméterek sorrendje.
	DE, ha már különböző akkor nem mindegy, hogy az első paramétert adjuk össze a másodikkal, vagy fordítva.
		! ha bináris operátorokat akarunk overloadolni úgy, hogy két különböző adattípusból származó paraméterekkel dolgozzanak
			két funkciót kell írnunk és nem egyet.
				lásd pl.

	! sokszor lehetséges az overloadolást megoldani úgy, hogy már meglévő overloadolt operátorok hívunk le.
		használd amikor csak tudod.

*/