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

  #include <string.h>
  #include <stdio.h>
  #include <glib.h>
  #include "symbol.h"
  #include "sym_list.h"
  #include "../include/sym_table.h"

  extern FILE *yyin;
  extern FILE *yyout;
  extern int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror(char *s);

  // inherited vars
  int inh_type, inh_dim;

  // Memory address for new vars
  int address = 0;

  // Temporal variables
  int temp = 0;

  // Symbol table
  Sym_Table *table; 

  // Aux functions
  void init();
  void error(char *msg, int line);

  symbol *operacion(symbol *arg1, symbol *arg2, char *op);
  char *get_temporal();

  char *aux_id;

#line 103 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INT = 258,
    DOUBLE = 259,
    FLOAT = 260,
    CHAR = 261,
    VOID = 262,
    STRUCT = 263,
    CARACTER = 264,
    NUMERO = 265,
    FLOTANTE = 266,
    CADENA = 267,
    SWITCH = 268,
    CASE = 269,
    BREAK = 270,
    DEFAULT = 271,
    FOR = 272,
    IF = 273,
    ELSE = 274,
    DO = 275,
    WHILE = 276,
    FUNC = 277,
    RETURN = 278,
    PRINT = 279,
    TRUE_P = 280,
    FALSE_P = 281,
    ID = 282,
    LE = 283,
    GE = 284,
    EQ = 285,
    NEQ = 286,
    AND = 287,
    OR = 288,
    IFX = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "parser.y" /* yacc.c:355  */

  char* cad;
  int num;
  double flo;
  struct intermediate_symbol *att;
  struct _GList* list;
  char *id;

