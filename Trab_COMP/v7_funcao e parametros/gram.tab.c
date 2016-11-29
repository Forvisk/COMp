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
#line 1 "gram.y" /* yacc.c:339  */

#include "gram.h"
#define YYSTYPE pListaAtributos

int linha = 0;
int nlabel = 0, labelAtual = 0;

#line 74 "gram.tab.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TID = 258,
    TINT = 259,
    TSTR = 260,
    TVOID = 261,
    TADD = 262,
    TINC = 263,
    TSUB = 264,
    TDEC = 265,
    TMUL = 266,
    TDIV = 267,
    TIGUAL = 268,
    TIGUALMA = 269,
    TIGUALME = 270,
    TMAIOR = 271,
    TMENOR = 272,
    TDIF = 273,
    TNOT = 274,
    TAND = 275,
    TOR = 276,
    TNUM = 277,
    TLIT = 278,
    TIF = 279,
    TELSE = 280,
    TWHILE = 281,
    TREAD = 282,
    TPRINT = 283,
    TATR = 284,
    TRPAR = 285,
    TLPAR = 286,
    TVIRG = 287,
    TLCH = 288,
    TRCH = 289,
    TRET = 290,
    TFLIN = 291,
    TFIM = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 160 "gram.tab.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    12,    12,    15,    16,    19,    22,    27,    32,    38,
      40,    44,    46,    50,    54,    55,    58,    62,    68,    75,
      78,    83,    85,    89,    92,    93,    96,    97,    98,    99,
     100,   101,   102,   105,   106,   109,   122,   140,   147,   156,
     173,   175,   178,   183,   186,   193,   197,   198,   201,   202,
     204,   205,   209,   213,   217,   222,   225,   227,   232,   236,
     240,   244,   248,   252,   258,   260,   262,   266,   269,   272,
     277,   280,   281,   284,   289
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TID", "TINT", "TSTR", "TVOID", "TADD",
  "TINC", "TSUB", "TDEC", "TMUL", "TDIV", "TIGUAL", "TIGUALMA", "TIGUALME",
  "TMAIOR", "TMENOR", "TDIF", "TNOT", "TAND", "TOR", "TNUM", "TLIT", "TIF",
  "TELSE", "TWHILE", "TREAD", "TPRINT", "TATR", "TRPAR", "TLPAR", "TVIRG",
  "TLCH", "TRCH", "TRET", "TFLIN", "TFIM", "$accept", "Codigo", "Prog",
  "ListFunc", "Func", "TipeReturn", "DecPar", "Par", "BlocoP", "Decs",
  "Dec", "Tipe", "Listid", "Bloco", "ListCom", "Com", "Ret", "Cse", "M",
  "N", "Cenq", "Catr", "Cread", "Cprint", "Cnprint", "Cfunc", "ListPar",
  "ExpLog", "FLog", "ExpRela", "ExpAr", "Am", "An", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,  -118,  -118,  -118,    38,    24,  -118,    74,  -118,     6,
    -118,  -118,    81,     2,  -118,    32,  -118,   111,    38,  -118,
      54,    10,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,    36,   118,   106,   129,    65,   100,    80,
     112,   143,  -118,   121,   143,  -118,     3,     9,  -118,  -118,
      66,  -118,    -1,  -118,  -118,    78,   126,    95,  -118,  -118,
      92,   116,   129,   129,    -5,  -118,  -118,   180,   129,   117,
     136,  -118,  -118,    19,   143,   143,  -118,   143,   143,  -118,
     151,  -118,  -118,   123,  -118,   163,  -118,  -118,  -118,   141,
    -118,    51,   162,  -118,  -118,  -118,   143,   143,   143,   143,
     143,   143,    96,   132,   140,    61,  -118,     9,     9,  -118,
    -118,  -118,  -118,   177,  -118,  -118,   116,  -118,   129,   129,
     150,   116,   116,   116,   116,   116,   116,  -118,  -118,   137,
     148,  -118,  -118,  -118,    26,   160,   150,  -118,  -118,    71,
     161,  -118,  -118,  -118,   150,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    20,    10,     0,     0,     2,     0,     6,     0,
       4,     9,     0,     0,    37,     0,    45,     0,     0,    17,
       0,     0,    25,    32,    26,    27,    28,    29,    30,    31,
       1,     5,     3,     0,     0,     0,     0,     0,     0,     0,
      72,     0,    74,     0,     0,    73,     0,    66,    69,    16,
       0,    22,     0,    15,    24,     0,     0,     0,    51,    47,
       0,    50,     0,     0,     0,    54,    57,     0,     0,     0,
       0,    70,    34,     0,     0,     0,    33,     0,     0,    14,
       0,    18,     8,     0,    12,     0,    41,    40,    46,     0,
      56,     0,     0,    37,    37,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    64,    65,    67,
      68,    21,     7,     0,    13,    49,    48,    55,     0,     0,
       0,    58,    60,    61,    62,    63,    59,    37,    42,     0,
       0,    11,    52,    53,     0,    35,     0,    44,    43,     0,
       0,    39,    23,    37,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,   181,  -118,  -118,    77,   184,  -118,
     182,     0,  -118,  -117,   -16,   -20,  -118,  -118,   -87,  -118,
    -118,  -118,  -118,  -118,  -118,    -4,  -118,    93,   -59,  -118,
     -12,     1,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    83,    84,    10,    18,
      19,    11,    52,   135,    21,    22,    23,    24,    37,   140,
      25,    26,    27,    28,    39,    45,    60,    64,    65,    66,
      67,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    54,    50,    90,    20,    46,   118,   119,   120,    33,
      74,    71,    75,    12,    29,    93,    94,    29,    20,   141,
      77,    78,    57,    61,    30,    95,    74,   145,    75,    12,
      54,    80,    73,    36,    13,    81,    14,    15,    16,    76,
     136,    12,     1,     2,    53,    17,    29,   109,   110,   106,
      13,    92,    14,    15,    16,    85,   144,    51,   105,   132,
     133,    17,    13,    38,    14,    15,    16,    55,    74,    12,
      75,    93,    94,    17,    12,   107,   108,   116,     1,     2,
       3,   117,     1,     2,   121,   122,   123,   124,   125,   126,
      13,   130,    14,    15,    16,    13,    68,    14,    15,    16,
      79,    17,    74,    69,    75,   142,    17,     4,    82,    40,
      34,    70,    35,    85,    40,    41,    93,    94,   139,    54,
      41,    40,    88,    74,    89,    75,   127,    41,    42,    58,
      29,    87,    40,    42,    43,    29,    59,    44,    41,    40,
      42,    56,    44,    35,    40,    41,    40,   103,    62,    44,
      41,    42,    41,   112,   111,   113,    91,    72,    42,   104,
      63,   102,    86,    42,   115,    42,   114,    44,   128,    74,
     129,    75,    44,   137,    44,    96,    97,    98,    99,   100,
     101,     1,     2,   134,   138,   -38,   143,    74,    31,    75,
     131,    32,   106,    96,    97,    98,    99,   100,   101,     0,
      49
};

