;	read syscall expects an unsigned int fd in %rdi, a char *buf address in %rsi.
;	and a size_t bytes count in %rdx

			section		.text

			extern		__errno_location
			global		ft_read

ft_read:	mov			rax, 0
			syscall
			cmp			rax, 0
			jl			error
			ret

error:		neg			rax	; set errcode to positive
			mov			rdi, rax ; store errcode in %rdi
			call		__errno_location wrt ..plt ; get errno location
			mov			[rax], rdi ; initialize errno with errcode
			mov			rax, -1	; return -1
			ret