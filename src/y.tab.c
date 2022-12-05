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
#line 1 "./src/scanner.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "y.tab.h"
#include "../include/scansemantic.h"

// int yylex();
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
  YYSYMBOL_OP_OR = 8,                      /* OP_OR  */
  YYSYMBOL_OP_AND = 9,                     /* OP_AND  */
  YYSYMBOL_OP_XOR = 10,                    /* OP_XOR  */
  YYSYMBOL_OP_IGUALDAD = 11,               /* OP_IGUALDAD  */
  YYSYMBOL_OP_RELACION = 12,               /* OP_RELACION  */
  YYSYMBOL_OP_ADITIVO = 13,                /* OP_ADITIVO  */
  YYSYMBOL_SIGSIG = 14,                    /* SIGSIG  */
  YYSYMBOL_OP_MULTIPLICATIVO = 15,         /* OP_MULTIPLICATIVO  */
  YYSYMBOL_OP_UNARIO = 16,                 /* OP_UNARIO  */
  YYSYMBOL_OP_TERNARIO = 17,               /* OP_TERNARIO  */
  YYSYMBOL_OP_ASIGNACION = 18,             /* OP_ASIGNACION  */
  YYSYMBOL_BOOLEANO = 19,                  /* BOOLEANO  */
  YYSYMBOL_CONSTANTE_NUM = 20,             /* CONSTANTE_NUM  */
  YYSYMBOL_CONSTANTE_CAR = 21,             /* CONSTANTE_CAR  */
  YYSYMBOL_CONSTANTE_FLOAT = 22,           /* CONSTANTE_FLOAT  */
  YYSYMBOL_TIPO_DATO = 23,                 /* TIPO_DATO  */
  YYSYMBOL_CADENA = 24,                    /* CADENA  */
  YYSYMBOL_LISTA = 25,                     /* LISTA  */
  YYSYMBOL_MIENTRAS = 26,                  /* MIENTRAS  */
  YYSYMBOL_SI = 27,                        /* SI  */
  YYSYMBOL_SINO = 28,                      /* SINO  */
  YYSYMBOL_ENTRADA = 29,                   /* ENTRADA  */
  YYSYMBOL_IMPRIMIR = 30,                  /* IMPRIMIR  */
  YYSYMBOL_DEVOLVER = 31,                  /* DEVOLVER  */
  YYSYMBOL_DIRECCION = 32,                 /* DIRECCION  */
  YYSYMBOL_IDENT = 33,                     /* IDENT  */
  YYSYMBOL_PARENTESIS_ABRE = 34,           /* PARENTESIS_ABRE  */
  YYSYMBOL_PARENTESIS_CIERRA = 35,         /* PARENTESIS_CIERRA  */
  YYSYMBOL_CORCHETE_ABRE = 36,             /* CORCHETE_ABRE  */
  YYSYMBOL_CORCHETE_CIERRA = 37,           /* CORCHETE_CIERRA  */
  YYSYMBOL_COMA = 38,                      /* COMA  */
  YYSYMBOL_PYC = 39,                       /* PYC  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_programa = 41,                  /* programa  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_bloque = 44,                    /* bloque  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_cuerpo_bloque = 46,             /* cuerpo_bloque  */
  YYSYMBOL_declar_de_subprogs = 47,        /* declar_de_subprogs  */
  YYSYMBOL_declar_subprog = 48,            /* declar_subprog  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_declar_de_variables_locales = 50, /* declar_de_variables_locales  */
  YYSYMBOL_51_5 = 51,                      /* $@5  */
  YYSYMBOL_variables_locales = 52,         /* variables_locales  */
  YYSYMBOL_cuerpo_declar_variables = 53,   /* cuerpo_declar_variables  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_identificador = 55,             /* identificador  */
  YYSYMBOL_varios_identificador = 56,      /* varios_identificador  */
  YYSYMBOL_tipo = 57,                      /* tipo  */
  YYSYMBOL_cabecera_subprog = 58,          /* cabecera_subprog  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_lista_parametros = 60,          /* lista_parametros  */
  YYSYMBOL_sentencias = 61,                /* sentencias  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_sentencia = 64,                 /* sentencia  */
  YYSYMBOL_sentencia_asignacion = 65,      /* sentencia_asignacion  */
  YYSYMBOL_sentencia_si = 66,              /* sentencia_si  */
  YYSYMBOL_sentencia_mientras = 67,        /* sentencia_mientras  */
  YYSYMBOL_sentencia_entrada = 68,         /* sentencia_entrada  */
  YYSYMBOL_sentencia_salida = 69,          /* sentencia_salida  */
  YYSYMBOL_lista_variables = 70,           /* lista_variables  */
  YYSYMBOL_lista_expresiones_o_cadena = 71, /* lista_expresiones_o_cadena  */
  YYSYMBOL_sentencia_retorno = 72,         /* sentencia_retorno  */
  YYSYMBOL_73_10 = 73,                     /* @10  */
  YYSYMBOL_expresion = 74,                 /* expresion  */
  YYSYMBOL_funcion = 75,                   /* funcion  */
  YYSYMBOL_lista_expresiones = 76,         /* lista_expresiones  */
  YYSYMBOL_lista_constantes = 77,          /* lista_constantes  */
  YYSYMBOL_lista_constante_booleano = 78,  /* lista_constante_booleano  */
  YYSYMBOL_contenido_lista_booleano = 79,  /* contenido_lista_booleano  */
  YYSYMBOL_lista_constante_entero = 80,    /* lista_constante_entero  */
  YYSYMBOL_contenido_lista_entero = 81,    /* contenido_lista_entero  */
  YYSYMBOL_lista_constante_flotante = 82,  /* lista_constante_flotante  */
  YYSYMBOL_contenido_lista_flotante = 83,  /* contenido_lista_flotante  */
  YYSYMBOL_lista_constante_car = 84,       /* lista_constante_car  */
  YYSYMBOL_contenido_lista_car = 85,       /* contenido_lista_car  */
  YYSYMBOL_constante = 86                  /* constante  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    70,    70,    71,    74,    73,    79,    80,
      82,    83,    85,    85,    87,    87,    88,    90,    91,    93,
      93,    96,    98,   114,   115,   117,   118,   120,   120,   121,
     123,   124,   125,   127,   127,   128,   128,   131,   132,   133,
     134,   135,   136,   137,   139,   150,   154,   160,   166,   168,
     170,   171,   172,   174,   175,   176,   177,   179,   179,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   198,   199,   200,   201,   203,   204,
     206,   207,   209,   210,   211,   212,   214,   216,   217,   219,
     221,   222,   224,   226,   227,   229,   231,   232,   234,   235,
     236,   237
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
  "PRINCIPAL", "INI_BLOQUE", "FIN_BLOQUE", "OP_OR", "OP_AND", "OP_XOR",
  "OP_IGUALDAD", "OP_RELACION", "OP_ADITIVO", "SIGSIG",
  "OP_MULTIPLICATIVO", "OP_UNARIO", "OP_TERNARIO", "OP_ASIGNACION",
  "BOOLEANO", "CONSTANTE_NUM", "CONSTANTE_CAR", "CONSTANTE_FLOAT",
  "TIPO_DATO", "CADENA", "LISTA", "MIENTRAS", "SI", "SINO", "ENTRADA",
  "IMPRIMIR", "DEVOLVER", "DIRECCION", "IDENT", "PARENTESIS_ABRE",
  "PARENTESIS_CIERRA", "CORCHETE_ABRE", "CORCHETE_CIERRA", "COMA", "PYC",
  "$accept", "programa", "$@1", "$@2", "bloque", "$@3", "cuerpo_bloque",
  "declar_de_subprogs", "declar_subprog", "$@4",
  "declar_de_variables_locales", "$@5", "variables_locales",
  "cuerpo_declar_variables", "$@6", "identificador",
  "varios_identificador", "tipo", "cabecera_subprog", "$@7",
  "lista_parametros", "sentencias", "$@8", "$@9", "sentencia",
  "sentencia_asignacion", "sentencia_si", "sentencia_mientras",
  "sentencia_entrada", "sentencia_salida", "lista_variables",
  "lista_expresiones_o_cadena", "sentencia_retorno", "@10", "expresion",
  "funcion", "lista_expresiones", "lista_constantes",
  "lista_constante_booleano", "contenido_lista_booleano",
  "lista_constante_entero", "contenido_lista_entero",
  "lista_constante_flotante", "contenido_lista_flotante",
  "lista_constante_car", "contenido_lista_car", "constante", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -94,   -94,     6,   -17,   -94,    28,   -94,     9,    -6,
     -28,   -94,   -94,   -94,   -94,    28,    30,    -6,   -94,   -94,
     -94,    36,   -94,    41,   -94,    53,   -94,   134,   -94,    10,
     -94,   -94,   -94,   -94,    -6,   -94,    45,   189,   -94,   -94,
      -6,   -94,    30,   189,    21,    29,    43,    48,   110,   -94,
      67,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,    49,
      76,   -94,   -94,   110,   110,    58,    25,   -94,   110,   110,
     -94,   -94,   -94,   -94,   110,    93,    47,   215,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   110,    -6,   -94,    28,   139,
     167,    58,    86,    81,    90,    25,    85,   215,    26,    26,
     177,    95,    96,   104,   107,    91,   125,   129,   164,   -94,
      73,   110,   110,   110,   110,   110,   110,   110,   110,   -94,
     193,   175,    88,   -94,   -23,   189,   189,   -94,    -6,   -94,
      25,   -94,   -94,   -94,   198,   201,   227,   228,   -94,   -94,
     -94,   -94,   -94,   215,   -22,   194,   223,   230,   156,   183,
     122,     5,    26,   -94,   -94,   -94,   -94,   -94,   221,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   110,   189,   215,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     2,     0,     0,     1,    32,    25,     0,     0,
       0,    26,    22,    30,     3,     0,     0,     0,     6,     4,
      31,    16,    14,     0,    11,     0,     7,     0,    21,     0,
      18,    19,    29,    10,     0,    12,    33,     0,    15,    17,
       0,    27,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    36,    38,    39,    40,    41,    42,    43,    23,     0,
       0,    13,    34,     0,     0,     0,     0,    77,     0,     0,
      98,    99,   101,   100,     0,     0,    73,    57,    75,    76,
      82,    83,    84,    85,    74,     0,     0,    20,    32,     0,
       0,     0,    50,     0,    55,     0,     0,    53,    71,    60,
       0,    87,    90,    96,    93,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,    24,     0,     0,     0,    51,     0,    48,
       0,    54,    49,    59,     0,     0,     0,     0,    86,    89,
      92,    95,    79,    81,     0,    64,    65,    66,    69,    67,
      70,    72,    68,    63,    58,    44,    28,    47,    45,    52,
      56,    88,    91,    97,    94,    78,     0,     0,    80,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -12,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   222,   -94,    -9,   -94,    35,   -94,   -94,
     165,   -94,   -94,   -94,   -42,   -94,   -94,   -94,   -94,   -94,
     161,   -93,   -94,   -94,   -45,   -94,   -94,   -94,   -94,   120,
     -94,   121,   -94,   118,   -94,   123,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    16,    49,    21,    23,    27,    33,    42,
      24,    25,    29,    30,    40,    76,    59,     9,    35,    60,
      10,    36,    43,    37,    51,    52,    53,    54,    55,    56,
      93,    96,    57,   121,    97,    78,   144,    79,    80,   105,
      81,   106,    82,   107,    83,   108,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    62,   131,    77,    19,     1,     5,    14,    20,     2,
      15,    28,   156,   165,    38,    15,   166,     6,    89,    90,
     118,   119,   120,    98,    99,    41,    67,    12,    50,   100,
      61,    58,    11,     7,    50,     8,    18,   160,    68,    22,
     122,    69,   119,   120,    70,    71,    72,    73,    26,    94,
      17,     7,    -8,     8,    28,    63,    92,    95,    12,    74,
      31,    75,    34,    64,    31,   143,   145,   146,   147,   148,
     149,   150,   151,   152,    67,    65,     7,   123,     8,   109,
      66,   110,    92,   157,   158,    85,    68,    86,    87,    69,
      91,    12,    70,    71,    72,    73,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    12,    74,   142,    75,
      88,    67,   101,   102,   103,   104,    50,    50,   128,   159,
     129,   168,   130,    68,   132,   169,    69,   155,   138,    70,
      71,    72,    73,   134,   135,    32,   117,   118,   119,   120,
     -35,    -9,   136,    12,    74,   137,    75,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     7,    50,     8,
     -35,   -35,   139,   -35,   -35,   -35,   140,   -35,   115,   116,
     117,   118,   119,   120,   125,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    18,   116,   117,   118,   119,
     120,   141,   126,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   133,   153,   154,    44,    45,   101,    46,    47,
      48,   102,    12,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   113,   114,   115,   116,   117,   118,   119,
     120,   114,   115,   116,   117,   118,   119,   120,   103,   167,
     104,    39,   127,   124,   161,   164,   162,     0,     0,   163
};

static const yytype_int16 yycheck[] =
{
       9,    43,    95,    48,    16,     1,     0,    35,    17,     5,
      38,     1,    35,    35,     4,    38,    38,    34,    63,    64,
      15,    16,    17,    68,    69,    34,     1,    33,    37,    74,
      42,    40,    23,    23,    43,    25,     6,   130,    13,     3,
      85,    16,    16,    17,    19,    20,    21,    22,     7,    24,
      15,    23,     7,    25,     1,    34,    65,    32,    33,    34,
      25,    36,    27,    34,    29,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     1,    32,    23,    86,    25,    32,
      32,    34,    91,   125,   126,    18,    13,    38,    39,    16,
      32,    33,    19,    20,    21,    22,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    33,    34,    35,    36,
      34,     1,    19,    20,    21,    22,   125,   126,    32,   128,
      39,   166,    32,    13,    39,   167,    16,    39,    37,    19,
      20,    21,    22,    38,    38,     1,    14,    15,    16,    17,
       6,     7,    38,    33,    34,    38,    36,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    23,   167,    25,
      26,    27,    37,    29,    30,    31,    37,    33,    12,    13,
      14,    15,    16,    17,    35,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     6,    13,    14,    15,    16,
      17,    37,    35,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    35,    20,    39,    26,    27,    19,    29,    30,
      31,    20,    33,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    10,    11,    12,    13,    14,    15,    16,
      17,    11,    12,    13,    14,    15,    16,    17,    21,    28,
      22,    29,    91,    88,   134,   137,   135,    -1,    -1,   136
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    41,    42,     0,    34,    23,    25,    57,
      60,    23,    33,    55,    35,    38,    43,    57,     6,    44,
      55,    45,     3,    46,    50,    51,     7,    47,     1,    52,
      53,    57,     1,    48,    57,    58,    61,    63,     4,    53,
      54,    55,    49,    62,    26,    27,    29,    30,    31,    44,
      55,    64,    65,    66,    67,    68,    69,    72,    55,    56,
      59,    44,    64,    34,    34,    32,    32,     1,    13,    16,
      19,    20,    21,    22,    34,    36,    55,    74,    75,    77,
      78,    80,    82,    84,    86,    18,    38,    39,    34,    74,
      74,    32,    55,    70,    24,    32,    71,    74,    74,    74,
      74,    19,    20,    21,    22,    79,    81,    83,    85,    32,
      34,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    73,    74,    55,    60,    35,    35,    70,    32,    39,
      32,    71,    39,    35,    38,    38,    38,    38,    37,    37,
      37,    37,    35,    74,    76,    74,    74,    74,    74,    74,
      74,    74,    74,    20,    39,    39,    35,    64,    64,    55,
      71,    79,    81,    85,    83,    35,    38,    28,    74,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    43,    41,    41,    45,    44,    46,    46,
      47,    47,    49,    48,    51,    50,    50,    52,    52,    54,
      53,    53,    55,    56,    56,    57,    57,    59,    58,    58,
      60,    60,    60,    62,    61,    63,    61,    64,    64,    64,
      64,    64,    64,    64,    65,    66,    66,    67,    68,    69,
      70,    70,    70,    71,    71,    71,    71,    73,    72,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    79,    79,    80,
      81,    81,    82,    83,    83,    84,    85,    85,    86,    86,
      86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     7,     1,     0,     4,     3,     2,
       2,     0,     0,     3,     0,     4,     0,     2,     1,     0,
       4,     1,     1,     1,     3,     1,     2,     0,     6,     1,
       2,     4,     0,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     7,     5,     4,     4,
       1,     2,     3,     1,     2,     1,     3,     0,     4,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     1
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
  case 2: /* $@1: %empty  */
