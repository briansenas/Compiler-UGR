
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

programa: {abrirArchivos();}PRINCIPAL {principal=1;tsAddSubprog($1);} {decParam = 1;} PARENTESIS_ABRE parametros PARENTESIS_CIERRA {addNewLine();} bloque {addNewLine(); fputs("}",MAIN); cerrarArchivos();}
        | error;

bloque: INI_BLOQUE
        {tsAddMark();
        if(!principal && !cond)
            cMarkIn();
        }
        cuerpo_bloque
        FIN_BLOQUE
        {tsCleanIn();
        if(!principal && !cond){
            cMarkOut();
        }
        }

cuerpo_bloque: declar_de_variables_locales
             declar_de_subprogs sentencias
       | declar_de_variables_locales declar_de_subprogs;

declar_de_subprogs: declar_de_subprogs declar_subprog
                  |;

declar_subprog:  cabecera_subprog {subProg=1; addNewLine(); } bloque {addNewLine();  subProg=0; };

declar_de_variables_locales: INI_VAR {decvariable=1;} variables_locales FIN_VAR {decvariable=0;
             if(principal){
             fputs("int main(){\n",MAIN);
             principal=0;
            }
                           }
                           |;

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables ;


cuerpo_declar_variables: tipo {setType($1);} varios_identificador PYC
                       | error;

cabecera_subprog: tipo IDENT {decParam = 1;$2.tipoDato = $1.tipoDato;tsAddSubprog($2); tipoAtipoC($1); cWriteIdent($2); addPAR_A(); }PARENTESIS_ABRE parametros PARENTESIS_CIERRA{decParam=1; addPAR_C(); decParam=0;}
                | error ;

parametros: lista_parametros {tsUpdateNparam($1); nParam=0; decParam=0;} {$1.nDim=0;}

lista_parametros:
    | lista_parametros COMA tipo identificador {$4.nDim=0; nParam++; setType($3); tsAddParam($4);
                    addCOMMA();
                    tipoAtipoC($3);
                    cWriteIdent($4);
    }
    | tipo identificador {$2.nDim=0; nParam++; setType($1); tsAddParam($2);
                    tipoAtipoC($1);
                    cWriteIdent($2);
};


sentencias: sentencias {decvariable=2;} sentencia
    |{decvariable=2;} sentencia;

sentencia: bloque
    | sentencia_asignacion
    | {cond=1;}sentencia_si
    | {cond=1;}sentencia_mientras
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
    } ;

