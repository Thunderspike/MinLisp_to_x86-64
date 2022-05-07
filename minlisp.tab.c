/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "minlisp.y"

    #include "minlisp.tab.h"
    #include "minlisp.h"

    // Lex/YACC utilities
    int yylex();
    int yyerror(char *s);
    extern int yylineno;

#line 80 "minlisp.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MINLISP_TAB_H_INCLUDED
# define YY_YY_MINLISP_TAB_H_INCLUDED
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
    _array = 258,
    _seq = 259,
    _define = 260,
    _if = 261,
    _while = 262,
    _write = 263,
    _writeln = 264,
    _read = 265,
    _and = 266,
    _or = 267,
    _not = 268,
    _set = 269,
    _let = 270,
    _true = 271,
    _false = 272,
    LTE = 273,
    NEQ = 274,
    GTE = 275,
    ID = 276,
    NUM = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "minlisp.y"

    char* keyword;
    char* nameVal;
    int intVal;
    struct Symbol* symbolPointerType;
    struct PLScope* paramsListType;

#line 163 "minlisp.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_MINLISP_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

#define YYUNDEFTOK  2
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,     2,    34,     2,
      23,    24,    29,    27,     2,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    33,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    46,    57,    64,    87,    92,    98,    98,
     151,   161,   189,   212,   231,   242,   273,   299,   307,   314,
     345,   345,   357,   417,   439,   461,   473,   480,   473,   503,
     535,   572,   609,   640,   669,   705,   716,   728,   740,   752,
     775,   787,   804,   816,   828,   840,   852,   861,   870,   885,
     904,   913,   943,   972,   981
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_array", "_seq", "_define", "_if",
  "_while", "_write", "_writeln", "_read", "_and", "_or", "_not", "_set",
  "_let", "_true", "_false", "LTE", "NEQ", "GTE", "ID", "NUM", "'('",
  "')'", "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'='",
  "'&'", "'|'", "'!'", "$accept", "ML", "arrays", "array", "program",
  "function", "$@1", "param_list", "id_list", "expr", "$@2", "$@3", "$@4",
  "actual_list", "assign_list", "expr_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    40,    41,    91,    93,    43,    45,    42,
      47,    60,    62,    61,    38,   124,    33
};
# endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,     6,    -8,   -31,    34,   -31,     5,   -31,    54,    55,
      77,   -31,    61,   -31,    74,    62,   -31,    32,   102,   -31,
     -31,    60,   -31,   -31,    75,   -31,    59,    83,   -31,   -31,
     102,   102,   102,   102,   102,   102,    86,   102,   102,   102,
      78,   -31,   102,   102,   102,   -31,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   -31,    90,   -31,    10,
     102,   -31,    96,    97,   -31,   102,   102,    98,    92,   103,
     102,   102,   102,    38,   102,    80,   102,   102,   102,   102,
     102,   102,   102,   104,   -31,   -31,   -31,   102,   102,   -31,
     -31,   105,   106,   -31,   102,   107,   109,   110,   111,   112,
     -31,   -31,   113,   -31,   114,   115,   116,   117,   118,   119,
     120,   121,   -31,   122,   123,   -31,   -31,   101,   -31,   127,
     -13,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   102,   102,   128,   -31,   126,
     129,   102,   102,   -31,   -31,   130,   131,   -31,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     7,     0,     0,
       0,     6,     0,     8,     0,     0,     5,     0,     0,    13,
      10,     0,    17,    18,    15,    14,     0,     0,    12,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    54,     0,
       0,    20,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    48,    53,     0,     0,    23,
      24,     0,     0,    46,     0,     0,     0,     0,     0,     0,
      22,    49,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,    42,    44,     0,    29,     0,
       0,    37,    40,    38,    31,    32,    33,    34,    35,    36,
      39,    43,    45,    19,    21,     0,     0,     0,    27,     0,
       0,     0,     0,    30,    52,     0,     0,    51,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -31,   -31,   -31,   -31,   -31,   145,   -31,   -31,   -31,   -30,
     -31,   -31,   -31,   -31,   -31,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    15,    18,    21,    27,
      88,    69,   142,    73,   120,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    60,    61,    62,    63,     3,    65,    66,    67,
     137,   138,    70,    71,    72,     4,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    22,    23,    10,    86,
      87,    24,    25,    26,    85,    91,    92,     8,    95,     9,
      97,    98,    99,   101,   102,   104,   105,   106,   107,   108,
     109,   110,   111,    19,    22,    23,    20,   113,   114,    24,
      25,    26,   100,    31,   117,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    12,    13,    42,    43,    44,
      45,    28,     9,    14,    29,    17,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    22,    23,    16,    68,
      30,    24,    25,    26,   103,   139,   140,    56,    22,    23,
      64,   145,   146,    24,    25,    26,    84,    94,    22,    23,
      89,    90,    93,    24,    25,    26,    96,   135,   112,   115,
     116,   118,   119,     0,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   136,   141,
     143,    11,     0,   144,   147,   148
};

