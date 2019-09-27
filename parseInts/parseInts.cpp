#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	int lastInsert = 0;
	int numCounter = 0;
	vector<int> v;
	int num;
	char ch;

	for (size_t it = 0; it < str.size(); ++it) {
		if (int(str[it]) >= 48 && int(str[it]) <= 57 && it == (str.size() - 1)) {
			++numCounter;
			stringstream ss(str.substr(it - numCounter + 1, string::npos));
			numCounter = 0;
			ss >> num;
			v.push_back(num);
		}
		else if (int(str[it]) >= 48 && int(str[it]) <= 57) {
			++numCounter;
		}
		else if (str[it] == ',') {
			stringstream ss(str.substr(it - numCounter, numCounter));
			numCounter = 0;
			ss >> num;
			v.push_back(num);
		}
	}

	return v;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}