static const yytype_int16 yycheck[] =
{
       4,    21,    18,    62,     4,    17,    93,    94,    95,     3,
       7,    41,     9,     3,    18,    20,    21,    21,    18,   136,
      11,    12,    34,    35,     0,    30,     7,   144,     9,     3,
      50,    32,    44,    31,    24,    36,    26,    27,    28,    36,
     127,     3,     4,     5,    34,    35,    50,    77,    78,    30,
      24,    63,    26,    27,    28,    55,   143,     3,    70,   118,
     119,    35,    24,    31,    26,    27,    28,    31,     7,     3,
       9,    20,    21,    35,     3,    74,    75,    89,     4,     5,
       6,    30,     4,     5,    96,    97,    98,    99,   100,   101,
      24,    30,    26,    27,    28,    24,    31,    26,    27,    28,
      34,    35,     7,     3,     9,    34,    35,    33,    30,     3,
      29,    31,    31,   113,     3,     9,    20,    21,   134,   139,
       9,     3,    30,     7,    32,     9,    30,     9,    22,    23,
     134,    36,     3,    22,    23,   139,    30,    31,     9,     3,
      22,    23,    31,    31,     3,     9,     3,    30,    19,    31,
       9,    22,     9,    30,     3,    32,    63,    36,    22,    23,
      31,    68,    36,    22,    23,    22,     3,    31,    36,     7,
      30,     9,    31,    36,    31,    13,    14,    15,    16,    17,
      18,     4,     5,    33,    36,    25,    25,     7,     7,     9,
     113,     7,    30,    13,    14,    15,    16,    17,    18,    -1,
      18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    33,    39,    40,    41,    42,    43,
      46,    49,     3,    24,    26,    27,    28,    35,    47,    48,
      49,    52,    53,    54,    55,    58,    59,    60,    61,    63,
       0,    42,    46,     3,    29,    31,    31,    56,    31,    62,
       3,     9,    22,    23,    31,    63,    68,    69,    70,    48,
      52,     3,    50,    34,    53,    31,    23,    68,    23,    30,
      64,    68,    19,    31,    65,    66,    67,    68,    31,     3,
      31,    70,    36,    68,     7,     9,    36,    11,    12,    34,
      32,    36,    30,    44,    45,    49,    36,    36,    30,    32,
      66,    65,    68,    20,    21,    30,    13,    14,    15,    16,
      17,    18,    65,    30,    23,    68,    30,    69,    69,    70,
      70,     3,    30,    32,     3,    23,    68,    30,    56,    56,
      56,    68,    68,    68,    68,    68,    68,    30,    36,    30,
      30,    45,    66,    66,    33,    51,    56,    36,    36,    52,
      57,    51,    34,    25,    56,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    46,    46,    47,    47,    48,    49,
      49,    50,    50,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    57,    58,
      59,    59,    60,    61,    61,    62,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     5,     4,     1,
       1,     3,     1,     2,     4,     3,     2,     1,     3,     1,
       1,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     6,    10,     0,     0,     7,
       4,     4,     5,     6,     6,     0,     4,     3,     3,     3,
       1,     1,     4,     4,     1,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       2,     3,     1,     1,     1
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
        case 5:
#line 19 "gram.y" /* yacc.c:1646  */
    {	
								addToGreatList( (yyvsp[0]), 0, (yyvsp[0]) -> tipe_temp);
							}
#line 1350 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 22 "gram.y" /* yacc.c:1646  */
    {	
								addToGreatList( (yyvsp[0]), 0, (yyvsp[0]) -> tipe_temp);
							}
#line 1358 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 27 "gram.y" /* yacc.c:1646  */
    {	
													addIdToList( (yyvsp[-1]), (yyvsp[-3]));
													addToBigList( (yyval), (yyvsp[-1]), 0, T_TODEF);
													addToGreatList((yyvsp[-1]), 0, T_TODEF);
												}
#line 1368 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 32 "gram.y" /* yacc.c:1646  */
    {	
													addIdToList( (yyvsp[0]), (yyvsp[-2]));
													addToGreatList((yyvsp[0]), 0, T_TODEF);
												}
#line 1377 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 38 "gram.y" /* yacc.c:1646  */
    {	(yyval) = (yyvsp[0]);
								}
#line 1384 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 40 "gram.y" /* yacc.c:1646  */
    {	(yyval) = createTipe( T_VOID);
								}
#line 1391 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 44 "gram.y" /* yacc.c:1646  */
    {	addIdToList( (yyvsp[-2]), (yyvsp[0]));
								}
#line 1398 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 46 "gram.y" /* yacc.c:1646  */
    {	addIdToList( (yyval), (yyvsp[0]));
								}
#line 1405 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 50 "gram.y" /* yacc.c:1646  */
    {	addIdToList( (yyval), (yyvsp[0]));
						}
#line 1412 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 58 "gram.y" /* yacc.c:1646  */
    {	
								printf("Decs -> Decs Dec %p %p\n", (void*)(yyval), (void*)(yyvsp[0]));
							addToGreatList( (yyvsp[0]), 1, (yyvsp[0]) -> tipe_temp);
						}
#line 1421 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "gram.y" /* yacc.c:1646  */
    {	
								printf("Decs -> Dec %p %p\n", (void*)(yyval), (void*)(yyvsp[0]));
							addToGreatList( (yyvsp[0]), 1, (yyvsp[0]) -> tipe_temp);
						}
#line 1430 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 68 "gram.y" /* yacc.c:1646  */
    {	
									(yyvsp[-1]) -> tipe_temp = (yyvsp[-2]) -> tipe_temp;
									(yyval) = (yyvsp[-1]);
									free((yyvsp[-2]));
								}
#line 1440 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 75 "gram.y" /* yacc.c:1646  */
    {
									(yyval) = createTipe( T_INT);
								}
#line 1448 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 78 "gram.y" /* yacc.c:1646  */
    {
									(yyval) = createTipe( T_STR);
								}
#line 1456 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 83 "gram.y" /* yacc.c:1646  */
    {	addIdToList((yyvsp[-2]), (yyvsp[0]));
								}
#line 1463 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "gram.y" /* yacc.c:1646  */
    {	addIdToList((yyval), (yyvsp[0]));
								}
#line 1470 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 109 "gram.y" /* yacc.c:1646  */
    {	
																	corrigirLabel( (yyvsp[-3]) -> seVerdadeiro, (yyvsp[-1]) -> label);
																	

																	nlabel++;
																	/*printf("n_labl %i\n", nlabel);*/
																	labelAtual = nlabel;
																	addLabel( labelAtual);

																	corrigirLabel( (yyvsp[-3]) -> seFalso, labelAtual);
																	free((yyvsp[-3]));
																	free((yyvsp[-1]));
																}
#line 1488 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 122 "gram.y" /* yacc.c:1646  */
    {	
																	corrigirLabel( (yyvsp[-7]) -> seVerdadeiro, (yyvsp[-5]) -> label);
																	corrigirLabel( (yyvsp[-7]) -> seFalso, (yyvsp[-1]) -> label);	

																	nlabel++;
																	/*printf("n_labl %i\n", nlabel);*/
																	labelAtual = nlabel;
																	addLabel( labelAtual);

																	corrigirLabel( (yyvsp[-3]) -> seVerdadeiro, labelAtual);

																	free((yyvsp[-7]));
																	free((yyvsp[-5]));
																	free((yyvsp[-3]));
																	free((yyvsp[-1]));
																}
#line 1509 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 140 "gram.y" /* yacc.c:1646  */
    {	nlabel++;
				/*printf("n_labl %i\n", nlabel);*/
				labelAtual = nlabel;
				(yyval) = addLabel( labelAtual);
			}
#line 1519 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 147 "gram.y" /* yacc.c:1646  */
    {	
				int linha = getTamListInstrucoes(); 
				addGoto( labelAtual);
				/*printf("%i ifelse GOTO", linha);*/
				(yyval) = createListVeF( GOTO, linha);
				(yyval) -> label = labelAtual;
			}
#line 1531 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 156 "gram.y" /* yacc.c:1646  */
    {   
														corrigirLabel( (yyvsp[-3]) -> seVerdadeiro, (yyvsp[-1]) -> label);
														addGoto((yyvsp[-5]) -> label);

														nlabel++;
														/*printf("n_labl %i\n", nlabel);*/
														labelAtual = nlabel;
														addLabel( labelAtual);

														corrigirLabel( (yyvsp[-3]) -> seFalso, labelAtual);

														free((yyvsp[-5]));
														free((yyvsp[-3]));
														free((yyvsp[-1]));
													}
#line 1551 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 173 "gram.y" /* yacc.c:1646  */
    {	addInstrucaoListaPosVal( ISTORE, getPosVal( (yyvsp[-3]) -> nomeIdTemp), -1, labelAtual);
										}
#line 1558 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 178 "gram.y" /* yacc.c:1646  */
    {	addNumLista( 3, labelAtual);
															addInstrucaoListaPosVal( ISTORE, getPosVal((yyvsp[-4])->nomeIdTemp), -1, labelAtual);
														}
#line 1566 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 183 "gram.y" /* yacc.c:1646  */
    {	/*addInstrucaoLista( INVOKEVIRTUAL, PRINT_INT, INVAL, labelAtual);*/
															addPrintInt( labelAtual);
														}
#line 1574 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 186 "gram.y" /* yacc.c:1646  */
    { 	addInstrucaoLista( LDC, addLiteralLista( (yyvsp[-2])), INVAL, labelAtual);
															/*addInstrucaoLista( INVOKEVIRTUAL, PRINT_STR, INVAL, labelAtual);*/
															addPrintStr( labelAtual);

														}
#line 1584 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 193 "gram.y" /* yacc.c:1646  */
    { 	addGetstaticSout( labelAtual);
				}
#line 1591 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 202 "gram.y" /* yacc.c:1646  */
    {	addLiteralLista((yyvsp[0]));
									}
#line 1598 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "gram.y" /* yacc.c:1646  */
    {	addLiteralLista((yyvsp[0]));
									}
#line 1605 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "gram.y" /* yacc.c:1646  */
    {	
										corrigirLabel( (yyvsp[-3]) -> seVerdadeiro, (yyvsp[-1]) -> label);
										(yyval) = mergeAnd( (yyvsp[0]), (yyvsp[-3]));
									}
#line 1614 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 213 "gram.y" /* yacc.c:1646  */
    {	
										corrigirLabel( (yyvsp[-3]) -> seFalso, (yyvsp[-1]) -> label);
										(yyval) = mergeOr( (yyvsp[0]), (yyvsp[-3]));
									}
#line 1623 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 217 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[0]);
									}
