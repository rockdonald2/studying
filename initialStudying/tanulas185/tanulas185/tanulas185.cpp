#include "pch.h"
#include <iostream>

/*

Stream states,
	a ios_base class számos state flaget tartalmaz, hogy jelezzen különböző kondicíókat amik megjelenhetnek
		stream használata közben:
			
			flag: goodbit - jelőli minden rendben van
				  badbit - fatális hiba jelent meg, pl. a program megpróbált a fájl vége utánról olvasni
				  eofbit - a stream elérte a fájl végét
				  failbit - nem fatális hiba jelent meg, pl. a felhasználó egy betüt írt be mikor a program
							egy számot várt
	hiába élnek ezek a flagek az ios_base-n belül, az ios az ios_base-ből van származtatva, így simán elérhetjük
		az ios namespace-t használva, pl. std::ios::failbit

	az ios még biztosít számos tag funkciót is, hogy kényelmesen elérd ezeket az állapotokat
		
			member functions: good() - return true ha a stream rendben van
							  bad() - return true ha fatális hiba jelent meg
							  eof() - return true ha a stream a fájl végén van
							  fail() - return true ha nem fatális hiba jelent meg
							  clear() - töröl minden flaget és visszaállítja a streamet a goodbit statere
							  clear(state) - töröl minden flaget és beállítja a "state" flaget
							  rdstate() - visszaadja a jelenleg érvényben levő flageket
							  setstate(state) - beállítja a "state" flaget

	a leggyakoribb bit amivel találkozni lehet az a failbit, ez akkor jelenik meg ha helytelen az input
		- ha egy hiba megjelenik és a stream bármi másra van állítva mint a goodbit, bármilyen további stream
			művelet ignorálva lesz, ezt meglehet oldani a clear() funkcióval.

Input validation,
	az input validation nem más mint az a folyamat, hogy leellenőrízzük, hogy az input megfelel-e bizonyos
		követelményeknek
		- két típusba lehet bontani: string, numeric

	a string validation esetében minden user inputot elfogadunk mint string, és aztán elfogadjuk, vagy elvetjük
		azt a stringet, attól függően, hogy megfelelően van-e formatálva.
			pl. inputnak kérünk egy telefonszámot, és leellenőrízzük, hogy megvan-e az összes számjegye.

	a numerical validation esetében általában azzal foglalkozunk, hogy a szám bizonyos halmazba tartozik-e vagy sem
		- azonban itt figyelni kell azokra esetekre is amikor nem számot ad meg a felhasználó
		- a C++ számos hasznos funkciót biztosít, hogy megvizsgáljuk bizonyos karakterek számok-e vagy betük.
		- a <cctype> headerben találhatók
			isalnum(int) - visszaad nem-zérót ha a paraméter betű vagy szám
			isalpha(int) - visszaad nem-zérót ha a paraméter betű
			iscntrl(int) - visszaad nem zérót ha a paraméter egy kontrol karakter
			isdigit(int) - visszaad nem-zérót ha a paraméter szám
			isgraph(int) - visszaad nem-zérót ha a paraméter egy kiírható karakter ami nem whitespace
			isprint(int) - visszaad nem-zérót ha a paraméter egy kiírható karakter, beleértve a whitespacet
			ispunct(int) - visszaad nem-zérót ha a paraméter nem alphanumeric és nem is whitespace
			isspace(int) - visszaad nem-zérót ha a paraméter whitespace
			isxdigit(int) - visszaad nem-zérót ha a paraméter hexadecimális szám (0-9, a-f, A-F)

*/