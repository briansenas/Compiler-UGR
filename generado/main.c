#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"


int n;
int curr;
int main(){
printf("%s","introduce un numero : ");
scanf("%d",&n);
printf("%d%s",n, " == ");
curr=2;
etiqueta_0:
;int tmp_0;
tmp_0 = curr <= n;
if(!tmp_0) goto etiqueta_1;
int d;
int tmp_1;
tmp_1 = n / curr;
d=tmp_1;
int tmp_2;
tmp_2 = d * curr;
int tmp_3;
tmp_3 = tmp_2 == n;
if(!tmp_3) goto etiqueta_4;
printf("%d",curr);
int tmp_4;
tmp_4 = curr < n;
if(!tmp_4) goto etiqueta_7;
printf("%s"," * ");
etiqueta_7:
;int tmp_5;
tmp_5 = n / curr;
n=tmp_5;
goto etiqueta_3 ;
etiqueta_4:
;int tmp_6;
tmp_6 = curr + 1;
curr=tmp_6;
etiqueta_3:
;goto etiqueta_0 ;
etiqueta_1:
;printf("%s","\n");
return 0;

}