#line 187 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   327

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    38,     2,     2,
      48,    49,    39,    36,    45,    37,    51,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    42,
      35,    50,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    76,    88,    88,    93,    98,   103,   108,
     113,   118,   123,   123,   143,   154,   167,   173,   183,   195,
     182,   208,   212,   215,   222,   221,   238,   238,   257,   263,
     271,   281,   281,   307,   318,   332,   341,   353,   353,   378,
     386,   397,   408,   414,   417,   438,   463,   466,   500,   525,
     554,   554,   576,   580,   594,   599,   603,   617,   631,   645,
     659,   671,   678,   685,   692,   699,   706,   727,   738,   752,
     762,   771,   780,   783,   816,   825,   836,   839,   842,   845,
     848,   851
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "FLOAT", "CHAR", "VOID",
  "STRUCT", "CARACTER", "NUMERO", "FLOTANTE", "CADENA", "SWITCH", "CASE",
  "BREAK", "DEFAULT", "FOR", "IF", "ELSE", "DO", "WHILE", "FUNC", "RETURN",
  "PRINT", "TRUE_P", "FALSE_P", "ID", "LE", "GE", "EQ", "NEQ", "AND", "OR",
  "'>'", "'<'", "'+'", "'-'", "'%'", "'*'", "'/'", "IFX", "';'", "'{'",
  "'}'", "','", "'['", "']'", "'('", "')'", "'='", "'.'", "':'", "'!'",
  "$accept", "program", "$@1", "decs", "$@2", "type", "$@3", "id_list",
  "type_arr", "funcs", "$@4", "$@5", "params", "param_list", "$@6", "$@7",
  "param_arr", "sents", "$@8", "$@9", "ids", "arrays", "cases", "$@10",
  "data", "case_def", "expression", "arguments", "logical", "relation", YY_NULLPTR
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
     285,   286,   287,   288,    62,    60,    43,    45,    37,    42,
      47,   289,    59,   123,   125,    44,    91,    93,    40,    41,
      61,    46,    58,    33
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,     4,   311,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
      -4,   -64,   -24,   311,   -64,    12,   311,    13,     6,    94,
      18,   -64,    63,   -64,   311,    55,   -64,    33,    68,   -64,
       6,   311,     6,   -64,   -64,    52,    57,   -64,    83,    81,
     311,    85,   311,   -64,    82,   -64,   232,   124,    85,   106,
     115,   110,   114,   121,   118,    24,    45,   -30,   232,    99,
     119,   126,    85,   -64,    45,   -64,   232,    65,   232,    65,
     -64,   -64,   -64,   -64,   -37,   -64,   -64,   257,   264,    45,
     152,   117,   -64,   232,    45,    45,   -64,   284,   183,   -64,
     -64,    65,    65,   233,   -25,   132,    31,    45,    45,    45,
      45,    45,    45,   -64,   -64,   240,   -64,   -64,    -4,   271,
     245,   135,    65,    62,    -6,   -64,   -64,   -64,   -64,   -64,
     -64,    45,    65,    65,   232,   160,   144,   284,    54,   250,
     250,   287,   -64,   -64,   -64,   -64,   -64,   -64,   147,    64,
     -64,   284,   -64,   159,   200,   149,   232,    45,   -64,   181,
     232,   232,    65,   150,   284,   153,   186,   232,   232,    76,
     -64,   189,   162,   167,   163,   174,   -64,   232,   -64,   179,
     -64,   -64,   232,   232,   232,   165,   215,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     7,     9,     8,    10,    11,    12,
      21,     4,     0,     0,     3,     0,     6,     0,    17,     0,
       0,    18,     0,    15,     6,     0,    13,     0,     0,     5,
      17,    23,    17,    14,    26,     0,    22,    16,     0,     0,
       0,    29,     6,    24,     0,    27,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,    46,    29,    28,     0,    39,     0,     0,     0,     0,
      65,    63,    64,    62,    45,    42,    61,     0,     0,     0,
       0,     0,    19,    30,     0,     0,    25,    37,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    40,     0,    47,    43,    21,     0,
       0,     0,     0,     0,    71,    80,    78,    76,    77,    79,
      81,     0,     0,     0,     0,     0,     0,    68,     0,    58,
      59,    60,    56,    57,    48,    20,    44,    49,     0,     0,
      72,    73,    70,    69,    35,     0,     0,     0,    66,    52,
       0,     0,     0,     0,    67,     0,    55,    31,    36,     0,
      34,     0,     0,     0,     0,     0,    53,     0,    38,     0,
      33,    50,    54,     0,     0,     0,    52,    32,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,    37,   -64,    -8,   -64,   -64,   116,   123,
     -64,   -64,   -64,   -64,   -64,   -64,   -45,   -46,   -64,   -64,
     -54,   -64,    58,   -64,   -64,   -64,   -14,   -64,   -63,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    15,    11,    12,    19,    23,    14,
      27,   108,    35,    36,    47,    38,    45,    83,   164,   111,
      60,    61,   156,   174,   171,   163,    93,   128,    94,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    76,    76,    63,     3,    17,    96,   122,   123,    79,
      76,    97,    81,    76,    80,    76,    79,    86,    13,    16,
      88,    80,    95,    34,   124,    76,   122,   123,   113,   114,
      76,    76,    43,    70,    71,    72,    73,    76,    76,    18,
      21,    77,    78,    76,    76,    76,    76,    76,    76,   139,
      87,    74,    22,    20,    70,    71,    72,    73,    76,   142,
     143,    29,    26,   122,   123,   105,    75,    76,    76,    76,
     109,   110,    74,    28,    70,    71,    72,    73,   144,    46,
     126,    31,    30,   127,   129,   130,   131,   132,   133,   159,
      89,    90,    74,    76,   122,   123,   122,   123,    76,   147,
     153,    39,    40,   148,   157,   158,   150,   141,   122,   123,
      41,   140,    49,    91,    50,    32,    51,    52,    92,    53,
      54,   172,    55,    56,    42,   165,    57,   175,   176,    48,
      49,    44,    50,   154,    51,    52,    24,    53,    54,    25,
      55,    56,    58,    82,    57,    49,    33,    50,    37,    51,
      52,    62,    53,    54,    64,    55,    56,    65,    66,    57,
      58,   107,    67,    49,    68,    50,    69,    51,    52,    84,
      53,    54,    85,    55,    56,    58,   125,    57,    49,   106,
      50,   145,    51,    52,   138,    53,    54,   146,    55,    56,
     149,   122,    57,    58,   160,   155,    49,   152,    50,   166,
      51,    52,   162,    53,    54,   161,    55,    56,    58,   177,
      57,   168,   169,    49,   167,    50,   170,    51,    52,   151,
      53,    54,   173,    55,    56,   112,    58,    57,    49,   155,
      50,   135,    51,    52,   178,    53,    54,     0,    55,    56,
       0,     0,    57,    58,     0,    49,     0,    50,     0,    51,
      52,     0,    53,    54,     0,    55,    56,     0,    58,    57,
       0,   115,   116,   117,   118,     0,     0,   119,   120,    98,
      99,   100,   101,   102,     0,    58,    98,    99,   100,   101,
     102,    98,    99,   100,   101,   102,     0,   134,   100,   101,
     102,     0,   137,    98,    99,   100,   101,   102,     0,   103,
      98,    99,   100,   101,   102,     0,   104,    98,    99,   100,
     101,   102,     0,   136,     4,     5,     6,     7,     8,     9,
      98,    99,   100,   101,   102,    -1,   101,   102
};

