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

int main( void ) {
	int i = 1;
	for(i = 1; i < MAX; i = i + 2) {
		if(is_prime(i))
			printf("%d %d\n", (int)sizeof(int), i);
	}
}
