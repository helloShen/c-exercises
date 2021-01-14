/* 
 * exercise 5-5
 */

#include <stdio.h>

/* 
 * strncat: concatenate most n character of ct to end of s
 */
char * mystrncat(char *s, char *ct, int n) {
	char *sb = s;
	while (*s != '\0') s++;
	while (*ct != '\0' && n > 0) {
		*s++ = *ct++;
		n--;
	}
	*s = '\0';
	return sb;
}