#line 1631 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 222 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[-1]);
									}
#line 1639 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 225 "gram.y" /* yacc.c:1646  */
    {	(yyval) = not( (yyvsp[0]));
									}
#line 1646 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 227 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[0]);
									}
#line 1654 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 232 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFEQ, linha);
											addIf( IFEQ, -1, -1, labelAtual);
										}
#line 1663 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 236 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFDIF, linha);
											addIf( IFDIF, -1, -1, labelAtual);
										}
#line 1672 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 240 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFMAEQ, linha);
											addIf( IFMAEQ, -1, -1, labelAtual);
										}
#line 1681 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 244 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFMEEQ, linha);
											addIf( IFMEEQ, -1, -1, labelAtual);
										}
#line 1690 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 248 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFMA, linha);
											addIf( IFMA, -1, -1, labelAtual);
										}
#line 1699 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 252 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFME, linha);
											addIf( IFME, -1, -1, labelAtual);
										}
#line 1708 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 258 "gram.y" /* yacc.c:1646  */
    {	addInstrucaoLista( IADD, INVAL, INVAL, labelAtual);
								}
#line 1715 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 260 "gram.y" /* yacc.c:1646  */
    {	addInstrucaoLista( ISUB, INVAL, INVAL, labelAtual);
								}
#line 1722 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 262 "gram.y" /* yacc.c:1646  */
    {	(yyval) = (yyvsp[0]);
								}
