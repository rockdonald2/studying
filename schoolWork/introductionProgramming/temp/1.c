#include <stdio.h>
#include <stdbool.h>

bool kisBetu(const char ch) {
	if ((int)ch >= 97 && (int)ch <= 122) return true;
	else return false;
}

int main() {
	char ch;
	printf("Gepelj be egy karaktert: ");
	scanf("%c%*c", &ch);
	printf("A kovetkezo karaktert gepelted be: %c\n", ch);
	
	printf("Az altalad begepelt karakter ");
	if (kisBetu(ch)) {
		printf("kisbetu.");
	} else {
		printf("nem kisbetu.");
	}
	
	return 0;
}
