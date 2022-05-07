#include "minlisp.h"

int scopeIdCounter = 0;
int nodeCounter = 0;
Scope* currScope_p = NULL;
GlobalFuncs* globalFuncs_p = NULL;
GlobalArrays* globalArrs_p = NULL;

char* genpurpRegName[GEN_PUR_AVAIL_REGS] = {
    "\%rbx", "\%rbp", "\%r10", "\%r11", "\%r12", "\%r13", "\%r14", "\%r15"
};
char* funcparamRegName[FUNC_PAR_AVAIL_REGS] = {
    "\%rdi", "\%rsi", "\%rdx", "\%rcx", "\%r8", "\%r9"
};
int funcRegs[FUNC_PAR_AVAIL_REGS] = { 1, 1, 1, 1, 1, 1 };

FILE* logsFile_p = NULL;

void initGlobalState() {
    if(!currScope_p && !globalFuncs_p) {
        currScope_p = (Scope *) malloc(sizeof(Scope));
        createScope("top");
        currScope_p->isTopScope = 1;

        createGlobalFuncs();
        createGlobalArrays();
    }
}

// ------

void createScope(char* name) {
    Scope* parent_p = (Scope*) malloc(sizeof(Scope));
    parent_p = currScope_p;
    currScope_p = _newScope();
    currScope_p->enclosingScope_p = parent_p;
    currScope_p->name = (char*) malloc(sizeof(STR_SIZE));
    if(name)
        currScope_p->name = name;
    else {
        // int length = snprintf( NULL, 0, "%d", scopeIdCounter );
        // currScope_p->name  = (char*) malloc( length + 1 );
        // snprintf( currScope_p->name , length + 1, "%d", scopeIdCounter );
        snprintf( currScope_p->name, STR_SIZE, "%d", scopeIdCounter );
    }

    currScope_p->id = scopeIdCounter++;
}

void createFuncScope(char* name) {
    createScope(name);
    currScope_p->isFunction = 1;
}

Scope* _newScope() {

    Scope* newScope_p = (Scope *) malloc(sizeof(Scope));
    newScope_p->count = 0;
    newScope_p->capacity = HASHMAPCAPACITY; 
    newScope_p->hashmap_p = (struct hsearch_data *) malloc(sizeof(struct hsearch_data));
    newScope_p->ids_p = (char **) malloc(HASHMAPCAPACITY * STR_SIZE);
    newScope_p->enclosingScope_p = (Scope *) malloc(sizeof(Scope));
    newScope_p->isTopScope = 0;
    newScope_p->isFunction = 0;

    struct hsearch_data *newHashmap_p = (struct hsearch_data *) calloc(1, sizeof(struct hsearch_data));

    if (hcreate_r(HASHMAPCAPACITY, newHashmap_p) == 0) {
        fprintf(stderr, "Error: Unable to create hashmap for scope.\n");
        exit(0);
    }
    newScope_p->hashmap_p = (struct hsearch_data *) newHashmap_p;

    return newScope_p;
}

// ------

Symbol* createSymbol(
    char lexeme[255], int type, int val_origin, int val_index 
) {
    Symbol* nSymbol_p =  (Symbol*) malloc(sizeof(Symbol));
    nSymbol_p->lexeme = (char *) malloc(sizeof(STR_SIZE));
    strcpy(nSymbol_p->lexeme, lexeme);
    nSymbol_p->type = type;
    
    nSymbol_p->val_origin = val_origin;
    nSymbol_p->val_index = val_index;

    return nSymbol_p;
}

void addSymbol(Scope* scope_p, Symbol* symbol_p) {
   
    ENTRY entry = {
        .key = symbol_p->lexeme,
        .data = symbol_p
    }, *entry_p;

    if (hsearch_r(entry, ENTER, &entry_p, scope_p->hashmap_p) == 0) {
        fprintf(stderr, "Error: entry for token failed into scope's hashtable\n");
        exit(0);
    }
    
    scope_p->ids_p[scope_p->count] = (char *) malloc(STR_SIZE);
    strcpy(scope_p->ids_p[scope_p->count], symbol_p->lexeme);

    scope_p->count++;
}

