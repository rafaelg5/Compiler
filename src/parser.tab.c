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

  // Symbol table
  Sym_Table *table; 

  // Aux functions
  void init();
  void error(char *msg, int line);

#line 95 "parser.tab.c" /* yacc.c:339  */

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
#line 32 "parser.y" /* yacc.c:355  */

  char* cad;
  int num;
  double flo;
  struct intermediate_symbol *att;
  struct _GList* list;
  char *id;

#line 179 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
       0,    68,    68,    68,    77,    77,    82,    87,    92,    97,
     102,   107,   112,   112,   132,   143,   156,   162,   171,   172,
     176,   179,   186,   185,   202,   202,   221,   227,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     249,   253,   254,   255,   259,   260,   264,   265,   269,   270,
     274,   277,   280,   283,   286,   289,   293,   295,   299,   303,
     306,   311,   314,   321,   324,   327,   330,   333,   334,   335,
     339,   342,   345,   348,   351,   354
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
  "type_arr", "funcs", "params", "param_list", "$@4", "$@5", "param_arr",
  "sents", "ids", "arrays", "cases", "case_def", "expression", "arguments",
  "logical", "relation", YY_NULLPTR
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

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -63,    35,   268,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
      14,   -63,    -1,   268,   -63,    30,   268,    36,    -5,    58,
       6,    16,    67,   -63,   268,    52,   -63,   268,    46,   -63,
      -5,   -63,    53,    62,    -5,   -63,    83,    69,   268,   -63,
      82,   268,   -63,    66,   -63,   218,    93,    82,    84,    80,
      87,    89,   218,    92,    12,    74,   -19,   218,   121,    81,
     100,    82,   -63,    74,   -63,   218,    63,   235,    63,   -63,
     -63,   -63,   -63,   -37,   -63,   -63,   275,   282,    74,   120,
     139,    14,   218,    74,    74,   -63,   230,   154,   -63,   -63,
      63,    63,   253,   -15,   102,    76,    74,    74,    74,    74,
      74,    74,   -63,   -63,   258,   -63,   -63,   -63,   289,   263,
     108,    63,   211,   -29,   -63,   -63,   -63,   -63,   -63,   -63,
      74,    63,    63,   218,    63,   218,   296,    21,   269,   269,
     299,   -63,   -63,   -63,   -63,   -63,   144,    23,   -63,   296,
     -63,   129,   171,   231,   218,    74,   -63,   101,   152,   218,
     218,   186,   296,   160,   124,   135,   106,   218,   -63,   218,
     218,   -63,   218,   203,   218,   218,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     7,     9,     8,    10,    11,    12,
      19,     4,     0,     0,     3,     0,     6,     0,    17,     0,
       0,     0,     0,    15,     6,     0,    13,    21,     0,     5,
      17,    24,     0,    20,    17,    14,     0,     0,     0,    16,
      27,     6,    22,     0,    25,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      42,    27,    26,     0,    35,     0,     0,     0,     0,    59,
      57,    58,    56,    41,    38,    55,     0,     0,     0,     0,
       0,    19,    28,     0,     0,    23,     0,     0,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    36,     0,    43,    39,    18,     0,     0,
       0,     0,     0,    65,    74,    72,    70,    71,    73,    75,
       0,     0,     0,     0,     0,     0,    62,     0,    52,    53,
      54,    50,    51,    44,    40,    45,    47,     0,    66,    67,
      64,    63,    32,     0,    31,     0,    60,     0,    49,     0,
       0,     0,    61,     0,     0,     0,     0,    33,    30,     0,
       0,    34,     0,    47,    48,    29,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,    -8,   -63,    13,   -63,   -63,    57,    99,
     -63,   -63,   -63,   -63,   -42,   -45,   -53,   -63,    10,   -63,
      -2,   -63,   -62,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    15,    11,    12,    19,    23,    14,
      32,    33,    46,    36,    44,    82,    59,    60,   148,   155,
      92,   127,    93,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    75,    75,   121,   122,    62,    95,    67,    20,    78,
      75,    96,    80,    75,    79,    75,    29,   121,   122,    85,
      87,    69,    70,    71,    72,    75,    17,    78,   112,   113,
      75,    75,    79,    45,   123,     3,    13,    75,    75,    73,
      31,    22,    16,    75,    75,    75,    75,    75,    75,   137,
      26,    42,    76,    77,    74,   121,   122,    18,    75,   140,
     141,    86,   143,    21,    27,   149,   145,    75,    75,    75,
     146,    75,    69,    70,    71,    72,   104,    28,   142,    30,
     144,   108,   109,    69,    70,    71,    72,    35,    88,    89,
      73,    39,    75,    34,   126,   128,   129,   130,   131,   132,
      24,    73,    37,    25,   156,   157,   144,    38,   121,   122,
      40,    90,    41,    47,   163,   164,    91,   165,   139,    48,
      61,    49,    64,    50,    51,   125,    52,    53,    43,    54,
      55,    83,    63,    56,    48,    65,    49,    66,    50,    51,
      68,    52,    53,   152,    54,    55,    84,   105,    56,    57,
     124,   136,    48,   153,    49,   162,    50,    51,   147,    52,
      53,   121,    54,    55,    57,    81,    56,    48,   154,    49,
     159,    50,    51,   166,    52,    53,   160,    54,    55,   161,
     107,    56,    57,   106,    48,     0,    49,     0,    50,    51,
     150,    52,    53,     0,    54,    55,   111,    57,    56,    48,
       0,    49,     0,    50,    51,     0,    52,    53,     0,    54,
      55,     0,     0,    56,    57,     0,    48,   147,    49,     0,
      50,    51,     0,    52,    53,     0,    54,    55,   158,    57,
      56,    48,     0,    49,     0,    50,    51,     0,    52,    53,
       0,    54,    55,   121,   122,    56,    57,     0,    48,     0,
      49,     0,    50,    51,     0,    52,    94,     0,    54,    55,
     138,    57,    56,   121,   122,     0,    97,    98,    99,   100,
     101,     4,     5,     6,     7,     8,     9,     0,    57,   110,
     151,   114,   115,   116,   117,     0,     0,   118,   119,    97,
      98,    99,   100,   101,    97,    98,    99,   100,   101,    97,
      98,    99,   100,   101,     0,   133,     0,    99,   100,   101,
     135,    97,    98,    99,   100,   101,     0,   102,    97,    98,
      99,   100,   101,     0,   103,    97,    98,    99,   100,   101,
       0,   134,    97,    98,    99,   100,   101,    -1,   100,   101
};