#line 70 "./src/scanner.y"
                    {tsAddSubprog(yyvsp[0]);}
#line 1574 "src/y.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 70 "./src/scanner.y"
                                                                                           {subProg=1;}
#line 1580 "src/y.tab.c"
    break;

  case 4: /* programa: PRINCIPAL $@1 PARENTESIS_ABRE lista_parametros PARENTESIS_CIERRA $@2 bloque  */
#line 70 "./src/scanner.y"
                                                                                                              {subProg=0;}
#line 1586 "src/y.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 74 "./src/scanner.y"
        {tsAddMark();}
#line 1592 "src/y.tab.c"
    break;

  case 7: /* bloque: INI_BLOQUE $@3 cuerpo_bloque FIN_BLOQUE  */
#line 77 "./src/scanner.y"
        {tsCleanIn();}
#line 1598 "src/y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 85 "./src/scanner.y"
                                 {subProg=1;}
#line 1604 "src/y.tab.c"
    break;

  case 13: /* declar_subprog: cabecera_subprog $@4 bloque  */
#line 85 "./src/scanner.y"
                                                     {subProg=0;}
#line 1610 "src/y.tab.c"
    break;

  case 14: /* $@5: %empty  */
#line 87 "./src/scanner.y"
                                     {decvariable=1;}
