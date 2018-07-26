#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

/*struct StudentGrade
{
	std::string s_name;
	char s_grade;
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map;

public:
	GradeMap() {}

	char& operator[] (std::string name);
};

char& GradeMap::operator[] (std::string name)
{
	for (auto &student : m_map)
	{
		if (student.s_name == name)
			return student.s_grade;
	}

	StudentGrade temp{ name, ' ' };

	m_map.push_back(temp);

	return m_map.back().s_grade;
}

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}*/

class Mystring
{
private:
	std::string m_string;

public:
	Mystring(std::string string) : m_string(string)
	{

	}

	std::string operator() (int start, int length);
};


std::string Mystring::operator() (int start, int length)
{
	std::string temp;

	for (int count = 0; count < length; ++count)
	{
		temp += Mystring::m_string[count + start];
	}

	return temp;
}

int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7, 5); // start at index 7 and return 5 characters

	return 0;
}