sentencia_asignacion:identificador OP_ASIGNACION expresion PYC{
    generaCodigoAsignacion($1,$3);
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

sentencia_primera: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA{
        $$.etiq1 = generarEtiqueta();
        $$.etiq2 = generarEtiqueta();
        generaCodigoSi(&$$,$3);
        if ($3.tipoDato != TIPOBOOL){
            printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
                 }
sentencia_si: sentencia_primera sentencia
            {
        char* etq = malloc(255);
        strcpy(etq,$1.etiq1);
        strcat(etq,":\n;");
        cWriteCode(etq);
        }
        | sentencia_primera sentencia SINO {
            generaGOTO($1.etiq2);
            char* etq = malloc(255);
            strcpy(etq,$1.etiq1);
            strcat(etq,":\n;");
            cWriteCode(etq);
        }sentencia{
            char* etq = malloc(255);
            strcpy(etq,$1.etiq2);
            strcat(etq,":\n;");
            cWriteCode(etq);
        };

sentencia_mientras: MIENTRAS {
                  $1.nombre=generarEtiqueta();
                  char * etiqueta = malloc(255);
                  strcpy(etiqueta,$1.nombre);
                  strcat(etiqueta,":\n{\n");
                  cWriteCode(etiqueta);
                  }cond_mientras {
                  char * res = malloc(255);
                  strcpy(res,"goto ");
                  strcat(res, $1.nombre);
                  strcat(res,";\n}\n");
                  cWriteCode(res);
                  strcpy(res,$3.nombre);
                  strcat(res,"\n");
                  cWriteCode(res);
                  };

cond_mientras: PARENTESIS_ABRE expresion PARENTESIS_CIERRA
        {
        generaCodigoSi(&$1,$2);
        strcpy($$.nombre,$1.nombre);
        if($2.tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
        } cuerpo_mientras;

cuerpo_mientras: sentencia;

sentencia_entrada: ENTRADA DIRECCION lista_variables PYC {
                 generarE_S("scanf(\"");
                 };

lista_variables: identificador {TS_subprog_params($1); }
               | DIRECCION lista_variables
               | identificador DIRECCION identificador
                {TS_subprog_params($1); }
                {TS_subprog_params($3); }
               ;


sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC{
                generarE_S("printf(\"");
                };

sentencia_retorno: DEVOLVER expresion {tsCheckReturn($2, &$$); generaCodigoReturn($2);} PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA {
    $$.tipoDato = $2.tipoDato; $$.nDim = $2.nDim; $$.tamDimen1 = $2.tamDimen1; $$.tamDimen2 = $2.tamDimen2; }
    | OP_UNARIO expresion {
    tsOpUnary($1, $2, &$$);
    $$.nombre=generarVariableTemporal();
    generaCodigoVariableTemporal($2,&$$);
    generaCodigoUnario($1,$2,&$$);
    }
    | expresion OP_UNARIO {
    tsOpUnary($2, $1, &$$);
    $$.nombre=generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigoUnario($2,$1,&$$);
    }
    | expresion OP_TERNARIO CONSTANTE_NUM {
    tsCheckLeftList($1,$3,&$$);
    }
    | expresion OP_OR expresion {
    tsOpOr($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigo("%s = %s || %s;\n", $$.nombre, $1.nombre, $3.nombre);
    }
    | expresion OP_AND expresion {
    tsOpAnd($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigo("%s = %s && %s;\n", $$.nombre, $1.nombre, $3.nombre);
    }
    | expresion OP_XOR expresion {
    tsOpXOr($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigo("%s = %s ^ %s;\n", $$.nombre, $1.nombre, $3.nombre);
    }
    | expresion OP_RELACION expresion {
    tsOpRel($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigoOpRelacion($1,$2,$3,&$$);
    }
    | expresion OP_MULTIPLICATIVO expresion {
    tsOpMul($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigoOpMultiplicativo($1,$2,$3,&$$);
    }
    | expresion OP_IGUALDAD expresion {
    tsOpEqual($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    $$.codigo = malloc(255);
    snprintf($$.codigo,255,"%s = %s == %s;\n",$$.nombre, $1.nombre, $3.nombre);
    cWriteCode($$.codigo);
    }
    | expresion OP_ADITIVO expresion {
    tsOpAdditivo($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    generaCodigoOpAditivo($1,$2,$3,&$$);
    }
    | OP_ADITIVO expresion {
    tsOpSign($1, $2, &$$);
    generaSigno($1,$2, &$$);
    } %prec OP_UNARIO
    | expresion SIGSIG expresion {tsOpSignSign($1, $2, $3, &$$); }
    | identificador { decvariable = 0;
    $$.tipoDato = $1.tipoDato; $$.lista = $1.lista; $$.es_constante = $1.es_constante;
    }
    | constante {
        $$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $1.tamDimen1;
        $$.tamDimen2 = $1.tamDimen2; $$.nombre = $1.nombre;
    }
    | funcion {
        $$.tipoDato = $1.tipoDato; $$.nDim = $1.nDim; $$.tamDimen1 = $1.tamDimen1;
        $$.tamDimen2 = $1.tamDimen2; $$.lista = $1.lista; cond=1;
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
                        tsAddId($1);
                        if(!decParam) {
                            tipoAtipoC($1);
                            cWriteIdent($1);
                            addPYC();
                            addNewLine();
                            if(principal){
                            subProg=1;
                            cWriteCode("extern ");
                            tipoAtipoC($1);
                            cWriteIdent($1);
                            addPYC();
                            addNewLine();
                            subProg=0;
                            }
                        }
					}else{
                        if(decParam==0)
                            tsGetId($1, &$$);
					}
				};




lista_expresiones_o_cadena: lista_expresiones_o_cadena DIRECCION expresion_o_cadena
                          | expresion_o_cadena;

expresion_o_cadena: expresion{
                  $$.tipoDato = $1.tipoDato;
                  TS_subprog_params($1);
                  }
                  | CADENA {
                  $$.tipoDato = $1.tipoDato;
                  TS_subprog_params($1);
                  } ;

constante: BOOLEANO { $$.tipoDato = TIPOBOOL; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; $$.nombre = $1.nombre; }
| CONSTANTE_NUM { $$.tipoDato = ENTERO; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; $$.nombre = $1.nombre; }
| CONSTANTE_FLOAT { $$.tipoDato = REAL; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; $$.nombre = $1.nombre; }
| CONSTANTE_CAR { $$.tipoDato = CARACTER; $$.nDim = 0; $$.tamDimen1 = 0; $$.tamDimen2 = 0; $$.nombre = $1.nombre; };

tipo: TIPO_DATO {$$.tipoDato = $1.tipoDato;$$.lista=0;}
    | LISTA TIPO_DATO {$$.tipoDato = $2.tipoDato; $$.lista=1;};

funcion: IDENT PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA {
            $$.nombre = generarVariableTemporal();
            int index = tsSearchName($1);
            atributos a;
            a.lista = ts[index].lista;
            a.nombre = ts[index].nombre;
            a.tipoDato = ts[index].tipoDato;
            generaCodigoVariableTemporal(a,&$$);
            char* resultado = malloc(255);
            strcpy(resultado,$$.nombre);
            strcat(resultado," = ");
            strcat(resultado,generarFuncion($1.nombre));
            cWriteCode(resultado);
            strcpy(resultado,$$.nombre);
            tsFunctionCall($1,&$$);
            strcpy($$.nombre, resultado);
        };
       | IDENT PARENTESIS_ABRE PARENTESIS_CIERRA {
            $$.nombre = generarVariableTemporal();
            int index = tsSearchName($1);
            atributos a;
            a.lista = ts[index].lista;
            a.nombre = ts[index].nombre;
            a.tipoDato = ts[index].tipoDato;
            generaCodigoVariableTemporal(a,&$$);
            char* resultado = malloc(255);
            strcpy(resultado,$$.nombre);
            strcat(resultado," = ");
            strcat(resultado,generarFuncion($1.nombre));
            cWriteCode(resultado);
            strcpy(resultado,$$.nombre);
            tsFunctionCall($1,&$$);
            strcpy($$.nombre, resultado);
       };

lista_expresiones: lista_expresiones COMA expresion {nParam++;TS_subprog_params($3);}
                 | expresion {nParam=1;TS_subprog_params($1);};

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
