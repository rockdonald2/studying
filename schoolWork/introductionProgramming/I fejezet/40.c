#include <stdio.h>
#include <stdlib.h>

void feleviJegyek() {
	printf("Add meg hany diak jegyet akarod beolvasni: ");
	int n;
	scanf("%d", &n);
	
	double *arr = (double*)malloc(n * sizeof(double));
	int bukok = 0;
	double atmenokOsszege = 0.0;
	
	for (int i = 0; i < n; ++i) {
		printf("Add meg az %d diak jegyet: ", i + 1);
		scanf("%lf", &arr[i]);
		
		if (arr[i] < 5.0) ++bukok;
		else if (arr[i] >= 5.0) atmenokOsszege += arr[i];
	}
	
	printf("Az altalad megadott jegyek alapjan %d diak kozul: %d megbuktak, es az atmenok atlaga %.3lf", n, bukok, atmenokOsszege / (n - bukok));
}

int main() {
	feleviJegyek();
	
	return 0;
}
