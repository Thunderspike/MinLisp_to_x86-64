#define _GNU_SOURCE

#define DEBUG 1
#define LOGFILE "logs.txt"

#define STR_SIZE 255
#define HASHMAPCAPACITY 30
#define MAIN "main"

#define _UNSASSIGNED 0 // unused
#define _INT 1
#define _BOOL 2
#define _UNDETERMINED 3
#define _PARAMLIST 4

// where will the value for the symbol be stored
#define _OFFSET 0
#define _REGISTER 1
#define _PARAM 2
#define _GLOBAL 3 // assuming GLOBAL will be the array name

#define GEN_PUR_AVAIL_REGS 8
#define FUNC_PAR_AVAIL_REGS 6
#define LABELSTACKDEPTH 10

#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

// int scopeIdCounter = 0;
// int nodeCounter = 0;
// Scope* currScope_p = NULL;
// GlobalFuncs* globalFuncs_p = NULL;
// GlobalArrays* globalArrs_p = NULL;

// Symbol table utilities
typedef struct Scope {
    int id;
    char* name;
    int count; // switchToSymbolCount ideally
    int capacity;
    struct hsearch_data *hashmap_p;
    char** ids_p; // rename this to symbolIds ideally
    struct Scope* enclosingScope_p;
    int isTopScope;
    int isFunction;
} Scope;

// creates top scope, points currScope, and creates global function scope
void initGlobalState(); 
void createScope(char* name);
void createFuncScope(char* name); // the same except sets isFunction = 1
Scope* _newScope();

// ------
// the workhorse grammar object, as well as what's stored in the Scope's symbol (hash) table
typedef struct Symbol {
    char* lexeme;
    int type;
    // ^ are for parsing | v are for assembly generation
    int val_origin;
    int val_index; // value index will change its meaning depending on value_origin.
    // OFFSET = offset in stack, REGISTER = free register index, GLOBAL = array names index
} Symbol;

Symbol* createSymbol(
    char lexeme[255], int type, int val_origin, int val_index 
);
void addSymbol(Scope*, Symbol*);
Symbol* getSymbol(Scope* scope_p, char id[255]);
void printScopeSymbols(Scope*);

// ------
// keep track of functions in global scope
typedef struct GlobalFunctionsEnumerator {
    int count;
    int capacity;
    struct hsearch_data *hashmap_p;
    char** ids_p;
} GlobalFuncs;

// function data object
typedef struct FunctionData {
    char* lexeme;
    int paramsCount;
    int type;
    int isRecursive;
    int isUndefined;
    // ^ are for parsing | v are for assembly generation
    int stackOffset;
    int* availRegisters; 
} FunctionData;

// CRUD ops for global function object
void createGlobalFuncs();
FunctionData* createFuncData(char lexeme[255], int paramsCount, int type);
FunctionData* addFunc(FunctionData* funcDataO_p);
FunctionData* getFuncO(char funcName[255]);
void printFuncs();
FunctionData* getClosestEnclosingFunc();
int* availRegisters();

// ----
// keeps track of arrays in global scope
typedef struct GlobalArraysEnumerator {
    int count;
    int capacity;
    struct hsearch_data *hashmap_p;
    char** ids_p;
} GlobalArrays;

typedef struct ArrayObject {
    char* lexeme;
    int capacity;
    Symbol** arr;
} ArrayObj;

// CRUD ops for global array management
void createGlobalArrays();
ArrayObj* addArrToScope(ArrayObj* arrO_p);
ArrayObj* createArrayO(char* lexeme, int size);
ArrayObj* getArrayO(char* lexeme);
void printArrays();

// ------
// YYAC grammar specific utilities

// params list grammar types - id_list & assign_list are making use of it to keep track of count
typedef struct PLScope {
    int count;
    int capacity;
    struct hsearch_data *hashmap_p;
    char** ids_p;
} PLScope;

PLScope* _newPLScope();
void _addToPL(PLScope* pl_p,  Symbol* symbol_p);
Symbol* _getFromPL(PLScope* pl_p, char lexeme[255]);
void _printPL(PLScope* pl_p);

// ------
// IR / Code generation specific utilities
int getFreeRegIndex();
void freeRegister(int index);
void printAvailRegisters();

// ------
// Global Labels Stack for branching
typedef struct GlobalLabelStack {
    int labelCounter;
    int top;
    unsigned capacity;
    int* array;
} GLS;

void createGLS(unsigned capacity);
int pushGLS();
int popGLS();
int peekGLS();

// ------
// x86-64 code generation utilities
char* symbolMemLoc(Symbol* sym_p);
void genPrintFunction(char* reg);
void genDivision(char* dividentReg, char* divisorReg);
void genFunctionHeader(char funcName[255]);
void genFunctionFooter();
void genSaveFuncParams();
void genFunctionCall(char funcName[255]);
int genInequalityExpr(Symbol* lSym_p, Symbol* rSym_p, char* ineqOp);
int genLogiInequalityExpr(Symbol* lSym_p, Symbol* rSym_p, char* ineqOp);
void genNotFunc();

// ------
// Extern variable declaration

extern int scopeIdCounter;
extern int nodeCounter;
extern Scope* currScope_p;
extern GlobalFuncs* globalFuncs_p;
extern GlobalArrays* globalArrs_p;
extern GLS* gls_p;

extern char* genpurpRegName[GEN_PUR_AVAIL_REGS];
extern char* funcparamRegName[FUNC_PAR_AVAIL_REGS];
extern int funcRegs[FUNC_PAR_AVAIL_REGS];

extern FILE* logsFile_p;

// --- debugging
void printSymbol(Symbol* sym_p);