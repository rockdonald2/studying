#include "pch.h"
#include <iostream>

/*

A File I/O nagyon hasonlóan működik a normális I/O-hoz, némi hozzáadott kicsi komplexitással
	3 féle alapvető file I/O van: ifstream (istream-ből származtatott), ofstream (ostream-ből származtatott),
		fstream (iostream-ből származtatott)
		- ahhoz, hogy használd az file I/O classokat, szükséged van az <fstream> headerre
		
	nem úgy mint a cout, cin, clog, cerr streamek, amik készen állnak a használatra, a file streameket kifejezetten
		a programozók állítják fel, de ez nagyon egyszerű: 
			- ahhoz, hogy megnyiss egy fájlt írásra vagy olvasásra, simán példázol egy objectet a megfelelő
				file I/O classból, a file nevével paraméterként, aztán használod az insertion<< vagy extraction>>
					operátorokat, hogy írj vagy olvas adatot a fájlra/ről
			- miután végeztél több mód van arra, hogy bezárd a fájlt: kifejezetten lehívod a close() funkciót,
				vagy hagyod a file I/O változónak, hogy kimenjen a scopeból (ekkor a file I/O class destruktőrje
					bezárja a fájlt neked)

File output,
	lásd pl.

File input,
	használjuk azt a tényt, hogy az ifstream return 0 akkor ha elértük a fájl végét(EOF)

Buffered output, 
	a C++ az output talán bufferelve lehet, ez azt jelenti, hogy a file streambe való kiírás nem azonnal jön létre,
		hanem számos output műveletet összegyűjt és együtt kezeli, teljesítménybeli okok miatt
		amikor a buffer kiíródik a lemezre, ezt hívjük flush-nak
		- az egyik mód arra, hogy flusholjuk a buffert, hogy bezárjuk a fájlt

	- a buffering általában nem egy probléma, de néhány esetben problémát okozhat a figyelmetlennek.
		a probléma akkor jelentkezik ha adat van a bufferbe de a program hirtelen bezárul,
			ebben az esetben a file stream classok destruktőrje nem hívódik le, a fájl nem záródik be, nincs flush
			- ez esetben nincs kiírás a lemezre, az adat örökre elveszett

	- lehetséges manuális flusholni a buffert az ostream::flush() funkcióval, vagy az std::flush-t kiküldve
		az output streambe.

	fontos megjegyezni, hogy az std::endl is flusholja az output streamt, ezért a túl sokszori használata 
		teljesitménybeli problémákat okozhat
		- ezért használjuk sokszor az \n-t mert ez ugyan új sort ír ki, de nem flusholja a buffert, nincs
			teljesitménybeli veszteség

File modes,
	abban az esetben ha már egy olyan fájlra akarunk írni amely létezik, de a már meglévő adattal akarjuk összefüzni
		használjuk a file stream konstruktőrök opcionális másodlagos paramétert amely lehetővé teszi
			számodra, hogy meghatározz információkat arról, hogy hogyan szeretnéd megnyitni az adott fájlt.
			- ezeket a paramétereket hívjuk file mode-nak

			flagek amiket elfogad: app(összefüzés mód)
								   ate(bepillant a fájl végére mielőtt írna/olvasna)
								   binary(megnyitja a fájlt bináris módban)
								   in(megnyitja a fájlt read módban)
								   out(megnyitja a fájlt irási módban)
								   trunc(kitörli a fájlt ha már létezik)

							- lehet használni egyszerre többet OR|-al elválasztva

Explicitly opening files using open(),
	ahogy lehetséges kifejezetten bezárni a fájlt close()-al, úgy open()-el meg is jelent nyitni.

*/