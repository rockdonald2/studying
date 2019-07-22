#include <iostream>

#include <vector>
#include <algorithm>

int getIndexToIns(std::vector<int> arr, int num) {
	if (arr.empty()) {
		return 0;
	}

	std::sort(arr.begin(), arr.end());

	for (unsigned int index = 0; index < arr.size(); ++index) {
		if (arr[index] > num) {
			return index;
		}
		else {
			continue;
		}
	}

	return -1;
}

int main(void) {
	std::vector<int> arr{ 10, 20, 30, 40, 50 };
	int num = 35;

	std::cout << getIndexToIns(arr, num) << std::endl;

	return 0;
}