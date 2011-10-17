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

int mod_div(int pub, int p) {
	int i = p;
	int j = pub;
	int y = p;
	int y2 = 0;
	int y1 = 1;
	int quotient = p;
	int remainder = p;
	if( pub >= p)
		return p;
	while( j > 0 ) {
		quotient = i / j;
		remainder = i - ( j * quotient );
		y = y2 - ( y1 * quotient );
		i = j;
		j = remainder;
		y2 = y1;
		y1 = y;
	}
	if( i != 1 )
		return p;
	if( y2 > 0 )	
		return y2 % p;
	else
		return p + y2;
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
