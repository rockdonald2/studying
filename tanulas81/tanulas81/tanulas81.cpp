#include "stdafx.h"
#include <iostream>

/*

A hagyományos programozásban(amit eddig csináltunk), a program lényegében utasítások sorozata a számitógéphez ami meghatároz
	adatokat(objectek által) és ezután dolgozik ezzekkel az adatokkal(állítások és funkciók által). Az adatok és a funkciók
	amik az adatokon dolgoznak különböző entitások amiket összekombinálunk, hogy a kivánt eredményt hozzuk létre.
	Ez a különállóság miatt, a hagyományos programozás sokszor nem nagyon reprezentálja a valóságot.
	A programozó feladata, hogy megfelelő módon kezelje és csatlakoztassa a tulajdonságokat(változók) a viselkedésekhez(funkciók)
		a megfelelő módon.
			
			Ez hasonló kódokhoz vezet:
					driveTo(you, work);

Szóval mi is az Object Oriented Programming(OOP)?
	A hasonlatosság által a legkönnyebb megmagyarázni. Nézz magad köré. Akárhova nézel tárgyakat(objects) látsz: könyvek, építmények,
	étel, és akár te magad is. A tárgyaknak van két meghatározó alkotóelemük: 1) Egy sor releváns tulajdonság: súly, szín, méret, stb.
	2) Egy bizonyos számú viselkedés amit előidézhetnek: kinyitható, valamit forróvá tesznek, stb. Ezek a tulajdonságok, és viselkedések
	elválaszthatatlanok.
	Az OOP biztosít számunkra egy lehetőséget arra vonatkozóan, hogy olyan objecteket hozzunk létre amely összekapcsolja mind a
	tulajdonságokat és viselkedéseket egy önálló, újrahasználható csomagban.

			Ez hasonló kódokhoz vezet:
					you.driveTo(work);

		Ez lehetőve teszi a programoknak, hogy egy sokkal modularisabb formában iródjanak, ami könnyebbé teszi az írást-megértést,
			és biztosít egy magasabb szintű kód-újrahasználhatóságot. Ezek az objectek biztosítanak egy sokkal intuitívabb módot
			arra ahogy dolgozunk az adatokkal az által, hogy lehetővé teszi, hogy meghatározzuk hogyan hatunk mi az objectekre,
			és hogy ők hogyan hatnak más objectekre.

	Az OOP még behoz jópár más hasznos koncepciót: inheritance(öröklés), encapsulation(beágyazás), abstraction(elvonás),
		polymorphism.


		! az 'object' szó kicsit overloaded, szóval egyszerűsítsünk:
			- az object a hagyományos programozásban egy darabka a memóriából ami arra szolgál, hogy értékeket raktározzon.
			- az OOP-ben, az object magába foglalja a hagyományos értelmet, továbbá egyesíti a tulajdonságot valamint viselkedést.

*/