segment .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

	_ft_strdup:
		mov rbx, rdi
		call _ft_strlen
		mov edi, eax
		call _malloc
		mov rax, rbx
		jmp ret

	ret:
		ret
