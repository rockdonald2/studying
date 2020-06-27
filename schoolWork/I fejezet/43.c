#include <stdio.h>
#include <stdlib.h>

double lnko(double a, double b) {
	a = a < 0.0 ? -a : a;
	b = b < 0.0 ? -b : b;

	// a = nagyobb szam, b = kisebb szam
	while (a != b) {
		if (a > b) {
			double t = a - b;
			a = b;
			b = t;
		} else {
			double t = b - a;
			b = t;
		}
	}

	return a;
}

int main() {
	double a, b;
	printf("Adj meg ket egesz szamot: ");
	scanf("%lf %lf", &a, &b);

	printf("A ket szam (%.2lf, %.2lf) lnko-ja: %.2lf", a, b, lnko(a, b));

	return 0;
}
