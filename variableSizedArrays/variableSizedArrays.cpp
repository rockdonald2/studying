#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		a[i].reserve(k);
		for (int j = 0; j < k; ++j) {
			int temp;
			cin >> temp;
			a[i].push_back(temp);
		}
	}

	vector<pair<int, int>> queries(q);
	for (int i = 0; i < q; ++i) {
		cin >> queries[i].first >> queries[i].second;

		cout << a[queries[i].first][queries[i].second];
	}

	return 0;
}