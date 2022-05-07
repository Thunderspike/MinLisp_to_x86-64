gcc play.c minLisp.h stateManagement.c -o play; ./play > out.s; gcc out.s minlisp_main.c -o exe; ./exe; ./exe


gcc play.c minLisp.h stateManagement.c generatorUtils.c -o play; ./play > out.s;
gcc -fomit-frame-pointer out.s minlisp_main.c -o exe; ./exe;

## -fomit-frame-pointer
Makes it so rbp can be used as a general purpose regiser
https://stackoverflow.com/questions/41912684/what-is-the-purpose-of-the-rbp-register-in-x86-64-assembler