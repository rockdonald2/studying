#include "stdafx.h"
#include <iostream>
#include <cassert>

/*class IntList
{
private:
	int m_list[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:
	int& operator[] (const int index);
	const int& operator[] (const int index) const;
};

int& IntList::operator[] (const int index)
{
	assert(index >= 0 && index < 10 && "Hibas index");

	return m_list[index];
}

const int& IntList::operator[] (const int index) const
{
	assert(index >= 0 && index < 10 && "Hibas index");


	return m_list[index];
}

int main()
{
	IntList list;
	list[2] = 3;
	std::cout << list[2] << '\n';

	const IntList clist;
	std::cout << clist[2];

	return 0;
}*/

#include <string>
#include <vector>

struct StudentGrade
{
	std::string name;
	char grade;
};


class GradeMap
{
private:
	std::vector<StudentGrade> m_map;

public:
	GradeMap() { }

	char& operator[](const std::string &name);
};


char& GradeMap::operator[](const std::string &name)
{
	for (auto &s : GradeMap::m_map)
		if (s.name == name)
			return s.grade;

	StudentGrade temp{ name, ' ' };

	m_map.push_back(temp);

	return m_map.back().grade;
}

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}