#line 1616 "src/y.tab.c"
    break;

  case 15: /* declar_de_variables_locales: INI_VAR $@5 variables_locales FIN_VAR  */
#line 87 "./src/scanner.y"
                                                                                {decvariable=0;}
#line 1622 "src/y.tab.c"
    break;

  case 19: /* $@6: %empty  */
#line 93 "./src/scanner.y"
                              {setType(yyvsp[0]);
                //printf("El globaltipoDato es: (%d)", $1.tipoDato);
            }
#line 1630 "src/y.tab.c"
    break;

  case 22: /* identificador: IDENT  */
#line 98 "./src/scanner.y"
                     {
					//printf("pila 1 \n");
                    //printTS();
                    if(decvariable == 1){
                        //printf("Antes: Se quiere declarar:  (%i) (%d) (%i) (%i).\n", $1.attr, $1.nombre, $1.tipoDato, $1.nDim);
                        //printf("Se ha declarado una variable.\n");
						yyvsp[0].nDim=0; yyvsp[0].tamDimen1 = 0; yyvsp[0].tamDimen2 = 0; tsAddId(yyvsp[0]);
                        //printf("pila 2 \n");
                        //printTS();
                        //printf("Despues: Se ha declarado: (%i) (%d) (%i) (%i).\n", $1.attr, $1.nombre, $1.tipoDato, $1.nDim);
					}else{
						if(decParam == 0)
							tsGetId(yyvsp[0], &yyval);
					}
				}
