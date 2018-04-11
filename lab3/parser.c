/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

/***********************************************************************
 * --YOUR GROUP INFO SHOULD GO HERE--
 * 
 *   Interface to the parser module for CSC467 course project.
 * 
 *   Phase 2: Implement context free grammar for source language, and
 *            parse tracing functionality.
 *   Phase 3: Construct the AST for the source language program.
 ***********************************************************************/

/***********************************************************************
 *  C Definitions and external declarations for this module.
 *
 *  Phase 3: Include ast.h if needed, and declarations for other global or
 *           external vars, functions etc. as needed.
 ***********************************************************************/

#include <string.h>

#include "common.h"
#include "ast.h"
#include "symbol.h"
#include "semantic.h"

#define YYERROR_VERBOSE
#define yTRACE(x)    { if (traceParser) fprintf(traceFile, "%s\n", x); }

void yyerror(const char* s);    /* what to do in case of error            */
int yylex();              /* procedure for calling lexical analyzer */
extern int yyline;        /* variable holding current line number   */

enum {
  DP3 = 0, 
  LIT = 1, 
  RSQ = 2
};

#line 57 "parser.y" /* yacc.c:339  */

#define YYDEBUG 1

#line 109 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FLOAT_T = 258,
    INT_T = 259,
    BOOL_T = 260,
    CONST = 261,
    FALSE_C = 262,
    TRUE_C = 263,
    IF = 264,
    ELSE = 265,
    AND = 266,
    OR = 267,
    NEQ = 268,
    EQ = 269,
    LEQ = 270,
    GEQ = 271,
    FUNC = 272,
    VEC_T = 273,
    BVEC_T = 274,
    IVEC_T = 275,
    FLOAT_C = 276,
    INT_C = 277,
    ID = 278,
    UMINUS = 279,
    WITHOUT_ELSE = 280,
    WITH_ELSE = 281
  };
#endif
/* Tokens.  */
#define FLOAT_T 258
#define INT_T 259
#define BOOL_T 260
#define CONST 261
#define FALSE_C 262
#define TRUE_C 263
#define IF 264
#define ELSE 265
#define AND 266
#define OR 267
#define NEQ 268
#define EQ 269
#define LEQ 270
#define GEQ 271
#define FUNC 272
#define VEC_T 273
#define BVEC_T 274
#define IVEC_T 275
#define FLOAT_C 276
#define INT_C 277
#define ID 278
#define UMINUS 279
#define WITHOUT_ELSE 280
#define WITH_ELSE 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 62 "parser.y" /* yacc.c:355  */

  int as_int;
  int as_vec;
  float as_float;
  char *as_str;
  int as_func;
  node *as_ast;

