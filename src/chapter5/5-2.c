/* 
 * exercise 5-2
 */

#include <stdio.h>
#include <ctype.h>
#include "ch5.h"

int main(void) {
	printf("Give me a stream:");
	double *n;
	int res = mygetfloat(n);
	if (res > 0) {
		printf("Your number is: %lf\n", *n);
	} else if (res == EOF) {
		printf("Reach the end of input!\n");
	} else {
		printf("Please make sure to give us a legal number!\n");
	}
}
