/* scanner for a Generating Pseudo-like Code-language */
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "./../include/scanner.h"
// #include "y.tab.h"

// using namespace std;
%}

%option noyywrap
%option yylineno

/* SECCIÓN DE DEFINCIONES */
DIGITO					[0-9]
FLOTANTE				[0-9]+([.][0-9]*)
LETRA					[a-zA-Z]
GUIONES                 [_]
ESPACIO					[" "]

%%


"ini_var"                { ECHO;       return(INI_VAR);}
"fin_var"                { ECHO;       return(FIN_VAR);}
"principal"             { ECHO; yylval.nombre=strdup(yytext);yylval.tipoDato=ENTERO; return(PRINCIPAL);}
"}"                       { ECHO;       return(FIN_BLOQUE);}
"{"                       { ECHO;       return(INI_BLOQUE);}
"entero"                  { ECHO; yylval.tipoDato=ENTERO; return(TIPO_DATO);}
"real"                    { ECHO; yylval.tipoDato=REAL; return(TIPO_DATO);}
"car"                { ECHO;      yylval.tipoDato=CARACTER;return(TIPO_DATO);}
"bool"                { ECHO;     yylval.tipoDato=TIPOBOOL;return(TIPO_DATO);}
"listade"                { ECHO;    yylval.tipoDato=TIPOLISTA; return(LISTA);}
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
"!"                              { ECHO; yylval.attr=0; return(OP_UNARIO);}
"#"                              { ECHO; yylval.attr=1; return(OP_UNARIO);}
"?"                       { ECHO;       yylval.attr=2; return(OP_UNARIO);}
"$"                       { ECHO;       yylval.attr=3; return(OP_UNARIO);}
"-"                       { ECHO;       yylval.attr=1; return(OP_ADITIVO);}
"+"                       { ECHO;       yylval.attr=0; return(OP_ADITIVO);}
"="                       { ECHO;       return(OP_ASIGNACION);}
"*"                       { ECHO;       yylval.attr=0; return(OP_MULTIPLICATIVO);}
"/"                       { ECHO;       yylval.attr=1; return(OP_MULTIPLICATIVO);}
"&&"                      { ECHO;       return(OP_AND);}
"||"                      { ECHO;       return(OP_OR);}
"^"                       { ECHO;       return(OP_XOR);}
"<"                       { ECHO;       yylval.attr=0; return(OP_RELACION);}
">"                       { ECHO;       yylval.attr=1; return(OP_RELACION);}
"<="                      { ECHO;       yylval.attr=2; return(OP_RELACION);}
">="                      { ECHO;       yylval.attr=3; return(OP_RELACION);}
"=="                      { ECHO;       yylval.attr=0; return(OP_IGUALDAD);}
"!="                      { ECHO;       yylval.attr=1; return(OP_IGUALDAD);}
"%"                       { ECHO;       yylval.attr=2; return(OP_MULTIPLICATIVO);}
"**"                      { ECHO;       yylval.attr=3; return(OP_MULTIPLICATIVO);}
","                       { ECHO;       return(COMA);}
{DIGITO}+				  { ECHO;    yylval.tipoDato=ENTERO; yylval.es_constante = 1; yylval.nombre=strdup(yytext); yylval.attr=1; return(CONSTANTE_NUM);}
{DIGITO}+"."{DIGITO}+	  { ECHO;    yylval.tipoDato=REAL; yylval.es_constante = 1; yylval.nombre=strdup(yytext); yylval.attr=2; return(CONSTANTE_FLOAT);}
\'[^\"\']?\'               { ECHO;   yylval.tipoDato=CARACTER; yylval.es_constante = 1; yylval.nombre=strdup(yytext); yylval.attr=3; return(CONSTANTE_CAR);}
"Verdadero"                 { ECHO;  yylval.tipoDato=TIPOBOOL; yylval.es_constante = 1;  yylval.attr=0; yylval.nombre = strdup(yytext); return(BOOLEANO);}
"Falso"                 { ECHO;  yylval.tipoDato=TIPOBOOL; yylval.es_constante = 1; yylval.attr=1; yylval.nombre = strdup(yytext); return(BOOLEANO);}
\"[^\"]*\"				  { ECHO;   yylval.es_constante = 1; yylval.nombre =strdup(yytext); return(CADENA);}
{LETRA}({LETRA}|{GUIONES}|{DIGITO})*    { ECHO; yylval.es_constante = 1;yylval.tipoDato=DESCONOCIDO; yylval.nombre=strdup(yytext); return(IDENT);}


"//".*                           { /* DO NOTHING */ ECHO;}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ ECHO;}
[/][*]                                    {
    printf(" \n [Linea %d]: lexical error: comentario sin cerrar'%s'. ", yylineno, yytext);
}

[ \t] {
    ECHO;
}
[\n\r] {
    ECHO;
    line++;
}

. {
    printf(" \n [Linea %d]: lexical error: no se reconoce la entrada '%s'. ", yylineno, yytext);
}

%%


