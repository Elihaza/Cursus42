; ft_strdup expects a string address in %rdi, and returns the string address of a malloc'd
; copy of that string
; size (in bytes) to malloc goes in %rdi, memory pointer returned in %rax

				section 	.text

				extern		malloc
				extern		__errno_location
				extern		ft_strlen
				extern		ft_strcpy
				global		ft_strdup

ft_strdup:		push		rdi
				call		ft_strlen	; %rax = strlen(%rdi)
				inc			rax		; len += 1 for '\0'
				mov			rdi, rax	; %rdi = len for malloc
				call		malloc wrt ..plt
				cmp			rax, 0		; check errors
				je			error
				pop			rdi
				mov			rsi, rdi
				mov			rdi, rax	; mov dst in %rdi for strcpy
				call		ft_strcpy

strdup_return:	ret

error:			neg			rax
				mov			rdi, rax
				call		__errno_location wrt ..plt
				mov			[rax], rdi
				mov			rax, 0
				ret
