#include <iostream>
#include <vector>
#include <algorithm>

void doors(std::vector<int> &v) {
	std::cout << "Initial state" << std::endl;
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}

	//std::cout << "\nAfter toggling all elements" << std::endl;
	//for (auto& elem : v) {
	//	if (elem == 0) {
	//		elem = 1;
	//	}
	//	else if (elem == 1) {
	//		elem = 0;
	//	}
	//}
	//for (const auto& elem : v) {
	//	std::cout << elem << " ";
	//}

	//std::cout << "\nAfter toggling every second element" << std::endl;
	//for (size_t it = 2; it < 100; it += 2) {
	//	if (v[it] == 0) {
	//		v[it] = 1;
	//	}
	//	else if (v[it] == 1) {
	//		v[it] = 0;
	//	}
	//}
	//for (const auto& elem : v) {
	//	std::cout << elem << " ";
	//}

	//std::cout << "\nAfter toggling every third element" << std::endl;
	//for (size_t it = 3; it < 100; it += 3) {
	//	if (v[it] == 0) {
	//		v[it] = 1;
	//	}
	//	else if (v[it] == 1) {
	//		v[it] = 0;
	//	}
	//}
	//for (const auto& elem : v) {
	//	std::cout << elem << " ";
	//}

	for (unsigned int i = 0; i < 100; ++i) {
		for (unsigned int j = 0; j < 100; j += i + 1) {
			if (v[j] == 0) {
				v[j] = 1;
			}
			else if (v[j] == 1) {
				v[j] = 0;
			}
		}
	}

	std::cout << "\nAfter a hundred pass" << std::endl;

	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
}

int main() {
	std::vector<int> arr(100);
	std::fill(arr.begin(), arr.end(), 0);
	doors(arr);

	return 0;
}
