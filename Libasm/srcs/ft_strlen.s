; ft_strlen expects %rdi to hold a string address
; and returns the string length in rax

				section		.text

				global		ft_strlen

ft_strlen:		mov			rax, 0

ft_strlen_loop:	cmp			byte [rdi + rax], 0
				je			strlen_ret
				inc			rax
				jmp			ft_strlen_loop

strlen_ret:		ret
