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
#line 1 "lab9.y" /* yacc.c:339  */


/*  Matthew Groover 
    3-2-20 - 3-27-20
 *  this y file defines the algol-c language for 
    our ast and later use for the whole compiler [21~



     may-4 - may-8 2020
    added create temp and fprint f structures 
    to generate mips code 
*/


	/* begin specs */
#include "ast.h"
#include <stdio.h>
#include <ctype.h>
#include  <stdlib.h>
#include "symtable.h"  
#include "emit.h"
   
  extern int linecount;  /*imports the linecount from lex */
  extern int mydebug;
  ASTnode *worldpointer;
  
  int level=0; /* the level of compund statments */

  int offset =0; // current offset
                 //offset is measured in words

  int goffset;

  int maxoffset; // holds the maximum amount of memory required for a function

  
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d \n", s,linecount);
}

 

int yylex();
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

#line 115 "y.tab.c" /* yacc.c:339  */

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
    ID = 258,
    NUM = 259,
    INT = 260,
    VOID = 261,
    BOOLEAN = 262,
    MYBEGIN = 263,
    END = 264,
    IF = 265,
    THEN = 266,
    ELSE = 267,
    WHILE = 268,
    DO = 269,
    MYRETURN = 270,
    READ = 271,
    WRITE = 272,
    LE = 273,
    LT = 274,
    GE = 275,
    GT = 276,
    EE = 277,
    NE = 278,
    AND = 279,
    OR = 280,
    TRUE = 281,
    FALSE = 282,
    NOT = 283,
    STRING = 284
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define INT 260
#define VOID 261
#define BOOLEAN 262
#define MYBEGIN 263
#define END 264
#define IF 265
#define THEN 266
#define ELSE 267
#define WHILE 268
#define DO 269
#define MYRETURN 270
#define READ 271
#define WRITE 272
#define LE 273
#define LT 274
#define GE 275
#define GT 276
#define EE 277
#define NE 278
#define AND 279
#define OR 280
#define TRUE 281
#define FALSE 282
#define NOT 283
#define STRING 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "lab9.y" /* yacc.c:355  */

int number;
char *string;
struct ASTNODEtype *node; 
 enum DATATYPE dtype;      /*global types to handle operators and nodes */
enum NODETYPE type;
 enum OPERATOR optype;

