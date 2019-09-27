#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	vector<long> v;
	v.reserve(n);
	for (int it = 0; it < n; ++it) {
		long temp;
		cin >> temp;
		v.push_back(temp);
	}

	int q1;
	cin >> q1;
	vector<int> q2;
	q2.reserve(2);
	int first;
	cin >> first;
	q2.push_back(first);
	int second;
	cin >> second;
	q2.push_back(second);

	if (q1 < v.size()) {
		v.erase(v.begin() + q1 - 1);
	}

	if (q2[0] < q2[1] && q2[1] < v.size()) {
		v.erase(v.begin() + q2[0] - 1, v.begin() + q2[1] - 1);
	}

	cout << v.size() << endl;
	for (vector<long>::const_iterator c = v.begin(); c != v.end(); ++c) {
		cout << *c << " ";
	}

	return 0;
}
