#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> reverseArray(vector<int> a) {
	int i = 0;
	int j = a.size() - 1;

	for (; i < a.size() / 2; ++i, --j) {
		std::swap(a[i], a[j]);
	}

	return a;
}

int main()
{
	vector<int> v{ 1, 4, 3, 2 };

	vector<int> a = reverseArray(v);

	return 0;
}