static const yytype_int16 yycheck[] =
{
      30,    31,    32,    33,    34,    35,     0,    37,    38,    39,
      23,    24,    42,    43,    44,    23,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    16,    17,    23,    59,
      60,    21,    22,    23,    24,    65,    66,     3,    68,     5,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    21,    16,    17,    24,    87,    88,    21,
      22,    23,    24,     4,    94,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    21,    21,    18,    19,    20,
      21,    21,     5,    22,    24,    23,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    16,    17,    24,    21,
      25,    21,    22,    23,    24,   135,   136,    24,    16,    17,
      24,   141,   142,    21,    22,    23,    26,    25,    16,    17,
      24,    24,    24,    21,    22,    23,    23,    26,    24,    24,
      24,    24,    23,    -1,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    21,    21,
      24,     6,    -1,    24,    24,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    23,    40,    41,    42,     3,     5,
      23,    42,    21,    21,    22,    43,    24,    23,    44,    21,
      24,    45,    16,    17,    21,    22,    23,    46,    21,    24,
      25,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    18,    19,    20,    21,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    24,    46,    46,    52,
      46,    46,    46,    46,    24,    46,    46,    46,    21,    48,
      46,    46,    46,    50,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    26,    24,    46,    46,    47,    24,
      24,    46,    46,    24,    25,    46,    23,    46,    46,    46,
      24,    46,    46,    24,    46,    46,    46,    46,    46,    46,
      46,    46,    24,    46,    46,    24,    24,    46,    24,    23,
      51,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    26,    21,    23,    24,    46,
      46,    21,    49,    24,    24,    46,    46,    24,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    41,    41,    43,    42,
      44,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      47,    46,    46,    46,    46,    46,    48,    49,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    50,
      50,    51,    51,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     5,     2,     1,     0,     7,
       2,     3,     2,     1,     1,     1,     4,     1,     1,     6,
       0,     6,     4,     4,     4,     3,     0,     0,     9,     5,
       8,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     4,     5,     5,     5,     5,     4,     4,     4,     2,
       0,     5,     4,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 33 "minlisp.y"
                                {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) ML - arrays program\n", nodeCounter++);
        printFuncs();
        printArrays();
    }

    char* lastF_p = globalFuncs_p->ids_p[globalFuncs_p->count - 1];

    if(strcasecmp(lastF_p, (char*) MAIN) != 0) 
        fprintf(stderr, "Line %d --- Last function must be 'main'.\n", yylloc.first_line);
}
#line 1547 "minlisp.tab.c"
    break;

  case 3:
#line 47 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) arrays - __empty__\n", nodeCounter++);

    // always fist node reached - perfect place to initialize global state and print required assembly function headers 
    initGlobalState();

    printf(".text\n");
    printf(".globl minlisp_main\n\n");
}
#line 1562 "minlisp.tab.c"
    break;

  case 4:
#line 58 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) arrays - arrays array\n", nodeCounter++);

}
#line 1572 "minlisp.tab.c"
    break;

  case 5:
#line 65 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) array - '(' 'array' %s %d ')'\n", nodeCounter++, (yyvsp[-2].nameVal), (yyvsp[-1].intVal));

    if(strcasecmp((yyvsp[-2].nameVal), (char*) MAIN) == 0)
        fprintf(stderr, "Line %d --- Illegal variable name 'main' for arrays'\n", yylloc.first_line);

    ArrayObj* arrO_p = (ArrayObj*) malloc(sizeof(ArrayObj));
    arrO_p = getArrayO((yyvsp[-2].nameVal));

    if(arrO_p) {
        fprintf(stderr, "Line %d --- Array '%s' has already been defined.\n", yylloc.first_line, (yyvsp[-2].nameVal));
    } else {
        int size = (yyvsp[-1].intVal);
        if(size < 0) {
            fprintf(stderr, "Line %d --- Array indices must be type integer and >= 0\n", yylloc.first_line);
            size = 0;
        }
        addArrToScope(createArrayO((yyvsp[-2].nameVal), size));
    }
}
#line 1598 "minlisp.tab.c"
    break;

  case 6:
#line 88 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) program - program function\n", nodeCounter++);
}
#line 1607 "minlisp.tab.c"
    break;

  case 7:
#line 93 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) program - function\n", nodeCounter++);
}
#line 1616 "minlisp.tab.c"
    break;

  case 8:
#line 98 "minlisp.y"
                               {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) function - '(' 'define' ID (%s) {} param_list  expr ')'\n", nodeCounter++, (yyvsp[0].nameVal));

    // 1. check if array
    // 2. check if main

    ArrayObj* arrO_p = getArrayO((yyvsp[0].nameVal));
    FunctionData* funcD_p = getFuncO((yyvsp[0].nameVal));

    // check if main is already defined
    if(getFuncO(MAIN))
        fprintf(stderr, "Line %d --- 'main' already defined.\n", yylloc.first_line);

    if(arrO_p) {
        fprintf(stderr, "Line %d --- Variable '%s' already declared in scope as an array\n", yylloc.first_line, (yyvsp[0].nameVal));
    } else if(funcD_p && funcD_p->isUndefined == 1) {
        funcD_p->type = _INT;
        funcD_p->isUndefined = 0;
    } else if(funcD_p && funcD_p->isUndefined != 1)
        fprintf(stderr, "Line %d --- Function '%s' already declared in scope\n", yylloc.first_line, (yyvsp[0].nameVal));
    
    if(!funcD_p)
        addFunc(createFuncData((yyvsp[0].nameVal), 0, _INT));

    // createScope
    createFuncScope((yyvsp[0].nameVal));
    if(strcasecmp((yyvsp[0].nameVal), MAIN) == 0)
        genFunctionHeader((char*)"minlisp_main");
    else
        genFunctionHeader((yyvsp[0].nameVal));
    
}
#line 1654 "minlisp.tab.c"
    break;

  case 9:
#line 130 "minlisp.y"
                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) function - '(' 'define' ID (%s) --> param_list  expr ')'\n", nodeCounter++, (yyvsp[-4].nameVal));

    FunctionData* funcEntry_p = getFuncO(currScope_p->name);
    // set return type
    funcEntry_p->type = (yyvsp[-1].symbolPointerType)->type;

    if(DEBUG)
		fprintf(logsFile_p, "\tReturn type from function %s: %d\n", (yyvsp[-4].nameVal), (yyvsp[-1].symbolPointerType)->type);

    // pop func scope
    currScope_p = currScope_p->enclosingScope_p;

    genFunctionFooter();
    if(strcasecmp((yyvsp[-4].nameVal), MAIN) == 0){
        printf(".size       minlisp_main, .-minlisp_main\n");
        printf(".section    .note.GNU-stack,\"\",@progbits\n");  
    }
}
#line 1679 "minlisp.tab.c"
    break;

  case 10:
