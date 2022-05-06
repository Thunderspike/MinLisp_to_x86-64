# Notes for P4
## 5/3/2022
* When a function calls another function it has to save the registeres used into the scope on the programatic side (C), and when it returns just like assembly pops the scope the program can also restore the list of registers used

# Todos
* register usability counter alongside with printing them
* make sure long list of arithmetic operations is cleaning the registers
* potentially generate uuid symbol names

# Implementations points to not forget
Pattern of algebratic operations

Addition and multiplication
```c++
// expr -> ( + expr expr )
// store result in right, free left
lSym_p = xSym_p;
rSym_p = ySym_p;
regIndex = getFreeRegIndex();
if(rSym_p->val_origin != _REGISTER) {
    // if right isn't a register, make a new register and store right in it
    printf("movq %s, %s\n", genSymMemLoc(rSym_p), genpurpRegName[regIndex]);
    rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
}
// add left to register at right
printf("addq %s, %s\n", genSymMemLoc(lSym_p), genSymMemLoc(rSym_p));

// free left if it's a register
if(lSym_p->val_origin == _REGISTER)
    freeRegister(lSym_p->val_index);

// right's register
Symbol* plus22_20 = createSymbol("_PLUS_EXP_EXP", _INT, _REGISTER, regIndex);
```

Subtraction and division:
```c++
// expr -> ( - expr expr )
// store result in left, free right
lSym_p = plus22_20;
rSym_p = mult5NegY;

regIndex = getFreeRegIndex();
if(lSym_p->val_origin != _REGISTER) {
    // if left isn't a register, make a new register and store left in it
    printf("movq %s, %s\n", genSymMemLoc(lSym_p), genpurpRegName[regIndex]);
    lSym_p = createSymbol(lSym_p->lexeme, _INT, _REGISTER, regIndex);
}

                        // right symbol       // left symbol
printf("subq %s, %s\n", genSymMemLoc(rSym_p), genSymMemLoc(lSym_p));
// free right
if(rSym_p->val_origin == _REGISTER)
    freeRegister(rSym_p->val_index);

// left's register
Symbol* minLeftRight = createSymbol("_MIN_EXP_EXP", _INT, _REGISTER, regIndex);
```

Unary negation:
```c++
// expr -> ( - expr )
rSym_p = ySym_p;
regIndex = getFreeRegIndex();
if(rSym_p->val_origin != _REGISTER) {
    // if expr isn't a register, make a new register and store expr in it
    printf("movq %s, %s\n", genSymMemLoc(rSym_p), genpurpRegName[regIndex]);
    rSym_p = createSymbol(rSym_p->lexeme, _INT, _REGISTER, regIndex);
} else {
    freeRegister(rSym_p->val_index);
}

printf("negq %s\n", genSymMemLoc(rSym_p));
Symbol* negSym = createSymbol("_NEGAT_EXPR", _INT, _REGISTER, regIndex);
```

## leftover

{
    printf(".text\n");
    printf(".globl minlisp_main\n");
}