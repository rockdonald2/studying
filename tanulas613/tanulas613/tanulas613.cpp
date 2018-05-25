#include "stdafx.h"
#include <iostream>


/*

void pointer,
	a vointer pointer, a.k.a általános mutató, egy különleges típusú mutató amely bármely adattípusra mutathat.
		úgyanúgy hozzuk létre mint a sima mutatót, csak az adattípus helyett void-ot írunk.

		! de mivel, egy ilyen fajta mutató nem tudja, hogy milyen típusú tárgyra mutat, ezért nem lehet direkt módon dereferencelni.
		először a mutatót kifejezetten átkell alakítani(castolni) egy bizonyos típusú mutató típussá, mielőtt dereferencelnéd.

		? hogyan tudod mivé kell alakítani? Ez a te feladatot nyilván tartani.

*/


/*

Void pointer egyveleg,
	- a void mutatókat lehet nullává egyenlővé tenni. Azaz null pointerré.
	- kerüld el, hogy olyan void mutatókat törlesz amik dinamikusan elosztott memóriára mutat.
	- nem lehetséges mutató számtant végezni a void mutatókon.

*/


/*
Konklúzió,
	Általánosságban, jobb elkerülni a void mutatók használatát, mert enged olyan dolgokat tenni amiknek semmi értelme,
		mivel nem használ semmiféle típus checket.


*/