#line 210 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,     2,     2,
      33,    41,    28,    26,    43,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      24,    40,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    42,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    32,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   138,   145,   150,   156,   161,   167,   171,
     175,   182,   186,   190,   194,   198,   205,   209,   213,   217,
     221,   225,   234,   238,   244,   248,   254,   258,   262,   266,
     270,   274,   278,   282,   286,   290,   294,   298,   302,   308,
     312,   316,   320,   326,   330,   330,   337,   341,   348,   352,
     359,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT_T", "INT_T", "BOOL_T", "CONST",
  "FALSE_C", "TRUE_C", "IF", "ELSE", "AND", "OR", "NEQ", "EQ", "LEQ",
  "GEQ", "FUNC", "VEC_T", "BVEC_T", "IVEC_T", "FLOAT_C", "INT_C", "ID",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'^'", "'!'", "UMINUS", "'('",
  "'['", "WITHOUT_ELSE", "WITH_ELSE", "'{'", "'}'", "';'", "'='", "')'",
  "']'", "','", "$accept", "program", "scope", "declarations",
  "statements", "declaration", "statement", "type", "expression", "$@1",
  "variable", "arguments", "arguments_opt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    60,    62,    43,    45,    42,    47,
      94,    33,   279,    40,    91,   280,   281,   123,   125,    59,
      61,    41,    93,    44
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   -51,     4,   -51,   195,   -51,   -51,   -51,   -51,   199,
     -51,   -51,   -51,    40,   -51,    27,    28,   -16,    32,   -51,
     -51,   -51,   -51,    21,   -14,    22,    37,    47,    37,   -51,
      37,    37,   -51,   -51,    49,   -51,   -51,    37,    37,    37,
      64,    60,   -51,    56,   100,   120,   140,    37,   -51,   -51,
      80,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    44,   -51,   -51,   -51,   -51,
     -51,   160,    57,    58,   -51,    61,    -6,   167,   179,   179,
     179,   179,   179,   179,    18,    18,    73,    73,    73,   107,
      37,   -51,   -51,    44,   160,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,     7,     1,    20,    16,    18,     0,
      21,    19,    17,     0,     4,     0,     0,     0,    46,     3,
      15,    14,     6,     0,     0,     0,     0,     0,     0,     8,
       0,     0,    40,    39,     0,    42,    41,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,    51,    24,    25,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    47,    11,     9,
      10,    49,    50,     0,    43,     0,    26,    27,    29,    28,
      31,    33,    30,    32,    34,    35,    36,    37,    38,    13,
       0,    23,    22,     0,    48,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   118,   -51,   -51,   -51,   -50,     7,   -25,   -51,
     -13,   -51,    68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    21,     4,    13,    14,    22,    40,    71,    66,
      42,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    41,     1,    44,     5,    45,    46,    54,    55,    56,
      57,    15,    48,    49,    50,    89,    16,    26,    58,    59,
      60,    61,    62,    63,    64,    29,    30,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       6,     7,     8,    95,    32,    33,    62,    63,    64,    17,
      24,    25,    23,    17,    34,    10,    11,    12,    35,    36,
      18,    28,    31,    18,    37,    94,    27,    18,    38,    43,
      39,    52,    53,    54,    55,    56,    57,     1,    19,    20,
      23,     1,    47,    20,    58,    59,    60,    61,    62,    63,
      64,    52,    53,    54,    55,    56,    57,    51,    67,    91,
      90,    65,    92,    64,    58,    59,    60,    61,    62,    63,
      64,    52,    53,    54,    55,    56,    57,    93,     3,    75,
       0,    74,     0,     0,    58,    59,    60,    61,    62,    63,
      64,    52,    53,    54,    55,    56,    57,     0,     0,    68,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,    52,    53,    54,    55,    56,    57,     0,     0,    69,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,    52,    53,    54,    55,    56,    57,     0,    52,    70,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    58,    59,    60,    61,    62,    63,    64,     6,     7,
       8,     9,     6,     7,     8,    60,    61,    62,    63,    64,
       0,     0,     0,    10,    11,    12,     0,    10,    11,    12
};

