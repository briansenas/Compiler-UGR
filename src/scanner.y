%{
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int yylex();
void yyerror(const char * mensaje);

int num_linea = 1;
int num_errores = 0;

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

%token BOOLEANO
%token CONSTANTE_NUM
%token CONSTANTE_CHAR
%token CONSTANTE_FLOAT
%token TIPO_DATO

%token SIGSIG
%token SIGNO

%token CADENA
%token SALIDA
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

programa: cabecera_programa bloque

bloque: INI_BLOQUE declar_de_variables_locales declar_de_subprogs FIN_BLOQUE
    {printf("bloque\n");}
    |   INI_BLOQUE declar_de_variables_locales declar_de_subprogs sentencias FIN_BLOQUE
    {printf("bloque\n");}

declar_de_subprogs: declar_de_subprogs declar_subprog
    {printf("declar_de_subprogs\n");}

declar_subprog: cabecera_subprograma bloque
    {printf("declar_subprog\n");}

declar_de_variables_locales: marca_ini_declar_variables variables_locales marca_fin_declar_variables
    {printf("declar_de_variables_locales\n");}

marca_ini_declar_variables: INI_VAR
    {printf("marca_ini_declar_variables\n");}

marca_fin_declar_variables: FIN_VAR
    {printf("marca_fin_declar_variables\n");}

cabecera_programa: PRINCIPAL
    {printf("cabecera_programa\n");}

inicio_de_bloque: LLAVE_ABRE
    {printf("inicio_de_bloque\n");}

fin_de_bloque: LLAVE_CIERRA
    {printf("fin_de_bloque\n");}   

variables_locales: variables_locales cuerpo_declar_variables
    | cuerpo_declar_variables
    {printf("variables_locales\n");}

cuerpo_declar_variables: tipo varios_identificador PYC
    {printf("cuerpo_declar_variables\n");}

varios_identificador: identificador
    | varios_identificador, identificador
    {printf("varios_identificador\n");}

tipo: tipo_dato
    | lista de tipo_dato
    {printf("tipo\n");}

tipo_dato: entero
    | flotante
    | car
    | booleano
    {printf("tipo_dato\n");}

cabecera_subprog: tipo identificador  PARENTESIS_ABRE lista_parametros PARENTESIS_ABRE
    {printf("cabecera_subprog\n");}

lista_parametros: tipo identificador 
    | lista_parametros, tipo identificador 
    | 𝜖
    {printf("lista_parametros\n");}

sentencias: sentencias sentencia
    | sentencia
    {printf("sentencias\n");}

sentencia: bloque
    {printf("sentencia\n");}
    | sentencia_asignacion
    {printf("sentencia\n");}
    | sentencia_si 
    {printf("sentencia\n");}
    | sentencia_mientras
    {printf("sentencia\n");}
    | sentencia_entrada
    {printf("sentencia\n");}
    | sentencia_salida
    {printf("sentencia\n");}
    | sentencia_retorno
    {printf("sentencia\n");}

sentencia_asignacion: ident = expresion PYC
    {printf("sentencia_asignacion\n");}

sentencia_si : si PARENTESIS_ABRE expresion PARENTESIS_CIERRA Sentencias
    {printf("sentencia_asignacion\n");}

sentencia_mientras: mientras PARENTESIS_ABRE expresion PARENTESIS_CIERRA Sentencia
    {printf("sentencia_mientras\n");}

sentencia_entrada: nomb_entrada lista_variables ;
    {printf("sentencia_entrada\n");}

nomb_entrada: entrada 
    {printf("entrada\n");}

sentencia_salida: nomb_salida lista_expresiones_o_cadena ;
    {printf("sentencia_salida\n"));}

lista_expresiones_o_cadena: expresion
    {printf("lista_expresiones_o_cadena\n");}
    | << lista_expresiones_o_cadena
     {printf("lista_expresiones_o_cadena\n");}
    | cadena
     {printf("lista_expresiones_o_cadena\n");}
    | cadena << lista_expresiones_o_cadena
    {printf("lista_expresiones_o_cadena\n");}

nomb_salida: imprimir <<
    {printf("nomb_salida\n");}

sentencia_retorno: devolver expresion ;
    {printf("sentencia_retorno\n");}

expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA
    {printf("expresion\n");}
    | op_unario expresion
    {printf("expresion\n");}
    | expresion op_unario_der 
    {printf("expresion\n");}
    | expresion op_binario expresion
   {printf("expresion\n");}
    | expresion op_ternario_prim expresion op_ternario_seg
    {printf("expresion\n");}
    | expresion
    {printf("expresion\");}
    | identificador 
    {printf("expresion\");}
    | constante
    {printf("expresion\");}
    | funcion
    {printf("expresion\");}
    | lista_constantes
    {printf("expresion\");}

op_unario: +
    | -
    | ++
    | - -
    | !
    | #
    | ?
    {printf("op_unario\n");}

op_unario_der : ++
    | - -
    | -
    | +
    | >>
    | <<
    | $
    {printf("op_unario_der\n");}

op_binario: *
    | /
    | %
    | <
    | >
    | <=
    | >=
    | ==
    | !=
    | +
    | -
    | @
    | - -
    | **
    | +
    | -
    {printf("op_binario\n");}

op_ternario_prim: ++
    {printf("op_ternario_prim\n");}

op_ternario_sec: @
    {printf("op_ternario_sec");}

funcion: identificador PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA
    {printf("funcion\n");}

lista_constantes: lista_constante_booleano
    | lista_constante_enteros
    | lista_constante_flotante
    | lista_constante_car 
    {printf("lista_constantes\n");}

lista_constante_booleano: CORCHETE_ABRE contenido_lista_booleano CORCHETE_CIERRA
    {printf("lista_constante_booleano\n");}

contenido_lista_booleano: booleano
    | boleano, contenido_lista_booleano
    {printf("contenido_lista_booleano\n");}

lista_constante_entero: CORCHETE_ABRE contenido_lista_entero CORCHETE_CIERRA
    {printf("lista_constante_entero\n");}

contenido_lista_entero: entero
    | entero , contenido_lista_entero
    {printf("contenido_lista_entero\n");}

lista_constante_flotante: CORCHETE_ABRE contenido_lista_flotante CORCHETE_CIERRA
    {printf("lista_constante_flotante\n");}

contenido_lista_flotante: flotante
    | flotante , contenido_lista_flotante
    {printf("contenido_lista_flotante\n");}

lista_constante_car : CORCHETE_ABREcontenido_lista_car CORCHETE_CIERRA
    {printf("lista_constante_car\n");}

contenido_lista_car : car 
    | car  , contenido_lista_car 
    {printf("contenido_lista_car\n");}

constante: booleano
| entero
| flotante
| car 
    {printf("constante\n");}

entero: [0-9]*
    {printf("entero\n");}

flotante: [0-9]*.[0-9]*
    {printf("flotante\n");}

car: ‘[^"‘]‘
    {printf("car\n");}

booleano:  Verdadero | Falso
    {printf("booleano\n");}


cadena: "[^\\"]*\\"
    {printf("cadena\n");}

identificador: [a-zñA-ZÑ]+([a-zñA-ZÑ]|[-_]|[0-9])*
    {printf("identificador\n");}

%%


#include "lex.yy.c"

void yyerror(const char *msg)
{
    fprintf(stderr,"[Linea %d]: %s\n", num_linea, msg) ;
	 num_errores++;
}

