;	ft_strcpy expects a dest string address in %rdi and a source string address in %rsi
;	it returns the dest string address in %rax

			global		ft_strcpy

			section		.text

ft_strcpy:	mov			rax, rdi ; destination dans rax
			push		rbp	; sauvegarde rbp
			xor			rbp, rbp ; mise a zero rbp

loop:		mov			dl, byte [rsi + rbp] ; on transfere bits, necessite syntaxique intermediaire
			mov			byte [rax + rbp], dl
			cmp			byte [rsi + rbp], 0 ; recherche fin string
			jz			end
			inc			rbp ; index + 1
			jmp			loop

end:		pop			rbp
			ret