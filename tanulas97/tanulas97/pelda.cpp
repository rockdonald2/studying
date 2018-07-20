#include "stdafx.h"
#include <iostream>

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit)
	{}

	Digit& operator++();
	Digit& operator--();
	Digit operator++(int);
	Digit operator--(int);

	friend std::ostream& operator<<(std::ostream &out, const Digit &d);
};

std::ostream& operator<<(std::ostream &out, const Digit &d)
{
	out << d.m_digit;

	return out;
}

Digit& Digit::operator++()
{
	// ha a számunk már 9, kerekítse 0-ra.
	if (m_digit == 9)
		m_digit = 0;
	// ha nem, csak növelje a következő számra.
	else
		++m_digit;

	return *this;
}

Digit& Digit::operator--()
{
	// ha a számunk 0, akkor tegye 9-re
	if (m_digit == 0)
		m_digit = 9;
	// ha nem, csak csökkentse az előző számra.
	else
		--m_digit;

	return *this;
}

Digit Digit::operator++(int)
{
	// csinálunk egy ideiglenes mentést a változóról
	Digit temp(m_digit);

	// megnöveljük a számot
	++(*this);

	// visszaadjuk a mentést.
	return temp;
}

Digit Digit::operator--(int)
{
	// csinálunk egy ideiglenes mentést a változóról
	Digit temp(m_digit);

	// megnöveljük a számot
	--(*this);

	// visszaadjuk a mentést.
	return temp;
}

int main()
{
	/*Digit digit(8);

	std::cout << digit;
	std::cout << ++digit;
	std::cout << ++digit;
	std::cout << --digit;
	std::cout << --digit;*/

	Digit digit(5);

	std::cout << digit;
	std::cout << ++digit; // calls Digit::operator++();
	std::cout << digit++; // calls Digit::operator++(int);
	std::cout << digit;
	std::cout << --digit; // calls Digit::operator--();
	std::cout << digit--; // calls Digit::operator--(int);
	std::cout << digit;

	return 0;
}