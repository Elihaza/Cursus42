; 	syscall write (%rax == 1) expects :
; 	- a string ptr in %rsi
;	- an unsigned int fd in %rdi
;	- a size_t byte count in %rdx

				section .text

				global	ft_write
				extern	__errno_location	; platform dependent
;	extern instruction used to reference a symbol defined outside of the
;	module being assembled.

ft_write:		mov			rax, 0
				inc			rax
				syscall
				cmp			rax, 0
				jl			error		; if rax < 0, handle error
				ret

error:			neg			rax			; set errcode to positive
				mov			rdi, rax		; store errcode in %rdi
				call		__errno_location wrt ..plt	; get errno location
				mov			[rax], rdi		; initialize errno with errcode
				mov			rax, -1			; return -1
				ret
;	elf does not support segment-base references, the wrt (with reference to) is hence used
;	to do position-independent-code (PIC) relocation.
;	Referring to a procedure name using wrt ..plt causes the linker to build a procedure
;	linkage table entry for the symbol.