#line 222 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 239 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      34,    35,    39,    37,    33,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    99,   100,   106,   107,   109,   119,   130,
     151,   174,   195,   197,   199,   202,   213,   202,   239,   240,
     242,   243,   245,   267,   293,   293,   293,   307,   308,   313,
     314,   321,   322,   323,   324,   325,   326,   327,   328,   330,
     334,   336,   343,   351,   357,   360,   365,   370,   374,   380,
     397,   401,   418,   436,   437,   459,   460,   461,   462,   463,
     464,   468,   469,   489,   490,   493,   494,   510,   511,   512,
     513,   516,   517,   521,   522,   523,   527,   531,   544,   567,
     568,   571,   578
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "INT", "VOID", "BOOLEAN",
  "MYBEGIN", "END", "IF", "THEN", "ELSE", "WHILE", "DO", "MYRETURN",
  "READ", "WRITE", "LE", "LT", "GE", "GT", "EE", "NE", "AND", "OR", "TRUE",
  "FALSE", "NOT", "STRING", "';'", "'['", "']'", "','", "'('", "')'",
  "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "program", "decl", "dec",
  "vardec", "varlist", "typespec", "fundec", "$@1", "$@2", "params",
  "paramlist", "param", "compstat", "$@3", "$@4", "localdec", "statlist",
  "statement", "expressstat", "selectionstat", "iterstat", "returstat",
  "readstat", "writestat", "assignstat", "expression", "var", "simpleexp",
  "relop", "addexp", "addop", "term", "mulop", "factor", "call", "args",
  "arglist", YY_NULLPTR
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
      59,    91,    93,    44,    40,    41,    61,    43,    45,    42,
      47
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      73,   -99,   -99,   -99,    26,   -99,    73,   -99,    35,   -99,
     -99,   -99,     3,    12,    45,    53,   -99,   -99,    27,    -6,
     -99,    78,    67,    25,    98,   -99,   -99,    70,    53,    50,
      71,    73,   -99,    72,    94,   -99,   -99,   -99,   -99,    73,
      73,    53,     5,   -99,   -17,   -99,    48,    48,    20,   102,
      37,   -99,   -99,    48,   -99,    48,   -99,    99,     5,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,    77,    74,    75,     7,
      33,   -99,   -99,    48,    48,   100,   -99,    95,   -99,    82,
      83,    85,    86,    87,   -99,    84,   -99,   -99,   -99,    48,
     -99,   -99,   -99,   -99,   -99,   -99,    48,   -99,   -99,    48,
     -99,   -99,   -99,   -99,    48,    81,    88,    89,   -99,     5,
       5,   -99,   -99,   -99,   -99,   -99,   -99,    69,     7,    33,
     -99,   -99,    48,   -99,   106,   -99,   -99,   -99,     5,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,    15,     7,     0,     8,
      10,     0,     9,    13,     0,    16,    19,    20,     0,    22,
       0,     0,    11,     0,     0,    21,    23,    24,    17,    27,
      27,     0,    29,    28,    51,    72,     0,     0,     0,     0,
       0,    75,    76,     0,    40,     0,    32,     0,    29,    31,
      33,    34,    36,    37,    38,    35,     0,    73,    50,    53,
      61,    65,    74,     0,    79,     0,    73,     0,    44,     0,
      51,     0,     0,     0,    77,     0,    25,    30,    39,     0,
      55,    56,    58,    57,    59,    60,     0,    63,    64,     0,
      69,    70,    67,    68,     0,     0,    81,     0,    80,     0,
       0,    45,    46,    48,    47,    71,    26,     0,    54,    62,
      66,    52,     0,    78,    41,    43,    49,    82,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   114,   -99,    30,    -9,    22,   -99,   -99,   -99,
     -99,    91,   -99,    92,   -99,   -99,    90,    65,   -98,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -45,   -42,    36,   -99,
      31,   -99,    29,   -99,   -49,   -99,   -99,     9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    21,    30,
      25,    26,    27,    56,    39,   116,    42,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    76,    68,    96,
      69,    99,    70,   104,    71,    72,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    75,    77,    79,    84,    83,    20,    81,    44,    45,
      85,   124,   125,    37,    73,    46,    67,    74,    47,    32,
      48,    49,    50,    44,    45,    14,    10,    15,   105,   106,
     129,    51,    52,    53,    14,    54,    15,    16,    12,    55,
      44,    45,    17,    24,    97,    98,    51,    52,    53,    18,
      78,    44,    45,    24,    55,   120,    19,   100,   101,    22,
     -18,    41,    41,    51,    52,    53,    82,    67,    67,    40,
      40,    55,   102,   103,    51,    52,    53,   106,     1,     2,
       3,    33,    55,     1,    23,     3,    67,    90,    91,    92,
      93,    94,    95,    90,    91,    92,    93,    94,    95,   126,
      28,    29,    37,    31,    36,    80,    34,    88,    86,   110,
      89,   109,   111,   121,    73,   112,   113,   114,   128,   115,
      11,   122,    35,    87,   123,   117,    38,   118,   119,     0,
      43,   127
};

