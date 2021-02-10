#include "pch.h"
#include <iostream>

/*

Character access,
	két majdnem egyforma karakter elérési lehetőség van a stringhez, az at() funkció és az operátor[]

Conversion to C-style arrays,
	rengeteg funkciók, köztük az összes C funkció, a stringeket úgy várja el, hogy C-style stringgé legyenek alakítva
		és nem std::stringgé.
		ezért az std::string 3 különböző módot tesz lehetővé az átalakításra

*/