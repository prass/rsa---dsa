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
	int offset = 0;
	public_key = rand() % phi;
	while(ggT(public_key, phi) > 1) {
		offset++;
		public_key = (rand() + offset) % phi;
	}
	return public_key;
}


int main( void ) {
	int p1 = 227, p2 = 31;
	int n = p1 * p2;
	int phi = (p1 - 1) * (p2 - 1); 
	int pub;
	int priv;
	int message[6] = {'h','a','l','l','o',0};
	int i = 0;
	srand(time(0));
	pub = get_public(phi);
	priv = mod_div(pub, phi);

	printf("Verschluessele Text...\n");
	for(i = 0; i < 6; i++) {
		printf("%c", (char)message[i]);
		message[i] = mod_pow(message[i],pub, n);
	}
	printf(" ----> ");
	for(i = 0; i < 6; i++) {
		printf("%c", (char)('!' + (message[i] % ('}' - '!'))));
	}
	printf("\n");
	printf("Entschluessele Text...\n");
	for(i = 0; i < 6; i++) {
		message[i] = mod_pow(message[i],priv, n);
		printf("%c", (char)message[i]);
	}
	printf("\n");

	printf("Pub: %d Priv: %d Phi: %d\n", pub, priv, phi);
	printf("%d * %d = %d\n", pub, priv, mod_mul(pub, priv, phi));

	return EXIT_SUCCESS;
}
