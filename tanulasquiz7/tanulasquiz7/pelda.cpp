#include "stdafx.h"
#include <iostream>


#include <assert.h>
/*int binarySearch(int *array, int celpont, int min, int max)
{
	assert(array);

	while (min <= max)
	{
		int arrayKozep = min + ((max - min) / 2);

		if (array[arrayKozep] > celpont)
		{
			max = arrayKozep - 1;
		}
		else if (array[arrayKozep] < celpont)
		{
			min = arrayKozep + 1;
		}
		else
			return arrayKozep;
	}

	return -1;

}*/

/*int binarySearch(int *array, int celpont, int min, int max)
{
	assert(array);

	if (min > max)
		return -1;

	int arrayKozep = min + ((max - min) / 2);

	if (array[arrayKozep] > celpont)
	{
		return binarySearch(array, celpont, min, arrayKozep - 1);
	}
	else if (array[arrayKozep] < celpont)
	{ 
		return binarySearch(array, celpont, arrayKozep + 1, max);
	}
	else
		return arrayKozep;
}*/

int main()
{
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	const int tesztErtekekSzama = 9;

	int tesztErtekek[tesztErtekekSzama] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };

	int vartErtekek[tesztErtekekSzama] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	for (int szamlalo = 0; szamlalo < tesztErtekekSzama; ++szamlalo)
	{
		int index = binarySearch(array, tesztErtekek[szamlalo], 0, 14);

		if (index == vartErtekek[szamlalo])
			std::cout << "a teszt ertek " << tesztErtekek[szamlalo] << " atment!\n";
		else
			std::cout << "a teszt ertek " << tesztErtekek[szamlalo] << " nem ment at! Valami baj van a kododdal!\n";
	}

	return 0;
}