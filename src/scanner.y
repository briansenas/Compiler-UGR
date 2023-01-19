
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

%token INI_VAR FIN_VAR PRINCIPAL INI_BLOQUE FIN_BLOQUE

%left OP_INTERR
%left DOS_PUNTOS
%left OP_OR
%left OP_AND
%left OP_XOR
%left OP_IGUALDAD
%left OP_RELACION
%left OP_ADITIVO
%right SIGSIG
%left OP_MULTIPLICATIVO

%right OP_UNARIO
%left OP_TERNARIO

%token OP_ASIGNACION BOOLEANO CONSTANTE_NUM CONSTANTE_CAR CONSTANTE_FLOAT TIPO_DATO

%token CADENA LISTA MIENTRAS SI SINO ENTRADA IMPRIMIR DEVOLVER

%token DIRECCION IDENT PARENTESIS_ABRE PARENTESIS_CIERRA CORCHETE_ABRE CORCHETE_CIERRA

%token COMA PYC

%start programa

%%

programa: {abrirArchivos();}PRINCIPAL {principal=1;tsAddSubprog($1);} {decParam = 1;} PARENTESIS_ABRE parametros PARENTESIS_CIERRA {addChar('\n');} bloque {addChar('\n'); fputs("}",MAIN); cerrarArchivos();}
        | error;

bloque: INI_BLOQUE
        {tsAddMark();
        if(!principal && cond<=0)
            cMarkIn();
        }
        cuerpo_bloque
        FIN_BLOQUE
        {tsCleanIn();
        }

cuerpo_bloque: declar_de_variables_locales
             declar_de_subprogs sentencias
       | declar_de_variables_locales declar_de_subprogs;

declar_de_subprogs: declar_de_subprogs declar_subprog
                  |;

declar_subprog:  cabecera_subprog {subProg++; addChar('\n'); } bloque {addChar('\n');  cMarkOut(); subProg--;};


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

cabecera_subprog: tipo IDENT {decParam = 1;$2.tipoDato = $1.tipoDato;tsAddSubprog($2); tipoAtipoC($1); cWriteIdent($2); addChar('('); }PARENTESIS_ABRE parametros PARENTESIS_CIERRA{decParam=1; addChar(')'); decParam=0;}
                | error ;

parametros: lista_parametros {tsUpdateNparam($1); nParam=0; decParam=0;}

lista_parametros:
    | lista_parametros COMA tipo identificador { nParam++; setType($3); tsAddParam($4);
                    addChar(',');
                    tipoAtipoC($3);
                    cWriteIdent($4);
    }
    | tipo identificador { nParam++; setType($1); tsAddParam($2);
                    tipoAtipoC($1);
                    cWriteIdent($2);
};


sentencias: sentencias {decvariable=2;} sentencia
    |{decvariable=2;} sentencia;

