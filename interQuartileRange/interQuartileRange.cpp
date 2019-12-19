#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int l;
	cin >> l;
	vector<double> a(l);
	vector<double> w(l);

	double Q1, Q2, Q3;

	for (size_t it = 0; it < a.size(); ++it) {
		cin >> a[it];
	}

	for (size_t it = 0; it < w.size(); ++it) {
		cin >> w[it];
	}

	vector<double> wa;
	int i = 0;

	for (size_t it = 0; it < a.size(); ++it) {
		while (w[i] != 0) {
			wa.push_back(a[it]);
			--w[i];
		}

		++i;
	}

	sort(wa.begin(), wa.end());

	if (wa.size() % 2 == 0) {
		Q2 = (wa[wa.size() / 2] + wa[wa.size() / 2 - 1]) / 2;

		vector<double> lower(wa.begin(), wa.begin() + (wa.size() / 2));
		vector<double> upper(wa.begin() + (wa.size() / 2) + 1, wa.end());

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
	else if (wa.size() % 2 != 0) {
		Q2 = wa[wa.size() / 2];

		vector<double> lower(wa.begin(), wa.begin() + trunc(wa.size() / 2));
		vector<double> upper(wa.begin() + trunc(wa.size() / 2) + 1, wa.end());

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


	cout << fixed << setprecision(1) << Q3 - Q1 << endl;


	return 0;
}
