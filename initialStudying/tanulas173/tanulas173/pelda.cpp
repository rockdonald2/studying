#include "pch.h"
#include <iostream>

//
#include <string>

int main()
{
	// size_type string::length() const
	// size_type string::size() const
		// mind a két funkció visszaadja a karakterek számát a stringben, a NULL terminátor kivételével
	std::string sSource("012345678");
	std::cout << sSource.length() << std::endl;

	// bool string::empty() const
		// ugyan lehet használni a length() funkciót is, hogy megtud-e van-e bármilyen karakter a stringben vagy sem
		// sokkal hatékonyabb erre a célra az empty() funkció, true ha üres a string, false ha nem
	std::string sSource1("Not empty");
	std::cout << (sSource1.empty() ? "true" : "false") << std::endl;
	std::string sSource2; // üres
	std::cout << (sSource2.empty() ? "true" : "false") << std::endl;

	// size_type string::max_size() const
		// visszaadja a max karakter számot amit a string birtokolhat
		// változni fog: függ az op. rendszertől és a rendszer architektúrájától
	std::string sSource3("MyString");
	std::cout << sSource3.max_size() << std::endl;

	// size_type string::capacity() const
		// visszaadja azt a karakter számot amelyet a string még birtokolni tud újraelosztás nélkül
	std::string sSource4("01234567");
	std::cout << sSource4.length() << std::endl;
	std::cout << sSource4.capacity() << std::endl;

	// void string::reserve()
	// void string::reserve(size type_unSize)
		// a második változata a funkciónak a kapacítást minimum az unSize értékre teszi, de lehet nagyobb is
		// ez talán igényelhet újraelosztást
		// az első változata a funkciónak pedig megpróbálja összehúzni a kapacítást, hogy megegyezzen a hosszal.
		// azonban ez nem kötelező érvényű, lehet nem jön létre
	std::string sSource5("01234567");
	std::cout << "Length: " << sSource5.length() << std::endl;
	std::cout << "Capacity: " << sSource5.capacity() << std::endl;

	sSource5.reserve(200);
	std::cout << "Length: " << sSource5.length() << std::endl;
	std::cout << "Capacity: " << sSource5.capacity() << std::endl;

	sSource5.reserve();
	std::cout << "Length: " << sSource5.length() << std::endl;
	std::cout << "Capacity: " << sSource5.capacity() << std::endl;
	return 0;
}