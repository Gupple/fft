test : complex.o matrix.o main.o
	gcc -o test main.o complex.o matrix.o

main.o : main.c
	gcc -c main.c

complex.o : complex.c
	gcc -c complex.c

matrix.o : matrix.c
	gcc -c matrix.c

clean : 
	rm test main.o complex.o matrix.o

