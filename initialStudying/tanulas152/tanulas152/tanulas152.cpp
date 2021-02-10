#include "pch.h"
#include <iostream>

/*

Még az első fejezetben említettük az l-értéket, illetve r-értéket, és azt mondtuk, hogy nem kell sokat törödni
	velük.
	Ez igaz is volt egészen a C++11-ig, azonban most a move semantics megértése miatt szükséges ezek újravétele

*/

/*

L-values and r-values,
	annak ellenére, hogy mindkét kifejezés tartalmazza az "érték" szót, az l-érték és r-érték
		igazából nem értékek tulajdonságai, sokkal inkább kifejezések tulajdonságai

	minden kifejezésnek a C++-ban van két tulajdonsága: típus (amit type checkinghez használnak),
		és egy érték kategória (amit különböző syntax checkinghez)
			! C++03-ban és korábban, csak ez a két érték kategória létezett

	a tényleges meghatározás, hogy mely értékek l-értékek, és melyek r-értékek nagyon bonyolultak, ezért
		egy egyszerűsített megközelítést fogok meghatározni, ami elégséges a téma megértéséhez

	minden l-értéknek egyszerűen van memória címe, illetve az l-érték lényegében úgy kell gondolni mint egy
		fúnkcióra vagy objectre (vagy egy kifejezésre ami egy funkcióra vagy egy objectre értékelődik)
		- eredetileg az l-értékeket úgy határozták meg mint értékek amelyek megfelelőek arra, hogy egy hozzárendelési
			kifejezésben a bal oldali helyet foglalják el
		- azonban a const kulcsszó hozzáadásával az l-értékek két fajtára osztódtak: módosítható l-értékek,
			illetve nem módosítható l-értéke, azaz a const-ok.

	az r-érték minden olyan dolog ami nem l-érték, főleg számokat, ideiglenes értékeket, és anonymous objecteket értünk
		ez alatt.
		az r-értékek általában az értékeikre értékelődnek, expression scopejuk van (azaz a kifejezés végén törlődnek),
			és nem lehet hozzájuk rendelni.

	ahhoz, hogy támogassa a move semantics-ot a C++11 3 új érték kategóriát vezetett be: pr-értékek, x-értékek, gl-értékek
		https://en.cppreference.com/w/cpp/language/value_category

*/


/*

L-value references,
	a C++11-et megelőzöen csak egyetlen hivatkozás típus létezett, amit csak simán hivatkozásnak hívtak,
		azonban C++11-ben ezt l-value hivatkozásnak hívják
		- minden l-érték hivatkozást csak módosítható l-értékkel lehet inicializálni
		- minden const-ra mutató l-érték hivatkozást bármely érték kategóriával lehet inicializálni,
			de nem lehet egyiket sem módosítani.

			! nagyon hasznos a const l-érték hivatkozás, hiszen lehetővé teszi, hogy bármilyen l-érték,
				vagy r-érték érvet átadjunk egy funkcióba anélkül, hogy másolatot készítenénk az érvből.


R-value references,
	a C++11 bevezetett egy új típusú hivatkozást amit r-érték hivatkozásnak hívnak.
	- az r-érték hivatkozás egy olyan hivatkozást amelyet csak r-értékkel lehet inicializálni

		lásd pl.

		- két fontos és hasznos tulajdonsággal rendelkezik:
			- az r-érték hivatkozás kibővíti az object élettartamát az inicializált r-érték hivatkozás élettartamáig
			- a nem-const r-érték hivatkozások lehetővé teszik, hogy módosítsd az r-értékeket.

			lásd pl.


R-value references as function parameters,
	a r-érték hivatkozásokat sokkal gyakrabban használják mint funkció paraméterek,
		a legnagyobb hasznuk akkor van amikor funkció overloadok esetében amikor különböző viselkedést akarsz
			l-értékeknek, és r-értékeknek
				- ez fontos lesz a move semantics esetében

Returning an r-value reference,
	sose szabadna sem r-érték hivatkozást, sem l-érték hivatkozást visszaadni, mivel gyakran csak egy logó hivatkozást
		adnál vissza, mivel a hivatkozott object kimegy scopeból a funkció végén.

QUIZ
	B, E, G

*/