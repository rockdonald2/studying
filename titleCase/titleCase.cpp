#include <iostream>

std::string titleCase(std::string str) {

	for (unsigned int letter = 0; letter < str.length(); ++letter) {
		if (str[letter] == ' ') {
			continue;
		}
		else if (str[letter] >= 65 && str[letter] <= 90 && letter == 0) {
			continue;
		}
		else if (str[letter] >= 65 && str[letter] <= 90 && str[letter - 1] == ' ')
		{
			continue;
		}
		else if (str[letter] >= 65 && str[letter] <= 90 && str[letter - 1] != ' ') {
			str[letter] = str[letter] + 32;
		}
		else if (str[letter] >= 97 && str[letter] <= 122 && letter == 0) {
			str[letter] = str[letter] - 32;
		}
		else if (str[letter] >= 97 && str[letter] <= 122 && str[letter - 1] == ' ') {
			str[letter] = str[letter] - 32;
		}
	}

	return str;
}

int main(void) {
	std::string str = "I'm a little tea pot";

	std::cout << titleCase(str) << "\n";

	return 0;
}