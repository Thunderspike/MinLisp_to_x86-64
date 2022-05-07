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

,# addition
movq %rsi, %rbx
addq %rdi, %rbx
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
