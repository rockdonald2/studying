#include "stdafx.h"
#include <iostream>

/*

növekedési/csökkentési operátor, increment/decrement operator, négy féle van, ami két különböző fajtát határoz meg.
		van egy prefix, és egy postfix verziója a növekedési/csökkentési operátornak.


		tipp: preferáld a pre-increment/decrement operatorok, teljesítmény miatt, és egyéb furcsa hibákból adodóan.
*/

int szam = 5;
int szam1 = ++szam; // szam egyenlő lesz 6-al, és a 6 asszignálva lesz a szam1-hez.

int szam2 = 6;
int szam3 = szam2++; // a 6-os asszignálva a szam3-hoz, és utána a szam2 egyenlő lesz 7-el.

/*

fontos dolog még megjegyezni ezzel az operátorral, hogy létrehozhat mellékhatással(side effect) rendelkező funkciókat, vagy kifejezéseket.
	mellékhatásnak nevezzük ha megváltoztat valamilyen állást (bármilyen információt a memóriában)

	vannak jó mellékhatások:
			pl: x = 5;
				++x;
				cout << x;



	vannak rossz mellékhatások:
			pl: x = 1;
				x = x++;
				cout << x;

					magyarázat: nem lehet tudni mit fog kiírni ez a program.
						lehet 1 vagy 2, attól függ, hogy a konzol milyen sorrendben végzi el a müveleteket.

	! szabály: ne használj egy változót mellékhatással, többször mint 1 egy adott kifejezésben, ha ezt csinálod az eredmény kiszámíthatatlan lesz.

*/