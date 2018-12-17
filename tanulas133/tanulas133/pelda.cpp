#include "pch.h"
#include <iostream>

/**/
#include <assert.h>

template <typename T> // de akár használhatnám a <class T>, mert typename = class
class Array
{
private:
	int m_length;
	T *m_data;

public:
	Array(
	)
	{
		m_length = 0;
		m_data = nullptr;
	}

	Array(int length)
	{
		m_length = length;
		m_data = new T[length];
	}

	~Array(
	)
	{
		delete[] m_data;
	}

	void Erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength(); // template getLenght funckiót a classon kivül kell deklarálni, úgyanakkor nem szükséges mindig
};

template <typename T>
int Array<T>::getLength() { return m_length; }

int main()
{
	Array<int> intArray(5);
	Array<double> doubleArray(5);

	for (int count = 0; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count = 0; count < doubleArray.getLength(); ++count)
	{
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';
	}
	
	return 1337;
}