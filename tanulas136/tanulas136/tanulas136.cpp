#include "pch.h"
#include <iostream>

/*

Az előző leckében megtanultuk, hogy hogyan lehet specializálni a template funkciót adott adattípusokra,
	ez akár egy classra is érvényes, szóval lehet akár egy egész classot specializálni.

	- az első megoldása a boolStorage-nek nem hatékony, mivel 8 byte-t használ fel, miközben 1 byte is elég lenne
		8 bool értékhez.
		a specializált class pont ezt oldja meg
		! egy specializált class úgy mükődik mint egy független class

*/