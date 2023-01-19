#include <stdlib.h>
#include <stdio.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#ifndef DEC_DATA_H
#define DEC_DATA_H

 struct listadeint {
    int* var;
    int actual;
    int longitud;
    int last_pos;
} listadeint_default = {NULL,0,255,1};

void insertarint(struct listadeint* l, int a){
    if(l->var == NULL){
        l->var = malloc(sizeof(int)*255);
        l->longitud = 255;
    }
    else if(l->last_pos >= l->longitud){
        l->var = realloc(l->var,sizeof(int)*l->longitud*2);
        l->longitud = l->longitud * 2;
    }
    if(l->last_pos < l->longitud){
        *(l->var+l->last_pos) = a;
        l->last_pos++;
    }else{
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
    if(l->actual<l->last_pos)
        l->actual++;
}

void irAPosicionint(struct listadeint* l,int a){
    if(a>=0 && a<l->last_pos)
        l->actual = a;
    else{
        printf("\n[ERROR GO-TO-LIST]: Out-of-bounds exception: %d \n",a);
        exit(-1);
    }
}

int getElementoint(struct listadeint l, int a){
    int res = -1;
    if(a>=0 && a<l.last_pos)
        res = *(l.var +a);
    else{
        printf("\n[ERROR GET]: Out-of-bounds exception: %d \n",a);
        exit(-1);
    }
    return res;
}

int getLongitudListaint(struct listadeint l){
    return l.last_pos;
}
struct listadeint borrarListaint(struct listadeint l,int a){
    if(a < l.last_pos){
        l.last_pos -= a;
        l.actual = MAX(l.actual-a,0);
    }else{
        printf("\n[ERROR LENGHT]: Out-of-bounds exception: %d \n",a);
        exit(-1);
    }

    return l;
}

struct listadeint concatenerListas(struct listadeint l, struct listadeint l2){
        for(int i=0;i<l2.last_pos;i++){
            *(l.var+l.last_pos+i) = *(l2.var+i);
        }
        l.last_pos += l2.last_pos;
    return l;
}

struct listadeint removeElementint(struct listadeint l, int a){
    if(a>=0 && a < l.last_pos){
        memcpy(l.var+a,l.var+l.last_pos-a-1,sizeof(int)*(l.last_pos-a-1));
        l.last_pos -= 1;
    }else{
        printf("\n[ERROR REMOVE]: Out-of-bounds exception: %d \n",a);
        exit(-1);
    }
    return l;
}

struct listadeint addElementAtint(struct listadeint l, int a, int b){
    if(l.var == NULL){
        l.var = malloc(sizeof(int)*255);
        l.longitud = 255;
    }
    else if(l.last_pos >= l.longitud){
        l.var = realloc(l.var,sizeof(int)*l.longitud*2);
        l.longitud = l.longitud * 2;
    }
    if(a>=0 && a<=l.last_pos){
        for(int i=a+1;i<l.last_pos;i++){
            *(l.var + i) = *(l.var+i-1);
        }
        *(l.var+a) = b;
        l.last_pos++;
    }else if(a==0){
        *(l.var+a) = b;
        l.last_pos++;
    }
    else{
        printf("\n[ERROR ADD]: Out-of-bounds exception: %d \n",a);
        exit(-1);
    }
    return l;
}

struct listadeint IntOperationListaint(struct listadeint l, int a, int op){
    switch(op){
        case 0:
            a *=-1;
        case 1:
            for(int i=0;i<l.last_pos;i++){
                *(l.var+i) = *(l.var+i) + a;
            }
            break;
        case 2:
            for(int i=0;i<l.last_pos;i++){
                *(l.var+i) = *(l.var+i) * a;
            }
            break;
        case 3:
            for(int i=0;i<l.last_pos;i++){
                *(l.var+i) = *(l.var+i) / a;
            }
            break;
    }

    return l;
}
int getIntFromlistaint(struct listadeint l, int a, int op){
    int res = a;
    switch(op){
        case 0:
            for(int i=0;i<l.last_pos;i++){
                res -= *(l.var+i);
            }
        case 1:
            for(int i=0;i<l.last_pos;i++){
                res += *(l.var+i);
            }
            break;
        case 2:
            for(int i=0;i<l.last_pos;i++){
                res *= *(l.var+i);
            }
            break;
        case 3:
            for(int i=0;i<l.last_pos;i++){
                res /= *(l.var+i);
            }
            break;
    }

    return res;
}
#endif
