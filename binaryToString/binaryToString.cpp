#include <iostream>
#include <string>

int charToInt(char str) {
	int number = (int)str - 48;

	return number;
}

int calculateBinary(int binaryIndex, std::string binaryString) {
	return (charToInt(binaryString[binaryIndex]) * 128) + (charToInt(binaryString[binaryIndex + 1]) * 64) + (charToInt(binaryString[binaryIndex + 2]) * 32) + (charToInt(binaryString[binaryIndex + 3]) * 16) + (charToInt(binaryString[binaryIndex + 4]) * 8) + (charToInt(binaryString[binaryIndex + 5]) * 4) + (charToInt(binaryString[binaryIndex + 6]) * 2) + (charToInt(binaryString[binaryIndex + 7]) * 1);
}

std::string binaryToString(std::string binaryString) {
	std::string string;
	int length = binaryString.length();

	for (unsigned int index = 0; index < length - 1; index += 9) {
		string.append(1, char(calculateBinary(index, binaryString)));
	}

	return string;
}

int main(void) {
	std::string binaryString = "01000001 01110010 01100101 01101110 00100111 01110100 00100000 01100010 01101111 01101110 01100110 01101001 01110010 01100101 01110011 00100000 01100110 01110101 01101110 00100001 00111111";

	std::cout << binaryToString(binaryString) << std::endl;

	return 0;
}