segment .text
	global _ft_strcmp

	_ft_strcmp:							; rdi (1arg)  rsi(2arg)
		mov rax, 0						; int i
		jmp comp_arg_one

	comp_arg_one:
		mov r8b, BYTE [rdi + rax]		; move rdi char to r8b
		mov r9b, BYTE [rsi + rax]		; move rsi char to r9b
		cmp r8b, 0						; compare char with \0
		jne comp_args
		jmp end

	comp_args:
		cmp r8b, r9b					; compare chars
		jne end
		inc rax
		jmp comp_arg_one

	end:
		sub r8b, r9b					; substract r9b(rsi) to r8b(rdi)
		movsx rax, r8b					; move r8b(rdi) to rax
		ret