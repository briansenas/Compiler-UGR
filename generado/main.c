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
printf("%s","Introduzca un número--->:\n");
scanf("%d",&ve);
int tmp_35;
tmp_35 = fibonacci(ve);
ve=tmp_35;
struct listadeint tmp_36;
tmp_36 = concatenerListas(lx,lx);
lx=tmp_36;
int tmp_37;
tmp_37 = imprimirlista(lx);
ve=tmp_37;

}