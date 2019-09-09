#include <iostream>
#include <vector>
#include <utility>

std::vector<int>& merge(std::vector<int>& arr, int left, int mid, int right) {
	// temp array to store the merged values
	std::vector<int> temp(right - left + 1, 0);

	// iterators for the arrays
	// i = start of divided array, j = end of divided array, k is for the temp
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			++k, ++i;
		}
		else {
			temp[k] = arr[j];
			++k, ++j;
		}
	}

	while (i <= mid) {
		temp[k] = arr[i];
		++k, ++i;
	}

	while (j <= right) {
		temp[k] = arr[j];
		++k, ++j;
	}

	for (i = left; i <= right; ++i) {
		arr[i] = temp[i - left];
	}

	return arr;
}

std::vector<int>& mergeSort(std::vector<int>& arr, int left, int right) {

	// continue 'til the low and high bounders are equal
	if (left < right) {

		// search for the middle index of the arr
		int mid = round((left + right) / 2);

		// call the mergeSort func for the first and second halves
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// then merge the two halves together
		merge(arr, left, mid, right);
	}

	return arr;
}

int main() {
	std::vector<int> array = { 1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92 };
	std::vector<int> sortedArr = mergeSort(array, 0, array.size() - 1);

	for (std::vector<int>::const_iterator it = sortedArr.begin(); it != sortedArr.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cin.get();
	return 0;
}