#line 152 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) param_list - '(' ')'\n", nodeCounter++);
    // report function param number to function hashtable entry
    FunctionData* funcEntry_p = getFuncO(currScope_p->name);
    funcEntry_p->paramsCount = 0;

    (yyval.paramsListType) = NULL;
}
#line 1693 "minlisp.tab.c"
    break;

  case 11:
#line 162 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) param_list - '(' id_list ')'\n", nodeCounter++);

    int paramsCount = 0;

    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));

    if((yyvsp[-1].paramsListType)){
        plScope_p = (yyvsp[-1].paramsListType);

        if(DEBUG)
            _printPL(plScope_p);
        paramsCount = plScope_p->count;
    }

    // report function param number to function hashtable entry
    FunctionData* funcEntry_p = getFuncO(currScope_p->name);
    funcEntry_p->paramsCount = paramsCount;

    if(DEBUG)
        printFuncs(funcEntry_p);

    (yyval.paramsListType) = plScope_p;
}
#line 1723 "minlisp.tab.c"
    break;

  case 12:
#line 190 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) id_list - id_list ID (%s)\n", nodeCounter++, (yyvsp[0].nameVal));
    Symbol* sym_p = malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, (yyvsp[0].nameVal));

    // use other copy to pass up to param_list for keeps
    PLScope* plScope_p = (yyvsp[-1].paramsListType);

    // lexeme shouldn't exist - if it does its value will getSymbol overwritten, for now
    if(sym_p)
        fprintf(stderr, "Line %d --- Parameter '%s' already defined\n", yylloc.first_line, (yyvsp[0].nameVal));
    else {
        // only addSymbol symbol if it's new to scope

        sym_p = createSymbol((yyvsp[0].nameVal), _INT, _PARAM, plScope_p->count);
        addSymbol(currScope_p, sym_p); 
        _addToPL(plScope_p, sym_p);
    }
     
    (yyval.paramsListType) = plScope_p;
}
#line 1750 "minlisp.tab.c"
    break;

  case 13:
#line 213 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) id_list - ID (%s)\n", nodeCounter++, (yyvsp[0].nameVal));     

    // always left-most node for id_list - create a new paramListScope to keep track of # of and param objects
    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));
    plScope_p = _newPLScope();

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = createSymbol((yyvsp[0].nameVal), _INT, _PARAM, plScope_p->count);
    addSymbol(currScope_p, sym_p); 

    _addToPL(plScope_p, sym_p);
    
    (yyval.paramsListType) = plScope_p;        
}
#line 1771 "minlisp.tab.c"
    break;

  case 14:
#line 232 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - NUM (%d)\n", nodeCounter++, (yyvsp[0].intVal));
    
    int regIndex = getFreeRegIndex();

    printf("movq $%d, %s\n", (yyvsp[0].intVal), genpurpRegName[regIndex]);

    (yyval.symbolPointerType) = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, regIndex);
}
#line 1786 "minlisp.tab.c"
    break;

  case 15:
#line 243 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - ID (%s)\n", nodeCounter++, (yyvsp[0].nameVal));

    // 1. check scope
    // 2. check func
    // 3. check for array and throw error   

    Symbol* sym_p = malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, (yyvsp[0].nameVal));

    if(!sym_p){
        sym_p = createSymbol((yyvsp[0].nameVal), _INT, _REGISTER, getFreeRegIndex());

        FunctionData* funcD_p = getFuncO((yyvsp[0].nameVal));
        ArrayObj* arrO_p = getArrayO((yyvsp[0].nameVal));

        if(funcD_p) {
            if(funcD_p->paramsCount != 0)  
                 fprintf(stderr, "Line %d --- Function '%s' expected [%d] parms\n", yylloc.first_line, (yyvsp[0].nameVal), funcD_p->paramsCount);
                 
            sym_p->type = funcD_p->type;
        } else if(arrO_p) 
            fprintf(stderr, "Line %d --- Array used incorrectly: '%s'\n", yylloc.first_line, (yyvsp[0].nameVal));
        else 
            fprintf(stderr, "Line %d --- Undeclared variable '%s'\n", yylloc.first_line, (yyvsp[0].nameVal));
    }

    (yyval.symbolPointerType) = sym_p;
}
#line 1821 "minlisp.tab.c"
    break;

  case 16:
#line 273 "minlisp.y"
                                 {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - ID (%s) '[' expr ']'\n", nodeCounter++, (yyvsp[-3].nameVal));  

    // 1. check scope and throw error
    // 2. check for function and throw error 
    // 3. check for array - and then check the rest of the array calling protocol

    Symbol* sym_p = getSymbol(currScope_p, (yyvsp[-3].nameVal));
    FunctionData* funcD_p = getFuncO((yyvsp[-3].nameVal));
    ArrayObj* arrO_p = getArrayO((yyvsp[-3].nameVal));

    if(sym_p) {
        fprintf(stderr, "Line %d --- '%s' is a scope variable, not an array\n", yylloc.first_line, (yyvsp[-3].nameVal));
    } else if(funcD_p) {
        fprintf(stderr, "Line %d --- '%s' is a function, not an array\n", yylloc.first_line, (yyvsp[-3].nameVal));
    } else if(arrO_p) {
        // if($3->type != _INT || $3->val < 0) 
        if((yyvsp[-1].symbolPointerType)->type != _INT)
            fprintf(stderr, "Line %d --- Array indices must be type integer and >= 0\n", yylloc.first_line);
        // here we calculate the value to return
    } else 
        fprintf(stderr, "Line %d --- Undeclared array '%s'\n", yylloc.first_line, (yyvsp[-3].nameVal));
    
    (yyval.symbolPointerType) = createSymbol((yyvsp[-3].nameVal), _INT, _GLOBAL, -1);  
}
#line 1852 "minlisp.tab.c"
    break;

  case 17:
