%{
    #include "minlisp.tab.h"
    #include "minlisp.h"

    // Lex/YACC utilities
    int yylex();
    int yyerror(char *s);
    extern int yylineno;
%}

%locations

%union {
    char* keyword;
    char* nameVal;
    int intVal;
    struct Symbol* symbolPointerType;
    struct PLScope* paramsListType;
}

%token _array _seq _define _if _while _write _writeln _read 
%token _and _or _not _set _let _true _false
%token LTE NEQ GTE
%token ID NUM 

%type<nameVal> ID 
%type<intVal> NUM
%type<symbolPointerType> expr 
%type<paramsListType> id_list param_list assign_list actual_list expr_list


%%  
ML          :   arrays program  {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) ML - arrays program\n", nodeCounter++);
        printFuncs();
        printArrays();
    }

    char* lastF_p = globalFuncs_p->ids_p[globalFuncs_p->count - 1];

    if(strcasecmp(lastF_p, (char*) MAIN) != 0) 
        fprintf(stderr, "Line %d --- Last function must be 'main'.\n", yylloc.first_line);
}
            ;
arrays      :   %empty 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) arrays - __empty__\n", nodeCounter++);

    // always fist node reached - perfect place to initialize global state and print required assembly function headers 
    initGlobalState();

    printf(".text\n");
    printf(".globl minlisp_main\n");
}           
            |  arrays array 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) arrays - arrays array\n", nodeCounter++);

}
            ;
array       :   '(' _array ID NUM ')'    
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) array - '(' 'array' %s %d ')'\n", nodeCounter++, $3, $4);

    if(strcasecmp($3, (char*) MAIN) == 0)
        fprintf(stderr,"Line %d --- Illegal variable name 'main' for arrays'\n", yylloc.first_line);

    ArrayObj* arrO_p = (ArrayObj*) malloc(sizeof(ArrayObj));
    arrO_p = getArrayO($3);

    if(arrO_p) {
        fprintf(stderr, "Line %d --- Array '%s' has already been defined.\n", yylloc.first_line, $3);
    } else {
        int size = $4;
        if(size < 0) {
            fprintf(stderr, "Line %d --- Array indices must be type integer and >= 0\n", yylloc.first_line);
            size = 0;
        }
        addArrToScope(createArrayO($3, size));
    }
}
            ;
program		:   program function    
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) program - program function\n", nodeCounter++);
}
            |   function    
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) program - function\n", nodeCounter++);
}
            ;
function    :   '(' _define ID {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) function - '(' 'define' ID (%s) {} param_list  expr ')'\n", nodeCounter++, $3);

    // 1. check if array
    // 2. check if main

    ArrayObj* arrO_p = getArrayO($3);
    FunctionData* funcD_p = getFuncO($3);

    // check if main is already defined
    if(getFuncO(MAIN))
        fprintf(stderr, "Line %d --- 'main' already defined.\n", yylloc.first_line);

    if(arrO_p) {
        fprintf(stderr, "Line %d --- Variable '%s' already declared in scope as an array\n", yylloc.first_line, $3);
    } else if(funcD_p && funcD_p->isUndefined == 1) {
        funcD_p->type = _INT;
        funcD_p->isUndefined = 0;
    } else if(funcD_p && funcD_p->isUndefined != 1)
        fprintf(stderr, "Line %d --- Function '%s' already declared in scope\n", yylloc.first_line, $3);
    
    if(!funcD_p)
        addFunc(createFuncData($3, 0, _INT));

    // createScope
    createFuncScope($3);

    if(strcasecmp($3, "main") == 0) {
        printf(".type minlisp_main, @function\n");
        printf("minlisp_main:\n");
        printf("subq $128, %%rsp\n");   
    } else 
        genFunctionHeader($3);
    
} param_list expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) function - '(' 'define' ID (%s) --> param_list  expr ')'\n", nodeCounter++, $3);

    FunctionData* funcEntry_p = getFuncO(currScope_p->name);
    // set return type
    funcEntry_p->type = $6->type;

    if(DEBUG)
		fprintf(logsFile_p, "\tReturn type from function %s: %d\n", $3, $6->type);

    // pop func scope
    currScope_p = currScope_p->enclosingScope_p;

    if(strcasecmp($3, "main") == 0){
        printf("addq $128, %%rsp\n");
        printf("ret\n\n");
        printf(".size       minlisp_main, .-minlisp_main\n");
        printf(".section    .note.GNU-stack,\"\",@progbits\n");  
    } else 
        genFunctionFooter();
}
            ;
