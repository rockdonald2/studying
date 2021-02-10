#include "pch.h"
#include <iostream>

/*class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource deleted\n"; }
};

int main()
{
	std::unique_ptr<Resource> res1(new Resource); // Resource object itt létrejött
	std::unique_ptr<Resource> res2; // itt még nullptr

	std::cout << "Res1 is: " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
	std::cout << "Res2 is: " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

	res2 = std::move(res1); // res2 átveszi a birtokjogot, res1 nullptr

	std::cout << "Res1 is: " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
	std::cout << "Res2 is: " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

	return 0;
}*/

/*class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource deleted\n"; }

	friend std::ostream& operator<<(std::ostream &out, const Resource &r)
	{
		out << "I am a resource\n";
		return out;
	}
};

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f)
	{
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
};

std::unique_ptr<Resource> createResource()
{
	return std::make_unique<Resource>();
}

void takeOwnership(std::unique_ptr<Resource> res)
{
	if (res) // a cast to bool funkció használata, hogy megbizonyosodjunk róla az std::unique_ptr kezel erőforrást
		std::cout << *res;
} // a Resource itt törlődik

// ez a funkció csak az erőforrást használja, szóval elfogadható egy mutató az erőforrásra, nem egy hivatkozás
// a teljes std::unique_ptr<Resource>-ra
void useResource(Resource *res)
{
	if (res)
		std::cout << *res;
}

int main()
{
	// létrehoz egy dinamikusan elosztott Fraction-t 3-al és 5-el
	std::unique_ptr<Fraction> f1 = std::make_unique<Fraction>(3, 5);
	std::cout << *f1 << '\n';

	// létrehoz egy dinamikusan elosztott array-t Fraction-ból 4-es hosszal
	// használhatjuk az automatikus típus levezetést jó hatással itt
	auto f2 = std::make_unique<Fraction[]>(4);
	std::cout << f2[0] << '\n';

	std::unique_ptr<Resource> ptr = createResource();

	auto ptr2 = std::make_unique<Resource>();
	takeOwnership(std::move(ptr2));

	auto ptr3 = std::make_unique<Resource>();
	useResource(ptr3.get()); // használjuk a get()-et, hogy nyerjünk egy mutatót az erőforrásra

	std::cout << "Ending program\n";
	
	return 0;
}*/

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f)
	{
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
};

void printFraction(const Fraction const *f)
{
	if (f)
		std::cout << *f;
}

int main()
{
	auto ptr = std::make_unique<Fraction>(3, 5);

	printFraction(ptr.get());

	return 0;
}