#include "pch.h"
#include <iostream>

int main()
{
	std::cout.setf(std::ios::showpos);
	std::cout << 27 << "abd" << '\n';

	std::cout.unsetf(std::ios::showpos);
	std::cout << 27 << '\n';

	std::cout.setf(std::ios::hex);
	std::cout << 27 << '\n';
		// nem működik, még mindig dec alapú az int

	std::cout.unsetf(std::ios::dec); // kikapcsolja a dec flaget
	std::cout.setf(std::ios::hex); // bekapcsolja a hex flaget
	std::cout << 27 << '\n';
		// működik

	std::cout << std::hex << 27 << '\n'; // 27-t ír ki hex-ben
	std::cout << 28 << '\n'; // még mindig hex
	std::cout << std::dec << 27 << '\n'; // újra dec

	return 0;
}