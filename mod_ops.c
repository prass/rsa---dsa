#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mod_ops.h"

int mod_add(int i, int j, int p) {
	if( (p - i ) > j )
		return i + j;
	else
		return j - ( p - i);
}

int mod_sub(int i, int j, int p) {
	return mod_add(i, p - j);
}

int mod_mul(int x, int y, int p) {
	int x1, x2;
	int y1, y2;
	int s = (int)sqrt((double)p);
	if( x == 0 || y == 0 ) return 0;
	if( x == 1 ) return y;
	if( y == 1 ) return x;
	if( x <= s && y <= s ) {
		return x * y;
	} else {
		x1 = x>>1;
		x2 = x - x1;
		y1 = y>>1;
		y2 = y - y1;
		return mod_add( mod_add( mod_add( mod_mul( x1, y1,p), mod_mul( x1, y2,p) ,p), mod_mul( x2, y1,p),p), mod_mul(x2,y2,p),p);
	}
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
	int r=1;
	while( n ) {
		if( (n&1) ) r = mod_mul(x, r, p);
		n>>=1;
		x = mod_mul(x, x, p);
	}
	return r % p;
}

int mod_sqrt(int x, int p) {
	if( x <= 1 ) return x;
	if( mod_pow(x, (p-1)>>1, p) != 1) return p;
	if( ( (p+1) & 3) == 0)
		return mod_pow(x, (p+1) >> 2, p);
	printf("\nPrimzahl + 1 ist nicht glatt durch 4 teilbar.\n");
	exit(1);
}
