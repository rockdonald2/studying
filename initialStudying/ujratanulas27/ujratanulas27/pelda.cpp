#include "stdafx.h"
#include <iostream>

int main()
{
	char ch11(97);
	std::cout << ch11 << std::endl;
	char ch12('a');
	std::cout << ch12 << std::endl;
	char ch13('b');
	std::cout << static_cast<int>(ch13) << std::endl;

	std::cout << "Irj be egy karaktert: ";
	
	// vegyük azt, hogy több mint egy karaktert ír be
	char ch14;
	std::cin >> ch14;
	std::cout << "Az " << ch14 << " karakternek az ASCII kódja: " << static_cast<int>(ch14) << std::endl;

	// ez a sor nem kér user input-ot, hanem a cin queue halmazából dolgozik, ha több mint 1 karaktert írt be
	//std::cin >> ch14;
	//std::cout << "Az " << ch14 << " karakternek az ASCII kódja: " << static_cast<int>(ch14) << std::endl;

	char32_t ch15('á');
	std::cout << ch15 << std::endl;
	
	return 0;

}