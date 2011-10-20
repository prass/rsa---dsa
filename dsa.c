#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mod_ops.h"

struct sign {
	int s1;
	int s2;
};

struct pub_key {
	int q;
	int p;
	int g;
	int y;
};

int validate(struct sign si,struct pub_key pub, int m) {
	int w, u1, u2, s1_;
	/* m = 3; */
	w = mod_div(si.s2, pub.q);
	u1 = mod_mul(m, w, pub.q);
	u2 = mod_mul(si.s1, w, pub.q);
	s1_ = mod_mul( mod_pow(pub.g, u1, pub.p), mod_pow(pub.y, u2, pub.p), pub.p) % pub.q;
	return s1_ == si.s1;
}


int main( void ) {
	int m = 31;
	int x;
	int h;
	int s;
	struct sign si;
	int result;
	struct pub_key pub;

	srand(time(0));

	pub.p = 21599;
	pub.q = 10799;

	x = 1 + rand() % (pub.q - 1 );
	h = 1 + rand() % (pub.p - 1 );
	while( mod_pow(h , (pub.p - 1) / pub.q, pub.p)  == 1) {
		h++;
		h = h % pub.p;
	}
	pub.g = mod_pow(h, (pub.p - 1) / pub.q, pub.p);
	pub.y = mod_pow(pub.g, x, pub.p);

	s = 1 + rand() % (pub.q -1 );
	si.s1 = mod_pow(pub.g, s, pub.p) % pub.q;
	si.s2 = mod_mul( mod_div(s,pub.q) , mod_add(m, mod_mul( si.s1, x, pub.q), pub.q), pub.q);

	printf("g: %d y: %d x: %d h: %d", pub.g, pub.y, x, h);
	printf("s1: %d, s2: %d\n", si.s1, si.s2);

	result = validate(si, pub, m);
	printf("Validated: %d\n", result);

	return EXIT_SUCCESS;
}