static const yytype_int16 yycheck[] =
{
      45,    54,    55,    32,    33,    47,    68,    52,    16,    46,
      63,    48,    57,    66,    51,    68,    24,    32,    33,    61,
      65,     9,    10,    11,    12,    78,    13,    46,    90,    91,
      83,    84,    51,    41,    49,     0,    22,    90,    91,    27,
      27,    46,    43,    96,    97,    98,    99,   100,   101,   111,
      44,    38,    54,    55,    42,    32,    33,    27,   111,   121,
     122,    63,   124,    27,    48,    42,    45,   120,   121,   122,
      49,   124,     9,    10,    11,    12,    78,    10,   123,    27,
     125,    83,    84,     9,    10,    11,    12,    30,    25,    26,
      27,    34,   145,    47,    96,    97,    98,    99,   100,   101,
      42,    27,    49,    45,   149,   150,   151,    45,    32,    33,
      27,    48,    43,    47,   159,   160,    53,   162,   120,    13,
      27,    15,    42,    17,    18,    49,    20,    21,    46,    23,
      24,    50,    48,    27,    13,    48,    15,    48,    17,    18,
      48,    20,    21,   145,    23,    24,    46,    27,    27,    43,
      48,    43,    13,    52,    15,    49,    17,    18,    14,    20,
      21,    32,    23,    24,    43,    44,    27,    13,    16,    15,
      10,    17,    18,   163,    20,    21,    52,    23,    24,    44,
      81,    27,    43,    44,    13,    -1,    15,    -1,    17,    18,
      19,    20,    21,    -1,    23,    24,    42,    43,    27,    13,
      -1,    15,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    -1,    27,    43,    -1,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    42,    43,
      27,    13,    -1,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    32,    33,    27,    43,    -1,    13,    -1,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      49,    43,    27,    32,    33,    -1,    36,    37,    38,    39,
      40,     3,     4,     5,     6,     7,     8,    -1,    43,    49,
      49,    28,    29,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    36,    37,    38,    39,    40,    36,
      37,    38,    39,    40,    -1,    47,    -1,    38,    39,    40,
      47,    36,    37,    38,    39,    40,    -1,    42,    36,    37,
      38,    39,    40,    -1,    42,    36,    37,    38,    39,    40,
      -1,    42,    36,    37,    38,    39,    40,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,     7,     8,
      57,    59,    60,    22,    63,    58,    43,    59,    27,    61,
      57,    27,    46,    62,    42,    45,    44,    48,    10,    57,
      27,    59,    64,    65,    47,    62,    67,    49,    45,    62,
      27,    43,    59,    46,    68,    57,    66,    47,    13,    15,
      17,    18,    20,    21,    23,    24,    27,    43,    69,    70,
      71,    27,    68,    48,    42,    48,    48,    69,    48,     9,
      10,    11,    12,    27,    42,    70,    74,    74,    46,    51,
      69,    44,    69,    50,    46,    68,    74,    69,    25,    26,
      48,    53,    74,    76,    21,    76,    48,    36,    37,    38,
      39,    40,    42,    42,    74,    27,    44,    63,    74,    74,
      49,    42,    76,    76,    28,    29,    30,    31,    34,    35,
      77,    32,    33,    49,    48,    49,    74,    75,    74,    74,
      74,    74,    74,    47,    42,    47,    43,    76,    49,    74,
      76,    76,    69,    76,    69,    45,    49,    14,    72,    42,
      19,    49,    74,    52,    16,    73,    69,    69,    42,    10,
      52,    44,    49,    69,    69,    69,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    56,    55,    58,    57,    57,    59,    59,    59,
      59,    59,    60,    59,    61,    61,    62,    62,    63,    63,
      64,    64,    66,    65,    67,    65,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     5,     0,     1,     1,     1,
       1,     1,     0,     5,     4,     2,     4,     0,    11,     0,
       1,     0,     0,     6,     0,     4,     3,     0,     2,     9,
       7,     5,     5,     7,     8,     2,     3,     3,     2,     3,
       4,     1,     1,     3,     4,     4,     5,     0,     3,     0,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       4,     3,     1,     3,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 68 "parser.y" /* yacc.c:1646  */
    {
  init();
  }
#line 1418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "parser.y" /* yacc.c:1646  */
    {
	inh_type = (yyvsp[0].att)->type;
	inh_dim = (yyvsp[0].att)->dim;
	}
#line 1427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 87 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = 0;
		(yyval.att)->dim = 4;
		}
