#include <stdio.h>
#include <stdlib.h>
#include "mod_ops.h"

struct euklid R,L;

int mod_add(int i, int j, int p) {
	if( (p - i ) > j )
		return i -j;
	else
		return j - ( p - i);
}

int mod_sub(int i, int j, int p) {
	if(i < j) {
		return p + (i - j);
	} else {
		return i - j;
	}
}

int mod_mul(int i, int j, int p) {
	int product = i*j;
	return product % p;
}

int mod_div2(int x, int p) {
	if( x % 2 == 0)
		return x/2;
	else
		return p - ( (p - x) / 2) ;
}


int mod_div(int x, int y, int p) {
	struct euklid *r=&R, *l=&L, *n=0;

	if(y == 0)
		return p;
	if(x == 0)
		return 0;

	while(y%2 == 0) {
		y = y /2;
		x = mod_div2(x, p);
	}

	l->a=p-y;
	l->t=p-x;

	r->a=y;
	r->t=x;

	while( l->a % 2 == 0 ) {
		l->a = l->a / 2;
		l->t = mod_div2(l->t, p);
	}

	while( R.a > 1 && L.a > 1) {
		if(r->a > l->a) {
			n=l;
			l=r;
			r=n;	
		}

		l->a = mod_sub(l->a, r->a, p);
		l->t = mod_sub(l->t, r->t, p);

		while( l->a % 2 == 0 ) {
			l->a = l->a / 2;
			l->t = mod_div2(l->t, p);
		}
	}
	if( l->a == 1 )
		return l->t;
	else
		return r->t;
}

int mod_pow(int x, int n, int p) {
	int ret=1;
	int i=0;
	for(i=0; i < n; i++) {
		ret = mod_mul(ret,x, p);
	}
	return ret;
}

int mod_sqrt(int x, int p) {
	if( x <= 1 ) return x;
	if( mod_pow(x, (p-1)>>1, p) != 1) return p;
	if( ( (p+1) & 3) == 0)
		return mod_pow(x, (p+1) >> 2, p);
	printf("\nPrimzahl + 1 ist nicht glatt durch 4 teilbar.\n");
	exit(1);
}