sentencia: bloque
    | sentencia_asignacion
    | {cond++;}sentencia_si{cond--;}
    | {cond++;}sentencia_mientras{cond--;}
    | sentencia_entrada
    | sentencia_salida
    | sentencia_retorno
    | identificador DIRECCION PYC {
    $2.tipoDato = $1.tipoDato;
    moverCursor($1,$2);
    if(!tsCheckList($1)){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    }
    | OP_UNARIO identificador PYC {
    $2.tipoDato = $1.tipoDato;
    moverCursor($2, $1);
    if(!tsCheckList($2)){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    } ;

sentencia_asignacion:identificador OP_ASIGNACION expresion PYC{
    generaCodigoAsignacion($1,$3);
    ErrorTipo($1,$3);
    if(tsCheckList($1)){
        if(!$3.lista){
            printf("Semantic Error(%d): No se puede asignar porque tienen que ser de tipo lista.\n",line);
        }
    }

}
    | identificador OP_ASIGNACION expresion OP_INTERR expresion DOS_PUNTOS expresion PYC{
        if ($3.tipoDato != TIPOBOOL){
            printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
        if($5.tipoDato != $7.tipoDato && $1.tipoDato != $5.tipoDato){
            printf("Semantic Error(%d): Los tipos de datos no coinciden\n",line);
        }
        if(tsCheckList($1)){
            if(!$5.lista && !$7.lista){
                printf("Semantic Error(%d): No se puede asignar porque tienen que ser de tipo lista.\n",line);
            }
        }
        generaCodigoLambda($1,$3,$5,$7);
    }
    | identificador OP_ASIGNACION TIPO_DATO PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA PYC{
        checkTypes($1,$3);
        generaCodigoInicializacion($1);
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
            cWriteLabel($1.etiq1);
        }
        | sentencia_primera sentencia SINO {
            generaGOTO($1.etiq2);
            cWriteLabel($1.etiq1);
        }sentencia{
            cWriteLabel($1.etiq2);
        };

sentencia_mientras: MIENTRAS {
                  $1.etiq1=generarEtiqueta();
                  cWriteLabel($1.etiq1);
                  } cond_mientras {
                  generaGOTO($1.etiq1);
                  cWriteLabel($3.etiq1);
                  };

cond_mientras: PARENTESIS_ABRE expresion PARENTESIS_CIERRA
        {
        generaCodigoSi(&$1,$2);
        if($2.tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
        } cuerpo_mientras;

cuerpo_mientras: sentencia;

sentencia_entrada: ENTRADA DIRECCION lista_variables PYC {
                 generarE_S("scanf(\"",0);
                 };

lista_variables: identificador {TS_subprog_params($1); }
               | DIRECCION lista_variables
               | identificador DIRECCION identificador
                {TS_subprog_params($1); }
                {TS_subprog_params($3); }
               ;


sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC{
                generarE_S("printf(\"",1);
                };

sentencia_retorno: DEVOLVER expresion {tsCheckReturn($2, &$$); generaCodigoReturn($2);} PYC;

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA {
    $$.tipoDato = $2.tipoDato;
    $$.nombre = $2.nombre;
    }
    | OP_UNARIO expresion {
    tsOpUnary($1, $2, &$$);
    $$.nombre=generarVariableTemporal();
    int tipo = $2.tipoDato;
    $2.tipoDato = $$.tipoDato;
    $2.lista=0;
    generaCodigoVariableTemporal($2,&$$);
    $2.lista=1;
    $2.tipoDato = tipo;
    generaCodigoUnario($1,$2,&$$);
    }
    | OP_INTERR expresion {
    if(!isList($2)){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    $$.nombre = generarVariableTemporal();
    $2.lista = 0;
    $$.tipoDato = $2.tipoDato;
    generaCodigoVariableTemporal($2,&$$);
    generaCodigoUnario($1,$2,&$$);
    } %prec OP_UNARIO
    | expresion OP_TERNARIO expresion {
    if(sigsig<0){
    tsCheckLeftList($1,$3,&$$);
    $$.nombre = generarVariableTemporal();
    int a = tsSearchId($1);
    $1.lista=0;
    generaCodigoVariableTemporal($1,&$$);
    char* res;
    char* tipoA = tipoAstring(ts[a].tipoDato);
    asprintf(&res,"%s = getElemento%s(%s,%s);\n", $$.nombre,
    tipoA,
    $1.nombre,$3.nombre);
    free(tipoA);
    $$.codigo = $3.nombre;
    cWriteCode(res);
    free(res);
    }else{
        $$.nombre = $1.nombre;
        $$.codigo = $3.nombre;
    }
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
    | expresion OP_MULTIPLICATIVO OP_MULTIPLICATIVO expresion {
        if($1.attr!=$2.attr && $1.attr!=1){
            printf("Semantic Error(%d): Operación no permitida. ", line);
        }
        $2.attr=11;
        tsOpMul($1, $2, $4, &$$);
        $$.nombre = generarVariableTemporal();
        generaCodigoVariableTemporal($1,&$$);
        generaCodigoOpMultiplicativo($1,$2,$3,&$$);
    }
    | expresion OP_IGUALDAD expresion {
    tsOpEqual($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal($1,&$$);
    asprintf(&$$.codigo,"%s = %s == %s;\n",$$.nombre, $1.nombre, $3.nombre);
    cWriteCode($$.codigo);
    free($$.codigo);
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
    | sigsig{
    sigsig++;
    }
    | identificador {
    decvariable = 0;
    $$.tipoDato = $1.tipoDato; $$.lista = $1.lista; $$.es_constante = $1.es_constante;
    $$.nombre = $1.nombre;
    }
    | constante {
        $$.tipoDato = $1.tipoDato; $$.nombre = $1.nombre; $$.codigo = $1.codigo;
    }
    | funcion {
        $$.tipoDato = $1.tipoDato; $$.lista = $1.lista; cond=1;
        $$.nombre = $1.nombre;
    }
    | lista_constantes {$$.tipoDato = $1.tipoDato;$$.lista = $1.lista;
        $$.nombre = generarVariableTemporal();
        $1.nombre = $$.nombre;
        generaCreacionLista($1);
    }
    | error ;

sigsig:expresion SIGSIG expresion {
    tsOpSignSign($1, $2, $3, &$$);
    $$.nombre = generarVariableTemporal();
    int index = tsSearchId($1);
    generaCodigoVariableTemporal($1,&$$);
    char* res;
    char* tipoA = tipoAstring(ts[index].tipoDato);
    if($2.attr==1){
        asprintf(&res,"%s = removeElement%s(%s,%s);\n", $$.nombre,
        tipoA,ts[index].nombre,$3.nombre);
        cWriteCode(res);
    }else{
        asprintf(&res,"%s = addElementAt%s(%s,%s,%s);\n",
        $$.nombre, tipoA,$1.nombre,$3.codigo,$3.nombre
        );
        cWriteCode(res);
    }
    free(res);
    free(tipoA);
      };

varios_identificador: identificador
    | varios_identificador COMA identificador;

identificador: IDENT {
                    if(decvariable == 1){
                        $1.tipoDato = globaltipoDato; $1.lista = globalLista; $1.es_constante = 0;
                        $$.tipoDato = globaltipoDato; $$.lista = globalLista; $$.es_constante = 0;
                        tsAddId($1);
                        if(!decParam) {
                            tipoAtipoC($1);
                            cWriteIdent($1);
                            addChar(';');
                            addChar('\n');
                            if(principal){
                                decParam = 1;
                                cWriteCode("extern ");
                                tipoAtipoC($1);
                                cWriteIdent($1);
                                addChar(';');
                                addChar('\n');
                                decParam = 0;
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

constante: BOOLEANO { $$.tipoDato = TIPOBOOL; $$.nombre = $1.nombre; }
| CONSTANTE_NUM { $$.tipoDato = ENTERO; $$.nombre = $1.nombre; }
| CONSTANTE_FLOAT { $$.tipoDato = REAL;  $$.nombre = $1.nombre; }
| CONSTANTE_CAR { $$.tipoDato = CARACTER;  $$.nombre = $1.nombre; };

tipo: TIPO_DATO {$$.tipoDato = $1.tipoDato;$$.lista=0;}
    | LISTA TIPO_DATO {$$.tipoDato = $2.tipoDato; $$.lista=1;};

funcion: IDENT PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA {
            $$.nombre = generarVariableTemporal();
            cWriteFunc($1,&$$);
            tsFunctionCall($1,&$$);
            $$.nombre = $1.nombre;
        }
       | IDENT PARENTESIS_ABRE PARENTESIS_CIERRA {
            $$.nombre = generarVariableTemporal();
            cWriteFunc($1,&$$);
            tsFunctionCall($1,&$$);
            $$.nombre = $1.nombre;
       };

lista_expresiones: lista_expresiones COMA expresion {nParam++;TS_subprog_params($3);}
                 | expresion {nParam=1;TS_subprog_params($1);};

lista_constantes: lista_constante_booleano {$$.lista=1; $$.tipoDato=TIPOBOOL;}
    | lista_constante_entero{$$.lista=1;$$.tipoDato=ENTERO;}
    | lista_constante_flotante{$$.lista=1;$$.tipoDato=REAL;}
    | lista_constante_car{$$.lista=1;$$.tipoDato=CARACTER;};

lista_constante_booleano: CORCHETE_ABRE contenido_lista_booleano CORCHETE_CIERRA;

contenido_lista_booleano: BOOLEANO{nParam=1; TS_subprog_params($1); }
    | BOOLEANO COMA contenido_lista_booleano{nParam++;TS_subprog_params($1);};

lista_constante_entero: CORCHETE_ABRE contenido_lista_entero CORCHETE_CIERRA;

contenido_lista_entero: CONSTANTE_NUM {nParam=1; TS_subprog_params($1); }
    | CONSTANTE_NUM COMA contenido_lista_entero{nParam++;TS_subprog_params($1);};

lista_constante_flotante: CORCHETE_ABRE contenido_lista_flotante CORCHETE_CIERRA;

contenido_lista_flotante: CONSTANTE_FLOAT {nParam=1; TS_subprog_params($1); }
    | CONSTANTE_FLOAT COMA contenido_lista_flotante{nParam++;TS_subprog_params($1);};

lista_constante_car : CORCHETE_ABRE contenido_lista_car CORCHETE_CIERRA;

contenido_lista_car : CONSTANTE_CAR{nParam=1; TS_subprog_params($1); }
    | CONSTANTE_CAR COMA contenido_lista_car{nParam++;TS_subprog_params($1);};

%%

#include "lex.yy.c"


void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s \n", yylineno, msg) ;
}
