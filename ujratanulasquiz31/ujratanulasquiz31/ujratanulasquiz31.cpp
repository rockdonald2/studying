#include "stdafx.h"
#include <iostream>

/*

1)
	(5 > 3 && 4 < 8) = TRUE;
	(4 > 6 && true ) = FAlSE;
	(3 >= 3 || false) = TRUE;
	(true || false) ? 4 : 5 = 4;

2)
	7 / 4 = 1;
	14 % 5 = 4;

3)
	1101 = 8 + 4 + 1 = 13;
	0010 1110 = 32 + 8 + 4 + 2 = 46;

4)
	15 = 0000 1111;
	53 = 0011 0101;

5)
	int y = foo(++x, x);    ezt soha, mivel nem szabad side-effecttel rendelkező változót egy adott állításban kétszer használni.
	int x = 7 / -2;    ezt soha, a kerekítési hiba miatt, ez lehet akár -3, vagy -4.
	int x = -5 % 2;    ezt soha, ha egy modulus bármelyik operándusa negatív, az eredmény lehet pozítiv vagy negatív.
	float x = 0.1 + 0.1; if (x == 0.2) return true; else return false;
		ezt soha, mivel kerekítési hibák vannak a floating point számokkal, és váratlan eredményekhez vezethet.
	int x = 3 / 0;    nullával való osztás értelmetlen, program crash.

*/

	