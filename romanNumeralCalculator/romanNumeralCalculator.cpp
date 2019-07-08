#include <iostream>

#include <string>

using namespace std;

string romanNumeralCalculator(int num) {
	int decimalArr[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string romanArr[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	unsigned int length = sizeof(decimalArr) / sizeof(decimalArr[0]);

	string roman = "";

	for (unsigned int index = 0; index < length; ++index) {
		while (decimalArr[index] <= num) {
			roman.append(romanArr[index]);
			num -= decimalArr[index];
		}
	}

	return roman;
}

int main(void) {
	cout << romanNumeralCalculator(125) << '\n';

	return 0;
}


