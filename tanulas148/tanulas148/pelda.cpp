#include "pch.h"
#include <iostream>

// 1
try
{
	openFile(filename);
	writeFile(filename, data);
	closeFile(filename);
}

catch (FileException &exception)
{
	cerr << "Failed to write to file: " << exception.what() << std::endl;

	// amikor writeFail dob egy kivételt, akkor a fájl kinyítása után a program lefolyása a catch handlerre ugrik,
		// azaz kiírja az üzenetet majd kilép, és a fájl sosem záródik be,
	// ezt kivételesen könnyen meglehet oldani ha a cerr elé beillesszük a closeFile(filename); hívást
}

// 2
try
{
	Person *john = new Person("John", 18, PERSON_MALE);
	processPerson(john);
	delete john;
}

catch (PersonException &exception)
{
	cerr << "Failed to process person: " << exception.what() << std::endl;

	// dinamikus elosztott memóriával ugyanez a helyzet
	// mikor a processPerson() dob egy kivételt, a program lefolyása a catch handlerre ugrik, john sose lesz
		// felszabadítva
	// ennek a megoldása trükkösebb, hiszen john a try blokkon belül lett létrehozva, így csak abban a scopeban elérhető
	// a catchen belül nincs, hogy felszabadítani
	// egyik megoldása ha john a try blokkon kivül hozzuk létre, így elérhető mind a try és catch számára
	// másik megoldása ha használunk egy olyan helyi változót egy classból ami tudja, hogy kell maga után
		// feltakarítani miután kilép a scopeból ( gyakran hívják smart pointernek, a standard libraryban található,
		// class std::unique_ptr) az std::unique_ptr az egy template class amely raktároz egy mutatót, és
		// felszabadítja miután kiment a scopeból
}