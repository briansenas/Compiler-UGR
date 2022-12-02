%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int yylex();
void yyerror(const char * mensaje);

#define YYERROR_VERBOSE

%}

// %error-verbose
//%define parse.error verbose

// A continuación declaramos los nombres simbólicos de los tokens.
// byacc se encarga de asociar a cada uno un código.

%left OP_OR expresion
%left OP_AND expresion
%left OP_XOR expresion
%left OP_RELACION expresion
%left OP_MULTIPLICATTIVO expresion
%left OP_IGUALDAD expresion
%left OP_ADITIVO expresion
%left OP_ASIGNACION expresion

%left OP_BINARIO
%right OP_UNARIO
%left OP_TERNARIO
%left SIGSIG

%token INI_VAR
%token FIN_VAR
%token PRINCIPAL
%token INI_BLOQUE
%token FIN_BLOQUE

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

bloque: INI_BLOQUE declar_de_variables_locales declar_de_subprogs sentencias FIN_BLOQUE
      | INI_BLOQUE declar_de_variables_locales declar_de_subprogs FIN_BLOQUE;

declar_de_subprogs: declar_de_subprogs declar_subprog
                  |;

declar_subprog: cabecera_subprog bloque;

declar_de_variables_locales: INI_VAR variables_locales FIN_VAR
                           |;

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables;

cuerpo_declar_variables: tipo varios_identificador PYC
                       | error;

varios_identificador: IDENT
    | varios_identificador COMA IDENT;

tipo: TIPO_DATO
    | LISTA TIPO_DATO;

cabecera_subprog: tipo IDENT  PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA
                | error ;

lista_parametros: tipo IDENT
    | lista_parametros COMA tipo IDENT
    |;

sentencias: sentencias sentencia
    | sentencia;


sentencia: bloque
    | sentencia_asignacion
    | sentencia_si
    | sentencia_mientras
    | sentencia_entrada
    | sentencia_salida
    | sentencia_retorno;

sentencia_asignacion: IDENT OP_BINARIO expresion PYC;

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
    | expresion OP_BINARIO expresion
    | expresion SIGSIG
    | SIGSIG expresion
    | expresion OP_TERNARIO CONSTANTE_NUM
    | expresion OP_OR expresion
    | expresion OP_AND expresion
    | expresion OP_XOR expresion
    | expresion OP_RELACION expresion
    | expresion OP_MULTIPLICATTIVO expresion
    | expresion OP_IGUALDAD expresion
    | expresion OP_ADITIVO expresion
    | expresion OP_ASIGNACION expresion
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
