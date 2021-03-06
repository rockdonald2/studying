#include "stdafx.h"
#include <iostream>


/*

Association,
	ez egy olyan kapcsolat amely két egyébként egymáshoz nem viszonyuló object között jön létre,
		nem úgy mint az object kompozició esetén, itt nincs rész-egész viszony.


	Ahhoz, hogy társulás jöjjön létre, egy object és egy másik object között a következő viszony kell legyen:
		- az asszociált, társult object egyébként össze nem függő a másik objecttel
		- az asszociált object akár több objecthez is tartozhat
		- az asszociált object élettartamát nem az object kezeli
		- az asszociált object talán igen, talán nem tud a másik object létezéséről.

	! elmondható, hogy a tarsulás egy "használ egy" kapcsolat.



Implementing associations,
	mivel a tarsulás egy széles körű kapcsolatfajta, ezért rengeteg módon építhető be.
		Leggyakrabban mutatók segítségével vannak beépítve, ahol a mutató az asszociált objectre mutat.

		lásd pl. a doktor-páciens kapcsolatról.


Reflexive associations,
	néha objectnek lehet kapcsolata egy másik úgyanolyan típusú objecttel.
		ezt hívjuk reflexív társulásnak.


Associations can be indirect,
	nem muszáj mutatót használni ahhoz, hogy direkt módon csatoljunk két objectet össze.
		bármely adat ami képes két objectet összekötni megfelelő.

		lásd példa az autó parkolóval.


Summary,
	lásd táblázat a project mappában.

*/