#include "pch.h"
#include <iostream>

// következő példa egy static array, melyben a template type paramter kezeli az adattípusát a static array-nek,
	// míg a non-type parameter az array méretét.

template <typename T, int size>
class StaticArray
{
private:
	T m_array[size];

public:
	T* getArray();

	T& operator[] (int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
T* StaticArray<T, size>::getArray()
{
	return m_array;
}

int main()
{
	StaticArray<int, 12> intArray;

	for (int count = 0; count < 12; ++count)
		intArray[count] = count;

	for (int count = 11; count >= 0; --count)
		std::cout << intArray[count] << ' ';

	return 1337;
}