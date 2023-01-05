#include <stdlib.h>
#include <stdio.h>
#ifndef DEC_COMPLEX_H
#define DEC_COMPLEX_H

struct complejo {
    float real;
    float imag;
} compejodefault = {0.0,0.0};

struct complejo setComplex(float a, float b){
    struct complejo res;
    res.real = a;
    res.imag = b;
    return res;
}

float getImaginaria(struct complejo a){ return a.imag; }
float getReal(struct complejo a){ return a.real; }

#endif
