#include <iostream>
#include <string>
#include <vector>
#include <utility>

int factorial(int a) {
	if (a > 1) {
		return a * factorial(a - 1);
	}
	else {
		return 1;
	}
}

// l - str starting index, r - str ending index
void permute(std::string str, int l, int r, std::vector<std::string>& temp) {
	// base case, if the two indeces are equal, push the string to the temp vector
	if (l == r) {
		temp.push_back(str);
	}
	else {
		for (int i = l; i <= r; ++i) {
			// swapping
			std::swap(str[l], str[i]);

			// permutation
			permute(str, l + 1, r, temp);

			// backswapping
			std::swap(str[l], str[i]);
		}
	}
}

// return true if there were any duplicates
bool checkDuplicate(std::string& str, int index, char& c) {
	std::string temp = str.substr(0, index).append(str.substr(index + 1, std::string::npos));

	if (temp.find(c) != std::string::npos) {
		return true;
	}
	else {
		return false;
	}
}

unsigned int noRepeats(std::string str) {
	int fact = factorial(str.length());

	// if str.length == 1 return 1
	if (str.length() == 1) {
		return 1;
	}

	// if all chars are the same, early exit with return value of 0
	unsigned int count = 0;
	for (std::string::iterator it = str.begin(); it != str.end() - 1; ++it) {
		if (*it == *(it + 1)) {
			++count;
		}
	}

	if (count == str.length() - 1) {
		return 0;
	}

	std::vector<std::string> temp;
	temp.reserve(fact);
	permute(str, 0, str.length() - 1, temp);

	int noRepeats = 0;
	for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); ++it) {
		bool repeat = false;

		for (unsigned int j = 0; j < (*it).length() - 1; ++j) {
			char c = (*it)[j];

			if ((*it)[j + 1] == c) {
				repeat = true;
			}

			if (repeat) {
				break;
			}
		}

		if (!repeat) {
			++noRepeats;
		}
	}

	return noRepeats;
}

int main() {
	std::string string = "a";
	std::cout << noRepeats(string) << "\n";

	std::cin.get();
	return 0;
}