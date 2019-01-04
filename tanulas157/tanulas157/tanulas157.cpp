#include "pch.h"
#include <iostream>

/*

Az előző leckében megtanultuk, hogy hogyan lehet használni a shared_ptr arra, hogy több mutató
	közösen birtokoljon egy erőforrást
	- azonban bizonyos esetekben ez problémákhoz vezethet
	lásd pl, ahol a shared mutatók két különböző objectekben a másik objectre mutatnak
		-szóval dinamikusan elhelyezünk két Person-t, Lucy-t és Ricky-t a make_shared()-el,
		aztán használjuk a partnerUp funkciót, ez által a shared_ptr Lucy-n belül Ricky-re fog mutatni,
			valamint fordítva
		-azonban a lefutás után nem hajtódik végre felszabadítás
		-amikor a partnerUp() funkció lehívódik két shared mutató mutat Ricky-re (ricky, és Lucy m_partnere) és
			két shared mutató mutat Lucy-ra(lucy, és Ricky m_partnere)
		-a funkció végén először ricky shared mutatója meg ki scopeból, amikor ez történik ricky leellenőrzi, hogy van-e
			más shared mutató amely birtokolja ugyanazt a Ricky Person-t, van Lucy m_partnere, így nem törli Ricky-t.
			ezután ugye akkor egy shared mutató van Ricky-re (Lucy m_partnere) és kettő Lucyra(lucy, és Ricky m_partnere)
		-- majd ugyanez lezajlik a másik felől, egy-egy shared mutatóval maradva
		- majd a program véget ér és egyik shared mutató sem lesz felszabadítva, mert Lucy Ricky-t tartja életben, míg
		Ricky Lucy-t.

		! ez a probléma bármikor előjöhet circular reference esetében

Circular reference,
	a circular reference (gyakran cyle-nek is emlegetik) az egy olyan hivatkozás sorozat amely során mindegyik object
		a következőre hivatkozik, majd az utolsó object pedig az elsőre, referential loop-ot okozva
		- a hivatkozások nem muszáj C++ hivatkozások legyen, lehetnek akár mutatók, egyedi ID-k, vagy bármi más
			ami adott objectek azonosítására használható.

		ez a probléma a Lucy-Ricky-nél is, ahol Lucy Ricky-re mutat, míg Ricky Lucy-ra, végül mindegyik object
			életben tartja a következőt, majd az utolsó életben tartja az elsőt.
			! tehát egyik object sem a sorozatból nem lehet felszabadítva mert azt hiszi, hogy más objectnek még mindig
				szüksége van rá.

A reductive case,
	amint kiderül a circular reference probléma esetlen shared_ptr esetében is létrejöhet,
		egy shared_ptr ami arra az objectre mutat amely tartalmazza azt az is egy cycle (azonban egy reduktív)
			lásd pl.
			- amikor a ptr1 kimegy a scopeból, nem szabadítja fel a Resource-t hiszen a Resource m_ptr-e
			még mindig megosztja a Resource-t, aztán senki sem marad aki felszabadíthatja a Resource-t
			(m_ptr sose megy ki scopeból, így soha nem lesz rá lehetősége)

std::weak_ptr,
	az std::weak_ptr arra szolgáltatott, hogy megoldja a ciklikus problémát,
		úgy kell gondolni a weak_ptr-ra mint egy megfigyelőre, aki megfigyeli és eléri mindazon objecteket amelyet
		a shared_ptr (vagy más weak_ptr) de nem számít egy birtokosnak.
	- amikor a shared_ptr kimegy scopeból, csak a többi shared_ptr-t veszi figyelembe, a weak_ptr-t nem, 
		így megfelelően törlődik minden.

			lásd I pl átalakítva
			- majdnem ugyanúgy működik mint a problémás példa, azonban most, ha ricky kimegy scopeból
				akkor látja, hogy nincs több shared_ptr Ricky-re mutatva, csak Lucy weak_ptr-e de az nem számít,
				így felszabadítja Ricky-t, majd ugyanez történik Lucy-val is.

Using std::weak_ptr,
	az std::weak_ptr hátulütője az, hogy az std::weak_ptr-t nem lehet közvetlenül használni (nincs operátor->)
		ha használni akarod muszáj átalakítani egy shared_ptr-á, aztán használhatod a shared_ptr-t
		! hogy átalakíts egy weak_ptr shared_ptr-á használhatod a lock() tag funkciót

		lásd pl.

*/