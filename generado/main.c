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
ve=-1;
etiqueta_0:
{
int tmp_2;
tmp_2 = ve < 0;
if(!tmp_2) goto etiqueta_1;
ve=1;
etiqueta_2:
{
int tmp_3;
tmp_3 = ve > 3;
if(!tmp_3) goto etiqueta_3;
ve=1;
etiqueta_4:
{
bool tmp_4;
tmp_4 = bol && A;
if(!tmp_4) goto etiqueta_5;
ve=1;
goto etiqueta_4;
}
etiqueta_5:
goto etiqueta_2;
}
etiqueta_3:
goto etiqueta_0;
}
etiqueta_1:
ve=0;
return ve;

}