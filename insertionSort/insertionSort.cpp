#include <iostream>
#include <vector>
#include <utility>
#include <time.h>

std::vector<int>& insertionSort(std::vector<int>& array) {

	unsigned int count = 1;
	for (std::vector<int>::iterator itI = array.begin() + 1; itI != array.end(); ++itI, ++count) {
		for (std::vector<int>::iterator itJ = array.begin(); itJ <= itI - 1; ++itJ) {
			if (*itJ > * itI) {
				itJ = array.insert(itJ, *itI);
				itI = array.begin() + count;
				itI = array.erase(itI + 1) - 1;
				break;
			}
		}
	}

	return array;
}

int main() {
	std::vector<int> array = { 1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92 };
	std::vector<int> sortedArr = insertionSort(array);

	for (std::vector<int>::const_iterator it = sortedArr.begin(); it != sortedArr.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cin.get();
	return 0;
}