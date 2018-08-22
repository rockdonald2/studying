#include "pch.h"
#include <iostream>

/*

Az object kompozíció csak egy a két fő módszerből ami által komplex classokat hozhatunk létre.
	A második az öröklés.

		az örökles kapcsolat az "az egy" kapcsolattípust ábrázolja
			pl. az alma az egy gyümölcs

		nem úgy mint az object kompozíció esetében ahol komplex class jött létre több kisebb class összetételéből,
			az öröklés során új objectek jönnek létre úgy, hogy közvetlenül megszerzi egy másik object tulajdonságait,
			és viselkedését majd ezt bővíti és specializálja ki


Hierarchy,
	egy hierarchia megmutatja, hogy a tagok miként viszonyulnak egymáshoz

	a hierarchia haladási sorrendje: általánostól -> sajátosságokig

	! a hierarchia tagjai öröklik a tőlük fenebb levő tagok tulajdonságait

*/