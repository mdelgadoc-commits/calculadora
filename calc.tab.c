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
#line 1 "calc.y"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "nodo.h"
#include "ast.h"
#include "cst.h"
#include "semantica.h"
#include "intermedio.h"

extern int yylex();
extern int num_linea;
void yyerror(const char *s);

int total_errores_lexicos     = 0;
int total_errores_sintacticos = 0;
int total_errores_logicos     = 0;

void yyerror(const char *s) {
    std::cerr << "\n\033[1;31m[ERROR SINTACTICO] Linea " << num_linea
              << ": estructura invalida.\033[0m\n"
              << "  Posibles causas:\n"
              << "  - Falta ';' al final\n"
              << "  - Parentesis o llave sin cerrar\n"
              << "  - Instruccion incompleta\n\n";
    total_errores_sintacticos++;
}

#line 104 "calc.tab.c"

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

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_VERDADERO = 4,                  /* VERDADERO  */
  YYSYMBOL_FALSO = 5,                      /* FALSO  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TEXTO_VAL = 7,                  /* TEXTO_VAL  */
  YYSYMBOL_SI = 8,                         /* SI  */
  YYSYMBOL_SINO = 9,                       /* SINO  */
  YYSYMBOL_MIENTRAS = 10,                  /* MIENTRAS  */
  YYSYMBOL_PARA = 11,                      /* PARA  */
  YYSYMBOL_FUNCION = 12,                   /* FUNCION  */
  YYSYMBOL_RETORNAR = 13,                  /* RETORNAR  */
  YYSYMBOL_MOSTRAR = 14,                   /* MOSTRAR  */
  YYSYMBOL_DATOINGRESADO = 15,             /* DATOINGRESADO  */
  YYSYMBOL_SALIDA = 16,                    /* SALIDA  */
  YYSYMBOL_ENTRADA = 17,                   /* ENTRADA  */
  YYSYMBOL_TENTERO = 18,                   /* TENTERO  */
  YYSYMBOL_TDECIMAL = 19,                  /* TDECIMAL  */
  YYSYMBOL_TTEXTO = 20,                    /* TTEXTO  */
  YYSYMBOL_LE = 21,                        /* LE  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_LT = 25,                        /* LT  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UMENOS = 35,                    /* UMENOS  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_programa = 46,                  /* programa  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_instrucciones = 48,             /* instrucciones  */
  YYSYMBOL_bloque = 49,                    /* bloque  */
  YYSYMBOL_instruccion = 50,               /* instruccion  */
  YYSYMBOL_params_lista = 51,              /* params_lista  */
  YYSYMBOL_args_lista = 52,                /* args_lista  */
  YYSYMBOL_cond = 53,                      /* cond  */
  YYSYMBOL_expr = 54                       /* expr  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
      42,    43,    32,    30,    44,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    59,    64,    65,    81,    86,    93,   100,
     107,   115,   124,   133,   142,   149,   155,   165,   171,   184,
     193,   203,   213,   223,   231,   238,   243,   252,   260,   261,
     267,   276,   277,   282,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   302,   307,   308,   309,   310,   316,   321,
     330,   336,   342,   348,   379,   385,   391
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "VERDADERO",
  "FALSO", "ID", "TEXTO_VAL", "SI", "SINO", "MIENTRAS", "PARA", "FUNCION",
  "RETORNAR", "MOSTRAR", "DATOINGRESADO", "SALIDA", "ENTRADA", "TENTERO",
  "TDECIMAL", "TTEXTO", "LE", "GE", "EQ", "NE", "LT", "GT", "AND", "OR",
  "NOT", "'+'", "'-'", "'*'", "'/'", "'%'", "UMENOS", "'{'", "'}'", "';'",
  "'['", "']'", "'='", "'('", "')'", "','", "$accept", "programa", "$@1",
  "instrucciones", "bloque", "instruccion", "params_lista", "args_lista",
  "cond", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -90,    24,   -90,   -90,   132,   -90,   -90,   -90,     6,   -90,
     -13,     1,    15,    -3,     2,    64,    73,    88,   107,   108,
       2,     2,   -90,   157,     2,     2,     2,   150,   150,   132,
      74,   116,   -16,   182,   155,   118,    23,   -27,    90,   -90,
      36,     2,     2,     2,     2,     2,   -90,    87,   191,    -8,
      41,   150,   -15,   177,    -9,   150,   112,    83,     2,     2,
     -90,    14,    93,   200,    94,   -90,   130,     2,   -90,     2,
     -90,   -90,    55,    55,   -90,   -90,   -90,   100,   -90,   110,
       2,   -90,   150,   150,   113,     2,     2,     2,     2,     2,
       2,   113,    22,   158,    34,   112,   135,    49,   -90,   -90,
     -90,   -90,   131,   209,   218,     2,   -90,    41,   -90,   143,
     -90,   163,    41,    41,    41,    41,    41,    41,   -90,   132,
     -90,   113,   159,    65,   -90,   -90,   138,   -90,   -90,   227,
      92,   113,   137,   -90,   167,   113,   -90,   -90,   -90,   -90,
     113,   -90,   -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     3,    43,    44,    45,    47,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,    31,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      32,     0,     0,     0,     0,     0,    28,     0,     0,    31,
      25,    47,    46,     0,     0,     7,     0,     0,     8,     0,
       9,    56,    50,    51,    52,    53,    54,    48,    13,    49,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,    17,    16,
      15,    18,     0,     0,     0,     0,    26,    33,    40,    41,
       4,    19,    34,    35,    36,    37,    38,    39,    21,     0,
      29,     0,     0,     0,    48,    49,     0,    11,    12,     0,
       0,     0,     0,    23,     0,     0,    10,    14,     6,    20,
       0,    30,    24,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,    68,   -89,   -28,    89,   123,   -24,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     4,   111,    22,    94,    49,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    55,   118,    30,    54,     5,     6,     7,    32,     9,
      33,    68,    82,    83,    69,    31,    39,    40,    82,    83,
      47,    48,    50,    58,     3,    23,    59,    81,    84,    27,
      63,    92,   133,    20,    91,    79,    80,    72,    73,    74,
      75,    76,   139,    28,    21,    24,   142,    25,    26,    82,
      83,   143,    98,    58,    96,    50,    59,    29,   108,   109,
     119,    65,    66,   103,    67,   104,    41,    42,    43,    44,
      45,    41,    42,    43,    44,    45,   107,   121,   122,    71,
      34,   112,   113,   114,   115,   116,   117,    43,    44,    45,
      35,   132,   125,    80,    36,     5,     6,     7,     8,     9,
      10,   129,    11,    12,    13,    14,    15,    16,   135,   122,
      17,    18,    19,    37,    38,    23,    56,    41,    42,    43,
      44,    45,    57,    20,    64,    95,    23,    77,    70,   138,
      93,    99,   101,   102,    21,     5,     6,     7,     8,     9,
      10,   105,    11,    12,    13,    14,    15,    16,   106,   110,
      17,    18,    19,     5,     6,     7,    32,     9,     5,     6,
       7,    61,    62,    20,   120,    41,    42,    43,    44,    45,
      82,   126,   131,   141,    21,   124,   136,   134,   130,    51,
     140,    20,    97,     0,   123,     0,    20,    41,    42,    43,
      44,    45,    21,     0,     0,    46,     0,    21,    85,    86,
      87,    88,    89,    90,     0,     0,     0,    41,    42,    43,
      44,    45,    41,    42,    43,    44,    45,     0,     0,     0,
      60,    41,    42,    43,    44,    45,     0,     0,     0,    78,
      41,    42,    43,    44,    45,     0,     0,     0,   100,    41,
      42,    43,    44,    45,     0,     0,     0,   127,    41,    42,
      43,    44,    45,     0,     0,     0,   128,    41,    42,    43,
      44,    45,     0,     0,     0,   137
};

static const yytype_int16 yycheck[] =
{
       4,    29,    91,     6,    28,     3,     4,     5,     6,     7,
      14,    38,    27,    28,    41,    18,    20,    21,    27,    28,
      24,    25,    26,    39,     0,    29,    42,    51,    43,    42,
      34,    55,   121,    31,    43,    43,    44,    41,    42,    43,
      44,    45,   131,    42,    42,    39,   135,    41,    42,    27,
      28,   140,    38,    39,    58,    59,    42,    42,    82,    83,
      38,    38,    39,    67,    41,    69,    30,    31,    32,    33,
      34,    30,    31,    32,    33,    34,    80,    43,    44,    43,
      16,    85,    86,    87,    88,    89,    90,    32,    33,    34,
      17,   119,    43,    44,     6,     3,     4,     5,     6,     7,
       8,   105,    10,    11,    12,    13,    14,    15,    43,    44,
      18,    19,    20,     6,     6,   119,    42,    30,    31,    32,
      33,    34,     6,    31,     6,    42,   130,    40,    38,    37,
      18,    38,    38,     3,    42,     3,     4,     5,     6,     7,
       8,    41,    10,    11,    12,    13,    14,    15,    38,    36,
      18,    19,    20,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    31,     6,    30,    31,    32,    33,    34,
      27,    40,     9,     6,    42,    40,    38,    18,   110,    29,
      43,    31,    59,    -1,    95,    -1,    31,    30,    31,    32,
      33,    34,    42,    -1,    -1,    38,    -1,    42,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,     0,    48,     3,     4,     5,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    18,    19,    20,
      31,    42,    50,    54,    39,    41,    42,    42,    42,    42,
       6,    18,     6,    54,    16,    17,     6,     6,     6,    54,
      54,    30,    31,    32,    33,    34,    38,    54,    54,    52,
      54,    29,    53,    54,    53,    50,    42,     6,    39,    42,
      38,     6,     7,    54,     6,    38,    39,    41,    38,    41,
      38,    43,    54,    54,    54,    54,    54,    40,    38,    43,
      44,    53,    27,    28,    43,    21,    22,    23,    24,    25,
      26,    43,    53,    18,    51,    42,    54,    52,    38,    38,
      38,    38,     3,    54,    54,    41,    38,    54,    53,    53,
      36,    49,    54,    54,    54,    54,    54,    54,    49,    38,
       6,    43,    44,    51,    40,    43,    40,    38,    38,    54,
      48,     9,    50,    49,    18,    43,    38,    38,    37,    49,
      43,     6,    49,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    52,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     3,     3,     3,     3,
       6,     5,     5,     4,     7,     4,     4,     4,     4,     5,
       7,     5,     8,     6,     7,     3,     5,     2,     0,     2,
       4,     0,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     4,     4,
       3,     3,     3,     3,     3,     2,     3
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
#line 59 "calc.y"
    { entrar_alcance("global"); }
#line 1249 "calc.tab.c"
    break;

  case 3: /* programa: $@1 instrucciones  */