static const yytype_int16 yycheck[] =
{
      46,    55,    56,    48,     0,    13,    69,    32,    33,    46,
      64,    48,    58,    67,    51,    69,    46,    62,    22,    43,
      66,    51,    68,    31,    49,    79,    32,    33,    91,    92,
      84,    85,    40,     9,    10,    11,    12,    91,    92,    27,
      27,    55,    56,    97,    98,    99,   100,   101,   102,   112,
      64,    27,    46,    16,     9,    10,    11,    12,   112,   122,
     123,    24,    44,    32,    33,    79,    42,   121,   122,   123,
      84,    85,    27,    10,     9,    10,    11,    12,   124,    42,
      49,    48,    27,    97,    98,    99,   100,   101,   102,   152,
      25,    26,    27,   147,    32,    33,    32,    33,   152,    45,
     146,    49,    45,    49,   150,   151,    42,   121,    32,    33,
      27,    49,    13,    48,    15,    47,    17,    18,    53,    20,
      21,   167,    23,    24,    43,    49,    27,   173,   174,    47,
      13,    46,    15,   147,    17,    18,    42,    20,    21,    45,
      23,    24,    43,    44,    27,    13,    30,    15,    32,    17,
      18,    27,    20,    21,    48,    23,    24,    42,    48,    27,
      43,    44,    48,    13,    43,    15,    48,    17,    18,    50,
      20,    21,    46,    23,    24,    43,    44,    27,    13,    27,
      15,    21,    17,    18,    49,    20,    21,    43,    23,    24,
      43,    32,    27,    43,    44,    14,    13,    48,    15,    10,
      17,    18,    16,    20,    21,    52,    23,    24,    43,    44,
      27,    44,    49,    13,    52,    15,    42,    17,    18,    19,
      20,    21,    43,    23,    24,    42,    43,    27,    13,    14,
      15,   108,    17,    18,   176,    20,    21,    -1,    23,    24,
      -1,    -1,    27,    43,    -1,    13,    -1,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    43,    27,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    -1,    43,    36,    37,    38,    39,
      40,    36,    37,    38,    39,    40,    -1,    47,    38,    39,
      40,    -1,    47,    36,    37,    38,    39,    40,    -1,    42,
      36,    37,    38,    39,    40,    -1,    42,    36,    37,    38,
      39,    40,    -1,    42,     3,     4,     5,     6,     7,     8,
      36,    37,    38,    39,    40,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,     7,     8,
      57,    59,    60,    22,    63,    58,    43,    59,    27,    61,
      57,    27,    46,    62,    42,    45,    44,    64,    10,    57,
      27,    48,    47,    62,    59,    66,    67,    62,    69,    49,
      45,    27,    43,    59,    46,    70,    57,    68,    47,    13,
      15,    17,    18,    20,    21,    23,    24,    27,    43,    71,
      74,    75,    27,    70,    48,    42,    48,    48,    43,    48,
       9,    10,    11,    12,    27,    42,    74,    80,    80,    46,
      51,    71,    44,    71,    50,    46,    70,    80,    71,    25,
      26,    48,    53,    80,    82,    71,    82,    48,    36,    37,
      38,    39,    40,    42,    42,    80,    27,    44,    65,    80,
      80,    73,    42,    82,    82,    28,    29,    30,    31,    34,
      35,    83,    32,    33,    49,    44,    49,    80,    81,    80,
      80,    80,    80,    80,    47,    63,    42,    47,    49,    82,
      49,    80,    82,    82,    71,    21,    43,    45,    49,    43,
      42,    19,    48,    71,    80,    14,    76,    71,    71,    82,
      44,    52,    16,    79,    72,    49,    10,    52,    44,    49,
      42,    78,    71,    43,    77,    71,    71,    44,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    56,    55,    58,    57,    57,    59,    59,    59,
      59,    59,    60,    59,    61,    61,    62,    62,    64,    65,
      63,    63,    66,    66,    68,    67,    69,    67,    70,    70,
      71,    72,    71,    71,    71,    71,    71,    73,    71,    71,
      71,    71,    71,    71,    71,    74,    74,    74,    75,    75,
      77,    76,    76,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     5,     0,     1,     1,     1,
       1,     1,     0,     5,     4,     2,     4,     0,     0,     0,
      13,     0,     1,     0,     0,     6,     0,     4,     3,     0,
       2,     0,    12,     9,     7,     5,     7,     0,     9,     2,
       3,     3,     2,     3,     4,     1,     1,     3,     4,     4,
       0,     7,     0,     0,     3,     0,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     4,     3,     1,     3,
       3,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 76 "parser.y" /* yacc.c:1646  */
    {
  init();
  }
#line 1430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "parser.y" /* yacc.c:1646  */
    {
  print_code();
  }
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "parser.y" /* yacc.c:1646  */
    {
	inh_type = (yyvsp[0].att)->type;
	inh_dim = (yyvsp[0].att)->dim;
	}
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = 0;
		(yyval.att)->dim = 4;
		}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 1;
            	(yyval.att)->dim = 4;
           	}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "parser.y" /* yacc.c:1646  */
    {
            	(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 2;
            	(yyval.att)->dim = 8;
            	}
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "parser.y" /* yacc.c:1646  */
    {
            	(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 3;
            	(yyval.att)->dim = 1;
            	}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "parser.y" /* yacc.c:1646  */
    {
            	(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 4;
            	(yyval.att)->dim = 0;
            	}
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "parser.y" /* yacc.c:1646  */
    {
		  // Create a new table and link it to the current one
  		Sym_Table *new_table; 
		  new_table = init_sym_table();
		  new_table->parent = table;
		  table->child = new_table;
		  table = new_table;
		}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "parser.y" /* yacc.c:1646  */
    {
		Sym_Table *prev = table;
		table = table->parent;
		
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = 5;
		(yyval.att)->dim = prev->size;
		}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "parser.y" /* yacc.c:1646  */
    {
		if(lookup(table, (yyvsp[-1].cad)) == NULL)
		{
			insert(table, (yyvsp[-1].cad), (yyvsp[0].att)->type, address, (yyvsp[0].att)->dim);
			address += (yyvsp[0].att)->dim;
		} else {
			error("ID defined twice.", yylineno);
		}
		}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "parser.y" /* yacc.c:1646  */
    {
		if(lookup(table, (yyvsp[-1].cad)) == NULL)
		{
			insert(table, (yyvsp[-1].cad), (yyvsp[0].att)->type, address, (yyvsp[0].att)->dim);
			address += (yyvsp[0].att)->dim;
		} else {
			error("ID defined twice.", yylineno);
		}
		}
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 167 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = (yyvsp[0].att);
				(yyval.att)->is_arr = 1;
				(yyval.att)->type = (yyvsp[0].att)->type;
				(yyval.att)->dim = (yyvsp[-2].num) * (yyvsp[0].att)->dim;
				}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 173 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				(yyval.att)->type = inh_type;
				(yyval.att)->dim = inh_dim;
				}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 183 "parser.y" /* yacc.c:1646  */
    {
    // Create a new table and link it to the current one
      Sym_Table *new_table; 
      new_table = init_sym_table();
      new_table->parent = table;
      table->child = new_table;
      table = new_table;

    // Codigo intermedio
    insert_code("label","","", (yyvsp[0].cad));
  }
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 195 "parser.y" /* yacc.c:1646  */
    {
    // Table
    Sym_Table *prev = table;
    table = table->parent;

    char *tmp, *lab;
    tmp = (char*) malloc(strlen((yyvsp[-8].cad))+4);
    sprintf(tmp, "%s%s", "end", (yyvsp[-8].cad));

    int line = insert_code("label","","", tmp);
    backpatch((yyvsp[-1].att)->lnext, line);
  }
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 212 "parser.y" /* yacc.c:1646  */
    {
		(yyval.list) = (yyvsp[0].list);
		}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 215 "parser.y" /* yacc.c:1646  */
    {
		(yyval.list) = NULL;
		}
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "parser.y" /* yacc.c:1646  */
    {
		inh_type = (yyvsp[0].att)->type;
		inh_dim = (yyvsp[0].att)->dim;
		}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 226 "parser.y" /* yacc.c:1646  */
    {
		(yyval.list) = (yyvsp[-5].list);

		if(lookup(table, (yyvsp[-1].cad)) == NULL)                              
                {                                                          
			(yyval.list) = g_list_append((yyval.list), (yyvsp[0].att)->type);
                        insert(table, (yyvsp[-1].cad), (yyvsp[0].att)->type, address, (yyvsp[0].att)->dim);                   
                        address += (yyvsp[0].att)->dim;                                     
                } else {                                                   
                        error("ID defined twice.", yylineno);              
                } 
		}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 238 "parser.y" /* yacc.c:1646  */
    {
		inh_type = (yyvsp[0].att)->type;
		inh_dim = (yyvsp[0].att)->dim;
		}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 242 "parser.y" /* yacc.c:1646  */
    {
		(yyval.list) = NULL;

		if(lookup(table, (yyvsp[-1].cad)) == NULL)                              
                {                                                          
			(yyval.list) = g_list_append((yyval.list), (yyvsp[0].att)->type);
                        insert(table, (yyvsp[-1].cad), (yyvsp[0].att)->type, address, (yyvsp[0].att)->dim);                   
                        address += (yyvsp[0].att)->dim;                                     
                } else {                                                   
                        error("ID defined twice.", yylineno);              
                }
		}
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 257 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
			(yyval.att)->dim = 8;
			(yyval.att)->is_arr = 1;
			(yyval.att)->type = (yyvsp[0].att)->type;
			}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 263 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = inh_type;
		(yyval.att)->dim = inh_dim;
		}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 272 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    backpatch((yyvsp[-1].att)->lnext, (yyvsp[0].att)->first);

    (yyval.att)->first = (yyvsp[-1].att)->first;
    (yyval.att)->lnext = (yyvsp[0].att)->lnext;
    (yyval.att)->lbreaks = merge((yyvsp[-1].att)->lbreaks, (yyvsp[0].att)->lbreaks);
  }
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 281 "parser.y" /* yacc.c:1646  */
    {

    int line = insert_code("goto", "", "", "");
    (yyvsp[0].att)->lnext = insert_in_label((yyvsp[0].att)->lnext, line);

    }
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 287 "parser.y" /* yacc.c:1646  */
    {
      (yyval.att) = new_inter_symbol();

      char tmp[10];
      sprintf(tmp, "%d", (yyvsp[-5].att)->first);
      int line = insert_code("goto", "", "", tmp);

      (yyval.att)->first = (yyvsp[-9].att)->first;

      backpatch((yyvsp[-9].att)->lnext, (yyvsp[-7].att)->first);

      backpatch((yyvsp[-7].att)->ltrue, (yyvsp[-1].att)->first);
      backpatch((yyvsp[-1].att)->lnext, (yyvsp[-5].att)->first);
      backpatch((yyvsp[-5].att)->lnext, (yyvsp[-7].att)->first);

      label temp = merge((yyvsp[-9].att)->lbreaks, (yyvsp[-5].att)->lbreaks);
      temp = merge((yyvsp[-1].att)->lbreaks, temp);

      (yyval.att)->lnext = merge((yyvsp[-7].att)->lfalse, temp);
    }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 308 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    (yyval.att)->first = (yyvsp[-6].att)->first;

    backpatch((yyvsp[-6].att)->lnext, (yyvsp[-2].att)->first);
    backpatch((yyvsp[-2].att)->ltrue, (yyvsp[-6].att)->first);

    (yyval.att)->lnext = merge((yyvsp[-2].att)->lfalse, (yyvsp[-2].att)->lbreaks);
  }
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 319 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    (yyval.att)->first = (yyvsp[-4].att)->first;
    backpatch((yyvsp[-4].att)->ltrue, (yyvsp[-1].att)->first);
    backpatch((yyvsp[-1].att)->lnext, (yyvsp[-4].att)->first);

    (yyval.att)->lnext = merge((yyvsp[-4].att)->lfalse, (yyvsp[-1].att)->lbreaks);

    char tmp[10];
    sprintf(tmp, "%d", (yyvsp[-4].att)->first);
    int line = insert_code("goto", "", "", tmp);
  }
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 333 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();
    backpatch((yyvsp[-2].att)->ltrue, (yyvsp[0].att)->first);

    (yyval.att)->first = (yyvsp[-2].att)->first;
    (yyval.att)->lnext = merge((yyvsp[-2].att)->lfalse, (yyvsp[0].att)->lnext);
    (yyval.att)->lbreaks = (yyvsp[0].att)->lbreaks;
  }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 342 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    (yyval.att)->first = (yyvsp[-4].att)->first;

    backpatch((yyvsp[-4].att)->ltrue, (yyvsp[-2].att)->first);
    backpatch((yyvsp[-4].att)->lfalse, (yyvsp[0].att)->first);

    (yyval.att)->lnext = merge((yyvsp[-2].att)->lnext, (yyvsp[0].att)->lnext);
    (yyval.att)->lbreaks = merge((yyvsp[-2].att)->lbreaks, (yyvsp[0].att)->lbreaks);
  }
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 353 "parser.y" /* yacc.c:1646  */
    {
    aux_id = strdup((yyvsp[0].att)->id);
  }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 356 "parser.y" /* yacc.c:1646  */
    {
    free(aux_id);
    (yyval.att) = new_inter_symbol();

    if((yyvsp[-6].att)->first != -1)
      (yyval.att)->first = (yyvsp[-6].att)->first;
    else if((yyvsp[-2].att)->first != -1)
      (yyval.att)->first = (yyvsp[-2].att)->first;
    else if((yyvsp[-1].att)->first != -1)
      (yyval.att)->first = (yyvsp[-1].att)->first;
    else{
      int line = insert_code("nop", "", "", "");
      (yyval.att)->first = line;
    }

    if((yyvsp[-1].att)->first != -1){
      backpatch((yyvsp[-2].att)->lnext, (yyvsp[-1].att)->first);
    }
    
    label temp = merge((yyvsp[-2].att)->lbreaks, (yyvsp[-1].att)->lbreaks);
    (yyval.att)->lnext = merge(temp, (yyvsp[-1].att)->lnext);
  }
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 379 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();
    int line = insert_code("goto","","","");

    (yyval.att)->first = line;
    (yyval.att)->lbreaks = insert_in_label((yyval.att)->lbreaks, line);
  }
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 387 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    int line = insert_code("print", (yyvsp[-1].att)->id, "", "");

    if((yyvsp[-1].att)->first == -1)
      (yyval.att)->first = line;
    else
      (yyval.att)->first = (yyvsp[-1].att)->first;
  }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 398 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    int line = insert_code("return", (yyvsp[-1].att)->id, "", "");

    if((yyvsp[-1].att)->first == -1)
      (yyval.att)->first = line;
    else
      (yyval.att)->first = (yyvsp[-1].att)->first;
  }
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 409 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();
    int line = insert_code("return", "", "", "");
    (yyval.att)->first = line;
  }
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 414 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = (yyvsp[-1].att);
			}
