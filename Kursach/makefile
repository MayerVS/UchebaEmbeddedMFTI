all: prog

prog: main.o temp_api.o struct_api.o
	gcc -o prog main.o temp_api.o struct_api.o

main.o: main.c 
	gcc -c -o main.o main.c

temp_api.o: temp_api.c temp_api.h
	gcc -c -o temp_api.o temp_api.c

struct_api.o: struct_api.c struct_api.h
	gcc -c -o struct_api.o struct_api.c

clean: 
	rm -rf *.o prog 