#line 1650 "src/y.tab.c"
    break;

  case 25: /* tipo: TIPO_DATO  */
#line 117 "./src/scanner.y"
                {yyval.tipoDato = yyvsp[0].tipoDato;}
#line 1656 "src/y.tab.c"
    break;

  case 26: /* tipo: LISTA TIPO_DATO  */
#line 118 "./src/scanner.y"
                      {yyval.tipoDato = yyvsp[-1].tipoDato;}
#line 1662 "src/y.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 120 "./src/scanner.y"
                                     {tsAddSubprog(yyvsp[0]);}
#line 1668 "src/y.tab.c"
    break;

  case 33: /* $@8: %empty  */
#line 127 "./src/scanner.y"
                       {decvariable=2;}
#line 1674 "src/y.tab.c"
    break;

  case 35: /* $@9: %empty  */
#line 128 "./src/scanner.y"
     {decvariable=2;}
#line 1680 "src/y.tab.c"
    break;

  case 44: /* sentencia_asignacion: identificador OP_ASIGNACION expresion PYC  */
#line 139 "./src/scanner.y"
                                                               {
    //printf("el $1 es: (%d)",$1.tipoDato);
    //printf("el $3 es: (%d)", $3.tipoDato);
    if(yyvsp[-3].tipoDato != yyvsp[-1].tipoDato){
        printf("Semantic Error(%d): No son del mismo tipo.\n", line);
    }
    if(!equalSize(yyvsp[-3],yyvsp[-1])){
        printf("Semantic Error(%d): No son del mismo tamanio.\n",line);
    }

}
#line 1696 "src/y.tab.c"
    break;

  case 45: /* sentencia_si: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia  */
