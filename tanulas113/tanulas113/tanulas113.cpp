#include "pch.h"
#include <iostream>

/*

Order of constructions,
	ebben a leckében a gyermekclass létrehozási sorrendjéről fogunk beszélni

	lásd pl.
		ebben az esetben a Derived class a származtatott, gyermek class,
		a Base class pedig a szülő class.

			mivel a Derived class örökli a Base class funkcióit, illetve változóit azt gondolnánk, hogy ezek
				átmásolódnak a Derived classba, pedig nem

				ehelyett gondoljunk úgy a Derived classra mint egy két részes classra: egyik rész Derived, másik Base


		- egyik normális, nem származtatott class esetében ugye a létrehozás úgy történik, hogy lefoglalja a memóriát
			a class számára, majd futassa az alapértelmezett konstruktőrt az inicializáláshoz
		- származtatott class esetében, ez kicsit másképp mükődik, először mindig kezdi a Base résszel a konstruktálást,
			majd így halad lefele amíg eléri a leglennébb levő gyermek classot

		szóval ha a példában látható Derived classot példáznánk, akkor először a Base class majd a Derived class
			konstruktálna.

*/