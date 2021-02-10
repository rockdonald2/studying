#include "pch.h"
#include <iostream>

/*

Non-type parameter,
	a template non-type parameter az egy speciális típusú paraméter amely nem egy típus helyettesítője,
		hanem ehelyett felcseréli egy értékkel.
		- egy non-type parameter a következők közül lehet:
			- egy érték aminek integral típusa van, vagy enum
			- egy mutató vagy hivatkozás egy class objectre
			- egy mutató vagy hivatkozás egy funkcióra
			- egy mutató vagy hivatkozás egy class tag funkcióra
			- std::nullptr_t

*/