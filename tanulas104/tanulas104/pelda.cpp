#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>


/*class Doctor;

class Patient
{
private:
	std::string m_name;
	std::vector<Doctor*> m_doctor;

	void addDoctor(Doctor *doc);

public:
	Patient(std::string name) : m_name(name)
	{}

	friend std::ostream& operator<<(std::ostream &out, const Patient &p);

	std::string getName() { return m_name; }

	friend class Doctor;
};


class Doctor
{
private:
	std::string m_name;
	std::vector<Patient*> m_patient;

public:
	Doctor(std::string name) : m_name(name)
	{}

	void addPatient(Patient *p)
	{
		m_patient.push_back(p);

		p->addDoctor(this);
	}

	friend std::ostream& operator<<(std::ostream &out, const Doctor &d)
	{
		unsigned int length = d.m_patient.size();

		if (length == 0)
		{
			out << "The doctor "<< d.m_name << " has no patients at all.\n";
			return out;
		}

		out << "Doctor " << d.m_name << " is seeing patients: ";
		for (unsigned int i = 0;  i < length;  ++i)
		{
			out << d.m_patient[i]->getName() << ' ';
		}

		return out;
	}

	std::string getName() { return m_name; }
};

void Patient::addDoctor(Doctor *d)
{
	m_doctor.push_back(d);
}

std::ostream& operator<<(std::ostream &out, const Patient &p)
{
	unsigned int length = p.m_doctor.size();

	if (length == 0)
	{
		out << "The patient " << p.m_name << " has no doctors at all.\n";
		return out;
	}

	out << "The patient " << p.m_name << " is seeing doctors: ";
	for (unsigned int i = 0; i < length; ++i)
	{
		out << p.m_doctor[i]->getName() << ' ';
	}

	return out;
}

int main()
{
	Patient *p1 = new Patient("Juliett");
	Patient *p2 = new Patient("Dave");
	Patient *p3 = new Patient("Zach");

	Doctor *d1 = new Doctor("Betsy");
	Doctor *d2 = new Doctor("Scott");

	d1->addPatient(p1);

	d2->addPatient(p3);
	d2->addPatient(p2);

	std::cout << *p1 << '\n';
	std::cout << *p2 << '\n';
	std::cout << *p3 << '\n';

	std::cout << *d1 << '\n';
	std::cout << *d2 << '\n';

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0;
}*/


class Car
{
private:
	std::string m_name;
	int m_id;

public:
	Car(std::string name, int id) : m_name(name), m_id(id)
	{}

	std::string getName() { return m_name; }
	int getId() { return m_id; }
};


class CarLot
{
private:
	static Car s_carLot[4];

public:
	CarLot() = delete;

	static Car* getCar(int id)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (s_carLot[i].getId() == id)
				return &(s_carLot[i]);

			else
				return nullptr;
		}
	}
};

Car CarLot::s_carLot[4] = { Car("Corolla", 1), Car("Volkswagen", 17), Car("Polo", 12), Car("Prius", 87) };

class Driver
{
private:
	std::string m_name;
	int m_carId;

public:
	Driver(std::string name, int carId) : m_name(name), m_carId(carId)
	{}

	std::string getName() { return m_name; }
	int getCarId() { return m_carId; }
};

int main()
{
	Driver d("Frank", 87);

	Car *car = CarLot::getCar(d.getCarId());

	if (car)
	{
		std::cout << d.getName() << " is driving a " << car->getName() << '.\n';
	}
	else
	{
		std::cout << d.getName() << " couldn't find his car.\n";
	}

	return 0;
}