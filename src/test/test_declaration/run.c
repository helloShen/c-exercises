/* 
 * call foo()
 */

#include <stdio.h>
#include "foo.h" // declaration of foo()

// call foo(), which function will be called?
int main() {
	int n = foo();
	if (n == 2) {
		printf("foo() from foo.c called\n");
	} else {	
		printf("foo() from doo.c called\n");
	}
}