param_list	:   '(' ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) param_list - '(' ')'\n", nodeCounter++);
    // report function param number to function hashtable entry
    FunctionData* funcEntry_p = getFuncO(currScope_p->name);
    funcEntry_p->paramsCount = 0;

    $$ = NULL;
}
            |   '(' id_list ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) param_list - '(' id_list ')'\n", nodeCounter++);

    int paramsCount = 0;

    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));

    if($2){
        plScope_p = $2;

        if(DEBUG)
            _printPL(plScope_p);
        paramsCount = plScope_p->count;
    }

    // report function param number to function hashtable entry
    FunctionData* funcEntry_p = getFuncO(currScope_p->name);
    funcEntry_p->paramsCount = paramsCount;

    if(DEBUG)
        printFuncs(funcEntry_p);

    $$ = plScope_p;
}
            ;
// internal type - PLScope*
id_list		:   id_list ID 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) id_list - id_list ID (%s)\n", nodeCounter++, $2);
    Symbol* sym_p = malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, $2);

    // use other copy to pass up to param_list for keeps
    PLScope* plScope_p = $1;

    // lexeme shouldn't exist - if it does its value will getSymbol overwritten, for now
    if(sym_p)
        fprintf(stderr, "Line %d --- Parameter '%s' already defined\n", yylloc.first_line, $2);
    else {
        // only addSymbol symbol if it's new to scope

        sym_p = createSymbol($2, _INT, _PARAM, plScope_p->count);
        addSymbol(currScope_p, sym_p); 
        _addToPL(plScope_p, sym_p);
    }
     
    $$ = plScope_p;
}
            |   ID 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) id_list - ID (%s)\n", nodeCounter++, $1);     

    // always left-most node for id_list - create a new paramListScope to keep track of # of and param objects
    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));
    plScope_p = _newPLScope();

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = createSymbol($1, _INT, _PARAM, plScope_p->count);
    addSymbol(currScope_p, sym_p); 

    _addToPL(plScope_p, sym_p);
    
    $$ = plScope_p;        
}
            ;