#line 300 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - 'true'\n", nodeCounter++);    

    // these should just be static symbols
    (yyval.symbolPointerType) = createSymbol("_TRUE", _BOOL, _REGISTER, getFreeRegIndex());
}
#line 1864 "minlisp.tab.c"
    break;

  case 18:
#line 308 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - 'false'\n", nodeCounter++);

    (yyval.symbolPointerType) = createSymbol("_FALSE", _BOOL, _REGISTER, getFreeRegIndex());
}
#line 1875 "minlisp.tab.c"
    break;

  case 19:
#line 314 "minlisp.y"
                                           {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'if' expr expr expr ')\n", nodeCounter++); 

    if((yyvsp[-3].symbolPointerType)->type != _BOOL && (yyvsp[-3].symbolPointerType)->type != _UNDETERMINED)
        fprintf(stderr, "Line %d --- Incorrect type for first expression in if expression: Boolean expected\n", yylloc.first_line);

    if(DEBUG)
		fprintf(logsFile_p, "\t_if type expr type: %d\n", (yyvsp[-3].symbolPointerType)->type);

    // print error if types don't match, but ignore if either type is undetermined
    if(
        (yyvsp[-2].symbolPointerType)->type != (yyvsp[-1].symbolPointerType)->type &&
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) 
    ) {
        fprintf(stderr, "Line %d --- Non-matching types used in if statements clauses\n", yylloc.first_line);
    }

    int type = _UNDETERMINED; // if not bool and int types, just pass up undetermined
    if((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED && (yyvsp[-1].symbolPointerType)->type != _UNDETERMINED)
        type = (yyvsp[-1].symbolPointerType)->type;
    else if((yyvsp[-1].symbolPointerType)->type == _UNDETERMINED && (yyvsp[-2].symbolPointerType)->type != _UNDETERMINED)
        type = (yyvsp[-2].symbolPointerType)->type;
    else if((yyvsp[-2].symbolPointerType)->type == (yyvsp[-1].symbolPointerType)->type)
        type = (yyvsp[-2].symbolPointerType)->type;

    // if true first, else second
    // int val = $3->val == 1 ? $4->val : $5->val;

    (yyval.symbolPointerType) = createSymbol("_IF_EXPR_EXPR_EXPR", type, _BOOL, -1);  
}
#line 1911 "minlisp.tab.c"
    break;

  case 20:
#line 345 "minlisp.y"
                                {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'while' expr {} expr ')\n", nodeCounter++); 

    if((yyvsp[0].symbolPointerType)->type != _UNDETERMINED && (yyvsp[0].symbolPointerType)->type != _BOOL) 
        fprintf(stderr, "Line %d --- Incorrect type for first expression in while expression: Boolean expected\n", yylloc.first_line);
}
#line 1923 "minlisp.tab.c"
    break;

  case 21:
#line 351 "minlisp.y"
           {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'while' expr --> expr ')\n", nodeCounter++); 
    
    (yyval.symbolPointerType) = createSymbol("_WHILE_EXPR_EXPR", (yyvsp[-1].symbolPointerType)->type, _BOOL, -1);
}
#line 1934 "minlisp.tab.c"
    break;

  case 22:
#line 358 "minlisp.y"
{
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' ID (%s) actual_list ')'\n", nodeCounter++, (yyvsp[-2].nameVal));  
        _printPL((yyvsp[-1].paramsListType));
    }

    // 1. check scope and throw error
    // 2. check for func
    // 3. check for array - throw err
    // 4. if none - create a func scope
    // 5. print assembly function call, and put return in temp register
    // 6. pass up symbol with temp register of function return

    Symbol* sym_p = (Symbol*) malloc(sizeof(sym_p));
    sym_p = getSymbol(currScope_p, (yyvsp[-2].nameVal));
    FunctionData* funcD_p = getFuncO((yyvsp[-2].nameVal));
    ArrayObj* arrO_p = getArrayO((yyvsp[-2].nameVal));

    int regIndex = getFreeRegIndex();

    if(sym_p) {
        fprintf(stderr, "Line %d --- '%s' is a scope variable, not an function\n", yylloc.first_line, (yyvsp[-2].nameVal));
        sym_p = createSymbol((yyvsp[-2].nameVal), _INT, _REGISTER, regIndex);  
    } else if(funcD_p) {
        
        // check num of params for existing functions
        if(funcD_p->paramsCount != (yyvsp[-1].paramsListType)->count) {
            fprintf(stderr, "Line %d --- Function '%s' expected [%d] number of parms\n", yylloc.first_line, (yyvsp[-2].nameVal), funcD_p->paramsCount);
        }

        for(int i = 0; i < (yyvsp[-1].paramsListType)->count; i++) {
            sym_p = _getFromPL((yyvsp[-1].paramsListType), (yyvsp[-1].paramsListType)->ids_p[i]);
            if(sym_p->type != _INT)
                fprintf(stderr, "Line %d --- Functions expect parameters of type integer. Param at index [%d] is not an integer\n", yylloc.first_line, i);
        }

        sym_p = createSymbol((yyvsp[-2].nameVal), funcD_p->type, _REGISTER, regIndex);

        if(strcasecmp(funcD_p->lexeme, currScope_p->name) == 0) {
            funcD_p->isRecursive = 1; // storing for funsies
            sym_p->type = _INT;
        }

    } else if(arrO_p) {
        fprintf(stderr, "Line %d --- '%s' is a scope variable, not an function\n", yylloc.first_line, (yyvsp[-2].nameVal));
        sym_p = createSymbol((yyvsp[-2].nameVal), _INT, _REGISTER, regIndex);  
    } else {
        FunctionData* undefinedFunc_p = createFuncData((yyvsp[-2].nameVal), (yyvsp[-1].paramsListType)->count, _INT);
        undefinedFunc_p->isUndefined = 1;
        addFunc(undefinedFunc_p);
        fprintf(stderr, "Line %d --- Undeclared function: '%s'\n", yylloc.first_line, (yyvsp[-2].nameVal));
        sym_p = createSymbol((yyvsp[-2].nameVal), _INT, _REGISTER, regIndex);
    }

    genFunctionCall((yyvsp[-2].nameVal));
    printf("movq %%rax, %s\n", genpurpRegName[regIndex]);

    (yyval.symbolPointerType) = sym_p;   
}
#line 1998 "minlisp.tab.c"
    break;

  case 23:
