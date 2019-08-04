#include <iostream>
#include <string>
#include <vector>

// a regex vizsgalas nem veszi figyelembe azt a faktort, hogy nagy vagy kis beturol beszelunk
bool anyMatch(std::string str = "", std::string regEx = "") {
	if (regEx.find_first_of("/") != 0 && regEx.find_last_of("/") != regEx.length() - 1) {
		std::cout << "Invalid regular expression format!\n";
		return false;
	}

	// ha nem tartalmaz karakter settet akkor folytonosan vizsgalja a stringet
	bool continousSearch = true;

	if (regEx.find("[") != std::string::npos) {
		continousSearch = false;
	}

	// teljes szavakat probal megkeresni amit megadtunk a regex-ben, false-t terit ha nincs egyezes
	if (continousSearch) {
		if (str.find_first_of(regEx[1]) != std::string::npos) {
			std::size_t start = str.find_first_of(regEx[1]);
			std::size_t end = str.find_last_of(regEx[regEx.length() - 2]);

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
	}
	// ha nem folytonos keresesrol van szo mert tartalmaz karakter settet
	else {
		std::size_t openingBracketPos = regEx.find("[");
		std::size_t closingBracketPos = regEx.find("]");
		// nyilvantartjuk milyen hosszu a tenyleges charset, +1 mivel ha nincs benne akkor a vegso zaro jelet nem veszi bele
		std::size_t charSetLength = closingBracketPos - openingBracketPos + 1;
		// az egyezes vonatkozik, ha a karakter setben barmelyik karakter megtalalhato a stringben akkor a found == true
		bool found = false;

		// ha meghataroztuk a karakter setben a karaktereket amiket keresunk, azaz nem tartalmaz a-c-t pl.
		if (regEx.find("-") == std::string::npos) {
			for (std::string::const_iterator it = regEx.begin() + openingBracketPos + 1; it != regEx.end() - 2; ++it) {
				if (*it == str.at(openingBracketPos - 1)) {
					found = true;
					regEx.push_back(*it);
				}
			}

			// ha nem csak a karakter settet tartalmazza rekurziv modon vizsgalja a regex tobbi reszevel a stringet
			if (openingBracketPos == 1 && closingBracketPos == regEx.length() - 1) {
				return found;
			}
			else {
				// ha nem csak a karakter settet tartalmazza rekurziv modon vizsgalja a regex tobbi reszevel a stringet
				regEx.erase(openingBracketPos, charSetLength);
				regEx.insert(regEx.begin() + openingBracketPos, regEx[regEx.length() - 1]);
				regEx.erase(regEx.end() - 1);

				return anyMatch(str, regEx);
			}
		}

		else if (regEx.find(("^")) > openingBracketPos && regEx.find(("^")) != std::string::npos) {
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
		// egy karakter set amely olyan karaktereket tartalmaz amelyek nem jelenthetnek meg a stringben
		else if (regEx.find("-") != std::string::npos) {
			// ha egy halmazt adtunk meg a regex-ben
			std::string charSet = "";

			for (unsigned int it = int(regEx[openingBracketPos + 1]); it <= int(regEx[closingBracketPos - 1]); ++it) {
				charSet.push_back(char(it));
			}

			// megnezzuk hany karakternek kell megfeleljen a karakter set
			int charsToCompare = str.length();
			std::string missingChars; // hianyzo karakterek
			std::vector<std::size_t> indexOfPresentChars;
			int numOfCharsOutsideOfTheBrackets = 0;

			for (std::size_t itStr = 0, itRegEx = 1; itStr < str.length() - 1; ++itRegEx) {
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
			for (unsigned int i = 0, j = 0; i < charsToCompare; ++i) {
				if (j == indexOfPresentChars.size()) {
					while (i < charsToCompare) {
						missingChars.push_back(str[i]);
						++i;
					}

					break;
				}

				if (i == indexOfPresentChars[j]) {
					j++;
					continue;
				}
				else {
					missingChars.push_back(str[i]);
				}
			}

			// tenyleges ellenorzes
			std::string::const_iterator itCharSet = charSet.begin();
			for (std::size_t it = 0; it < charsToCompare;) {
				if (*itCharSet == missingChars[it]) {
					found = true;
					regEx.push_back(*itCharSet);
					++it;
				}
				else {
					++itCharSet;
				}

				/* a kurva nagy problema az, hogy resetelni kene az iterator minden egyes talalat eseten0*/
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
				regEx.erase(regEx.end() - 1);

				return anyMatch(str, regEx);
			}
		}
	}

	return true;
}

int main() {
	std::string str = "Match";
	std::string regEx = "/M[a-z]/";

	if (anyMatch(str, regEx)) {
		std::cout << "There's a match";
	}
	else {
		std::cout << "There's no match";
	}

	// ami hatravan: {n}, x | y, ^(kezdes), $(befejezes)
	// az a problema, hogy amikor tobb mint egy karaktert vizsgalunk a karakter setben pl. M[a-e]tch helyett M[a-z] akkor csak az elso karaktert hasonlitja, ebben az esetben az 'a'-t
	return 0;
}