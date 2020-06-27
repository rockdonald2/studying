#include <stdio.h>
#include <stdlib.h>

void szamokLekerese(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("Gepelj be egy egesz szamot: ");
		scanf("%d%*c", &arr[i]);
	}
}

void kiir(int *arr, int n) {
	for (int j = 0; j < n; j++) printf("%d ", arr[j]);
}

int kereses(int *arr, int n, int celszam) {
	int bal = 0, jobb = n, kozepso;

	while (bal <= jobb) {
		kozepso = bal + (jobb - bal) / 2;

		if (arr[kozepso] == celszam) return kozepso;
		else if (arr[kozepso] < celszam) bal = kozepso + 1;
		else jobb = kozepso - 1;
	}

	return -1;
}

// selection sort
void rendez(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int legkisebb = i;

		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[legkisebb]) legkisebb = j;
		}

		int ideiglenes = arr[i];
		arr[i] = arr[legkisebb];
		arr[legkisebb] = ideiglenes;
	}
}

int main() {
	int n = 12;
	int *arr = (int*)malloc(n * sizeof(int));

	szamokLekerese(arr, n);
	rendez(arr, n);
	kiir(arr, n);
	printf("\nA keresett szam indexe: %d", kereses(arr, n, 9));

	return 0;
}
