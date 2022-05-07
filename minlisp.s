.text
.globl minlisp_main


.type add, @function
add:

subq $128, %rsp
movq %rdi, 80(%rsp)
movq %rsi, 88(%rsp)
movq %rdx, 96(%rsp)
movq %rcx, 104(%rsp)
movq %r8, 112(%rsp)
movq %r9, 120(%rsp)

movq $22, %rbx
movq $20, %rbp
# addition
addq %rbx, %rbp
movq $5, %rbx
movq %rsi, %r10
negq %r10
# multiplication
imulq %rbx, %r10
# subtraction
subq %r10, %rbp
# division

# start division
pushq %rdx
pushq %rcx
movq $0, %rdx
movq %rbp, %rax
movq %rsi, %rcx
divq %rcx
movq %rax, %rbp
popq %rcx
popq %rdx
# end division

movq %rbp, 4(%rsp)
# addition
movq %rsi, %rbx
addq %rdi, %rbx
# subtraction
movq 4(%rsp), %rbp
subq %rbx, %rbp
movq %rbp, 8(%rsp)
movq 8(%rsp), %rbx

# start write
pushq %rdi
pushq %rsi
movq %rbx, %rsi
movq S1(%rip), %rdi
movl $0, %eax
call printf
popq %rsi
popq %rdi
# end write

movq $22, %rbp
movq $20, %r10
# addition
addq %rbp, %r10
movq $5, %rbp
movq %rsi, %r11
negq %r11
# multiplication
imulq %rbp, %r11
# subtraction
subq %r11, %r10
# division

# start division
pushq %rdx
pushq %rcx
movq $0, %rdx
movq %r10, %rax
movq %rsi, %rcx
divq %rcx
movq %rax, %r10
popq %rcx
popq %rdx
# end division


# start write
pushq %rdi
pushq %rsi
movq %r10, %rsi
movq S1(%rip), %rdi
movl $0, %eax
call printf
popq %rsi
popq %rdi
# end write

# subtraction
movq %rdi, %rbp
subq %rsi, %rbp

# start write
pushq %rdi
pushq %rsi
movq %rbp, %rsi
movq S1(%rip), %rdi
movl $0, %eax
call printf
popq %rsi
popq %rdi
# end write

# addition
movq %rsi, %r11
addq %rdi, %r11
movq %r11, %rax
movq 80(%rsp), %rdi
movq 88(%rsp), %rsi
movq 96(%rsp), %rdx
movq 104(%rsp), %rcx
movq 112(%rsp), %r8
movq 120(%rsp), %r9
addq $128, %rsp
ret

# ---------------------------------------

.type minlisp_main, @function
minlisp_main:

subq $128, %rsp
movq %rdi, 80(%rsp)
movq %rsi, 88(%rsp)
movq %rdx, 96(%rsp)
movq %rcx, 104(%rsp)
movq %r8, 112(%rsp)
movq %r9, 120(%rsp)

movq $5, %rbx

# start write
pushq %rdi
pushq %rsi
movq %rbx, %rsi
movq S1(%rip), %rdi
movl $0, %eax
call printf
popq %rsi
popq %rdi
# end write

movq %rbx, 4(%rsp)
movq $2, %rbx
movq %rbx, 8(%rsp)
movq 4(%rsp), %rdi
movq 8(%rsp), %rsi
pushq %rbx
pushq %rbp
pushq %r10
pushq %r11
pushq %r12
pushq %r13
pushq %r14
pushq %r15
call add
popq %r15
popq %r14
popq %r13
popq %r12
popq %r11
popq %r10
popq %rbp
popq %rbx
movq %rax, %rbx

# start write
pushq %rdi
pushq %rsi
movq %rbx, %rsi
movq S1(%rip), %rdi
movl $0, %eax
call printf
popq %rsi
popq %rdi
# end write

movq %rbx, %rax
movq 80(%rsp), %rdi
movq 88(%rsp), %rsi
movq 96(%rsp), %rdx
movq 104(%rsp), %rcx
movq 112(%rsp), %r8
movq 120(%rsp), %r9
addq $128, %rsp
ret

# ---------------------------------------
.size       minlisp_main, .-minlisp_main
.section    .note.GNU-stack,"",@progbits
