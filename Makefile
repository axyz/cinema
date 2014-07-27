.PHONY: default all clean test

default: all

all:

test:
	gcc lib/cinema.c test/test.c -o test/test
	test/test

clean:
	rm -f *.o