#line 418 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'write' expr ')'\n", nodeCounter++);

    Symbol* exprSym_p = (yyvsp[-1].symbolPointerType);

    if(exprSym_p->type != _INT)
        fprintf(stderr, "Line %d --- 'write' expects an integer type\n", yylloc.first_line);

    exprSym_p->type = _INT;

    if(exprSym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(exprSym_p), genpurpRegName[regIndex]);
        exprSym_p = createSymbol(exprSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    genPrintFunction(symbolMemLoc(exprSym_p));
    
    (yyval.symbolPointerType) = exprSym_p;
}
#line 2024 "minlisp.tab.c"
    break;

  case 24:
#line 440 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'writeln' expr ')'\n", nodeCounter++);    

    Symbol* exprSym_p = (yyvsp[-1].symbolPointerType);

    if(exprSym_p->type != _INT)
        fprintf(stderr, "Line %d --- '_writeln' expects an integer type", yylloc.first_line);

    exprSym_p->type = _INT;

    if(exprSym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(exprSym_p), genpurpRegName[regIndex]);
        exprSym_p = createSymbol(exprSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    
    genPrintFunction(symbolMemLoc(exprSym_p));

    (yyval.symbolPointerType) = exprSym_p;
}
#line 2050 "minlisp.tab.c"
    break;

  case 25:
#line 462 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'read' ')'\n", nodeCounter++); 

    int regIndex = getFreeRegIndex();

    printf("call minlisp_input\n");
    printf("movq %%rax, %s\n", genpurpRegName[regIndex]);

    (yyval.symbolPointerType) = createSymbol("_READ", _INT, _OFFSET, regIndex); 
}
#line 2066 "minlisp.tab.c"
    break;

  case 26:
#line 473 "minlisp.y"
                         {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'let' {} '(' assign_list ')' expr ')'\n", nodeCounter++); 

    // push scope
    createScope(NULL);

}
#line 2079 "minlisp.tab.c"
    break;

  case 27:
#line 480 "minlisp.y"
                      {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' 'let' '(' assign_list ')' {} expr ')'\n", nodeCounter++);    
        printScopeSymbols(currScope_p);
    }
}
#line 2090 "minlisp.tab.c"
    break;

  case 28:
#line 485 "minlisp.y"
           {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' 'let'  '(' assign_list ')' --> expr ')'\n", nodeCounter++);    
    }

    Symbol* sym_p = (yyvsp[-1].symbolPointerType);

    if(sym_p->val_origin == _REGISTER)
        freeRegister(sym_p->val_index);

    (yyvsp[-1].symbolPointerType)->val_origin = _REGISTER;
    (yyvsp[-1].symbolPointerType)->val_index = getFreeRegIndex();

    // pop scope
    currScope_p = currScope_p->enclosingScope_p;

    (yyval.symbolPointerType) = sym_p;
}
#line 2113 "minlisp.tab.c"
    break;

  case 29:
#line 504 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'set' %s expr ')'\n", nodeCounter++, (yyvsp[-2].nameVal));  

    // 1. check scope
    // 2. check for func
    // 3. check for array

    // assuming set can only re-assing values to scope variables, not populate the scope with new variables

    Symbol* sym_p = (Symbol*) malloc(sizeof(sym_p));
    sym_p = getSymbol(currScope_p, (yyvsp[-2].nameVal));

    if(sym_p) {
        if(sym_p->type != (yyvsp[-1].symbolPointerType)->type) 
            fprintf(stderr, "Line %d --- Type mismatch in set statement\n", yylloc.first_line);
        
    } else if(getFuncO((yyvsp[-2].nameVal)) || getArrayO((yyvsp[-2].nameVal))) {
        fprintf(stderr, "Line %d --- `( set ID expr )` can only assign values to local scope variables, not functions or arrays\n", yylloc.first_line);
        sym_p = createSymbol((yyvsp[-2].nameVal), _INT, _REGISTER, getFreeRegIndex()); 
    } else {
        fprintf(stderr, "Line %d --- variable '%s' does not exist in scope\n", yylloc.first_line, (yyvsp[-2].nameVal));
        sym_p = createSymbol((yyvsp[-2].nameVal), _INT, _REGISTER, getFreeRegIndex()); 
    }

    printf("movq %s, %s", symbolMemLoc((yyvsp[-1].symbolPointerType)), symbolMemLoc(sym_p));
    if((yyvsp[-1].symbolPointerType)->val_origin == _REGISTER)
        freeRegister((yyvsp[-1].symbolPointerType)->val_index);

    (yyval.symbolPointerType) = sym_p;
}
#line 2149 "minlisp.tab.c"
    break;

  case 30:
#line 535 "minlisp.y"
                                                  {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'set' %s '[' expr ']' expr ')'\n", nodeCounter++, (yyvsp[-5].nameVal));    

    // 1. check scope and throw error
    // 2. check for function and throw error 
    // 3. check for array - and then check the rest of the array calling protocol

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, (yyvsp[-5].nameVal));
    ArrayObj* arrO_p = getArrayO((yyvsp[-5].nameVal));

    if(sym_p || getFuncO((yyvsp[-5].nameVal))) {
        fprintf(stderr, "Line %d --- `( _set ID [ expr ] expr ')` can only assign values to local scope variables, not functions or arrays\n", yylloc.first_line);
        sym_p = createSymbol((yyvsp[-5].nameVal), _INT, _GLOBAL, -1);
    } else if(arrO_p) {
        // 1. check type of expresion inside brackets
        // 2. check type of rightmost expr

        sym_p = (yyvsp[-1].symbolPointerType);

        // if($5->type != _INT || $5->val < 0) {
        if((yyvsp[-3].symbolPointerType)->type != _INT)
            fprintf(stderr, "Line %d --- Array indices must be type integer and >= 0\n", yylloc.first_line);
        
        if(sym_p->type != _INT)
            fprintf(stderr, "Line %d --- Illegal parameter type: Integer expected. Arrays only store integer types.\n", yylloc.first_line);

        sym_p->type = _INT;
        
    } else {
        fprintf(stderr, "Line %d --- Undeclared array '%s'\n", yylloc.first_line, (yyvsp[-5].nameVal));
        sym_p = createSymbol((yyvsp[-5].nameVal), _INT, _GLOBAL, -1);
    }

    (yyval.symbolPointerType) = sym_p;
}
#line 2191 "minlisp.tab.c"
    break;

  case 31:
#line 573 "minlisp.y"
{
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' '+' expr expr ')'\n", nodeCounter++);  

        fprintf(logsFile_p, "Left - Lex: %s, type: %d\n", (yyvsp[-2].symbolPointerType)->lexeme, (yyvsp[-2].symbolPointerType)->type);
        fprintf(logsFile_p, "Right - Lex: %s, type: %d\n", (yyvsp[-1].symbolPointerType)->lexeme, (yyvsp[-1].symbolPointerType)->type);
    }
         
    // if either expr isn't INT (except undetermined), print an error message, but continue computation
    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator +: Integers expected\n", yylloc.first_line);

    // store register in right, free left
    Symbol* lSym_p = (yyvsp[-2].symbolPointerType);
    Symbol* rSym_p = (yyvsp[-1].symbolPointerType);
    if(DEBUG)
        printf("# addition\n");
    if(rSym_p->val_origin != _REGISTER) {
        // if right isn't a register, make a new register and store right in it
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    // add left to register at right
    printf("addq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));

    // free left if it's a register
    if(lSym_p->val_origin == _REGISTER)
        freeRegister(lSym_p->val_index);

    // right's register
    (yyval.symbolPointerType) = createSymbol("_PLUS_EXP_EXP", _INT, _REGISTER, rSym_p->val_index);
}
#line 2232 "minlisp.tab.c"
    break;

  case 32:
#line 610 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '-' expr expr ')'\n", nodeCounter++);

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    )
        fprintf(stderr, "Line %d --- Incorrect type for operator -: Integers expected\n", yylloc.first_line);
    
    Symbol* lSym_p = (yyvsp[-2].symbolPointerType);
    Symbol* rSym_p = (yyvsp[-1].symbolPointerType);
    if(DEBUG)
        printf("# subtraction\n");
    if(lSym_p->val_origin != _REGISTER) {
        // if left isn't a register, make a new register and store left in it
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(lSym_p), genpurpRegName[regIndex]);
        lSym_p = createSymbol(lSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

                            // right symbol       // left symbol
    printf("subq %s, %s\n", symbolMemLoc(rSym_p), symbolMemLoc(lSym_p));
    // free right
    if(rSym_p->val_origin == _REGISTER)
        freeRegister(rSym_p->val_index);

    // left's register
    (yyval.symbolPointerType) = createSymbol("_MIN_EXP_EXP", _INT, _REGISTER, lSym_p->val_index);
}
#line 2267 "minlisp.tab.c"
    break;

  case 33:
#line 641 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '*' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator *: Integers expected\n", yylloc.first_line);

    Symbol* lSym_p = (yyvsp[-2].symbolPointerType);
    Symbol* rSym_p = (yyvsp[-1].symbolPointerType);if(DEBUG)
        printf("# multiplication\n");
    // if right isn't a register type, make a new register and store right in it
    if(rSym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    printf("imulq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));
    // free left
    if(lSym_p->val_origin == _REGISTER)
        freeRegister(lSym_p->val_index);

    // right's register
    (yyval.symbolPointerType) = createSymbol("_MULT_EXP_EXP", _INT, _REGISTER, rSym_p->val_index);
}
#line 2300 "minlisp.tab.c"
    break;

  case 34:
#line 670 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '/' expr expr ')'\n", nodeCounter++);    
    
    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator /: Integers expected\n", yylloc.first_line);

    Symbol* lSym_p = (yyvsp[-2].symbolPointerType);
    Symbol* rSym_p = (yyvsp[-1].symbolPointerType);
    if(DEBUG)
            printf("# division\n");
    if(lSym_p->val_origin != _REGISTER) {
        // if left isn't a register, make a new register and store left in it
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(lSym_p), genpurpRegName[regIndex]);
        lSym_p = createSymbol(lSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    // hacky - am not passing functions registers to divide func, and since I'm pushing two 8 byte needed registers into the stack I have to increase the value of the offset by 16 for _OFFSET type expressions
    if(rSym_p->val_origin == _OFFSET) {
        Symbol* tempRSym_p = createSymbol("temp", -1, _OFFSET, rSym_p->val_index + 16);
        genDivision(symbolMemLoc(lSym_p), symbolMemLoc(tempRSym_p));
    } else 
        genDivision(symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));

    // free right
    if(rSym_p->val_origin == _REGISTER)
        freeRegister(rSym_p->val_index);

    // left's register
    (yyval.symbolPointerType) = createSymbol("_DIVIDE_EXP_EXP", _INT, _REGISTER, lSym_p->val_index);
}
#line 2340 "minlisp.tab.c"
    break;

  case 35:
