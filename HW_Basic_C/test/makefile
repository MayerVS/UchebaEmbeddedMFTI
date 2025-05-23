all: prog

prog: test.o
	gcc -o prog test.o

test.o: test.c 
	gcc -c -o test.o test.c

clean: 
	rm -rf *.o prog