#include "stdafx.h"
#include <iostream>
#include <vector>

/*int main()
{
	// 1
	std::vector<int>array = { 0, 1, 2 };
	array.resize(5);

	for (auto const &elem : array)
		std::cout << elem << ' ';

	std::cout << '\n';

	std::cout << "Az array hossza: " << array.size() << '\n';
	std::cout << "Az array kapacitasa: " << array.capacity() << '\n';

	// 2

	std::vector<int>array2;
	array2 = { 2, 3, 4, 5, 6 };
	
	std::cout << "Az array hossza " << array2.size() << ", az array kapacitasa pedig " << array2.capacity() << '\n';

	array2 = { 9, 8, 7 };

	std::cout << "Az array hossza " << array2.size() << ", az array kapacitasa pedig " << array2.capacity() << '\n';


	return 0;
}*/

/*
void printStack(const std::vector<int> &stack)
{
	for (const auto &elem : stack)
		std::cout << elem << ' ';
	std::cout << "(kap " << stack.capacity() << " hossz " << stack.size() << ")\n";
}

int main()
{
	std::vector<int> stack;

	stack.reserve(5);

	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "A rakas csucsa: " << stack.back() << '\n';

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}*/

/*
int main()
{
	// 3
	std::vector<int> array = { 0, 1, 2, 3, 4 };
	std::cout << "Array hossz " << array.size() << ", kapacitas " << array.capacity() << '\n';

	array.push_back(5);
	std::cout << "Array hossz " << array.size() << ", kapacitas " << array.capacity() << '\n';

	return 0;
}*/