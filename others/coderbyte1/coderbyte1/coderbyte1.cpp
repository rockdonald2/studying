#include "pch.h"
#include <iostream>
#include <string>
#include <cctype> // toupper()

using namespace std;

/*int FirstFactorial(int num)
{
	if (num > 1)
		return num * FirstFactorial(num - 1);
	if (num <= 1)
		return 1;
}

int main()
{
	cout << "Enter a number: ";
	int num{ 0 };
	cin >> num;


	std::cout << num << "! = " << FirstFactorial(num) << endl;

	return 0;
}*/

/*string LetterChanges(string &str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'z')
		{
			if (str[i] == 'z')
				str[i] = 'A';
			else if (str[i] == 'Z')
				str[i] = 'a';
			else
				++str[i];
		}
	}

	for (int j = 0; j < str.length(); ++j)
	{
		if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
		{
			str[j] = toupper(str[j]);
		}
	}

	return str;
}

int main()
{
	string str{ "hello*3" };
	string str2{ "fun times!" };
	string str3{ "Zolo kutza" };
	cout << LetterChanges(str);
	cout << '\n';
	cout << LetterChanges(str2);
	cout << '\n';
	cout << LetterChanges(str3);


	return 0;
}*/