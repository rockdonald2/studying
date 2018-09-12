#include "pch.h"
#include <iostream>

/*

Multiple inheritance,
	az eddig összes példa olyan öröklésre alapozott amiben minden gyerek classnak, csak egyetlen szülő classa volt.
	 ! azonban, a C++ támogat többszöri öröklés is, ami alapján egy gyerek class akár több szülő classtól is örökölhet tulajdonságokat.

		pl. tegyünk fel egy tanárt, ami egyben személy is de alkalmazott is,
				létrehozhatunk egy olyan Teacher classot ami egyszerre örököl Person és Employee classtól

					a többszöri öröklés sémája egyszerű, vesszővel válasszuk el őket


Problems with multiple inheritance,
	miközben a többszöri öröklés egy jó kis kiegészítőjének tünik a egyes öröklésnek, valójában rengeteg lényeges problémát okozhat, leginkább
		nagyon komplexé tehet programokat, és igazi rémálommá válhat tőle a kód karbantartás.

		1) kétértelműség léphet fel, amikor két classból származó funkciónak úgyan az a neve.
			- ezt a problémát viszonylag egyszerűen megtudod oldani azért, ha kifejezetten megmondod melyik classból hívod le a funkciót
				CLASSNÉV::FUNKCIÓ

				minél több classból örökölsz annál nagyobb a valószinüsége, hogy naming conflict alakul ki


		2) a gyémánt minta, ez akkor jön létre amikor egy class két olyan classtól örököl ami egy közös alap classtól örököl
				így kialakítva a gyémánt öröklési fát.


Is multiple inheritance more trouble than it's worth?
	rengeteg modern nyelv vagy teljesen mértékben tiltja, vagy korlátozza a többszöri öröklés használatát
		egyetlen ok, túl komplexé tesszi a programokat, és több gondot okoz mint amit megold

		! de fontos szabálya mégis az: használhatod a többszöri öröklés, de csakis akkor ha az alternatívák még komplexebbé teszik a programot.

*/