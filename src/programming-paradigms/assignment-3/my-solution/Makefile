#
# Compile and test vector and hashset
#

CC = gcc
# 1. C11 is the newest version of C language
# 2. -Wpointer-arith request a warning when addtion and subtraction are done
# on pointers to void and to functions, which is supported in GNU C.
CFLAGS = -g -Wall -std=gnu11 -Wpointer-arith
LDFLAGS = 

VECTOR_SRCS = vector.c
VECTOR_HDRS = $(VECTOR_SRCS:.c=.h)
VECTOR_OBJS = $(VECTOR_SRCS:.c=.o)	

MY_VECTOR_TEST_SRCS = myvectortest.c $(VECTOR_SRCS)
MY_VECTOR_TEST_OBJS = $(MY_VECTOR_TEST_SRCS:.c=.o)

VECTOR_TEST_SRCS = vectortest.c $(VECTOR_SRCS)
VECTOR_TEST_OBJS = $(VECTOR_TEST_SRCS:.c=.o)

SRCS = $(VECTOR_SRCS) myvectortest.c vectortest.c
HDRS = $(VECTOR_HDRS)
OBJS = $(SRCS:.c=.o) 

EXECUTABLES = my-vector-test vector-test

default: $(EXECUTABLES)

my-vector-test: Makefile.dependencies $(MY_VECTOR_TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(MY_VECTOR_TEST_OBJS) $(LDFLAGS)

vector-test: Makefile.dependencies $(VECTOR_TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(VECTOR_TEST_OBJS) $(LDFLAGS)

# 1. The dependencies below make use of make's default rules,
# under which a .o automatically depends on its .c and
# the action taken uses the $(CC) and $(CFLAGS) variables.
# These lines describe a few extra dependencies involved.

# 2. -MMD means write a dependencies file containing user headers.
# -MM likes -MMD, but also implies -E only do preprocess,
# and write to stand out by default.

# 3. Professor add this is to show us what the implicit rules
# look like. No efficiency purpose.

Makefile.dependencies:: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -MM $(SRCS) > Makefile.dependencies 

-include Makefile.dependencies

.PHONY: clean
clean:
	-rm -fr $(EXECUTABLES) $(OBJS) Makefile.dependencies