###
# foo.c and doo.c both contain a function called foo()
#
# foo.c and doo.c can be compiled correctly
#
# A collision will occur if we try to link foo.o and doo.o at a time
# 
# Declaration in header file is NOT safe
###

# run do nothing
run: 

# call foo() from foo.c
fromFoo: foo.o run.o
	gcc -o run foo.o run.o

# call foo() from doo.c
fromDoo: doo.o run.o
	gcc -o run doo.o run.o

# collision occurs when given two different version of function foo()
callBoth: foo.o doo.o run.o
	gcc -o run foo.o doo.o run.o

# *.o generated from *.c automatically by implicite rules


# clean
.PHONY: clean
clean:
	-rm *.o run
	

