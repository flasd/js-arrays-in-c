all: header object clean

header:
	gcc -E src/array.h -o dist/array.h

object: build merge

build:
	gcc -c src/acessors.c src/array.c src/iterators.c src/mutators.c

merge:
	ld --relocatable acessors.o array.o iterators.o mutators.o -o dist/array.o

clean:
	rm -rf *.o