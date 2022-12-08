/* scanner for a Generating Pseudo-like Code-language */
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUGGING 1
#define COMMENTS 0
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
"ini_var"                { if(DEBUGGING) ECHO;       return(INI_VAR);}
"fin_var"                { if(DEBUGGING) ECHO;       return(FIN_VAR);}
"principal"             { if(DEBUGGING) ECHO; yylval.nombre=strdup(yytext);yylval.tipoDato=ENTERO; return(PRINCIPAL);}
"}"                       { if(DEBUGGING) ECHO;       return(FIN_BLOQUE);}
"{"                       { if(DEBUGGING) ECHO;       return(INI_BLOQUE);}
"entero"                  { if(DEBUGGING) ECHO; yylval.tipoDato=ENTERO; return(TIPO_DATO);}
"real"                    { if(DEBUGGING) ECHO; yylval.tipoDato=REAL; return(TIPO_DATO);}
"car"                { if(DEBUGGING) ECHO;      yylval.tipoDato=CARACTER;return(TIPO_DATO);}
"bool"                { if(DEBUGGING) ECHO;     yylval.tipoDato=TIPOBOOL;return(TIPO_DATO);}
"listade"                { if(DEBUGGING) ECHO;    yylval.tipoDato=TIPOLISTA; return(LISTA);}
"si"                      { if(DEBUGGING) ECHO;       return(SI);}
"sino"                      { if(DEBUGGING) ECHO;       return(SINO);}
"devolver"                { if(DEBUGGING) ECHO;       return(DEVOLVER);}
"mientras"                { if(DEBUGGING) ECHO;       return(MIENTRAS);}
"imprimir"                  { if(DEBUGGING) ECHO;       return(IMPRIMIR);}
"entrada"                        { if(DEBUGGING) ECHO; return(ENTRADA);}
"<<"                             { if(DEBUGGING) ECHO; return(DIRECCION);}
">>"                             { if(DEBUGGING) ECHO; return(DIRECCION);}
")"                              { if(DEBUGGING) ECHO; return(PARENTESIS_CIERRA);}
"("                              { if(DEBUGGING) ECHO; return(PARENTESIS_ABRE);}
";"                              { if(DEBUGGING) ECHO; return(PYC);}
"++"                             { if(DEBUGGING) ECHO; return(SIGSIG);}
"--"                             { if(DEBUGGING) ECHO; return(SIGSIG);}
"@"                              { if(DEBUGGING) ECHO; return(OP_TERNARIO);}
"!"                              { if(DEBUGGING) ECHO; yylval.attr=0; return(OP_UNARIO);}
"#"                              { if(DEBUGGING) ECHO; yylval.attr=1; return(OP_UNARIO);}
"?"                       { if(DEBUGGING) ECHO;       yylval.attr=2; return(OP_UNARIO);}
"$"                       { if(DEBUGGING) ECHO;       yylval.attr=3; return(OP_UNARIO);}
"-"                       { if(DEBUGGING) ECHO;       yylval.attr=1; return(OP_ADITIVO);}
"+"                       { if(DEBUGGING) ECHO;       yylval.attr=0; return(OP_ADITIVO);}
"="                       { if(DEBUGGING) ECHO;       return(OP_ASIGNACION);}
"*"                       { if(DEBUGGING) ECHO;       yylval.attr=0; return(OP_MULTIPLICATIVO);}
"/"                       { if(DEBUGGING) ECHO;       yylval.attr=1; return(OP_MULTIPLICATIVO);}
"&&"                      { if(DEBUGGING) ECHO;       return(OP_AND);}
"||"                      { if(DEBUGGING) ECHO;       return(OP_OR);}
"^"                       { if(DEBUGGING) ECHO;       return(OP_XOR);}
"<"                       { if(DEBUGGING) ECHO;       yylval.attr=0; return(OP_RELACION);}
">"                       { if(DEBUGGING) ECHO;       yylval.attr=1; return(OP_RELACION);}
"<="                      { if(DEBUGGING) ECHO;       yylval.attr=2; return(OP_RELACION);}
">="                      { if(DEBUGGING) ECHO;       yylval.attr=3; return(OP_RELACION);}
"=="                      { if(DEBUGGING) ECHO;       yylval.attr=0; return(OP_IGUALDAD);}
"!="                      { if(DEBUGGING) ECHO;       yylval.attr=1; return(OP_IGUALDAD);}
"%"                       { if(DEBUGGING) ECHO;       yylval.attr=2; return(OP_MULTIPLICATIVO);}
"**"                      { if(DEBUGGING) ECHO;       yylval.attr=3; return(OP_MULTIPLICATIVO);}
","                       { if(DEBUGGING) ECHO;       return(COMA);}
{DIGITO}+				  { if(DEBUGGING) ECHO;    yylval.tipoDato=ENTERO; yylval.es_constante = 1; yylval.nombre=strdup(yytext); yylval.attr=1; return(CONSTANTE_NUM);}
{DIGITO}+"."{DIGITO}+	  { if(DEBUGGING) ECHO;    yylval.tipoDato=REAL; yylval.es_constante = 1; yylval.nombre=strdup(yytext); yylval.attr=2; return(CONSTANTE_FLOAT);}
\'[^\"\']?\'               { if(DEBUGGING) ECHO;   yylval.tipoDato=CARACTER; yylval.es_constante = 1; yylval.nombre=strdup(yytext); yylval.attr=3; return(CONSTANTE_CAR);}
"Verdadero"                 { if(DEBUGGING) ECHO;  yylval.tipoDato=TIPOBOOL; yylval.es_constante = 1;  yylval.attr=0; yylval.nombre = strdup(yytext); return(BOOLEANO);}
"Falso"                 { if(DEBUGGING) ECHO;  yylval.tipoDato=TIPOBOOL; yylval.es_constante = 1; yylval.attr=1; yylval.nombre = strdup(yytext); return(BOOLEANO);}
\"[^\"]*\"				  { if(DEBUGGING) ECHO;   yylval.tipoDato=CADENA; yylval.es_constante = 1; yylval.nombre =strdup(yytext); return(CADENA);}
{LETRA}({LETRA}|{GUIONES}|{DIGITO})*    { if(DEBUGGING) ECHO; yylval.es_constante = 1;yylval.tipoDato=DESCONOCIDO; yylval.nombre=strdup(yytext); return(IDENT);}
"//".*                           { /* DO NOTHING */ if(DEBUGGING || COMMENTS) if(DEBUGGING) ECHO;}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ if(DEBUGGING || COMMENTS) if(DEBUGGING) ECHO;}
[/][*]                                    {
    printf(" \n [Linea %d]: lexical error: comentario sin cerrar'%s'. ", yylineno, yytext);
}

[ \t] {
    if(DEBUGGING) if(DEBUGGING) ECHO;
}
[\n\r] {
    if(DEBUGGING || COMMENTS) if(DEBUGGING) ECHO;
}

. {
    printf(" \n [Linea %d]: lexical error: no se reconoce la entrada '%s'. ", yylineno, yytext);
}

%%


