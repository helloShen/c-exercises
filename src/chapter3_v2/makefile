#####################################################
#
# generate all applications at once:
# 	make
# or one by one:
# 	make 3-1
# 	make 3-2
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

execs = 3-1 3-2 3-3 3-4 3-5 3-6

# main event
runall: $(execs)

# *.o will be generated automatically by implicite rules
# "$@" implies the file name on the left side of :
# "$@" implies the file name on the left side of :
3-1: 3-1.o
	$(CC) $(CFLAGS) -o $@ $^
3-2: 3-2.o
	$(CC) $(CFLAGS) -o $@ $^
3-3: 3-3.o
	$(CC) $(CFLAGS) -o $@ $^
3-4: 3-4.o
	$(CC) $(CFLAGS) -o $@ $^
3-5: 3-5.o
	$(CC) $(CFLAGS) -o $@ $^
3-6: 3-6.o
	$(CC) $(CFLAGS) -o $@ $^

# clean
.PHONY: clean
clean:	
	-rm $(execs) *.o
