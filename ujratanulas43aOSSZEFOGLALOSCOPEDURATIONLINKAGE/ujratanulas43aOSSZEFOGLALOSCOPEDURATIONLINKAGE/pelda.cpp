#include "stdafx.h"
#include <iostream>

// externális non-const globális változó (file scope, static duration, external linkage)
int g_x; 
int g_x{ 5.0 }; /// mindkettő helyes, lehet initializálva, vagy sem.

// internális non-const globális változó (file scope, static duration, internal linkage)
static int g_x;
static int g_x{ 5.0 }; /// mindkettő helyes, lehet initializálva vagy sem.

// internális const globális változó (file scope, static duration, internal linkage)
const int g_x{ 1.0 }; /// muszáj initializálni

// externális const globális változó (file scope, static duration, external linkage)
extern const int g_x{ 5.0 }; /// muszáj initializálni

void foo(int x)
{
	// funkció paraméter ( block scope, automatic duration, no linkage)
}

int main()
{
	// helyi változó ( block scope, automatic duration, no linkage)
	int x;

	// static helyi változó ( block scope, static duration, no linkage)
	static int s_x;

	// forward declaration
	void foo(int x); /// nincs funkció body!

	// forward declaration, non-const globális változó
	extern int g_x; /// muszáj uninitializált legyen!

	// forward declaration, const globális változó
	extern const int g_x; /// muszáj uninitializált legyen!



	return 0;
}