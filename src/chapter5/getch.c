/*
 * read next char from std input.
 * add a buffer for getchar() function in stdio.h
 * this will allow user to push back some characters once they
 * read too many.
 */

#include <stdio.h>

#define BUFSIZE 100	// maximum buffer size

char buff[BUFSIZE];		// buffer for ungetch 
int p = 0; 				// next free position in buffer

int getch(void) {
	return (p > 0)? buff[--p] : getchar();
}

void ungetch(int c) {
	if (p >= BUFSIZE) {
		printf("out of maximum buffer size!");
	} else {
		buff[p++] = c;
	}
}

void clean_getch(void) {
	p = 0;
}
