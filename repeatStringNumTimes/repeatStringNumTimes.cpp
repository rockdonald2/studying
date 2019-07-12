#include <iostream>
#include <string>

std::string repeatStringNumTimes(std::string str, int bound) {
	unsigned int counter = 1;

	std::string newStr{ "" };

	while (counter <= bound) {
		for (unsigned int letter = 0; letter < str.length(); ++letter) {
			newStr.push_back(str[letter]);
		}
		++counter;
	}

	return newStr;
}

int main(void) {
	std::string str{ "abc" };

	std::cout << repeatStringNumTimes(str, 3) << "\n";

	return 0;
}