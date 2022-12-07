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

programa: PRINCIPAL {tsAddSubprog($1);} {decParam = 1;} PARENTESIS_ABRE parametros {subProg=1;} bloque {subProg=0;}
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

declar_subprog:  cabecera_subprog {subProg=1;} bloque {subProg=0;};

declar_de_variables_locales: INI_VAR {decvariable=1;} variables_locales FIN_VAR {decvariable=0;}
                           |;

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables ;


cuerpo_declar_variables: tipo {setType($1);
            } varios_identificador PYC
                       | error;

cabecera_subprog: tipo IDENT {decParam = 1;} {tsAddSubprog($2);} PARENTESIS_ABRE parametros
                | error ;

parametros: lista_parametros PARENTESIS_CIERRA {tsUpdateNparam($1); nParam=0; decParam=0;} {$1.nDim=0;}
          | PARENTESIS_CIERRA {decParam=0;};

sentencias: sentencias {decvariable=2;} sentencia
    |{decvariable=2;} sentencia;

sentencia: bloque
    | sentencia_asignacion
    | sentencia_si
    | sentencia_mientras
    | sentencia_entrada
    | sentencia_salida
    | sentencia_retorno;

sentencia_asignacion: identificador OP_ASIGNACION expresion PYC{
    //printf("el $1 es: (%d)",$1.tipoDato);
    //printf("el $3 es: (%d)", $3.tipoDato);
    if($1.tipoDato != $3.tipoDato){

        printf("Semantic Error(%d): No son del mismo tipo.\n", line);
    }
    if(!equalSize($1,$3)){
        printf("Semantic Error(%d): No son del mismo tamanio.\n",line);
    }

};

sentencia_si: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia{
        if ($3.tipoDato != TIPOBOOL){
            printf("Expression are not logic. \n");
        }}
            | SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia SINO sentencia{
                if($3.tipoDato != TIPOBOOL){
                    printf("Expression are not logic");
                }
            } ;

sentencia_mientras: MIENTRAS PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia{
        if($3.tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Expression are not logic.\n", line);
        }
};

sentencia_entrada: ENTRADA DIRECCION lista_variables PYC;

sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC;

sentencia_retorno: DEVOLVER expresion {tsCheckReturn($2, &$$);} PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA { $$.tipoDato = $2.tipoDato; $$.nDim = $2.nDim; $$.tamDimen1 = $2.tamDimen1; $$.tamDimen2 = $2.tamDimen2; }
    | OP_UNARIO expresion {tsOpUnary($1, $2, &$$); }
    | expresion OP_UNARIO {tsOpUnary($2, $1, &$$); }
    | identificador DIRECCION
    | expresion OP_TERNARIO CONSTANTE_NUM
    | expresion OP_OR expresion {tsOpOr($1, $2, $3, &$$); }
    | expresion OP_AND expresion {tsOpAnd($1, $2, $3, &$$); }
    | expresion OP_XOR expresion {tsOpXOr($1, $2, $3, &$$); }
    | expresion OP_RELACION expresion {tsOpRel($1, $2, $3, &$$);}
    | expresion OP_MULTIPLICATIVO expresion {tsOpMul($1, $2, $3, &$$); }
    | expresion OP_IGUALDAD expresion {tsOpEqual($1, $2, $3, &$$); }
    | expresion OP_ADITIVO expresion {tsOpAdditivo($1, $2, $3, &$$); }
    | OP_ADITIVO expresion {tsOpSign($1, $2, &$$); } %prec OP_UNARIO
    | expresion SIGSIG expresion {tsOpSignSign($1, $2, $3, &$$); }
    | identificador { decvariable = 0;
        if(callSub)
            TS_subprog_params($1);
    }
    | constante {$$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $1.tamDimen1; $$.tamDimen2 = $0.tamDimen2;
        if(callSub)
            TS_subprog_params($1);
    }
    | funcion {$$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $0.tamDimen1; $$.tamDimen2 = $0.tamDimen2; currentFunction=-1;
        if(callSub)
            TS_subprog_params($1);
    }
    | lista_constantes
    | error ;

varios_identificador: identificador
    | varios_identificador COMA identificador;

identificador: IDENT {
                    if(decvariable == 1){
						$1.nDim=0; $1.tamDimen1 = 0; $1.tamDimen2 = 0; tsAddId($1); $1.tipoEnt = 2;
					}else{
                        if(decParam==0)
                            tsGetId($1, &$$);
					}
				};



lista_parametros:
    | lista_parametros COMA tipo identificador {$4.nDim=0; nParam++; setType($3); tsAddParam($4);}
    | tipo identificador {$2.nDim=0; nParam++; setType($1); tsAddParam($2);}
    | lista_parametros error tipo identificador;

lista_expresiones_o_cadena: lista_expresiones_o_cadena DIRECCION expresion_o_cadena {nParam++; tsCheckParam($1,nParam);}
                          | expresion_o_cadena{nParam=1;tsCheckParam($1,nParam);};

expresion_o_cadena: expresion
                  | CADENA ;

constante: BOOLEANO { $$.tipoDato = TIPOBOOL; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_NUM { $$.tipoDato = ENTERO; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_FLOAT { $$.tipoDato = REAL; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_CAR { $$.tipoDato = CARACTER; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; };

tipo: TIPO_DATO {$$.tipoDato = $1.tipoDato;}
    | LISTA TIPO_DATO {$$.tipoDato = $1.tipoDato;};

lista_variables: identificador
               | DIRECCION lista_variables
               | identificador DIRECCION identificador;

funcion: IDENT PARENTESIS_ABRE {callSub=1;}lista_expresiones PARENTESIS_CIERRA {tsFunctionCall($1,&$$);callSub=0;}
       | IDENT PARENTESIS_ABRE PARENTESIS_CIERRA {tsFunctionCall($1,&$$);};

lista_expresiones: lista_expresiones COMA expresion {nParam++;}
                 | expresion {nParam=1;}

lista_constantes: lista_constante_booleano {$1.lista=1;}
    | lista_constante_entero{$1.lista=1;}
    | lista_constante_flotante{$1.lista=1;}
    | lista_constante_car{$1.lista=1;};

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

%%

#include "lex.yy.c"


void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s \n", yylineno, msg) ;
}
