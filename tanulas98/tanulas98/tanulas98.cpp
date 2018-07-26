#include "stdafx.h"
#include <iostream>

/*

Overloading operator[],
	az index operátort tag funkciókként kell overloadolni, és egyetlen paramétert vesz be, az index-et amit a [] közé raksz.
		! fontos, integert add vissza, így a return type int& kell legyen.

		lásd pl.

		a overloadolt index operátor segítségével képesek vagyunk direkt módon lekérni, illetve beállítani array értékeket.

Dealing with const objects,
	const objectek esetében a normál operátor[] mellé egy const verziót is mellékelni kell.
		a non-const verzió a non-const objectekhez, a const verzió a const objectekhez.

Error checking,
	az overloadolt operátor[]-vel nagyon egyszerű az error check, simán behelyezünk egy assert funkciót, hogy leellenőrízzük,
		hogy az index helyes-e.


		! fontos szabály, sose hívd le az operátor[]-t egy objectre mutató mutatóra.
			- ez előtt le kell dereferencelni és akkor mükődni fog.


Function parameter does not need to be an integer,
	az operátor[] paramétere bármilyen típusból lehet.
		- akár szavakat is használhatsz mint index.

*/