/* pointer version of strcat() in chapter 2 */

#include <stdio.h>

/* strcat: concatenate t to end of s
 * s must be big enough */
void mystrcat(char *s, char *t) {
	while (*s != '\0') s++;
	while ((*s++ = *t++) != '\0');
}
