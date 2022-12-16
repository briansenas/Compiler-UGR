#include <stdio.h>
#include <stdbool.h>
#include "dec_data.c"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
extern int ve;
extern int ve2;
extern struct listadeint lx;
extern struct listadeint lx2;
int imprimirlista(struct listadeint b)
{
ve=0;
etiqueta_0:
int tmp_0;
tmp_0 = getLongitudListaint(b);
int tmp_1;
tmp_1 = ve < tmp_0;
if(!tmp_1) goto etiqueta_1;
{
int tmp_2;
tmp_2 = getActualListaint(lx);
printf("%d%s",tmp_2, "\t");
avanzarListaint(&lx);
int tmp_3;
tmp_3 = ve + 1;
ve=tmp_3;

}
goto etiqueta_0 ;
etiqueta_1:
printf("%s","\n");
irAPosicionint(&lx,0);

}

