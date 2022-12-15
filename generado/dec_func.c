#include <stdio.h>
#include <stdbool.h>
#include "dec_data.c"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
extern int ve;
extern struct listadeint lx;
extern struct listadeint lx2;
int funcionA(int b)
{
int tmp_0;
tmp_0 = b + ve;
return tmp_0;

}

