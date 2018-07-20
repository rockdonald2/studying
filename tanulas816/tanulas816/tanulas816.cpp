#include "stdafx.h"
#include <iostream>

/*

Timing your code,
	amikor íruk a kódodat, néha szembe mész olyan esetekkel mikor nem tudod eldönteni, hogy egyik metódus vagy épp a másik
		a legeredményesebb.

	egy könnyű mód arra vonatkozólag, hogy kiterítsd ezt, hogy leméred mekkora idő alatt futódik le az adott programod.
	a <chrono> könyvtár tartalmaz pár parancsot erre vonatkozóan, és egy class segítségével könnyen beágyazhatunk minden
	időmérő funkciót egyetlen helyre, hogy bármely programunkban használhassuk.


	lásd a classot az idomero.cpp-ben,
		és ennyi az egész class, ahhoz, hogy használjuk bármely main()-ben vagy funkcióban simán létrehozunk egy Idomero
			objectet, és majd lehívjuk az elteltIdo() tag funkciót bármikor amikor tudni akarjuk az eltelt időt amennyi eltelt
			a program futása óta addig a pontig.

*/