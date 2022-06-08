CFLAGS = -c -Wall
CC = gcc
LIBS =  -lm 

all: kplrun

kplrun: main.o instructions.o vm.o
	${CC} main.o instructions.o vm.o -lm -lncurses -o kplrun

main.o: main.c
	${CC} ${CFLAGS} main.c

instructions.o: instructions.c
	${CC} ${CFLAGS} instructions.c

vm.o: vm.c
	${CC} ${CFLAGS} vm.c

clean:
	rm -f *.o *~

