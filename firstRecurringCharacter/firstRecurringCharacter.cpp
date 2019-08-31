#include <iostream>
#include <string>
#include <unordered_set>

char firstRecurringChar(std::string& str) {
	std::unordered_set<char> h; // a hash to contain the chars, duplicates are prohibited

	char c = str[0];
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == ' ') {
			continue;
		}

		c = *it;

		// if the character is in the hash return that as first recurring, if not insert it into the hash
		if (h.find(c) != h.end()) {
			return c;
		}
		else {
			h.insert(c);
		}
	}

	// fallback return
	return str[0];
}

int main() {
	std::string str{ "the quick brown fox jumps over the lazy dog" };

	std::cout << firstRecurringChar(str) << "\n";

	return 0;
}