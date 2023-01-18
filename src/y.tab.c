/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "./src/scanner.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "y.tab.h"
#include "../include/scansemantic.h"

int yylex();
void yyerror(const char * mensaje);

#define YYERROR_VERBOSE


#line 85 "src/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INI_VAR = 3,                    /* INI_VAR  */
  YYSYMBOL_FIN_VAR = 4,                    /* FIN_VAR  */
  YYSYMBOL_PRINCIPAL = 5,                  /* PRINCIPAL  */
  YYSYMBOL_INI_BLOQUE = 6,                 /* INI_BLOQUE  */
  YYSYMBOL_FIN_BLOQUE = 7,                 /* FIN_BLOQUE  */
  YYSYMBOL_OP_INTERR = 8,                  /* OP_INTERR  */
  YYSYMBOL_DOS_PUNTOS = 9,                 /* DOS_PUNTOS  */
  YYSYMBOL_OP_OR = 10,                     /* OP_OR  */
  YYSYMBOL_OP_AND = 11,                    /* OP_AND  */
  YYSYMBOL_OP_XOR = 12,                    /* OP_XOR  */
  YYSYMBOL_OP_IGUALDAD = 13,               /* OP_IGUALDAD  */
  YYSYMBOL_OP_RELACION = 14,               /* OP_RELACION  */
  YYSYMBOL_OP_ADITIVO = 15,                /* OP_ADITIVO  */
  YYSYMBOL_SIGSIG = 16,                    /* SIGSIG  */
  YYSYMBOL_OP_MULTIPLICATIVO = 17,         /* OP_MULTIPLICATIVO  */
  YYSYMBOL_OP_UNARIO = 18,                 /* OP_UNARIO  */
  YYSYMBOL_OP_TERNARIO = 19,               /* OP_TERNARIO  */
  YYSYMBOL_OP_ASIGNACION = 20,             /* OP_ASIGNACION  */
  YYSYMBOL_BOOLEANO = 21,                  /* BOOLEANO  */
  YYSYMBOL_CONSTANTE_NUM = 22,             /* CONSTANTE_NUM  */
  YYSYMBOL_CONSTANTE_CAR = 23,             /* CONSTANTE_CAR  */
  YYSYMBOL_CONSTANTE_FLOAT = 24,           /* CONSTANTE_FLOAT  */
  YYSYMBOL_TIPO_DATO = 25,                 /* TIPO_DATO  */
  YYSYMBOL_CADENA = 26,                    /* CADENA  */
  YYSYMBOL_LISTA = 27,                     /* LISTA  */
  YYSYMBOL_MIENTRAS = 28,                  /* MIENTRAS  */
  YYSYMBOL_SI = 29,                        /* SI  */
  YYSYMBOL_SINO = 30,                      /* SINO  */
  YYSYMBOL_ENTRADA = 31,                   /* ENTRADA  */
  YYSYMBOL_IMPRIMIR = 32,                  /* IMPRIMIR  */
  YYSYMBOL_DEVOLVER = 33,                  /* DEVOLVER  */
  YYSYMBOL_DIRECCION = 34,                 /* DIRECCION  */
  YYSYMBOL_IDENT = 35,                     /* IDENT  */
  YYSYMBOL_PARENTESIS_ABRE = 36,           /* PARENTESIS_ABRE  */
  YYSYMBOL_PARENTESIS_CIERRA = 37,         /* PARENTESIS_CIERRA  */
  YYSYMBOL_CORCHETE_ABRE = 38,             /* CORCHETE_ABRE  */
  YYSYMBOL_CORCHETE_CIERRA = 39,           /* CORCHETE_CIERRA  */
  YYSYMBOL_COMA = 40,                      /* COMA  */
  YYSYMBOL_PYC = 41,                       /* PYC  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_44_1 = 44,                      /* @1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_bloque = 48,                    /* bloque  */
  YYSYMBOL_49_5 = 49,                      /* $@5  */
  YYSYMBOL_cuerpo_bloque = 50,             /* cuerpo_bloque  */
  YYSYMBOL_declar_de_subprogs = 51,        /* declar_de_subprogs  */
  YYSYMBOL_declar_subprog = 52,            /* declar_subprog  */
  YYSYMBOL_53_6 = 53,                      /* $@6  */
  YYSYMBOL_declar_de_variables_locales = 54, /* declar_de_variables_locales  */
  YYSYMBOL_55_7 = 55,                      /* $@7  */
  YYSYMBOL_variables_locales = 56,         /* variables_locales  */
  YYSYMBOL_cuerpo_declar_variables = 57,   /* cuerpo_declar_variables  */
  YYSYMBOL_58_8 = 58,                      /* $@8  */
  YYSYMBOL_cabecera_subprog = 59,          /* cabecera_subprog  */
  YYSYMBOL_60_9 = 60,                      /* $@9  */
  YYSYMBOL_parametros = 61,                /* parametros  */
  YYSYMBOL_lista_parametros = 62,          /* lista_parametros  */
  YYSYMBOL_sentencias = 63,                /* sentencias  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_sentencia = 66,                 /* sentencia  */
  YYSYMBOL_67_12 = 67,                     /* $@12  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_sentencia_asignacion = 69,      /* sentencia_asignacion  */
  YYSYMBOL_sentencia_primera = 70,         /* sentencia_primera  */
  YYSYMBOL_sentencia_si = 71,              /* sentencia_si  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_sentencia_mientras = 73,        /* sentencia_mientras  */
  YYSYMBOL_74_15 = 74,                     /* $@15  */
  YYSYMBOL_cond_mientras = 75,             /* cond_mientras  */
  YYSYMBOL_76_16 = 76,                     /* $@16  */
  YYSYMBOL_cuerpo_mientras = 77,           /* cuerpo_mientras  */
  YYSYMBOL_sentencia_entrada = 78,         /* sentencia_entrada  */
  YYSYMBOL_lista_variables = 79,           /* lista_variables  */
  YYSYMBOL_80_17 = 80,                     /* $@17  */
  YYSYMBOL_sentencia_salida = 81,          /* sentencia_salida  */
  YYSYMBOL_sentencia_retorno = 82,         /* sentencia_retorno  */
  YYSYMBOL_83_18 = 83,                     /* @18  */
  YYSYMBOL_expresion = 84,                 /* expresion  */
  YYSYMBOL_sigsig = 85,                    /* sigsig  */
  YYSYMBOL_varios_identificador = 86,      /* varios_identificador  */
  YYSYMBOL_identificador = 87,             /* identificador  */
  YYSYMBOL_lista_expresiones_o_cadena = 88, /* lista_expresiones_o_cadena  */
  YYSYMBOL_expresion_o_cadena = 89,        /* expresion_o_cadena  */
  YYSYMBOL_constante = 90,                 /* constante  */
  YYSYMBOL_tipo = 91,                      /* tipo  */
  YYSYMBOL_funcion = 92,                   /* funcion  */
  YYSYMBOL_lista_expresiones = 93,         /* lista_expresiones  */
  YYSYMBOL_lista_constantes = 94,          /* lista_constantes  */
  YYSYMBOL_lista_constante_booleano = 95,  /* lista_constante_booleano  */
  YYSYMBOL_contenido_lista_booleano = 96,  /* contenido_lista_booleano  */
  YYSYMBOL_lista_constante_entero = 97,    /* lista_constante_entero  */
  YYSYMBOL_contenido_lista_entero = 98,    /* contenido_lista_entero  */
  YYSYMBOL_lista_constante_flotante = 99,  /* lista_constante_flotante  */
  YYSYMBOL_contenido_lista_flotante = 100, /* contenido_lista_flotante  */
  YYSYMBOL_lista_constante_car = 101,      /* lista_constante_car  */
  YYSYMBOL_contenido_lista_car = 102       /* contenido_lista_car  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    50,    50,    50,    50,    51,    54,    53,
      63,    65,    67,    68,    70,    70,    73,    73,    79,    81,
      82,    85,    85,    86,    88,    88,    89,    91,    93,    94,
      99,   105,   105,   106,   106,   108,   109,   110,   110,   111,
     111,   112,   113,   114,   115,   122,   130,   143,   157,   162,
     170,   174,   174,   181,   181,   190,   189,   197,   199,   203,
     204,   206,   205,   211,   215,   215,   217,   221,   232,   241,
     260,   266,   272,   278,   284,   290,   300,   308,   314,   318,
     321,   326,   329,   333,   338,   340,   358,   359,   361,   390,
     391,   393,   397,   402,   403,   404,   405,   407,   408,   410,
     416,   423,   424,   426,   427,   428,   429,   431,   433,   434,
     436,   438,   439,   441,   443,   444,   446,   448,   449
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INI_VAR", "FIN_VAR",
  "PRINCIPAL", "INI_BLOQUE", "FIN_BLOQUE", "OP_INTERR", "DOS_PUNTOS",
  "OP_OR", "OP_AND", "OP_XOR", "OP_IGUALDAD", "OP_RELACION", "OP_ADITIVO",
  "SIGSIG", "OP_MULTIPLICATIVO", "OP_UNARIO", "OP_TERNARIO",
  "OP_ASIGNACION", "BOOLEANO", "CONSTANTE_NUM", "CONSTANTE_CAR",
  "CONSTANTE_FLOAT", "TIPO_DATO", "CADENA", "LISTA", "MIENTRAS", "SI",
  "SINO", "ENTRADA", "IMPRIMIR", "DEVOLVER", "DIRECCION", "IDENT",
  "PARENTESIS_ABRE", "PARENTESIS_CIERRA", "CORCHETE_ABRE",
  "CORCHETE_CIERRA", "COMA", "PYC", "$accept", "programa", "@1", "$@2",
  "$@3", "$@4", "bloque", "$@5", "cuerpo_bloque", "declar_de_subprogs",
  "declar_subprog", "$@6", "declar_de_variables_locales", "$@7",
  "variables_locales", "cuerpo_declar_variables", "$@8",
  "cabecera_subprog", "$@9", "parametros", "lista_parametros",
  "sentencias", "$@10", "$@11", "sentencia", "$@12", "$@13",
  "sentencia_asignacion", "sentencia_primera", "sentencia_si", "$@14",
  "sentencia_mientras", "$@15", "cond_mientras", "$@16", "cuerpo_mientras",
  "sentencia_entrada", "lista_variables", "$@17", "sentencia_salida",
  "sentencia_retorno", "@18", "expresion", "sigsig",
  "varios_identificador", "identificador", "lista_expresiones_o_cadena",
  "expresion_o_cadena", "constante", "tipo", "funcion",
  "lista_expresiones", "lista_constantes", "lista_constante_booleano",
  "contenido_lista_booleano", "lista_constante_entero",
  "contenido_lista_entero", "lista_constante_flotante",
  "contenido_lista_flotante", "lista_constante_car", "contenido_lista_car", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -45,    35,    58,   -45,   -45,   -45,     7,    87,   -45,
      42,    37,    41,    66,   -45,   -45,    87,   -45,   -45,    79,
      66,   -45,   -45,   -45,   112,   -45,   121,   -45,    39,   -45,
     203,   -45,     4,   -45,   -45,   -45,   -45,   -45,   125,    47,
      99,   -45,   -45,    66,    79,    47,    66,   102,   111,   184,
     -45,   -45,   117,   119,   -45,   -45,   -45,   -45,    50,   -45,
     -31,   -45,   -45,   -45,   107,    38,    33,   -45,   184,   184,
     184,   -45,   -45,   -45,   -45,   115,   184,    -9,   296,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   122,    47,
     -45,   -45,   -45,    95,   126,   132,    66,   -45,   -45,    38,
     128,   137,   -45,   296,   -30,   -45,   153,   153,   153,   141,
     239,   120,   134,   135,   144,   151,   152,   154,   155,   184,
     184,   184,   184,   184,   184,   184,   165,   184,   156,   184,
     166,   159,   162,     8,   -45,    87,   -45,   -45,   -45,    66,
      33,   -45,   -45,   296,     2,   -45,   190,   191,   189,   192,
     -45,   -45,   -45,   -45,   305,    92,   108,   138,    83,   124,
     124,   184,   153,   -45,   -45,   249,   -45,   184,   -45,   184,
     184,   -45,   177,   -45,   -45,   -45,   184,   -45,   -45,   -45,
     -45,   153,   -45,    47,   268,    10,   279,   -45,   -45,   296,
     -45,   -45,   174,   184,    47,   -45,   229,   -45,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     0,     0,     1,     3,     4,     0,    28,    97,
       0,     0,    27,     0,    98,     5,     0,    88,    30,     0,
       0,     8,     6,    29,    18,    16,     0,    13,     0,     9,
       0,    23,     0,    20,    21,    26,    12,    14,    31,    37,
       0,    17,    19,     0,     0,    37,     0,     0,     0,     0,
      35,    34,     0,     0,    36,    41,    42,    43,     0,    24,
       0,    86,    15,    32,     0,     0,     0,    84,     0,     0,
       0,    93,    94,    96,    95,    88,     0,     0,    64,    79,
      80,    81,    82,    83,   103,   104,   105,   106,     0,    37,
      38,    53,    40,     0,     0,     0,     0,    22,    45,     0,
       0,    59,    92,    91,     0,    90,    68,    78,    67,     0,
       0,   108,   111,   117,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,    44,    28,    87,    60,    58,     0,
       0,    63,   100,   102,     0,    66,     0,     0,     0,     0,
     107,   110,   113,   116,    70,    71,    72,    76,    73,    77,
      85,     0,    74,    69,    65,     0,    51,     0,    54,     0,
       0,    46,     0,    61,    89,    99,     0,   109,   112,   118,
     115,    75,    49,    37,     0,     0,     0,    25,    62,   101,
      52,    55,     0,     0,    37,    48,     0,    57,    56,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,   -16,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   185,   -45,   -45,   -45,    88,
     -45,   -45,   -45,   -45,   -44,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   127,   -45,   -45,
     -45,   -45,   -32,   -45,   -45,   -13,   -45,    78,   -45,    30,
     -45,    55,   -45,   -45,    81,   -45,    82,   -45,    76,   -45,
      85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,     7,    19,    50,    24,    26,    30,
      36,    44,    27,    28,    32,    33,    43,    37,    95,    11,
      12,    38,    45,    39,    51,    52,    53,    54,    89,    90,
     183,    92,   131,   168,   194,   198,    55,   100,   188,    56,
      57,   128,   103,    79,    60,    80,   104,   105,    81,    13,
      82,   144,    83,    84,   115,    85,   116,    86,   117,    87,
     118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    63,     1,    22,   140,    31,    -2,    23,    41,    96,
      97,   141,   111,   112,   113,   114,   170,    78,   119,   120,
     121,   122,   123,   124,   125,   126,    58,   127,    62,     9,
      61,    10,    58,    64,    67,     4,   106,   107,   108,   175,
      31,    68,   176,     8,   110,   130,    20,   192,    69,   171,
     176,    70,   101,    21,    71,    72,    73,    74,    34,   102,
      40,   133,    34,     5,     9,    46,    10,    14,    75,    76,
      93,    77,    99,    17,    15,   -39,    58,   143,    47,    48,
      49,    16,    17,   136,    94,    21,   101,   154,   155,   156,
     157,   158,   159,   160,   162,   163,    67,   165,   124,   125,
     126,    17,   127,    68,   121,   122,   123,   124,   125,   126,
      69,   127,     9,    70,    10,    25,    71,    72,    73,    74,
     132,   122,   123,   124,   125,   126,   173,   127,    29,   181,
      75,    76,   -10,    77,    59,   184,    65,   143,   186,   190,
     125,   126,    67,   127,   189,    66,    88,    91,    98,    68,
     197,   109,   123,   124,   125,   126,    69,   127,   129,    70,
     146,   196,    71,    72,    73,    74,    67,   134,   135,   138,
      58,   139,   127,    68,   147,   148,    75,    76,   142,    77,
      69,    58,   161,    70,   149,    67,    71,    72,    73,    74,
     150,   151,    68,   152,   153,   167,   166,   164,   169,    69,
      75,    76,    70,    77,    35,    71,    72,    73,    74,   -33,
     -11,   111,   113,   112,   187,   195,   114,    42,   174,    75,
      76,   -33,    77,   172,   185,   180,   137,   177,     9,   178,
      10,   -33,   -33,   179,   -33,   -33,   -33,     0,   -33,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,     0,
     199,     0,     0,     0,     0,     0,   145,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   182,   127,   193,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,     0,
       0,     0,     0,     0,     0,   191,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,   120,   121,   122,   123,
     124,   125,   126,     0,   127
};

static const yytype_int16 yycheck[] =
{
      13,    45,     1,    19,    34,     1,     5,    20,     4,    40,
      41,    41,    21,    22,    23,    24,     8,    49,    10,    11,
      12,    13,    14,    15,    16,    17,    39,    19,    44,    25,
      43,    27,    45,    46,     1,     0,    68,    69,    70,    37,
       1,     8,    40,    36,    76,    89,    16,    37,    15,    41,
      40,    18,    65,     6,    21,    22,    23,    24,    28,    26,
      30,    93,    32,     5,    25,    18,    27,    25,    35,    36,
      20,    38,    34,    35,    37,    28,    89,   109,    31,    32,
      33,    40,    35,    96,    34,     6,    99,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     1,   129,    15,    16,
      17,    35,    19,     8,    12,    13,    14,    15,    16,    17,
      15,    19,    25,    18,    27,     3,    21,    22,    23,    24,
      25,    13,    14,    15,    16,    17,   139,    19,     7,   161,
      35,    36,     7,    38,    35,   167,    34,   169,   170,   183,
      16,    17,     1,    19,   176,    34,    29,    28,    41,     8,
     194,    36,    14,    15,    16,    17,    15,    19,    36,    18,
      40,   193,    21,    22,    23,    24,     1,    41,    36,    41,
     183,    34,    19,     8,    40,    40,    35,    36,    37,    38,
      15,   194,    17,    18,    40,     1,    21,    22,    23,    24,
      39,    39,     8,    39,    39,    36,    30,    41,    36,    15,
      35,    36,    18,    38,     1,    21,    22,    23,    24,     6,
       7,    21,    23,    22,    37,    41,    24,    32,   140,    35,
      36,    18,    38,   135,   169,   149,    99,   146,    25,   147,
      27,    28,    29,   148,    31,    32,    33,    -1,    35,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    37,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    37,    19,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    11,    12,    13,    14,
      15,    16,    17,    -1,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    43,    44,     0,     5,    45,    46,    36,    25,
      27,    61,    62,    91,    25,    37,    40,    35,    87,    47,
      91,     6,    48,    87,    49,     3,    50,    54,    55,     7,
      51,     1,    56,    57,    91,     1,    52,    59,    63,    65,
      91,     4,    57,    58,    53,    64,    18,    31,    32,    33,
      48,    66,    67,    68,    69,    78,    81,    82,    87,    35,
      86,    87,    48,    66,    87,    34,    34,     1,     8,    15,
      18,    21,    22,    23,    24,    35,    36,    38,    84,    85,
      87,    90,    92,    94,    95,    97,    99,   101,    29,    70,
      71,    28,    73,    20,    34,    60,    40,    41,    41,    34,
      79,    87,    26,    84,    88,    89,    84,    84,    84,    36,
      84,    21,    22,    23,    24,    96,    98,   100,   102,    10,
      11,    12,    13,    14,    15,    16,    17,    19,    83,    36,
      66,    74,    25,    84,    41,    36,    87,    79,    41,    34,
      34,    41,    37,    84,    93,    37,    40,    40,    40,    40,
      39,    39,    39,    39,    84,    84,    84,    84,    84,    84,
      84,    17,    84,    84,    41,    84,    30,    36,    75,    36,
       8,    41,    61,    87,    89,    37,    40,    96,    98,   102,
     100,    84,    37,    72,    84,    93,    84,    37,    80,    84,
      66,    37,    37,     9,    76,    41,    84,    66,    77,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    45,    46,    47,    43,    43,    49,    48,
      50,    50,    51,    51,    53,    52,    55,    54,    54,    56,
      56,    58,    57,    57,    60,    59,    59,    61,    62,    62,
      62,    64,    63,    65,    63,    66,    66,    67,    66,    68,
      66,    66,    66,    66,    66,    66,    69,    69,    69,    70,
      71,    72,    71,    74,    73,    76,    75,    77,    78,    79,
      79,    80,    79,    81,    83,    82,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    86,    86,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    96,    96,
      97,    98,    98,    99,   100,   100,   101,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     9,     1,     0,     4,
       3,     2,     2,     0,     0,     3,     0,     4,     0,     2,
       1,     0,     4,     1,     0,     6,     1,     1,     0,     4,
       2,     0,     3,     0,     2,     1,     1,     0,     2,     0,
       2,     1,     1,     1,     3,     3,     4,     8,     7,     4,
       2,     0,     5,     0,     3,     0,     5,     1,     4,     1,
       2,     0,     4,     4,     0,     4,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* @1: %empty  */
