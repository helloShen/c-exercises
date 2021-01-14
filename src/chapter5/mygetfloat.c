/*
 * exercise 5-2
 * get next float from input into *pn
 */

#include<stdio.h>
#include<ctype.h>	// for isspace() & isdigit()
#include "ch5.h" 	// for getch() & ungetch()


void consecutiveDigits(int *c, double *pn, int *offset);

/* 
 * get next float from standard input stream,
 * 		return EOF, if reach the end of the file
 * 		return 0, if is not a legal float number
 * 		return a positive number, if is a legal integer 
 */
int mygetfloat(double *pn) {

	int c, sign;
	
	/* trim spaces */
	while (isspace(c = getch()));

	/* only if it's digital number, EOF, -, +, or ., go to next round,
	 * otherwise die off and return 0 */
	if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
		ungetch(c);
		return 0;
	}

	/* treat EOF condition first */
	if (c == EOF) return c;

	/* in case of + or -, read one more character */
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
	int offset = -1; // turn off infraction counting 
	consecutiveDigits(&c, pn, &offset); 	
	/* if fraction exist */
	if (c == '.') c = getch();
	offset = 0;		// turn on infraction counting
	consecutiveDigits(&c, pn, &offset); 	
	if (c != EOF) ungetch(c);
	for (int i = 0; i < offset; i++) *pn /= 10;
	*pn *= sign;
	return c;
}

void consecutiveDigits(int *c, double *pn, int *offset) {
	while (isdigit(*c)) {
		*pn *= 10;
		*pn += (*c - '0');
		*c = getch();
		if (*offset >= 0) (*offset)++;
	}
}
	
