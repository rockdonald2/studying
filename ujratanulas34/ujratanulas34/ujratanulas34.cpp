#include "stdafx.h"
#include <iostream>

/*

1. sizeof operátor, a sizeof(type/variable) sémát használva, kiírja mekkora méretet foglal el az adott típus/változó byte-okban számolva a memóriában.

2. a comma, vessző, operátor lehetőve teszi, hogy több kifejezést fejezz ki, akárhol ahol csak egyet lehetne.
			a comma operátor kifejezi a legjobboldalibb operándust.

			tipp: ne nagyon használd, ha lehet soha, maximum for loopokon belül.

3. a conditional, kondiciónális, feltételes, operátor, ami egy rövíditett változata az if kifejezésnek.
		sémája: kondició ? első_érték : else_érték
			tipp: csak akkor használd, ha elősegíti az olvashatóságot, és csakis egyszerű kifejezéseknél.


			a conditional operátort lehet használni olyan helyeken ahol a sima if kifejezést nem!
				pl. a konstant értékek meghatározásánál.

				const int osztalyMeret = egyAtlagosOsztalyMerete ? 30 : 20;
						ez azért lehetséges mert a conditional operátor egy kifejezésnek felel meg,
							amikor az if kifejezés pedig egy sor állításnak.
			

*/