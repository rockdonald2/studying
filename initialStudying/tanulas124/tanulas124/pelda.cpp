#include "pch.h"
#include <iostream>

/*void printValue(int value)
{
	std::cout << "The value is: " << value << '\n';
}

int add(int x, int y)
{
	return x + y;
}

int main()
{
	printValue(5);

	int(*pFcn)(int, int) = add;
	std::cout << pFcn(5, 3) << '\n';

	return 0;
}*/

int add(int x, int y)
{
	return x + y;
}

int substract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	char op;
	do
	{
		std::cout << "Enter an operator(+,-,*): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*');

	int(*pFcn)(int, int) = nullptr;

	int x, y;
	std::cout << "Enter the first operand: ";
	std::cin >> x;
	std::cout << "Enter the second operand: ";
	std::cin >> y;

	switch (op)
	{
	case '+': pFcn = add; break;
	case '-': pFcn = substract; break;
	case '*': pFcn = multiply; break;
	}

	std::cout << "The answer is: " << pFcn(x, y) << '\n';

	return 0;
}