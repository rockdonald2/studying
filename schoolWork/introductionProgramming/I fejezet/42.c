#include <stdio.h>
#include <stdlib.h>

int algor(int *arr, int n) {
	int szamlalo = 0;
	
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 11 == 5) {
			int utolsoSzamjegy = (arr[i] % 10);
			int elsoSzamjegy = arr[i];
			
			while (elsoSzamjegy >= 10) {
				elsoSzamjegy /= 10;
			}
			
			if (2 * utolsoSzamjegy == elsoSzamjegy) ++szamlalo;
		}
	}
	
	return szamlalo;
}

int main() {
	printf("Add meg hany szamot akarsz beolvasni: ");
	int n;
	scanf("%d", &n);
	
	int *arr = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < n; ++i) {
		printf("Add meg (%d) szamot: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	printf("A szamok kozul %d olyan van amelynek a 11-el valo osztasi maradeka 5, es az elso szamjegye az utolso ketszerese.", algor(arr, n));
	
	return 0;
}
