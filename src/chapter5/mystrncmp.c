/* 
 * exercise 5-5
 */

#include <stdio.h>

int mystrncmp(char *s, char *t, int n) {
	while (*s == *t) {
		if (*s == '\0' || --n == 0) return 0;
		s++; t++;
	}
	return *s - *t;
}
