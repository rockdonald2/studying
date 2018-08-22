#include "pch.h"
#include <iostream>
#include <string>

class Person
{
public:
	std::string m_name;
	int m_age;

	Person(const std::string name="", const int age=0) : m_name(name), m_age(age)
	{}

	std::string getName() { return m_name; }
	int getAge() { return m_age; }
};


class BaseballPlayer : public Person
{
public:
	double m_battingAverage;
	int m_numberOfHomeRuns;

	BaseballPlayer(double battingAverage=0.0, int numberOfHomeRuns=0) : m_battingAverage(battingAverage), m_numberOfHomeRuns(numberOfHomeRuns)
	{}
};

class Employee : public Person
{
public:
	double m_hourlySalary;
	long m_employeeID;

	Employee(double hourlySalary=0.0, long employeeID=0) : m_hourlySalary(hourlySalary), m_employeeID(employeeID)
	{}

	friend std::ostream& operator<< (std::ostream &out, Employee &e)
	{
		out << "(" << e.m_employeeID << ")" << " " << e.m_hourlySalary << " " << e.m_name;

		return out;
	}
};

class Supervisor : public Employee
{
public:
	long m_overseesIDs[5];

	Supervisor() {}
};


int main(void)
{
	BaseballPlayer joe{ 2.3, 5 };
	joe.m_name = "Joe";
	joe.m_age = 21;

	std::cout << joe.m_name << "(" << joe.m_age << ")" << '\n';

	Employee natasha{ 23.5, 5 };
	natasha.m_name = "Natasha";
	natasha.m_age = 28;

	std::cout << natasha;

	return 0;
}