#include "pch.h"
#include <iostream>

/*int main()
{
	int x = 5; // l-érték
	int &lref = x; // l-érték hivatkozás
	int &&rref = 5; // r-érték hivatkozás
	
	
	return 0;
}*/

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
	{}

	friend std::ostream& operator<<(std::ostream &out, Fraction &f)
	{
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
};

int main()
{
	Fraction &&rref = Fraction(3, 5); // r-érték hivatkozás egy ideiglenes funkcióra, anonymous object

	std::cout << rref << '\n'; // így képesek vagyunk itt is használni

	return 0;
}