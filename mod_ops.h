/* PRIME + 1 muss glatt durch 4 Teilbar sein, damit die Wurzelfunktion funktionier */
/* Geht auch mit anderen, allerdings wird die Wurzelfunktion dann schwieriger */
#define PRIME 8191

struct euklid {
	int a;
	int t;
};

int mod_add(int i, int j, int p = PRIME);
int mod_sub(int i, int j, int p = PRIME);
int mod_mul(int i, int j, int p = PRIME);
int mod_div(int x, int p = PRIME);
int mod_pow(int x, int n, int p = PRIME);
int mod_sqrt(int x, int p = PRIME);