#line 1901 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 417 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    if((yyvsp[-3].att)->type == (yyvsp[-1].att)->type)
    {

      char *tmp = strdup("=");
      int line = insert_code(tmp, (yyvsp[-1].att)->id, "", (yyvsp[-3].att)->id);
      free(tmp);

      if((yyvsp[-1].att)->first == -1)
        (yyval.att)->first = line;
      else
        (yyval.att)->first = (yyvsp[-1].att)->first;
    } else {
      error("Type mismatch.", yylineno);
    }
  }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 438 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.att) = new_inter_symbol();

	Sym_Table *test_table = table;
	int found = 0;
	
	while(test_table != NULL)
	{
		if(lookup(test_table, (yyvsp[0].cad)) != NULL)
		{
			found = 1;
			break;
		}

		test_table = test_table->parent;
	}

    	if(found)
    	{
      	  //Para el codigo intermedio
      	  strcpy((yyval.att)->id, (yyvsp[0].cad));
    	} else { 
      	  error("ID1 does not exist.", yylineno);
    	}
      }
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 463 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = (yyvsp[0].att);
  }
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 466 "parser.y" /* yacc.c:1646  */
    {
    		(yyval.att) = new_inter_symbol();

		Sym_Table *test_table = table;
		int found = 0;
	
		while(test_table != NULL)
		{
			if(lookup(test_table, (yyvsp[-2].cad)) != NULL)
			{
				found = 1;
				break;
			}
	
			test_table = test_table->parent;
		}

    		if(found)
    		{
		  if(lookup(table, (yyvsp[-2].cad))->type == 5)
		  {
		    //Para el codigo intermedio
    		    sprintf((yyval.att)->id, "%s.%s", (yyvsp[-2].cad), (yyvsp[0].cad));
		  } else {
		    error("ID is not a struct.", yylineno);
		  }
    		} else {
      	  	  error("ID2 does not exist.", yylineno);
    		}

  }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 500 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    Sym_Table *test_table = table;
    int found = 0;
	
    while(test_table != NULL)
    {
	if(lookup(test_table, (yyvsp[-3].cad)) != NULL)
	{
	    found = 1;
	    break;
	}
	
        test_table = test_table->parent;
    }

    if(found)
    {
      //Para el codigo intermedio
      sprintf((yyval.att)->id, "%s[%s]", (yyvsp[-3].cad), (yyvsp[-1].att)->id);
    } else {
      error("ID3 does not exist.", yylineno);
    }
  }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 525 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();

    Sym_Table *test_table = table;
    int found = 0;
	
    printf("looking for %s\n", (yyvsp[-3].att)->id);
    while(test_table != NULL)
    {
	if(lookup(test_table, (yyvsp[-3].att)->id) != NULL)
	{
	    found = 1;
	    break;
	}
	
        test_table = test_table->parent;
    }

    if(found)
    {
      //Para el codigo intermedio
      sprintf((yyval.att)->id, "%s[%s]", (yyvsp[-3].att)->id, (yyvsp[-1].att)->id);
    } else {
      error("ID4 does not exist.", yylineno);
    }
  }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "parser.y" /* yacc.c:1646  */
    {
    char tmp[20];
    sprintf(tmp, "%d", (yyvsp[-1].num));
    strcpy(CODE.code[(yyvsp[0].att)->ltrue.code_lines[(yyvsp[0].att)->ltrue.size-1]].arg2, tmp);
  }
