#include <iostream>
#include <string>
#include <math.h>

double orbitalPeriod(std::string name, double avgAlt) {
	double orbitalPeriod{ 0.0 };

	double h{ avgAlt };
	double v, P;
	const double pi = 3.14159265359;

	v = sqrt(398600.4418 / (6367.4447 + h));
	P = 2 * pi * ((6367.4447 + h) / v);

	return P;
}

int main() {
	std::string name{ "Sputnik" };
	double avgAlt = 35873.5553;

	std::cout << "It takes " << round(orbitalPeriod(name, avgAlt)) << " seconds for " << name << " to orbit this planet.\n";

	return 0;
}