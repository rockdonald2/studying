//#include <vector>
//#include <memory>
//#include <iterator>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main() 
//{
//	ifstream file("sample.txt");
//	string fileData;
//	if (file)
//	{
//		fileData.append((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
//
//		cout << fileData << '\n';
//	}
//	else
//		cout << "Couldn't be opened for copying\n";
//
//	ofstream oFile("oSample.txt");
//	if (oFile)
//	{
//		ostreambuf_iterator<char> outPutToFile(oFile);
//		copy(fileData.begin(), fileData.end(), outPutToFile);
//	}
//	else
//		cout << "Couldn't be opened for writing\n";
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool isDivisibleWith5(int number)
{
	return ((number % 5) == 0);
}

int main()
{
	typedef vector<int> IVC; // IVC = INT VECTOR CONTAINER
	typedef vector<int>::iterator IVCi; // IVCi = IVC iterator

	IVC data;
	data.reserve(100);
	cout << "In the beginning the capacity of data is: " << data.capacity() << " and the size is: " << data.size() << '\n';

	// fill up the IVC
	for (size_t i = 0; i < data.capacity(); ++i)
		data.push_back((((i + 2) * 10) / 5));

	// print the IVC
	for (size_t i = 0; i < data.size(); ++i)
		cout << data[i] << ' ';

	// partition data, number divisible with 5 precedes any other
	IVCi goodEnd;
	for (unsigned int i = 0; i < data.size(); ++i)
		goodEnd = partition(data.begin(), data.end(), isDivisibleWith5);

	// erase number divisible with 5
	data.erase(data.begin(), goodEnd);

	// print the IVC
	cout << '\n';
	for (size_t i = 0; i < data.size(); ++i)
		cout << data[i] << ' ';

	return 0;
}