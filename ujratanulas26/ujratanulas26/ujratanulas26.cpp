#include "stdafx.h"
#include <iostream>


/*

logikai(boolean) típus, ami igaz/hamis (true/false) értékkel dolgozik.

*/

bool bx;

bool b1 = true; // copy initialization
bool b2(false); // direct initialization
bool b3{ true }; // uniform initialization

bool funkcio()
{
	int b33;
	b33 = false; // assignment

	return b33;
}

/*

a számoknál -(minusz) operátort használva lehet ellentétezni
	itt a !(NOT) operátort használva lehet megfordítani

*/

bool b4 = !false; // igaz lesz
bool b5(!false); // igaz lesz


/*

cout paranccsal kivetítve, nem true-t vagy false-t fog írni, hanem egész számokként jelennek meg 1(true), 0(false)

		ha kiakarod iratni true vagy false-ként akkor használhatod az std::boolalpha parancsot
																	std::noboolalpha a kikapcsolásához
				
				std::cout << std::boolalpha;
				std::cout << std::noboolalpha;

*/



/*

a boolean változók leggyakoribb felhasználása ha nyilatkozatokban(if statements) vannak.

	két részből áll, egy condition-ból, vagy conditional expressionból, és egy vagy két statementből.

*/

int funkcio2()
{
	bool b(false);
	if (b)
		std::cout << "b igaz" << std::endl;
	else
		std::cout << "b hamis" << std::endl;

	return b;
}

