rsa: rsa.c mod_ops.o
	g++ -g -Wall -o rsa rsa.c mod_ops.o
mod_ops.o: mod_ops.c mod_ops.h
	g++ -g -c -Wall mod_ops.c
clean:
	rm rsa *.o
.PHONY: clean