#line 50 "./src/scanner.y"
          {abrirArchivos();}
#line 1622 "src/y.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 50 "./src/scanner.y"
                                      {principal=1;tsAddSubprog(yyvsp[-1]);}
#line 1628 "src/y.tab.c"
    break;

  case 4: /* $@3: %empty  */
#line 50 "./src/scanner.y"
                                                                      {decParam = 1;}
#line 1634 "src/y.tab.c"
    break;

  case 5: /* $@4: %empty  */
#line 50 "./src/scanner.y"
                                                                                                                                   {addChar('\n');}
#line 1640 "src/y.tab.c"
    break;

  case 6: /* programa: @1 PRINCIPAL $@2 $@3 PARENTESIS_ABRE parametros PARENTESIS_CIERRA $@4 bloque  */
#line 50 "./src/scanner.y"
                                                                                                                                                           {addChar('\n'); fputs("}",MAIN); cerrarArchivos();}
#line 1646 "src/y.tab.c"
    break;

  case 8: /* $@5: %empty  */
#line 54 "./src/scanner.y"
        {tsAddMark();
        if(!principal && cond<=0)
            cMarkIn();
        }
#line 1655 "src/y.tab.c"
    break;

  case 9: /* bloque: INI_BLOQUE $@5 cuerpo_bloque FIN_BLOQUE  */