static const yytype_int16 yycheck[] =
{
      42,    46,    47,    48,    53,    50,    15,    49,     3,     4,
      55,   109,   110,     8,    31,    10,    58,    34,    13,    28,
      15,    16,    17,     3,     4,    31,     0,    33,    73,    74,
     128,    26,    27,    28,    31,    30,    33,    34,     3,    34,
       3,     4,    30,    21,    37,    38,    26,    27,    28,     4,
      30,     3,     4,    31,    34,   104,     3,    24,    25,    32,
      35,    39,    40,    26,    27,    28,    29,   109,   110,    39,
      40,    34,    39,    40,    26,    27,    28,   122,     5,     6,
       7,    31,    34,     5,     6,     7,   128,    18,    19,    20,
      21,    22,    23,    18,    19,    20,    21,    22,    23,    30,
      33,     3,     8,    33,    32,     3,    35,    30,     9,    14,
      36,    11,    30,    32,    31,    30,    30,    30,    12,    35,
       6,    33,    31,    58,    35,    89,    34,    96,    99,    -1,
      40,   122
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    42,    43,    44,    45,    47,    48,
       0,    43,     3,    46,    31,    33,    34,    30,     4,     3,
      46,    49,    32,     6,    47,    51,    52,    53,    33,     3,
      50,    33,    46,    31,    35,    52,    32,     8,    54,    55,
      45,    47,    57,    57,     3,     4,    10,    13,    15,    16,
      17,    26,    27,    28,    30,    34,    54,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    71,
      73,    75,    76,    31,    34,    67,    68,    67,    30,    67,
       3,    68,    29,    67,    75,    67,     9,    58,    30,    36,
      18,    19,    20,    21,    22,    23,    70,    37,    38,    72,
      24,    25,    39,    40,    74,    67,    67,    77,    78,    11,
      14,    30,    30,    30,    30,    35,    56,    69,    71,    73,
      75,    32,    33,    35,    59,    59,    30,    78,    12,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    46,    47,    47,    47,    49,    50,    48,    51,    51,
      52,    52,    53,    53,    55,    56,    54,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    64,    65,    65,    66,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    76,    77,
      77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     2,     4,     0,     0,     6,     0,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     6,     4,     2,     3,     3,     3,     3,     4,
       1,     1,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     4,     0,
       1,     1,     3
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
#line 97 "lab9.y" /* yacc.c:1646  */
    { worldpointer = (yyvsp[0].node); }
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.node)=(yyvsp[-1].node);
                (yyvsp[-1].node)->next = (yyvsp[0].node);  /*assigns the next dec to its pointer next */
               
              }
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 106 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "lab9.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[-1].node);    
                            ASTnode *p;
                             p = (yyval.node);       
			     while(p!=NULL){
                               p->datatype =  (yyvsp[-2].dtype);
			       Search(p->Name,level,0)->Type = (yyvsp[-2].dtype);
			       p=p->s1;
			     }
                           }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "lab9.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(vardec);                                                                                                                                                                                                                   (yyval.node)->Name = (yyvsp[0].string);
  (yyval.node)->size =1;                                                                                                                                                                                                                                 if(Search((yyvsp[0].string),level,0) != NULL){                                                                                                                                                                                                                yyerror("duplicate declaration \n");
    yyerror((yyvsp[0].string));
    exit(1);                                                                                                                                                                                                                                   }                                                                                                                                                                                                                                            else{
    (yyval.node)->symbol=Insert((yyvsp[0].string),-1,0,level,1,offset,NULL);                                                                                                                                                                                              /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
																														   Tnode * fparms ); */
    offset = offset +1;
    Display();
  }
  }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "lab9.y" /* yacc.c:1646  */
    { // fprintf(stderr,"there is a num it is %d \n",$3);


  (yyval.node)=ASTCreateNode(vardec);
  (yyval.node)->Name = (yyvsp[-3].string);
  (yyval.node)->size = (yyvsp[-1].number);

  if(Search((yyvsp[-3].string),level,0) != NULL){
    yyerror("duplicate declaration \n");
    yyerror((yyvsp[-3].string));
    exit(1);
  }
  else{

    (yyval.node)->symbol=Insert((yyvsp[-3].string),-1,2,level,(yyvsp[-1].number),offset,NULL);
    /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
      Tnode * fparms ); */
    offset = offset + (yyvsp[-1].number);
    Display();
  }
 }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 151 "lab9.y" /* yacc.c:1646  */
    {


  (yyval.node)=ASTCreateNode(vardec);  /*these handle all variable declarations varlist recusively points at itself hence the null handle */
  (yyval.node)->Name = (yyvsp[-2].string);
  (yyval.node)->s1 = (yyvsp[0].node);
  (yyval.node)->size =1;

  if(Search((yyvsp[-2].string),level,0) != NULL){
    yyerror("duplicate declaration \n");
    yyerror((yyvsp[-2].string));
    exit(1);
  }
  else{

    (yyval.node)->symbol=Insert((yyvsp[-2].string),-1,0,level,1,offset,NULL);
    /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
      Tnode * fparms ); */
    offset = offset +1;
  }

 }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 174 "lab9.y" /* yacc.c:1646  */
    {

  (yyval.node)=ASTCreateNode(vardec);
  (yyval.node)->Name = (yyvsp[-5].string);
  (yyval.node)->size = (yyvsp[-3].number);
  (yyval.node)->s1 = (yyvsp[0].node);
  if(Search((yyvsp[-5].string),level,0) != NULL){
    yyerror("duplicate declaration \n");
    yyerror((yyvsp[-5].string));
    exit(1);
  }
  else{

    (yyval.node)->symbol= Insert((yyvsp[-5].string),-1,2,level,(yyvsp[-3].number),offset,NULL);
    /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
      Tnode * fparms ); */
    offset = offset +(yyvsp[-3].number);
  }

 }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 195 "lab9.y" /* yacc.c:1646  */
    {(yyval.dtype)=inttype;
  }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 197 "lab9.y" /* yacc.c:1646  */
    {(yyval.dtype) = voidtype;
        }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 199 "lab9.y" /* yacc.c:1646  */
    {(yyval.dtype) = booltype;
	 }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "lab9.y" /* yacc.c:1646  */
    {
  if(Search((yyvsp[-1].string),level,0) != NULL){
    yyerror("duplicate function declaration \n");
    yyerror((yyvsp[-2].dtype));
    exit(1);
  }
  
  goffset = offset;
  offset =2;
  maxoffset =offset;

  }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 213 "lab9.y" /* yacc.c:1646  */
    {
    
    goffset +=1; //inserts function
    Display();

   }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 218 "lab9.y" /* yacc.c:1646  */
    {
  
          (yyval.node) = ASTCreateNode(fundec);
          (yyval.node)->symbol=Insert((yyvsp[-6].string), (yyvsp[-7].dtype), 1, level, 1,goffset, (yyvsp[-3].node) );
          (yyval.node)->Name = (yyvsp[-6].string);
          (yyval.node)->s1 = (yyvsp[-3].node);                  
          (yyval.node)->s2 = (yyvsp[0].node);
          (yyval.node)->datatype = (yyvsp[-7].dtype);
	  offset = goffset;

	  //  if(offset>maxoffset){
	  // maxoffset = offset;
	  //}
          
	  
	  (yyval.node)->symbol->mysize = maxoffset;
	  (yyval.node)->size = maxoffset;

          
      }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 239 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 240 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 242 "lab9.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 243 "lab9.y" /* yacc.c:1646  */
    { (yyval.node)=(yyvsp[-2].node); (yyvsp[-2].node)->next = (yyvsp[0].node);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 245 "lab9.y" /* yacc.c:1646  */
    {  
    (yyval.node) = ASTCreateNode(params);
    (yyval.node)->Name = (yyvsp[0].string);
    (yyval.node)->size =1;
    (yyval.node)->datatype = (yyvsp[-1].dtype);
    (yyval.node)->semtype = (yyvsp[-1].dtype);

    if(Search((yyvsp[0].string),level+1,0) != NULL){
      yyerror("duplicate declaration \n");
      yyerror((yyvsp[0].string));
      exit(1);
    }
    else{

      (yyval.node)->symbol=Insert((yyvsp[0].string),(yyvsp[-1].dtype),0,level+1,1,offset,NULL);                                                                                                                                                                                            /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
																														     Tnode * fparms ); */
      offset+=1;
      Display();

    }

  }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 267 "lab9.y" /* yacc.c:1646  */
    {


  (yyval.node) = ASTCreateNode(params);
  (yyval.node)->Name = (yyvsp[-2].string);
  (yyval.node)->size = 2;
  (yyval.node)->datatype = (yyvsp[-3].dtype);


  if(Search((yyvsp[-2].string),level+1,0) != NULL){
    yyerror("duplicate declaration \n");
    yyerror((yyvsp[-2].string));                                                                                                                                                                                                        \

    exit(1);
  }
  else{

    (yyval.node)->symbol=Insert((yyvsp[-2].string),(yyvsp[-3].dtype),2,level+1,1,offset,NULL);
    /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
      Tnode * fparms ); */
    offset = offset +1;
    Display();                                                                                                                                                                                                          \
  }

  }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 293 "lab9.y" /* yacc.c:1646  */
    {level +=1;}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "lab9.y" /* yacc.c:1646  */
    { 

  if(offset>maxoffset){
    maxoffset = offset;
  }
  offset-=Delete(level);
   level=level-1;
 }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 300 "lab9.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(comp);
         (yyval.node)->s1 = (yyvsp[-3].node);
         (yyval.node)->s2 = (yyvsp[-2].node);
	 // Display();
        }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 307 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 308 "lab9.y" /* yacc.c:1646  */
    {  /*handle local variable declaration within a compound statment */
	  (yyvsp[-1].node)->next=(yyvsp[0].node);(yyval.node)=(yyvsp[-1].node);
	  
          }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 313 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 314 "lab9.y" /* yacc.c:1646  */
    {  
  if((yyvsp[-1].node)==NULL){
    (yyval.node)=(yyvsp[0].node);             /*statlist recursively handles itself so we check against null to prevent seg faults*/
  }
  (yyvsp[-1].node)->next = (yyvsp[0].node); (yyval.node)=(yyvsp[-1].node); 
  }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 321 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 322 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 323 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 324 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 325 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 326 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 327 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 328 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 330 "lab9.y" /* yacc.c:1646  */
    {
  (yyval.node)= ASTCreateNode(exprstmt);
  (yyval.node)->s1 = (yyvsp[-1].node);
            }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 334 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 336 "lab9.y" /* yacc.c:1646  */
    {
              (yyval.node)=ASTCreateNode(iff);
	      (yyval.node)->s2 = ASTCreateNode(iffbody);  /* we create a node for the statment then body of the if */
              (yyval.node)->s1 = (yyvsp[-2].node);
	      (yyval.node)->s2->s1 = (yyvsp[0].node);
	      (yyval.node)->s2->s2 = NULL;
              }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 343 "lab9.y" /* yacc.c:1646  */
    {
	       (yyval.node)=ASTCreateNode(iff);
	       (yyval.node)->s2 = ASTCreateNode(iffbody); /*the s2 of the body if is only initialized if we have an else */
               (yyval.node)->s1 = (yyvsp[-4].node);
               (yyval.node)->s2->s1 = (yyvsp[-2].node);
	       (yyval.node)->s2->s2 = (yyvsp[0].node);
              }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 351 "lab9.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(loop);    /*handles the while do statments */
	   (yyval.node)->s1 = (yyvsp[-2].node);
	   (yyval.node)->s2 = (yyvsp[0].node);
         }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 357 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =ASTCreateNode(RET);
   (yyval.node)->s1 = NULL;
         }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 360 "lab9.y" /* yacc.c:1646  */
    {
           (yyval.node) = ASTCreateNode(RET);
           (yyval.node)->s1 = (yyvsp[-1].node);
         }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 365 "lab9.y" /* yacc.c:1646  */
    {
         (yyval.node) = ASTCreateNode(RED); /*handles the read */
         (yyval.node)->s1 = (yyvsp[-1].node);
	 }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 370 "lab9.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(WRIT); /*handles write statments */
	  (yyval.node)->s1 = (yyvsp[-1].node);
          }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 375 "lab9.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(WRIT); /*handles write statments */
	   (yyval.node)->Name = (yyvsp[-1].string);
	   (yyval.node)->label = genlabel();
	 }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 380 "lab9.y" /* yacc.c:1646  */
    {
  if((yyvsp[-3].node)->semtype != (yyvsp[-1].node)->semtype){
    yyerror("type mismatch on assignment \n");
    exit(1);
  }
            
          (yyval.node) = ASTCreateNode(assign); /*assignment statement handle */
          (yyval.node)->s1 = (yyvsp[-3].node);
	  (yyval.node)->s2 = (yyvsp[-1].node);
	  (yyval.node)->Name=CreateTemp();
	  (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);
	  offset++;
          }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 397 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 401 "lab9.y" /* yacc.c:1646  */
    { struct SymbTab* search = Search((yyvsp[0].string),level,1);
    if(search == NULL ){
      yyerror("variable does not exist \n");
      yyerror((yyvsp[0].string));
      exit(1);
    }
    if(search->IsAFunc !=0){
      yyerror("needs to be a scalar \n");
      yyerror((yyvsp[0].string));
      exit(1);
    }
         (yyval.node)=ASTCreateNode(VAR); /*this is a leaf it often should not have anyone other nodes */
         (yyval.node)->Name = (yyvsp[0].string);
	 (yyval.node)->symbol = search;
	 (yyval.node)->semtype = search->Type;
	 (yyval.node)->s1 = NULL;
     }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 418 "lab9.y" /* yacc.c:1646  */
    { struct SymbTab* search = Search((yyvsp[-3].string),level,1);
    if(search == NULL ){                                                                                                                                                                                                                           yyerror("variable does not exist \n");                                                                                                                                                                                                       yyerror((yyvsp[-3].string));
      exit(1);
    }
    if(search->IsAFunc !=2){                                                                                                                                                                                                                       yyerror("needs to be an array \n");                                                                                                                                                                                                          yyerror((yyvsp[-3].string));
      exit(1);                                                                                                                                                                                                                                   }  
    
     (yyval.node)=ASTCreateNode(VAR);
         (yyval.node)->Name = (yyvsp[-3].string); 
         (yyval.node)->s1 = (yyvsp[-1].node);
	 (yyval.node)->symbol = search;
	 (yyval.node)->semtype = search->Type;
    }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 436 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[0].node);}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 437 "lab9.y" /* yacc.c:1646  */
    {

       if((yyvsp[-2].node)->semtype != (yyvsp[0].node)->semtype){

             
	 yyerror("type mismatch \n");
	 exit(1);
	 
       }
       
       (yyval.node) = ASTCreateNode(expr);
       (yyval.node)->s1 = (yyvsp[-2].node);
       (yyval.node)->s2 = (yyvsp[0].node);             /* this handles most of our addition and subtraction cases*/
       (yyval.node)->operator = (yyvsp[-1].optype);
       (yyval.node)->semtype = (yyvsp[-2].node)->semtype;
       (yyval.node)->Name=CreateTemp();
       (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);
       offset++;
     }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 459 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = LessEqual;}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 460 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = LessThan;}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 461 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = GreatThan;}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 462 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = GreatEqual;}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 463 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = Equal;}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 464 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = NotEqual;}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 468 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 469 "lab9.y" /* yacc.c:1646  */
    {

  if((yyvsp[-2].node)->semtype != (yyvsp[0].node)->semtype){

    yyerror("type mismatch \n");
    exit(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }

  
  (yyval.node) = ASTCreateNode(expr);
  (yyval.node)->s1 = (yyvsp[-2].node);
  (yyval.node)->s2 = (yyvsp[0].node);
  (yyval.node)->operator = (yyvsp[-1].optype);
  (yyval.node)->semtype = (yyvsp[-2].node)->semtype;
  (yyval.node)->Name=CreateTemp();
  (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);
  offset++;
 }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 489 "lab9.y" /* yacc.c:1646  */
    { (yyval.optype) = PLUS;}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 490 "lab9.y" /* yacc.c:1646  */
    { (yyval.optype) = MINUS;}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 493 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 494 "lab9.y" /* yacc.c:1646  */
    {
      if((yyvsp[-2].node)->semtype != (yyvsp[0].node)->semtype){

	yyerror("type mismatch \n");
	exit(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
      
      (yyval.node) =ASTCreateNode(expr);
      (yyval.node)->operator = (yyvsp[-1].optype);
      (yyval.node)->s1 = (yyvsp[-2].node);
      (yyval.node)->s2 = (yyvsp[0].node);
      (yyval.node)->semtype = (yyvsp[-2].node)->semtype;
      (yyval.node)->Name=CreateTemp();
      (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);                                                                                                                                                                                  offset++; 
     }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 510 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype)= multi;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 511 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = devi;}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 512 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = aNd;}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 513 "lab9.y" /* yacc.c:1646  */
    {(yyval.optype) = oR;}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 516 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[-1].node);}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 517 "lab9.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(mynum);
               (yyval.node)->value = (yyvsp[0].number);
	       (yyval.node)->semtype = inttype;
             }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 521 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 522 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[0].node);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 523 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =ASTCreateNode(mynum);
              (yyval.node)->value = 1;
	      (yyval.node)->semtype = booltype;
       }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 527 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) =ASTCreateNode(mynum);
              (yyval.node)->value =0;
	      (yyval.node)->semtype = booltype;
       }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 531 "lab9.y" /* yacc.c:1646  */
    { if((yyvsp[0].node)->semtype != booltype){
      yyerror("not needs a boolean type\n");
      exit(1);
    }
  (yyval.node) = ASTCreateNode(expr);
  (yyval.node)->operator = nOt;
   (yyval.node)->s1 = (yyvsp[0].node);
   (yyval.node)->semtype = (yyvsp[0].node)->semtype;
   (yyval.node)->Name=CreateTemp();
   (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);                                                                                                                                                                                  offset++; 
      }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 544 "lab9.y" /* yacc.c:1646  */
    {
  struct SymbTab* search = Search((yyvsp[-3].string),level,1);
  if(search == NULL ){                                                                                                                                                                                                                       yyerror("function does not exist \n");                                                                                                                                                                                                       yyerror((yyvsp[-3].string));
    exit(1);
  }
  if(search->IsAFunc !=1){                                                                                                                                                                                                                       yyerror("needs to be a function \n");                                                                                                                                                                                                       yyerror((yyvsp[-3].string));
    exit(1);                                                                                                                                                                                                                                   }

  //check the formal vs actual
  if(checkFormalsandParams(search->fparms,(yyvsp[-1].node)) != 1)
    {  yyerror("function actual and formal params mismatch \n");
      exit(1);

    }
  
    (yyval.node)=ASTCreateNode(callme);
    (yyval.node)->Name = (yyvsp[-3].string);
    (yyval.node)->s1 = (yyvsp[-1].node);
    (yyval.node)->symbol =search;
    (yyval.node)->semtype = search->Type;
    }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 567 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 568 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 571 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(ARGLIST);
    (yyval.node)->s1 = (yyvsp[0].node);
    (yyval.node)->semtype = (yyvsp[0].node)->semtype;
    (yyval.node)->next = NULL;
    (yyval.node)->Name=CreateTemp();
    (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);                                                                                                                                                                                  offset++; 
       }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 578 "lab9.y" /* yacc.c:1646  */
    {
	 (yyval.node)=ASTCreateNode(ARGLIST);
         (yyval.node)->next = (yyvsp[0].node);
	 (yyval.node)->semtype = (yyvsp[-2].node)->semtype; 
	 (yyval.node)->s1 = (yyvsp[-2].node);
	 (yyval.node)->Name=CreateTemp();
	 (yyval.node)->symbol=Insert((yyval.node)->Name,inttype,0,level,1,offset,NULL);                                                                                                                                                                                  offset++; 
       }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2253 "y.tab.c" /* yacc.c:1646  */
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
#line 588 "lab9.y" /* yacc.c:1906  */
	/* end of rules, start of program */

