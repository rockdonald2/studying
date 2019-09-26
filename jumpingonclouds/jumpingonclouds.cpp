#include <iostream>
#include <vector>

using namespace std;

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {

	int jumps = 0;

	for (size_t it = 0; it < c.size() - 1;) {
		if (it + 2 < c.size()) {
			if (c[it + 2] != 1) {
				++jumps;
				it += 2;
				continue;
			}
		}
		if (it + 1 < c.size()) {
			if (c[it + 1] != 1) {
				++jumps;
				it += 1;
				continue;
			}
		}
	}

	return jumps;
}

int main()
{
	int n = 10;
	vector<int> c{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 };
	cout << jumpingOnClouds(c) << endl;

	return 0;
}

