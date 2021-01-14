/* 
 * Push a + or - not followed by a digit back on the input. 
 */

#include <stdio.h>
#include <ctype.h>
#include "ch5.h"

int main(void) {
	printf("Give me a stream:");
	int *n;
	int res = mygetint(n);
	if (res > 0) {
		printf("Your number is: %d\n", *n);
	} else if (res == EOF) {
		printf("Reach the end of input!\n");
	} else {
		printf("Please make sure to give us a legal number!\n");
	}
}
