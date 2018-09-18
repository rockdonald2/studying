#include "pch.h"
#include <iostream>

/*

Virtual destructors,
	Habár, a C++ mindig biztosít számodra egy alapértelmezett destruktőrt ha te nem írsz egy sajátot, ami csak abban az esetben lényeges
		ha a classod dinamikusan elosztott memóriával dolgozik.

		! de fontos, minden esetben tedd virtuálissá a destruktőrödet ha örökléssel dolgozol.

		lásd pl.


Virtual assignment,
	képes vagy a hozzárendelési operátort is virtuálissá tenni, ez azonban nem mindig jó, nem úgy mint a virtuális destruktőr,
		ez egy haladó C++ téma.


Ignoring virtualization,
	nagyon ritkán talán mellőzni akarod a virtualizációt, ezt a scope resolution operátorral teheted meg amivel kifejezetten megmondod melyik
		funkciót akarod használni.

			lásd pl.

*/