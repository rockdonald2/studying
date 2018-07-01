#include "stdafx.h"
#include <iostream>

class Valami
{
public:
	int m_ertek;

	Valami() { m_ertek = 0; }

	void visszaallit() { m_ertek = 0; }
	void modosit(int ertek) { m_ertek = ertek; }

	int leker() const { return m_ertek; }
};

int main()
{
	const Valami vlm;

	// vlm.m_ertek = 5; error
	// vlm.modosit(5); error

	std::cout << vlm.leker() << "\n";
}