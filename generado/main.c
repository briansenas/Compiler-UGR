#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"
#include "dec_data.c"


int ve;
int ve2;
struct listadeint lx;
struct listadeint lx2;
int main(){
struct listadeint tmp_4= listadeint_default;
insertarint(&tmp_4,1);
insertarint(&tmp_4,2);
insertarint(&tmp_4,3);
insertarint(&tmp_4,4);
lx=tmp_4;
struct listadeint tmp_5= listadeint_default;
insertarint(&tmp_5,5);
insertarint(&tmp_5,6);
lx2=tmp_5;
int tmp_6;
tmp_6 = getLongitudListaint(lx);
printf("%s%d%s","Longitud: ", tmp_6, " \n");
int tmp_7;
tmp_7 = imprimirlista(lx);
ve=tmp_7;
int tmp_8;
tmp_8 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_8, " \n");
avanzarListaint(&lx);
int tmp_9;
tmp_9 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_9, " \n");
retrocederListaint(&lx);
int tmp_10;
tmp_10 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_10, " \n");
int tmp_11;
tmp_11 = getElementoint(lx,4);
printf("%s%d%s","Elemento Posicion 4: ", tmp_11, " \n");
printf("%s","Borrando lista por la mitad \n");
struct listadeint tmp_12;
tmp_12 = borrarListaint(lx,2);
lx=tmp_12;
int tmp_13;
tmp_13 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud nueva: ", tmp_13, " \n");
printf("%s","Concatenando listas...\n");
struct listadeint tmp_14;
tmp_14 = concatenerListas(lx,lx2);
lx=tmp_14;
int tmp_15;
tmp_15 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud Lx nueva: ", tmp_15, " \n");
int tmp_16;
tmp_16 = imprimirlista(lx);
ve=tmp_16;
struct listadeint tmp_17;
tmp_17 = removeElementint(lx,1);
lx=tmp_17;
int tmp_18;
tmp_18 = imprimirlista(lx);
ve=tmp_18;

}