#include "stdafx.h"
#include <iostream>

/*

Overloading typecasts,
	a C++ tudja hogyan kell átalakítani a beépített típusokat, azonban a felhasználó által írt class típusok esetében nem.

	két fontos dolgot kell lejegyezni typecast overload esetében:
		1) ahhoz, hogy overloadoljunk egy funkciót ami átalakítja a classunkat egy intbe, írnunk kell egy új funkciót a classunkba
			'operator int()' néven. 
				! van egy space az 'operator' szó és a típus között amire alakítjuk.
		2) Az átalakító operátoroknak nincs return typeja. C++ feltételezi, hogy a megfelelő típust adod vissza.

			lásd pl.


			ilyen fajta átalakítás után kifejezett módon is képesek vagyunk átalakítani a static_cast<>() paranccsal.
*/