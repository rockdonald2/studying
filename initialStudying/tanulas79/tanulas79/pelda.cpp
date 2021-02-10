#include "stdafx.h"
#include <iostream>

int foo(int x)
{
	// b
	return x; 
} // foo lekerül a rakásról itt

int main()
{
	// a
	foo(5); // foo felkerül a rakásra itt
	// c
}


/*

a rakás kinézete a különböző pontokban:
	
	a -
	    main()

	b - 
		foo()
		main()
		

	c -
		main()

*/