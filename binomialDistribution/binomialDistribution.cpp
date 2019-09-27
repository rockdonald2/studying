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

//int main() {
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	double ratio;
//	cin >> ratio;
//	int odd;
//	cin >> odd;
//
//	// cout << ratio << " " << odd;
//
//	int numOfChildren = 6;
//	int n = 6;
//	double p = ratio / (1 + ratio);
//	double q = 1 - p;
//
//	double sum = 0.0;
//	for (unsigned int x = 3; x <= numOfChildren; ++x) {
//		sum += (combination(n, x) * pow(p, x) * pow(q, n - x));
//	}
//
//	cout << std::fixed << std::setprecision(3) << sum << endl;
//
//	return 0;
//}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	
	double percentage;
	cin >> percentage;
	int n;
	cin >> n;

	int max = 2;
	double p = (percentage / 100);
	double q = 1 - p;

	double sumNoMoreThanTwoRejects = 0.0;
	double sumAtLeastTwoRejects = 0.0;
	for (unsigned int x = 0; x <= max; ++x) {
		sumNoMoreThanTwoRejects += (combination(n, x) * pow(p, x) * pow(q, n - x));
	}

	for (unsigned int y = max; y <= n; ++y) {
		sumAtLeastTwoRejects += (combination(n, y) * pow(p, y) * pow(q, n - y));
	}

	cout << std::fixed << std::setprecision(3) << sumNoMoreThanTwoRejects << '\n' << sumAtLeastTwoRejects << endl;

	return 0;
}
