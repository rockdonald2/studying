#include <iostream>
#include <string>

std::string reverseString(std::string str) {
	std::string newStr = "";

	for (int letter = str.length() - 1; letter >= 0; letter--) {
		newStr.push_back(str[letter]);
	}

	return newStr;
}

int main(void) {
	std::string str{ "hello" };

	std::cout << reverseString(str) << "\n";

	return 0;
}