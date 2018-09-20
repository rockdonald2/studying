#include "pch.h"
#include <iostream>

/*

Pure virtual(abstract) functions, and abstract base classes,
	Minden virtuális funkció amit eddig írtunk tartalmazott body-t.
	Azonban a C++ lehetőséget ad olyan virtuális funkció létrehozására is aminek nincs body-ja, ez lényegében csak egy helyfoglaló funkciót,
		ami arra szolgáltatott, hogy a származtatott classok által felülírva legyen.
		! ezt hívjuk pure virtual function-nak

		- ahhoz, hogy létrehozzunk egy pure virtual functiont, ahelyett, hogy meghatároznánk a body-ját, a funkciót simán egyenlővé tesszük 0-val.	

		a pure virtual function használatának két fő következménye van:
			1) olyan classokat amelyek egy vagy több pure virtual functiont használnak abstract base classoknak hívunk, amelyeket nem lehet példázni.
			2) minden származtott classnak megkell határoznia a body-ját ennek a funkciónak,
				ha nem teszik meg akkor azokat is abstract base classnak kell tekinteni.


		példa

			- a példában megfigyelhető, hogy két abstract base class van: Animal és Cow.
			- mind a kettő tartalmaz pure virtual function, az első szándékosan, a második mert nem írtuk felül a speak() funkciót
			- amíg abstract base classok addig nem lehet őket példázni, azaz objectet létrehozni a classból.


Pure virtual functions with bodies,
	lehetséges olyan pure virtual function-et létrehozni amik tartalmaznak body-t, azonban ez a body nem lehet ugyanazon a helyen meghatározva,
		mint ahol deklaráltuk a pure virtual functiont, hanem a classon kivül.
	- nincs nagyon gyakran használva, azt a célt szolgálja, hogy a base class szolgáltasson egy fajta alapértelmezett beépítést a funkcióhoz,
		de még mindig kényszerítve a származtatott classokat, hogy a saját verziójukat is építsék be, de ha valamelyik származtatott
			classnak megfelelő az alapértelmezett, csak returnolja azt.

Interface classes,
	egy interfész class az egy olyan class aminek nincs saját tag változója, és minden egyes funkciója pure virtual function.
	ezek a classok akkor hasznosak amikor meg akarsz határozni egy alapértelmezett funkcionalítást amit a származtatott classok muszáj beépítsenek,
		de a tényleges kivitelezést mindig a származtatott classra bízod.

		! általában az ilyen classok neve nagy I betűvel kezdődik.
		! ne felejts el az ilyen classokhoz virtuális destruktőrt mellékelni, hogy a megfelelő destruktőr legyen mindig lehívva.

*/