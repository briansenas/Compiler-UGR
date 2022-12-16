#include <stdio.h>
#include <stdbool.h>
#include "dec_data.c"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
extern int ve;
extern int ve2;
extern int last;
extern int next;
extern int suma;
extern int cont;
extern struct listadeint lx;
extern struct listadeint lx2;
extern struct listadeint lx3;
int imprimirlista(struct listadeint b)
{
ve=0;
etiqueta_0:
int tmp_0;
tmp_0 = getLongitudListaint(b);
int tmp_1;
tmp_1 = ve < tmp_0;
if(!tmp_1) goto etiqueta_1;
int tmp_2;
tmp_2 = getActualListaint(lx);
ve2=tmp_2;
printf("%d%s",ve2, "\t");
avanzarListaint(&lx);
int tmp_3;
tmp_3 = ve + 1;
ve=tmp_3;
goto etiqueta_0 ;
etiqueta_1:
printf("%s","\n");
irAPosicionint(&lx,0);


}
int fibonacci(int in)
{
last=0;
next=1;
struct listadeint tmp_4;
tmp_4 = addElementAtint(lx,0,1);
lx=tmp_4;
int tmp_5;
tmp_5 = in == 1;
if(!tmp_5) goto etiqueta_4;
struct listadeint tmp_6;
tmp_6 = addElementAtint(lx,0,1);
lx=tmp_6;
etiqueta_4:
int tmp_7;
tmp_7 = in == 2;
if(!tmp_7) goto etiqueta_7;
int tmp_8;
tmp_8 = getLongitudListaint(lx);
ve=tmp_8;
struct listadeint tmp_9;
tmp_9 = addElementAtint(lx,ve,next);
lx=tmp_9;
goto etiqueta_6 ;
etiqueta_7:
cont=2;
etiqueta_8:
int tmp_10;
tmp_10 = cont < in;
if(!tmp_10) goto etiqueta_9;
int tmp_11;
tmp_11 = last + next;
suma=tmp_11;
last=next;
next=suma;
int tmp_12;
tmp_12 = getLongitudListaint(lx);
ve=tmp_12;
struct listadeint tmp_13;
tmp_13 = addElementAtint(lx,ve,suma);
lx=tmp_13;
int tmp_14;
tmp_14 = cont + 1;
cont=tmp_14;
goto etiqueta_8 ;
etiqueta_9:
etiqueta_6:
printf("%s","Fibonacci en lista:\n");
return 0;


}
