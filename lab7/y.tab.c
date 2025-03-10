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
#line 1 "lab7.y" /* yacc.c:339  */


/*  Matthew Groover 
    3-2-20 - 3-27-20
 *  this y file defines the algol-c language for 
    our ast and later use for the whole compiler [21~
*/


	/* begin specs */
#include "ast.h"
#include <stdio.h>
#include <ctype.h>
#include  <stdlib.h>
#include "symtable.h"  
 
  extern int linecount;  /*imports the linecount from lex */
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

#line 107 "y.tab.c" /* yacc.c:339  */

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
    NOT = 283
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "lab7.y" /* yacc.c:355  */

int number;
char *string;
struct ASTNODEtype *node; 
 enum DATATYPE dtype;      /*global types to handle operators and nodes */
enum NODETYPE type;
 enum OPERATOR optype;

#line 212 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      33,    34,    38,    36,    32,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    90,    91,    97,    98,   100,   110,   127,
     146,   168,   190,   192,   194,   197,   207,   197,   224,   225,
     227,   228,   230,   251,   270,   270,   279,   280,   285,   286,
     293,   294,   295,   296,   297,   298,   299,   300,   302,   306,
     308,   315,   323,   329,   332,   337,   342,   347,   361,   365,
     382,   400,   401,   420,   421,   422,   423,   424,   425,   429,
     430,   447,   448,   451,   452,   466,   467,   468,   469,   472,
     473,   477,   478,   479,   483,   487,   497,   520,   521,   524,
     529
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
  "FALSE", "NOT", "';'", "'['", "']'", "','", "'('", "')'", "'='", "'+'",
  "'-'", "'*'", "'/'", "$accept", "program", "decl", "dec", "vardec",
  "varlist", "typespec", "fundec", "$@1", "$@2", "params", "paramlist",
  "param", "compstat", "$@3", "localdec", "statlist", "statement",
  "expressstat", "selectionstat", "iterstat", "returstat", "readstat",
  "writestat", "assignstat", "expression", "var", "simpleexp", "relop",
  "addexp", "addop", "term", "mulop", "factor", "call", "args", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      91,    93,    44,    40,    41,    61,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      45,   -84,   -84,   -84,    12,   -84,    45,   -84,    14,   -84,
     -84,   -84,     7,    -2,    26,    87,   -84,   -84,    13,    11,
     -84,    75,    59,    58,    90,   -84,   -84,    62,    87,    65,
      63,    45,   -84,    67,    88,   -84,   -84,   -84,   -84,    45,
      45,    87,     5,   -84,   -19,   -84,    32,    32,    20,    96,
      32,   -84,   -84,    32,   -84,    32,   -84,    91,     5,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    72,    68,    66,    41,
      37,   -84,   -84,    32,    32,    93,   -84,    92,   -84,    73,
      77,    76,    79,   -84,    78,   -84,   -84,   -84,    32,   -84,
     -84,   -84,   -84,   -84,   -84,    32,   -84,   -84,    32,   -84,
     -84,   -84,   -84,    32,    80,    81,    82,   -84,     5,     5,
     -84,   -84,   -84,   -84,    50,    41,    37,   -84,   -84,    32,
     -84,    97,   -84,   -84,   -84,     5,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,    15,     7,     0,     8,
      10,     0,     9,    13,     0,    16,    19,    20,     0,    22,
       0,     0,    11,     0,     0,    21,    23,    24,    17,    26,
      26,     0,    28,    27,    49,    70,     0,     0,     0,     0,
       0,    73,    74,     0,    39,     0,    31,     0,    28,    30,
      32,    33,    35,    36,    37,    34,     0,    71,    48,    51,
      59,    63,    72,     0,    77,     0,    71,     0,    43,     0,
      49,     0,     0,    75,     0,    25,    29,    38,     0,    53,
      54,    56,    55,    57,    58,     0,    61,    62,     0,    67,
      68,    65,    66,     0,     0,    79,     0,    78,     0,     0,
      44,    45,    46,    69,     0,    52,    60,    64,    50,     0,
      76,    40,    42,    47,    80,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   104,   -84,    17,    -9,    24,   -84,   -84,   -84,
     -84,    83,   -84,    84,   -84,    85,    57,   -83,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -45,   -42,    29,   -84,    25,
     -84,    21,   -84,   -49,   -84,   -84,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    21,    30,
      25,    26,    27,    56,    39,    42,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    76,    68,    95,    69,
      98,    70,   103,    71,    72,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    75,    77,    79,    83,    82,    20,    81,    44,    45,
      84,    73,    10,    37,    74,    46,    67,    12,    47,    32,
      48,    49,    50,    44,    45,   121,   122,    17,   104,   105,
      18,    51,    52,    53,    54,    44,    45,    14,    55,    15,
      16,    14,   126,    15,    22,    24,    51,    52,    53,    78,
       1,     2,     3,    55,   117,    24,    40,    40,    51,    52,
      53,    99,   100,    41,    41,    55,    67,    67,    89,    90,
      91,    92,    93,    94,   105,   101,   102,    96,    97,   123,
       1,    23,     3,    67,    89,    90,    91,    92,    93,    94,
      19,    28,   -18,    29,    31,    33,    37,    34,    36,    80,
      85,    87,   110,    88,   108,   111,   109,    73,   112,   125,
      11,   118,   113,   119,    35,    86,   120,   114,    38,   116,
     115,   124,     0,     0,     0,    43
};

