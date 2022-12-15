#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"
#include "dec_data.c"


int ve;
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
tmp_7 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_7, " \n");
avanzarListaint(&lx);
int tmp_8;
tmp_8 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_8, " \n");
retrocederListaint(&lx);
int tmp_9;
tmp_9 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_9, " \n");
int tmp_10;
tmp_10 = getElementoint(lx,4);
printf("%s%d%s","Elemento Posicion 4: ", tmp_10, " \n");
printf("%s","Borrando lista por la mitad \n");
struct listadeint tmp_11;
tmp_11 = borrarListaint(lx,2);
lx=tmp_11;
int tmp_12;
tmp_12 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud nueva: ", tmp_12, " \n");
printf("%s","Concatenando listas...\n");
struct listadeint tmp_13;
tmp_13 = concatenerListas(lx,lx2);
lx=tmp_13;
int tmp_14;
tmp_14 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud Lx nueva: ", tmp_14, " \n");
int tmp_15;
tmp_15 = imprimirlista(lx);
ve=tmp_15;

}