#line 61 "calc.y"
    { }
#line 1255 "calc.tab.c"
    break;

  case 5: /* instrucciones: instrucciones instruccion  */
#line 66 "calc.y"
        {
            if ((yyvsp[0].nodo)) {
                std::cout << "\n\033[1;33m--- AST ---\033[0m\n";
                imprimirAST((yyvsp[0].nodo));
                std::cout << "\n\033[1;36m--- CST ---\033[0m\n";
                imprimirCST((yyvsp[0].nodo));
                std::ofstream fa("ast_salida.txt", std::ios::app);
                guardarAST((yyvsp[0].nodo), fa); fa << "\n";
                std::ofstream fc("cst_salida.txt", std::ios::app);
                guardarCST((yyvsp[0].nodo), fc); fc << "\n";
            }
        }
#line 1272 "calc.tab.c"
    break;

  case 6: /* bloque: '{' instrucciones '}'  */
#line 81 "calc.y"
                           { }
#line 1278 "calc.tab.c"
    break;

  case 7: /* instruccion: TENTERO ID ';'  */
#line 87 "calc.y"
        {
            declarar_var((yyvsp[-1].str), TIPO_ENTERO);
            emitir("DECL", "entero", "", (yyvsp[-1].str));
            (yyval.nodo) = new Nodo("declaracion entero: " + std::string((yyvsp[-1].str)),
                          nullptr, nullptr, new Nodo("token: ';'"));
        }
