#include "pch.h"
#include <iostream>

/*int main()
{
	int x = 5; // l-�rt�k
	int &lref = x; // l-�rt�k hivatkoz�s
	int &&rref = 5; // r-�rt�k hivatkoz�s
	
	
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
	Fraction &&rref = Fraction(3, 5); // r-�rt�k hivatkoz�s egy ideiglenes funkci�ra, anonymous object

	std::cout << rref << '\n'; // �gy k�pesek vagyunk itt is haszn�lni

	return 0;
}