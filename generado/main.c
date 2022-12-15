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
struct listadeint tmp_1= listadeint_default;
insertarint(&tmp_1,1);
insertarint(&tmp_1,2);
insertarint(&tmp_1,3);
insertarint(&tmp_1,4);
lx=tmp_1;
struct listadeint tmp_2= listadeint_default;
insertarint(&tmp_2,5);
insertarint(&tmp_2,6);
lx2=tmp_2;
int tmp_3;
tmp_3 = getLongitudListaint(lx);
printf("%s%d%s","Longitud: ", tmp_3, " \n");
int tmp_4;
tmp_4 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_4, " \n");
avanzarListaint(&lx);
int tmp_5;
tmp_5 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_5, " \n");
retrocederListaint(&lx);
int tmp_6;
tmp_6 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_6, " \n");
int tmp_7;
tmp_7 = getElementoint(lx,4);
printf("%s%d%s","Elemento Posicion 4: ", tmp_7, " \n");
printf("%s","Borrando lista por la mitad \n");
struct listadeint tmp_8;
tmp_8 = borrarListaint(lx,2);
lx=tmp_8;
int tmp_9;
tmp_9 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud nueva: ", tmp_9, " \n");
printf("%s","Concatenando listas...\n");
struct listadeint tmp_10;
tmp_10 = concatenerListas(lx,lx2);
lx=tmp_10;
int tmp_11;
tmp_11 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud Lx nueva: ", tmp_11, " \n");

}