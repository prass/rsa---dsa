all: rsa calc_primes
rsa: rsa.c mod_ops.o
	g++ -g -Wall -o rsa rsa.c mod_ops.o
mod_ops.o: mod_ops.c mod_ops.h
	g++ -g -c -Wall mod_ops.c
calc_primes: calc_primes.c
	g++ -g -Wall -lm -o calc_primes calc_primes.c
clean:
	rm rsa *.o
.PHONY: clean
