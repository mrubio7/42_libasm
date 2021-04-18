segment .text
	global		_ft_strdup
	extern		_malloc
	extern		_ft_strlen
	extern		_ft_strcpy
	extern		___error

	_ft_strdup:
		push	rdi
		call	_ft_strlen
		inc		rax
		mov		rdi, rax
		call	_malloc
		pop		rdi
		or		rax, rax
		jz		rerror
		mov		rsi, rdi
		mov		rdi, rax
		call	_ft_strcpy
		jmp		exit

	rerror:
		neg		rax
		push	rax
		call	___error
		pop		qword[rax]
		mov		rax, -1

	exit:
		ret