.text
.globl minlisp_main
minlisp_main:

// main allocates 128 bytes for itself
subq $128, %rsp

# division
# temporarily store %rdx and %rcx in the stack as they'll be needed by division
# expects divident and divisor temp registers
pushq %rdx
pushq %rcx
movq $0, %rdx    # clear dividend -uses 3d func param
movq $15, %rax   # dividend
movq $5, %rcx    # divisor -uses 4th func param
divq %rcx        
movq %rax, %rbx  # store result of division general purpose register
popq %rcx
popq %rdx

# write 42
movq %rbx, %rsi     # parameter 2 in %rsi/esi
movq S1(%rip), %rdi # parameter 1 in %rdi/edi - S1 is the string "%dn"
movl $0, %eax       
call printf  



addq $128, %rsp

ret
.size       minlisp_main, .-minlisp_main
.section    .note.GNU-stack,"",@progbits
