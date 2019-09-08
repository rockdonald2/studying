#include <iostream>
#include <vector>
#include <utility>

int partition(std::vector<int>& array, int low, int high) {

	int pivot = array[high];

	int i = (low - 1);

	for (int j = low; j <= high - 1; ++j) {
		if (array[j] < pivot) {
			i++;
			std::swap(array[i], array[j]);
		}
	}

	std::swap(array[i + 1], array[high]);

	return (i + 1);
}

// low -- starting index && high -- ending index
std::vector<int>& quickSort(std::vector<int>& array, int low, int high) {

	if (low < high) {
		int pi = partition(array, low, high);

		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}

	return array;
}

int main() {
	std::vector<int> array = { 1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92 };
	std::vector<int> sortedArr = quickSort(array, 0, array.size() - 1);

	for (std::vector<int>::const_iterator it = sortedArr.begin(); it != sortedArr.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cin.get();
	return 0;
}