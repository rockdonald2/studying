// sockMerchant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
	sort(ar.begin(), ar.end());

	int sum = 0;

	for (size_t i = 0; i < ar.size(); ++i) {
		int counter = 1;
		for (size_t j = i + 1; j < ar.size(); ++j) {
			if (ar[i] == ar[j]) {
				++counter;
			}
			else {
				i = (j - 1);
				break;
			}

			if (j + 1 == ar.size()) {
				i = (j - 1);
			}
		}

		sum += (counter / 2);
	}

	return sum;
}

int main() {
	int n = 10;
	vector<int> arr{ 1, 1, 3, 1, 2, 1, 3, 3, 3, 3 };
	cout << sockMerchant(n, arr) << endl;

	return 0;
}
