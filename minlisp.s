.text
.globl minlisp_main

# expects %rdi with value 1 or 0, and returns not
.type get_not, @function
get_not:

subq $160, %rsp
movq %rdi,  64(%rsp)
movq %rsi,  72(%rsp)
movq %rdx,  80(%rsp)
movq %rcx,  88(%rsp)
movq %r8,   96(%rsp)
movq %r9,   104(%rsp)
movq %r10,  112(%rsp)
movq %r11,  120(%rsp)
movq %r12,  128(%rsp)
movq %r13,  136(%rsp)
movq %r14,  144(%rsp)
movq %r15,  152(%rsp)
cmpq $0, %rdi
je get_result_true
# get_result_false:
movq $0, %rbx
jmp get_return_not
get_result_true:
movq $1, %rbx
get_return_not:
movq %rbx, %rax
movq 64(%rsp),  %rdi 
movq 72(%rsp),  %rsi
movq 80(%rsp),  %rdx
movq 88(%rsp),  %rcx
movq 96(%rsp),  %r8
movq 104(%rsp), %r9
movq 112(%rsp), %r10
movq 120(%rsp), %r11
movq 128(%rsp), %r12
movq 136(%rsp), %r13
movq 144(%rsp), %r14
movq 152(%rsp), %r15
addq $160, %rsp
ret

# ---------------------------------------

.type max, @function
max:

subq $160, %rsp
movq %rdi,  64(%rsp)
movq %rsi,  72(%rsp)
movq %rdx,  80(%rsp)
movq %rcx,  88(%rsp)
movq %r8,   96(%rsp)
movq %r9,   104(%rsp)
movq %r10,  112(%rsp)
movq %r11,  120(%rsp)
movq %r12,  128(%rsp)
movq %r13,  136(%rsp)
movq %r14,  144(%rsp)
movq %r15,  152(%rsp)
cmpq %rsi, %rdi
setg %al
movzbq %al, %rbx
cmpq $0, %rbx
je cond4False

# cond4True

movq %rdi, 4(%rsp)
jmp cond4End
cond4False:

movq %rsi, 4(%rsp)
cond4End:
movq 4(%rsp), %rbx
movq %rbx, %rax
movq 64(%rsp),  %rdi 
movq 72(%rsp),  %rsi
movq 80(%rsp),  %rdx
movq 88(%rsp),  %rcx
movq 96(%rsp),  %r8
movq 104(%rsp), %r9
movq 112(%rsp), %r10
movq 120(%rsp), %r11
movq 128(%rsp), %r12
movq 136(%rsp), %r13
movq 144(%rsp), %r14
movq 152(%rsp), %r15
addq $160, %rsp
ret

# ---------------------------------------

.type minlisp_main, @function
minlisp_main:

subq $160, %rsp
movq %rdi,  64(%rsp)
movq %rsi,  72(%rsp)
movq %rdx,  80(%rsp)
movq %rcx,  88(%rsp)
movq %r8,   96(%rsp)
movq %r9,   104(%rsp)
movq %r10,  112(%rsp)
movq %r11,  120(%rsp)
movq %r12,  128(%rsp)
movq %r13,  136(%rsp)
movq %r14,  144(%rsp)
movq %r15,  152(%rsp)
movq $10, %rbx
movq %rbx, %rdi
movq $20, %rbx
movq %rbx, %rsi
pushq %rbx
pushq %rbp
pushq %r10
pushq %r11
pushq %r12
pushq %r13
pushq %r14
pushq %r15
call max
popq %r15
popq %r14
popq %r13
popq %r12
popq %r11
popq %r10
popq %rbp
popq %rbx
movq %rax, %rbx
movq $42, %rbp
movq %rbp, %rdi
movq $9, %rbp
movq %rbp, %rsi
pushq %rbx
pushq %rbp
pushq %r10
pushq %r11
pushq %r12
pushq %r13
pushq %r14
pushq %r15
call max
popq %r15
popq %r14
popq %r13
popq %r12
popq %r11
popq %r10
popq %rbp
popq %rbx
movq %rax, %rbp
# addition
addq %rbx, %rbp

# start print
movq %rdi,  64(%rsp)
movq %rsi,  72(%rsp)
movq %rdx,  80(%rsp)
movq %rcx,  88(%rsp)
movq %r8,   96(%rsp)
movq %r9,   104(%rsp)
movq %r10,  112(%rsp)
movq %r11,  120(%rsp)
movq %r12,  128(%rsp)
movq %r13,  136(%rsp)
movq %r14,  144(%rsp)
movq %r15,  152(%rsp)
movq %rbp, %rsi # our param
movq S1(%rip), %rdi
movq $0, %rax
call printf
movq 64(%rsp),  %rdi 
movq 72(%rsp),  %rsi
movq 80(%rsp),  %rdx
movq 88(%rsp),  %rcx
movq 96(%rsp),  %r8
movq 104(%rsp), %r9
movq 112(%rsp), %r10
movq 120(%rsp), %r11
movq 128(%rsp), %r12
movq 136(%rsp), %r13
movq 144(%rsp), %r14
movq 152(%rsp), %r15
# end print

movq %rbp, %rax
movq 64(%rsp),  %rdi 
movq 72(%rsp),  %rsi
movq 80(%rsp),  %rdx
movq 88(%rsp),  %rcx
movq 96(%rsp),  %r8
movq 104(%rsp), %r9
movq 112(%rsp), %r10
movq 120(%rsp), %r11
movq 128(%rsp), %r12
movq 136(%rsp), %r13
movq 144(%rsp), %r14
movq 152(%rsp), %r15
addq $160, %rsp
ret

# ---------------------------------------
.size       minlisp_main, .-minlisp_main
.section    .note.GNU-stack,"",@progbits
