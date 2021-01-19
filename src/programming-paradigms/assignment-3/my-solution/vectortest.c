#include "vector.h"
#include <stdio.h>
#include <ctype.h>


/**
 * VectorMapFunction passed to VectorMap
 */
static void PrintChar(void *elem, void *fp) {
	fprintf((FILE *)fp, "%c", *(char *)elem);
	fflush((FILE *)fp);
}

/**
 * Call VectorMap to print the entire vector to stdout
 */
static void PrintVector(vector *v) {
	VectorMap(v, PrintChar, stdout);
	fprintf(stdout, "\n");
}

/**
 * VectorCompareFunction
 */
static int CompareChar(const void *elemA, const void *elemB) {
	return (*(char *)elemA - *(char *)elemB);
}

static void TestAppend(vector *v) {
	char ch;
	int i;
	for (ch = 'Z'; ch >= 'A'; ch--) {
		VectorAppend(v, &ch);
	}
	fprintf(stdout, "First, here is the alphabet: ");
	PrintVector(v);
	for (i = 9; i >= 0; i--) {
		char n = '0' + i;
		VectorAppend(v, &n);
	}
	fprintf(stdout, "Now, here comes digits: ");
	PrintVector(v);	
}

static void TestSortSearch(vector *v) {
	VectorSort(v, CompareChar);
	fprintf(stdout, "After sort: ");
	PrintVector(v);
	char c = 'J';
	fprintf(stdout, "Search for %c --> @%d\n", c, VectorSearch(v, &c, CompareChar, 0, true));
	c = '$';
	fprintf(stdout, "Search for %c --> @%d\n", c, VectorSearch(v, &c, CompareChar, 0, true));
}

static void TestAt(vector *v) {
	int i;
	for (i = 0; i < VectorLength(v); i += 2) {
		char *elem = VectorNth(v, i);
		*elem = tolower(*elem);
	}
	fprintf(stdout, "After lowercase every other letter: ");
	PrintVector(v);
}

static void TestInsertDelete(vector *v) {
	char dash = '-';
	int i;
	for (i = 3; i < VectorLength(v); i+=4) {
		VectorInsert(v, &dash, i);	
	}
	fprintf(stdout, "After insert dashes: ");
	PrintVector(v);
	for (i = 3; i < VectorLength(v); i+=3) {
		VectorDelete(v, i);
	}
	fprintf(stdout, "After deleting dashes: ");
	PrintVector(v);
}

static void TestReplace(vector *v) {
	int found = 0;
	char toFind = 's', toReplace = '*';
	while ((found = VectorSearch(v, &toFind, CompareChar, found, false)) != -1) {
		VectorReplace(v, &toReplace, found);
	}
	fprintf(stdout, "After replace: ");
	PrintVector(v);
}

void SimpleTest(void) {
	fprintf(stdout, "--------------------------- Starting the basic test...\n");	
	vector alphabet;
	VectorNew(&alphabet, sizeof(char), NULL, 4);
	TestAppend(&alphabet);
	TestSortSearch(&alphabet);
	TestAt(&alphabet);
	TestInsertDelete(&alphabet);
	TestReplace(&alphabet);
	VectorDispose(&alphabet);
}
int main(void) {
	SimpleTest();
}