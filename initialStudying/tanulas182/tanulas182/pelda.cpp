#include "pch.h"
#include <iostream>

//

#include <iomanip>

int main()
{
	using namespace std;

	char buff[10];
	cin >> buff;
		// mi történik ha 18-at írunk be? overflow
		// egyik megoldása a manipulator

	char buff1[10];
	cin >> setw(10) >> buff1;
		// így csak az első 9 karakter lesz kiolvasva a streamből(egyik hellyel a terminátorhoz)
		// bármely hátramaradt karakter bent lesz hagyva a streambe a következő kiolvasásig

	char ch;
	while (cin >> ch)
		cout << ch;
		// input: hello my name is
		// output: hellomynameis

	char ch1;
	while (cin.get(ch))
		cout << ch;
		// input: hello my name is
		// output: hello my name is

	char strBuff[11];
	cin.get(strBuff, 11);
	cout << strBuff << endl;
		// megakadályozza a buffer overflowját

	return 0;
}