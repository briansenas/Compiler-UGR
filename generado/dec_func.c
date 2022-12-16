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
int tmp_0;
tmp_0 = getLongitudListaint(b);
ve2=tmp_0;
etiqueta_0:
int tmp_1;
tmp_1 = getLongitudListaint(b);
int tmp_2;
tmp_2 = ve < tmp_1;
if(!tmp_2) goto etiqueta_1;
int tmp_3;
tmp_3 = getActualListaint(b);
ve2=tmp_3;
printf("%d%s",ve2, "\t");
avanzarListaint(&b);
int tmp_4;
tmp_4 = ve + 1;
ve=tmp_4;
goto etiqueta_0 ;
etiqueta_1:
printf("%s","\n");
irAPosicionint(&b,0);


}
int fibonacci(int in)
{
int multiplicarPorDos(int mul)
{
int multiplicarSiMisma(int a)
{
ve=0;
irAPosicionint(&lx,0);
etiqueta_2:
int tmp_5;
tmp_5 = getLongitudListaint(lx);
int tmp_6;
tmp_6 = ve < tmp_5;
if(!tmp_6) goto etiqueta_3;
int tmp_7;
tmp_7 = getActualListaint(lx);
ve=tmp_7;
int tmp_8;
tmp_8 = ve * ve;
ve=tmp_8;
int tmp_9;
tmp_9 = getLongitudListaint(lx3);
ve2=tmp_9;
struct listadeint tmp_10;
tmp_10 = addElementAtint(lx3,ve2,ve);
lx3=tmp_10;
avanzarListaint(&lx);
goto etiqueta_2 ;
etiqueta_3:
printf("%s","Multiplicando Lx * Lx:\n");
irAPosicionint(&lx,0);
int tmp_11;
tmp_11 = imprimirlista(lx3);
ve=tmp_11;
return 0;


}
printf("%s%d%s","Multiplicando por:", mul, "\n");
struct listadeint tmp_12;
tmp_12 = IntOperationListaint(lx,mul,2);
lx2=tmp_12;
int tmp_13;
tmp_13 = imprimirlista(lx2);
ve=tmp_13;
return 0;


}
last=0;
next=1;
int tmp_14;
tmp_14 = getLongitudListaint(lx);
ve=tmp_14;
struct listadeint tmp_15;
tmp_15 = addElementAtint(lx,ve,last);
lx=tmp_15;
int tmp_16;
tmp_16 = in < 2;
if(!tmp_16) goto etiqueta_6;
int tmp_17;
tmp_17 = getLongitudListaint(lx);
ve=tmp_17;
struct listadeint tmp_18;
tmp_18 = addElementAtint(lx,ve,next);
lx=tmp_18;
goto etiqueta_5 ;
etiqueta_6:
int tmp_19;
tmp_19 = in == 2;
if(!tmp_19) goto etiqueta_9;
int tmp_20;
tmp_20 = getLongitudListaint(lx);
ve=tmp_20;
struct listadeint tmp_21;
tmp_21 = addElementAtint(lx,ve,next);
lx=tmp_21;
int tmp_22;
tmp_22 = getLongitudListaint(lx);
ve=tmp_22;
struct listadeint tmp_23;
tmp_23 = addElementAtint(lx,ve,next);
lx=tmp_23;
goto etiqueta_8 ;
etiqueta_9:
int tmp_24;
tmp_24 = getLongitudListaint(lx);
ve=tmp_24;
struct listadeint tmp_25;
tmp_25 = addElementAtint(lx,ve,next);
lx=tmp_25;
int tmp_26;
tmp_26 = getLongitudListaint(lx);
ve=tmp_26;
struct listadeint tmp_27;
tmp_27 = addElementAtint(lx,ve,next);
lx=tmp_27;
last=1;
cont=2;
etiqueta_10:
int tmp_28;
tmp_28 = cont < in;
if(!tmp_28) goto etiqueta_11;
int tmp_29;
tmp_29 = last + next;
suma=tmp_29;
last=next;
next=suma;
int tmp_30;
tmp_30 = getLongitudListaint(lx);
ve=tmp_30;
struct listadeint tmp_31;
tmp_31 = addElementAtint(lx,ve,suma);
lx=tmp_31;
int tmp_32;
tmp_32 = cont + 1;
cont=tmp_32;
goto etiqueta_10 ;
etiqueta_11:
etiqueta_8:
etiqueta_5:
printf("%s","Fibonacci en lista:\n");
int tmp_33;
tmp_33 = imprimirlista(lx);
ve=tmp_33;
int tmp_34;
tmp_34 = multiplicarPorDos(2);
ve=tmp_34;
return 0;


}
