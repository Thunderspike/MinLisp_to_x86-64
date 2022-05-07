#include "minlisp.h"

char* symbolMemLoc(Symbol* sym_p) {
    char* origin_s = (char *) malloc(sizeof(STR_SIZE));

     switch(sym_p->val_origin) {
        case _OFFSET:
            snprintf( origin_s, STR_SIZE, "%d(%%rsp)", sym_p->val_index );
            break;
        case _REGISTER:
            snprintf( origin_s, STR_SIZE, "%s", genpurpRegName[sym_p->val_index] );
            break;
        case _PARAM:
            snprintf( origin_s, STR_SIZE, "%s", funcparamRegName[sym_p->val_index] );
            break;
        case _GLOBAL:
            snprintf( origin_s, STR_SIZE, "%d_undetermined", sym_p->val_index );
            break;
    }

    return origin_s;
}

void genPrintFunction(char* reg) {
    printf("\n");
    printf("# start print\n");
    printf("movq %%rdi,  64(%%rsp)\n");
    printf("movq %%rsi,  72(%%rsp)\n");
    printf("movq %%rdx,  80(%%rsp)\n");
    printf("movq %%rcx,  88(%%rsp)\n");
    printf("movq %%r8,   96(%%rsp)\n");
    printf("movq %%r9,   104(%%rsp)\n");
    printf("movq %%r10,  112(%%rsp)\n");
    printf("movq %%r11,  120(%%rsp)\n");
    printf("movq %%r12,  128(%%rsp)\n");
    printf("movq %%r13,  136(%%rsp)\n");
    printf("movq %%r14,  144(%%rsp)\n");
    printf("movq %%r15,  152(%%rsp)\n");
    printf("movq %s, %%rsi # our param\n", reg); 
    printf("movq S1(%%rip), %%rdi\n");
    printf("movq $0, %%rax\n");
    printf("call printf\n");
    printf("movq 64(%%rsp),  %%rdi \n");
    printf("movq 72(%%rsp),  %%rsi\n");
    printf("movq 80(%%rsp),  %%rdx\n");
    printf("movq 88(%%rsp),  %%rcx\n");
    printf("movq 96(%%rsp),  %%r8\n");
    printf("movq 104(%%rsp), %%r9\n");
    printf("movq 112(%%rsp), %%r10\n");
    printf("movq 120(%%rsp), %%r11\n");
    printf("movq 128(%%rsp), %%r12\n");
    printf("movq 136(%%rsp), %%r13\n");
    printf("movq 144(%%rsp), %%r14\n");
    printf("movq 152(%%rsp), %%r15\n");
    printf("# end print\n\n");
}

void genDivision(char* dividentReg, char* divisorReg) {
    printf("\n");
    printf("# start division\n");
    printf("pushq %%rdx\n");
    printf("pushq %%rcx\n");
    printf("movq $0, %%rdx\n");
    printf("movq %s, %%rax\n", dividentReg);
    printf("movq %s, %%rcx\n", divisorReg);
    printf("divq %%rcx\n");
    printf("movq %%rax, %s\n", dividentReg);
    printf("popq %%rcx\n");
    printf("popq %%rdx\n");
    printf("# end division\n\n");
}   

void genFunctionHeader(char funcName[STR_SIZE]) {
    // start printing out function header
    printf("\n.type %s, @function\n", funcName);
    printf("%s:\n\n", funcName);   

    printf("subq $160, %%rsp\n");

    // for now always store func parasm
    printf("movq %%rdi,  64(%%rsp)\n");
    printf("movq %%rsi,  72(%%rsp)\n");
    printf("movq %%rdx,  80(%%rsp)\n");
    printf("movq %%rcx,  88(%%rsp)\n");
    printf("movq %%r8,   96(%%rsp)\n");
    printf("movq %%r9,   104(%%rsp)\n");
    printf("movq %%r10,  112(%%rsp)\n");
    printf("movq %%r11,  120(%%rsp)\n");
    printf("movq %%r12,  128(%%rsp)\n");
    printf("movq %%r13,  136(%%rsp)\n");
    printf("movq %%r14,  144(%%rsp)\n");
    printf("movq %%r15,  152(%%rsp)\n");
}

