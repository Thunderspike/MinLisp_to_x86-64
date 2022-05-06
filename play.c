#include "minlisp.h"

void generateAdd();
void generateMain();

int main() { 
    // printRegisters();
    
    // int a = getRegister();
    // int b = getRegister();
    // int c = getRegister();

    // printRegisters();

    // freeRegister(b);

    // printRegisters();

    generateAdd();
    generateMain();

    return 0;
}

void generateAdd() {
    // when passing params we store 8 bits
    // write expects 8 bit
    // read returns 8 bit?
    // return from function is 8 bit
    // defining locals is 4 bit
    // defining temporary registers for hardcoded values is 4 bit

    // start new .s file
    printf(".text\n");
    printf(".globl minlisp_main\n");

    initGlobalState();
    addFunc(createFuncData("add", 2, _INT));
    createScope("add");
    currScope_p->isFunction = 1;
    genFunctionHeader("add");
  
    PLScope* pl_Scope = _newPLScope();
    Symbol* x = createSymbol("x", _INT, _PARAM, pl_Scope->count);
    addSymbol(currScope_p, x);
    _addToPL(pl_Scope, x);
    Symbol* y = createSymbol("y", _INT, _PARAM, pl_Scope->count);
    addSymbol(currScope_p, y);
    _addToPL(pl_Scope, y);

    int regIndex;
    Symbol* lSym_p;
    Symbol* rSym_p;
    Symbol* xSym_p;
    Symbol* ySym_p;

    // ---

    // expr -> NUM
    Symbol* num22Sym_p = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, getFreeRegIndex());
    printf("movq $22, %s\n", genpurpRegName[num22Sym_p->val_index]);

    // expr -> NUM
    Symbol* num20Sym_p = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, getFreeRegIndex());
    printf("movq $20, %s\n", genpurpRegName[num20Sym_p->val_index]);

    // ---

    // expr -> ( + expr expr )
    // store result in right, free left
    lSym_p = num22Sym_p;
    rSym_p = num20Sym_p;
    if(rSym_p->val_origin != _REGISTER) {
        // if right isn't a register, make a new register and store right in it
        regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    // add left to register at right
    printf("addq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));

    // free left if it's a register
    if(lSym_p->val_origin == _REGISTER)
        freeRegister(lSym_p->val_index);

    // right's register
    Symbol* plus22_20 = createSymbol("_PLUS_EXP_EXP", _INT, _REGISTER, rSym_p->val_index);

    // ---

    // expr -> NUM
    Symbol* num5Sym_p = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, getFreeRegIndex());
    printf("movq $5, %s\n", genpurpRegName[num5Sym_p->val_index]);

    // expr -> ID
    ySym_p = getSymbol(currScope_p, (char*)"y");

    // expr -> ( - expr )
    rSym_p = ySym_p;
    if(rSym_p->val_origin != _REGISTER) {
        regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    printf("negq %s\n", symbolMemLoc(rSym_p));
    Symbol* negSym = createSymbol("_NEGAT_EXPR", _INT, _REGISTER, rSym_p->val_index);

    // ---

    // expr -> ( * expr expr )
    // store result in right, free left
    lSym_p = num5Sym_p;
    rSym_p = negSym;
    // if right isn't a register type, make a new register and store right in it
    if(rSym_p->val_origin != _REGISTER) {
        regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

    printf("imulq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));
    // free left
    if(lSym_p->val_origin == _REGISTER)
        freeRegister(lSym_p->val_index);

    // right's register
    Symbol* mult5NegY = createSymbol("_MULT_EXP_EXP", _INT, _REGISTER, rSym_p->val_index);

    // ------

    // ---
    // expr -> ( - expr expr )
    // store result in left, free right
    lSym_p = plus22_20;
    rSym_p = mult5NegY;

    if(lSym_p->val_origin != _REGISTER) {
        // if left isn't a register, make a new register and store left in it
        regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(lSym_p), genpurpRegName[regIndex]);
        lSym_p = createSymbol(lSym_p->lexeme, _INT, _REGISTER, regIndex);
    }

                            // right symbol       // left symbol
    printf("subq %s, %s\n", symbolMemLoc(rSym_p), symbolMemLoc(lSym_p));
    // free right
    if(rSym_p->val_origin == _REGISTER)
        freeRegister(rSym_p->val_index);

    // left's register
    Symbol* minLeftRight = createSymbol("_MIN_EXP_EXP", _INT, _REGISTER, lSym_p->val_index);

    // ---

    // expr -> ID
    ySym_p = getSymbol(currScope_p, (char*)"y");

    // expr -> ( / expr expr )
    // store result in left, free right
    lSym_p = minLeftRight;
    rSym_p = ySym_p;

    if(lSym_p->val_origin != _REGISTER) {
        // if left isn't a register, make a new register and store left in it
        regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(lSym_p), genpurpRegName[regIndex]);
        lSym_p = createSymbol(lSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    
    genDivision(symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));
    // free right
    if(rSym_p->val_origin == _REGISTER)
        freeRegister(rSym_p->val_index);

    // left's register
    Symbol* divRightLeft = createSymbol("_DIVIDE_EXP_EXP", _INT, _REGISTER, lSym_p->val_index);

    // ---
    // expr -> ( write expr )
    rSym_p = divRightLeft;
    if(rSym_p->val_origin != _REGISTER) {
        regIndex = getFreeRegIndex();
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    genPrintFunction(symbolMemLoc(rSym_p));
    Symbol* writeSym_p = rSym_p;


    // ------------------------------------------------------------------------------------------

    // expr -> ID (x)
    xSym_p = getSymbol(currScope_p, (char*)"x");
    
    // expr -> ID (y)
    ySym_p = getSymbol(currScope_p, (char*)"y");

    // expr -> ( + expr expr )
    // store result in right, free left
    lSym_p = xSym_p;
    rSym_p = ySym_p;
    regIndex = getFreeRegIndex();
    if(rSym_p->val_origin != _REGISTER) {
        // if right isn't a register, make a new register and store right in it
        printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
        rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
    }
    // add left to register at right
    printf("addq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(rSym_p));

    // free left if it's a register
    if(lSym_p->val_origin == _REGISTER)
        freeRegister(lSym_p->val_index);

    // right's register
    Symbol* plusXY = createSymbol("_PLUS_EXP_EXP", _INT, _REGISTER, regIndex);


    // '+' node
    // Symbol* l_s = getSymbol(currScope_p, "x");
    // Symbol* r_s = getSymbol(currScope_p, "y");

    // int usedRegIndex = getFreeRegIndex();

    // // move left into target generated register
    // printf(
    //     "movq %s, %s\n", 
    //     genSymMemLoc(l_s), 
    //     genpurpRegName[usedRegIndex]
    // );
    // // add right to target generated register
    // printf(
    //     "addq %s, %s\n", 
    //     genSymMemLoc(r_s), 
    //     genpurpRegName[usedRegIndex]
    // );

    // Symbol* lastSymbol_p = createSymbol("_PLUS_EXP_EXP", _INT, _REGISTER, usedRegIndex);  

    // return the value at the position of the last register
    printf("movq %s, %%rax\n", symbolMemLoc(plusXY));
    genFunctionFooter();
}

void generateMain() {
    printf(".type minlisp_main, @function\n");
    printf("minlisp_main:\n");
    printf("subq $128, %%rsp\n");

    // when a new function is establisehd - I don't think we have to do this
    // for scope - we give it a fresh array of unset registers just like
    // we're doing in assembly on the C side

    // do the same with functions

    // function -> ( define id {} param_list expr ) 
    addFunc(createFuncData("main", 0, _INT));
    createScope("main");
    currScope_p->isFunction = 1;
    // set offset of function to 4 (leave 0 alone - not sure what's going on with return pointer)

    // expr -> ( let  {} ( assign_list ) expr ) 
    createScope(NULL); // explicitly not creating scope for for lets

                // expr -> num {}
    int usedRegIndex = getFreeRegIndex();
    Symbol* numSym_p = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, usedRegIndex);
    // movq $5, %rbx
    printf(
        "movq %s, %s\n", 
        "$5", 
        symbolMemLoc(numSym_p)
    );
    
            // expr -> ( write expr ) {}
    genPrintFunction(symbolMemLoc(numSym_p));

        // assign_list -> ( id expr )  {}
    // 1. create sym with offset
    Symbol* a = createSymbol("a", _INT, _OFFSET, getClosestEnclosingFunc()->stackOffset);
    // 2. print command at offset with expression's origin type
    printf("movq %s, %d(%%rsp)\n", symbolMemLoc(numSym_p), a->val_index);
    // 3. increment offset for function scope
    getClosestEnclosingFunc()->stackOffset += 4;
    // 4. if expression's origin is register (temp var), clean up register
    if(numSym_p->val_origin == _REGISTER)
        freeRegister(numSym_p->val_index);

            // expr -> num {}
    usedRegIndex = getFreeRegIndex();
    numSym_p = createSymbol("_NUMERIC_VAL_", _INT, _REGISTER, usedRegIndex);
    // movq $2, %freeReg
    printf(
        "movq %s, %s\n", 
        "$2", 
        genpurpRegName[numSym_p->val_index] 
    );

        // assign_list -> assign_list ( id expr )
    Symbol* b = createSymbol("b", _INT, _OFFSET, getClosestEnclosingFunc()->stackOffset);
    // 2. print command at offset with expression's origin type
    printf("movq %s, %d(%%rsp)\n", symbolMemLoc(numSym_p), b->val_index);
    // 3. increment offset for function scope
    getClosestEnclosingFunc()->stackOffset += 4;
    // 4. if expression's origin is register (temp var), clean up register
    if(numSym_p->val_origin == _REGISTER)
        freeRegister(numSym_p->val_index);

    // expr -> ( id actual_list {} )
    char* funcName = "add";
    printf("# calling '%s' func\n", funcName);
    // grab symbols a and b
    // pass a and b as params
    printf("movq %s, %s\n", symbolMemLoc(a), funcparamRegName[0]);
    printf("movq %s, %s\n", symbolMemLoc(b), funcparamRegName[1]);

    // return of: expr -> ( id actual_list {} )

    // When a function calls another function it has to save the registeres
    // used into the scope on the programatic side (C), and when it returns
    // just like assembly pops the scope the program can also restore the 
    // list of registers used
    genFunctionCall(funcName);
    Symbol* addFuncSym_p = createSymbol("add", _INT, _REGISTER, getFreeRegIndex());
    // grab function return and store in temporary register
    printf("movq %%rax, %s\n", symbolMemLoc(addFuncSym_p));

    // (write add(a, b) ): expr -> (write expr {})
    // use register of right ro store the result of writing
    Symbol* writeSym_p = createSymbol(addFuncSym_p->lexeme, _INT, _REGISTER, addFuncSym_p->val_index);
    genPrintFunction(symbolMemLoc(writeSym_p));
    
    // end function: expr -> ( define id param_list expr {} )
    printf("movq %s, %%rax\n", symbolMemLoc(writeSym_p));
    
    printf("addq $128, %%rsp\n");
    printf("ret\n\n");
    printf(".size       minlisp_main, .-minlisp_main\n");
    printf(".section    .note.GNU-stack,\"\",@progbits\n");
    
}

