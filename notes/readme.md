## to play: 
`gcc  -o $1  minlisp_main.c $1.s`

## pushl/pushl here doesn't work unless you compile this as 32 bit with 
`as --32 power.s -o power.o`

[32 vs 64](https://stackoverflow.com/questions/21679131/error-invalid-instruction-suffix-for-push/21680219)

| Register     | Usage                                                                  |Preserved |
|---------------------------------------------------------------------------------------|across fn |
|--------------|------------------------------------------------------------------------|----------|
| %rsp         | Stack pointer                                                          | Yes      |
| %rbx         | Callee-saved register; optionally used as base pointer                 | Yes      |
| %rbp         | Callee-saved register, optionally used as frame pointer                | Yes      |
| %r12-r15     | Callee-saved registers                                                 | Yes      |
----------------------------------------------------------------------------------------------------
| %rax         | Temporary register; with variable arguments passes information about 	| No	   |
|              | the number of SSE registers used; 1st return register    				|          |
----------------------------------------------------------------------------------------------------
| %rdi         | Used to pass 1st argument to functions                                 | No       |
| %rsi         | Used to pass 2nd argument to functions                                 | No       |
| %rdx         | Used to pass 3d argument to functions; 2nd return register             | No       |
| %rcx         | Used to pass 4th integer argument to functions                         | No       |
| %r8          | Used to pass 5th argument to functions                                 | No       |
| %r9          | Used to pass 6th argument functions                                    | No       |
| %r10         | Temporary register, used for passing a function's static chain pointer | No       |
| %r11         | Temporary register                                                     | No       |
| %xmll0-%xmm1 | Used to pass and return floating point arguments                       | No       |
| %xmm2-%xmm7  | Used to pass floating point arguments                                  | No       |
| %xmm8-xmm15  | Temporary registers                                                    | No       |
| %mmx0-%mmx7  | Temporary registers                                                    | No       |
| %st0         | Temporary register, used to return long double arguments               | No       |
| %st1         | Temporary registers; used to return long double arguments              | No       |
| %st2-%st7    | Temporary registers                                                    | No       |
| %fs          | Reserved for system use(as thread specific data register)              | No       |


| 8bit | 16-bit | 32-bit | 64-bit |
| spl  | sp     | esp    | rsp    | - stack ptr 
| bl   | bx     | ebx    | rbx    | - base ptr
| bpl  | bp     | ebp    | rbp    | - frame ptr
| r10b | r10w   | r10d   | r10    |
| r11b | r11w   | r11d   | r11    |
| r12b | r12w   | r12d   | r12    |
| r13b | r13w   | r13d   | r13    |
| r14b | r14w   | r14d   | r14    |
| r15b | r15w   | r15d   | r15    |
|------|--------|--------|--------|
| al   | ax     | eax    | rax    | 
| dil  | di     | edi    | rdi    | -- func param registers
| sil  | si     | esi    | rsi    |
| dl   | dx     | edx    | rdx    |
| cl   | cx     | ecx    | rcx    |
| r8b  | r8w    | r8d    | r8     |
| r9b  | r9w    | r9d    | r9     |

// registers
// %ebx, %ebp, %r10d, %r11d, %r12d, %r13d, %r14d, %r15d - 8

// func params
// %rdi/edi, %rsi/esi, %rdx,edx, %rcx/%ecx, %r8/%r8d, %r9/%r9d - 6
// %edi, %esi, %edx, %ecx, %r8d, %r9d - 6

// function / scope returns are in 

----

| syscall   	| ID  	| %rdi    	        | %rsi    	| %rdx   	| %r8 	| %r9 	| %r10  |
|-----------	|-----	|-----------------	|---------	|--------	|------	|------	|------	|
| sys_read  	| 0   	| #filedescriptor 	| $buffer 	| #count 	|      	|      	|      	|
| sys_write 	| 1   	| #filedescriptor 	| $buffer 	| #count 	|      	|      	|      	|
| sys_open  	| 2   	| $filename       	| #flags  	| #mode  	|      	|      	|      	|
| sys_close 	| 3   	| #filedescriptor 	|         	|        	|      	|      	|      	|
| ...       	| ... 	| ...             	| ...     	| ...    	| ...  	| ...  	| ...  	|
| pwritev2  	| 328 	| ...             	| ...     	| ...    	| ...  	| ...  	| ...  	|


`#` are hard numbers from registers
`$` are pointers to the memory data

4) `sys_write`
This is what we use to write "hello, world!" to the screen

| Argument Type   	| Argument Description                                        	|
|-----------------	|-------------------------------------------------------------	|
| File Descriptor 	| 0 (Standard Input), 1 (Standard Output), 2 (Standard Error) 	|
| Buffer          	| Location of string to write                                	|
| Count           	| Length of string                                            	|

14 in rdx because "hello, world!" is length 13 + '\n' is 14

```c#
(define add (x, y)
    ( seq 
        (write (/ (- (+ 22 20) ( * 5 (- y))) y)) # 52 / 2 = 26
        (write (- x y))
        ( + x y )
    )
)
(define main() 
    ( let (
            (a (write 5))
            (b 2)
        )
        (write add(a, b))
    )
)
```

```c#
(define f(x y)
    (let ( (a 2) (b (+ x y)))
        (write (*  (+ x a) b))
))
```