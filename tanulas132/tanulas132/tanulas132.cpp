#include "pch.h"
#include <iostream>

/*

hogyan is müködik egy funkció template?
	- a funkció templateket a compiler direkt módon nem fordítja le, hanem
		minden egyes lehívás esetében replikálja az adott funkció a lehívott típussal, majd ezt fordítja le.
		! ezt a funkciót amit valódi adattípusokkal hozz létre function template instance-nek hívjuk.

*/

/*

Operators, function calls, and function templates,
	template funckiók bármely beépített adattípussal, illetve classal müködik, egy ellentmondással.
	- amikor a compiler lefordítja a template instance-t, úgy csinálja ahogy egy normál funkciót.
	- minden normál funkcióban, bármely operátor vagy funkció hívás amit a típusaiddal használsz megkell legyen határozva,
		ha nincs compiler error
	- hasonlóan, bármely operátor vagy funkció hívás a template funkciódban is muszáj meghatározva legyen bármely típusra
		amelyre a template példázva lehet

		lásd pl.-t a classal, ahol muszáj a > operátort overloadolni ahhoz, hogy müködjön.

*/