#line 150 "./src/scanner.y"
                                                                      {
        if (yyvsp[-2].tipoDato != TIPOBOOL){
            printf("Expression are not logic. \n");
        }}
#line 1705 "src/y.tab.c"
    break;

  case 46: /* sentencia_si: SI PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia SINO sentencia  */
#line 154 "./src/scanner.y"
                                                                                     {
                if(yyvsp[-4].tipoDato != TIPOBOOL){
                    printf("Expression are not logic");
                }
            }
#line 1715 "src/y.tab.c"
    break;

  case 47: /* sentencia_mientras: MIENTRAS PARENTESIS_ABRE expresion PARENTESIS_CIERRA sentencia  */
#line 160 "./src/scanner.y"
                                                                                  {
        if(yyvsp[-2].tipoDato != TIPOBOOL){
                printf("Semantic Error(%d): Expression are not logic.\n", line);
        }
}
#line 1725 "src/y.tab.c"
    break;

  case 57: /* @10: %empty  */
#line 179 "./src/scanner.y"
                                      {tsCheckReturn(yyvsp[0], &yyval);}
#line 1731 "src/y.tab.c"
    break;

  case 59: /* expresion: PARENTESIS_ABRE expresion PARENTESIS_CIERRA  */
#line 181 "./src/scanner.y"
                                                       { yyval.tipoDato = yyvsp[-1].tipoDato; yyval.nDim = yyvsp[-1].nDim; yyval.tamDimen1 = yyvsp[-1].tamDimen1; yyval.tamDimen2 = yyvsp[-1].tamDimen2; }
