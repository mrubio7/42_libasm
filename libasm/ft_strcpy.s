segment .text
	global _ft_strcpy

	_ft_strcpy:									; arg1: rdi(dst)  arg2: rsi(src)
		mov rax, 0								; int i = 0
		jmp compare
	
	compare:
		cmp BYTE [rsi + rax], 0					; comparing rsi(src) with \0
		jne copy								; jump if not equal
		jump ret								; if equal 0 jump to ret

	copy:
		mov rcx, QWORD [rsi + rax]				; copy source char to rcx
		mov QWORD [rdi + rax], rcx				; copy rcx to dest
		inc rax									; i++
		jmp compare								; loop
		
	ret:
		ret