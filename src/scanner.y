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
%error-verbose

%token CONSTANTE_BASICA

%%

constante                   : CONSTANTE_BASICA

%%


#include "lex.yy.c"

void yyerror(const char *msg)
{
    fprintf(stderr,"[Linea %d]: %s\n", num_linea, msg) ;
	 num_errores++;
}

