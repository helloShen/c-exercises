/* test rewrite pointer version of strcat() */

#include <stdio.h>
#include <stdlib.h>
#include "ch5.h"

int main(void) {
	int size = 20;
	char *s = (char *) malloc(size * sizeof(char));
	*s = '\0';
	char *t1 = "hello ";
	char *t2 = "world!";
	printf("ready go!\n");
	printstr(s, size);
	mystrcat(s, t1);
	printstr(s, size);
	mystrcat(s, t2);
	printstr(s, size);
	free(s);
}

