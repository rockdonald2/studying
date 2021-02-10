#include "pch.h"
#include <iostream>

/*template <typename T, int size> // a size non-type parameter, azaz expression parameter
class StaticArray
{
private:
	T m_array[size]; // ez esetben a size határozza meg az array méretét

public:
	T* getarray() { return m_array; }

	T& operator[] (int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count] << ' ';
}

template <typename T, int size>
void fill(StaticArray<T, size> &array, int index, int value)
{
	array[index] = value;
}

template <>
void print(StaticArray<char, 14> &array)
{
	for (int count = 0; count < 14; ++count)
		std::cout << array[count];
}

template<int size> // size expression paraméter lesz
void print(StaticArray<char, size> &array) // míg a char kifejezetten megvan határozva
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count];
}

int main()
{
	StaticArray<int, 8> intArray;
	for (int count = 0; count < 8; ++count)
		fill(intArray, count, count + 2);
	print(intArray);
	std::cout << '\n';
	StaticArray<char, 14> char14;
	strcpy_s(char14.getarray(), 14, "Hello, world!"); // az strcpy egyiket stringet a másikba másolja
	print(char14);
	std::cout << '\n';
	StaticArray<char, 12> char12;
	strcpy_s(char12.getarray(), 12, "Hello, mom!");
	print(char12);

	return 0;
}*/

template<typename T, int size>
class StaticArray_Base
{
protected:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[] (int index)
	{
		return m_array[index];
	}

	virtual void print() 
	{
		for (int count = 0; count < size; ++count)
		{
			std::cout << m_array[count] << ' ';
		}
		std::cout << '\n';
	}

	void fill(int index, int value)
	{
		m_array[index] = value;
	}
};

template<typename T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
public:
	StaticArray()
	{}
};

template<int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
private:
	typedef StaticArray_Base<char, size> Parent;
public:
	virtual void print() override
	{
		for (int count = 0; count < size; ++count)
		{
			std::cout << Parent::m_array[count]; // a typedef-es megoldás
			//std::cout << this->m_array[count]; // itt van a felkiáltójeles eset, itt mindig kell ez a this.
		}
		std::cout << '\n';
	}
};

int main()
{
	StaticArray<int, 8> intArray;
	for (int count = 0; count < 8; ++count)
		intArray.fill(count, count + 2);
	intArray.print();
	std::cout << '\n';
	StaticArray<char, 14> char14;
	strcpy_s(char14.getArray(), 14, "Hello, world!"); // az strcpy egyiket stringet a másikba másolja
	char14.print();
	std::cout << '\n';
	StaticArray<char, 12> char12;
	strcpy_s(char12.getArray(), 12, "Hello, mom!");
	char12.print();

	return 0;
}