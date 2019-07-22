#include <iostream>

#include <string>

bool confirmEnding(std::string str, std::string target) {
	int searchLength = target.length();
	bool verdict = false;

	for (int index = searchLength; index >= 0; --index) {
		if (str[str.length() - index] == target[target.length() - index]) {
			verdict = true;
		}
		else {
			return false;
		}
	}

	return verdict;
}

int main(void) {
	std::string str = "Confirm";
	std::string target = "m";

	std::cout << confirmEnding(str, target) << std::endl;

	return 0;
}