.text
.globl minlisp_main

.type   minlisp_main, @function
# main doesn't need to save register state
minlisp_main:

// main allocates 128 bytes for itself
subq $128, %rsp

call minlisp_input
movq %rax, %rbx

pushq %rdi
pushq %rsi
movq %rbx, %rsi     # parameter 2 in %rsi/esi
movq S1(%rip), %rdi # parameter 1 in %rdi/edi - S1 is the string "%dn"
movl $0, %eax       
call printf  
popq %rsi
popq %rdi

movq %rbx, %rax
addq $128, %rsp

ret
.size       minlisp_main, .-minlisp_main
.section    .note.GNU-stack,"",@progbits
