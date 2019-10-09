#include <iostream>

long func(long x) {
	if (x < 10) return x + 1;

	long a = x % 10 + 1;
	long b = func(x / 10) * 10;
	return (a == 10 ? (b + 1) * 10 : b + a);
}

int main() {
	std::cout << func(293) << std::endl;

	return 0;
}