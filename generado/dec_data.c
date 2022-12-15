#include <stdlib.h>
#include <stdio.h>
#ifndef DEC_DATA_H
#define DEC_DATA_H

 struct listadeint {
    int* var;
    int actual;
    int longitud;
    int last_pos;
} listadeint_default = {NULL,0,255,0};

void insertarint(struct listadeint* l, int a){
    if(l->var == NULL){
        l->var = malloc(sizeof(int)*255);
    }
    if(l->last_pos < l->longitud){
        *(l->var+l->last_pos+1) = a;
        l->last_pos++;
    }else{
        printf("OVERFLOW ERROR, lists only support 255 numbers");
        exit(-1);
    }
}

int getActualListaint(struct listadeint l){
    return *(l.var + l.actual);
}

void retrocederListaint(struct listadeint* l){
    if((*l).actual > 0)
        (*l).actual--;
}
void avanzarListaint(struct listadeint* l){
    if(l->actual<l->longitud)
        l->actual++;
}

void irAPosicionint(struct listadeint* l,int a){
    if(a>0 && a <l->longitud)
        l->actual = a;
    else{
        printf("\n[ERROR]: Out-of-bounds exception\n");
        exit(-1);
    }
}

int getElementoint(struct listadeint l, int a){
    int res = -1;
    if(a>0 && a <l.longitud)
        res = *(l.var +a);
    else{
        printf("\n[ERROR]: Out-of-bounds exception\n");
        exit(-1);
    }
    return res;
}

int getLongitudListaint(struct listadeint l){
    return l.last_pos;
}
#endif
