#include "pch.h"
#include <iostream>

//

/*#include <string>

// copy semantics
template <typename T>
void swap(T& a, T& b)
{
	T tmp{ a }; // copy constructor-t hívja segítségül
	a = b; // copy assignment-et hívja segítségül
	b = tmp; // copy assignment-et hívja segítségül
}

// move semantics
template <typename T>
void swap(T& a, T& b)
{
	T tmp{ std::move(a) }; // mivel ezek már r-érték hivatkozások az std::move miatt, a move semantics lesz segítségül
		// hívva
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };
	
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	swap(x, y);
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}*/

#include <vector>
#include <utility>
#include <string>

int main()
{
	std::vector<std::string> v;
	std::string str = "Knock";

	std::cout << "Copying str\n";
	v.push_back(str); // lehívja az l-érték szerinti push_back-et, amely belemásolja az str-t az array elembe

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nMoving str\n";
	v.push_back(std::move(str)); // lehívja az r-érték szerinti push_back-et, amely átruházza az str birtokjogát
		// az array elemre
	
	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << v[1] << '\n';

	return 0;
}