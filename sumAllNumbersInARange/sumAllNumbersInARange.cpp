#include <iostream>

#include <vector>

template <typename T>
T sumAll(std::vector<T> arr) {
	T sum{ 0 };

	T higherBound = (arr[0] > arr[1] ? arr[0] : arr[1]);
	T lowerBound = (arr[0] < arr[1] ? arr[0] : arr[1]);
	T numbersToSum = higherBound - lowerBound;

	for (T i = 0; i <= numbersToSum; i++) {
		sum += (lowerBound + i);
	}

	return sum;
}

double sumAll(std::vector<double> arr) {
	double sum = 0.0;

	double higherBound = (arr[0] > arr[1] ? arr[0] : arr[1]);
	double lowerBound = (arr[0] < arr[1] ? arr[0] : arr[1]);
	double numbersToSum = higherBound - lowerBound;

	for (double i = 0; i <= numbersToSum; i += 0.1) {
		sum += (lowerBound + i);
	}

	return sum;
}

int main(void) {
	std::vector<double> arr = { 4.5, 1.2 };

	std::cout << sumAll(arr);

	return 0;
}