#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseArray(vector<int> a) {
	int i = 0;
	int j = a.size() - 1;

	for (; i < a.size() / 2; ++i, --j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	return a;
}

int main()
{
	vector<int> v{ 1, 4, 3, 2 };

	vector<int> a = reverseArray(v);

	return 0;
}