#line 2069 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 559 "parser.y" /* yacc.c:1646  */
    {
    backpatch((yyvsp[-3].att)->ltrue, (yyvsp[-1].att)->first);

    (yyval.att) = new_inter_symbol(); 

    (yyval.att)->first = (yyvsp[-3].att)->ltrue.code_lines[(yyvsp[-3].att)->ltrue.size-1];
    (yyval.att)->lnext = merge((yyvsp[-1].att)->lnext, (yyvsp[-3].att)->lfalse);

    if((yyvsp[0].att)->first != -1){
      backpatch((yyval.att)->lnext, (yyvsp[0].att)->first);
      (yyval.att)->lnext = (yyvsp[0].att)->lnext;
    }

    (yyval.att)->lbreaks = merge((yyvsp[-1].att)->lbreaks, (yyvsp[0].att)->lbreaks);


  }
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 576 "parser.y" /* yacc.c:1646  */
    { (yyval.att) = new_inter_symbol();}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 580 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol(); 
    char temp[10];
    sprintf(temp, "%d", 0);

    int line_true = insert_code("if==", aux_id, temp, "");
    int line_false = insert_code("goto","","","");

    (yyval.att)->ltrue = insert_in_label((yyval.att)->ltrue, line_true);
    (yyval.att)->lfalse = insert_in_label((yyval.att)->lfalse, line_false);
  }
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 595 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = (yyvsp[0].att);
    
  }
