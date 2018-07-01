#include "stdafx.h"
#include <iostream>

/*

Static member functions,
	az ez előtti leckében megtanultad, hogy a static tag változók részei a classnak, és nem az objectnek.
	ha a static tag public akkor elérhető a class neve és a scope resolution operátor által.
		De mivan akkor ha a static tag változó privát?
			általában ilyenkor létrehozunk egy public tag funkció ami eléri a változót.
			de ebben az esetben példáznunk kellene egy objectet a classból, hogy használjuk a funkciót.
			sokkal jobb megoldás a static tag funkció.

	úgyanúgy mint a static tag változók, a static tag funkció sem függenek egy adott objecttől.
		lásd pl.
		úgy simán lehívhatók a class neve és a scope resolution operátorral
		! lehívhatók simán objecteken keresztül is, de úgyanúgy mint a tag változók esetében ez nem ajánlott.

*/


/*

Static member functions have no *this pointer,
	a static tag funkcióknak két "fordulatuk" van:
		- először, mivel a static tag funkciók nem függenek egy objecttől sem, nincs this mutatójuk.
		- static tag funkciók elérhetnek közvetlenül más static tagokat, de nem érhetnek el non-static tagokat.
			! mind a kettő azzal van kapcsolatban, hogy a static tagok nem függenek, nem csatoltak egy bizonyos objecthez.

*/


/*

A word of warning about classes with all static members,
	légy óvatos amikor csak static tagokból álló classot írsz, mivel van néhány hátulütőjük:
		- először, mivel minden static tag csak egyszer van példázva, lehetetlen több másolatot létrehozni egy tiszta
			static classból.(anélkül, hogy másolnád és átneveznéd)
		- másodszor, tiszta static classok úgyanolyan hibákkal bírnak mint a globális változók(amiket ugye kerülni kell).


C++ does not support static constructors,
	mivel normál tag változók inicializálhatók konstruktőrök által, így logikus lenne, hogy static tag változókat static konstruktőrök
		inicializálhatnak.
	néhány modern nyelv támogatja az efajta viselkedést, de a C++ nem.

	ha a static változódat tudod közvetlenül inicializálni, nincs szükség egy konstruktőrre: képes vagy static tagot
		inicializálni a meghatározáskor még akkor is ha privát.

	ha a static tag változód inicializálásához szükség van végrehajtodó kódra(pl. loop), rengeteg különböző mód van arra, hogy
		ezt valahogy megold. De valószinüleg soha nem fogod használni.

*/


/*

Összegző,
	static tag funkciók használhatók arra, hogy static tag változókkal dolgozunk egy classon belül.
		nincs szükség objectre ahhoz, hogy lehívjük őket.

	létrehozhatók olyan classok amelyen tiszta static tagokkal dolgoznak. úgyanakkor, ilyen classok alapvetően
		egyenlőek olyan funkciókkal és globális változókkal amelyek a globálisan elérhető namespaceben hozol létre,
		és ezeket általában el kell kerülni, hacsak nincs egy nagyon jó indokod rá.

*/