#include "pch.h"
#include <iostream>

// ez eddig egy normál template
template <typename T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value) : m_value(value) {}

	~Storage() {}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

// itt jön a partial template mutatókra
template <typename T>
class Storage<T*>
{
private:
	T* m_value;

public:
	Storage(T* value)
	{
		m_value = new T(*value);
	}

	~Storage()
	{
		delete m_value;
	}

	void print()
	{
		std::cout << *m_value << '\n';
	}
};

int main()
{
	Storage<int> intSt(5);
	intSt.print();

	int x = 7;
	Storage<int*> intPSt(&x);

	x = 9;
	intPSt.print();

	return 0;
}