#line 2122 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 599 "parser.y" /* yacc.c:1646  */
    {(yyval.att) = new_inter_symbol();}
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 603 "parser.y" /* yacc.c:1646  */
    {
  	int t1 = ((yyvsp[-2].att)->type == 0 || (yyvsp[-2].att)->type == 1 || (yyvsp[-2].att)->type == 2);
	int t2 = ((yyvsp[0].att)->type == 0 || (yyvsp[0].att)->type == 1 || (yyvsp[0].att)->type == 2);

	if(t1 && t2)
	{
	  // Generar codigo intermedio
          char *tmp = strdup("*");
          (yyval.att) = operacion((yyvsp[-2].att), (yyvsp[0].att), tmp);
          free(tmp);
	} else {
	  error("Multiplication needs numeric types.", yylineno);
	}
				}
#line 2147 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 617 "parser.y" /* yacc.c:1646  */
    {
  	int t1 = ((yyvsp[-2].att)->type == 0 || (yyvsp[-2].att)->type == 1 || (yyvsp[-2].att)->type == 2);
	int t2 = ((yyvsp[0].att)->type == 0 || (yyvsp[0].att)->type == 1 || (yyvsp[0].att)->type == 2);

	if(t1 && t2)
	{
	  // Generar codigo intermedio
          char *tmp = strdup("/");
          (yyval.att) = operacion((yyvsp[-2].att), (yyvsp[0].att), tmp);
          free(tmp);
	} else {
	  error("Division needs numeric types.", yylineno);
	}
				}
