#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <initializer_list>

class IntArray
{
private:
	int m_length;
	int *m_data; // azert kell a mutato, mert azt akarjuk, hogy az array atmeretezheto legyen

public:
	IntArray() : m_length(0), m_data(nullptr)
	{
		
	}

	IntArray(int length) : m_length(length)
	{
		assert(length >= 0 && "A hossz nagyobb vagy egyenlo kell legyen mint 0");

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	IntArray(const std::initializer_list<int> &list) : IntArray(list.size())
	{
		int count = 0;

		for (auto &elem : list)
		{
			m_data[count] = elem;
			++count;
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length && "Ervenytelen index");

		return m_data[index];

	}

	IntArray& operator=(const std::initializer_list<int> &list)
	{
		if (list.size() > static_cast<size_t>(m_length))
		{
			delete[] m_data;

			m_length = list.size();
			m_data = new int[m_length];
		}

		int count = 0;

		for (auto &elem : list)
		{
			m_data[count] = elem;
			++count;
		}

		return *this;

	}

	int getLength()
	{
		return m_length;
	}

	void reallocate(int newLength)
	{
		erase();

		if (newLength <= 0)
			return;

		m_data = new int[newLength];
		m_length = newLength;
	}

	void resize(int newLength)
	{
		if (newLength == m_length)
			return;

		if (newLength <= 0)
		{
			erase();
			return;
		}

		int *data = new int[newLength];

		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? newLength : m_length;

			for (int index = 0; index <	elementsToCopy; ++index)
			{
				data[index] = m_data[index];
			}
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}


	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length && "Ervenytelen index");

		int *data = new int[m_length + 1];

		for (int before = 0; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		data[index] = value;

		for (int after = index; after < m_length; ++after)
		{
			data[after + 1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void remove(int index)
	{
		assert(index >= 0 && index < m_length && "Ervenytelen index");

		if (m_length == 1)
		{
			erase();
			return;
		}

		int *data = new int[m_length - 1];

		for (int before = 0; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		for (int after = index + 1; after < m_length; ++after)
		{
			data[after - 1] = m_data[after];
		}


		delete[] m_data;
		m_data = data;
		--m_length;

	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }
};

#endif
