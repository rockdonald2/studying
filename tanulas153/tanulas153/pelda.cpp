#include "pch.h"
#include <iostream>

template <class T>
class Auto_ptr3
{
private:
	T* m_ptr;

public:
	Auto_ptr3(T* ptr = nullptr) : m_ptr(ptr) {}

	~Auto_ptr3() { delete m_ptr; }

	// copy constructor
	// deep copy-t hajt végre az a.m_ptr-ból az m_ptr-ba
	Auto_ptr3(const Auto_ptr3& a) = delete;
	/*{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}*/

	// move constructor
	// átruházza az a.m_ptr erőforrásainak birtokjogát az m_ptr-ra
	Auto_ptr3(Auto_ptr3&& a) : m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

	// copy assignment
	// deep copy-t hajt végre az a.m_ptr-ból az m_ptr-ba
	Auto_ptr3& operator=(const Auto_ptr3& a) = delete;
	/*{
		// self-assignment check
		if (&a == this)
			return *this;

		// megbizonyosodunk róla, hogy az m_ptr nem tartalmaz semmit
		delete m_ptr;

		// másoljuk az adatokat
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}*/

	Auto_ptr3& operator=(Auto_ptr3&& a)
	{
		// self-assignment check
		if (&a == this)
			return *this;

		delete m_ptr;

		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource()
{
	Auto_ptr3<Resource> res(new Resource);
	return res; // ez a return érték segítségül fogja hívni a move konstruktőrt
}

int main()
{
	Auto_ptr3<Resource> mainres;
	mainres = generateResource(); // ez az assignment a move assignment fogja segítségül hívni

	return 0;
}