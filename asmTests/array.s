.section .data
data_items:         # These are the data items
.long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

.text
.globl minlisp_main

.type printLoop, @function
printLoop:

movq $0, %rdi
movq $1, %rbx

start_loop:                
cmpq $0, %rbx
je exit_loop

movq data_items(,%rdi,4), %rbx

pushq %rdi
pushq %rsi
movq %rbx, %rsi     # parameter 2 in %rsi/esi
movq S1(%rip), %rdi # parameter 1 in %rdi/edi - S1 is the string "%dn"
movl $0, %eax       
call printf  
popq %rsi
popq %rdi

incq %rdi

jmp start_loop
exit_loop:

ret

# --------------------------------------------------------------------

.type minlisp_main, @function
minlisp_main:

# call printLoop

# attempt to get the 5th element
movq $3, %rbx

# movq data_items(,%rbx,4), %rbx
# pushq %rdi
# pushq %rsi
# movq %rbx, %rsi     # parameter 2 in %rsi/esi
# movq S1(%rip), %rdi # parameter 1 in %rdi/edi - S1 is the string "%dn"
# movl $0, %eax       
# call printf  
# popq %rsi
# popq %rdi

movq $200, data_items(,%rbx,4)
movq data_items(,%rbx,4), %rbx

pushq %rdi
pushq %rsi
movq %rbx, %rsi     # parameter 2 in %rsi/esi
movq S1(%rip), %rdi # parameter 1 in %rdi/edi - S1 is the string "%dn"
movl $0, %eax       
call printf  
popq %rsi
popq %rdi

call printLoop



ret
.size       minlisp_main, .-minlisp_main
.section    .note.GNU-stack,"",@progbits
