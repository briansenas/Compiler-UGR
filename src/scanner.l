/* scanner for a Generating Pseudo-like Code-language */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../include/scanner.h"

using namespace std;

%}
/* SECCIÓN DE DEFINCIONES */
DIGITO					[0-9]
FLOTANTE				[0-9]+([.][0-9]*)
LETRA					[a-zA-Z]
GUIONES                 [-_]
ESPACIO					[" "]

%option noyywrap
%option yylineno
%%

"ini_var"                       return(INI_VAR);
"fin_var"                       return(FIN_VAR);
"principal"                    return(PRINCIPAL);
"}"                              return(INI_BLOQUE);
"{"                              return(FIN_BLOQUE);
"entero"                         return(TIPO_DATO);
"real"                           return(TIPO_DATO);
"car"                       return(TIPO_DATO);
"bool"                       return(TIPO_DATO);
"listade"                       return(LISTA);
"si"                             return(SI);
"devolver"                       return(DEVOLVER);
"mientras"                       return(MIENTRAS);
"imprimir"                         return(IMPRIMIR);
"entrada"                        return(ENTRADA);
"<<"                             return(DIRECCION);
">>"                             return(DIRECCION);
")"                              return(PARENTESIS_CIERRA);
"("                              return(PARENTESIS_ABRE);
";"                              return(PYC);
"++"                             return(SIGSIG);
"--"                             return(SIGSIG);
"@"                              return(OP_TERNARIO);
"!"                              return(OP_UNARIO);
"#"                              return(OP_UNARIO);
"?"                              return(OP_UNARIO);
"$"                              return(OP_UNARIO);
"-"                              return(SIGNO);
"+"                              return(SIGNO);
"="                              return(OP_BINARIO);
"*"                              return(OP_BINARIO);
"/"                              return(OP_BINARIO);
"&&"                             return(OP_BINARIO);
"||"                             return(OP_BINARIO);
"^"                              return(OP_BINARIO);
"<"                              return(OP_BINARIO);
">"                              return(OP_BINARIO);
"<="                             return(OP_BINARIO);
">="                             return(OP_BINARIO);
"=="                             return(OP_BINARIO);
"!="                             return(OP_BINARIO);
"%"                              return(OP_BINARIO);
"**"                             return(OP_BINARIO);
","                              return(COMA);
{DIGITO}+				         return(CONSTANTE_NUM);
{DIGITO}+"."{DIGITO}+	         return(CONSTANTE_FLOAT);
\'[^\"\']\'                      return(CONSTANTE_CHAR);
("Verdadero"|"Falso")	         return(BOOLEANO);
\"[^\"]+\"				         return(CADENA);
{LETRA}({LETRA}|{GUIONES}|{DIGITO})*    return(IDENT);
"\n"                                    return 1;

. {
    printf(" \nError Léxico en Linea: %d. No se reconoce la palabra '%s'. ", yylineno, yytext);
}

%%
