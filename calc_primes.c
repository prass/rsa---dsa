#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 1000

int is_prime(int number) {
	int i = 3;
	int wurzel = (int)sqrt((double)number);
	if(number < 3) return 1;
	if( !(number&1) ) return 0;
	for(i = 3; i <= wurzel; i = i + 2) {
		if(number % i == 0) return 0;
	}
	return 1;
}

int main( int argc, char *argv[] ) {
	int i = 1;
	if(argc < 2) return EXIT_FAILURE;
	for(i = 1; i < atoi(argv[1]); i = i + 2) {
		if(is_prime(i))
			printf("%d %d\n", (int)sizeof(int), i);
	}
}
