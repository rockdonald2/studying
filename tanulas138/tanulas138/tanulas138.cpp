#include "pch.h"
#include <iostream>

/*

A 13.5-ös leckében található példában láttuk, hogy miként lehet a shallow copy-deep copy hibába esni mutatók esetében,
	általában ha mutató típust adunk be inputként akkor shallow copy jön létre, azaz ha töröljük az értéket,
	akkor a class object rossz memória címre fog mutatni(a copy és az input úgyanarra a címre mutat).

	- ezt a problémát nagyon jól meglehet oldani partial template specializationnal.
	- ezt ott full template specializationnal oldottuk meg, de az nem megfelelő, mert explicit módon megkell határoznunk
		a mutató típusát, ez minden típusra mükődik.

*/