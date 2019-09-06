#include <iostream>
#include <vector>
#include <utility>

std::vector<int> bubbleSort(std::vector<int>& array) {
	bool swap = false;

	while (true) {
		swap = false;

		for (unsigned int it = 0; it < array.size() - 1; ++it) {
			if (array[it] > array[it + 1]) {
				std::swap(array[it], array[it + 1]);
				swap = true;
			}
		}

		if (!swap) {
			break;
		}
	}


	return array;
}

int main() {
	std::vector<int> vector = { 1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92 };
	std::vector<int> sortedVector = bubbleSort(vector);

	for (std::vector<int>::const_iterator it = sortedVector.begin(); it != sortedVector.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cin.get();
	return 0;
}
