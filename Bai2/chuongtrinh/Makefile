all: test

test:	test.o abc.o
	gcc test.o abc.o -o test
test.o:	test.c
	gcc -c test.c -o test.o
abc.o:	abc.c
	gcc -c abc.c -o abc.o
clean:
	rm test test.o abc.o
	