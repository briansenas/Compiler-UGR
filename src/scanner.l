/* scanner for a Generating Pseudo-like Code-language */
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "./../include/scanner.h"
#include "y.tab.h"

// using namespace std;
%}

%option noyywrap
%option yylineno

/* SECCIÓN DE DEFINCIONES */
DIGITO					[0-9]
FLOTANTE				[0-9]+([.][0-9]*)
LETRA					[a-zA-Z]
GUIONES                 [-_]
ESPACIO					[" "]

%%

"//".*                           { ECHO; /* DO NOTHING */ }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { ECHO; /* DO NOTHING */ }
[/][*]                                    {
    printf(" \n [Linea %d]: lexical error: no se reconoce la palabra '%s'. ", yylineno, yytext);
}

"ini_var"                { ECHO;       return(INI_VAR);}
"fin_var"                { ECHO;       return(FIN_VAR);}
"principal"             { ECHO; return(PRINCIPAL);}
"}"                       { ECHO;       return(FIN_BLOQUE);}
"{"                       { ECHO;       return(INI_BLOQUE);}
"entero"                  { ECHO;       return(TIPO_DATO);}
"real"                    { ECHO;       return(TIPO_DATO);}
"car"                { ECHO;       return(TIPO_DATO);}
"bool"                { ECHO;       return(TIPO_DATO);}
"listade"                { ECHO;       return(LISTA);}
"si"                      { ECHO;       return(SI);}
"sino"                      { ECHO;       return(SINO);}
"devolver"                { ECHO;       return(DEVOLVER);}
"mientras"                { ECHO;       return(MIENTRAS);}
"imprimir"                  { ECHO;       return(IMPRIMIR);}
"entrada"                        { ECHO; return(ENTRADA);}
"<<"                             { ECHO; return(DIRECCION);}
">>"                             { ECHO; return(DIRECCION);}
")"                              { ECHO; return(PARENTESIS_CIERRA);}
"("                              { ECHO; return(PARENTESIS_ABRE);}
";"                              { ECHO; return(PYC);}
"++"                             { ECHO; return(SIGSIG);}
"--"                             { ECHO; return(SIGSIG);}
"@"                              { ECHO; return(OP_TERNARIO);}
"!"                              { ECHO; return(OP_UNARIO);}
"#"                              { ECHO; return(OP_UNARIO);}
"?"                       { ECHO;       return(OP_UNARIO);}
"$"                       { ECHO;       return(OP_UNARIO);}
"-"                       { ECHO;       return(OP_BINARIO);}
"+"                       { ECHO;       return(OP_BINARIO);}
"="                       { ECHO;       return(OP_BINARIO);}
"*"                       { ECHO;       return(OP_BINARIO);}
"/"                       { ECHO;       return(OP_BINARIO);}
"&&"                      { ECHO;       return(OP_BINARIO);}
"||"                      { ECHO;       return(OP_BINARIO);}
"^"                       { ECHO;       return(OP_BINARIO);}
"<"                       { ECHO;       return(OP_BINARIO);}
">"                       { ECHO;       return(OP_BINARIO);}
"<="                      { ECHO;       return(OP_BINARIO);}
">="                      { ECHO;       return(OP_BINARIO);}
"=="                      { ECHO;       return(OP_BINARIO);}
"!="                      { ECHO;       return(OP_BINARIO);}
"%"                       { ECHO;       return(OP_BINARIO);}
"**"                      { ECHO;       return(OP_BINARIO);}
","                       { ECHO;       return(COMA);}
{DIGITO}+				  { ECHO;       return(CONSTANTE_NUM);}
{DIGITO}+"."{DIGITO}+	  { ECHO;       return(CONSTANTE_FLOAT);}
\'[^\"\']?\'               { ECHO;       return(CONSTANTE_CAR);}
("Verdadero"|"Falso")	  { ECHO;       return(BOOLEANO);}
\"[^\"]*\"				  { ECHO;       return(CADENA);}
{LETRA}({LETRA}|{GUIONES}|{DIGITO})*    { ECHO; return(IDENT);}

[ \t] {
    ECHO;
}
[\n\r] {
    ECHO;
}

. {
    printf(" \n [Linea %d]: lexical error: no se reconoce la palabra '%s'. ", yylineno, yytext);
}

%%


void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s en la entrada \'%s\'\n", yylineno, msg, yytext) ;
}
