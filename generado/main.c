#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"
#include "dec_data.c"


int ve;
int ve2;
int last;
int next;
int suma;
int cont;
struct listadeint lx;
struct listadeint lx2;
struct listadeint lx3;
int main(){
ve=5;
ve2=10;
last=1;
int tmp_0;
tmp_0 = next > last;
if(!tmp_0) goto etiqueta_0;
ve=ve2;
goto etiqueta_1;
etiqueta_0:
ve=ve;
etiqueta_1:
printf("%d%s",ve, "\n");

}