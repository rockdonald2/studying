#include <iostream>

#include <vector>

int gcd(int a, int b) {
	int r = 0;

	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}

	r = a % b;

	return gcd(b, r);
}

std::vector<int> selectionSort(std::vector<int> arr) {
	std::vector<int> newArr = arr;

	for (unsigned int startIndex = 0; startIndex < arr.size() - 1; ++startIndex) {
		unsigned int lowestIndex = startIndex;

		for (unsigned int currentIndex = startIndex + 1; currentIndex < arr.size(); ++currentIndex) {
			if (arr[currentIndex] < arr[lowestIndex]) {
				lowestIndex = currentIndex;
			}
		}

		std::swap(newArr[startIndex], newArr[lowestIndex]);
	}

	return newArr;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

std::vector<int> lcmArr(std::vector<int> arr) {
	std::vector<int> newArr;

	for (unsigned int index = 0; index < arr.size() - 1; ++index) {
		newArr.push_back(lcm(arr[index], arr[index + 1]));
	}

	return newArr;
}

int scm(std::vector<int> arr) {
	std::vector<int> newArr;

	if (arr[0] > arr[1]) {
		int c = arr[0];

		while (c >= arr[1]) {
			newArr.push_back(c);
			--c;
		}
	}
	else {
		int c = arr[1];

		while (c >= arr[0]) {
			newArr.push_back(c);
			--c;
		}
	}

	std::vector<int> sortedArr = selectionSort(newArr);
	unsigned int count = 0;
	std::vector<int> finalArr = sortedArr;
	while (count < sortedArr.size() - 1) {
		finalArr = lcmArr(finalArr);
		++count;
	}

	return finalArr[0];
}

int main(void) {
	std::vector<int> arr{ 5, 1 };

	std::cout << scm(arr) << std::endl;

	return 0;
}