#line 1289 "calc.tab.c"
    break;

  case 8: /* instruccion: TDECIMAL ID ';'  */
#line 94 "calc.y"
        {
            declarar_var((yyvsp[-1].str), TIPO_DECIMAL);
            emitir("DECL", "decimal", "", (yyvsp[-1].str));
            (yyval.nodo) = new Nodo("declaracion decimal: " + std::string((yyvsp[-1].str)),
                          nullptr, nullptr, new Nodo("token: ';'"));
        }
#line 1300 "calc.tab.c"
    break;

  case 9: /* instruccion: TTEXTO ID ';'  */
#line 101 "calc.y"
        {
            declarar_var((yyvsp[-1].str), TIPO_TEXTO);
            emitir("DECL", "texto", "", (yyvsp[-1].str));
            (yyval.nodo) = new Nodo("declaracion texto: " + std::string((yyvsp[-1].str)),
                          nullptr, nullptr, new Nodo("token: ';'"));
        }
#line 1311 "calc.tab.c"
    break;

  case 10: /* instruccion: TENTERO ID '[' NUM ']' ';'  */
#line 108 "calc.y"
        {
            declarar_var((yyvsp[-4].str), TIPO_ENTERO, true, (int)(yyvsp[-2].num));
            char buf[64]; snprintf(buf,63,"%d",(int)(yyvsp[-2].num));
            emitir("DECL_ARRAY", "entero", buf, (yyvsp[-4].str));
            (yyval.nodo) = new Nodo("declaracion arreglo entero: " + std::string((yyvsp[-4].str)) +
                          "[" + std::to_string((int)(yyvsp[-2].num)) + "]");
        }
