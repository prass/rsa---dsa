#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "mod_ops.h"

int ggT(int a, int b) {
	int tmp;
	while(b > 0 && a > 0) {
		if( b > a) {
			tmp = a;
			a = b;
			b = tmp;
		}
		a = a % b;
	}
	if( b > a) 
		return b;
	else
		return a;
}

int get_public(int phi) {
	int public_key;
	public_key = rand() % PRIME;
	while(ggT(public_key, phi) > 1) 
		public_key = rand() % PRIME;
	return public_key;
}


int main( void ) {
	int p1 = 13, p2 = 5;
	//int n = p1 * p2;
	int phi = (p1 - 1) * (p2 - 1); 
	int pub = PRIME;
	int priv = PRIME;
	srand(time(0));
	printf("%d \n", ggT(p1, p2));
	pub = get_public(phi);
	priv = mod_div(1,pub);
	printf("%d * %d = %d\n", pub, priv, mod_mul(pub, priv, phi));

	return EXIT_SUCCESS;
}