void genFunctionFooter() {
    printf("movq 64(%%rsp),  %%rdi \n");
    printf("movq 72(%%rsp),  %%rsi\n");
    printf("movq 80(%%rsp),  %%rdx\n");
    printf("movq 88(%%rsp),  %%rcx\n");
    printf("movq 96(%%rsp),  %%r8\n");
    printf("movq 104(%%rsp), %%r9\n");
    printf("movq 112(%%rsp), %%r10\n");
    printf("movq 120(%%rsp), %%r11\n");
    printf("movq 128(%%rsp), %%r12\n");
    printf("movq 136(%%rsp), %%r13\n");
    printf("movq 144(%%rsp), %%r14\n");
    printf("movq 152(%%rsp), %%r15\n");
    printf("addq $160, %%rsp\n");
    printf("ret\n\n");
    printf("# ---------------------------------------\n");
}

void genSaveFuncParams() {
    printf("pushq %%rbx\n");
    printf("pushq %%rbp\n");
    printf("pushq %%r10\n");
    printf("pushq %%r11\n");
    printf("pushq %%r12\n");
    printf("pushq %%r13\n");
    printf("pushq %%r14\n");
    printf("pushq %%r15\n");
}

void genFunctionCall(char funcName[STR_SIZE]) {
   
    printf("call %s\n", funcName);

    printf("popq %%r15\n");
    printf("popq %%r14\n");
    printf("popq %%r13\n");
    printf("popq %%r12\n");
    printf("popq %%r11\n");
    printf("popq %%r10\n");
    printf("popq %%rbp\n");
    printf("popq %%rbx\n");
}

int genInequalityExpr(Symbol* lSym_p, Symbol* rSym_p, char* ineqOp) {
    printf("cmpq %s, %s\n", symbolMemLoc(rSym_p), symbolMemLoc(lSym_p));
    // free let and right registers if they're gen purpose
    if(lSym_p->val_origin == _REGISTER)
        freeRegister(lSym_p->val_index);
    if(rSym_p->val_origin == _REGISTER)
        freeRegister(rSym_p->val_index);
    printf("%s %%al\n", ineqOp);
    int regIndex = getFreeRegIndex();
    printf("movzbq %%al, %s\n", genpurpRegName[regIndex]);
    return regIndex;
}

int genLogiInequalityExpr(Symbol* lSym_p, Symbol* rSym_p, char* ineqOp) {
    Symbol* ts_p = malloc(sizeof(Symbol));
    int regIndex = -1;
    if(strcasecmp(ineqOp, "and") == 0) {
        ts_p = rSym_p;
        if(rSym_p->val_origin != _REGISTER) {
            regIndex = getFreeRegIndex();
            printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
            ts_p = createSymbol("temp", -1, _BOOL, regIndex);
        }
        printf("andq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(ts_p));
        if(lSym_p->val_origin == _REGISTER) 
            freeRegister(lSym_p->val_index);
    } else if (strcasecmp(ineqOp, "or") == 0) {
        ts_p = rSym_p;
        if(rSym_p->val_origin != _REGISTER) {
            regIndex = getFreeRegIndex();
            printf("movq %s, %s\n", symbolMemLoc(rSym_p), genpurpRegName[regIndex]);
            ts_p = createSymbol("temp", -1, _BOOL, regIndex);
        }
        printf("orq %s, %s\n", symbolMemLoc(lSym_p), symbolMemLoc(ts_p));
        if(lSym_p->val_origin == _REGISTER) 
            freeRegister(lSym_p->val_index);
    } else if (strcasecmp(ineqOp, "not") == 0) {
        ts_p = lSym_p;
        if(lSym_p->val_origin != _REGISTER) {
            regIndex = getFreeRegIndex();
            printf("movq %s, %s\n", symbolMemLoc(lSym_p), genpurpRegName[regIndex]);
            ts_p = createSymbol("temp", -1, _BOOL, regIndex);
        }
        // call get_not (which is injected just for the 'not' op) and get result from rax
        char* reg = symbolMemLoc(ts_p);
        genSaveFuncParams();
        printf("movq %s, %%rdi\n", reg);
        genFunctionCall("get_not\n");
        printf("movq %%rax, %s\n", symbolMemLoc(ts_p));
    }
    return ts_p->val_index;
}

// probably a cleaner way to do it but couldn't find one in a rush
void genNotFunc() {
    printf("# expects %%rdi with value 1 or 0, and returns not");
    genFunctionHeader("get_not");
    printf("cmpq $0, %%rdi\n");
    printf("je get_result_true\n");
    printf("# get_result_false:\n");
    printf("movq $0, %%rbx\n");
    printf("jmp get_return_not\n");
    printf("get_result_true:\n");
    printf("movq $1, %%rbx\n");
    printf("get_return_not:\n");
    printf("movq %%rbx, %%rax\n");
    genFunctionFooter();
}