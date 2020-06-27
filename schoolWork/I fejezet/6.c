#include <stdio.h>

int main() {
	float x, y;
	printf("Irj be szokozzel elvalasztva ket szamot: ");
	scanf("%f %f", &x, &y);
	
	if (x > y) {
		printf("Hanyadosuk: %.2f, es maradekuk: %d", x / y, (int)x % (int)y);
	} else {
		printf("Hanyadosuk: %.2f, es maradekuk: %d", y / x, (int)y % (int)x);
	}
	
	return 0;
}