#line 1729 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "gram.y" /* yacc.c:1646  */
    {	
										addInstrucaoLista( IMUL, INVAL, INVAL, labelAtual);
									}
#line 1737 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 269 "gram.y" /* yacc.c:1646  */
    {	
										addInstrucaoLista( IDIV, INVAL, INVAL, labelAtual);
									}
#line 1745 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 272 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[0]);
									}
#line 1753 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 277 "gram.y" /* yacc.c:1646  */
    {	
										addInstrucaoLista( INEG, INVAL, INVAL, labelAtual);
									}
#line 1761 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 281 "gram.y" /* yacc.c:1646  */
    { 	
										addInstrucaoListaPosVal( ILOAD, getPosVal((yyvsp[0])->nomeIdTemp), -1, labelAtual);
									}
#line 1769 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 284 "gram.y" /* yacc.c:1646  */
    {
										if( existeId( getGreatList(), (yyvsp[0])) == 0){

										}
									}
#line 1779 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 289 "gram.y" /* yacc.c:1646  */
    {	
										addNumLista( (yyvsp[0]) -> numTemp, labelAtual);
									}
#line 1787 "gram.tab.c" /* yacc.c:1646  */
    break;


#line 1791 "gram.tab.c" /* yacc.c:1646  */
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
#line 294 "gram.y" /* yacc.c:1906  */

#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", linha, yytext, str);
	setPossuiErro();
} 		 
int yywrap(){
	return 1;
}
