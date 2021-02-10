#include <stdio.h>
#include <stdbool.h>

bool maganhangzo(const char ch) {
	switch(ch) {
		case 'a':
		case 'e':
		case 'u':
		case 'i':
		case 'o':
		case 'A':
		case 'E':
		case 'U':
		case 'I':
		case 'O':
			return true;
		default:
			return false;
	}
}

int main() {
	printf("Gepelj be valamilyen betut (a-z vagy A-Z): ");
	char ch;
	scanf("%c", &ch);
	printf("A kovetkezo betut gepelted be: %c\n", ch);
	
	if (maganhangzo(ch)) {
		printf("Az altalad begepelt karakter (%c) maganhangzo.", ch);
	} else {
		printf("Az altalad begepelt karakter (%c) massalhangzo.", ch);
	}
	
	return 0;
}