Symbol* getSymbol(Scope* scope_p, char id[255]){
    // fprintf(logsFile_p, "\n\n--- get '%s' ---", id);

    Scope* currScope_p = scope_p;

    while (1) {
        ENTRY entry = { .key = id };
        ENTRY* entry_p = (ENTRY *) malloc(sizeof(ENTRY));

        hsearch_r(
            entry,
            FIND,
            &entry_p,
            currScope_p->hashmap_p
        );

        if (!entry_p) {
            if (currScope_p->isTopScope) {
                return NULL;
            } else {
                currScope_p = currScope_p->enclosingScope_p;
            }
        } else {
            return (Symbol *)(entry_p->data);
        }
    }
}

void printScopeSymbols(Scope* scope_p) {
    fprintf(logsFile_p, "\n\n--- printing scope symbols ---\n\n");

    Scope* currScope_p = scope_p;

    while (1) {
        fprintf(logsFile_p, "Scope - name: %s, id: %d\n", currScope_p->name, currScope_p->id);
        fprintf(logsFile_p, "[ ");
        ENTRY entry, *entry_p;

        for (int i = 0; i < currScope_p->count; i++) {
            entry.key = (currScope_p->ids_p)[i];

            if (
                hsearch_r(
                    entry,
                    FIND,
                    &entry_p,
                    currScope_p->hashmap_p
                ) == 0
            ){
                fprintf(stderr, "Error: search for lexeme '%s' in scope's hashtbale failed in print\n", entry.key);
                exit(0);
            }
            
            Symbol* sym_p = (Symbol *) (entry_p->data);

            fprintf(
                logsFile_p,
                "{ %s: %d (vo: %d, vi: %d) },  ",
                sym_p->lexeme,
                sym_p->type,
                sym_p->val_origin,
                sym_p->val_index
            );
        }
        fprintf(logsFile_p, "]\n");

        if (!currScope_p->isTopScope)
            currScope_p = currScope_p->enclosingScope_p;
        else
            break;
    }
    fprintf(logsFile_p, "---------------------------------------\n");
}

// ------

void createGlobalFuncs() {
    globalFuncs_p = (GlobalFuncs *) malloc(sizeof(GlobalFuncs));
    globalFuncs_p->count = 0;
    globalFuncs_p->capacity = HASHMAPCAPACITY; 
    globalFuncs_p->hashmap_p = (struct hsearch_data *) malloc(sizeof(struct hsearch_data));
    globalFuncs_p->ids_p = (char **) malloc(HASHMAPCAPACITY * STR_SIZE);

    struct hsearch_data *newHashmap_p = (struct hsearch_data *) calloc(1, sizeof(struct hsearch_data));

     if (hcreate_r(HASHMAPCAPACITY, newHashmap_p) == 0) {
        fprintf(stderr, "Error: Unable to create hashmap for functions.\n");
        exit(0);
    }
    globalFuncs_p->hashmap_p = (struct hsearch_data *) newHashmap_p;
}

FunctionData* createFuncData(char lexeme[255], int paramsCount, int type) {
    FunctionData* funcDataO_p =  (FunctionData*) malloc(sizeof(FunctionData));
    funcDataO_p->lexeme = (char *) malloc(sizeof(STR_SIZE));
    strcpy(funcDataO_p->lexeme, lexeme);
    funcDataO_p->paramsCount = paramsCount;
    funcDataO_p->type = type;
    funcDataO_p->isRecursive = 0;
    funcDataO_p->isUndefined = 0;
    // ^ are for parsing | v are for assembly generation
    funcDataO_p->stackOffset = 4; // start at 4, leave 0 just in case
    funcDataO_p->availRegisters = (int*) malloc(sizeof(int) * GEN_PUR_AVAIL_REGS);
    for(int i = 0; i < GEN_PUR_AVAIL_REGS; i++)
        funcDataO_p->availRegisters[i] = 1;
   
    return funcDataO_p;
}

FunctionData* addFunc(FunctionData* funcDataO_p) {
    ENTRY entry = {
        .key = funcDataO_p->lexeme,
        .data = funcDataO_p
    }, *entry_p;

    if (hsearch_r(entry, ENTER, &entry_p, globalFuncs_p->hashmap_p) == 0) {
        fprintf(stderr, "Error: entry for function data object in global function hashmap\n");
        exit(0);
    }
    
    globalFuncs_p->ids_p[globalFuncs_p->count] = (char *) malloc(STR_SIZE);
    strcpy(globalFuncs_p->ids_p[globalFuncs_p->count], funcDataO_p->lexeme);

    globalFuncs_p->count++;

    return funcDataO_p;
}

