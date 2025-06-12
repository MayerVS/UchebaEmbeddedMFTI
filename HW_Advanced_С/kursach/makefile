all: prog clean

prog: main.o f.o func.o
	gcc -o prog main.o f.o func.o

main.o: main.c 
	gcc -c -o main.o main.c

f.o: f.c f.h
	gcc -c -o f.o f.c

func.o: func.c func.h
	gcc -c -o func.o func.c

clean: 
	rm -rf *.o