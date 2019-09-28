#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int factorial(int a) {
	if (a > 1) {
		return a * (factorial(a - 1));
	}
	else {
		return 1;
	}
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	/*double mean;
	cin >> mean;
	int k;
	cin >> k;
	const double e = 2.71828;

	double P = (pow(mean, k) * exp(-mean)) / factorial(k);

	cout << std::fixed << std::setprecision(3) <<  P << endl;*/

	double A;
	cin >> A;
	double B;
	cin >> B;

	double X = A + pow(A, 2);
	double Y = B + pow(B, 2);

	cout << 160 + 40 * (X) << endl;
	cout << 128 + 40 * (Y) << endl;

	return 0;
}