FunctionData* getFuncO(char funcName[255]){

    ENTRY entry = { .key = funcName };
    ENTRY* entry_p = (ENTRY *) malloc(sizeof(ENTRY));

    hsearch_r(
        entry,
        FIND,
        &entry_p,
        globalFuncs_p->hashmap_p
    );

    if (!entry_p) 
        return NULL;

    return (FunctionData *) (entry_p->data);
}

void printFuncs() {
    fprintf(logsFile_p, "\n\n--- printing funcs available to global scope ---\n\n");
    FunctionData* func = (FunctionData*) malloc(sizeof(FunctionData));
    for(int i = 0; i < globalFuncs_p->count; i++) {
        func = getFuncO(globalFuncs_p->ids_p[i]);
        fprintf(logsFile_p, "funcName: %s, paramCount: %d, funcReturnType: %d, isRecursive: %d, isUndefined: %d\n", 
            func->lexeme, func->paramsCount, func->type, func->isRecursive, func->isUndefined
        );
    }
    fprintf(logsFile_p, "---------------------------------------\n");
}

FunctionData* getClosestEnclosingFunc() {
    FunctionData* funcDat_p = (FunctionData*) malloc(sizeof(FunctionData));
    Scope* localCurrScope_p = currScope_p;
    while (1) {
       if (!localCurrScope_p->isFunction)
            localCurrScope_p = localCurrScope_p->enclosingScope_p;
        else {
            funcDat_p = getFuncO(localCurrScope_p->name);
            break;
        } 
    }
    return funcDat_p;
}

int* availRegisters() {
    return getClosestEnclosingFunc()->availRegisters;
}

// ------

void createGlobalArrays() {
    // globalArrs_p
    globalArrs_p = (GlobalArrays *) malloc(sizeof(GlobalArrays));
    globalArrs_p->count = 0;
    globalArrs_p->capacity = HASHMAPCAPACITY; 
    globalArrs_p->hashmap_p = (struct hsearch_data *) malloc(sizeof(struct hsearch_data));
    globalArrs_p->ids_p = (char **) malloc(HASHMAPCAPACITY * STR_SIZE);

    struct hsearch_data *newHashmap_p = (struct hsearch_data *) calloc(1, sizeof(struct hsearch_data));

    if (hcreate_r(HASHMAPCAPACITY, newHashmap_p) == 0) {
        fprintf(stderr, "Error: Unable to create hashmap for global arrays.\n");
        exit(0);
    }
    globalArrs_p->hashmap_p = (struct hsearch_data *) newHashmap_p;
}

ArrayObj* addArrToScope(ArrayObj* arrO_p) {
    ENTRY entry = {
        .key = arrO_p->lexeme,
        .data = arrO_p
    }, *entry_p;

    if (hsearch_r(entry, ENTER, &entry_p, globalArrs_p->hashmap_p) == 0) {
        fprintf(stderr, "Error: entry for token failed into global array tracker's hashmap\n");
        exit(0);
    }
    
    globalArrs_p->ids_p[globalArrs_p->count] = (char *) malloc(STR_SIZE);
    strcpy(globalArrs_p->ids_p[globalArrs_p->count], arrO_p->lexeme);

    globalArrs_p->count++;

    return arrO_p;
}

ArrayObj* createArrayO(char* lexeme, int size) {
    ArrayObj* arrO_p = (ArrayObj*) malloc(sizeof(ArrayObj));
    arrO_p->lexeme = (char*) malloc(sizeof(STR_SIZE));
    strcpy(arrO_p->lexeme, lexeme);
    arrO_p->capacity = size;
    arrO_p->arr = (Symbol**) malloc(sizeof(Symbol) * size);
    
    return arrO_p;
}

ArrayObj* getArrayO(char* lexeme) {
    ENTRY entry = { .key = lexeme };
    ENTRY* entry_p = (ENTRY *) malloc(sizeof(ENTRY));

    hsearch_r(
        entry,
        FIND,
        &entry_p,
        globalArrs_p->hashmap_p
    );

    if (!entry_p)
        return NULL;
    
    return (ArrayObj *)(entry_p->data);
}

void printArrays() {
    fprintf(logsFile_p, "\n\n--- printing array entries list ---\n\n");
    Symbol* arrEntry_p = (Symbol*) malloc(sizeof(Symbol));
    for(int i = 0; i < globalArrs_p->count; i++) {
        ArrayObj* arrO_p = getArrayO(globalArrs_p->ids_p[i]);
        fprintf(logsFile_p, "[ ");
        for(int j = 0; j < arrO_p->capacity; j++) {
            arrEntry_p = arrO_p->arr[j];
            if(arrEntry_p)  
                fprintf(logsFile_p, "%s, ", arrEntry_p->lexeme);
            else 
                fprintf(logsFile_p, "NULL, ");
            
        }
        fprintf(logsFile_p, "]");
    }
    fprintf(logsFile_p, "---------------------------------------\n");
}

