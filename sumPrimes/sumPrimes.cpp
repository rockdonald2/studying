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
		a pr�msz�m meghat�roz�s m�dszere: kerek�tj�k a higherBound sz�m gy�k�t, majd a higherBound-ot osztani kezdj�k a kerek�tett sz�mmal, majd -1, -2, �gy tov�bb
			ha mindegyik oszt�s marad�kos a sz�m pr�msz�m
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