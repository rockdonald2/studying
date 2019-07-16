#include <iostream>

int* selectionSort(int arr[], int length) {
	for (unsigned int startIndex = 0; startIndex < length - 1; ++startIndex) {
		int smallestIndex = startIndex;

		for (unsigned int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
			if (arr[currentIndex] < arr[smallestIndex]) {
				smallestIndex = currentIndex;
			}
		}

		std::swap(arr[startIndex], arr[smallestIndex]);
	}

	return arr;
}

int main(void) {
	int arr[5] = { 4, 1, 7, 8, 9 };
	int length = sizeof(arr) / sizeof(arr[0]);

	int* sortedArr = selectionSort(arr, length);

	for (unsigned int index = 0; index < length; ++index) {
		std::cout << sortedArr[index] << "\t";
	}

	return 0;
}