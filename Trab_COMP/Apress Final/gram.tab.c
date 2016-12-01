/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
    TFIM = 292,
    TMAISIGUAL = 293
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

#line 161 "gram.tab.c" /* yacc.c:358  */

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    12,    12,    15,    16,    19,    22,    27,    31,    37,
      39,    43,    45,    49,    54,    55,    58,    62,    68,    75,
      78,    83,    85,    89,    92,    93,    96,    97,    98,    99,
     100,   101,   102,   104,   107,   108,   111,   124,   142,   149,
     158,   175,   184,   191,   194,   200,   219,   229,   238,   242,
     243,   246,   247,   249,   250,   254,   258,   262,   267,   270,
     272,   277,   281,   285,   289,   293,   297,   303,   305,   307,
     311,   314,   317,   322,   325,   326,   336,   341
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
  "TLCH", "TRCH", "TRET", "TFLIN", "TFIM", "TMAISIGUAL", "$accept",
  "Codigo", "Prog", "ListFunc", "Func", "TipeReturn", "DecPar", "Par",
  "BlocoP", "Decs", "Dec", "Tipe", "Listid", "Bloco", "ListCom", "Com",
  "Ret", "Cse", "M", "N", "Cenq", "Caddatr", "Inc", "Catr", "Cread",
  "Cprint", "Cnprint", "Cfunc", "ListPar", "ExpLog", "FLog", "ExpRela",
  "ExpAr", "Am", "An", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  -131,  -131,  -131,    42,    10,  -131,    16,  -131,    57,
    -131,  -131,    22,   -18,  -131,    53,  -131,   110,    42,  -131,
      92,     9,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,    71,   135,   106,    68,   140,    99,
     124,   103,   111,   147,  -131,   116,   147,  -131,    19,   176,
    -131,  -131,    47,  -131,    27,  -131,  -131,    74,   134,    20,
    -131,  -131,    82,   146,   147,   140,   140,    -5,  -131,  -131,
     186,   140,   117,   142,  -131,  -131,    96,   147,   147,  -131,
     147,   147,  -131,   143,  -131,  -131,   131,  -131,   157,  -131,
    -131,  -131,   145,    89,  -131,    90,   168,  -131,  -131,  -131,
     147,   147,   147,   147,   147,   147,   101,   136,   144,   109,
    -131,   176,   176,  -131,  -131,  -131,  -131,    26,  -131,  -131,
     146,  -131,  -131,   140,   140,   156,   146,   146,   146,   146,
     146,   146,  -131,  -131,   154,   155,  -131,  -131,  -131,    59,
     167,   156,  -131,  -131,    73,   169,  -131,  -131,  -131,   156,
    -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    20,    10,     0,     0,     2,     0,     6,     0,
       4,     9,    42,     0,    38,     0,    48,     0,     0,    17,
       0,     0,    25,    32,    26,    27,    33,    28,    29,    30,
      31,     1,     5,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,    77,     0,     0,    76,     0,    69,
      72,    16,     0,    22,     0,    15,    24,     0,     0,     0,
      54,    50,     0,    53,     0,     0,     0,     0,    57,    60,
       0,     0,     0,     0,    73,    35,     0,     0,     0,    34,
       0,     0,    14,     0,    18,     8,     0,    12,     0,    44,
      43,    49,     0,     0,    59,     0,     0,    38,    38,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    67,    68,    70,    71,    21,     7,     0,    13,    52,
      51,    41,    58,     0,     0,     0,    61,    63,    64,    65,
      66,    62,    38,    45,     0,     0,    11,    55,    56,     0,
      36,     0,    47,    46,     0,     0,    40,    23,    38,     0,
      37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,   172,  -131,  -131,    63,   189,  -131,
     179,     0,  -131,  -130,   -16,   -20,  -131,  -131,   -90,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,    -4,  -131,     1,
     -59,  -131,   -12,   -39,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    86,    87,    10,    18,
      19,    11,    54,   140,    21,    22,    23,    24,    39,   145,
      25,    26,    37,    27,    28,    29,    41,    47,    62,    67,
      68,    69,    70,    49,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    56,    52,    74,    20,    48,    94,   123,   124,   125,
      31,   146,    12,    38,    30,    97,    98,    30,    20,   150,
       1,     2,     3,    59,    63,    99,    77,    77,    78,    78,
       1,     2,    56,    13,    76,    14,    15,    16,   111,   112,
     113,   114,   141,    55,    17,    12,     1,     2,    30,     4,
      12,    35,    93,    36,    96,    79,    90,    88,   149,    83,
      34,   109,    12,    84,   137,   138,    13,    95,    14,    15,
      16,    13,   106,    14,    15,    16,    12,    17,     1,     2,
     120,    82,    17,    13,    40,    14,    15,    16,   126,   127,
     128,   129,   130,   131,    17,    53,    77,    13,    78,    14,
      15,    16,    57,    77,    85,    78,    64,   147,    17,    42,
      97,    98,    91,    42,    92,    43,    77,    88,    78,    43,
     122,    97,    98,   144,    56,   121,   110,    72,    44,    60,
      71,   132,    44,    45,    73,    30,    61,    46,    42,   135,
      30,    46,    36,    42,    43,    42,   115,   107,    42,    43,
      42,    43,    75,    77,    43,    78,    43,    44,    58,    65,
     118,   116,    44,   117,    44,   108,    46,    44,   119,    44,
      89,    66,   133,    46,   134,    77,    46,    78,    46,    32,
     136,   100,   101,   102,   103,   104,   105,    80,    81,   139,
     142,   143,   -39,    77,   148,    78,    33,    51,   110,   100,
     101,   102,   103,   104,   105
};

