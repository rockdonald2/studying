#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int factorial(int x) {
	if (x > 1) {
		return x * (factorial(x - 1));
	}
	else {
		return 1;
	}
}

int combination(int x, int y) {
	return ((factorial(x)) / (factorial(y) * (factorial(x - y))));
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	double p;
	double tempX;
	cin >> tempX;
	double tempY;
	cin >> tempY;
	p = tempX / tempY;
	double q = 1 - p;

	int n;
	cin >> n;

	double sum = 0.0;
	for (int x = 1; x <= n; ++x) {
		sum += pow(q, n - x) * p;
	}

	cout << std::fixed << std::setprecision(3) << sum << endl;

	return 0;
}
