segment .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

	_ft_strdup:						; ft_strdup(rdi)
		mov r8, rdi					; r8 = rdi
		call _ft_strlen				; eax = ft_strlen
		mov edi, eax				; edi = eax
		call _malloc				; malloc(edi)
		mov rax, r8					; rax = r8
		ret