/* a test of working without header files */

#include <stdio.h>
#include "foo.h" // declaration of foo()

// this foo() always return 3
int foo() {
	return 3;
}
