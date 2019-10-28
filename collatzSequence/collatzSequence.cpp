#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
std::uint64_t getRandomNumber(std::uint64_t min, std::uint64_t max)
{
	static constexpr long double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<std::uint64_t>((max - min + 1) * (std::rand() * fraction));
}

void collatzSequence(unsigned int _tries) {
	std::ofstream outf("memory.dat", std::ios::app);

	if (!outf) {
		std::cerr << "Memory.dat could not be opened for writing" << std::endl;
		exit(-1);
	}

	std::uint64_t collatzNum = 0;
	unsigned int length = 0;

	unsigned int _loop = true;
	for (unsigned int c = 0; c < _tries; ++c) {
		_loop = true;
		std::uint64_t collatzNum = getRandomNumber(1, 18446744073709551615);
		length = 0;

		std::cout << "Current collatzNum was " << collatzNum;
		outf << "Current collatzNum was " << collatzNum;

		while (_loop) {
			if (collatzNum % 2 == 0) {
				collatzNum /= 2;
			}
			else {
				collatzNum = (3 * collatzNum + 1);
			}

			++length;

			if (collatzNum == 1) {
				_loop = !_loop;
			}
		}

		std::cout << " which took " << length << " steps to equal 1" << std::endl;
		outf << " which took " << length << " steps to equal 1" << std::endl;
	}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	rand();

	collatzSequence(100000);

	return 0;
}