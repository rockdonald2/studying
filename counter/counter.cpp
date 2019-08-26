#include <iostream>
#include <string>

void counter(std::string str) {
	unsigned int sum = 0;
	int n = std::stoi(str);

	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}

	std::cout << "The number of 1s: " << sum << " \nThe number of 0s: " << str.length() - sum << " \n";
}

int main() {
	std::string str = "010001";
	counter(str);

	return 0;
}