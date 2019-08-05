#include <iostream>
#include <string>
#include <vector>

// a regex vizsgalas nem veszi figyelembe azt a faktort, hogy nagy vagy kis beturol beszelunk
bool anyMatch(std::string str = "", std::string regEx = "") {
	if (regEx.find_first_of("/") != 0 || regEx.find_last_of("/") != regEx.length() - 1) {
		std::cout << "Invalid regular expression format!\n";
		return false;
	}

	// megnezzuk tartalmaz-e OR operatort a regEx
	if (regEx.find("|") != std::string::npos) {
		// ha tartalmaz a regEx-t kette valasztjuk es kulon rekurziv modon vizsgaljuk
		if (anyMatch(str, regEx.substr(regEx.find_first_of("/"), regEx.find_first_of("|")) + "/") | anyMatch(str, "/" + regEx.substr(regEx.find_first_of("|") + 1, regEx.find_last_of("/")))) {
			return true;
		}
		else {
			return false;
		}
	}


	// ha nem tartalmaz karakter settet akkor folytonosan vizsgalja a stringet
	bool continousSearch = true;

	if (regEx.find("[") != std::string::npos) {
		continousSearch = false;
	}

	// teljes szavakat probal megkeresni amit megadtunk a regex-ben, false-t terit ha nincs egyezes (tokeletesen mukodik eddig) !
	if (continousSearch) {
		if (str.find_first_of(regEx[1]) != std::string::npos) {
			std::size_t start = str.find_first_of(regEx[1]);
			std::size_t end = str.find_last_of(regEx[regEx.length() - 2]) + 1;

			std::size_t it = 1;
			while (start != end) {
				if (str[start] == regEx[it]) {
					++start;
					++it;
					continue;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}

	// ha nem folytonos keresesrol van szo mert tartalmaz karakter settet
	else {
		std::size_t openingBracketPos = regEx.find("[");
		std::size_t closingBracketPos = regEx.find("]");
		// nyilvantartjuk milyen hosszu a tenyleges charset, +1 mivel ha nincs benne akkor a vegso zaro jelet nem veszi bele
		std::size_t charSetLength = closingBracketPos - openingBracketPos + 1;
		// az egyezes vonatkozik, ha a karakter setben barmelyik karakter megtalalhato a stringben akkor a found == true
		bool found = false;

		// egy karakter set amely olyan karaktereket tartalmaz amelyek nem jelenthetnek meg a stringben
		if (regEx.find(("^")) > openingBracketPos && regEx.find(("^")) != std::string::npos) {
			std::string charSet = "";

			for (unsigned int it = int(regEx[openingBracketPos + 2]); it <= int(regEx[closingBracketPos - 1]); ++it) {
				charSet.push_back(char(it));
			}

			for (std::string::const_iterator it = charSet.begin(); it != charSet.end(); ++it) {
				if (*it != str.at(openingBracketPos - 1)) {
					found = true;
				}
				else {
					found = false;
				}
			}

			return found;
		}

		// ha olyan karakter settrol van szo amely nem tartalmazza a !not(^) jelet
		// ha meghataroztuk a karakter setben a karaktereket amiket keresunk, azaz nem tartalmaz a-c-t pl.
		std::string charSet;

		for (unsigned int it = int(regEx[openingBracketPos + 1]); it <= int(regEx[closingBracketPos - 1]); ++it) {
			charSet.push_back(char(it));
		}

		// megnezzuk hany karakternek kell megfeleljen a karakter set
		int charsToCompare = str.length();
		std::string missingChars; // hianyzo karakterek
		std::vector<std::size_t> indexOfPresentChars;
		int numOfCharsOutsideOfTheBrackets = 0;

		// felirja a jelenlevo karakterek indexet
		for (std::size_t itStr = 0, itRegEx = 1; itStr < str.length(); ++itRegEx, ++itStr) {
			if (str[itStr] == regEx[itRegEx]) {
				++numOfCharsOutsideOfTheBrackets;
				indexOfPresentChars.push_back(itStr);
				continue;
			}
			else if (regEx[itRegEx] == '[') {
				itRegEx = closingBracketPos;
			}
			else if (itRegEx == regEx.length() - 1) {
				break;
			}
		}

		charsToCompare -= numOfCharsOutsideOfTheBrackets;
		std::vector<std::size_t>::const_iterator i = indexOfPresentChars.begin(); // egy iterator az indexOfPresentChars-hoz
		for (std::size_t it = 0; it < str.length(); ++it) {

			// abban az esetben ha ures a vector
			if (indexOfPresentChars.empty()) {
				while (it < str.length()) {
					missingChars.push_back(str[it]);
					++it;
				}

				break;
			}

			// abban az esetben ha csak egyetlen indexet tartalmaz a vector
			if (*i == it && i == indexOfPresentChars.end() - 1) {
				++it;
				while (it < str.length()) {
					missingChars.push_back(str[it]);
					++it;
				}

				break;
			}
			

			// maskepp hozzaadja a missingChars vectorhoz a hianyzo karaktereket
			if (*i == it) {
				++i;
				continue;
			}
			else {
				missingChars.push_back(str[it]);
			}
		}

		// tenyleges ellenorzes
		std::string::const_iterator itCharSet = charSet.begin();
		for (std::size_t it = 0; it < charsToCompare;) {
			if (*itCharSet == missingChars[it]) {
				found = true;
				regEx.push_back(*itCharSet);
				++it;
				itCharSet = charSet.begin();
			}
			else {
				++itCharSet;
			}
		}

		// ha nem volt egyetlen egyezes sem teriti a found-ot ami == false
		if (!found) {
			return found;
		}

		if (openingBracketPos == 1 && closingBracketPos == regEx.length() - 2) {
			return found;
		}
		else {
			// ha nem csak a karakter settet tartalmazza rekurziv modon vizsgalja a regex tobbi reszevel a stringet
			regEx.erase(openingBracketPos, charSetLength);
			regEx.insert(openingBracketPos, regEx.substr(regEx.find_last_of("/") + 1));
			regEx.erase(regEx.find_last_of("/") + 1);

			return anyMatch(str, regEx);
		}
	}

	return true;
}

int main() {
	std::string str = "Match";
	std::string regEx = "/Match|Catch/";

	if (anyMatch(str, regEx)) {
		std::cout << "There's a match";
	}
	else {
		std::cout << "There's no match";
	}

	// ami hatravan: {n}, ^(kezdes), $(befejezes)
	return 0;
}