#line 1323 "calc.tab.c"
    break;

  case 11: /* instruccion: TENTERO ID '=' expr ';'  */
#line 116 "calc.y"
        {
            declarar_var((yyvsp[-3].str), TIPO_ENTERO);
            asignar_var((yyvsp[-3].str), atof((yyvsp[-1].nodo)->etiqueta.c_str()));
            emitir("=", (yyvsp[-1].nodo)->etiqueta, "", (yyvsp[-3].str));
            (yyval.nodo) = new Nodo("decl+asig: " + std::string((yyvsp[-3].str)),
                          new Nodo("variable: " + std::string((yyvsp[-3].str))), (yyvsp[-1].nodo),
                          new Nodo("token: '='"));
        }
#line 1336 "calc.tab.c"
    break;

  case 12: /* instruccion: TDECIMAL ID '=' expr ';'  */
#line 125 "calc.y"
        {
            declarar_var((yyvsp[-3].str), TIPO_DECIMAL);
            asignar_var((yyvsp[-3].str), atof((yyvsp[-1].nodo)->etiqueta.c_str()));
            emitir("=", (yyvsp[-1].nodo)->etiqueta, "", (yyvsp[-3].str));
            (yyval.nodo) = new Nodo("decl+asig: " + std::string((yyvsp[-3].str)),
                          new Nodo("variable: " + std::string((yyvsp[-3].str))), (yyvsp[-1].nodo),
                          new Nodo("token: '='"));
        }
#line 1349 "calc.tab.c"
    break;

  case 13: /* instruccion: ID '=' expr ';'  */
#line 134 "calc.y"
        {
            asignar_var((yyvsp[-3].str), atof((yyvsp[-1].nodo)->etiqueta.c_str()));
            printf("  %s = %.6g\n", (yyvsp[-3].str), atof((yyvsp[-1].nodo)->etiqueta.c_str()));
            emitir("=", (yyvsp[-1].nodo)->etiqueta, "", (yyvsp[-3].str));
            (yyval.nodo) = new Nodo("asignacion: " + std::string((yyvsp[-3].str)) + " =",
                          new Nodo("variable: " + std::string((yyvsp[-3].str))), (yyvsp[-1].nodo),
                          new Nodo("token: '='"));
        }
#line 1362 "calc.tab.c"
    break;

  case 14: /* instruccion: ID '[' expr ']' '=' expr ';'  */
#line 143 "calc.y"
        {
            std::string etiq = std::string((yyvsp[-6].str)) + "[" + (yyvsp[-4].nodo)->etiqueta + "]";
            emitir("ARRAY_SET", (yyvsp[-1].nodo)->etiqueta, (yyvsp[-4].nodo)->etiqueta, (yyvsp[-6].str));
            (yyval.nodo) = new Nodo("asignacion arreglo: " + etiq,
                          (yyvsp[-4].nodo), (yyvsp[-1].nodo), nullptr);
        }
#line 1373 "calc.tab.c"
    break;

  case 15: /* instruccion: MOSTRAR SALIDA expr ';'  */
#line 150 "calc.y"
        {
            printf("%.6g\n", atof((yyvsp[-1].nodo)->etiqueta.c_str()));
            emitir("PRINT", (yyvsp[-1].nodo)->etiqueta, "", "");
            (yyval.nodo) = new Nodo("mostrar <<", (yyvsp[-1].nodo), nullptr, new Nodo("token: '<<'"));
        }
