#include "pch.h"
#include <iostream>

/*

Ez egy a "gyémánt problémával" foglalkozó lecke,

The diamond problem,
	a gyémánt probléma megtekinthető a példában.
		- ebben az egyik fő probléma amit nehéz megérteni, hogy hány PoweredDevice másolata lesz a CopyMachine-nek?
		- valamint, hogy hogyan oldódnak meg a bizonyos adott kétértelmű hívások?


		mint ahogy a példából is kiderül a CopyMachine-nek két PoweredDevice másolata lesz, azaz az öröklési ábra nem is gyémánt alakú, sokkal inkább
			U, valahogy így:
					
						PoweredDevice	PoweredDevice
							||				||
							Scanner		Printer
							||				||
								CopyMachine


			a legtöbbször ez a kivánt struktúra, azonban vannak olyan esetek amikor csak egy PoweredDevice másolatot akarunk, ami közösen van megosztva
				a scanner és printer által.


Virtual base classes,
	ahhoz, hogy a származtatott classok megosszanak egy base classot, simán beilleszük a virtual kulcsszót az öröklési listába a származtatott classnál.
		- ezt hívjuk virtual base classnak, ami azt jelenti, hogy csak egy base object van ami megvan osztva a többi által.


		ez azonban felvet egy újabb kérdést? Ezután ki a felelős a PoweredDevice létrehozásáért?
			- mint kiderül a CopyMachine, és ez az egyik eset amikor egy származtatott class lehívhat egy nem-azonnali-szülő class konstruktőrjét.



Observations,
	1) minden virtual base class hamarább jön létre mint a non-virtual classok, ez bebiztosítja, hogy minden alap létezik mielőtt létrejönne egy
		származtatott object
	2) észrevehetjük, hogy a Scanner és Printer classokban még mindig megtalálható a PoweredDevice konstruktőrje, ez azonban ignorálva van
		a compiler által amikor egy CopyMachine objectet hozunk létre, de használva van amikor csak egy sima Scanner vagy Printer objectet.
	3) ha egy class olyan egy vagy több classtól örököl amelyeknek virtual base classa van, mindig a legszármaztatotabb classnak a felelőssége,
		hogy létrehozza a virtual base class objectet.
	4) egy virtual base class mindig közvetlen alapjának tekinthető a legszármaztatotabb classnak.

*/