#line 705 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '<' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator <: Integers expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_LT_EXP_EXP", _BOOL, _REGISTER, -1);
}
#line 2357 "minlisp.tab.c"
    break;

  case 36:
#line 716 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '>' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator >: Integers expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_GT_EXP_EXP", _BOOL, _REGISTER, -1);
}
#line 2374 "minlisp.tab.c"
    break;

  case 37:
#line 728 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '<=' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator <=: Integers expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_LTE_EXP_EXP", _BOOL, _REGISTER, -1);
}
#line 2391 "minlisp.tab.c"
    break;

  case 38:
#line 740 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '>=' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator >=: Integers expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_GTE_EXP_EXP", _BOOL, _REGISTER, -1);
}
#line 2408 "minlisp.tab.c"
    break;

  case 39:
#line 752 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '=' expr expr ')'\n", nodeCounter++);      

    Symbol* exp_1 = (yyvsp[-2].symbolPointerType);
    Symbol* exp_2 = (yyvsp[-1].symbolPointerType);

    Symbol* sym_p = malloc(sizeof(Symbol));

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator =: Integers expected\n", yylloc.first_line);

    // no matter whether UNDEFINED | INT | BOOl combination, return comparison of two exprs
    sym_p = createSymbol("_EQ_EXP_EXP", _BOOL, _REGISTER, -1);

    if(DEBUG)
		fprintf(logsFile_p, "\tlexeme: %s, type: %d\n", sym_p->lexeme, sym_p->type);

    (yyval.symbolPointerType) = sym_p;
}
#line 2436 "minlisp.tab.c"
    break;

  case 40:
#line 775 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '<>' expr ')'\n", nodeCounter++); 

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _INT || (yyvsp[-1].symbolPointerType)->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator <>: Integers expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_NEQ_EXP_EXP", _BOOL, _REGISTER, -1);   
}
#line 2453 "minlisp.tab.c"
    break;

  case 41:
#line 787 "minlisp.y"
                                 {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '-' expr ')'\n", nodeCounter++);  

    if((yyvsp[-1].symbolPointerType)->type != _UNDETERMINED && (yyvsp[-1].symbolPointerType)->type != _INT)
        fprintf(stderr, "Line %d --- Incorrect type for operator -: Integer expected\n", yylloc.first_line);

    Symbol* sym_p = (yyvsp[-1].symbolPointerType);
    if(sym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(sym_p), genpurpRegName[regIndex]);
        sym_p = createSymbol(sym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    printf("negq %s\n", symbolMemLoc(sym_p));
    (yyval.symbolPointerType) = createSymbol("_NEGAT_EXPR", _INT, _REGISTER, sym_p->val_index);
}
#line 2475 "minlisp.tab.c"
    break;

  case 42:
#line 804 "minlisp.y"
                                       {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'and' expr expr ')'\n", nodeCounter++);

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _BOOL || (yyvsp[-1].symbolPointerType)->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator 'and': Booleans expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_AND", _BOOL, _REGISTER, -1);
}
#line 2492 "minlisp.tab.c"
    break;

  case 43:
#line 816 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '&' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _BOOL || (yyvsp[-1].symbolPointerType)->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator '&': Booleans expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_AND", _BOOL, _REGISTER, -1);
}
#line 2509 "minlisp.tab.c"
    break;

  case 44:
#line 828 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'or' expr expr ')'\n", nodeCounter++); 

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _BOOL || (yyvsp[-1].symbolPointerType)->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator 'or': Booleans expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_OR", _BOOL, _REGISTER, -1);  
}
#line 2526 "minlisp.tab.c"
    break;

  case 45:
#line 840 "minlisp.y"
                                      {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '|' expr expr ')'\n", nodeCounter++);    

    if(
        !((yyvsp[-2].symbolPointerType)->type == _UNDETERMINED || (yyvsp[-1].symbolPointerType)->type == _UNDETERMINED) && 
        ((yyvsp[-2].symbolPointerType)->type != _BOOL || (yyvsp[-1].symbolPointerType)->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator '|': Booleans expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_OR", _BOOL, _REGISTER, -1); 
}
#line 2543 "minlisp.tab.c"
    break;

  case 46:
#line 852 "minlisp.y"
                                  {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'not' expr ')'\n", nodeCounter++);    

    if((yyvsp[-1].symbolPointerType)->type != _UNDETERMINED && (yyvsp[-1].symbolPointerType)->type != _BOOL)
        fprintf(stderr, "Line %d --- Incorrect type for operator 'not': Boolean expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_NEGATION", _BOOL, _REGISTER, -1); 
}
#line 2557 "minlisp.tab.c"
    break;

  case 47:
#line 861 "minlisp.y"
                                 {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '!' expr  ')'\n", nodeCounter++);

    if((yyvsp[-1].symbolPointerType)->type != _UNDETERMINED  && (yyvsp[-1].symbolPointerType)->type != _BOOL)
        fprintf(stderr, "Line %d --- Incorrect type for operator '!': Boolean expected\n", yylloc.first_line);

    (yyval.symbolPointerType) = createSymbol("_NEGATION", _BOOL, _REGISTER, -1); 
}
#line 2571 "minlisp.tab.c"
    break;

  case 48:
#line 870 "minlisp.y"
                                       {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' 'seq' expr_list ')'\n", nodeCounter++);    
        _printPL((yyvsp[-1].paramsListType));
    }   
 
    // last symbol from the hashtable
    Symbol* sym_p  = _getFromPL((yyvsp[-1].paramsListType), (yyvsp[-1].paramsListType)->ids_p[(yyvsp[-1].paramsListType)->count - 1]);
    
    if(DEBUG)
		fprintf(logsFile_p, "last symbol in expr_list - lexeme: %s, type: %d", sym_p->lexeme, sym_p->type);
    
    (yyval.symbolPointerType) = createSymbol("_SEQ_EXPR", sym_p->type, _REGISTER, -1);
}
#line 2590 "minlisp.tab.c"
    break;

  case 49:
