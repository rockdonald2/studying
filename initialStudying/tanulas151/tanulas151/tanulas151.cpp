#include "pch.h"
#include <iostream>

/*

Lásd pl.-ban a funkciót ahol dinamikusan helyeztünk el egy értéket
	- a funkció eléggé egyértelmű, azonban rengeteg esetben elég egyszerű elfelejteni felszabadítani a ptr mutatót
	- ez a probléma több más esetben is felléphet, a hanyagságon kivül, például a program korai befejezésével,
		ahol talán nem lett felszabadítva a mutató
		- a program korai befejezése történhet akár return-el, vagy egy kivételel.

	! a probléma szíve az, hogy a mutató változóknak nincsen beépített mechanizmusra arra, hogy maguk után
		takarítsanak, értsd felszabadítsák az adott memóriát

*/

/*

Smart pointer classes to the rescue?
	az egyik legjobb dolog a classokban az, hogy tartalmaznak destruktőröket amelyek automatikusan végrehajtódnak, 
		amikor az object kimegy scopeból, vagy kifejezetten törölik, egyszóval garantálja, hogy a lefoglalt memória
		a class object törlése után felszabadul.

	- szóval képesek vagyunk olyan classot létrehozni amely segít, hogy kezeljük és feltakarítsuk a mutatóinkat.

	lásd pl.
		- az ilyen classokat mint az Auto_ptr1 hívjuk smart pointereknek.
		- egy smart pointer egy kompozíciós class amelyet arra terveznek, hogy kezeljen dinamikusan elosztott memóriát
			és biztosítja, hogy a memória törlődik miután a smart pointer object kimegy a scopeból.

A critical flaw
	az Auto_ptr1 classnak van egy kritikus hibája
		lásd pl.
		- a probléma az, hogy mivel a classnak nem szolgáltattunk egy assignment operátort vagy copy constructort,
			C++ szolgáltat egyet nekünk, ami shallow copy-t csinál
		amikor inicializáljuk a res2-t a res1-el, mindkét object ugyanarra a Resource objectre mutat.
		amikor a res2 kimegy a scopeból, törlődik, hátrahagyva a res1-et egy dangling mutatóval
		amikor a res1 törölni akarja a már törölt memóriáját, crash.

		- ugyanez a probléma akkor ha érték általi továbbadást végzünk az objectekkel.

Ilyenkor merül fel a kérdés, hogy hogyan adjunk vissza egy Auto_ptr1-t a funkcióból a hívónak?
	
Move semantics,
	a move semantics azt jelenti, hogy a class átadja az object birtoklását ahelyett, hogy egy másolatot hozna létre.

	lásd Auto_ptr1 class

*/


/*

std::auto_ptr, and why to avoid it,
	az std::auto_ptr volt a C++ első próbálkozása arra, hogy standarizált smart pointert vezessen be
	- hasonlóan építette magába a move semantics-ot mint az Auto_ptr1 class

	ugyanakkor, mindkét classnak számtalan problémája van amik veszélyessé teszi őket
		elsőként, mivel az std::auto_ptr a move semantics-ot copy konstruktőr, illetve assignment operátor által
			építette be, egy std::auto_ptr átadása érték által egy funkcióhoz azt okozza, hogy a forrás a paraméterbe
			legyen mozgatva (aztán kitörölve a funkció végén, amikor a funkció paraméter kimegy scopeból)

		második, az std::auto_ptr mindig minden tartalmát a nem-array féle delete-el törli,
			így az std::auto_ptr nem fog megfelelően működni dinamikusan elhelyezett array-el

		utolsó, az std::auto_ptr nem működik megfelelően rengeteg más classal a standard libraryból

		- ezután a C++17-től teljesen kivették az std::auto_ptr-t a standard libraryból

*/