#line 60 "./src/scanner.y"
        {tsCleanIn();
        }
#line 1662 "src/y.tab.c"
    break;

  case 14: /* $@6: %empty  */
#line 70 "./src/scanner.y"
                                  {subProg++; addChar('\n'); }
#line 1668 "src/y.tab.c"
    break;

  case 15: /* declar_subprog: cabecera_subprog $@6 bloque  */
#line 70 "./src/scanner.y"
                                                                      {addChar('\n');  cMarkOut(); subProg--;}
#line 1674 "src/y.tab.c"
    break;

  case 16: /* $@7: %empty  */
#line 73 "./src/scanner.y"
                                     {decvariable=1;}
#line 1680 "src/y.tab.c"
    break;

  case 17: /* declar_de_variables_locales: INI_VAR $@7 variables_locales FIN_VAR  */
#line 73 "./src/scanner.y"
                                                                                {decvariable=0;
             if(principal){
             fputs("int main(){\n",MAIN);
             principal=0;
            }
                           }
#line 1691 "src/y.tab.c"
    break;

  case 21: /* $@8: %empty  */
#line 85 "./src/scanner.y"
                              {setType(yyvsp[0]);}
#line 1697 "src/y.tab.c"
    break;

  case 24: /* $@9: %empty  */
#line 88 "./src/scanner.y"
                             {decParam = 1;yyvsp[0].tipoDato = yyvsp[-1].tipoDato;tsAddSubprog(yyvsp[0]); tipoAtipoC(yyvsp[-1]); cWriteIdent(yyvsp[0]); addChar('('); }