expr		:   NUM 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - NUM (%d)\n", nodeCounter++, $1);
    
    int regIndex = getFreeRegIndex();

    printf("movq %d, %s\n", $1, genpurpRegName[regIndex]);

    $$ = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, regIndex);
}
            |   ID 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - ID (%s)\n", nodeCounter++, $1);

    // 1. check scope
    // 2. check func
    // 3. check for array and throw error   

    Symbol* sym_p = malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, $1);

    if(!sym_p){
        sym_p = createSymbol($1, _INT, _REGISTER, getFreeRegIndex());

        FunctionData* funcD_p = getFuncO($1);
        ArrayObj* arrO_p = getArrayO($1);

        if(funcD_p) {
            if(funcD_p->paramsCount != 0)  
                 fprintf(stderr, "Line %d --- Function '%s' expected [%d] parms\n", yylloc.first_line, $1, funcD_p->paramsCount);
                 
            sym_p->type = funcD_p->type;
        } else if(arrO_p) 
            fprintf(stderr, "Line %d --- Array used incorrectly: '%s'\n", yylloc.first_line, $1);
        else 
            fprintf(stderr, "Line %d --- Undeclared variable '%s'\n", yylloc.first_line, $1);
    }

    $$ = sym_p;
}
            |   ID  '[' expr ']' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - ID (%s) '[' expr ']'\n", nodeCounter++, $1);  

    // 1. check scope and throw error
    // 2. check for function and throw error 
    // 3. check for array - and then check the rest of the array calling protocol

    Symbol* sym_p = getSymbol(currScope_p, $1);
    FunctionData* funcD_p = getFuncO($1);
    ArrayObj* arrO_p = getArrayO($1);

    if(sym_p) {
        fprintf(stderr, "Line %d --- '%s' is a scope variable, not an array\n", yylloc.first_line, $1);
    } else if(funcD_p) {
        fprintf(stderr, "Line %d --- '%s' is a function, not an array\n", yylloc.first_line, $1);
    } else if(arrO_p) {
        // if($3->type != _INT || $3->val < 0) 
        if($3->type != _INT)
            fprintf(stderr, "Line %d --- Array indices must be type integer and >= 0\n", yylloc.first_line);
        // here we calculate the value to return
    } else 
        fprintf(stderr, "Line %d --- Undeclared array '%s'\n", yylloc.first_line, $1);
    
    $$ = createSymbol($1, _INT, _GLOBAL, -1);  
}
            |   _true 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - 'true'\n", nodeCounter++);    

    // these should just be static symbols
    $$ = createSymbol("_TRUE", _BOOL, _REGISTER, getFreeRegIndex());
}
            |   _false 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - 'false'\n", nodeCounter++);

    $$ = createSymbol("_FALSE", _BOOL, _REGISTER, getFreeRegIndex());
}
            |   '(' _if expr expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'if' expr expr expr ')\n", nodeCounter++); 

    if($3->type != _BOOL && $3->type != _UNDETERMINED)
        fprintf(stderr, "Line %d --- Incorrect type for first expression in if expression: Boolean expected\n", yylloc.first_line);

    if(DEBUG)
		fprintf(logsFile_p, "\t_if type expr type: %d\n", $3->type);

    // print error if types don't match, but ignore if either type is undetermined
    if(
        $4->type != $5->type &&
        !($4->type == _UNDETERMINED || $5->type == _UNDETERMINED) 
    ) {
        fprintf(stderr, "Line %d --- Non-matching types used in if statements clauses\n", yylloc.first_line);
    }

    int type = _UNDETERMINED; // if not bool and int types, just pass up undetermined
    if($4->type == _UNDETERMINED && $5->type != _UNDETERMINED)
        type = $5->type;
    else if($5->type == _UNDETERMINED && $4->type != _UNDETERMINED)
        type = $4->type;
    else if($4->type == $5->type)
        type = $4->type;

    // if true first, else second
    // int val = $3->val == 1 ? $4->val : $5->val;

    $$ = createSymbol("_IF_EXPR_EXPR_EXPR", type, _BOOL, -1);  
}
            |   '(' _while expr {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'while' expr {} expr ')\n", nodeCounter++); 

    if($3->type != _UNDETERMINED && $3->type != _BOOL) 
        fprintf(stderr, "Line %d --- Incorrect type for first expression in while expression: Boolean expected\n", yylloc.first_line);
} expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'while' expr --> expr ')\n", nodeCounter++); 
    
    $$ = createSymbol("_WHILE_EXPR_EXPR", $5->type, _BOOL, -1);
}
            |   '(' ID actual_list ')' 
{
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' ID (%s) actual_list ')'\n", nodeCounter++, $2);  
        _printPL($3);
    }

    // 0.1 generate assembly function calling code and returning code
    PLScope* plScope_p = $3;
    if(plScope_p) {
        for(int i = 0; i < plScope_p->count; i++) {
            Symbol* paramSym_p = _getFromPL(plScope_p, plScope_p->ids_p[i]);
            printf("movq %s, %s\n", symbolMemLoc(paramSym_p), funcparamRegName[i]);
            // cleanup parameters's register if it was a temporary variable
            if(paramSym_p->val_origin == _REGISTER)
                freeRegister(paramSym_p->val_index);
        }
    }
    genFunctionCall($2);
    // 0.2 store function resuilt register into temporary register for the expr symbol
    int regIndex = getFreeRegIndex();
    printf("movq %%rax, %s\n", funcparamRegName[regIndex]);

    // 1. check scope and throw error
    // 2. check for func
    // 3. check for array - throw err

    Symbol* sym_p = (Symbol*) malloc(sizeof(sym_p));
    sym_p = getSymbol(currScope_p, $2);
    FunctionData* funcD_p = getFuncO($2);
    ArrayObj* arrO_p = getArrayO($2);

    if(sym_p) {
        fprintf(stderr, "Line %d --- '%s' is a scope variable, not an function\n", yylloc.first_line, $2);
        sym_p = createSymbol($2, _INT, _REGISTER, regIndex);  
    } else if(funcD_p) {
        
        // check num of params for existing functions
        if(funcD_p->paramsCount != $3->count) {
            fprintf(stderr, "Line %d --- Function '%s' expected [%d] number of parms\n", yylloc.first_line, $2, funcD_p->paramsCount);
        }

        for(int i = 0; i < $3->count; i++) {
            sym_p = _getFromPL($3, $3->ids_p[i]);
            if(sym_p->type != _INT)
                fprintf(stderr, "Line %d --- Functions expect parameters of type integer. Param at index [%d] is not an integer\n", yylloc.first_line, i);
        }

        sym_p = createSymbol($2, funcD_p->type, _REGISTER, regIndex);

        if(strcasecmp(funcD_p->lexeme, currScope_p->name) == 0) {
            funcD_p->isRecursive = 1; // storing for funsies
            sym_p->type = _INT;
        }

    } else if(arrO_p) {
        fprintf(stderr, "Line %d --- '%s' is a scope variable, not an function\n", yylloc.first_line, $2);
        sym_p = createSymbol($2, _INT, _REGISTER, regIndex);  
    } else {
        FunctionData* undefinedFunc_p = createFuncData($2, $3->count, _INT);
        undefinedFunc_p->isUndefined = 1;
        addFunc(undefinedFunc_p);
        fprintf(stderr, "Line %d --- Undeclared function: '%s'\n", yylloc.first_line, $2);
        sym_p = createSymbol($2, _INT, _REGISTER, regIndex);
    }

    $$ = sym_p;   
}
            |   '(' _write expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'write' expr ')'\n", nodeCounter++);

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = $3;

    if(sym_p->type != _INT && sym_p->type != _UNDETERMINED)
        fprintf(stderr, "Line %d --- 'write' expects an integer type\n", yylloc.first_line);

    sym_p->type = _INT;

    if(sym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(sym_p), genpurpRegName[regIndex]);
        sym_p = createSymbol(sym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    genPrintFunction(symbolMemLoc(sym_p));
    $$ = sym_p;
}
            |   '(' _writeln expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'writeln' expr ')'\n", nodeCounter++);    

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = $3;

    if(sym_p->type != _INT && sym_p->type != _UNDETERMINED)
        fprintf(stderr, "Line %d --- '_writeln' expects an integer type", yylloc.first_line);

    sym_p->type = _INT;

    if(sym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(sym_p), genpurpRegName[regIndex]);
        sym_p = createSymbol(sym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    genPrintFunction(symbolMemLoc(sym_p));
    $$ = sym_p;
}
            |   '(' _read ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'read' ')'\n", nodeCounter++); 

    int regIndex = getFreeRegIndex();

    printf("call minlisp_input\n");
    printf("movq %%rax, %s\n", genpurpRegName[regIndex]);

    $$ = createSymbol("_READ", _INT, _REGISTER, regIndex); 
}
            |   '(' _let {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'let' {} '(' assign_list ')' expr ')'\n", nodeCounter++); 

    // push scope
    createScope(NULL);

} '(' assign_list ')' {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' 'let' '(' assign_list ')' {} expr ')'\n", nodeCounter++);    
        printScopeSymbols(currScope_p);
    }
} expr ')' {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' 'let'  '(' assign_list ')' --> expr ')'\n", nodeCounter++);    
    }

    Symbol* sym_p = $8;

    if(sym_p->val_origin == _REGISTER)
        freeRegister(sym_p->val_index);

    $8->val_origin = _REGISTER;
    $8->val_index = getFreeRegIndex();

    // pop scope
    currScope_p = currScope_p->enclosingScope_p;

    $$ = sym_p;
} 
            |   '(' _set ID expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'set' %s expr ')'\n", nodeCounter++, $3);  

    // 1. check scope
    // 2. check for func
    // 3. check for array

    // assuming set can only re-assing values to scope variables, not populate the scope with new variables

    Symbol* sym_p = (Symbol*) malloc(sizeof(sym_p));
    sym_p = getSymbol(currScope_p, $3);

    if(sym_p) {
        if(sym_p->type != $4->type) 
            fprintf(stderr, "Line %d --- Type mismatch in set statement\n", yylloc.first_line);
        
    } else if(getFuncO($3) || getArrayO($3)) {
        fprintf(stderr, "Line %d --- `( set ID expr )` can only assign values to local scope variables, not functions or arrays\n", yylloc.first_line);
        sym_p = createSymbol($3, _INT, _REGISTER, getFreeRegIndex()); 
    } else {
        fprintf(stderr, "Line %d --- variable '%s' does not exist in scope\n", yylloc.first_line, $3);
        sym_p = createSymbol($3, _INT, _REGISTER, getFreeRegIndex()); 
    }

    printf("movq %s, %s", symbolMemLoc($4), symbolMemLoc(sym_p));
    if($4->val_origin == _REGISTER)
        freeRegister($4->val_index);

    $$ = sym_p;
}
            |   '(' _set ID '[' expr ']' expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'set' %s '[' expr ']' expr ')'\n", nodeCounter++, $3);    

    // 1. check scope and throw error
    // 2. check for function and throw error 
    // 3. check for array - and then check the rest of the array calling protocol

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, $3);
    ArrayObj* arrO_p = getArrayO($3);

    if(sym_p || getFuncO($3)) {
        fprintf(stderr, "Line %d --- `( _set ID [ expr ] expr ')` can only assign values to local scope variables, not functions or arrays\n", yylloc.first_line);
        sym_p = createSymbol($3, _INT, _GLOBAL, -1);
    } else if(arrO_p) {
        // 1. check type of expresion inside brackets
        // 2. check type of rightmost expr

        sym_p = $7;

        // if($5->type != _INT || $5->val < 0) {
        if($5->type != _INT)
            fprintf(stderr, "Line %d --- Array indices must be type integer and >= 0\n", yylloc.first_line);
        
        if(sym_p->type != _INT)
            fprintf(stderr, "Line %d --- Illegal parameter type: Integer expected. Arrays only store integer types.\n", yylloc.first_line);

        sym_p->type = _INT;
        
    } else {
        fprintf(stderr, "Line %d --- Undeclared array '%s'\n", yylloc.first_line, $3);
        sym_p = createSymbol($3, _INT, _GLOBAL, -1);
    }

    $$ = sym_p;
}
            |   '(' '+' expr expr ')' 
{
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' '+' expr expr ')'\n", nodeCounter++);  

        fprintf(stderr, "Left - Lex: %s, type: %d\n", $3->lexeme, $3->type);
        fprintf(stderr, "Right - Lex: %s, type: %d\n", $4->lexeme, $4->type);
    }
         
    // if either expr isn't INT (except undetermined), print an error message, but continue computation
    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator +: Integers expected\n", yylloc.first_line);

    // store register in right, free left
    Symbol* lSym_p = $3;
    Symbol* rSym_p = $4;
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
    $$ = createSymbol("_PLUS_EXP_EXP", _INT, _REGISTER, rSym_p->val_index);
}
            |   '(' '-' expr expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '-' expr expr ')'\n", nodeCounter++);

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    )
        fprintf(stderr, "Line %d --- Incorrect type for operator -: Integers expected\n", yylloc.first_line);
    
    Symbol* lSym_p = $3;
    Symbol* rSym_p = $4;

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
    $$ = createSymbol("_MIN_EXP_EXP", _INT, _REGISTER, lSym_p->val_index);
}
            |   '(' '*' expr expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '*' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator *: Integers expected\n", yylloc.first_line);

    Symbol* lSym_p = $3;
    Symbol* rSym_p = $4;
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
    $$ = createSymbol("_MULT_EXP_EXP", _INT, _REGISTER, rSym_p->val_index);
}
            |   '(' '/' expr expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '/' expr expr ')'\n", nodeCounter++);    
    
    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator /: Integers expected\n", yylloc.first_line);

    Symbol* lSym_p = $3;
    Symbol* rSym_p = $4;

    if(lSym_p->val_origin != _REGISTER) {
        // if left isn't a register, make a new register and store left in it
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(lSym_p), genpurpRegName[regIndex]);
        lSym_p = createSymbol(lSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    
    genDivision(symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));
    // free right
    if(rSym_p->val_origin == _REGISTER)
        freeRegister(rSym_p->val_index);

    // left's register
    $$ = createSymbol("_DIVIDE_EXP_EXP", _INT, _REGISTER, lSym_p->val_index);
}
            |   '(' '<' expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '<' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator <: Integers expected\n", yylloc.first_line);

    $$ = createSymbol("_LT_EXP_EXP", _BOOL, _REGISTER, -1);
}           |   '(' '>' expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '>' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator >: Integers expected\n", yylloc.first_line);

    $$ = createSymbol("_GT_EXP_EXP", _BOOL, _REGISTER, -1);
}
            |   '(' LTE expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '<=' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator <=: Integers expected\n", yylloc.first_line);

    $$ = createSymbol("_LTE_EXP_EXP", _BOOL, _REGISTER, -1);
}
            |   '(' GTE expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '>=' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator >=: Integers expected\n", yylloc.first_line);

    $$ = createSymbol("_GTE_EXP_EXP", _BOOL, _REGISTER, -1);
}
            |   '(' '=' expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '=' expr expr ')'\n", nodeCounter++);      

    Symbol* exp_1 = $3;
    Symbol* exp_2 = $4;

    Symbol* sym_p = malloc(sizeof(Symbol));

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator =: Integers expected\n", yylloc.first_line);

    // no matter whether UNDEFINED | INT | BOOl combination, return comparison of two exprs
    sym_p = createSymbol("_EQ_EXP_EXP", _BOOL, _REGISTER, -1);

    if(DEBUG)
		fprintf(logsFile_p, "\tlexeme: %s, type: %d\n", sym_p->lexeme, sym_p->type);

    $$ = sym_p;
}
            |   '(' NEQ expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '<>' expr ')'\n", nodeCounter++); 

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _INT || $4->type != _INT) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator <>: Integers expected\n", yylloc.first_line);

    $$ = createSymbol("_NEQ_EXP_EXP", _BOOL, _REGISTER, -1);   
}
            |   '(' '-' expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '-' expr ')'\n", nodeCounter++);  

    if($3->type != _UNDETERMINED && $3->type != _INT)
        fprintf(stderr, "Line %d --- Incorrect type for operator -: Integer expected\n", yylloc.first_line);

    Symbol* sym_p = $3;
    if(sym_p->val_origin != _REGISTER) {
        int regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(sym_p), genpurpRegName[regIndex]);
        sym_p = createSymbol(sym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    printf("negq %s\n", symbolMemLoc(sym_p));
    $$ = createSymbol("_NEGAT_EXPR", _INT, _REGISTER, sym_p->val_index);
}
            |   '(' _and expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'and' expr expr ')'\n", nodeCounter++);

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _BOOL || $4->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator 'and': Booleans expected\n", yylloc.first_line);

    $$ = createSymbol("_AND", _BOOL, _REGISTER, -1);
}
            |   '(' '&' expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '&' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _BOOL || $4->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator '&': Booleans expected\n", yylloc.first_line);

    $$ = createSymbol("_AND", _BOOL, _REGISTER, -1);
}
            |   '(' _or expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'or' expr expr ')'\n", nodeCounter++); 

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _BOOL || $4->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator 'or': Booleans expected\n", yylloc.first_line);

    $$ = createSymbol("_OR", _BOOL, _REGISTER, -1);  
}
            |   '(' '|' expr expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '|' expr expr ')'\n", nodeCounter++);    

    if(
        !($3->type == _UNDETERMINED || $4->type == _UNDETERMINED) && 
        ($3->type != _BOOL || $4->type != _BOOL) 
    ) 
        fprintf(stderr, "Line %d --- Incorrect type for operator '|': Booleans expected\n", yylloc.first_line);

    $$ = createSymbol("_OR", _BOOL, _REGISTER, -1); 
}
            |   '(' _not expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' 'not' expr ')'\n", nodeCounter++);    

    if($3->type != _UNDETERMINED && $3->type != _BOOL)
        fprintf(stderr, "Line %d --- Incorrect type for operator 'not': Boolean expected\n", yylloc.first_line);

    $$ = createSymbol("_NEGATION", _BOOL, _REGISTER, -1); 
}
            |   '(' '!' expr ')' {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr - '(' '!' expr  ')'\n", nodeCounter++);

    if($3->type != _UNDETERMINED  && $3->type != _BOOL)
        fprintf(stderr, "Line %d --- Incorrect type for operator '!': Boolean expected\n", yylloc.first_line);

    $$ = createSymbol("_NEGATION", _BOOL, _REGISTER, -1); 
}
            |   '(' _seq expr_list ')' {
    if(DEBUG) {
		fprintf(logsFile_p, "(%d) expr - '(' 'seq' expr_list ')'\n", nodeCounter++);    
        _printPL($3);
    }   
 
    // last symbol from the hashtable
    Symbol* sym_p  = _getFromPL($3, $3->ids_p[$3->count - 1]);
    
    if(DEBUG)
		fprintf(logsFile_p, "last symbol in expr_list - lexeme: %s, type: %d", sym_p->lexeme, sym_p->type);
    
    $$ = createSymbol("_SEQ_EXPR", sym_p->type, _REGISTER, -1);
}
            ;
