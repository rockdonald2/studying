#include "stdafx.h"
#include <iostream>

// Program: myArgs

int main(int argc, char *argv[])
{
	std::cout << "Tartalmaz " << argc << " ervet:\n";

	for (int szamlalo = 0; szamlalo < argc; ++szamlalo)
		std::cout << szamlalo << " " << argv[szamlalo] << '\n';

	return 0;
}