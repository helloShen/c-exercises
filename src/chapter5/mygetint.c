/*
 * get next integer from input into *pn
 */

#include<stdio.h>
#include<ctype.h>	// for isspace() & isdigit()
#include "ch5.h" 	// for getch() & ungetch()

/* get next integer from standard input stream,
 * 		return EOF, if reach the end of the file
 * 		return 0, if is not a legal integer
 * 		return a positive number, if is a legal integer 
 */
int mygetint(int *pn) {

	int c, sign;
	
	/* trim spaces */
	while (isspace(c = getch()));

	/* only if it's digital number, EOF, or -, +, go to next round,			
	 * otherwise die off and return 0 */
	if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
		ungetch(c);
		return 0;
	}

	/* treat EOF condition first */
	if (c == EOF) return c;

	/* treat the -, + condition
	 * read one more character */
	sign = 1;
	if (c == '-' || c == '+') {
		int nc = getch();
		if (!isdigit(nc)) {
			if (nc != EOF) ungetch(nc);
			ungetch(c);
			return 0;
		}
		if (c == '-') sign = -1;
		/* pass on to next step as if it was legal number */
		c = nc; 
	}
	
	/* legal number */
	*pn = 0;
	while (isdigit(c)) {
		*pn *= 10;
		*pn += (c - '0');
		c = getch();
	}
	if (c != EOF) {
		ungetch(c);
	}
	*pn *= sign;

	return c;
}
