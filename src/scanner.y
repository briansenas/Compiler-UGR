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

%token CONSTANTE_NUM
%token CONSTANTE_CHAR
%token CONSTANTE_FLOAT
%token TIPO_DATO

%token SIGSIG

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

%token COMA
%token PYC

%start programa

%%

programa                   : CONSTANTE_NUM

%%


#include "lex.yy.c"

void yyerror(const char *msg)
{
    fprintf(stderr,"[Linea %d]: %s\n", num_linea, msg) ;
	 num_errores++;
}

