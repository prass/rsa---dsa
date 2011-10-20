all: rsa calc_primes dsa
rsa: rsa.c mod_ops.o
	g++ -g -Wall -o rsa rsa.c mod_ops.o
mod_ops.o: mod_ops.c mod_ops.h
	g++ -g -c -Wall mod_ops.c
calc_primes: calc_primes.c
	g++ -g -Wall -lm -o calc_primes calc_primes.c
dsa: dsa.c mod_ops.o
	g++ -g -Wall -o dsa dsa.c mod_ops.o
clean:
	rm dsa rsa *.o calc_primes
.PHONY: clean all
