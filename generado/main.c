#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"


int ve;
int ve2;
int ve3;
bool bol;
bool A;
bool B;
int main(){
ve=1;
etiqueta_0:
int tmp_2;
tmp_2 = ve > 0;
if(!tmp_2) goto etiqueta_1;
int tmp_3;
tmp_3 = ve - 1;
ve=tmp_3;
goto etiqueta_0;
etiqueta_1:
printf("%d",ve2);
return 0;

}