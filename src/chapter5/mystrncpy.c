/* 
 * exercise 5-5
 * mystrncpy(), mystrncat(), mystrncmp()
 */

#include <stdio.h>
#include "ch5.h"

char *mystrncpy(char *s, char *ct, int n) {
	char *sb = s;
	while (*s != '\0' && *ct != '\0' & n > 0) {
		*s++ = *ct++;
		n--;
	}
	while (*s != '\0' && n > 0) {
		*s++ = '\0';
		n--;
	}
	return sb;
}