#line 1703 "src/y.tab.c"
    break;

  case 25: /* cabecera_subprog: tipo IDENT $@9 PARENTESIS_ABRE parametros PARENTESIS_CIERRA  */
#line 88 "./src/scanner.y"
                                                                                                                                                                                   {decParam=1; addChar(')'); decParam=0;}
#line 1709 "src/y.tab.c"
    break;

  case 27: /* parametros: lista_parametros  */
#line 91 "./src/scanner.y"
                             {tsUpdateNparam(yyvsp[0]); nParam=0; decParam=0;}
#line 1715 "src/y.tab.c"
    break;

  case 29: /* lista_parametros: lista_parametros COMA tipo identificador  */
#line 94 "./src/scanner.y"
                                               { nParam++; setType(yyvsp[-1]); tsAddParam(yyvsp[0]);
                    addChar(',');
                    tipoAtipoC(yyvsp[-1]);
                    cWriteIdent(yyvsp[0]);
    }
#line 1725 "src/y.tab.c"
    break;

  case 30: /* lista_parametros: tipo identificador  */
#line 99 "./src/scanner.y"
                         { nParam++; setType(yyvsp[-1]); tsAddParam(yyvsp[0]);
                    tipoAtipoC(yyvsp[-1]);
                    cWriteIdent(yyvsp[0]);
}
#line 1734 "src/y.tab.c"
    break;

  case 31: /* $@10: %empty  */
