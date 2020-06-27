#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Add meg hany szammal akarsz dolgozni: ");
	int n;
	scanf("%d", &n);
	
	int *arr = (int*)malloc(n * sizeof(int));
	
	int oszthato3 = 0, oszthato5 = 0, oszthato15 = 0;
	for (int i = 0; i < n; ++i) {
		printf("Add meg az %d szamot: ", i + 1);
		scanf("%d", &arr[i]);
		
		if (arr[i] % 3 == 0 && arr[i] % 5 == 0) ++oszthato15;
		else if (arr[i] % 3 == 0) ++oszthato3;
		else if (arr[i] % 5 == 0) ++oszthato5;
	}
	
	printf("Az altalad megadott szamok kozul %d oszthato 3-al, %d oszthato 5-el, es %d oszthato 15-el.", oszthato3, oszthato5, oszthato15);
	
	return 0;
}