// ------

PLScope* _newPLScope() {
    PLScope* newPLScope_p = (PLScope *) malloc(sizeof(PLScope));
    newPLScope_p->count = 0;
    newPLScope_p->capacity = HASHMAPCAPACITY; 
    newPLScope_p->hashmap_p = (struct hsearch_data *) malloc(sizeof(struct hsearch_data));
    newPLScope_p->ids_p = (char **) malloc(HASHMAPCAPACITY * STR_SIZE);

    struct hsearch_data *newHashmap_p = (struct hsearch_data *) calloc(1, sizeof(struct hsearch_data));

     if (hcreate_r(HASHMAPCAPACITY, newHashmap_p) == 0) {
        fprintf(stderr, "Error: Unable to create hashmap for parameterList scope.\n");
        exit(0);
    }
    newPLScope_p->hashmap_p = (struct hsearch_data *) newHashmap_p;

    return newPLScope_p;
}

void _addToPL(PLScope* pl_p,  Symbol* symbol_p) {
    ENTRY entry = {
        .key = symbol_p->lexeme,
        .data = symbol_p
    }, *entry_p;

    if (hsearch_r(entry, ENTER, &entry_p, pl_p->hashmap_p) == 0) {
        fprintf(stderr, "Error: entry for token failed into scope's hashtable\n");
        exit(0);
    }
    
    pl_p->ids_p[pl_p->count] = (char *) malloc(STR_SIZE);
    strcpy(pl_p->ids_p[pl_p->count], symbol_p->lexeme);

    pl_p->count++;
}

Symbol* _getFromPL(PLScope* pl_p, char lexeme[255]){

    ENTRY entry = { .key = lexeme };
    ENTRY* entry_p = (ENTRY *) malloc(sizeof(ENTRY));

    hsearch_r(
        entry,
        FIND,
        &entry_p,
        pl_p->hashmap_p
    );

    if (!entry_p) 
        return NULL;

    return (Symbol *) (entry_p->data);
}

void _printPL(PLScope* pl_p) {
    fprintf(logsFile_p, "\n\n--- printing current parameter list ---\n\n");
    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));

    for(int i = 0; i < pl_p->count; i++ ) {
        sym_p = _getFromPL(pl_p, pl_p->ids_p[i]);

        fprintf(logsFile_p, "Symbol - lexeme: %s, type: %d, val_origin: %d, val_index: %d\n", sym_p->lexeme, sym_p->type, sym_p->val_origin, sym_p->val_index);
    }
    fprintf(logsFile_p, "---------------------------------------\n");
}

// ------
int getFreeRegIndex() {
    FunctionData* funcDataO_p = getClosestEnclosingFunc();
    int freeRegister = -1;
    for(int i = 0; i < GEN_PUR_AVAIL_REGS; i++) {
        if(funcDataO_p->availRegisters[i]) {
            funcDataO_p->availRegisters[i] = 0;
            freeRegister = i;
            break;
        }
    }
    if(freeRegister < 0) {
        fprintf(stderr, "Error: Out of registers.\n");
        exit(0);
    }
    return freeRegister;
}

void freeRegister(int index) {
    getClosestEnclosingFunc()->availRegisters[index] = 1;
}

void printAvailRegisters() {
    fprintf(logsFile_p, "\n\n--- printing available general purpose registers ---\n\n");
    FunctionData* funcDataO_p = getClosestEnclosingFunc();
    fprintf(logsFile_p, "[ ");
    for(int i = 0; i < GEN_PUR_AVAIL_REGS; i++) {
        if(funcDataO_p->availRegisters[i])
            fprintf(logsFile_p, "%s ", genpurpRegName[i]);
    }
    fprintf(logsFile_p, "]\n");
    fprintf(logsFile_p, "\n\n---\t\t---\n\n");
}

// --- debugging
void printSymbol(Symbol* sym_p) {
    printf("# { %s: %d (vo: %d, vi: %d) }\n", sym_p->lexeme, sym_p->type, sym_p->val_origin, sym_p->val_index);
    fprintf(logsFile_p, "{ %s: %d (vo: %d, vi: %d) }\n", sym_p->lexeme, sym_p->type, sym_p->val_origin, sym_p->val_index);
}