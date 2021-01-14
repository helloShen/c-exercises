/* 
 * exercise 5-4
 */

#include <stdio.h>
#include "ch5.h"

/* test strend() */
int main(void) {
	char s[100], t[100];
	printf("Give me string s (lenth < 100):");
	gets(s);
	printf("Give me string t (lenth < 100):");
	gets(t);
	printf("%c\n", (strend(s,t) == 1)? 'Y' : 'N');
}
