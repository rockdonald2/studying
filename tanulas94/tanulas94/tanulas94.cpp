#include "stdafx.h"
#include <iostream>

/*

Operátorok overloadolása tag funkciókkal nagyon hasonló az előzö módszerekhez.
	Amikor tag funkciókkal overloadolunk egy operátort:
		- az overloadolt operátor muszáj tag funkciókként hozzáadva legyen a bal oldali operándushoz.
		- a bal oldali operándus lesz a magától értetődő *this object
		- minden egyéb operándus funkció paraméter lesz
		

	Átalakítás:
		- az overloadolt operátor tag funkció lesz ahelyett, hogy friend funkció lenne.(Cents::operator+ a friend operator+ helyett)
		- a bal paraméter kitörölve, az már a magától értetődő this object.
		- a funkció bodyba, minden hivatkozás a bal paraméterre kitörölve.(cents.m_cents helyett simán m_cents)


	Melyiket kéne használjuk a két overloadolási módszer közül?
		- nem mindent lehet overloadolni friend funkció használatával: hozzárendelési operátor(=), index operátor([]), funkció hívás
			operátor(()), tag választási operátor(->), ezeket csak tag funkció segítségével lehet overloadolni.
		- nem minden lehet overloadolni tag funkció használatával: I/O operátorok, vagy bármi olyan ami nem class, vagy
			egy olyan class amit nem tudunk modosítani.

		! bináris operátor ami nem modosítja a bal operándust -->> normál/friend overload
		! bináris operátor ami modosítja a bal operándust -->> tag overload
		! unáris operátor -->> tag overload
*/