#include "pch.h"
#include <iostream>

/*

The need for function templates,
	szóval, röviden a funkció templatekre azért van szükség, hogy létrehozzunk egy olyan funkciót amely BÁRMELY paraméter típussal
		müködik.

		- így megelőzve a duplikált kódot, illetve a karbantartási gondokat

*/

/*

What is a function template?
	a C++-ban a template olyan funkciók amelyek mintaként szolgálnak ahhoz, hogy más hasonló funkciókat hozzunk létre
	az alapvető ötlet a templatek mögött az, hogy létrehozzunk egy funkciót anélkül, hogy megkelljen pontosan határoznunk néhány
		vagy akár az összes változójának a típusát.
		- helyettesítő típusokat használunk a valódi típusok helyett, amiket template type parametersnek nevezünk
		! annyi type parameterre van szükség ahány különböző adattípus van használva
*/

/*

Creating function templates,
	lásd pl.
		! mielőtt meghatároznád a template funkciódat, létrekell hoznod egy template paramater declaration-t.
		sémája: template <typename T1, typename T2, ...> // a T a helyettesítő típus, ez bármi lehet.

*/