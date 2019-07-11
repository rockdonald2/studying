#include <iostream>

int sumFibonacci(int higherBound) {
	int sum = 0;

	int firstTag = 1;
	int secondTag = 1;
	int thirdTag = 0;

	while (firstTag <= higherBound) {
		thirdTag = firstTag + secondTag;
		firstTag = secondTag;
		secondTag = thirdTag;
		if (firstTag == 1) {
			sum += 2;
		}
		else if (firstTag <= higherBound) {
			sum += firstTag;
		}
	}

	return sum;
}

int sumOddFibonacci(int higherBound) {
	int sum = 0;

	int firstTag = 1;
	int secondTag = 1;
	int thirdTag = 0;

	while (firstTag <= higherBound) {
		thirdTag = firstTag + secondTag;
		firstTag = secondTag;
		secondTag = thirdTag;
		if (firstTag == 1) {
			sum += 2;
		}
		else if (firstTag <= higherBound && (firstTag % 2 != 0)) {
			sum += firstTag;
		}
	}

	return sum;
}

int main(void) {
	int higherBound = 1000;

	std::cout << sumFibonacci(higherBound) << "\n";
	std::cout << sumOddFibonacci(higherBound) << "\n";

	return 0;
}