#include "pch.h"
#include <iostream>

template <typename T>
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T &value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}
};

template <>
class Storage8<bool>
{
private:
	unsigned char m_data;

public:
	Storage8() : m_data(0)
	{}

	void set(int index, bool value)
	{
		// ezzel megkeressük melyik bit-et akarjuk állítani
		// ez egy 1-est rak abba a bitbe amelyik minket érdekel
		unsigned char mask = 1 << index;

		if (value) // ha állítjuk a bit-et
			m_data |= mask; // használjuk a bitwise-or-t, hogy "bekapcsoljuk" azt a bit-et
		else
			m_data &= ~mask; // bitwise-and és az inverse mask, hogy "kikapcsoljuk" azt a bit-et
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		// bitwise-and, hogy lekérjük azt az értéket a bitnek ami minket érdekel
		// aztán kifejezetten átalakítjuk bool formába
		return (m_data & mask) != 0;
	}
};

int main()
{
	// meghatározunk egy Storage8-at integerekhez.
	Storage8<int> intStorage;
	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);
	for (int count = 0; count < 8; ++count)
		std::cout << intStorage.get(count) << '\n';

	// meghatározunk egy Storage8-t booleanokhoz.
	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);
	for (int count = 0; count < 8; ++count)
		std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';

	return 1337;
}