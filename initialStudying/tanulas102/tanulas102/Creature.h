#ifndef CREATURE_H
#define CREATURE_H


#include "stdafx.h"
#include <iostream>
#include <string>

#include "Point2d.h"


class Creature
{
private:
	std::string m_name;
	Point2d m_location;

public:
	Creature(const std::string &name, const Point2d &location) : m_name(name), m_location(location)
	{}

	friend std::ostream& operator<<(std::ostream &out, const Creature &c)
	{
		out << c.m_name << " is at " << c.m_location;

		return out;
	}

	void moveTo(int x, int y)
	{
		m_location.setPoint(x, y);
	}

};

#endif
