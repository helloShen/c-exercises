#####################################################
#
# generate all applications at once:
# 	make
# or one by one:
# 	make 5-1
# 	make 5-2
# 	...
#
# clear all generated files:
# 	make clean
#
#####################################################

# built-in variables
CC = gcc
CFLAGS = -g
DEPS = 

getint = mygetint.o getch.o
getfloat = mygetfloat.o getch.o
strcat = mystrcat.o printstr.o
strend = strend.o
strncpy = mystrncpy.o $(getint)
strncat = mystrncat.o
strncmp = mystrncmp.o

f1 = 5-1.o $(getint)
f2 = 5-2.o $(getfloat)
f3 = 5-3.o $(strcat)
f4 = 5-4.o $(strend)
f5 = 5-5.o $(strncpy) $(strncat) $(strncmp)

execs = 5-1 5-2 5-3 5-4 5-5
functions = $(f1) $(f2) $(f3) $(f4) $(f5)


# main event
runall: $(execs)

# *.o will be generated automatically by implicite rules
# "$@" implies the file name on the left side of :
# "$^" implies the file name on the right side of :
5-1: $(f1)
	$(CC) $(CFLAGS) -o $@ $^
5-2: $(f2) getch.o
	$(CC) $(CFLAGS) -o $@ $^
5-3: $(f3)
	$(CC) $(CFLAGS) -o $@ $^
5-4: $(f4)
	$(CC) $(CFLAGS) -o $@ $^
5-5: $(f5)
	$(CC) $(CFLAGS) -o $@ $^


# clean
.PHONY: clean
clean:	
	-rm $(execs) $(functions)