#line 2166 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 631 "parser.y" /* yacc.c:1646  */
    {
        int t1 = ((yyvsp[-2].att)->type == 0 || (yyvsp[-2].att)->type == 1 || (yyvsp[-2].att)->type == 2);
	int t2 = ((yyvsp[0].att)->type == 0 || (yyvsp[0].att)->type == 1 || (yyvsp[0].att)->type == 2);

	if(t1 && t2)
	{
	  // Generar codigo intermedio
          char *tmp = strdup("+");
          (yyval.att) = operacion((yyvsp[-2].att), (yyvsp[0].att), tmp);
          free(tmp);
	} else {
	  error("Addition needs numeric types.", yylineno);
	}
			}
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 645 "parser.y" /* yacc.c:1646  */
    {
	int t1 = ((yyvsp[-2].att)->type == 0 || (yyvsp[-2].att)->type == 1 || (yyvsp[-2].att)->type == 2);
	int t2 = ((yyvsp[0].att)->type == 0 || (yyvsp[0].att)->type == 1 || (yyvsp[0].att)->type == 2);

	if(t1 && t2)
	{
  	  // Generar codigo intermedio
          char *tmp = strdup("-");
          (yyval.att) = operacion((yyvsp[-2].att), (yyvsp[0].att), tmp);
          free(tmp);
	} else {
	  error("Substraction needs numeric types.", yylineno);
	}
				}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 659 "parser.y" /* yacc.c:1646  */
    {

	if((yyvsp[-2].att)->type == 0 || (yyvsp[0].att)->type == 0)
	{
  	  // Generar codigo intermedio
          char *tmp = strdup("%");
          (yyval.att) = operacion((yyvsp[-2].att), (yyvsp[0].att), tmp);
          free(tmp);
	} else {
	  error("Modulo requires integers.", yylineno);
	}
				}
#line 2221 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 671 "parser.y" /* yacc.c:1646  */
    {
	(yyval.att) = new_inter_symbol();
	(yyval.att)->type = (yyvsp[0].att)->type;

   	//Para el codigo intermedio
    	sprintf((yyval.att)->id, "%s", (yyvsp[0].att)->id);
	}
#line 2233 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 678 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.att) = new_inter_symbol();

    	//Para el codigo intermedio
    	sprintf((yyval.att)->id, "\"%s\"", (yyvsp[0].cad));
  }
#line 2244 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 685 "parser.y" /* yacc.c:1646  */
    {
	(yyval.att) = new_inter_symbol();
	(yyval.att)->type = 0;

   	// Para el codigo intermedio
   	sprintf((yyval.att)->id, "%d", (yyvsp[0].num));
		}
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 692 "parser.y" /* yacc.c:1646  */
    {
	(yyval.att) = new_inter_symbol();
	(yyval.att)->type = 1;

    	// Para el codigo intermedio
    	sprintf((yyval.att)->id, "%f", (yyvsp[0].flo));
		}
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 699 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.att) = new_inter_symbol();
	(yyval.att)->type = 3;

    	//Para el codigo intermedio
    	sprintf((yyval.att)->id, "'%c'", (yyvsp[0].cad));
		}
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 706 "parser.y" /* yacc.c:1646  */
    {
    	// Para el codigo intermedio 
    	// falta hacer el llamado a la funcion aqui
    	(yyval.att) = new_inter_symbol();

    	// Temp
    	char *tmp = get_temporal();

    	int line = insert_code("call", (yyvsp[-3].cad), "", tmp);
    	strcpy((yyval.att)->id, tmp);
    	free(tmp);

    	if((yyvsp[-1].att)->first == -1)
      	  (yyval.att)->first = line;
    	else
      	  (yyval.att)->first = (yyvsp[-1].att)->first;
  }
#line 2302 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 727 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
        int line = insert_code("push", (yyvsp[0].att)->id, "", "");

        if((yyvsp[-2].att)->first != -1)
          (yyval.att)->first = (yyvsp[-2].att)->first;
        else if((yyvsp[0].att)->first != -1)
          (yyval.att)->first = (yyvsp[0].att)->first;
        else
          (yyval.att)->first = line;
				}
#line 2318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 738 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
        int line = insert_code("push", (yyvsp[0].att)->id, "", "");
        
        if((yyvsp[0].att)->first == -1)
          (yyval.att)->first = line;
        else
          (yyval.att)->first = (yyvsp[0].att)->first;

      }
