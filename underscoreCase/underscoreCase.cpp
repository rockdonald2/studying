#include <iostream>

#include <string>

std::string underscoreCase(std::string str) {

	for (unsigned int letter = 0; letter < str.length(); ++letter) {
		if (str[letter] >= 65 && str[letter] <= 90) {
			str[letter] = str[letter] + 32;
		}
		else if (str[letter] >= 97 && str[letter] <= 122) {
			continue;
		}
		else if (str[letter] == 32) {
			str[letter] = char(95);
		}
		else if (str[letter] >= 48 && str[letter] <= 57) {
			continue;
		}
		else {
			std::cerr << "Unknown character";
			return "-1";
		}
	}

	return str;
}

int main(void) {
	std::string str{ "5 principles of eternity" };

	std::cout << underscoreCase(str) << std::endl;

	return 0;
}