#line 886 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) actual_list - actual_list expr\n", nodeCounter++); 
    
    PLScope* plScope_p = (yyvsp[-1].paramsListType);
    Symbol* exprSym_p = (yyvsp[0].symbolPointerType);

    // move expr value into function param register
    printf("movq %s, %s\n", symbolMemLoc(exprSym_p), funcparamRegName[plScope_p->count]);

    // clean expr if it was a temp register - it's not further processed above
    if(exprSym_p->val_origin == _REGISTER)
        freeRegister(exprSym_p->val_index);

    _addToPL(plScope_p, exprSym_p);
        
    (yyval.paramsListType) = plScope_p;  
}
#line 2613 "minlisp.tab.c"
    break;

  case 50:
#line 905 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) actual_list -> ε\n", nodeCounter++);
  
    // left-most node, create a new parameterListScope obj
    (yyval.paramsListType) = _newPLScope();   
}
#line 2625 "minlisp.tab.c"
    break;

  case 51:
#line 914 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) assign_list - assign_list '(' ID (%s) expr ')'\n", nodeCounter++, (yyvsp[-2].nameVal));

    Symbol* scopeNewSym_p = malloc(sizeof(Symbol));
    scopeNewSym_p = getSymbol(currScope_p, (yyvsp[-2].nameVal));

    // lexeme shouldn't exist - if it does its value will getSymbol overwritten
    if(scopeNewSym_p){
        fprintf(stderr, "Line %d --- Parameter %s already defined\n", yylloc.first_line, (yyvsp[-2].nameVal));
        scopeNewSym_p->type = (yyvsp[-1].symbolPointerType)->type;
        scopeNewSym_p->val_origin = _OFFSET;
        scopeNewSym_p->val_index = getClosestEnclosingFunc()->stackOffset;
    } else {
        scopeNewSym_p = createSymbol((yyvsp[-2].nameVal), (yyvsp[-1].symbolPointerType)->type, _OFFSET, getClosestEnclosingFunc()->stackOffset);
        addSymbol(currScope_p, scopeNewSym_p); 
    }

    _addToPL((yyvsp[-4].paramsListType), scopeNewSym_p);

    // generate 'store to stack' statement
    printf("movq %s, %d(%%rsp)\n", symbolMemLoc((yyvsp[-1].symbolPointerType)), getClosestEnclosingFunc()->stackOffset);
    getClosestEnclosingFunc()->stackOffset += 4;    
    // cleanup register for right expr if _REGISTER
    if((yyvsp[-1].symbolPointerType)->val_origin == _REGISTER)
        freeRegister((yyvsp[-1].symbolPointerType)->val_index);

    (yyval.paramsListType) = (yyvsp[-4].paramsListType);  
}
#line 2659 "minlisp.tab.c"
    break;

  case 52:
#line 944 "minlisp.y"
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) assign_list -  '(' %s expr ')'\n", nodeCounter++, (yyvsp[-2].nameVal));

    Symbol* scopeNewSym_p = (Symbol*) malloc(sizeof(Symbol));
    scopeNewSym_p = getSymbol(currScope_p, (yyvsp[-2].nameVal));

    if(scopeNewSym_p)
        fprintf(stderr, "Line %d --- Parameter %s already defined\n", yylloc.first_line, (yyvsp[-2].nameVal));

    scopeNewSym_p = createSymbol((yyvsp[-2].nameVal), (yyvsp[-1].symbolPointerType)->type, _OFFSET, getClosestEnclosingFunc()->stackOffset);
    addSymbol(currScope_p, scopeNewSym_p); 

    // always left-most node for id_list - create a new paramListScope to keep track of assigned objects
    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));
    plScope_p = _newPLScope();
    _addToPL(plScope_p, scopeNewSym_p);

    // generate 'store to stack' statement
    printf("movq %s, %d(%%rsp)\n", symbolMemLoc((yyvsp[-1].symbolPointerType)), getClosestEnclosingFunc()->stackOffset);
    getClosestEnclosingFunc()->stackOffset += 4;
     // cleanup register for right expr if _REGISTER
    if((yyvsp[-1].symbolPointerType)->val_origin == _REGISTER)
        freeRegister((yyvsp[-1].symbolPointerType)->val_index);
    
    (yyval.paramsListType) = plScope_p;  
}
#line 2691 "minlisp.tab.c"
    break;

  case 53:
#line 972 "minlisp.y"
                               {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr_list - expr_list expr\n", nodeCounter++);

    PLScope* plScope_p = (yyvsp[-1].paramsListType);
    _addToPL(plScope_p, (yyvsp[0].symbolPointerType));
    
    (yyval.paramsListType) = plScope_p;
}
#line 2705 "minlisp.tab.c"
    break;

  case 54:
#line 981 "minlisp.y"
                     {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr_list - expr\n", nodeCounter++);

    // always left-most node for expr_list - create a new paramListScope to track list objects
    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));
    plScope_p = _newPLScope();

    _addToPL(plScope_p, (yyvsp[0].symbolPointerType));
    
    (yyval.paramsListType) = plScope_p;  
}
#line 2722 "minlisp.tab.c"
    break;


#line 2726 "minlisp.tab.c"

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
  *++yylsp = yyloc;

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 994 "minlisp.y"


int yyerror(char* s) {
	fprintf(stderr, "\t--- %s - { line: %d }\n", s, yylloc.first_line );
	return 0;
}

int main (void) {
    logsFile_p = fopen (LOGFILE, "w");
    if (DEBUG && logsFile_p == NULL) {
        fprintf(stderr, "Error writing to logs file. Exiting\n");
        exit(1);
    }

    yylloc.first_line = yylloc.last_line = 1;
    yylloc.first_column = yylloc.last_column = 0;
    int result = yyparse();

    return result;
}