#line 1437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 1;
            	(yyval.att)->dim = 4;
           	}
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "parser.y" /* yacc.c:1646  */
    {
            	(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 2;
            	(yyval.att)->dim = 8;
            	}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "parser.y" /* yacc.c:1646  */
    {
            	(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 3;
            	(yyval.att)->dim = 1;
            	}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "parser.y" /* yacc.c:1646  */
    {
            	(yyval.att) = new_inter_symbol();
            	(yyval.att)->type = 4;
            	(yyval.att)->dim = 0;
            	}
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 112 "parser.y" /* yacc.c:1646  */
    {
		// Create a new table and link it to the current one
  		Sym_Table *new_table; 
		new_table = init_sym_table();
		new_table->parent = table;
		table->child = new_table;
		table = new_table;
		}
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "parser.y" /* yacc.c:1646  */
    {
		Sym_Table *prev = table;
		table = table->parent;
		
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = 5;
		(yyval.att)->dim = prev->size;
		}
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "parser.y" /* yacc.c:1646  */
    {
		if(lookup(table, (yyvsp[-1].cad)) == NULL)
		{
			insert(table, (yyvsp[-1].cad), (yyvsp[0].att)->type, address, (yyvsp[0].att)->dim);
			address += (yyvsp[0].att)->dim;
		} else {
			error("ID defined twice.", yylineno);
		}
		}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "parser.y" /* yacc.c:1646  */
    {
		if(lookup(table, (yyvsp[-1].cad)) == NULL)
		{
			insert(table, (yyvsp[-1].cad), (yyvsp[0].att)->type, address, (yyvsp[0].att)->dim);
			address += (yyvsp[0].att)->dim;
		} else {
			error("ID defined twice.", yylineno);
		}
		}
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = (yyvsp[0].att);
				(yyval.att)->is_arr = 1;
				(yyval.att)->type = (yyvsp[0].att)->type;
				(yyval.att)->dim = (yyvsp[-2].num) * (yyvsp[0].att)->dim;
				}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				(yyval.att)->type = inh_type;
				(yyval.att)->dim = inh_dim;
				}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "parser.y" /* yacc.c:1646  */
    {
		(yyval.list) = (yyvsp[0].list);
		}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "parser.y" /* yacc.c:1646  */
    {
		(yyval.list) = NULL;
		}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "parser.y" /* yacc.c:1646  */
    {
		inh_type = (yyvsp[0].att)->type;
		inh_dim = (yyvsp[0].att)->dim;
		}
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 190 "parser.y" /* yacc.c:1646  */
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
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 202 "parser.y" /* yacc.c:1646  */
    {
		inh_type = (yyvsp[0].att)->type;
		inh_dim = (yyvsp[0].att)->dim;
		}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 206 "parser.y" /* yacc.c:1646  */
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
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 221 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
			(yyval.att)->dim = 8;
			(yyval.att)->is_arr = 1;
			(yyval.att)->type = (yyvsp[0].att)->type;
			}
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 227 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = inh_type;
		(yyval.att)->dim = inh_dim;
		}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 235 "parser.y" /* yacc.c:1646  */
    {}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 236 "parser.y" /* yacc.c:1646  */
    {}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 237 "parser.y" /* yacc.c:1646  */
    {}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 238 "parser.y" /* yacc.c:1646  */
    {}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 239 "parser.y" /* yacc.c:1646  */
    {}
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 240 "parser.y" /* yacc.c:1646  */
    {}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 241 "parser.y" /* yacc.c:1646  */
    {}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 242 "parser.y" /* yacc.c:1646  */
    {}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 243 "parser.y" /* yacc.c:1646  */
    {}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 244 "parser.y" /* yacc.c:1646  */
    {}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 245 "parser.y" /* yacc.c:1646  */
    {}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 246 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = (yyvsp[-1].att);
			}
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "parser.y" /* yacc.c:1646  */
    {}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 253 "parser.y" /* yacc.c:1646  */
    {}
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 254 "parser.y" /* yacc.c:1646  */
    {}
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 255 "parser.y" /* yacc.c:1646  */
    {}
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 259 "parser.y" /* yacc.c:1646  */
    {}
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 260 "parser.y" /* yacc.c:1646  */
    {}
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 264 "parser.y" /* yacc.c:1646  */
    {}
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 265 "parser.y" /* yacc.c:1646  */
    {}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 269 "parser.y" /* yacc.c:1646  */
    {}
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 270 "parser.y" /* yacc.c:1646  */
    {}
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 274 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 277 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				}
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 283 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				}
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 286 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				}
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "parser.y" /* yacc.c:1646  */
    {
	(yyval.att) = new_inter_symbol();
	(yyval.att)->type = (yyvsp[0].att)->type;
	}
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 293 "parser.y" /* yacc.c:1646  */
    {}
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 295 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = 0;
		}
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 299 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att) = new_inter_symbol();
		(yyval.att)->type = 1;
		}
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "parser.y" /* yacc.c:1646  */
    {
		(yyval.att)->type = 3;
		}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 306 "parser.y" /* yacc.c:1646  */
    {}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 311 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
				}
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 314 "parser.y" /* yacc.c:1646  */
    {
				(yyval.att) = new_inter_symbol();
          			}
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 321 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
			}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 324 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
			}
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 327 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = new_inter_symbol();
			}
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 330 "parser.y" /* yacc.c:1646  */
    {
			(yyval.att) = (yyvsp[-1].att);
			}
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 333 "parser.y" /* yacc.c:1646  */
    {}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 334 "parser.y" /* yacc.c:1646  */
    {}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 335 "parser.y" /* yacc.c:1646  */
    {}
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 339 "parser.y" /* yacc.c:1646  */
    {
	strdup("==");
	}
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 342 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup("!=");
	}
#line 1944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 345 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup(">=");
	}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 348 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup(">");
	}
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 351 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup("<=");
	}
#line 1968 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 354 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cad) = strdup("<");
	}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1980 "parser.tab.c" /* yacc.c:1646  */
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
#line 359 "parser.y" /* yacc.c:1906  */


void yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
}

void error(char *msg, int line)
{
	fprintf(stderr, "Error, line %d: %s\n", line, msg);
}

void init()
{
	table = init_sym_table();
}

int main(int argc, char** argv){
    if(argc>1){
        yyin = fopen(argv[1], "r");
        if(!yyin) return 1;
        yyparse();
        fclose(yyin);
    }
}