static const yytype_int8 yycheck[] =
{
      13,    26,    37,    28,     0,    30,    31,    13,    14,    15,
      16,     4,    37,    38,    39,    65,     9,    33,    24,    25,
      26,    27,    28,    29,    30,    39,    40,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       3,     4,     5,    93,     7,     8,    28,    29,    30,     9,
      23,    23,    65,     9,    17,    18,    19,    20,    21,    22,
      23,    40,    40,    23,    27,    90,    34,    23,    31,    22,
      33,    11,    12,    13,    14,    15,    16,    37,    38,    39,
      93,    37,    33,    39,    24,    25,    26,    27,    28,    29,
      30,    11,    12,    13,    14,    15,    16,    33,    42,    41,
      43,    41,    41,    30,    24,    25,    26,    27,    28,    29,
      30,    11,    12,    13,    14,    15,    16,    10,     0,    51,
      -1,    41,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    11,    12,    13,    14,    15,    16,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    11,    12,    13,    14,    15,    16,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    11,    12,    13,    14,    15,    16,    -1,    11,    39,
      13,    14,    15,    16,    24,    25,    26,    27,    28,    29,
      30,    24,    25,    26,    27,    28,    29,    30,     3,     4,
       5,     6,     3,     4,     5,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    18,    19,    20,    -1,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    45,    46,    47,     0,     3,     4,     5,     6,
      18,    19,    20,    48,    49,    51,    51,     9,    23,    38,
      39,    46,    50,    54,    23,    23,    33,    34,    40,    39,
      40,    40,     7,     8,    17,    21,    22,    27,    31,    33,
      51,    52,    54,    22,    52,    52,    52,    33,    52,    52,
      52,    33,    11,    12,    13,    14,    15,    16,    24,    25,
      26,    27,    28,    29,    30,    41,    53,    42,    39,    39,
      39,    52,    55,    56,    41,    56,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    50,
      43,    41,    41,    10,    52,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    52,    54,    54,    55,    55,
      56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     0,     2,     0,     3,     5,
       6,     4,     7,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     3,     0,     2,     1,     4,     3,     1,
       1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 132 "parser.y" /* yacc.c:1646  */
    { yTRACE("program -> scope\n")
        ast = (yyvsp[0].as_ast); 
      }
#line 1393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "parser.y" /* yacc.c:1646  */
    { yTRACE("scope -> { declarations statements }\n") 
        (yyval.as_ast) = ast_allocate(SCOPE_NODE, (yyvsp[-2].as_ast), (yyvsp[-1].as_ast));
      }
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 146 "parser.y" /* yacc.c:1646  */
    { yTRACE("declarations -> declarations declaration\n") 
      	(yyval.as_ast) = ast_allocate(DECLARATIONS_NODE, (yyvsp[-1].as_ast), (yyvsp[0].as_ast));
      }
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 150 "parser.y" /* yacc.c:1646  */
    { yTRACE("declarations -> \n") 
      	(yyval.as_ast) = NULL;
      }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "parser.y" /* yacc.c:1646  */
    { yTRACE("statements -> statements statement\n") 
      	(yyval.as_ast) = ast_allocate(STATEMENT_NODE, (yyvsp[-1].as_ast), (yyvsp[0].as_ast));
      }
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 161 "parser.y" /* yacc.c:1646  */
    { yTRACE("statements -> \n") 
      	(yyval.as_ast) = NULL;
      }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "parser.y" /* yacc.c:1646  */
    { yTRACE("declaration -> type ID ;\n") 
      	(yyval.as_ast) = ast_allocate(DECLARATION_NODE, 0, (yyvsp[-2].as_ast), (yyvsp[-1].as_str), NULL);
      }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "parser.y" /* yacc.c:1646  */
    { yTRACE("declaration -> type ID = expression ;\n") 
      	(yyval.as_ast) = ast_allocate(DECLARATION_NODE, 0, (yyvsp[-4].as_ast), (yyvsp[-3].as_str), (yyvsp[-1].as_ast));
      }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "parser.y" /* yacc.c:1646  */
    { yTRACE("declaration -> CONST type ID = expression ;\n") 
      	(yyval.as_ast) = ast_allocate(DECLARATION_NODE, 1, (yyvsp[-4].as_ast), (yyvsp[-3].as_str), (yyvsp[-1].as_ast));
      }
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "parser.y" /* yacc.c:1646  */
    { yTRACE("statement -> variable = expression ;\n") 
      	(yyval.as_ast) = ast_allocate(ASSIGNMENT_NODE, (yyvsp[-3].as_ast), (yyvsp[-1].as_ast)); 
      }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 187 "parser.y" /* yacc.c:1646  */
    { yTRACE("statement -> IF ( expression ) statement ELSE statement \n") 
      	(yyval.as_ast) = ast_allocate(IF_STATEMENT_NODE, (yyvsp[-4].as_ast), (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 191 "parser.y" /* yacc.c:1646  */
    { yTRACE("statement -> IF ( expression ) statement \n") 
      	(yyval.as_ast) = ast_allocate(IF_STATEMENT_NODE, (yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL);
      }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 195 "parser.y" /* yacc.c:1646  */
    { yTRACE("statement -> scope \n") 
      	(yyval.as_ast) = (yyvsp[0].as_ast);
      }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 199 "parser.y" /* yacc.c:1646  */
    { yTRACE("statement -> ; \n")
		(yyval.as_ast) = NULL; 
	  }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "parser.y" /* yacc.c:1646  */
    { yTRACE("type -> INT_T \n") 
      	(yyval.as_ast) = ast_allocate(TYPE_NODE, INT); 
      }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "parser.y" /* yacc.c:1646  */
    { yTRACE("type -> IVEC_T \n") 
      	(yyval.as_ast) = ast_allocate(TYPE_NODE, IVEC2+(yyvsp[0].as_vec)-1); 
      }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "parser.y" /* yacc.c:1646  */
    { yTRACE("type -> BOOL_T \n") 
      	(yyval.as_ast) = ast_allocate(TYPE_NODE, BOOL); 
      }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 218 "parser.y" /* yacc.c:1646  */
    { yTRACE("type -> BVEC_T \n") 
      	(yyval.as_ast) = ast_allocate(TYPE_NODE, BVEC2+(yyvsp[0].as_vec)-1); 
      }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "parser.y" /* yacc.c:1646  */
    { yTRACE("type -> FLOAT_T \n") 
      	(yyval.as_ast) = ast_allocate(TYPE_NODE, FLOAT); 
      }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 226 "parser.y" /* yacc.c:1646  */
    { yTRACE("type -> VEC_T \n") 
      	(yyval.as_ast) = ast_allocate(TYPE_NODE, VEC2+(yyvsp[0].as_vec)-1); 
      }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 235 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> type ( arguments_opt ) \n") 
      	(yyval.as_ast) = ast_allocate(CONSTRUCTOR_NODE, (yyvsp[-3].as_ast), (yyvsp[-1].as_ast));
      }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 239 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> FUNC ( arguments_opt ) \n") 
      	(yyval.as_ast) = ast_allocate(FUNCTION_NODE, (yyvsp[-3].as_func), (yyvsp[-1].as_ast));
      }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> - expression \n") 
      	(yyval.as_ast) = ast_allocate(UNARY_EXPRESION_NODE, '-', (yyvsp[0].as_ast));
      }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> ! expression \n") 
      	(yyval.as_ast) = ast_allocate(UNARY_EXPRESION_NODE, '!', (yyvsp[0].as_ast));
      }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 255 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression AND expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, AND, (yyvsp[-2].as_ast), (yyvsp[0].as_ast));
      }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 259 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression OR expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, OR, (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 263 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression EQ expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, EQ, (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 267 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression NEQ expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, NEQ, (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 271 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression < expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '<', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 275 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression LEQ expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, LEQ, (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 279 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression > expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '>', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 283 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression GEQ expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, GEQ, (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 287 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression + expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '+', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 291 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression - expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '-', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 295 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression * expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '*', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 299 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression / expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '/', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 303 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> expression ^ expression \n") 
      	(yyval.as_ast) = ast_allocate(BINARY_EXPRESSION_NODE, '^', (yyvsp[-2].as_ast), (yyvsp[0].as_ast)); 
      }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 309 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> TRUE_C \n") 
      	(yyval.as_ast) = ast_allocate(BOOL_NODE, 1); 
      }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 313 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> FALSE_C \n") 
      	(yyval.as_ast) = ast_allocate(BOOL_NODE, 0); 
      }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 317 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> INT_C \n") 
      	(yyval.as_ast) = ast_allocate(INT_NODE, (yyvsp[0].as_int)); 
      }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 321 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> FLOAT_C \n") 
      	(yyval.as_ast) = ast_allocate(FLOAT_NODE, (yyvsp[0].as_float)); 
      }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 327 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> ( expression ) \n") 
      	(yyval.as_ast) = ast_allocate(NESTED_EXPRESSION_NODE, (yyvsp[-1].as_ast));
      }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 330 "parser.y" /* yacc.c:1646  */
    { }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 331 "parser.y" /* yacc.c:1646  */
    { yTRACE("expression -> variable \n") 
      (yyval.as_ast) = ast_allocate(EXP_VAR_NODE, (yyvsp[-1].as_ast));
    }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 338 "parser.y" /* yacc.c:1646  */
    { yTRACE("variable -> ID \n") 
      	(yyval.as_ast) = ast_allocate(VAR_NODE, 0, (yyvsp[0].as_str), 0); 
      }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 342 "parser.y" /* yacc.c:1646  */
    { yTRACE("variable -> ID [ INT_C ] \n") 
      	(yyval.as_ast) = ast_allocate(VAR_NODE, 1, (yyvsp[-3].as_str), (yyvsp[-1].as_int)); 
      }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 349 "parser.y" /* yacc.c:1646  */
    { yTRACE("arguments -> arguments , expression \n") 
      	(yyval.as_ast) = ast_allocate(ARGUMENTS_NODE, (yyvsp[-2].as_ast), (yyvsp[0].as_ast));;
      }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 353 "parser.y" /* yacc.c:1646  */
    { yTRACE("arguments -> expression \n") 
      	(yyval.as_ast) = ast_allocate(ARGUMENTS_NODE, NULL, (yyvsp[0].as_ast));
      }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 360 "parser.y" /* yacc.c:1646  */
    { yTRACE("arguments_opt -> arguments \n") 
      	(yyval.as_ast) = ast_allocate(ARGUMENTS_NODE, (yyvsp[0].as_ast), NULL);
      }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 364 "parser.y" /* yacc.c:1646  */
    { yTRACE("arguments_opt -> \n") 
      	(yyval.as_ast) = NULL;
      }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1787 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 369 "parser.y" /* yacc.c:1906  */


/***********************************************************************ol
 * Extra C code.
 *
 * The given yyerror function should not be touched. You may add helper
 * functions as necessary in subsequent phases.
 ***********************************************************************/
void yyerror(const char* s) {
  if(errorOccurred) {
    return;    /* Error has already been reported by scanner */
  } else {
    errorOccurred = 1;
  }

  fprintf(errorFile, "\nPARSER ERROR, LINE %d", yyline);
  
  if(strcmp(s, "parse error")) {
    if(strncmp(s, "parse error, ", 13)) {
      fprintf(errorFile, ": %s\n", s);
    } else {
      fprintf(errorFile, ": %s\n", s+13);
    }
  } else {
    fprintf(errorFile, ": Reading token %s\n", yytname[YYTRANSLATE(yychar)]);
  }
}

