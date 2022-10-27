/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INI_VAR = 258,                 /* INI_VAR  */
    FIN_VAR = 259,                 /* FIN_VAR  */
    PRINCIPAL = 260,               /* PRINCIPAL  */
    INI_BLOQUE = 261,              /* INI_BLOQUE  */
    FIN_BLOQUE = 262,              /* FIN_BLOQUE  */
    CONSTANTE_NUM = 263,           /* CONSTANTE_NUM  */
    CONSTANTE_CHAR = 264,          /* CONSTANTE_CHAR  */
    CONSTANTE_FLOAT = 265,         /* CONSTANTE_FLOAT  */
    TIPO_DATO = 266,               /* TIPO_DATO  */
    SIGSIG = 267,                  /* SIGSIG  */
    SALIDA = 268,                  /* SALIDA  */
    LISTA = 269,                   /* LISTA  */
    MIENTRAS = 270,                /* MIENTRAS  */
    SI = 271,                      /* SI  */
    ENTRADA = 272,                 /* ENTRADA  */
    IMPRIMIR = 273,                /* IMPRIMIR  */
    DEVOLVER = 274,                /* DEVOLVER  */
    DIRECCION = 275,               /* DIRECCION  */
    IDENT = 276,                   /* IDENT  */
    OP_BINARIO = 277,              /* OP_BINARIO  */
    OP_UNARIO = 278,               /* OP_UNARIO  */
    OP_TERNARIO = 279,             /* OP_TERNARIO  */
    LLAVE_ABRE = 280,              /* LLAVE_ABRE  */
    LLAVE_CIERRA = 281,            /* LLAVE_CIERRA  */
    PARENTESIS_ABRE = 282,         /* PARENTESIS_ABRE  */
    PARENTESIS_CIERRA = 283,       /* PARENTESIS_CIERRA  */
    COMA = 284,                    /* COMA  */
    PYC = 285                      /* PYC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
