#include "pch.h"
#include <iostream>

/*int& IntArray(const int index)
{
	if (index < 0 || index >= getLength())
	return m_data[index];
}

try
{
	int *value = new int(array[index1] + array[index2]);
}

catch (int value)
{
	// mit is kéne kifogni?
}*/

/*#include <string>

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string error) : m_error(error) {}

	const char* getError() { return m_error.c_str(); }
};

class IntArray
{
private:
	int m_data[3];

public:
	IntArray() {}

	int getLength() { return 3; }

	int& operator[] (const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}
};

int main()
{
	IntArray array;

	try
	{
		int value = array[-1];
	}

	catch (ArrayException &exception)
	{
		std::cerr << "An array exception occured(" << exception.getError() << ")\n";
	}

	return 0;
}*/

/*class Base
{
public:
	Base() {}
};

class Derived : public Base
{
public:
	Derived() {}
};

int main()
{
	try
	{
		throw Derived();
	}

	catch (Derived)
	{
		std::cerr << "caught derived\n";
	}

	catch (Base)
	{
		std::cerr << "caught base\n";
	}

	return 0;
}*/

/*#include <string>
#include <exception>

int main()
{
	try
	{
		std::string s;
		s.resize(-1); // std::bad_alloc fog dobódni
	}

	// ez elfog kapni minden kivételt az std::bad_allocból(és bármit ami belőle lett származtatva)
	catch (std::bad_alloc &exception)
	{
		std::cerr << "You ran out of memory!\n";
	}

	// ez elfog kapni minden kivételt az std::excpetionból(és bármit ami belőle lett származtatva)
	catch (std::exception &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}

	return 0;
}*/

/*#include <stdexcept>

int main()
{
	try
	{
		throw std::runtime_error("Bad things happened");
	}

	catch (std::exception &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}

	return 0;
}*/

#include <string>
#include <exception>

class ArrayException : public std::exception
{
private:
	std::string m_error;

public:
	ArrayException(std::string error) : m_error(error) {}

	const char* what() const noexcept { return m_error.c_str(); }
};

class IntArray
{
private:

	int m_data[3];
public:
	IntArray() {}

	int getLength() { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}
};

int main()
{
	IntArray array;

	try
	{
		int value = array[5];
	}

	catch (ArrayException &exception)
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}

	catch (std::exception &exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}

	return 0;
}