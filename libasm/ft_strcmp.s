section		.text
	global		_ft_strcmp

	_ft_strcmp:
		xor		rax, rax
		xor		rdx, rdx
		xor		rcx, rcx

	compare:
		mov		al, [rdi + rcx]
		mov		dl, [rsi + rcx]
		cmp		al, 0
		jz		retrn
		cmp		dl, 0
		jz		retrn
		cmp		al, dl
		jnz		retrn
		inc		rcx
		jmp		compare

	retrn:
		sub		rax, rdx
		ret