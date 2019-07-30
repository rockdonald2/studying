#include <iostream>

#include <string>

using namespace std;

string searchAndReplace(string str, string before, string after) {
	int startIndex = -1;
	unsigned int i = 0;
	for (unsigned int letter = 0; letter < str.length(); ++letter) {
		if (str[letter] == before[i]) {
			if (startIndex == -1) {
				startIndex = letter;
			}

			i++;
		}
		else if (i == before.length()) {
			break;
		}
		else {
			startIndex = -1;
		}
	}

	if (startIndex != -1) {
		unsigned int j = 0;
		for (unsigned int letter = startIndex; letter < startIndex + after.length(); letter++) {
			str[letter] = after[j++];
		}

		if (after.length() > before.length()) {
			str.insert(startIndex + after.length(), " ");
		}

		if (str[startIndex + after.length()] != ' ') {
			str.erase(startIndex + after.length(), before.length() - after.length());
		}
	}

	return str;
}

int main(void) {
	string str = "The quick brown fox jumped over the lazy dog.";
	string before = "fox";
	string after = "bear";

	std::cout << searchAndReplace(str, before, after) << std::endl;

	return 0;
}