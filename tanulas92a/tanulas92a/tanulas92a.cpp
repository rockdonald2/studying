#include "stdafx.h"
#include <iostream>

/*

Overloading operators using normal functions,
	a friend funkciós mód kényelmes, mivel lehetőséget biztosít, hogy a belső tagjait elérd a classnak amin dolgozol.
	DE, ha nincs szükséged erre az elérésre, overloadolhatod az operátorokat normál funkciókkal is.
		az előzö leckében található példa esetében volt egy tag funkciónk getCents() néven ami lehetővé tette, hogy elérjük
			a privát változót anélkül, hogy használhatnánk a class belső tagjait.

			lásd pl.

	a friend funkciós mód, és a normál funkciós mód között nincs lényeges különbség, csak egy, amikor a class-ot .h és .cpp
		fájlokba bontod fel, a normál funkciós mód esetén kifejezetten oda kell írj egy funkció prototypeot is a .h fájlba,
		hogy tudja, hogy az operátor overloadolva lesz/van.

	! szabály, bármikor amikor lehetőséged van a normál funkciós módot preferáld.

*/