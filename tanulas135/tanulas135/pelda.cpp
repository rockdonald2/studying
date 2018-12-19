#include "pch.h"
#include <iostream>

template <typename T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value) : m_value(value)
	{}

	~Storage() 
	{}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

template <>
void Storage<double>::print()
{
	std::cout << std::scientific << m_value << '\n';
}

template<>
Storage<char*>::Storage(char* value)
{
	int length = 0;
	while (value[length] != '\0') //kisz�moljuk milyen hossz� a string
		++length;
	++length; // a \0 termint�ronak csin�lunk helyet

	m_value = new char[length]; // l�trehozzuk a stringet
	
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count]; // �tm�soljuk az input stringet a saj�t stringbe
}

Storage<char*>::~Storage()
{
	delete[] m_value;
}

int main()
{
	Storage<int> intValue(5);
	Storage<double> doubleValue(5.22);

	intValue.print();
	doubleValue.print();

	char *string = new char[40];

	std::cout << "Enter your name: ";
	std::cin >> string;

	Storage<char*> charValue(string);

	delete[] string;

	charValue.print();

	return 1337;
}