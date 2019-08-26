#include <iostream>

#include <vector>
#include <algorithm>

// returns the unique values from the two arrays sorted
std::vector<int> arrDiff(std::vector<int> arr1, std::vector<int> arr2) {

	for (std::vector<int>::const_iterator itI = arr2.begin(); itI != arr2.end();) {
		for (std::vector<int>::const_iterator itJ = arr1.begin(); itJ != arr1.end();) {
			if (*itI == *itJ) {
				itI = arr2.erase(itI);
				arr1.erase(itJ);
				itJ = arr1.begin();
				continue;
			}
			else {
				++itJ;
			}
		}
		++itI;
	}

	arr1.insert(arr1.end(), arr2.begin(), arr2.end());
	std::sort(arr1.begin(), arr1.end());

	return arr1;
}

int main(void) {
	std::vector<int> arr1{ 6, 5, 2, 9, 11, 24, 44 };
	std::vector<int> arr2{ 1, 4, 6, 7, 11, 22 };

	std::vector<int> uniqueArr = arrDiff(arr1, arr2);

	for (std::vector<int>::const_iterator it = uniqueArr.begin(); it != uniqueArr.end(); ++it) {
		std::cout << *it << ' ';
	}

	return 0;
}