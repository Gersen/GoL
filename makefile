gol :  fonctions.o gol.o
	gcc -o gol fonctions.o gol.o

fonction.o: fonction.c
	gcc -o fonctions.o -c fonctions.c -W -Wall  -pedantic

gol.o : gol.c header.h
	gcc -o gol.o -c gol.c -W -Wall  -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf gol