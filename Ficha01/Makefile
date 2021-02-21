#############Makefile##################

#to compile everything call make all
all: triangulo

triangulo: triangulo.o vertical.o horizontal.o

#to compile to a .o file
triangulo.o: triangulo.c
	gcc -c triangulo.c

vertical.o: vertical.c
	gcc -c vertical.c

horizontal.o: horizontal.c
	gcc -c horizontal.c

# delete all .o files
clean: rm *.o
