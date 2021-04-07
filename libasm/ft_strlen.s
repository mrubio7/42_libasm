segment .text
	global _ft_strlen

	_ft_strlen:						; ft_strlen(rdi -> arg = char *str)
		mov rax, 0					; int x = 0
		jmp iter					; jump to iter:

	iter:
		cmp BYTE [rdi + rax], 0		; comparing rdi (arg) + rax with 0
		je return						; jump if equal (equal 0)
		inc rax						; rax++
		jmp iter					; loop

	return:
		ret							; return