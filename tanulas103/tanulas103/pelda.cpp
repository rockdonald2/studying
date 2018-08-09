#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(std::string name = "") : m_name(name)
	{}

	std::string getName() {
		return m_name;
	}
};


/*class Department
{
private:
	Teacher * m_teacher;
	int m_numberOfTeachersMAX = 10;
	int m_numberOfTeachers = 10;

public:
	Department()
	{
		m_teacher = new Teacher[m_numberOfTeachersMAX];
	}

	void add(Teacher *teacher)
	{
		m_teacher[m_numberOfTeachersMAX - m_numberOfTeachers] = *teacher;
		--m_numberOfTeachers;
	}

	~Department()
	{
		delete[] m_teacher;
	}

	friend std::ostream& operator<<(std::ostream &out, Department &d)
	{
		out << "Az osztaly tanarai: ";

		for (int teacher = 0; teacher < 10 - d.m_numberOfTeachers; ++teacher)
			out << d.m_teacher[teacher].getName() << ' ';

		return out;
	}
};*/

class Department
{
private:
	std::vector<Teacher*> m_teacher;

public:
	Department()
	{
		
	}

	void add(Teacher *teacher)
	{
		m_teacher.push_back(teacher);
	}

	friend std::ostream& operator<<(std::ostream &out, Department &d)
	{
		out << "Az osztaly tanarai: ";

		for (int teacher = 0; teacher < d.m_teacher.size(); ++teacher)
			out << d.m_teacher[teacher]->getName() << ' ';

		return out;
	}
};


int main(void)
{
	// szóval létrehozunk egy új Teacher mutatót a Department scopeján kivül.
	Teacher *t1 = new Teacher("Bob");
	Teacher *t2 = new Teacher("Mike");
	Teacher *t3 = new Teacher("Jake");

	{
		// létrehozzunk egy department amelynek a konstruktőrjét használjuk, hogy továbbadjuk a mutatót mint paraméter
		Department dept;
		dept.add(t1);
		dept.add(t2);
		dept.add(t3);

		std::cout << dept << '\n';
	} // itt a dept kimegy a scopeból és megsemmisül

	// de a teacher mutató nem törlődött és itt is használható, mivel a dept nem törölte.

	std::cout << t1->getName() << " meg mindig letezik.\n";
	std::cout << t2->getName() << " meg mindig letezik.\n";
	std::cout << t3->getName() << " meg mindig letezik.\n";


	delete t1;
	delete t2;
	delete t3;

	return 0;
}