#line 1383 "calc.tab.c"
    break;

  case 16: /* instruccion: MOSTRAR SALIDA TEXTO_VAL ';'  */
#line 156 "calc.y"
        {
            char *s = (yyvsp[-1].str); if (s[0]=='"') s++;
            char buf[256]; strncpy(buf,s,255);
            int len=strlen(buf);
            if(buf[len-1]=='"') buf[len-1]='\0';
            printf("%s\n", buf);
            emitir("PRINT", "\""+std::string(buf)+"\"", "", "");
            (yyval.nodo) = new Nodo("mostrar << \"" + std::string(buf) + "\"");
        }
#line 1397 "calc.tab.c"
    break;

  case 17: /* instruccion: MOSTRAR SALIDA ID ';'  */
#line 166 "calc.y"
        {
            printf("%.6g\n", obtener_var((yyvsp[-1].str)));
            emitir("PRINT", (yyvsp[-1].str), "", "");
            (yyval.nodo) = new Nodo("mostrar << var(" + std::string((yyvsp[-1].str)) + ")");
        }
#line 1407 "calc.tab.c"
    break;

  case 18: /* instruccion: DATOINGRESADO ENTRADA ID ';'  */
#line 172 "calc.y"
        {
            if (!existe_var((yyvsp[-1].str)))
                std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                          << ": variable '" << (yyvsp[-1].str) << "' no declarada.\033[0m\n\n";
            double val;
            printf("Ingresa valor para %s: ", (yyvsp[-1].str));
            fflush(stdout);
            fscanf(stdin, "%lf", &val);
            asignar_var((yyvsp[-1].str), val);
            emitir("READ", "", "", (yyvsp[-1].str));
            (yyval.nodo) = new Nodo("datoingresado >> " + std::string((yyvsp[-1].str)));
        }
#line 1424 "calc.tab.c"
    break;

  case 19: /* instruccion: SI '(' cond ')' bloque  */
#line 185 "calc.y"
        {
            std::string Lfalso = nuevo_label();
            std::string Lfin   = nuevo_label();
            emitir("IF_FALSE", (yyvsp[-2].nodo)->etiqueta, "", Lfalso);
            emitir("LABEL",    "", "", Lfalso);
            emitir("LABEL",    "", "", Lfin);
            (yyval.nodo) = new Nodo("si ( condicion )", (yyvsp[-2].nodo), nullptr);
        }
#line 1437 "calc.tab.c"
    break;

  case 20: /* instruccion: SI '(' cond ')' bloque SINO bloque  */
#line 194 "calc.y"
        {
            std::string Lfalso = nuevo_label();
            std::string Lfin   = nuevo_label();
            emitir("IF_FALSE", (yyvsp[-4].nodo)->etiqueta, "", Lfalso);
            emitir("GOTO",     "", "", Lfin);
            emitir("LABEL",    "", "", Lfalso);
            emitir("LABEL",    "", "", Lfin);
            (yyval.nodo) = new Nodo("si-sino", (yyvsp[-4].nodo), nullptr);
        }
#line 1451 "calc.tab.c"
    break;

  case 21: /* instruccion: MIENTRAS '(' cond ')' bloque  */
#line 204 "calc.y"
        {
            std::string Linicio = nuevo_label();
            std::string Lfin    = nuevo_label();
            emitir("LABEL",    "", "", Linicio);
            emitir("IF_FALSE", (yyvsp[-2].nodo)->etiqueta, "", Lfin);
            emitir("GOTO",     "", "", Linicio);
            emitir("LABEL",    "", "", Lfin);
            (yyval.nodo) = new Nodo("mientras ( condicion )", (yyvsp[-2].nodo), nullptr);
        }
#line 1465 "calc.tab.c"
    break;

  case 22: /* instruccion: PARA '(' instruccion cond ';' instruccion ')' bloque  */
#line 214 "calc.y"
        {
            std::string Linicio = nuevo_label();
            std::string Lfin    = nuevo_label();
            emitir("LABEL",    "", "", Linicio);
            emitir("IF_FALSE", (yyvsp[-4].nodo)->etiqueta, "", Lfin);
            emitir("GOTO",     "", "", Linicio);
            emitir("LABEL",    "", "", Lfin);
            (yyval.nodo) = new Nodo("para ( init ; cond ; paso )", (yyvsp[-5].nodo), (yyvsp[-4].nodo));
        }