static const yytype_uint8 yycheck[] =
{
       4,    21,    18,    43,     4,    17,    65,    97,    98,    99,
       0,   141,     3,    31,    18,    20,    21,    21,    18,   149,
       4,     5,     6,    35,    36,    30,     7,     7,     9,     9,
       4,     5,    52,    24,    46,    26,    27,    28,    77,    78,
      80,    81,   132,    34,    35,     3,     4,     5,    52,    33,
       3,    29,    64,    31,    66,    36,    36,    57,   148,    32,
       3,    73,     3,    36,   123,   124,    24,    66,    26,    27,
      28,    24,    71,    26,    27,    28,     3,    35,     4,     5,
      92,    34,    35,    24,    31,    26,    27,    28,   100,   101,
     102,   103,   104,   105,    35,     3,     7,    24,     9,    26,
      27,    28,    31,     7,    30,     9,    38,    34,    35,     3,
      20,    21,    30,     3,    32,     9,     7,   117,     9,     9,
      30,    20,    21,   139,   144,    36,    30,     3,    22,    23,
      31,    30,    22,    23,    31,   139,    30,    31,     3,    30,
     144,    31,    31,     3,     9,     3,     3,    30,     3,     9,
       3,     9,    36,     7,     9,     9,     9,    22,    23,    19,
       3,    30,    22,    32,    22,    23,    31,    22,    23,    22,
      36,    31,    36,    31,    30,     7,    31,     9,    31,     7,
     117,    13,    14,    15,    16,    17,    18,    11,    12,    33,
      36,    36,    25,     7,    25,     9,     7,    18,    30,    13,
      14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    33,    40,    41,    42,    43,    44,
      47,    50,     3,    24,    26,    27,    28,    35,    48,    49,
      50,    53,    54,    55,    56,    59,    60,    62,    63,    64,
      66,     0,    43,    47,     3,    29,    31,    61,    31,    57,
      31,    65,     3,     9,    22,    23,    31,    66,    71,    72,
      73,    49,    53,     3,    51,    34,    54,    31,    23,    71,
      23,    30,    67,    71,    38,    19,    31,    68,    69,    70,
      71,    31,     3,    31,    73,    36,    71,     7,     9,    36,
      11,    12,    34,    32,    36,    30,    45,    46,    50,    36,
      36,    30,    32,    71,    69,    68,    71,    20,    21,    30,
      13,    14,    15,    16,    17,    18,    68,    30,    23,    71,
      30,    72,    72,    73,    73,     3,    30,    32,     3,    23,
      71,    36,    30,    57,    57,    57,    71,    71,    71,    71,
      71,    71,    30,    36,    30,    30,    46,    69,    69,    33,
      52,    57,    36,    36,    53,    58,    52,    34,    25,    57,
      52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    45,    45,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    58,
      59,    60,    61,    62,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    67,    67,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     5,     4,     1,
       1,     3,     1,     2,     4,     3,     2,     1,     3,     1,
       1,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     6,    10,     0,     0,
       7,     5,     0,     4,     4,     5,     6,     6,     0,     4,
       3,     3,     3,     1,     1,     4,     4,     1,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     2,     3,     1,     1,     1
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
#line 1355 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 22 "gram.y" /* yacc.c:1646  */
    {	
								addToGreatList( (yyvsp[0]), 0, (yyvsp[0]) -> tipe_temp);
							}
#line 1363 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 27 "gram.y" /* yacc.c:1646  */
    {	
													addIdToList( (yyvsp[-1]), (yyvsp[-3]));
													addToGreatList((yyvsp[-1]), 0, T_TODEF);
												}
#line 1372 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 31 "gram.y" /* yacc.c:1646  */
    {	
													addIdToList( (yyvsp[0]), (yyvsp[-2]));
													addToGreatList((yyvsp[0]), 0, T_TODEF);
												}
#line 1381 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 37 "gram.y" /* yacc.c:1646  */
    {	(yyval) = (yyvsp[0]);
								}
#line 1388 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 39 "gram.y" /* yacc.c:1646  */
    {	(yyval) = createTipe( T_VOID);
								}
#line 1395 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 43 "gram.y" /* yacc.c:1646  */
    {	/*addIdToList( $1, $3);*/
								}
#line 1402 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 45 "gram.y" /* yacc.c:1646  */
    {	/*addIdToList( $$, $1);*/
								}
#line 1409 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 49 "gram.y" /* yacc.c:1646  */
    {	addIdToList( (yyvsp[0]), (yyvsp[0]));
							addToGreatList((yyvsp[0]), 1, (yyvsp[-1]) -> tipe_temp);
						}
#line 1417 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 58 "gram.y" /* yacc.c:1646  */
    {	
								/*printf("Decs -> Decs Dec %p %p\n", (void*)$$, (void*)$2);*/
							addToGreatList( (yyvsp[0]), 1, (yyvsp[0]) -> tipe_temp);
						}
#line 1426 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "gram.y" /* yacc.c:1646  */
    {	
								/*printf("Decs -> Dec %p %p\n", (void*)$$, (void*)$1);*/
							addToGreatList( (yyvsp[0]), 1, (yyvsp[0]) -> tipe_temp);
						}
#line 1435 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 68 "gram.y" /* yacc.c:1646  */
    {	
									(yyvsp[-1]) -> tipe_temp = (yyvsp[-2]) -> tipe_temp;
									(yyval) = (yyvsp[-1]);
									free((yyvsp[-2]));
								}
#line 1445 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 75 "gram.y" /* yacc.c:1646  */
    {
									(yyval) = createTipe( T_INT);
								}
#line 1453 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 78 "gram.y" /* yacc.c:1646  */
    {
									(yyval) = createTipe( T_STR);
								}
#line 1461 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 83 "gram.y" /* yacc.c:1646  */
    {	addIdToList((yyvsp[-2]), (yyvsp[0]));
								}
#line 1468 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "gram.y" /* yacc.c:1646  */
    {	addIdToList((yyval), (yyvsp[0]));
								}
#line 1475 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 111 "gram.y" /* yacc.c:1646  */
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
#line 1493 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 124 "gram.y" /* yacc.c:1646  */
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
#line 1514 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 142 "gram.y" /* yacc.c:1646  */
    {	nlabel++;
				/*printf("n_labl %i\n", nlabel);*/
				labelAtual = nlabel;
				(yyval) = addLabel( labelAtual);
			}
#line 1524 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 149 "gram.y" /* yacc.c:1646  */
    {	
				int linha = getTamListInstrucoes(); 
				addGoto( labelAtual);
				/*printf("%i ifelse GOTO", linha);*/
				(yyval) = createListVeF( GOTO, linha);
				(yyval) -> label = labelAtual;
			}
#line 1536 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 158 "gram.y" /* yacc.c:1646  */
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
#line 1556 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 175 "gram.y" /* yacc.c:1646  */
    {	if( existeId( getGreatList(), (yyvsp[-4])) == 1){
													setPossuiErro();
												}
												corrigirPosVal( (yyvsp[-3]) -> seVerdadeiro, getPosVal((yyvsp[-4])->nomeIdTemp));
												addInstrucaoLista( IADD, INVAL, INVAL, labelAtual, 0);
												addInstrucaoListaPosVal( ISTORE, getPosVal( (yyvsp[-4]) -> nomeIdTemp), -1, labelAtual);
											}
#line 1568 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 184 "gram.y" /* yacc.c:1646  */
    {	
			int linha = getTamListInstrucoes();
			(yyval) = createListVeF( ILOAD, linha);
			addInstrucaoListaPosVal( ILOAD, 0, -1, labelAtual);
		}
#line 1578 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 191 "gram.y" /* yacc.c:1646  */
    {	
											addInstrucaoListaPosVal( ISTORE, getPosVal( (yyvsp[-3]) -> nomeIdTemp), -1, labelAtual);
										}
#line 1586 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 194 "gram.y" /* yacc.c:1646  */
    {
											addLdc( addLiteralLista( (yyvsp[-1])), labelAtual);
											addInstrucaoListaPosVal( ISTORE, getPosVal( (yyvsp[-3]) -> nomeIdTemp), -1, labelAtual);
										}
#line 1595 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 200 "gram.y" /* yacc.c:1646  */
    {	
															int tipe = getTipe( (yyvsp[-2])->nomeIdTemp);
															if( tipe == T_INT){
																/*printf(" ler inteiro %s\n", $3->nomeIdTemp);*/
																addNumLista( 3, labelAtual);
															} else if( tipe == T_STR){
																/*printf(" ler string %s\n", $3->nomeIdTemp);*/
																addLdc( "\"Aqui temos sorvete\"", labelAtual);
															} else {
																printf("\nErro %s %i\n", (yyvsp[-2])->nomeIdTemp, tipe);
																setPossuiErro();
															}
															if( existeId( getGreatList(), (yyvsp[-2])) == 1){
																setPossuiErro();
															}
															addInstrucaoListaPosVal( ISTORE, getPosVal((yyvsp[-2])->nomeIdTemp), -1, labelAtual);
														}
#line 1617 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 219 "gram.y" /* yacc.c:1646  */
    {	/*addInstrucaoLista( INVOKEVIRTUAL, PRINT_INT, INVAL, labelAtual);*/
															if( (yyvsp[-2]) -> tipe_temp == T_INT)
																addPrintInt( labelAtual);
															else if( (yyvsp[-2]) -> tipe_temp == T_STR)
																addPrintStr(labelAtual);
															else{
																setPossuiErro();
																printf("\nTipo incompativel para escrita\n");
															}
														}
#line 1632 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 229 "gram.y" /* yacc.c:1646  */
    { 	/*addInstrucaoLista( LDC, addLiteralLista( $4), INVAL, labelAtual);*/
															/*addInstrucaoLista( INVOKEVIRTUAL, PRINT_STR, INVAL, labelAtual);*/
															/*printf("\nliteral : %s\n", $4 -> literal);*/
															addLdc( addLiteralLista( (yyvsp[-2])), labelAtual);
															addPrintStr( labelAtual);

														}
#line 1644 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "gram.y" /* yacc.c:1646  */
    { 	addGetstaticSout( labelAtual);
				}
#line 1651 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 247 "gram.y" /* yacc.c:1646  */
    {	addLiteralLista((yyvsp[0]));
									}
#line 1658 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 250 "gram.y" /* yacc.c:1646  */
    {	addLiteralLista((yyvsp[0]));
									}
#line 1665 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 254 "gram.y" /* yacc.c:1646  */
    {	
										corrigirLabel( (yyvsp[-3]) -> seVerdadeiro, (yyvsp[-1]) -> label);
										(yyval) = mergeAnd( (yyvsp[0]), (yyvsp[-3]));
									}
#line 1674 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 258 "gram.y" /* yacc.c:1646  */
    {	
										corrigirLabel( (yyvsp[-3]) -> seFalso, (yyvsp[-1]) -> label);
										(yyval) = mergeOr( (yyvsp[0]), (yyvsp[-3]));
									}
#line 1683 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 262 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[0]);
									}
