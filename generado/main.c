#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"
#include "dec_data.c"
#include "dec_complex.c"


int ve;
int ve2;
int last;
int next;
int suma;
int cont;
float r;
float i;
struct listadeint lx;
struct listadeint lx2;
struct listadeint lx3;
struct complejo c1;
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
c1=setComplex(1,2);
float tmp_1;
tmp_1 = getImaginaria(c1);
i=tmp_1;
float tmp_2;
tmp_2 = getReal(c1);
r=tmp_2;
printf("%f%s%f%s%s",r, " - ", i, "i", "\n");

}