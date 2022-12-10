
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "y.tab.h"
#include "../include/scansemantic.h"

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

programa: {abrirArchivos();}PRINCIPAL {tsAddSubprog($1);} {decParam = 1;} PARENTESIS_ABRE {fputs("int main(",MAIN);}parametros PARENTESIS_CIERRA bloque {fputs(")",MAIN);cerrarArchivos();}
    | error;

bloque: INI_BLOQUE
    {tsAddMark();
    cMarkIn();
    }
    cuerpo_bloque
    FIN_BLOQUE {cMarkOut();}
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


cuerpo_declar_variables: tipo { setType($1); Many=1;} varios_identificador {Many=0;}PYC
                   | error;

cabecera_subprog: tipo IDENT {$2.tipoDato = $1.tipoDato;tsAddSubprog($2);tipoAtipoC($1);  decParam = 1; cWriteIdent($2); } PARENTESIS_ABRE {fputs("(",MAIN);} parametros PARENTESIS_CIERRA{fputs(")",MAIN);}
                | error ;

parametros: lista_parametros {tsUpdateNparam($1); nParam=0; decParam=0;} {$1.nDim=0;}

lista_parametros:
    | lista_parametros COMA tipo identificador {
    $4.nDim=0; nParam++; setType($3); tsAddParam($4); tipoAtipoC($3); cWriteIdent($4);
    }
    | tipo identificador {$2.nDim=0; nParam++; setType($1); tsAddParam($2);
    tipoAtipoC($1); cWriteIdent($2);
    };

sentencias: sentencias {decvariable=2;} sentencia
    |{decvariable=2;} sentencia;

sentencia: bloque
    | sentencia_asignacion
    | sentencia_si
    | sentencia_mientras
    | sentencia_entrada
    | sentencia_salida
    | sentencia_retorno
    | identificador DIRECCION PYC {
    if(!tsCheckList($1)){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    }
    | DIRECCION identificador PYC {
    if(!tsCheckList($2)){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    }

sentencia_asignacion: identificador OP_ASIGNACION expresion PYC{
    if($1.tipoDato != $3.tipoDato){
        printf("Semantic Error(%d): El valor a asignar no es del mismo tipo.[Expected: %s - Got:%s]\n",
        line, tipoAstring($1.tipoDato),tipoAstring($3.tipoDato));
    }
    if(!equalSize($1,$3)){
        printf("Semantic Error(%d): El valor a asignar no es del mismo tamanio.\n",line);
    }
    if(tsCheckList($1)){
        if(!$3.lista){
            printf("Semantic Error(%d): No se puede asignar porque tienen que ser de tipo lista.\n",line);
        }
    }

};

sentencia_si: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia{
        if ($3.tipoDato != TIPOBOOL){
            printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }}
            | SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia SINO sentencia{
                if($3.tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
                }
            } ;

sentencia_mientras: MIENTRAS PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia{
        if($3.tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
};

sentencia_entrada: ENTRADA DIRECCION lista_variables PYC;

sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC;

sentencia_retorno: DEVOLVER expresion {tsCheckReturn($2, &$$);} PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA {
    $$.tipoDato = $2.tipoDato; $$.nDim = $2.nDim; $$.tamDimen1 = $2.tamDimen1; $$.tamDimen2 = $2.tamDimen2; }
    | OP_UNARIO expresion {tsOpUnary($1, $2, &$$); }
    | expresion OP_UNARIO {tsOpUnary($2, $1, &$$); }
    | expresion OP_TERNARIO CONSTANTE_NUM {tsCheckLeftList($1,$3,&$$);}
    | expresion OP_OR expresion {tsOpOr($1, $2, $3, &$$); }
    | expresion OP_AND expresion {tsOpAnd($1, $2, $3, &$$); }
    | expresion OP_XOR expresion {tsOpXOr($1, $2, $3, &$$); }
    | expresion OP_RELACION expresion {tsOpRel($1, $2, $3, &$$);}
    | expresion OP_MULTIPLICATIVO expresion {tsOpMul($1, $2, $3, &$$); }
    | expresion OP_IGUALDAD expresion {tsOpEqual($1, $2, $3, &$$); }
    | expresion OP_ADITIVO expresion {tsOpAdditivo($1, $2, $3, &$$); }
    | OP_ADITIVO expresion {tsOpSign($1, $2, &$$); } %prec OP_UNARIO
    | expresion SIGSIG expresion {tsOpSignSign($1, $2, $3, &$$); }
    | identificador { decvariable = 0; }
    | constante {
        $$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $1.tamDimen1;
        $$.tamDimen2 = $1.tamDimen2;
    }
    | funcion {
        $$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $1.tamDimen1;
        $$.tamDimen2 = $1.tamDimen2; $$.lista = $1.lista;
    }
    | lista_constantes {$$.tipoDato = $1.tipoDato;$$.lista = $1.lista;}
    | error ;

varios_identificador: identificador
    | varios_identificador COMA identificador;

identificador: IDENT {
                    if(decvariable == 1){
						$1.nDim=0; $1.tamDimen1 = 0; $1.tamDimen2 = 0;
                        $1.tipoDato = globaltipoDato; $1.lista = globalLista; $1.es_constante = 0;
						$$.nDim=0; $$.tamDimen1 = 0; $$.tamDimen2 = 0;
                        $$.tipoDato = globaltipoDato; $$.lista = globalLista; $$.es_constante = 0;
                        if(Many){
                            tipoAtipoC($1);
                            Many = 0;
                        }

                        tsAddId($1);
					}else{
                        if(decParam==0)
                            tsGetId($1, &$$);

					}
                    if(!decParam)
                        cWriteIdent($1);
				};




lista_expresiones_o_cadena: lista_expresiones_o_cadena DIRECCION expresion_o_cadena
                          | expresion_o_cadena;

expresion_o_cadena: expresion
                  | CADENA ;

constante: BOOLEANO { $$.tipoDato = TIPOBOOL; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_NUM { $$.tipoDato = ENTERO; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_FLOAT { $$.tipoDato = REAL; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; }
| CONSTANTE_CAR { $$.tipoDato = CARACTER; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; };

tipo: TIPO_DATO {$$.tipoDato = $1.tipoDato;$$.lista=0;}
    | LISTA TIPO_DATO {$$.tipoDato = $2.tipoDato; $$.lista=1;};

lista_variables: identificador
               | DIRECCION lista_variables
               | identificador DIRECCION identificador;

funcion: IDENT PARENTESIS_ABRE {fputs("(",MAIN);} lista_expresiones PARENTESIS_CIERRA {fputs(")",MAIN);tsFunctionCall($1,&$$);}
       | IDENT PARENTESIS_ABRE PARENTESIS_CIERRA {fputs("()",MAIN); tsFunctionCall($1,&$$);};

lista_expresiones: lista_expresiones COMA expresion {nParam++; TS_subprog_params($3);}
                 | expresion {nParam=1; TS_subprog_params($1);}

lista_constantes: lista_constante_booleano {$$.lista=1; $$.tipoDato=TIPOBOOL;}
    | lista_constante_entero{$$.lista=1;$$.tipoDato=ENTERO;}
    | lista_constante_flotante{$$.lista=1;$$.tipoDato=REAL;}
    | lista_constante_car{$$.lista=1;$$.tipoDato=CARACTER;};

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
