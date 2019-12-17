#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int l;
	cin >> l;
	vector<double> a(l);

	for (size_t it = 0; it < a.size(); ++it) {
		cin >> a[it];
	}

	sort(a.begin(), a.end());

	// mean calculation
	double s = 0;
	double d = 0;
	for (vector<double>::iterator it = a.begin(); it != a.end(); ++it) {
		s += *it;
	}
	d = s / a.size();

	// median calculation
	double m = 0;
	if (a.size() % 2 == 0) {
		m = (a[a.size() / 2] + a[a.size() / 2 - 1]) / 2;
	}
	else {
		m = a[a.size() / 2];
	}

	// mode calculation
	map<double, double> p;
	for (vector<double>::iterator it = a.begin(); it != a.end(); ++it) {
		if (p.find(*it) != p.end()) {
			p[*it] += 1;
		}
		else {
			pair<double, double> foo = make_pair(*it, 1);
			p.insert(foo);
		}
	}

	int h = (*p.begin()).first;
	for (map<double, double>::iterator it = p.begin(); it != p.end(); ++it) {
		if (p[h] < (*it).second) {
			h = (*it).first;
		}
	}

	cout << d << "\n" << m << "\n" << h << endl;

	return 0;
}
