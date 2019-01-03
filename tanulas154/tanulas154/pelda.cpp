#include "pch.h"
#include <iostream>

//

/*#include <string>

// copy semantics
template <typename T>
void swap(T& a, T& b)
{
	T tmp{ a }; // copy constructor-t h�vja seg�ts�g�l
	a = b; // copy assignment-et h�vja seg�ts�g�l
	b = tmp; // copy assignment-et h�vja seg�ts�g�l
}

// move semantics
template <typename T>
void swap(T& a, T& b)
{
	T tmp{ std::move(a) }; // mivel ezek m�r r-�rt�k hivatkoz�sok az std::move miatt, a move semantics lesz seg�ts�g�l
		// h�vva
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
	v.push_back(str); // leh�vja az l-�rt�k szerinti push_back-et, amely belem�solja az str-t az array elembe

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nMoving str\n";
	v.push_back(std::move(str)); // leh�vja az r-�rt�k szerinti push_back-et, amely �truh�zza az str birtokjog�t
		// az array elemre
	
	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << v[1] << '\n';

	return 0;
}