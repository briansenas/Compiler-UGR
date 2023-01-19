#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_func.c"
#include "dec_data.c"
#include "dec_complex.c"


int ve;
int v;
int c;
int g;
int n;
float vf;
float x;
float z;
float m;
float j;
char vc;
bool vl;
int pe;
int pe2;
float pf;
float pf2;
char pc;
char pc2;
bool pl;
bool pl2;
struct listadeint lx;
struct listadeint lz;
struct listadeint a;
int main(){
pe=pe2;
pe2=pe3;
vl=vc;
vf=1.3;
avanzarListaint(&lx);
retrocederListaint(&lx);
irAPosicionint(&lx,0);
int tmp_17;
tmp_17 = getActualListaint(lx);
ve=tmp_17;
int tmp_18;
tmp_18 = getLongitudListaint(lx);
ve=tmp_18;
int tmp_19;
tmp_19 = getActualListaint(pe);
lx=tmp_19;
desconocido tmp_20;
tmp_20 = getLongitudListaint(pe);
lx=tmp_20;
ve=lx;
ve=pe;
struct listadeint tmp_21;
tmp_21 = addElementAtint(lx,2,a);
lz=tmp_21;
struct listadeint tmp_22;
tmp_22 = removeElementint(lx,1);
lx=tmp_22;
struct listadeint tmp_23;
tmp_23 = addElementAtint(lx,2,pe);
lz=tmp_23;
int tmp_24;
tmp_24 = addElementAtint(pe,2,a);
lz=tmp_24;
struct listadeint tmp_25;
tmp_25 = removeElementint(lx,'h');
lx=tmp_25;
int tmp_26;
tmp_26 = removeElementint(pe,1);
lx=tmp_26;
struct listadeint tmp_27;
tmp_27 = borrarListaint(lx,0);
lx=tmp_27;
struct listadeint tmp_28;
tmp_28 = borrarListaint(lx,'h');
lx=tmp_28;
int tmp_29;
tmp_29 = pe % 0;
lx=tmp_29;
struct listadeint tmp_30;
tmp_30 = concatenerListas(lx,lz);
lx=tmp_30;
int tmp_31;
tmp_31 = concatenerListas(pe,lz);
lx=tmp_31;
struct listadeint tmp_32;
tmp_32 = IntOperationListaint(lx,1,1);
lx=tmp_32;
int tmp_33;
tmp_33 = getIntFromlistaint(lx,1,1);
a=tmp_33;
struct listadeint tmp_34;
tmp_34 = IntOperationListaint(lx,1,0);
lx=tmp_34;
struct listadeint tmp_35;
tmp_35 = IntOperationListaint(lx,1,2);
lx=tmp_35;
float tmp_36;
tmp_36 = getIntFromlistaint(lx,x,2);
a=tmp_36;
struct listadeint tmp_37;
tmp_37 = IntOperationListaint(lx,x,3);
lx=tmp_37;
return pl;

}