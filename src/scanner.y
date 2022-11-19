%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int yylex();
void yyerror(const char * mensaje);

int num_linea = 1;
int num_errores = 0;

#define YYERROR_VERBOSE

%}

// %error-verbose
//%define parse.error verbose

// A continuación declaramos los nombres simbólicos de los tokens.
// byacc se encarga de asociar a cada uno un código.
%token INI_VAR
%token FIN_VAR
%token PRINCIPAL
%token INI_BLOQUE
%token FIN_BLOQUE

%token BOOLEANO
%token CONSTANTE_NUM
%token CONSTANTE_CHAR
%token CONSTANTE_FLOAT
%token TIPO_DATO

%token SIGSIG
%token SIGNO

%token CADENA
%token LISTA
%token MIENTRAS
%token SI
%token ENTRADA
%token IMPRIMIR
%token DEVOLVER

%token DIRECCION
%token IDENT

%token OP_BINARIO
%token OP_UNARIO
%token OP_TERNARIO

%left OP_BINARIO
%right OP_UNARIO
%left OP_TERNARIO
%left SIGSIG

%token LLAVE_ABRE
%token LLAVE_CIERRA
%token PARENTESIS_ABRE
%token PARENTESIS_CIERRA
%token CORCHETE_ABRE
%token CORCHETE_CIERRA

%token COMA
%token PYC

%start programa

%%

programa: PRINCIPAL bloque;

bloque: INI_BLOQUE declar_de_variables_locales declar_de_subprogs sentencias FIN_BLOQUE;

declar_de_subprogs: declar_de_subprogs declar_subprog
                  |;

declar_subprog: cabecera_subprog bloque;

declar_de_variables_locales: INI_VAR variables_locales FIN_VAR;

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables;

cuerpo_declar_variables: tipo varios_identificador PYC;

varios_identificador: IDENT
    | varios_identificador COMA IDENT;

tipo: TIPO_DATO
    | LISTA TIPO_DATO;

cabecera_subprog: tipo IDENT  PARENTESIS_ABRE lista_parametros PARENTESIS_ABRE;

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

sentencia_si : SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencias;

sentencia_mientras: MIENTRAS PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia;

sentencia_entrada: nomb_entrada lista_variables PYC;

nomb_entrada: ENTRADA;

sentencia_salida: nomb_salida lista_expresiones_o_cadena PYC;

lista_variables: IDENT
               | DIRECCION lista_variables
               | IDENT DIRECCION IDENT;

lista_expresiones_o_cadena: expresion
    | DIRECCION lista_expresiones_o_cadena
    | CADENA
    | CADENA DIRECCION lista_expresiones_o_cadena;

nomb_salida: IMPRIMIR DIRECCION;

sentencia_retorno: DEVOLVER expresion PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA
    | OP_UNARIO expresion
    | expresion OP_UNARIO
    | expresion OP_BINARIO expresion
    | expresion SIGSIG expresion OP_TERNARIO
    | expresion
    | IDENT
    | constante
    | funcion
    | lista_constantes;

funcion: IDENT PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA;

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

contenido_lista_car : CADENA
    | CADENA  COMA contenido_lista_car;

constante: BOOLEANO
| CONSTANTE_NUM
| CONSTANTE_FLOAT
| CADENA;

%%

void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s\n", num_linea, msg) ;
	 num_errores++;
}
