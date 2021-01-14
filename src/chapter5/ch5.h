/*
 * one header file for all chapter 5 exercises 
 */


// exercise 5-1. read from standard input, using buffer to put back. 
int mygetint(int *pn);
int getch(void);
void ungetch(int c);
void clean_getch(void);

// exercise 5-2.
int mygetfloat(double *pn); 
void printstr(char *p, int size); 

// exercise 5-3. rewrite pointer version of ctrcpy() function
void mystrcat(char *s, char *t);

// exercise 5-4. write strend() function
int strend(char *s, char *t);

// exercise 5-5. mystrncpy(), mystrncat(), and mystrncmp()
char *mystrncpy(char *s, char *ct, int n);
char *mystrncat(char *s, char *ct, int n);
int mystrncmp(char *cs, char *ct, int n);
