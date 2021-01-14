/* to print string of chars */

#include <stdio.h>

void printstr(char *p, int size) {
	char *s = p;
	while (p - s < size && *p != '\0') {
		printf("%c", *p++);
	}
	printf("\n");
}


