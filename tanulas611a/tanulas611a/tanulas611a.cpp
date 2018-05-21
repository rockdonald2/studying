#include "stdafx.h"
#include <iostream>

/*

References and consts,
	ahogy lehetséges egy const értékre mutatót rakni, lehetséges meghatározni egy hivatkozást egy konstans értékre,
		használjuk a const kulcsszót

	nem úgy mint a sima hivatkozások esetében amik non-konstans l-értékekre hivatkoznak, a konstans hivatkozások hivatkozhatnak
		non-konstans l-értékre, konstans l-értékre, vagy r-értékre is.

	pont úgy mint egy mutató esetében ami konstans értékre mutat, egy konstans hivatkozás is hivatkozhat olyan értékr ami eredetileg
		nem konstans, de így a hivatkozáson keresztül az lesz.


*/


/*

Fontos megjegyezni, hogy a hivatkozások kibővítik egy r-érték élettartamát,
	szóval, mivel egy r-értéknek expression scopeja van azaz a kifejezés kiértékelése után törlődnek az értékek, ha ezt egy
		hivatkozáson keresztül tesszük akkor az r-érték élettartama kibővül, hogy megegyezzen a hivatkozás élettartamával.

		! lásd példa
*/


/*

Konstans hivatkozások mint funkció paraméterek,
	a hivatkozások amiket funkció paraméterként adunk át lehet konstansok,
		ez két okból jó: garantálja, hogy nem másoljuk az eredeti érvet ami költséges lehet, de mégis képesek vagyunk elérni
						 garantálja, hogy a funkció nem változtassa meg az eredeti értéket.

	konstans hivatkozások legtöbbször emiatt hasznosak, sokat használják funkció paraméterként mert sokoldalúak,
		egy konstans hivatkozások lehetőséget ad, hogy továbbadjunk non-konstans l-értéket, konstans l-értéket, r-értéket(ami lehet betü,
			vagy egy kifejezés értéke)


*/

/*
Ahhoz, hogy elkerüljük, hogy szükségtelen, talán drága másolatokat, olyan változók amelyek nem mutatók, vagy alapvető adattípusok(int, double
	stb.) alapból egy (konstans) hivatkozás által kellene átadni. 

	Alapvető adattípusok pedig érték szerint kellene továbbadni, hacsak a funkció nem kell megváltoztassa.

	! szabály, Minden nem mutató, vagy nem alapvető adattípust(pl. stucts, vagy class) (konstans) hivatkozásokon keresztül adj át.


*/



