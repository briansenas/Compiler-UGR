%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "y.tab.h"
#include "../include/scansemantic.h"

// int yylex();
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
        cuerpo_bloque
        FIN_BLOQUE
        {tsCleanIn();}

cuerpo_bloque: declar_de_variables_locales declar_de_subprogs sentencias
       | declar_de_variables_locales declar_de_subprogs;

declar_de_subprogs: declar_de_subprogs declar_subprog
                  |;

declar_subprog: cabecera_subprog {subProg=1;} bloque {subProg=0;};

declar_de_variables_locales: INI_VAR {decvariable=1;} variables_locales FIN_VAR {decvariable=0;}
                           |;

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables;

cuerpo_declar_variables: tipo {setType($0);} varios_identificador PYC
                       | error;

varios_identificador: IDENT {
                    printf("Se quiere declarar:  (%i) (%s) (%i) (%i).\n", $0.attr, $0.nombre, $0.tipoDato, $0.nDim);
					if(decvariable == 1){
                        printf("Se ha declarado una variable.\n");
						$0.nombre=$0.nombre; $0.nDim=0; $0.tamDimen1 = 0; $0.tamDimen2 = 0; tsAddId($0);
                        
					}else{
						if(decParam == 0)
							tsGetId($0, &$$);
					}
				}
    | varios_identificador COMA IDENT {
					if(decvariable == 1){
                        printf("Se ha declarado una variable.\n");
						$2.nDim=0; $2.tamDimen1 = 0; $2.tamDimen2 = 0; tsAddId($2);
					}else{
						if(decParam == 0)
							tsGetId($2, &$$);
					}
				};

tipo: TIPO_DATO
    | LISTA TIPO_DATO;

cabecera_subprog: tipo IDENT {
					if(decvariable == 1){
                        printf("Se ha declarado una variable.\n");
						$1.nDim=0; $1.tamDimen1 = 0; $1.tamDimen2 = 0; tsAddId($1);
					}else{
						if(decParam == 0)
							tsGetId($1, &$$);
					}
				} {tsAddSubprog($1);} PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA
                | error ;

lista_parametros: tipo IDENT {
					if(decvariable == 1){
                        printf("Se ha declarado una variable.\n");
						$1.nDim=0; $1.tamDimen1 = 0; $1.tamDimen2 = 0; tsAddId($1);
					}else{
						if(decParam == 0)
							tsGetId($1, &$$);
					}
				}
    | lista_parametros COMA tipo IDENT {
					if(decvariable == 1){
                        printf("Se ha declarado una variable.\n");
						$3.nDim=0; $3.tamDimen1 = 0; $3.tamDimen2 = 0; tsAddId($3);
					}else{
						if(decParam == 0)
							tsGetId($3, &$$);
					}
				}
    |;

sentencias: sentencias {decvariable=2;} sentencia
    |{decvariable=2;} sentencia;


sentencia: bloque
    | sentencia_asignacion
    | sentencia_si
    | sentencia_mientras
    | sentencia_entrada
    | sentencia_salida
    | sentencia_retorno;

sentencia_asignacion: IDENT OP_ASIGNACION expresion PYC{
    printf("el $0 es: (%s)",$0.nombre);
    printf("el $2 es: (%s)", $2.nombre);
    if($0.tipoDato != $2.tipoDato){
        printf("Semantic Error(%d): No son del mismo tipo.\n", line);
    }
    if(!equalSize($0,$2)){
        printf("Semantic Error(%d): No son del mismo tamanio.\n",line);
    }

};
sentencia_si: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia{
        if ($2.tipoDato != booleano){
            printf("Expression are not logic. \n");
        }}
            | SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia SINO sentencia{
                if($2.tipoDato != booleano){
                    printf("Expression are not logic");
                }
            } ;

sentencia_mientras: MIENTRAS PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia{
        if($2.tipoDato != booleano){
                printf("Semantic Error(%d): Expression are not logic.\n", line);
        }
};

sentencia_entrada: ENTRADA DIRECCION lista_variables PYC;

sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC;

lista_variables: IDENT
               | DIRECCION lista_variables
               | IDENT DIRECCION IDENT;

lista_expresiones_o_cadena: expresion
    | DIRECCION lista_expresiones_o_cadena
    | CADENA
    | CADENA DIRECCION lista_expresiones_o_cadena;

sentencia_retorno: DEVOLVER expresion {tsCheckReturn($1, &$$);} PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA { $$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $1.tamDimen1; $$.tamDimen2 = $1.tamDimen2; }
    | OP_UNARIO expresion {tsOpUnary($0, $1, &$$); }
    | expresion OP_UNARIO {tsOpUnary($1, $0, &$$); }
    | IDENT DIRECCION
    | expresion OP_TERNARIO CONSTANTE_NUM
    | expresion OP_OR expresion {tsOpOr($0, $1, $2, &$$); }
    | expresion OP_AND expresion {tsOpAnd($0, $1, $2, &$$); }
    | expresion OP_XOR expresion {tsOpXOr($0, $0, $2, &$$); }
    | expresion OP_RELACION expresion {tsOpRel($0, $1, $2, &$$); }
    | expresion OP_MULTIPLICATIVO expresion {tsOpMul($0, $1, $2, &$$); }
    | expresion OP_IGUALDAD expresion {tsOpEqual($0, $1, $2, &$$); }
    | expresion OP_ADITIVO expresion {tsOpAdditivo($0, $1, $2, &$$); }
    | OP_ADITIVO expresion {tsOpSign($0, $1, &$$); } %prec OP_UNARIO
    | expresion SIGSIG expresion {tsOpSignSign($0, $1, $2, &$$); }
    | IDENT { decvariable = 0;
        printf("Se ha usado un identificador en la expresion\n");
    }
    | constante {$$.tipoDato = $0.tipoDato; $$.nDim = $0.nDim; $$.tamDimen1 = $0.tamDimen1; $$.tamDimen2 = $0.tamDimen2; }
    | funcion {$$.tipoDato = $0.tipoDato; $$.nDim = $0.nDim; $$.tamDimen1 = $0.tamDimen1; $$.tamDimen2 = $0.tamDimen2; currentFunction = -1;}
    | lista_constantes
    | error ;

funcion: IDENT PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA { tsFunctionCall($0, &$$); }
       | IDENT PARENTESIS_ABRE PARENTESIS_CIERRA { tsFunctionCall($0, &$$); };

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

constante: BOOLEANO { $$.tipoDato = booleano; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_NUM { $$.tipoDato = entero; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_FLOAT { $$.tipoDato = real; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_CAR { $$.tipoDato = caracter; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; };

%%

#include "lex.yy.c"


void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s \n", yylineno, msg) ;
}
