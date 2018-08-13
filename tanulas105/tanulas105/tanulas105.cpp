#include "stdafx.h"
#include <iostream>

/*

Dependency,
	függőség akkor alakul ki amikor egy object egy másik object funkcionalitására hagyatkozik, hogy egy bizonyos műveletet elvégezzen.

		! a függőség mindig unidirekcionális kapcsolat

	egy egyszerű függőségi példa egy class amely használ egy cout overloadot, mert függ az std::couttól, hogy elvégezze a kiírást neki.


Dependency vs association,
	a társulási kapcsolatokban, a kapcsolat két class között jön létre class szinten.
		az egyik class mindig tart egy "kapcsolatot" a másik asszociált classal mint egy tag, lehet az direkt vagy indirekt.
			pl. a Doctor classnak van egy mutató arraye a Patient-ekhez mint tag.
					így akármikor megkérdezheted, hogy kik a doktor páciensei.

	a függőségi kapcsolat nem alakulnak ki class szinten.
		a függő object nem alakít ki "kapcsolatot" mint tag.
			inkább, a függő object példázott amikor szükséges(pl. mikor megnyitsz egy fájlt, hogy írj bele), vagy tovább van adva
				mint paraméter egy funkcióba(pl. az overloadolt cout).

*/