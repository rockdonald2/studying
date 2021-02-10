#include "pch.h"
#include <iostream>

/*

Input and output streams,
	az input/output nem része a C++ nyelv magjának, sokkal inkább a standard library adja hozzá ezt a funkcionalítást
		ezért az <iostream> headerben találhatók meg
			pl. cin, cout

The iostream library,
	amikor includeolod az <iostream> headert egy teljes class hierarchiát érsz el ami I/O funkcionalítást biztosít
		- beleértve egy classt amit ténylegesen iostream-nek hívnak
		- a class hierarchia non-file-I/O classoknak valahogy így néz ki:
			ios_base
				|
			  ios
				|
		istream   ostream
		|		\/		|
istream_withassign	| ostream_withassign
	(cin)			|	(cout, cerr, clog)
				iostream
					|
			iostream_withassign

	- az első dolog amit észrevehetsz, hogy többszöri öröklést használ, azt amire azt írtuk korábban, hogy kerüld
		el ha lehetséges, de mivel az iostream library-t többször tesztelték, hogy elkerüljék a tipikus
		problémákat, így szabadon lehet használni

Streams,
	a második dolog amit észrevehetsz, hogy a stream szó rengetegszer megjelenik, az alapvető I/O a C++-ban streamek
		segítségével van beépítve.
		- a stream lényegében csak egy karakter sorozat amit egymás után lehet elérni
		- idővel, a stream létrehozhat vagy felemészthet végtelen mennyiségű adatot

	általában két féle streammel foglalkozunk, az első az input stream, amit arra használunk, hogy inputot tároljunk
		egy adat előállítótól, akárcsak egy billentyűzet, egy fájl, vagy hálózat,
			pl. a felhasználó leüthet  egy gombot a bill.-en miközben a program nem számít ilyenre,
				ezt a karaktert az input stream tárolja amíg a program készen áll majd rá.
	a második az output stream, amit arra használunk, hogy outputot tároljunk egy bizonyos adat fogyasztónak,
		mint pl. egy monitor, egy fájl vagy egy nyomtató
		- amikor adatot írunk egy output eszköznek, az eszköz nem biztos, hogy már készen áll, hogy elfogadja az adatot,
			pl a nyomtató nem melegedett még fel, így az output stream tárolja az adatot, míg a nyomtató neki nem fog
				feldolgozni azt.

	- néhány eszköz mint fájlok vagy hálozatok, képesek egyszerre input és output streamek is lenni.

	- a jó dolog a streamekkel kapcsolatban az, hogy a programozónak csak azt kell tudnia, hogy interaktáljon ezekkel
		a streamekkel, hogy adatot tudjon olvasni vagy írni különböző fajtájú eszközökre/ről,
		a részletek arról, hogy hogyan vannak a stream interfészek összekötve a tényleges eszközökkel az rá van hagyva
			az operációs rendszerre illetve környezetre.

Input/output in C++,
	habár az ios class igazából a ios_base classból van származtatva, az ios class az utolsó amivel általában
		közvetlenül dolgoznod kell, az ios class meghatároz egy csomó dolgot ami gyakori input és output streamekhez

	az istream class az elsődleges class amit input streamekhez használunk,
		input stream esetében az extraction operator-t használjuk (>>), hogy értéket töröljünk ki a streamből

	az ostream class az elsődleges class amit output streamekhez használunk,
		az insertion operator-t használjuk (<<), hogy értéket helyezzünk a streambe

	az iostream class képes kezelni mindkettőt, lehetővé téve kétirányú I/O-t

	aztán ott van rengeteg class "_withassign"-al, ezek a stream classok istream, ostream, vagy iostream classokból
		vannak származtatva egy assignment operátorral meghatározva, lehetővé téve, hogy egyik stream-et a másikhoz
			rendeld, de a legtöbb esetben nem fogsz ezekkel dolgozni közvetlenül

Standard streams in C++,
	a standard stream az egy előre hozzácsatlakozott stream biztosítva egy számítógéphez a környezetétől
		a C++ 4 előre meghatározott standard stream objecttel rendelkezik amik már készen állnak arra, hogy
			használjuk 
		cin - istream_withassign class hozzákötve a standard inputhoz
		cout - ostream_withassign class hozzákötve a standard outputhoz
		cerr - ostream_withassign class hozzákötve a standard errorhoz, biztosítva buffer nélküli outputot
		clog - ostream_withassign class hozzákötve a standard errorhoz, biztosítva buffer-es outputot

	- a buffer nélküli outputot általában azonnal kezeljük, míg a buffe-es outputot általában tároljuk, majd
		kiírjuk mint egy blokk, mivel a clog-ot gyakran nem használjuk, ezért ki is szokták hagyni a standard
			stream listából.

			alapvető példa lásd pelda.cpp
*/