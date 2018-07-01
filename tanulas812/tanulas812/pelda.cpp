#include "stdafx.h"
#include <iostream>

class Valami
{
private:
	static int m_ertek;
public:
	static int leker()
	{
		return m_ertek;
	}
};

int Valami::m_ertek = 1;

int main()
{
	std::cout << Valami::leker() << '\n';

	return 0;
}