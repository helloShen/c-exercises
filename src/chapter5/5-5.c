/* 
 * exercise 5-5
 * mystrncpy(), mystrncat(), mystrncmp()
 */

#include <stdio.h>
#include <ctype.h>
#include "ch5.h"

void testCpy(void);
void testCat(void);
void testCmp(void);


int main(void) {
	//testCpy();
	//testCat();
	testCmp();
}

void testCpy(void) {
	printf("Give me string s:");
	char s[100];
	gets(s);
	printf("Give me string t:");
	char t[100];
	gets(t);
	int size;
	int flag;
	do {
		printf("Give me max characters (positive integer):");
		// clean getch buffer array before reuse it.
		clean_getch();
		flag =  mygetint(&size);
	} while (flag <= 0 || flag == EOF || size < 0);
	printf("After strncpy(): %s\n", mystrncpy(s, t, size));
}

void testCat(void) {
	printf("Give me string s:");
	char s[100];
	gets(s);
	printf("Give me string t:");
	char t[100];
	gets(t);
	int size;
	int flag;
	do {
		printf("Give me max characters (positive integer):");
		// clean getch buffer array before reuse it.
		clean_getch();
		flag =  mygetint(&size);
	} while (flag <= 0 || flag == EOF || size < 0);
	printf("After strncat(): %s\n", mystrncat(s, t, size));
}

void testCmp(void) {
	printf("Give me string s:");
	char s[100];
	gets(s);
	printf("Give me string t:");
	char t[100];
	gets(t);
	int size;
	int flag;
	do {
		printf("Give me max characters (positive integer):");
		// clean getch buffer array before reuse it.
		clean_getch();
		flag =  mygetint(&size);
	} while (flag <= 0 || flag == EOF || size < 0);
	int res = mystrncmp(s, t, size);
	char op; 
	if (res > 0) {
		op = '>';
	} else if (res < 0) {
		op = '<';
	} else {
		 op = '=';
	}
	printf("%s %c %s\n", s, op, t);
}
