#include "pch.h"
#include <iostream>
#include "IntArray.h"

int main(void)
{
	/*IntArray array(10);

	for (int index = 0; index < 10; ++index)
		array[index] = index + 1;

	array.resize(8);

	array.insertBefore(20, 5);

	array.remove(3);

	array.insertAtBeginning(30);
	array.insertAtEnd(50);

	for (int index = 0; index < array.getLength(); ++index)
		std::cout << array[index] << ' ';*/

	IntArray array { 1, 2, 3, 4, 5 };
	for (int index = 0; index < array.getLength(); ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

	array = { 5, 4, 3, 2, 1, 0, -1 };
	for (int index = 0; index < array.getLength(); ++index)
		std::cout << array[index] << ' ';
	
	return 0;

}