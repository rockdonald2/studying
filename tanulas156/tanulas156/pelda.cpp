#include "pch.h"
#include <iostream>

/*class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	// létrehozunk egy Resource objectet és hagyjuk, hogy az std::shared_ptr birtokolja
	Resource *res = new Resource;
	std::shared_ptr<Resource> ptr1(res);
	{
		std::shared_ptr<Resource> ptr2(ptr1); // copy inicializálást használva létrehozunk egy másik std::shared_ptr-t
		// amely ugyanarra mutat
		std::cout << "Killing one shared pointer\n";
	} // ptr2 kimegy scopeból, de mivel létezik még egy shared_ptr amely ugyanarra mutat a Resource nem törlődik

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 kimegy scopeból, a lefoglalt Resource törlődik*/

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	// lefoglalunk egy Resource objectet, és odaadjuk az std::shared_ptr-nak, hogy birtokolja
	auto ptr1 = std::make_shared<Resource>();
	{
		auto ptr2 = ptr1; // copy inicializálássasl létrehozunk egy második shared_ptr-t
		
		std::cout << "Killing one shared pointer\n";
	} // ptr2 kimegy scopeból, nem történik semmi

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 kimegy scopeból, Resource törlődik