int main(int argc, char * argv[])
{
  //printf("mydebug is currently %d \n",mydebug); argument debug prints 
  // printf("main has %d arguments with %s as the string \n",argc,argv[0]);
   int i=1;
   char s[100];
   FILE *fp;
   int foundit =0;
   
   while(i<argc){

     if(strcmp(argv[i],"-d") ==0)
       { mydebug =1;
	 i=i+1;
       }
     else if(strcmp(argv[i],"-o")==0)
       {//we asssume that the i+1 is the file prefix we want

	 if(argc>i+1)foundit =1;
	 
	 sprintf(s,"%s.asm",argv[i+1]);
	 i=i+2;

       }
     else i=i+1;

   }//process our argument list
   
   /* we now want to open and write to a file */

   if(foundit ==0){
     printf("you have to give me a -o argument \n");
     exit(1);
   }
   fp=fopen(s,"w");
   
   if(fp == NULL){
     printf("cannot open file %s \n",s);
     exit(1);
   }//if file cannot be opened

   
  yyparse();
  // ASTprint(worldpointer,0);//prints tree

  fprintf(fp,".data \n\n");
  
  EMITSTRINGS(worldpointer,fp);

  fprintf(fp,"_NL:\t .asciiz\t\"\\n\"\n");

  fprintf(fp,"\n.align 2 \n\n");
  
  EMITGLOBALS(worldpointer,fp);      //print outs needed for every mips code 

  fprintf(fp,"\n.text\n\n");


  fprintf(fp,"\n.globl main\n\n");
  
  EMITAST(worldpointer,fp);
}//of main
