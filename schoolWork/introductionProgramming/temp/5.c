#include <stdio.h>
#include <math.h>

double func(int x) {
	if (x < -1) return 2;
	else if (x >= -1 && x < 1) return x * x - 1;
	else return sqrt(x);
}

int main() {
	printf("A fuggveny a kovetkezo alakot olti: \n");
	printf("f(x) = 2, ha x < -1\n");
	printf("f(x) = x^2 - 1, ha -1 <= x < 1\n");
	printf("f(x) = sqrt(x), ha x >= 1\n\n");
	
	int x;
	printf("Add meg az x egesz erteket: ");
	scanf("%d%*c", &x);
	printf("Az f(%d) erteke: %f", x, func(x));

	return 0;
}
