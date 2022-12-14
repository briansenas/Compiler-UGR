#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"


int n;
int curr;
int ultim;
int cuenta;
int primero;
int main(){
curr=2;
ultim=0;
cuenta=0;
primero=1;
printf("%s","introduce un numero : ");
scanf("%d",&n);
printf("%d, %s",n, " == ");
curr=2;
int tmp_0;
tmp_0 = curr <= n;
if(!tmp_0) goto etiqueta_0;
int d;
int tmp_1;
tmp_1 = n / curr;
d=tmp_1;
int tmp_2;
tmp_2 = d * curr;
int tmp_3;
tmp_3 = tmp_2 == n;
if(!tmp_3) goto etiqueta_2;
int tmp_4;
tmp_4 = curr == ultim;
if(!tmp_4) goto etiqueta_4;
ultim=curr;
cuenta=1;
goto etiqueta_5;
etiqueta_4:
;int tmp_5;
tmp_5 = cuenta + 1;
cuenta=tmp_5;
etiqueta_5:
;int tmp_6;
tmp_6 = n / curr;
n=tmp_6;
goto etiqueta_3;
etiqueta_2:
;int tmp_7;
tmp_7 = cuenta > 0;
if(!tmp_7) goto etiqueta_6;
int tmp_8;
tmp_8 = primero == 0;
if(!tmp_8) goto etiqueta_8;
printf("%s"," *");
etiqueta_8:
;primero=0;
printf("%s, %d"," ", curr);
int tmp_9;
tmp_9 = cuenta > 1;
if(!tmp_9) goto etiqueta_10;
printf("%s, %d","^", cuenta);
etiqueta_10:
;etiqueta_6:
;etiqueta_3:
;int tmp_10;
tmp_10 = curr + 1;
curr=tmp_10;
cuenta=0;
etiqueta_0:
;int tmp_11;
tmp_11 = cuenta > 0;
if(!tmp_11) goto etiqueta_12;
int tmp_12;
tmp_12 = primero == 0;
if(!tmp_12) goto etiqueta_14;
printf("%s"," *");
etiqueta_14:
;primero=0;
printf("%s, %d"," ", curr);
int tmp_13;
tmp_13 = cuenta > 1;
if(!tmp_13) goto etiqueta_16;
printf("%s, %d","^", cuenta);
etiqueta_16:
;etiqueta_12:
;printf("%s","\n");
return 0;

}