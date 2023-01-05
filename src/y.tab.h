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
    OP_INTERR = 263,               /* OP_INTERR  */
    DOS_PUNTOS = 264,              /* DOS_PUNTOS  */
    OP_OR = 265,                   /* OP_OR  */
    OP_AND = 266,                  /* OP_AND  */
    OP_XOR = 267,                  /* OP_XOR  */
    OP_IGUALDAD = 268,             /* OP_IGUALDAD  */
    OP_RELACION = 269,             /* OP_RELACION  */
    OP_ADITIVO = 270,              /* OP_ADITIVO  */
    SIGSIG = 271,                  /* SIGSIG  */
    OP_MULTIPLICATIVO = 272,       /* OP_MULTIPLICATIVO  */
    OP_UNARIO = 273,               /* OP_UNARIO  */
    OP_TERNARIO = 274,             /* OP_TERNARIO  */
    OP_ASIGNACION = 275,           /* OP_ASIGNACION  */
    BOOLEANO = 276,                /* BOOLEANO  */
    CONSTANTE_NUM = 277,           /* CONSTANTE_NUM  */
    CONSTANTE_CAR = 278,           /* CONSTANTE_CAR  */
    CONSTANTE_FLOAT = 279,         /* CONSTANTE_FLOAT  */
    TIPO_DATO = 280,               /* TIPO_DATO  */
    CADENA = 281,                  /* CADENA  */
    LISTA = 282,                   /* LISTA  */
    MIENTRAS = 283,                /* MIENTRAS  */
    SI = 284,                      /* SI  */
    SINO = 285,                    /* SINO  */
    ENTRADA = 286,                 /* ENTRADA  */
    IMPRIMIR = 287,                /* IMPRIMIR  */
    DEVOLVER = 288,                /* DEVOLVER  */
    DIRECCION = 289,               /* DIRECCION  */
    IDENT = 290,                   /* IDENT  */
    PARENTESIS_ABRE = 291,         /* PARENTESIS_ABRE  */
    PARENTESIS_CIERRA = 292,       /* PARENTESIS_CIERRA  */
    CORCHETE_ABRE = 293,           /* CORCHETE_ABRE  */
    CORCHETE_CIERRA = 294,         /* CORCHETE_CIERRA  */
    COMA = 295,                    /* COMA  */
    PYC = 296                      /* PYC  */
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