#line 1691 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 267 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[-1]);
									}
#line 1699 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 270 "gram.y" /* yacc.c:1646  */
    {	(yyval) = not( (yyvsp[0]));
									}
#line 1706 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 272 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[0]);
									}
#line 1714 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 277 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFEQ, linha);
											addIf( IFEQ, -1, -1, labelAtual);
										}
#line 1723 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 281 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFDIF, linha);
											addIf( IFDIF, -1, -1, labelAtual);
										}
#line 1732 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 285 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFMAEQ, linha);
											addIf( IFMAEQ, -1, -1, labelAtual);
										}
#line 1741 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 289 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFMEEQ, linha);
											addIf( IFMEEQ, -1, -1, labelAtual);
										}
#line 1750 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 293 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFMA, linha);
											addIf( IFMA, -1, -1, labelAtual);
										}
#line 1759 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 297 "gram.y" /* yacc.c:1646  */
    {	int linha = getTamListInstrucoes();
											(yyval) = createListVeF( IFME, linha);
											addIf( IFME, -1, -1, labelAtual);
										}
#line 1768 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 303 "gram.y" /* yacc.c:1646  */
    {	addInstrucaoLista( IADD, INVAL, INVAL, labelAtual, 0);
								}
#line 1775 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 305 "gram.y" /* yacc.c:1646  */
    {	addInstrucaoLista( ISUB, INVAL, INVAL, labelAtual, 0);
								}
