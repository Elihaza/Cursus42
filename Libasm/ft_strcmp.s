		global			ft_strcmp

				section			.text

ft_strcmp:		push			rdx ; sauvegarde rdx
				push			rcx ; sauvegarde rcx
				xor				rdx, rdx ; mise a zero du compteur
				xor				rax, rax ; mise a zero de rax

loop:			mov				cl, byte [rsi + rdx] ; valeur s2[x] dans cl
				cmp				byte [rdi + rdx], cl ; comparaison avec s1[x]
				jl				lower ; si s2 < s1
				jg				greater ; si s2 > s1
				or				cl, cl ; on compare s1[x] a zero
				jz				end
				inc				rdx ; on incremente le compteur
				jmp				loop

lower:			mov				rax, -1 ;retour -1
				jmp				end

greater:		mov				rax, 1 ;retour 1

end:			pop				rdx ;on remet rdx
				pop				rcx ;on remet rcx
				ret
