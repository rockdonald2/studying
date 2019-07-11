#include <iostream>

#include <cmath>

bool isPrime(double number) {
	if (number == 1) {
		return false;
	}

	double m;

	m = round(sqrt(number));

	while (m >= 2) {
		if (!(round(number / m) == (number / m))) {
			m--;
		}
		else {
			return false;
		}
	}

	return true;
}

double sumPrimes(double higherBound) {
	double sum = 0;

	/*
		a prímszám meghatározás módszere: kerekítjük a higherBound szám gyökét, majd a higherBound-ot osztani kezdjük a kerekített számmal, majd -1, -2, így tovább
			ha mindegyik osztás maradékos a szám prímszám
	*/
	
	while (higherBound >= 1) {
		if (isPrime(higherBound)) {
			sum += higherBound;
			--higherBound;
		}
		else {
			--higherBound;
		}
	}

	return sum;
}

int main(void) {
	double higherBound = 10;

	std::cout << sumPrimes(higherBound) << std::endl;

	return 0;
}