#include "stdafx.h"
#include <iostream>

/*

Assert and static_assert,
	az a módszer ami alapján egy megsértett feltételezést megállapítunk, azaz használunk egy kondicíós állítást, együtt egy error üzenettel,
		majd leállítva a programot annyira gyakori a C++ nyelvben, hogy egy saját rövidített metódust vezettek be emiatt.
		Ezt hívjuk assertnek.

		Egy assert állítás, azaz kijelentő állítást, egy olyan preprocessor macro ami kiértékel egy kondicíós kifejezést runtimekor.
			ha a kifejezés true akkor az assert állítás nem csinál semmit, de ha false, akkor kiír egy error üzenetet majd
			leállítja a programot. Az error üzenetet tartalmazza azt a kondicíós állítást ami nem sikerült, együtt a kódfájl
			nevével, és a sorszámmal ahol a probléma fellépett.

		Az assert funkcionalitás a <cassert> headerben él, és gyakran használják továbbadott paraméterek helyességének vizsgálatára,
			valamint egy funkció hívás return értékének helyességének vizsgálatára

			lásd pl.

		Bőségesen használd ezeket a funkciókat a kódjaid során.

		Néha az assert állítások nemigazán leíróak.
			Ahhoz, hogy a kevésbé leíró állításokat leíróvá tedd használhatsz egy C-style string leírást a logical AND operátorral
				összekötve.

*/


/*

NDEBUG, and other considerations,
	az NDEBUG segítségével az assert() hívást ignorálhatod, ezt általában release buildeknél használják, mivel akkora a programod
		már teljesen egészében tesztelve kellene, hogy legyen.

			#define NDEBUG

		! a visual studio esetében ha release buildet compileolsz le ezt a parancsot már alapból tartalmazni fogja a kódod.

		! az exit() és az assert() funkció azonnal leállítja a programot, ezért megfontoltan kell ezeket használni ha esetleg
			fájl vagy adatbázis korruptálás állhat fent.

*/


/*

static_assert,
	a C++11-ben bevezetett static_assert annyi különbséggel bír a sima asserthez képest, hogy ez compile idején vizsgálja,
		és compile errort ír ki ha az adott állítás nem igaz.

*/


/*

Exceptions,
	C++ szolgáltat még egy metódust felismerni, és kezelni a hibákat, amit úgy hívunk kivétel kezelés.
		Az alap ötlet az, hogy amikor egy hiba fellép, az error "eldobodik", ha a jelenlegi funkció nem képes "elkapni"
			a hibát, a funkció hívójának van esélye elkapni a hibát. Ha a hívó sem képes, a hivó hivójának van esélye ugyanazt
			elkapni. A hiba progresszíven megy felfele a rakáson amíg vagy elkapják és kezelik, vagy a main()-nek nem sikerül
			kezelnie a hibát. Ha senkinek sem sikerül kezelnie a hibát, a program véget ér.

*/
