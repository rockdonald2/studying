#include "stdafx.h"
#include <iostream>

/*

Command line arguments,
	The need for command line arguments,
		az eddig írt programok esetében, kivétel nélkül, a main() funkció nem fogadott be semmiféle paramétert,
			de a programozásban nagyon is szükség van arra, hogy paramétert adjunk át a main(), hogy tudja
			melyik fájlal/adatbázissal/bármivel kell dolgoznia.
			
				pl. ha egy olyan programot írunk amely Thumbnailt készít képfájlokból,
						ha manuálisan probáljuk beírni a fájlneveket rengeteg időt veszítünk, mint ha
							paraméterként adnánk meg a fájlnevét.

	a command line érvek, olyan opcíonális string érvek amelyeket az operácios rendszer által vannak továbbadva
		a programnak akkor amikor az elindul. A program használhatja ezeket mint input, vagy figyelmen kivül hagyhatja.
		Úgyanúgy ahogy a funkció paraméterek biztosítanak egy utat ahhoz, hogy a funkció biztosítson inputot egy másik funkciónak,
			a command line érvek biztosítanak egy útat az embereknek vagy programoknak, hogy biztosítsanak inputot egy programnak.

Passing command line arguments,
	ahhoz, hogy visual studioban command line érvet adj meg jobb klik a projektre, majd 'properties' majd ott 'debugging' és
		ott command arguments-be beírod. Ez automatikusan továbbadja a programodnak az érvet amikor futtatod.

Using command line arguments,
	egy különböző formájú main() használunk mint amit ezelőtt. Ez az új formájú main() két érvet fogad be, argc, és argv.

		int main(int argc, char *argv[])

		- ahol az argc(argument count), egy integer paraméter, amely tartalmazza az érvek számának számát amit továbbadnak
			a programnak. argc mindig legalább 1, mivel az első argument maga a program neve. Minden egyes command line érv
				tovább növeli az argc-t 1-el.
		- ahol az argv(argument values), az a hely ahol az aktuális érv értékeket tárolják. Argv csak egy C-style string array.
			Az argv array hossza az argc.

			lásd myArgs program.

*/


/*

Dealing with numeric arguments,
	a command line érveket mindig stringként adják tovább, még akkor is ha a biztosított érték szám.
		Ahhoz, hogy használjunk egy command line érvet mint szám, át kell alakítanunk stringből számmá.

		lásd pl.

The OS parses command line arguments first,
	az operációs rendszer mindig elemzi az érveket arra vonatkozóan, hogy hogyan kezelje őket és adja tovább a programnak.

	pl. ha egy érvben két " " közé helyezed a stringet az nem két érv lesz hanem csak egy, de ha két " " szeretnél kiírni
		akkor backslashhel kell megkülönböztetnek.

			pl. "Hello world!" - 1 string
				\"Hello world!\" - 2 string

*/

/*

Konkluzió,
	a command line érvek biztosítanak egy olyan módot arra, hogy a felhasználó vagy más program input adatot adjon át a programnak
		induláskor. Gondolj minden olyan input adatra amire szükség van induláskor command line paraméterként.
			Ha nincs command line továbbadva, mindig észreveheted, és kérheted a felhasználot input megadásra.
			Így a programod mindkét módon üzemelhet.

*/