# Project to understand language processing.
The main idea is to develop, slowly and iteratively, a language that is based on C
but with the following  principles:
- It must be based on spanish
- It must contain functions, not procedures.
- It must contain list based functions.

And we must comply with the following language processing steps:
- Syntact Analysis
- Semantic Analysis
- Intermedium code generation based on 4-tuples.

# How to compile?
Bruh:
```
clear && make clean && make && ./bin/scanner < examples/basic.txt && gcc -o main generado/main.c && ./main
```

# List operations
The following list operations are available:
```
    imprimir >> "Avanzando...\n";
    lx>>;
    imprimir >> "Retrocediento...\n";
    lx<<;
    imprimir >> "Elemento actual: " >> ?lx >> "\n";
    imprimir >> "Borrando lista por la mitad \n";
    lx = lx%2;
    imprimir >> "Elemento Longitud nueva: " >> #lx >> " \n";
    imprimir >> "Concatenando listas...\n";
    lx = lx**lx2;
    imprimir >> "Elemento Longitud Lx nueva: " >> #lx >> " \n";
    imprimir >> "Quitando elemento posición 1" >> "\n";
    lx = lx--1;
    imprimir >> "Añadiendo 1 en la posición 2" >> "\n";
    lx = lx++1@2;
    imprimir >> "Sumar 1 a la lista" >> "\n";
    lx = lx + 1;
    imprimir >> "Restar 1 a la lista" >> "\n";
    lx = lx - 1;
    imprimir >> "Multiplicar por 2 a la lista" >> "\n";
    lx = lx * 2;
    imprimir >> "Dividir por 2 a la lista" >> "\n";
    lx = lx / 2;
    ve = 1 + lx;
    imprimir >> ve >> "\t";
    ve = 1 - lx;
    imprimir >> ve >> "\t";
    ve = 1 * lx;
    imprimir >> ve >> "\t";
    ve = 1 / lx;
    imprimir >> ve >> "\t\n";
```
There are more examples on the `examples` folder.

## How to write a simple code?
1. Remember that functions must return something, always (we where to lazy to allow it not to).
2. Remember that the block goes like: __declar\_variables -> declar\_functions -> code block [..]__
3. Some lists operations are under-development and might have memory leakage or core dump xd

Better example:
```
principal(){
    imprimir >> "Hello World!\n";
}
```