static const yytype_int8 yycheck[] =
{
      42,    46,    47,    48,    53,    50,    15,    49,     3,     4,
      55,    30,     0,     8,    33,    10,    58,     3,    13,    28,
      15,    16,    17,     3,     4,   108,   109,    29,    73,    74,
       4,    26,    27,    28,    29,     3,     4,    30,    33,    32,
      33,    30,   125,    32,    31,    21,    26,    27,    28,    29,
       5,     6,     7,    33,   103,    31,    39,    40,    26,    27,
      28,    24,    25,    39,    40,    33,   108,   109,    18,    19,
      20,    21,    22,    23,   119,    38,    39,    36,    37,    29,
       5,     6,     7,   125,    18,    19,    20,    21,    22,    23,
       3,    32,    34,     3,    32,    30,     8,    34,    31,     3,
       9,    29,    29,    35,    11,    29,    14,    30,    29,    12,
       6,    31,    34,    32,    31,    58,    34,    88,    34,    98,
      95,   119,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    41,    42,    43,    44,    46,    47,
       0,    42,     3,    45,    30,    32,    33,    29,     4,     3,
      45,    48,    31,     6,    46,    50,    51,    52,    32,     3,
      49,    32,    45,    30,    34,    51,    31,     8,    53,    54,
      44,    46,    55,    55,     3,     4,    10,    13,    15,    16,
      17,    26,    27,    28,    29,    33,    53,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    69,
      71,    73,    74,    30,    33,    65,    66,    65,    29,    65,
       3,    66,    65,    73,    65,     9,    56,    29,    35,    18,
      19,    20,    21,    22,    23,    68,    36,    37,    70,    24,
      25,    38,    39,    72,    65,    65,    75,    76,    11,    14,
      29,    29,    29,    34,    67,    69,    71,    73,    31,    32,
      34,    57,    57,    29,    76,    12,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    45,    45,
      45,    45,    46,    46,    46,    48,    49,    47,    50,    50,
      51,    51,    52,    52,    54,    53,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    61,    61,    62,    63,    64,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    75,    75,    76,
      76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     2,     4,     0,     5,     0,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     6,     4,     2,     3,     3,     3,     4,     1,     1,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     4,     0,     1,     1,
       3
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
#line 88 "lab7.y" /* yacc.c:1646  */
    { worldpointer = (yyvsp[0].node); }
#line 1398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "lab7.y" /* yacc.c:1646  */
    {
                (yyval.node)=(yyvsp[-1].node);
                (yyvsp[-1].node)->next = (yyvsp[0].node);  /*assigns the next dec to its pointer next */
               
              }
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[-1].node);    
                            ASTnode *p;
                             p = (yyval.node);       
			     while(p!=NULL){
                               p->datatype =  (yyvsp[-2].dtype);
			       Search(p->Name,level,0)->Type = (yyvsp[-2].dtype);
			       p=p->s1;
			     }
                           }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "lab7.y" /* yacc.c:1646  */
    {
  if(Search((yyvsp[0].string),level,0) != NULL){
    yyerror("duplicate declaration \n");
    yyerror((yyvsp[0].string));
    exit(1);
  }
  else{

    Insert((yyvsp[0].string),-1,0,level,1,offset,NULL);
    /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
			    Tnode * fparms ); */
    offset = offset +1;
  }
           (yyval.node) = ASTCreateNode(vardec);
            (yyval.node)->Name = (yyvsp[0].string);
	    (yyval.node)->size =1;
           }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "lab7.y" /* yacc.c:1646  */
    { // fprintf(stderr,"there is a num it is %d \n",$3);

	 if(Search((yyvsp[-3].string),level,0) != NULL){
	   yyerror("duplicate declaration \n");
	   yyerror((yyvsp[-3].string));
	   exit(1);
	 }
	 else{

	   Insert((yyvsp[-3].string),-1,2,level,(yyvsp[-1].number),offset,NULL);
	   /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
	     Tnode * fparms ); */
	   offset = offset + (yyvsp[-1].number);
	   Display();
	 }
                     (yyval.node)=ASTCreateNode(vardec);
		     (yyval.node)->Name = (yyvsp[-3].string);
		     (yyval.node)->size = (yyvsp[-1].number);
	}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 146 "lab7.y" /* yacc.c:1646  */
    {
	  if(Search((yyvsp[-2].string),level,0) != NULL){
	    yyerror("duplicate declaration \n");
	    yyerror((yyvsp[-2].string));
	    exit(1);
	  }
	  else{

	    Insert((yyvsp[-2].string),-1,0,level,1,offset,NULL);
	    /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
	      Tnode * fparms ); */
	    offset = offset +1;
	    
	  }
	  
	                 (yyval.node)=ASTCreateNode(vardec);  /*these handle all variable declarations varlist recusively points at itself hence the null handle */
			 (yyval.node)->Name = (yyvsp[-2].string);
			  (yyval.node)->s1 = (yyvsp[0].node);
			  (yyval.node)->size =1;

	 }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 168 "lab7.y" /* yacc.c:1646  */
    {
	 if(Search((yyvsp[-5].string),level,0) != NULL){
	   yyerror("duplicate declaration \n");
	   yyerror((yyvsp[-5].string));
	   exit(1);
	 }
	 else{

	   Insert((yyvsp[-5].string),-1,2,level,(yyvsp[-3].number),offset,NULL);
	   /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
	     Tnode * fparms ); */
	   offset = offset +(yyvsp[-3].number);
	   
	 }
                        
                         (yyval.node)=ASTCreateNode(vardec);
			 (yyval.node)->Name = (yyvsp[-5].string);
			 (yyval.node)->size = (yyvsp[-3].number);
			 (yyval.node)->s1 = (yyvsp[0].node);

	}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 190 "lab7.y" /* yacc.c:1646  */
    {(yyval.dtype)=inttype;
  }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "lab7.y" /* yacc.c:1646  */
    {(yyval.dtype) = voidtype;
        }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 194 "lab7.y" /* yacc.c:1646  */
    {(yyval.dtype) = booltype;
	 }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "lab7.y" /* yacc.c:1646  */
    {
  if(Search((yyvsp[-1].string),level,0) != NULL){
    yyerror("duplicate function declaration \n");
    yyerror((yyvsp[-2].dtype));
    exit(1);
  }
  
  goffset = offset;
  offset =0;

  }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 207 "lab7.y" /* yacc.c:1646  */
    {

    Insert((yyvsp[-3].string), (yyvsp[-4].dtype), 1, level, 1,goffset, (yyvsp[0].node) );
    goffset +=1; //inserts function
    Display();

   }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 213 "lab7.y" /* yacc.c:1646  */
    {
  
          (yyval.node) = ASTCreateNode(fundec);
          (yyval.node)->Name = (yyvsp[-6].string);
          (yyval.node)->s1 = (yyvsp[-3].node);                  
          (yyval.node)->s2 = (yyvsp[0].node);
          (yyval.node)->datatype = (yyvsp[-7].dtype);
	  offset = goffset;
          
      }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 224 "lab7.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 225 "lab7.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 227 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 228 "lab7.y" /* yacc.c:1646  */
    { (yyval.node)=(yyvsp[-2].node); (yyvsp[-2].node)->next = (yyvsp[0].node);}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "lab7.y" /* yacc.c:1646  */
    {  if(Search((yyvsp[0].string),level+1,0) != NULL){
     yyerror("duplicate declaration \n");
     yyerror((yyvsp[0].string));
     exit(1);
   }
   else{

     Insert((yyvsp[0].string),(yyvsp[-1].dtype),0,level+1,1,offset,NULL);
     /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
       Tnode * fparms ); */
     
     Display();

   }

  (yyval.node) = ASTCreateNode(params);
                      (yyval.node)->Name = (yyvsp[0].string);
		       (yyval.node)->size =1;
		       (yyval.node)->datatype = (yyvsp[-1].dtype);
		       (yyval.node)->semtype = (yyvsp[-1].dtype);
                    }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 251 "lab7.y" /* yacc.c:1646  */
    { if(Search((yyvsp[-2].string),level+1,0) != NULL){
      yyerror("duplicate declaration \n");
      yyerror((yyvsp[-2].string));                                                                                                                                                                                                                                 exit(1);
    }
    else{

      Insert((yyvsp[-2].string),(yyvsp[-3].dtype),2,level+1,1,offset,NULL);
      /*Insert(char *name, enum OPERATOR Type, int isafunc, int  level, int mysize, int offse,
	Tnode * fparms ); */
      offset = offset +1;
      Display();                                                                                                                                                                                                                                                                                                                                                                                                                                                                              }


	(yyval.node) = ASTCreateNode(params);
                      (yyval.node)->Name = (yyvsp[-2].string);
                      (yyval.node)->size = 2;
		      (yyval.node)->datatype = (yyvsp[-3].dtype);
     }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 270 "lab7.y" /* yacc.c:1646  */
    {level +=1;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 270 "lab7.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(comp);
         (yyval.node)->s1 = (yyvsp[-2].node);
         (yyval.node)->s2 = (yyvsp[-1].node);
	 level=level-1;
	 offset-=Delete(level);
	 Display();
        }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 279 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 280 "lab7.y" /* yacc.c:1646  */
    {  /*handle local variable declaration within a compound statment */
	  (yyvsp[-1].node)->next=(yyvsp[0].node);(yyval.node)=(yyvsp[-1].node);
	  
          }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 285 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 286 "lab7.y" /* yacc.c:1646  */
    {  
  if((yyvsp[-1].node)==NULL){
    (yyval.node)=(yyvsp[0].node);             /*statlist recursively handles itself so we check against null to prevent seg faults*/
  }
  (yyvsp[-1].node)->next = (yyvsp[0].node); (yyval.node)=(yyvsp[-1].node); 
  }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 295 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 296 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 297 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 298 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 299 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 300 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 302 "lab7.y" /* yacc.c:1646  */
    {
  (yyval.node)= ASTCreateNode(exprstmt);
  (yyval.node)->s1 = (yyvsp[-1].node);
            }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 308 "lab7.y" /* yacc.c:1646  */
    {
              (yyval.node)=ASTCreateNode(iff);
	      (yyval.node)->s2 = ASTCreateNode(iffbody);  /* we create a node for the statment then body of the if */
              (yyval.node)->s1 = (yyvsp[-2].node);
	      (yyval.node)->s2->s1 = (yyvsp[0].node);
	      (yyval.node)->s2->s2 = NULL;
              }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 315 "lab7.y" /* yacc.c:1646  */
    {
	       (yyval.node)=ASTCreateNode(iff);
	       (yyval.node)->s2 = ASTCreateNode(iffbody); /*the s2 of the body if is only initialized if we have an else */
               (yyval.node)->s1 = (yyvsp[-4].node);
               (yyval.node)->s2->s1 = (yyvsp[-2].node);
	       (yyval.node)->s2->s2 = (yyvsp[0].node);
              }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 323 "lab7.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(loop);    /*handles the while do statments */
	   (yyval.node)->s1 = (yyvsp[-2].node);
	   (yyval.node)->s2 = (yyvsp[0].node);
         }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 329 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =ASTCreateNode(RET);
   (yyval.node)->s1 = NULL;
         }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 332 "lab7.y" /* yacc.c:1646  */
    {
           (yyval.node) = ASTCreateNode(RET);
           (yyval.node)->s1 = (yyvsp[-1].node);
         }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 337 "lab7.y" /* yacc.c:1646  */
    {
         (yyval.node) = ASTCreateNode(RED); /*handles the read */
         (yyval.node)->s1 = (yyvsp[-1].node);
	 }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "lab7.y" /* yacc.c:1646  */
    {
  (yyval.node) = ASTCreateNode(WRIT); /*handles write statments */
	  (yyval.node)->s1 = (yyvsp[-1].node);
          }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 347 "lab7.y" /* yacc.c:1646  */
    {
  if((yyvsp[-3].node)->semtype != (yyvsp[-1].node)->semtype){
    yyerror("type mismatch on assignment \n");
    exit(1);
  }
            
          (yyval.node) = ASTCreateNode(assign); /*assignment statement handle */
          (yyval.node)->s1 = (yyvsp[-3].node);
	  (yyval.node)->s2 = (yyvsp[-1].node);
          }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 361 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 365 "lab7.y" /* yacc.c:1646  */
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
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 382 "lab7.y" /* yacc.c:1646  */
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
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 400 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[0].node);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 401 "lab7.y" /* yacc.c:1646  */
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
     }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 420 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = LessEqual;}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 421 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = LessThan;}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 422 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = GreatThan;}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 423 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = GreatEqual;}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 424 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = Equal;}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 425 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = NotEqual;}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 429 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 430 "lab7.y" /* yacc.c:1646  */
    {

  if((yyvsp[-2].node)->semtype != (yyvsp[0].node)->semtype){

    yyerror("type mismatch \n");
    exit(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }

  
  (yyval.node) = ASTCreateNode(expr);
  (yyval.node)->s1 = (yyvsp[-2].node);
  (yyval.node)->s2 = (yyvsp[0].node);
  (yyval.node)->operator = (yyvsp[-1].optype);
  (yyval.node)->semtype = (yyvsp[-2].node)->semtype;
 }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 447 "lab7.y" /* yacc.c:1646  */
    { (yyval.optype) = PLUS;}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 448 "lab7.y" /* yacc.c:1646  */
    { (yyval.optype) = MINUS;}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 451 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 452 "lab7.y" /* yacc.c:1646  */
    {
      if((yyvsp[-2].node)->semtype != (yyvsp[0].node)->semtype){

	yyerror("type mismatch \n");
	exit(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
      
      (yyval.node) =ASTCreateNode(expr);
      (yyval.node)->operator = (yyvsp[-1].optype);
      (yyval.node)->s1 = (yyvsp[-2].node);
      (yyval.node)->s2 = (yyvsp[0].node);
      (yyval.node)->semtype = (yyvsp[-2].node)->semtype;
     }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 466 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype)= multi;}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 467 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = devi;}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 468 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = aNd;}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 469 "lab7.y" /* yacc.c:1646  */
    {(yyval.optype) = oR;}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 472 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[-1].node);}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 473 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(mynum);
               (yyval.node)->value = (yyvsp[0].number);
	       (yyval.node)->semtype = inttype;
             }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 477 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 478 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =(yyvsp[0].node);}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 479 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =ASTCreateNode(TF);
              (yyval.node)->value = 1;
	      (yyval.node)->semtype = booltype;
       }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 483 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) =ASTCreateNode(TF);
              (yyval.node)->value =0;
	      (yyval.node)->semtype = booltype;
       }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 487 "lab7.y" /* yacc.c:1646  */
    { if((yyvsp[0].node)->semtype != booltype){
      yyerror("not needs a boolean type\n");
      exit(1);
    }
  (yyval.node) = ASTCreateNode(nOt);
   (yyval.node)->s1 = (yyvsp[0].node);
   (yyval.node)->semtype = (yyvsp[0].node)->semtype;
      }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 497 "lab7.y" /* yacc.c:1646  */
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
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 520 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 521 "lab7.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 524 "lab7.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(ARGLIST);
    (yyval.node)->s1 = (yyvsp[0].node);
    (yyval.node)->semtype = (yyvsp[0].node)->semtype;
    (yyval.node)->next = NULL;
       }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 529 "lab7.y" /* yacc.c:1646  */
    {
	 (yyval.node)=ASTCreateNode(ARGLIST);
         (yyval.node)->next = (yyvsp[0].node);
	 (yyval.node)->semtype = (yyvsp[-2].node)->semtype; 
	 (yyval.node)->s1 = (yyvsp[-2].node);
       }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2187 "y.tab.c" /* yacc.c:1646  */
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
#line 537 "lab7.y" /* yacc.c:1906  */
	/* end of rules, start of program */

int main()
{ yyparse();
  // ASTprint(worldpointer,0);//prints tree 
}//of main
