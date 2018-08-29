#include "pch.h"
#include <iostream>

/*

The protected access specifier,
	a védett hozzáférési pontosító engedélyezi minden olyan class számára a tagok eléréset amely vagy a class része,
		vagy friend class, vagy végül pedig az aki öröklési viszonyban áll.

		! úgyanakkor, akárcsak a private hozzáférés esetén, a védett hozzáférés esetén a tagok nem érhetők el a classon
			kivülről.

			lásd pl.


Different kind of inheritances, and their impact on access,
	- három féle öröklési mód van: public, private, protected
		- az alapértelmezett a private

	ez a három öröklési mód, a három hozzáférési pontosítóval 9 féle kombinációt alakít ki

	De mi a különbség közöttük?
		Dióhéjban, amikor egy tagot örökölünk, az örökölt classban az örökölt tag hozzáférést változtathat attól
			függően, hogy milyen öröklést választottunk


Public inheritance,
	messziről a legtöbbet használt öröklési mód
	a többi öröklési módot nagyon ritkán fogod használni, vagy soha
		! ezért ezt fontos megérteni, de ezt a legkönnyebb is

		- a public öröklés esetében minden tag ami public volt az is marad, szóval elérhető bárki által,
			minden tag ami privát volt, azaz elérhetetlen az is marad, és minden tag ami protected volt az is marad.


Private inheritance,
	a privát öröklés esetében, minden egyes örökölt tag hozzáférése privát lesz
		- azaz a privát privát marad, a public és protected priváttá válik

		 ! fontos megjegyezni, ez csak a classon kivülről érvényes amikor az adott származtatott classon keresztül
			próbálják elérni a tagot

			- nagyon ritkán használják


Protected inheritance,
	az utolsó öröklési mód, majdnem sohasem használják
	ez esetben a privát privát marad, a public és protected pedig protected lesz

*/