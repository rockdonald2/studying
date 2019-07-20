#include <iostream>

#include <string>

std::string rot13(std::string str) {
	for (unsigned int letter = 0; letter < str.length(); ++letter) {
		if (str[letter] >= 32 && str[letter] <= 47) {
			continue;
		}
		else if (str[letter] >= 48 && str[letter] <= 57) {
			continue;
		}
		else if (str[letter] >= 58 && str[letter] <= 64) {
			continue;
		}
		else if (str[letter] + 13 <= 90) {
			str[letter] = char(str[letter] + 13);
		}
		else if (str[letter] + 13 > 90) {
			str[letter] = char(((str[letter] + 13) - 90) + 64);
		}
		else {
			continue;
		}
	}


	return str;
}

int main(void) {
	std::string str = "GUR DHVPX OEBJA SBK WHZCF BIRE GUR YNML QBT.";

	std::cout << rot13(str) << "\n";

	return 0;
}