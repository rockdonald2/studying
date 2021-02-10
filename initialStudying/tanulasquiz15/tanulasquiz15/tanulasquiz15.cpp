#include "pch.h"
#include <iostream>

// QUIZ

//1
//1a
/*
std::unique_ptr should be used to manage any dynamically allocated object that is not shared by multiple objects
*/
//1b
/*
std::shared_ptr should be used to manage any dynamically allocated object that is may be shared among other pointers.
	a shared_ptr resource is not deallocated until the last shared_ptr is destroyed.
*/
//1c
/*
std::weak_ptr should be used when we need a smart pointer to view and access a resource managed by a shared_ptr,
	but a weak_ptr doesn't count when the shared_ptr consider to deallocate the resource
*/
//1d
/*
std::auto_ptr is deprecated, and should never be used. As of C++17 std::auto_ptr is removed from the STD.
*/

//2
/*
R-values references allow us to define different behaviours for l-value arguments and r-value arguments.
	move semantics is implemented by using r-value references, the temporary object is moved to another object,
		it simply steals the resources from the object
*/

//3
//3a
/*class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Resource *res = new Resource;
	std::shared_ptr<Resource> ptr1(res);
	std::shared_ptr<Resource> ptr2(ptr1);

	auto ptr1 = std::make_shared<Resource>();
	auto ptr2(ptr1);

	return 0;
}*/

//3b
/*class Something; // feltételezzük, hogy a class képes valamilyen kivétel dobására

int main()
{
	doSomething(std::make_shared<Something>(), std::make_shared<Something>());

	return 0;
}*/