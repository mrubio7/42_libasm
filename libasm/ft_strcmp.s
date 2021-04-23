segment .text
	global _ft_strcmp

	_ft_strcmp:						; ft_strcmp(rdi, rsi)
		mov rax, 0					; int i = 0
		jmp compare_swap

	compare_swap:
		mov r8b, BYTE [rdi + rax]	; move rdi char to r8b
		mov r9b, BYTE [rsi + rax]	; move rsi char to r9b
		cmp r8b, 0					; compare rdi(1 arg) char with \0
		jne compare_both
		jmp end

	compare_both:
		cmp r9b, 0					; compare rdi(2 arg) char with \0
		je end
		cmp r8b, r9b				; compare chars of both args
		jne end
		inc rax
		jmp compare_swap

	end:
		sub r8b, r9b				; substract rsi to rdi
		movsx rax, r8b				; (movsx) because move 8bits to 64bits
		ret