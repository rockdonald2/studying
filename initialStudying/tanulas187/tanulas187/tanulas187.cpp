#include "pch.h"
#include <iostream>

/*

File pointer,
	minden egyes file stream class tartalmaz egy file pointert amely nyomon követi éppen fájlban
		történő írás/olvasás pozícióját

	- amikor valamilyen írás/olvasás történik a fájlon belül, az olvasás/írás a file pointer jelenlegi helyzetén
		történik
		- alapértelmezettként amikor megnyitunk egy fájlt, a file pointer a fájl elejére mutat,
			azonban ha összefüzés módban nyissuk meg a file pointer a fájl végére mutat, így a fájl nem írja felül
				a jelenlegi tartalmát a fájlnak.

Random file access with seekg() and seekp(),
	eddig minden file hozzáférést szekvenciális végeztünk, azaz az írás/olvasás a fájl tartalmaiban sorban történt
		azonban lehetséges ezt random módon is tenni, kihagyni a fájl bizonyos pontjait, hogy azt olvassuk be
			ami nekünk kell.

	a random file access a file pointer manipulálásával jön létre használva a seekg() funkciót(inputhoz),
		és sekkp() funkciót(outputhoz); g-get, p-put
		- néhány típusú stream esetében a seekg() a read pozíció változtatásához jó, míg a seekp() a write pozíció
			változtatásához jó, szóval egymástól függetlenül működnek, de file streamek esetében felcserélhetők,
				mivel a read-write pozíció mindig megegyezik.

	a seekg() és seekp() funkciók két paramétert vesznek be, az első paraméter az offset határozza meg, 
	hogy hány byte-al mozgatjuk el a file pointert, a második paraméter az Ios flag ami meghatározza, hogy az
		offset paraméter honnan legyen eltolva

		beg - azt jelenti, hogy a fájl elejétől számolja
		cur - a file pointer jelenlegi helyzetétől
		end - a fájl végétől

			+offset - azt jelenti, hogy a fájl vége fele mozgatjuk
			-offset - azt jelenti, hogy a fájl eleje fele mozgatjuk

	- még két hasznos funkció a tellg() és tellp() arra használjuk, hogy returnoljuk az abszolút pozícióját
		a file pointernek.
		- ez arra jó, hogy meghatározzuk a fájl méretét.


Reading and writing a file at the same time using fstream,
	az fstream képes arra, hogy egyszerre írjon és olvasson egy fájlt -- majdnem
		az a probléma, hogy nem lehet önkényesen váltogatni az írás-olvasás között
		- ha egyszer egy olvasás vagy írás megtörtént, az egyetlen mód arra, hogy váltsunk a kettő között,
			az, hogy végrehajtunk egy műveletet ami változtatja a file pozíciót(pl. seek)
			- ha nem akarod mozgatni a file pointert, bármikor képes vagy a jelenlegi helyzetre "mozogni"
				iofile.seekg(iofile.tellg(), ios::beg);

				! ha nem csinálod ezt bármilyen furcsa és bizar dolog megjelenhet

		a másik dolog, amikor használtuk ifstream esetében a while(inf)-et, hogy megnézzük van-e még mit
			beolvasni a fájlról, az fstream esetében ez nem működik
			lásd pl.

		többi hasznos funkció: remove() fájl törlésére, is_open() ha megakarnánk nézni nyitva van-e a stream

*/