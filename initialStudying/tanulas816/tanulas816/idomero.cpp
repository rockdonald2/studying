#include "stdafx.h"
#include <iostream>

#include <chrono> // az std::chrono funkciókhoz

class Idomero
{
private:

	// type aliases, hogy könnyebb legyen elérni később
	using ora_i = std::chrono::high_resolution_clock;
	using masodperc_i = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<ora_i> m_leker;

public:

	Idomero() : m_leker(ora_i::now())
	{}

	void visszaallit()
	{
		m_leker = ora_i::now();
	}

	double elteltIdo() const
	{
		return std::chrono::duration_cast<masodperc_i>(ora_i::now() - m_leker).count();
	}
};