#line 1479 "calc.tab.c"
    break;

  case 23: /* instruccion: FUNCION ID '(' params_lista ')' bloque  */
#line 224 "calc.y"
        {
            declarar_funcion((yyvsp[-4].str), TIPO_VOID, {});
            salir_alcance();
            emitir("LABEL", "", "", std::string((yyvsp[-4].str)) + "_inicio");
            emitir("RETURN","0","","");
            (yyval.nodo) = new Nodo("funcion: " + std::string((yyvsp[-4].str)), (yyvsp[-2].nodo), nullptr);
        }
#line 1491 "calc.tab.c"
    break;

  case 24: /* instruccion: FUNCION TENTERO ID '(' params_lista ')' bloque  */
#line 232 "calc.y"
        {
            declarar_funcion((yyvsp[-4].str), TIPO_ENTERO, {});
            salir_alcance();
            emitir("LABEL", "", "", std::string((yyvsp[-4].str)) + "_inicio");
            (yyval.nodo) = new Nodo("funcion entero: " + std::string((yyvsp[-4].str)), (yyvsp[-2].nodo), nullptr);
        }
#line 1502 "calc.tab.c"
    break;

  case 25: /* instruccion: RETORNAR expr ';'  */
#line 239 "calc.y"
        {
            emitir("RETURN", (yyvsp[-1].nodo)->etiqueta, "", "");
            (yyval.nodo) = new Nodo("retornar", (yyvsp[-1].nodo));
        }
#line 1511 "calc.tab.c"
    break;

  case 26: /* instruccion: ID '(' args_lista ')' ';'  */
#line 244 "calc.y"
        {
            if (!existe_funcion((yyvsp[-4].str)))
                std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                          << ": funcion '" << (yyvsp[-4].str) << "' no declarada.\033[0m\n\n";
            std::string tmp = nuevo_temp();
            emitir("CALL", (yyvsp[-4].str), "0", tmp);
            (yyval.nodo) = new Nodo("llamada funcion: " + std::string((yyvsp[-4].str)), (yyvsp[-2].nodo));
        }
#line 1524 "calc.tab.c"
    break;

  case 27: /* instruccion: expr ';'  */
#line 253 "calc.y"
        {
            printf("= %s\n", (yyvsp[-1].nodo)->etiqueta.c_str());
            emitir("EXPR", (yyvsp[-1].nodo)->etiqueta, "", nuevo_temp());
            (yyval.nodo) = new Nodo("expresion", (yyvsp[-1].nodo), nullptr, new Nodo("token: ';'"));
        }
#line 1534 "calc.tab.c"
    break;

  case 28: /* params_lista: %empty  */
#line 260 "calc.y"
    { (yyval.nodo) = new Nodo("params: vacio"); }
#line 1540 "calc.tab.c"
    break;

  case 29: /* params_lista: TENTERO ID  */
#line 262 "calc.y"
        {
            entrar_alcance("funcion");
            declarar_var((yyvsp[0].str), TIPO_ENTERO);
            (yyval.nodo) = new Nodo("param entero: " + std::string((yyvsp[0].str)));
        }
#line 1550 "calc.tab.c"
    break;

  case 30: /* params_lista: params_lista ',' TENTERO ID  */
#line 268 "calc.y"
        {
            declarar_var((yyvsp[0].str), TIPO_ENTERO);
            (yyval.nodo) = new Nodo("params", (yyvsp[-3].nodo),
                          new Nodo("param entero: " + std::string((yyvsp[0].str))));
        }
#line 1560 "calc.tab.c"
    break;

  case 31: /* args_lista: %empty  */
#line 276 "calc.y"
    { (yyval.nodo) = new Nodo("args: vacio"); }
#line 1566 "calc.tab.c"
    break;

  case 32: /* args_lista: expr  */
#line 278 "calc.y"
        {
            emitir("PARAM", (yyvsp[0].nodo)->etiqueta, "", "");
            (yyval.nodo) = new Nodo("arg", (yyvsp[0].nodo));
        }
#line 1575 "calc.tab.c"
    break;

  case 33: /* args_lista: args_lista ',' expr  */
#line 283 "calc.y"
        {
            emitir("PARAM", (yyvsp[0].nodo)->etiqueta, "", "");
            (yyval.nodo) = new Nodo("args", (yyvsp[-2].nodo), (yyvsp[0].nodo));
        }
#line 1584 "calc.tab.c"
    break;

  case 34: /* cond: expr LE expr  */
