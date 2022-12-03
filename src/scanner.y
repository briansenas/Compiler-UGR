%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "/include/scansemantic.h"

int yylex();
void yyerror(const char * mensaje);

#define YYERROR_VERBOSE

%}

// %error-verbose
%define parse.error verbose

// A continuación declaramos los nombres simbólicos de los tokens.
// byacc se encarga de asociar a cada uno un código.

%token INI_VAR
%token FIN_VAR
%token PRINCIPAL
%token INI_BLOQUE
%token FIN_BLOQUE

%left OP_OR
%left OP_AND
%left OP_XOR
%left OP_IGUALDAD
%left OP_RELACION
%left OP_ADITIVO
%left SIGSIG
%left OP_MULTIPLICATIVO

%right OP_UNARIO
%left OP_TERNARIO

%token OP_ASIGNACION
%token BOOLEANO
%token CONSTANTE_NUM
%token CONSTANTE_CAR
%token CONSTANTE_FLOAT
%token TIPO_DATO

%token CADENA
%token LISTA
%token MIENTRAS
%token SI
%token SINO
%token ENTRADA
%token IMPRIMIR
%token DEVOLVER

%token DIRECCION
%token IDENT

%token PARENTESIS_ABRE
%token PARENTESIS_CIERRA
%token CORCHETE_ABRE
%token CORCHETE_CIERRA

%token COMA
%token PYC

%start programa

%%

programa: PRINCIPAL PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA bloque
        | error;

bloque: INI_BLOQUE 
        {tsAddMark();}
        bloque2
        FIN_BLOQUE
        {tsCleanIn();}
      
bloque2: declar_de_variables_locales declar_de_subprogs sentencias
       | declar_de_variables_locales declar_de_subprogs;

declar_de_subprogs: declar_de_subprogs declar_subprog
                  |;

declar_subprog: cabecera_subprog {subProg=1;} bloque {subProg=0;};

declar_de_variables_locales: INI_VAR {decVar=1;} variables_locales FIN_VAR {decVar=0;}
                           |;

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables;

cuerpo_declar_variables: tipo {setType($1);} varios_identificador PYC
                       | error;

varios_identificador: IDENT {tsUpdateNparam($1); nParam=0, decParam=0;} {$1.nDim=0;}
    | varios_identificador COMA IDENT;

tipo: TIPO_DATO
    | LISTA TIPO_DATO;

cabecera_subprog: tipo IDENT {decParam=1;} {tsAddSubprog($2);} PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA
                | error ;

lista_parametros: tipo IDENT
    | lista_parametros COMA tipo IDENT
    |;

sentencias: sentencias {decVar=2;} sentencia
    |{decVar=2;} sentencia;


sentencia: bloque
    | sentencia_asignacion
    | sentencia_si
    | sentencia_mientras
    | sentencia_entrada
    | sentencia_salida
    | sentencia_retorno;

sentencia_asignacion: IDENT OP_ASIGNACION expresion PYC{
    if($1.tipoDato != $3.tipoDato){
        printf("they are not equal \n");
    }
    if(!equalSize($1,$3){
        printf("size is not equal \n");
    }

};

sentencia_si: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia
            | SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia SINO sentencia ;

sentencia_mientras: MIENTRAS PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia;

sentencia_entrada: ENTRADA DIRECCION lista_variables PYC;

sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC;

lista_variables: IDENT
               | DIRECCION lista_variables
               | IDENT DIRECCION IDENT;

lista_expresiones_o_cadena: expresion
    | DIRECCION lista_expresiones_o_cadena
    | CADENA
    | CADENA DIRECCION lista_expresiones_o_cadena;

sentencia_retorno: DEVOLVER expresion PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA
    | OP_UNARIO expresion
    | expresion OP_UNARIO
    | IDENT DIRECCION
    | expresion OP_TERNARIO CONSTANTE_NUM
    | expresion OP_OR expresion
    | expresion OP_AND expresion
    | expresion OP_XOR expresion
    | expresion OP_RELACION expresion
    | expresion OP_MULTIPLICATIVO expresion
    | expresion OP_IGUALDAD expresion
    | expresion OP_ADITIVO expresion
    | OP_ADITIVO expresion %prec OP_UNARIO
    | expresion SIGSIG expresion
    | IDENT
    | constante
    | funcion
    | lista_constantes
    | error ;

funcion: IDENT PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA
       | IDENT PARENTESIS_ABRE PARENTESIS_CIERRA;

lista_expresiones: lista_expresiones COMA expresion
                 | expresion;

lista_constantes: lista_constante_booleano
    | lista_constante_entero
    | lista_constante_flotante
    | lista_constante_car;

lista_constante_booleano: CORCHETE_ABRE contenido_lista_booleano CORCHETE_CIERRA;

contenido_lista_booleano: BOOLEANO
    | BOOLEANO COMA contenido_lista_booleano;

lista_constante_entero: CORCHETE_ABRE contenido_lista_entero CORCHETE_CIERRA;

contenido_lista_entero: CONSTANTE_NUM
    | CONSTANTE_NUM COMA contenido_lista_entero;

lista_constante_flotante: CORCHETE_ABRE contenido_lista_flotante CORCHETE_CIERRA;

contenido_lista_flotante: CONSTANTE_FLOAT
    | CONSTANTE_FLOAT COMA contenido_lista_flotante;

lista_constante_car : CORCHETE_ABRE contenido_lista_car CORCHETE_CIERRA;

contenido_lista_car : CONSTANTE_CAR
    | CONSTANTE_CAR COMA contenido_lista_car;

constante: BOOLEANO
| CONSTANTE_NUM
| CONSTANTE_FLOAT
| CONSTANTE_CAR;

%%
