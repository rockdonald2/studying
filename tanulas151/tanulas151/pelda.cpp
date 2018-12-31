#include "pch.h"
#include <iostream>

/*void someFunction()
{
	Resource *ptr = new Resource; // ahol Resource egy class vagy struct

	// különböző dolgok a ptr-el

	delete ptr;
}*/

template<class T>
class Auto_ptr1
{
	T* m_ptr;

public:
	// beadunk egy mutatót amelyet birtokolni fog a konstruktőr által
	Auto_ptr1(T* ptr = nullptr) : m_ptr(ptr)
	{}

	// a destruktőr biztosítja, hogy a memória fel lesz szabadítva
	~Auto_ptr1()
	{
		delete m_ptr;
	}

	// copy konstruktőr amely magába építi a move semantics-ot
	Auto_ptr1(Auto_ptr1& a)
	{
		m_ptr = a.m_ptr; // átadjuk az alap mutatónkat a forrásból a helyi objectbe
		a.m_ptr = nullptr; // bebiztosítsuk, hogy a forrás már nem birtokolja a mutatót
	}

	// assignment operátor amely magába építi a move semantics-ot
	Auto_ptr1& operator=(Auto_ptr1& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr; // bebiztosítsuk, hogy a célmutató semmilyen értéket nem tárol
		m_ptr = a.m_ptr; // átadjuk az alap mutatónkat a forrásból a helyi objectbe
		a.m_ptr = nullptr; // bebiztosítsuk, hogy a forrás már nem birtokolja a mutatót

		return *this;
	}

	// szükségünk van egy overloadolt dereference és operátor-> operátorra, így úgy tudjuk használni az Auto_ptr1-t
		// mint az m_ptr-t
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};

// egy minta class, hogy bizonyítsuk, hogy működik.
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource deleted\n"; }
};

int main()
{
	//Auto_ptr1<Resource> res1(new Resource); /// critical flaw
	//Auto_ptr1<Resource> res2(res1);

	Auto_ptr1<Resource> res1(new Resource);
	Auto_ptr1<Resource> res2; // nullptr alapból

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1; // res2 átveszi a birtokjogot, a res1 null lesz

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	return 0;
} // a res kimegy scopeból, és törli a lefoglalt Resource-t nekünk 