#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int l;
	cin >> l;
	vector<double> a(l);

	double Q1, Q2, Q3;

	for (size_t it = 0; it < a.size(); ++it) {
		cin >> a[it];
	}

	sort(a.begin(), a.end());

	if (l % 2 == 0) {
		Q2 = (a[a.size() / 2] + a[a.size() / 2 - 1]) / 2;

		vector<double> lower(a.begin(), a.begin() + (l / 2));
		vector<double> upper(a.begin() + (l / 2), a.end());

		if (lower.size() % 2 == 0) {
			Q1 = (lower[lower.size() / 2] + lower[lower.size() / 2 - 1]) / 2;
		}
		else {
			Q1 = lower[lower.size() / 2];
		}

		if (upper.size() % 2 == 0) {
			Q3 = (upper[upper.size() / 2] + upper[upper.size() / 2 - 1]) / 2;
		}
		else {
			Q3 = upper[upper.size() / 2];
		}
	}
	else if (l % 2 != 0) {
		Q2 = a[l / 2];

		vector<double> lower(a.begin(), a.begin() + trunc(l / 2));
		vector<double> upper(a.begin() + trunc(l / 2) + 1, a.end());

		if (lower.size() % 2 == 0) {
			Q1 = (lower[lower.size() / 2] + lower[lower.size() / 2 - 1]) / 2;
		}
		else {
			Q1 = lower[lower.size() / 2];
		}

		if (upper.size() % 2 == 0) {
			Q3 = (upper[upper.size() / 2] + upper[upper.size() / 2 - 1]) / 2;
		}
		else {
			Q3 = upper[upper.size() / 2];
		}
	}
	else {
		return -1;
	}


	cout << Q1 << "\n" << Q2 << "\n" << Q3 << endl;


	return 0;
}
