#include "pch.h"
#include <iostream>

int findFirstChar(const char* string, char ch)
{
	const std::size_t stringlength{ strlen(string) };

	// végignézi a string összes karakterét, ha megegyezik a ch-val visszaadja az indexet
	for (std::size_t index = 0; index < stringlength; ++index)
		if (string[index] == ch)
			return index;
	// ha nem talál egyezést, -1-et ad vissza
	return -1;
}