actual_list	:   %empty 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) actual_list -> ε\n", nodeCounter++);
  
    // left-most node, create a new parameterListScope obj
    $$ = _newPLScope();   
}
            |   actual_list expr 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) actual_list - actual_list expr\n", nodeCounter++); 
    
    PLScope* plScope_p = $1;

    _addToPL(plScope_p, $2);
        
    $$ = plScope_p;  
}
            ;
assign_list	:   assign_list '(' ID expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) assign_list - assign_list '(' ID (%s) expr ')'\n", nodeCounter++, $3);

    Symbol* sym_p = malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, $3);

    // lexeme shouldn't exist - if it does its value will getSymbol overwritten
    if(sym_p){
        fprintf(stderr, "Line %d --- Parameter %s already defined\n", yylloc.first_line, $3);
        sym_p->type = $4->type;
        sym_p->val_origin = _OFFSET;
        sym_p->val_index = getClosestEnclosingFunc()->stackOffset;
    } else {
        sym_p = createSymbol($3, $4->type, _OFFSET, getClosestEnclosingFunc()->stackOffset);
        addSymbol(currScope_p, sym_p); 
    }

    _addToPL($1, sym_p);

    // generate 'store to stack' statement
    printf("movq %s, %d(%%rsp)\n", symbolMemLoc(sym_p), sym_p->val_index);
    getClosestEnclosingFunc()->stackOffset += 4;    
    // cleanup register for right expr if _REGISTER
    if($4->val_origin == _REGISTER)
        freeRegister($4->val_index);

    $$ = $1;  
}
            |   '(' ID expr ')' 
{
    if(DEBUG)
		fprintf(logsFile_p, "(%d) assign_list -  '(' %s expr ')'\n", nodeCounter++, $2);

    Symbol* sym_p = (Symbol*) malloc(sizeof(Symbol));
    sym_p = getSymbol(currScope_p, $2);

    if(sym_p)
        fprintf(stderr, "Line %d --- Parameter %s already defined\n", yylloc.first_line, $3);

    sym_p = createSymbol($2, $3->type, _OFFSET, getClosestEnclosingFunc()->stackOffset);
    addSymbol(currScope_p, sym_p); 

    // always left-most node for id_list - create a new paramListScope to keep track of assigned objects
    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));
    plScope_p = _newPLScope();
    _addToPL(plScope_p, sym_p);

    // generate 'store to stack' statement
    printf("movq %s, %d(%%rsp)\n", symbolMemLoc(sym_p), sym_p->val_index);
    getClosestEnclosingFunc()->stackOffset += 4;
     // cleanup register for right expr if _REGISTER
    if($3->val_origin == _REGISTER)
        freeRegister($3->val_index);
    
    $$ = plScope_p;  
}
            ;
expr_list   :   expr_list expr {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr_list - expr_list expr\n", nodeCounter++);

    PLScope* plScope_p = $1;
    _addToPL(plScope_p, $2);
    
    $$ = plScope_p;
}
            |   expr {
    if(DEBUG)
		fprintf(logsFile_p, "(%d) expr_list - expr\n", nodeCounter++);

    // always left-most node for expr_list - create a new paramListScope to track list objects
    PLScope* plScope_p = (PLScope*) malloc(sizeof(PLScope));
    plScope_p = _newPLScope();

    _addToPL(plScope_p, $1);
    
    $$ = plScope_p;  
}
            ;
%%

int yyerror(char* s) {
	fprintf(stderr, "\t--- %s - { line: %d }\n", s, yylloc.first_line );
	return 0;
}

int main (void) {
    if (DEBUG && logsFile_p == NULL) {
        fprintf(stderr, "Error writing to logs file. Exiting\n");
        exit(1);
    }

    yylloc.first_line = yylloc.last_line = 1;
    yylloc.first_column = yylloc.last_column = 0;
    int result = yyparse();

    return result;
}