#include "stdafx.h"
#include <iostream>

/*

Egy mutató egy mutatóra(a pointer to a pointer),
	ahogy a neve is mutatja, egy olyan mutató amely egy másik mutató memória címét tartalmazza.

	Ahogy egy sima mutatót egy csillaggal jelölünk, úgy a mutatóra mutatót két csillaggal.
		pl. int *ptr;
			int **ptrptr;

	Egy ilyen fajta mutató úgy mükődik akárcsak egy sima mutató, dereferencelhető, hogy lekérjük milyen értéket tartalmaz, ez esetben
		memória címet, majd megint dereferencelve az eredeti értéket. Ezt a két dereferencelést csinálhatod egymás után is.
		pl. lásd pelda

		! fontos, nem tudsz egy ilyen fajta mutatót egy értékre tenni.
		úgyanakkor, egy ilyen mutató lehet null pointer.
			
*/

/*

Az ilyen fajta mutatóknak nagyon kevés felhasználási módja van, az egyik ilyen ha dinamikusan akarsz elosztani egy arrayni mutatót.
	pl. int **array = new int*[10]
		- ez úgy mükődik akárcsak egy normális dinamikus array, de az array elemei int-re mutató mutatók lesznek.
	
*/

/*

Két dimenziós dinamikusan elosztott arrayek,
	bonyolult dolog, amit sose fogsz használni.

*/

/*

Akár lehet olyan mutatót létrehozni ami mutatat egy mutatóra ami megint mutat egy mutatóra és a többi..

*/


/*
Konkluzió,
	ezt a dolgot egy az egyben kerüld el, jó tudni róla, de bonyolult és nagyon veszélyes beiktatni egy programban.


*/