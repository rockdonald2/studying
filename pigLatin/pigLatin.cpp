#include <iostream>

#include <string>

bool checkConsonant(char str) {
	switch (str) {
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
	case 'i':
	case 'I':
		return false;

	default: return true;
	}
}

std::string translatePigLatin(std::string str) {
	std::string newStr;

	int consonantCluster = 0;

	for (unsigned int letter = 0; letter < str.length(); ++letter) {
		if (checkConsonant(str[letter])) {
			consonantCluster++;
		}
		else {
			break;
		}
	}

	if (consonantCluster == 0) {
		return str.append("way");
	}

	for (unsigned int count = consonantCluster; count < str.length(); ++count) {
		newStr.push_back(str[count]);
	}

	for (unsigned int count = 0; count < consonantCluster; ++count) {
		newStr.push_back(str[count]);
	}

	return newStr.append("ay");
}

int main(void) {
	std::string str{ "Eightway" };

	std::cout << translatePigLatin(str) << "\n";

	return 0;
}