#include <stdio.h>
#include <stdbool.h>
#include "dec_data.c"
#include "dec_complex.c"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
extern int ve;
extern int v;
extern int c;
extern int g;
extern int n;
extern float vf;
extern float x;
extern float z;
extern float m;
extern float j;
extern char vc;
extern bool vl;
extern int pe;
extern int pe2;
extern float pf;
extern float pf2;
extern char pc;
extern char pc2;
extern bool pl;
extern bool pl2;
extern struct listadeint lx;
extern struct listadeint lz;
extern struct listadeint a;
float funcionB(char b1,bool b2)
{
float vf;
char vc;
bool vl;
float xf;
float x2;
float funcionC(bool c1,int c2)
{
float x1;
int aux;
x1=1.3;
int tmp_0;
tmp_0 = c2 > 10;
if(!tmp_0) goto etiqueta_2;
int tmp_1;
tmp_1 = c2 - 1;
c2=tmp_1;
goto etiqueta_1 ;
etiqueta_2:
x1=3.1;
etiqueta_1:
return x1;


}
float funcionD(bool c1,int c2)
{
float x1;
x1=1.3;
int tmp_2;
tmp_2 = c2 > 10;
if(!tmp_2) goto etiqueta_5;
int tmp_3;
tmp_3 = c2 - 1;
c2=tmp_3;
goto etiqueta_4 ;
etiqueta_5:
x1=3.1;
etiqueta_4:
return x1;


}
float tmp_4;
tmp_4 = funcionC(true, 10);
xf=funcionC;
float tmp_5;
tmp_5 = funcionD(false, -2);
xf=funcionD;
float tmp_6;
tmp_6 = funcionC(false, 1);
float tmp_7;
tmp_7 = funcionC(true, 23);
float tmp_8;
tmp_8 = funcionC - funcionC;
float tmp_9;
tmp_9 = xf * tmp_8;
float tmp_10;
tmp_10 = tmp_9 / 10.0;
x2=tmp_10;
xf="Esto no debería funcionar";
float tmp_11;
tmp_11 = funcionC(10, true);
x2=funcionC;
etiqueta_6:
float tmp_12;
tmp_12 = funcionC(false, 2);
float tmp_13;
tmp_13 = x2 * funcionC;
float tmp_14;
tmp_14 = tmp_13 - xf;
float tmp_15;
tmp_15 = tmp_14 < 10.0;
if(!tmp_15) goto etiqueta_7;
float tmp_16;
tmp_16 = x2 * xf;
x2=tmp_16;
goto etiqueta_6 ;
etiqueta_7:
return x2;


}
