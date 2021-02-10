#include "pch.h"
#include  <iostream>

//

/*#include <memory>
#include <string>

class Person
{
	std::string m_name;
	std::shared_ptr<Person> m_partner; // alapból üresen jön létre

public:
	Person(const std::string &name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

		return true;
	}
};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy"); // létrehozunk egy Person-t Lucy névvel
	auto ricky = std::make_shared<Person>("Ricky"); // létrehozunk egy Person-t Ricky névvel

	partnerUp(lucy, ricky); // Lucy ezután Ricky-re fog mutatni, és fordítva

	return 0;
}*/

/*class Resource
{
public:
	std::shared_ptr<Resource> m_ptr; // üresen jön létre először

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 = std::make_shared<Resource>();

	ptr1->m_ptr = ptr1; // szóval most az m_ptr megosztja azt a Resource-t ami tartalmazza őt

	return 0;
}*/

/*#include <memory>
#include <string>

class Person
{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // alapból üresen jön létre, mostmár weak_ptr

public:
	Person(const std::string &name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

		return true;
	}

	// átalakítja a weak_ptr-t shared_ptr-é a lock() funkcióval
	const std::shared_ptr<Person> getPartner() const { return m_partner.lock(); }
	const std::string& getName() const { return m_name; }
};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy"); // létrehozunk egy Person-t Lucy névvel
	auto ricky = std::make_shared<Person>("Ricky"); // létrehozunk egy Person-t Ricky névvel

	partnerUp(lucy, ricky); // Lucy ezután Ricky-re fog mutatni, és fordítva
	
	auto partner = ricky->getPartner();
	std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';

	return 0;
}*/

class Resource
{
public:
	std::weak_ptr<Resource> m_ptr; // üresen jön létre először

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 = std::make_shared<Resource>();

	ptr1->m_ptr = ptr1; // szóval most az m_ptr megosztja azt a Resource-t ami tartalmazza őt

	return 0;
}