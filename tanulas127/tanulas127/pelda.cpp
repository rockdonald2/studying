#include "pch.h"
#include <iostream>

class PoweredDevice
{
public:
	PoweredDevice(int power)
	{
		std::cout << "PoweredDevice: " << power << '\n';
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power) : PoweredDevice(power)
	{
		std::cout << "Printer: " << printer << '\n';
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power) : PoweredDevice(power)
	{
		std::cout << "Scanner: " << scanner << '\n';
	}
};

class CopyMachine : public Printer, public Scanner
{
public:
	CopyMachine(int printer, int scanner, int power) : Scanner(scanner, power), Printer(printer, power), PoweredDevice(power) {}
};

int main()
{
	CopyMachine(1, 2, 3);

	return 0;
}