#line 2333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 752 "parser.y" /* yacc.c:1646  */
    {
      (yyval.att) = new_inter_symbol();
      backpatch((yyvsp[-2].att)->lfalse, (yyvsp[0].att)->first);

      // first, ltrue, lfalse
      (yyval.att)->first = (yyvsp[-2].att)->first;
      (yyval.att)->ltrue = merge((yyvsp[-2].att)->ltrue, (yyvsp[0].att)->ltrue);
      (yyval.att)->lfalse = (yyvsp[0].att)->lfalse;

			}
#line 2348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 762 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
      backpatch((yyvsp[-2].att)->ltrue, (yyvsp[0].att)->first);

      // first, ltrue, lfalse
      (yyval.att)->first = (yyvsp[-2].att)->first;
      (yyval.att)->ltrue = (yyvsp[0].att)->ltrue;
      (yyval.att)->lfalse = merge((yyvsp[-2].att)->lfalse, (yyvsp[0].att)->lfalse);
			}
#line 2362 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 771 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
      
      // first, ltrue, lfalse
      (yyval.att)->first = (yyvsp[0].att)->first;
      (yyval.att)->ltrue = (yyvsp[0].att)->lfalse;
      (yyval.att)->lfalse = (yyvsp[0].att)->ltrue;
      
			}
#line 2376 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 780 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = (yyvsp[-1].att);
			}
#line 2384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 783 "parser.y" /* yacc.c:1646  */
    {

    (yyval.att) = new_inter_symbol();

    int t1 = ((yyvsp[-2].att)->type == 0 || (yyvsp[-2].att)->type == 1 || (yyvsp[-2].att)->type == 2);
    int t2 = ((yyvsp[0].att)->type == 0 || (yyvsp[0].att)->type == 1 || (yyvsp[0].att)->type == 2);

    if(t1 && t2)
    {
      char *operacion = strdup("if1234");
      sprintf(operacion, "if%s", (yyvsp[-1].cad));

      int line_true = insert_code(operacion, (yyvsp[-2].att)->id, (yyvsp[0].att)->id, "");
      int line_false = insert_code("goto", "", "", "");

      // first, ltrue, lfalse
      if((yyvsp[-2].att)->first == -1){
        if((yyvsp[0].att)->first == -1){
          (yyval.att)->first = line_true;
        } else {
          (yyval.att)->first = (yyvsp[0].att)->first;
        }
      } else{
        (yyval.att)->first = (yyvsp[-2].att)->first;
      }
    
      (yyval.att)->ltrue = insert_in_label((yyval.att)->ltrue, line_true);
      (yyval.att)->lfalse = insert_in_label((yyval.att)->lfalse, line_false);
    } else {
      error("Operation needs numeric types.", yylineno);
    }

      }
#line 2422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 816 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();
    int line = insert_code("goto", "", "", "");

    // first, ltrue, lfalse
    (yyval.att)->first = line;
    (yyval.att)->ltrue = insert_in_label((yyval.att)->ltrue, line);

  }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 825 "parser.y" /* yacc.c:1646  */
    {
    (yyval.att) = new_inter_symbol();
    int line = insert_code("goto", "", "", "");

    // first, ltrue, lfalse
    (yyval.att)->first = line;
    (yyval.att)->lfalse = insert_in_label((yyval.att)->lfalse, line);
  }
#line 2449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 836 "parser.y" /* yacc.c:1646  */
    {
	strdup("==");
	}
#line 2457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 839 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup("!=");
	}
#line 2465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 842 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup(">=");
	}
#line 2473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 845 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup(">");
	}
#line 2481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 848 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup("<=");
	}
#line 2489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 851 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup("<");
	}
#line 2497 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2501 "parser.tab.c" /* yacc.c:1646  */
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
#line 856 "parser.y" /* yacc.c:1906  */


void yyerror(char *s)
{
	fprintf(stderr, "Error: '%s'. Con el token '%s' en linea %d\n", s, yytext, yylineno);
  exit(1);
}

void error(char *msg, int line)
{
	fprintf(stderr, "Error, line %d: %s\n", line, msg);
}

void init()
{
	table = init_sym_table();
  init_code();
}

symbol *operacion(symbol *arg1, symbol *arg2, char *op){
  symbol *res = new_inter_symbol();

  char *tmp = get_temporal();

  // Codigo intermedio
  int line = insert_code(op, arg1->id, arg2->id, tmp);

  // Valores para compartir
  strcpy(res->id, tmp);

  if(arg1->first != -1)
    res->first = arg1->first;
  else if(arg2->first != -1)
    res->first = arg2->first;
  else 
    res->first = line;

  // Limpiar memoria
  free(tmp);

  return res;
}


char *get_temporal(){
  temp++;
  char tmp[7];
  sprintf(tmp, "%c%d", 't', temp);
  return strdup(tmp);
}


int main(int argc, char** argv){
    if(argc>1){
        yyin = fopen(argv[1], "r");
        if(!yyin) return 1;
        yyparse();
        fclose(yyin);
    }
}
