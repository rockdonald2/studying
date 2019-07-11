#include <iostream>

char fearNoLetter(std::string str) {
	std::string strBackup = str;

	for (unsigned int letter = 0; letter < str.length() - 1; ++letter) {
		if ((++str[letter]) == strBackup[letter + 1]) {
			continue;
		}
		else {
			return str[letter];
		}
	}

	return NULL;
}

int main(void) {
	std::string str = "stvwx";

	std::cout << fearNoLetter(str) << "\n";

	return 0;
}