#line 1737 "src/y.tab.c"
    break;

  case 60: /* expresion: OP_UNARIO expresion  */
#line 182 "./src/scanner.y"
                          {tsOpUnary(yyvsp[-1], yyvsp[0], &yyval); }
#line 1743 "src/y.tab.c"
    break;

  case 61: /* expresion: expresion OP_UNARIO  */
#line 183 "./src/scanner.y"
                          {tsOpUnary(yyvsp[0], yyvsp[-1], &yyval); }
#line 1749 "src/y.tab.c"
    break;

  case 64: /* expresion: expresion OP_OR expresion  */
#line 186 "./src/scanner.y"
                                {tsOpOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1755 "src/y.tab.c"
    break;

  case 65: /* expresion: expresion OP_AND expresion  */
#line 187 "./src/scanner.y"
                                 {tsOpAnd(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1761 "src/y.tab.c"
    break;

  case 66: /* expresion: expresion OP_XOR expresion  */
#line 188 "./src/scanner.y"
                                 {tsOpXOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1767 "src/y.tab.c"
    break;

  case 67: /* expresion: expresion OP_RELACION expresion  */
#line 189 "./src/scanner.y"
                                      {tsOpRel(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1773 "src/y.tab.c"
    break;

  case 68: /* expresion: expresion OP_MULTIPLICATIVO expresion  */
#line 190 "./src/scanner.y"
                                            {tsOpMul(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1779 "src/y.tab.c"
    break;

  case 69: /* expresion: expresion OP_IGUALDAD expresion  */
#line 191 "./src/scanner.y"
                                      {tsOpEqual(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1785 "src/y.tab.c"
    break;

  case 70: /* expresion: expresion OP_ADITIVO expresion  */
#line 192 "./src/scanner.y"
                                     {tsOpAdditivo(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1791 "src/y.tab.c"
    break;

  case 71: /* expresion: OP_ADITIVO expresion  */
#line 193 "./src/scanner.y"
                           {tsOpSign(yyvsp[-1], yyvsp[0], &yyval); }
#line 1797 "src/y.tab.c"
    break;

  case 72: /* expresion: expresion SIGSIG expresion  */
#line 194 "./src/scanner.y"
                                 {tsOpSignSign(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1803 "src/y.tab.c"
    break;

  case 73: /* expresion: identificador  */
#line 195 "./src/scanner.y"
                    { decvariable = 0;
        //printf("Se ha usado un identificador en la expresion\n");
    }
#line 1811 "src/y.tab.c"
    break;

  case 74: /* expresion: constante  */
#line 198 "./src/scanner.y"
                {yyval.tipoDato = yyvsp[0].tipoDato; yyval.nDim = yyvsp[0].nDim; yyval.tamDimen1 = yyvsp[0].tamDimen1; yyval.tamDimen2 = yyvsp[-1].tamDimen2; }
#line 1817 "src/y.tab.c"
    break;

  case 75: /* expresion: funcion  */
#line 199 "./src/scanner.y"
              {yyval.tipoDato = yyvsp[0].tipoDato; yyval.nDim = yyvsp[0].nDim; yyval.tamDimen1 = yyvsp[-1].tamDimen1; yyval.tamDimen2 = yyvsp[-1].tamDimen2; currentFunction = -1;}
#line 1823 "src/y.tab.c"
    break;

  case 78: /* funcion: identificador PARENTESIS_ABRE lista_expresiones PARENTESIS_CIERRA  */
#line 203 "./src/scanner.y"
                                                                           { tsFunctionCall(yyvsp[-3], &yyval); }
#line 1829 "src/y.tab.c"
    break;

  case 79: /* funcion: identificador PARENTESIS_ABRE PARENTESIS_CIERRA  */
#line 204 "./src/scanner.y"
                                                         { tsFunctionCall(yyvsp[-2], &yyval); }
#line 1835 "src/y.tab.c"
    break;

  case 98: /* constante: BOOLEANO  */
#line 234 "./src/scanner.y"
                    { yyval.tipoDato = TIPOBOOL; yyval.nDim = 0; yyval.tamDimen1 = 0; yyval.tamDimen2 = 0; }
#line 1841 "src/y.tab.c"
    break;

  case 99: /* constante: CONSTANTE_NUM  */
#line 235 "./src/scanner.y"
                { yyval.tipoDato = ENTERO; yyval.nDim = 0; yyval.tamDimen1 = 0; yyval.tamDimen2 = 0; }
#line 1847 "src/y.tab.c"
    break;

  case 100: /* constante: CONSTANTE_FLOAT  */
#line 236 "./src/scanner.y"
                  { yyval.tipoDato = REAL; yyval.nDim = 0; yyval.tamDimen1 = 0; yyval.tamDimen2 = 0; }
#line 1853 "src/y.tab.c"
    break;

  case 101: /* constante: CONSTANTE_CAR  */
#line 237 "./src/scanner.y"
                { yyval.tipoDato = CARACTER; yyval.nDim = 0; yyval.tamDimen1 = 0; yyval.tamDimen2 = 0; }
#line 1859 "src/y.tab.c"
    break;


#line 1863 "src/y.tab.c"

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

#line 239 "./src/scanner.y"


#include "lex.yy.c"


void yyerror(const char *msg)
{
     fprintf(stderr,"[Linea %d]: %s \n", yylineno, msg) ;
}