#line 290 "calc.y"
                  { (yyval.nodo) = new Nodo("condicion: <=", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1590 "calc.tab.c"
    break;

  case 35: /* cond: expr GE expr  */
#line 291 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: >=", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1596 "calc.tab.c"
    break;

  case 36: /* cond: expr EQ expr  */
#line 292 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: ==", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1602 "calc.tab.c"
    break;

  case 37: /* cond: expr NE expr  */
#line 293 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: !=", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1608 "calc.tab.c"
    break;

  case 38: /* cond: expr LT expr  */
#line 294 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: <",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1614 "calc.tab.c"
    break;

  case 39: /* cond: expr GT expr  */
#line 295 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: >",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1620 "calc.tab.c"
    break;

  case 40: /* cond: cond AND cond  */
#line 296 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: &&", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1626 "calc.tab.c"
    break;

  case 41: /* cond: cond OR cond  */
#line 297 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: ||", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1632 "calc.tab.c"
    break;

  case 42: /* cond: NOT cond  */
#line 298 "calc.y"
                    { (yyval.nodo) = new Nodo("condicion: !",  (yyvsp[0].nodo), nullptr); }
#line 1638 "calc.tab.c"
    break;

  case 43: /* expr: NUM  */
#line 303 "calc.y"
        {
            char buf[64]; snprintf(buf,63,"%g",(yyvsp[0].num));
            (yyval.nodo) = new Nodo(std::string(buf));
        }
#line 1647 "calc.tab.c"
    break;

  case 44: /* expr: VERDADERO  */
#line 307 "calc.y"
                  { (yyval.nodo) = new Nodo("verdadero"); }
#line 1653 "calc.tab.c"
    break;

  case 45: /* expr: FALSO  */
#line 308 "calc.y"
                  { (yyval.nodo) = new Nodo("falso"); }
#line 1659 "calc.tab.c"
    break;

  case 46: /* expr: TEXTO_VAL  */
#line 309 "calc.y"
                  { (yyval.nodo) = new Nodo(std::string((yyvsp[0].str))); }
#line 1665 "calc.tab.c"
    break;

  case 47: /* expr: ID  */
#line 311 "calc.y"
        {
            double v = obtener_var((yyvsp[0].str));
            char buf[64]; snprintf(buf,63,"var(%s)=%g",(yyvsp[0].str),v);
            (yyval.nodo) = new Nodo(std::string(buf));
        }
#line 1675 "calc.tab.c"
    break;

  case 48: /* expr: ID '[' expr ']'  */
#line 317 "calc.y"
        {
            std::string etiq = std::string((yyvsp[-3].str)) + "[" + (yyvsp[-1].nodo)->etiqueta + "]";
            (yyval.nodo) = new Nodo("acceso arreglo: " + etiq, (yyvsp[-1].nodo));
        }
#line 1684 "calc.tab.c"
    break;

  case 49: /* expr: ID '(' args_lista ')'  */
#line 322 "calc.y"
        {
            if (!existe_funcion((yyvsp[-3].str)))
                std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                          << ": funcion '" << (yyvsp[-3].str) << "' no declarada.\033[0m\n\n";
            std::string tmp = nuevo_temp();
            emitir("CALL", (yyvsp[-3].str), "0", tmp);
            (yyval.nodo) = new Nodo("llamada: " + std::string((yyvsp[-3].str)) + "()", (yyvsp[-1].nodo));
        }
#line 1697 "calc.tab.c"
    break;

  case 50: /* expr: expr '+' expr  */
#line 331 "calc.y"
        {
            std::string tmp = nuevo_temp();
            emitir("+", (yyvsp[-2].nodo)->etiqueta, (yyvsp[0].nodo)->etiqueta, tmp);
            (yyval.nodo) = new Nodo("expr: +", (yyvsp[-2].nodo), (yyvsp[0].nodo), new Nodo("token: '+'"));
        }
#line 1707 "calc.tab.c"
    break;

  case 51: /* expr: expr '-' expr  */
#line 337 "calc.y"
        {
            std::string tmp = nuevo_temp();
            emitir("-", (yyvsp[-2].nodo)->etiqueta, (yyvsp[0].nodo)->etiqueta, tmp);
            (yyval.nodo) = new Nodo("expr: -", (yyvsp[-2].nodo), (yyvsp[0].nodo), new Nodo("token: '-'"));
        }
#line 1717 "calc.tab.c"
    break;

  case 52: /* expr: expr '*' expr  */
#line 343 "calc.y"
        {
            std::string tmp = nuevo_temp();
            emitir("*", (yyvsp[-2].nodo)->etiqueta, (yyvsp[0].nodo)->etiqueta, tmp);
            (yyval.nodo) = new Nodo("expr: *", (yyvsp[-2].nodo), (yyvsp[0].nodo), new Nodo("token: '*'"));
        }
#line 1727 "calc.tab.c"
    break;

  case 53: /* expr: expr '/' expr  */
#line 349 "calc.y"
    {
        bool div_cero = false;
        std::string etiq_der = (yyvsp[0].nodo)->etiqueta;

        if (etiq_der == "0" || etiq_der == "0.0") {
            div_cero = true;
        }
        else if (etiq_der.find("var(") == 0) {
            size_t pos_igual = etiq_der.find("=");
            if (pos_igual != std::string::npos) {
                std::string val_str = etiq_der.substr(pos_igual + 1);
                if (val_str == "0" || val_str == "0.0" || atof(val_str.c_str()) == 0.0) {
                    div_cero = true;
                }
            }
        }

        if (div_cero) {
            std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                      << ": division por cero detectada.\033[0m\n"
                      << "  Causa: el divisor vale 0. Operacion invalida.\n"
                      << "  Tipo: ERROR SEMANTICO (el codigo es sintacticamente correcto\n"
                      << "        pero tiene un significado invalido en tiempo de ejecucion)\n\n";
            total_errores_logicos++;
        }

        std::string tmp = nuevo_temp();
        emitir("/", (yyvsp[-2].nodo)->etiqueta, (yyvsp[0].nodo)->etiqueta, tmp);
        (yyval.nodo) = new Nodo("expr: /", (yyvsp[-2].nodo), (yyvsp[0].nodo), new Nodo("token: '/'"));
    }
#line 1762 "calc.tab.c"
    break;

  case 54: /* expr: expr '%' expr  */
#line 380 "calc.y"
        {
            std::string tmp = nuevo_temp();
            emitir("%", (yyvsp[-2].nodo)->etiqueta, (yyvsp[0].nodo)->etiqueta, tmp);
            (yyval.nodo) = new Nodo("expr: %", (yyvsp[-2].nodo), (yyvsp[0].nodo), new Nodo("token: '%'"));
        }
#line 1772 "calc.tab.c"
    break;

  case 55: /* expr: '-' expr  */
#line 386 "calc.y"
        {
            std::string tmp = nuevo_temp();
            emitir("NEG", (yyvsp[0].nodo)->etiqueta, "", tmp);
            (yyval.nodo) = new Nodo("negativo", (yyvsp[0].nodo));
        }
#line 1782 "calc.tab.c"
    break;

  case 56: /* expr: '(' expr ')'  */
#line 392 "calc.y"
        {
            (yyval.nodo) = new Nodo("agrupacion",
                          new Nodo("token: '('"), (yyvsp[-1].nodo),
                          new Nodo("token: ')'"));
        }
#line 1792 "calc.tab.c"
    break;


#line 1796 "calc.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 399 "calc.y"


int main() {
    std::cout << "=== COMPILADOR v2 — Con bucles, funciones y semantica ===\n";
    std::cout << "Escribe tu codigo y presiona Ctrl+D al finalizar:\n\n";
    yyparse();
    imprimir_tabla_simbolos();
    imprimir_intermedio();
    guardar_intermedio();
    std::cout << "\033[1;33m  RESUMEN DE ERRORES\033[0m\n";
    std::cout << "\033[1;33m----------------------------\033[0m\n";
    if (!total_errores_lexicos && !total_errores_sintacticos && !total_errores_logicos)
        std::cout << "\033[1;32m  Sin errores. Codigo valido.\033[0m\n\n";
    else {
        if (total_errores_lexicos)
            std::cout << "\033[1;31m  Errores lexicos:     " << total_errores_lexicos     << "\033[0m\n";
        if (total_errores_sintacticos)
            std::cout << "\033[1;31m  Errores sintacticos: " << total_errores_sintacticos << "\033[0m\n";
        if (total_errores_logicos)
            std::cout << "\033[1;31m  Errores logicos:     " << total_errores_logicos     << "\033[0m\n";
        std::cout << "\n";
    }
    return 0;
}
