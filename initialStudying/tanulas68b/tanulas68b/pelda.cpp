#include "stdafx.h"
#include <iostream>

int main()
{
	char string[] = "Zsolt"; // normál c-style string
	const char *stringN = "Zsolt"; // c-style symbolic constant

	std::cout << string << ' ' << stringN << '\n'; // ez a kettő char*, vagy const char* -ba fog leépülni

	int sor[5] = { 1, 2, 3, 4, 5 };

	std::cout << sor << '\n'; // de ez int* -be.

		// másszóval char, és const char C-style string esetében nincs szükség dereference-re.

	return 0;

}