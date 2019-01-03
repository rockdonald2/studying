#include "pch.h"
#include <iostream>

/*

Ahogy gyakrabban neki fogsz használni a move semantics-ot szembe mehetsz olyan esetekkel ahol
	a move semantics-ot akarod segítségül hívni, de az objectek amikkel dolgozol nem r-értékek, hanem l-értékek
		lásd pl.
		- a példában ahhoz, hogy a csere megtörténjen a copy semantics segítségével a compiler 3 másolatot hoz létre,
			ami sokszor nem eléggé hatékony, de hogyan tudnánk a move semantics-ot használni a copy helyett,
				ha a két paraméter nem r-érték hivatkozások, hanem l-érték hivatkozások

std::move
	a "utility" headerben meghatározott std::move-nak egyetlenegy célja van, hogy a beadott érvet r-érték hivatkozássá
		alakítsa át
		- beletudok adni egy l-értéket és r-érték hivatkozást kapunk vissza

		lásd pl, és 2. pl

		! fontos megjegyezni, hogy az std::move-ot olyan l-értékkel használd amelyekre később nem számítasz
			és soha olyan állandó objectre amelyet nem akarsz módosítani
			sose várd el, hogy az object állapota ugyanaz legyen mint std::move előtt

Move functions should always leave your objects in a well-defined state,
	ahogy az előzö leckében megemlítettük mindig nagyon jó ötlet, hogy az objecteket amely mozgattál
		egy jól meghatározott állapotban hagyd, ez lehet egy "null állapot", amikor uninicializált, vagy zéró
			állapotban hagyod a változót

		azért fontos ez mert lehet, hogy a programozó később használja akarja majd azt a változót és akkor e szerint
			tud tervezni

			- a fenti példában a str üres stringgé lett alakítva mozgatás után
			- ez lehetővé teszi, hogy újrahasználjuk az str-t ha akarjuk.

Where else is std::move useful?
	std::move a rendező algoritmusokban lehet még hasznos, számos rendező algoritmus(selection sort, bubble sort)
		ahelyett, hogy másolatokat készíteni(drága) mozgatja, ez által cseréli, az elempárokat

*/