#line 1782 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 307 "gram.y" /* yacc.c:1646  */
    {	(yyval) = (yyvsp[0]);
								}
#line 1789 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 311 "gram.y" /* yacc.c:1646  */
    {	
										addInstrucaoLista( IMUL, INVAL, INVAL, labelAtual, 0);
									}
#line 1797 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 314 "gram.y" /* yacc.c:1646  */
    {	
										addInstrucaoLista( IDIV, INVAL, INVAL, labelAtual, 0);
									}
#line 1805 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 317 "gram.y" /* yacc.c:1646  */
    {	
										(yyval) = (yyvsp[0]);
									}
#line 1813 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 322 "gram.y" /* yacc.c:1646  */
    {	
										addInstrucaoLista( INEG, INVAL, INVAL, labelAtual, 0);
									}
#line 1821 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 326 "gram.y" /* yacc.c:1646  */
    { 	
										if( existeId( getGreatList(), (yyvsp[0]) -> nomeIdTemp) == 1){
											setPossuiErro();
											printf("ID %s não existe\n", (yyvsp[0]) -> nomeIdTemp);
										}
										addInstrucaoListaPosVal( ILOAD, getPosVal((yyvsp[0])->nomeIdTemp), -1, labelAtual);
										(yyval) -> tipe_temp = getTipe( (yyvsp[0]) -> nomeIdTemp);
										/*printf("\n%i\n", $$ ->tipe_temp);*/
										free((yyvsp[0]));
									}
#line 1836 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 336 "gram.y" /* yacc.c:1646  */
    {
										if( existeId( getGreatList(), (yyvsp[0])) == 0){
											printf("\nFuncao nao implemetada\n");
										}
									}
#line 1846 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 341 "gram.y" /* yacc.c:1646  */
    {	
										addNumLista( (yyvsp[0]) -> numTemp, labelAtual);
									}
#line 1854 "gram.tab.c" /* yacc.c:1646  */
    break;


#line 1858 "gram.tab.c" /* yacc.c:1646  */
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
#line 346 "gram.y" /* yacc.c:1906  */

#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", linha, yytext, str);
	setPossuiErro();
} 		 
int yywrap(){
	return 1;
}
