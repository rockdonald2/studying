#include <iostream>

/*
GCD: greatest common divisor

	1. IF A=0 --> GCD(0, B) = B
	2. IF B=0 --> GCD(A, 0) = A
	3. A = B * Q + R
	4. GCD(A, B) == GCD(B, R)
	
*/

int gcd(int a, int b) {
	int r;
	// int q;

	if (a == 0)
		return b;
	if (b == 0)
		return a;
	r = a % b;
	// q = a / b;
	// a = b * q + r

	return gcd(b, r);
}


int main(void) {

	int divisor = gcd(5, 3);
	std::cout << divisor;

	return 0;
}