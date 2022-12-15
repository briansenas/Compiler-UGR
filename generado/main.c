#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"
#include "dec_data.c"


int ve;
struct listadeint lx;
int main(){
struct listadeint tmp_1= listadeint_default;
insertarint(&tmp_1,1);
insertarint(&tmp_1,2);
insertarint(&tmp_1,3);
insertarint(&tmp_1,4);
lx=tmp_1;
int tmp_2;
tmp_2 = getLongitudListaint(lx);
printf("%s%d%s","Longitud: ", tmp_2, " \n");
int tmp_3;
tmp_3 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_3, " \n");
avanzarListaint(&lx);
int tmp_4;
tmp_4 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_4, " \n");
retrocederListaint(&lx);
int tmp_5;
tmp_5 = getActualListaint(lx);
printf("%s%d%s","Elemento Actual: ", tmp_5, " \n");
int tmp_6;
tmp_6 = getElementoint(lx,4);
printf("%s%d%s","Elemento Posicion 4: ", tmp_6, " \n");
printf("%s","Borrando lista por la mitad \n");
struct listadeint tmp_7;
tmp_7 = borrarListaint(lx,2);
lx=tmp_7;
int tmp_8;
tmp_8 = getLongitudListaint(lx);
printf("%s%d%s","Elemento Longitud nueva: ", tmp_8, " \n");

}