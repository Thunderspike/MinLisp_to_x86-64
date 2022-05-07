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
    printf("# start write\n");
    printf("pushq %%rdi\n");
    printf("pushq %%rsi\n");
    printf("movq %s, %%rsi\n", reg);    
    printf("movq S1(%%rip), %%rdi\n");
    printf("movl $0, %%eax\n");      
    printf("call printf\n"); 
    printf("popq %%rsi\n");
    printf("popq %%rdi\n");
    printf("# end write\n\n");
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

    printf("subq $128, %%rsp\n");

    // for now always store func parasm
    printf("movq %%rdi, 80(%%rsp)\n");
    printf("movq %%rsi, 88(%%rsp)\n");
    printf("movq %%rdx, 96(%%rsp)\n");
    printf("movq %%rcx, 104(%%rsp)\n");
    printf("movq %%r8, 112(%%rsp)\n");
    printf("movq %%r9, 120(%%rsp)\n\n");
}

void genFunctionFooter() {
    printf("movq 80(%%rsp), %%rdi\n");
    printf("movq 88(%%rsp), %%rsi\n");
    printf("movq 96(%%rsp), %%rdx\n");
    printf("movq 104(%%rsp), %%rcx\n");
    printf("movq 112(%%rsp), %%r8\n");
    printf("movq 120(%%rsp), %%r9\n");
    printf("addq $128, %%rsp\n");
    printf("ret\n\n");
    printf("# ---------------------------------------\n");
}

void genFunctionCall(char funcName[STR_SIZE]) {
    printf("pushq %%rbx\n");
    printf("pushq %%rbp\n");
    printf("pushq %%r10\n");
    printf("pushq %%r11\n");
    printf("pushq %%r12\n");
    printf("pushq %%r13\n");
    printf("pushq %%r14\n");
    printf("pushq %%r15\n");

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
