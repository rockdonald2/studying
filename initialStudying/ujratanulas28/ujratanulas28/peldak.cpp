#include "stdafx.h"
#include <iostream>

int main()
{
	int x = 012; // a 0 előtag jelző, hogy ez egy 8-as alapú szám
	std::cout << x << std::endl; // 10-et fog kiírni
				// nagyon ritkán használják, kerüld el.

	int y = 0xF; // a 0x előtag jelzi, ez egy 16-os alapú szám
	std::cout << y << std::endl; // 15-öt fog kiírni
			// 16-os számrendszerű számokat használják, arra, hogy reprezentálják a memória címeket, vagy nyers értékeket a memóriában

	int h = 0b11; // bináris 0000 0011 értéket iniciálja a változóhoz
	std::cout << h << std::endl;

	return 0;
}