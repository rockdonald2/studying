#include "pch.h"
#include <iostream>

/*

Az öröklés két class között jön létre, amelyből a class amiből örökölnek az a szülőclass, és ami örököl az a gyermekclass.

	Egy gyermek class örökli a szülő class tulajdonságait(tag változók), valamint viselkedését(tag funkciók)
		majd ezek a változók és funkciók tagjai lesznek a gyermek classnak.


		! de mivel a gyermek class is egy teljes értékű class, ezért rendelkezhetnek sajátos változókkal és funkciókkal is.




		lásd példa, egy átlagos ember reprezentálása,
			minden ember rendelkezik(nem törődve a nemmel, vagy foglalkozással) korral és névvel.
			azután ábrázoltunk egy baseball játékost az ütési átlag, és hazafutások által
				de szeretnénk neki nevet és kort is meghatározni, és ez esetben az öröklés a legjobb választás,
					mivel a Person class rendelkezik ezekkel a tulajdonságokkal


			ahhoz, hogy publikus öröklés hozzunk létre a class neve mellé teszünk egy kettőspontot, majd a 'public'
				kulcsszót végül az örökölni kivánt class nevét.

					- a publikus öröklés által a BaseballPlayer class megszerzi a Person class publikus tag változóit,
						illetve tag funkcióit.


Inheritance chains,
	lehetséges egy olyan classtól örökölni, ami már maga örökli egy másik class tulajdonságait.
*/