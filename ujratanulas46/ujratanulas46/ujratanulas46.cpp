#include "stdafx.h"
#include <iostream>

/*

typedefs,
	segítségével "becézni" lehet az adattípusokat
		sémája: typedef becézni_kivánt_adattípus becenév_t;
			pl: typedef short id_t;
				_t suffix fontos, így jobban megkülönböztethető, hogy az egy typedef.
*/

/*

sok helyzetben hasznosak,
	segít az olvashatóságban, mivel így a return értéknek kontextust ad.
	segít a kód karbantartásban, mivel segítségével nem kell több száz helyen típust változtatni egy egy változásnál, elég egy helyen.
	segít a platform független kód írásban, lásd learncpp.com-on a példát.
	fontos még, hogy segít bonyolult típusok leegyszerüsítésére, van egy hosszú nevü funkciód, adsz neki egy rövidebb nevet,
		így könnyebb megérteni, és dolgozni vele.

*/

/*

C+11-ben új syntax-ot vezettek be, a type aliast.
	a type alias segítségével bevezetel egy nevet ami szinonimaként fog szolgálni az adott típusnak.
		séma: using becenév_t = becézni_kivánt_típus;
				typedef becézni_kivánt_típus becenév_t; a kettő úgyanaz.

					ha lehet inkább ezt használd.

*/