#line 105 "./src/scanner.y"
                       {decvariable=2;}
#line 1740 "src/y.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 106 "./src/scanner.y"
     {decvariable=2;}
#line 1746 "src/y.tab.c"
    break;

  case 37: /* $@12: %empty  */
#line 110 "./src/scanner.y"
      {cond++;}
#line 1752 "src/y.tab.c"
    break;

  case 38: /* sentencia: $@12 sentencia_si  */
#line 110 "./src/scanner.y"
                           {cond--;}
#line 1758 "src/y.tab.c"
    break;

  case 39: /* $@13: %empty  */
#line 111 "./src/scanner.y"
      {cond++;}
#line 1764 "src/y.tab.c"
    break;

  case 40: /* sentencia: $@13 sentencia_mientras  */
#line 111 "./src/scanner.y"
                                 {cond--;}
#line 1770 "src/y.tab.c"
    break;

  case 44: /* sentencia: identificador DIRECCION PYC  */
#line 115 "./src/scanner.y"
                                  {
    yyvsp[-1].tipoDato = yyvsp[-2].tipoDato;
    moverCursor(yyvsp[-2],yyvsp[-1]);
    if(!tsCheckList(yyvsp[-2])){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    }
#line 1782 "src/y.tab.c"
    break;

  case 45: /* sentencia: OP_UNARIO identificador PYC  */
#line 122 "./src/scanner.y"
                                  {
    yyvsp[-1].tipoDato = yyvsp[-2].tipoDato;
    moverCursor(yyvsp[-1], yyvsp[-2]);
    if(!tsCheckList(yyvsp[-1])){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    }
#line 1794 "src/y.tab.c"
    break;

  case 46: /* sentencia_asignacion: identificador OP_ASIGNACION expresion PYC  */
#line 130 "./src/scanner.y"
                                                              {
    generaCodigoAsignacion(yyvsp[-3],yyvsp[-1]);
    if(yyvsp[-3].tipoDato != yyvsp[-1].tipoDato){
        printf("Semantic Error(%d): El valor a asignar no es del mismo tipo.[Expected: %s - Got:%s]\n",
        line, tipoAstring(yyvsp[-3].tipoDato),tipoAstring(yyvsp[-1].tipoDato));
    }
    if(tsCheckList(yyvsp[-3])){
        if(!yyvsp[-1].lista){
            printf("Semantic Error(%d): No se puede asignar porque tienen que ser de tipo lista.\n",line);
        }
    }

}
#line 1812 "src/y.tab.c"
    break;

  case 47: /* sentencia_asignacion: identificador OP_ASIGNACION expresion OP_INTERR expresion DOS_PUNTOS expresion PYC  */
#line 143 "./src/scanner.y"
                                                                                        {
        if (yyvsp[-5].tipoDato != TIPOBOOL){
            printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
        if(yyvsp[-3].tipoDato != yyvsp[-1].tipoDato && yyvsp[-7].tipoDato != yyvsp[-3].tipoDato){
            printf("Semantic Error(%d): Los tipos de datos no coinciden\n",line);
        }
        if(tsCheckList(yyvsp[-7])){
            if(!yyvsp[-3].lista && !yyvsp[-1].lista){
                printf("Semantic Error(%d): No se puede asignar porque tienen que ser de tipo lista.\n",line);
            }
        }
        generaCodigoLambda(yyvsp[-7],yyvsp[-5],yyvsp[-3],yyvsp[-1]);
    }
#line 1831 "src/y.tab.c"
    break;

  case 48: /* sentencia_asignacion: identificador OP_ASIGNACION TIPO_DATO PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA PYC  */
#line 157 "./src/scanner.y"
                                                                                                   {
        checkTypes(yyvsp[-6],yyvsp[-4]);
        generaCodigoInicializacion(yyvsp[-6]);
    }
#line 1840 "src/y.tab.c"
    break;

  case 49: /* sentencia_primera: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA  */
#line 162 "./src/scanner.y"
                                                                 {
        yyval.etiq1 = generarEtiqueta();
        yyval.etiq2 = generarEtiqueta();
        generaCodigoSi(&yyval,yyvsp[-1]);
        if (yyvsp[-1].tipoDato != TIPOBOOL){
            printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
                 }
#line 1853 "src/y.tab.c"
    break;

  case 50: /* sentencia_si: sentencia_primera sentencia  */
#line 171 "./src/scanner.y"
            {
            cWriteLabel(yyvsp[-1].etiq1);
        }
#line 1861 "src/y.tab.c"
    break;

  case 51: /* $@14: %empty  */
#line 174 "./src/scanner.y"
                                           {
            generaGOTO(yyvsp[-2].etiq2);
            cWriteLabel(yyvsp[-2].etiq1);
        }
#line 1870 "src/y.tab.c"
    break;

  case 52: /* sentencia_si: sentencia_primera sentencia SINO $@14 sentencia  */
#line 177 "./src/scanner.y"
                  {
            cWriteLabel(yyvsp[-4].etiq2);
        }
#line 1878 "src/y.tab.c"
    break;

  case 53: /* $@15: %empty  */
#line 181 "./src/scanner.y"
                             {
                  yyvsp[0].etiq1=generarEtiqueta();
                  cWriteLabel(yyvsp[0].etiq1);
                  }
#line 1887 "src/y.tab.c"
    break;

  case 54: /* sentencia_mientras: MIENTRAS $@15 cond_mientras  */
#line 184 "./src/scanner.y"
                                  {
                  generaGOTO(yyvsp[-2].etiq1);
                  cWriteLabel(yyvsp[0].etiq1);
                  }
#line 1896 "src/y.tab.c"
    break;

  case 55: /* $@16: %empty  */
#line 190 "./src/scanner.y"
        {
        generaCodigoSi(&yyvsp[-2],yyvsp[-1]);
        if(yyvsp[-1].tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Se espera una expresión condicional de tipo booleana.\n",line);
        }
        }
#line 1907 "src/y.tab.c"
    break;

  case 58: /* sentencia_entrada: ENTRADA DIRECCION lista_variables PYC  */
#line 199 "./src/scanner.y"
                                                         {
                 generarE_S("scanf(\"",0);
                 }
#line 1915 "src/y.tab.c"
    break;

  case 59: /* lista_variables: identificador  */
#line 203 "./src/scanner.y"
                               {TS_subprog_params(yyvsp[0]); }
#line 1921 "src/y.tab.c"
    break;

  case 61: /* $@17: %empty  */
#line 206 "./src/scanner.y"
                {TS_subprog_params(yyvsp[-2]); }
#line 1927 "src/y.tab.c"
    break;

  case 62: /* lista_variables: identificador DIRECCION identificador $@17  */
#line 207 "./src/scanner.y"
                {TS_subprog_params(yyvsp[-1]); }
#line 1933 "src/y.tab.c"
    break;

  case 63: /* sentencia_salida: IMPRIMIR DIRECCION lista_expresiones_o_cadena PYC  */
#line 211 "./src/scanner.y"
                                                                   {
                generarE_S("printf(\"",1);
                }
#line 1941 "src/y.tab.c"
    break;

  case 64: /* @18: %empty  */
#line 215 "./src/scanner.y"
                                      {tsCheckReturn(yyvsp[0], &yyval); generaCodigoReturn(yyvsp[0]);}
#line 1947 "src/y.tab.c"
    break;

  case 66: /* expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA  */
#line 217 "./src/scanner.y"
                                                       {
    yyval.tipoDato = yyvsp[-1].tipoDato;
    yyval.nombre = yyvsp[-1].nombre;
    }
#line 1956 "src/y.tab.c"
    break;

  case 67: /* expresion: OP_UNARIO expresion  */
#line 221 "./src/scanner.y"
                          {
    tsOpUnary(yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre;
    asprintf(&yyval.nombre,"%s",generarVariableTemporal());
    yyvsp[0].lista=0;
    int tipo = yyvsp[0].tipoDato;
    yyvsp[0].tipoDato = yyval.tipoDato;
    generaCodigoVariableTemporal(yyvsp[0],&yyval);
    yyvsp[0].tipoDato = tipo;
    generaCodigoUnario(yyvsp[-1],yyvsp[0],&yyval);
    }
#line 1972 "src/y.tab.c"
    break;

  case 68: /* expresion: OP_INTERR expresion  */
#line 232 "./src/scanner.y"
                          {
    if(!isList(yyvsp[-1])){
        printf("Semantic Error(%d): Esta operación solamente de listas", line);
    }
    yyval.nombre = generarVariableTemporal();
    yyvsp[0].lista = 0;
    generaCodigoVariableTemporal(yyvsp[0],&yyval);
    generaCodigoUnario(yyvsp[-1],yyvsp[0],&yyval);
    }
#line 1986 "src/y.tab.c"
    break;

  case 69: /* expresion: expresion OP_TERNARIO expresion  */
#line 241 "./src/scanner.y"
                                      {
    if(sigsig<0){
    tsCheckLeftList(yyvsp[-2],yyvsp[0],&yyval);
    yyval.nombre = generarVariableTemporal();
    int a = tsSearchId(yyvsp[-2]);
    yyvsp[-2].lista=0;
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    char* res;
    asprintf(res,"%s = getElemento%s(%s,%s);\n", yyval.nombre,
    tipoAstring(ts[a].tipoDato),
    yyvsp[-2].nombre,yyvsp[0].nombre);
    yyval.codigo;
    asprintf(yyval.codigo,"%s",yyvsp[0].nombre);
    cWriteCode(res);
    }else{
        yyval.nombre = yyvsp[-2].nombre;
        yyval.codigo = yyvsp[0].nombre;
    }
    }
#line 2010 "src/y.tab.c"
    break;

  case 70: /* expresion: expresion OP_OR expresion  */
#line 260 "./src/scanner.y"
                                {
    tsOpOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    generaCodigo("%s = %s || %s;\n", yyval.nombre, yyvsp[-2].nombre, yyvsp[0].nombre);
    }
#line 2021 "src/y.tab.c"
    break;

  case 71: /* expresion: expresion OP_AND expresion  */
#line 266 "./src/scanner.y"
                                 {
    tsOpAnd(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    generaCodigo("%s = %s && %s;\n", yyval.nombre, yyvsp[-2].nombre, yyvsp[0].nombre);
    }
#line 2032 "src/y.tab.c"
    break;

  case 72: /* expresion: expresion OP_XOR expresion  */
#line 272 "./src/scanner.y"
                                 {
    tsOpXOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    generaCodigo("%s = %s ^ %s;\n", yyval.nombre, yyvsp[-2].nombre, yyvsp[0].nombre);
    }
#line 2043 "src/y.tab.c"
    break;

  case 73: /* expresion: expresion OP_RELACION expresion  */
#line 278 "./src/scanner.y"
                                      {
    tsOpRel(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    generaCodigoOpRelacion(yyvsp[-2],yyvsp[-1],yyvsp[0],&yyval);
    }
#line 2054 "src/y.tab.c"
    break;

  case 74: /* expresion: expresion OP_MULTIPLICATIVO expresion  */
#line 284 "./src/scanner.y"
                                            {
    tsOpMul(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    generaCodigoOpMultiplicativo(yyvsp[-2],yyvsp[-1],yyvsp[0],&yyval);
    }
#line 2065 "src/y.tab.c"
    break;

  case 75: /* expresion: expresion OP_MULTIPLICATIVO OP_MULTIPLICATIVO expresion  */
#line 290 "./src/scanner.y"
                                                              {
        if(yyvsp[-3].attr!=yyvsp[-2].attr && yyvsp[-3].attr!=1){
            printf("Semantic Error(%d): Operación no permitida. ", line);
        }
        yyvsp[-2].attr=11;
        tsOpMul(yyvsp[-3], yyvsp[-2], yyvsp[0], &yyval);
        yyval.nombre = generarVariableTemporal();
        generaCodigoVariableTemporal(yyvsp[-3],&yyval);
        generaCodigoOpMultiplicativo(yyvsp[-3],yyvsp[-2],yyvsp[-1],&yyval);
    }
#line 2080 "src/y.tab.c"
    break;

  case 76: /* expresion: expresion OP_IGUALDAD expresion  */
#line 300 "./src/scanner.y"
                                      {
    tsOpEqual(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    yyval.codigo;
    asprintf(yyval.codigo,"%s = %s == %s;\n",yyval.nombre, yyvsp[-2].nombre, yyvsp[0].nombre);
    cWriteCode(yyval.codigo);
    }
#line 2093 "src/y.tab.c"
    break;

  case 77: /* expresion: expresion OP_ADITIVO expresion  */
#line 308 "./src/scanner.y"
                                     {
    tsOpAdditivo(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    generaCodigoOpAditivo(yyvsp[-2],yyvsp[-1],yyvsp[0],&yyval);
    }
#line 2104 "src/y.tab.c"
    break;

  case 78: /* expresion: OP_ADITIVO expresion  */
#line 314 "./src/scanner.y"
                           {
    tsOpSign(yyvsp[-1], yyvsp[0], &yyval);
    generaSigno(yyvsp[-1],yyvsp[0], &yyval);
    }
#line 2113 "src/y.tab.c"
    break;

  case 79: /* expresion: sigsig  */
#line 318 "./src/scanner.y"
            {
    sigsig++;
    }
#line 2121 "src/y.tab.c"
    break;

  case 80: /* expresion: identificador  */
#line 321 "./src/scanner.y"
                    {
    decvariable = 0;
    yyval.tipoDato = yyvsp[0].tipoDato; yyval.lista = yyvsp[0].lista; yyval.es_constante = yyvsp[0].es_constante;
    yyval.nombre = yyvsp[0].nombre;
    }
#line 2131 "src/y.tab.c"
    break;

  case 81: /* expresion: constante  */
#line 326 "./src/scanner.y"
                {
        yyval.tipoDato = yyvsp[0].tipoDato; yyval.nombre = yyvsp[0].nombre; yyval.codigo = yyvsp[0].codigo;
    }
#line 2139 "src/y.tab.c"
    break;

  case 82: /* expresion: funcion  */
#line 329 "./src/scanner.y"
              {
        yyval.tipoDato = yyvsp[0].tipoDato; yyval.lista = yyvsp[0].lista; cond=1;
        yyval.nombre = yyvsp[0].nombre;
    }
#line 2148 "src/y.tab.c"
    break;

  case 83: /* expresion: lista_constantes  */
#line 333 "./src/scanner.y"
                       {yyval.tipoDato = yyvsp[0].tipoDato;yyval.lista = yyvsp[0].lista;
        yyval.nombre = generarVariableTemporal();
        yyvsp[0].nombre = yyval.nombre;
        generaCreacionLista(yyvsp[0]);
    }
#line 2158 "src/y.tab.c"
    break;

  case 85: /* sigsig: expresion SIGSIG expresion  */
#line 340 "./src/scanner.y"
                                  {
    tsOpSignSign(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval);
    yyval.nombre = generarVariableTemporal();
    int index = tsSearchId(yyvsp[-2]);
    generaCodigoVariableTemporal(yyvsp[-2],&yyval);
    char* res;
    if(yyvsp[-1].attr==1){
        asprintf(&res,"%s = removeElement%s(%s,%s);\n", yyval.nombre,
        tipoAstring(ts[index].tipoDato),ts[index].nombre,yyvsp[0].nombre);
        cWriteCode(res);
    }else{
        asprintf(&res,"%s = addElementAt%s(%s,%s,%s);\n",
        yyval.nombre, tipoAstring(ts[index].tipoDato),yyvsp[-2].nombre,yyvsp[0].codigo,yyvsp[0].nombre
        );
        cWriteCode(res);
    }
      }
#line 2180 "src/y.tab.c"
    break;

  case 88: /* identificador: IDENT  */
#line 361 "./src/scanner.y"
                     {
                    if(decvariable == 1){
                        yyvsp[0].tipoDato = globaltipoDato; yyvsp[0].lista = globalLista; yyvsp[0].es_constante = 0;
                        yyval.tipoDato = globaltipoDato; yyval.lista = globalLista; yyval.es_constante = 0;
                        tsAddId(yyvsp[0]);
                        if(!decParam) {
                            tipoAtipoC(yyvsp[0]);
                            cWriteIdent(yyvsp[0]);
                            addChar(';');
                            addChar('\n');
                            if(principal){
                                decParam = 1;
                                cWriteCode("extern ");
                                tipoAtipoC(yyvsp[0]);
                                cWriteIdent(yyvsp[0]);
                                addChar(';');
                                addChar('\n');
                                decParam = 0;
                            }
                        }
					}else{
                        if(decParam==0)
                            tsGetId(yyvsp[0], &yyval);
					}
				}
#line 2210 "src/y.tab.c"
    break;

  case 91: /* expresion_o_cadena: expresion  */
#line 393 "./src/scanner.y"
                             {
                  yyval.tipoDato = yyvsp[0].tipoDato;
                  TS_subprog_params(yyvsp[0]);
                  }
#line 2219 "src/y.tab.c"
    break;

  case 92: /* expresion_o_cadena: CADENA  */
#line 397 "./src/scanner.y"
                           {
                  yyval.tipoDato = yyvsp[0].tipoDato;
                  TS_subprog_params(yyvsp[0]);
                  }
#line 2228 "src/y.tab.c"
    break;

  case 93: /* constante: BOOLEANO  */
#line 402 "./src/scanner.y"
                    { yyval.tipoDato = TIPOBOOL; yyval.nombre = yyvsp[0].nombre; }
#line 2234 "src/y.tab.c"
    break;

  case 94: /* constante: CONSTANTE_NUM  */
#line 403 "./src/scanner.y"
                { yyval.tipoDato = ENTERO; yyval.nombre = yyvsp[0].nombre; }
#line 2240 "src/y.tab.c"
    break;

  case 95: /* constante: CONSTANTE_FLOAT  */
#line 404 "./src/scanner.y"
                  { yyval.tipoDato = REAL;  yyval.nombre = yyvsp[0].nombre; }
#line 2246 "src/y.tab.c"
    break;

  case 96: /* constante: CONSTANTE_CAR  */
#line 405 "./src/scanner.y"
                { yyval.tipoDato = CARACTER;  yyval.nombre = yyvsp[0].nombre; }
#line 2252 "src/y.tab.c"
    break;

  case 97: /* tipo: TIPO_DATO  */
#line 407 "./src/scanner.y"
                {yyval.tipoDato = yyvsp[0].tipoDato;yyval.lista=0;}
#line 2258 "src/y.tab.c"
    break;

  case 98: /* tipo: LISTA TIPO_DATO  */
#line 408 "./src/scanner.y"
                      {yyval.tipoDato = yyvsp[0].tipoDato; yyval.lista=1;}
#line 2264 "src/y.tab.c"
    break;

  case 99: /* funcion: IDENT PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA  */
#line 410 "./src/scanner.y"
                                                                   {
            yyval.nombre = generarVariableTemporal();
            cWriteFunc(yyvsp[-3],&yyval);
            tsFunctionCall(yyvsp[-3],&yyval);
            yyval.nombre = yyvsp[-3].nombre;
        }
#line 2275 "src/y.tab.c"
    break;

  case 100: /* funcion: IDENT PARENTESIS_ABRE PARENTESIS_CIERRA  */
#line 416 "./src/scanner.y"
                                                 {
            yyval.nombre = generarVariableTemporal();
            cWriteFunc(yyvsp[-2],&yyval);
            tsFunctionCall(yyvsp[-2],&yyval);
            yyval.nombre = yyvsp[-2].nombre;
       }
#line 2286 "src/y.tab.c"
    break;

  case 101: /* lista_expresiones: lista_expresiones COMA expresion  */
#line 423 "./src/scanner.y"
                                                    {nParam++;TS_subprog_params(yyvsp[0]);}
#line 2292 "src/y.tab.c"
    break;

  case 102: /* lista_expresiones: expresion  */
#line 424 "./src/scanner.y"
                             {nParam=1;TS_subprog_params(yyvsp[0]);}
#line 2298 "src/y.tab.c"
    break;

  case 103: /* lista_constantes: lista_constante_booleano  */
#line 426 "./src/scanner.y"
                                           {yyval.lista=1; yyval.tipoDato=TIPOBOOL;}
#line 2304 "src/y.tab.c"
    break;

  case 104: /* lista_constantes: lista_constante_entero  */
#line 427 "./src/scanner.y"
                            {yyval.lista=1;yyval.tipoDato=ENTERO;}
#line 2310 "src/y.tab.c"
    break;

  case 105: /* lista_constantes: lista_constante_flotante  */
#line 428 "./src/scanner.y"
                              {yyval.lista=1;yyval.tipoDato=REAL;}
#line 2316 "src/y.tab.c"
    break;

  case 106: /* lista_constantes: lista_constante_car  */
#line 429 "./src/scanner.y"
                         {yyval.lista=1;yyval.tipoDato=CARACTER;}
#line 2322 "src/y.tab.c"
    break;

  case 108: /* contenido_lista_booleano: BOOLEANO  */
#line 433 "./src/scanner.y"
                                  {nParam=1; TS_subprog_params(yyvsp[0]); }
#line 2328 "src/y.tab.c"
    break;

  case 109: /* contenido_lista_booleano: BOOLEANO COMA contenido_lista_booleano  */
#line 434 "./src/scanner.y"
                                            {nParam++;TS_subprog_params(yyvsp[-2]);}
#line 2334 "src/y.tab.c"
    break;

  case 111: /* contenido_lista_entero: CONSTANTE_NUM  */
#line 438 "./src/scanner.y"
                                      {nParam=1; TS_subprog_params(yyvsp[0]); }
#line 2340 "src/y.tab.c"
    break;

  case 112: /* contenido_lista_entero: CONSTANTE_NUM COMA contenido_lista_entero  */
#line 439 "./src/scanner.y"
                                               {nParam++;TS_subprog_params(yyvsp[-2]);}
#line 2346 "src/y.tab.c"
    break;

  case 114: /* contenido_lista_flotante: CONSTANTE_FLOAT  */
#line 443 "./src/scanner.y"
                                          {nParam=1; TS_subprog_params(yyvsp[0]); }
#line 2352 "src/y.tab.c"
    break;

  case 115: /* contenido_lista_flotante: CONSTANTE_FLOAT COMA contenido_lista_flotante  */
#line 444 "./src/scanner.y"
                                                   {nParam++;TS_subprog_params(yyvsp[-2]);}
#line 2358 "src/y.tab.c"
    break;

  case 117: /* contenido_lista_car: CONSTANTE_CAR  */
#line 448 "./src/scanner.y"
                                   {nParam=1; TS_subprog_params(yyvsp[0]); }
#line 2364 "src/y.tab.c"
    break;

  case 118: /* contenido_lista_car: CONSTANTE_CAR COMA contenido_lista_car  */
#line 449 "./src/scanner.y"
                                            {nParam++;TS_subprog_params(yyvsp[-2]);}
#line 2370 "src/y.tab.c"
    break;


#line 2374 "src/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 451 "./src/scanner.y"


#include "lex.yy.c"


void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s \n", yylineno, msg) ;
}
