segment .text
	global _ft_read
	extern ___error

	_ft_read:					; ft_read(fd[rsi], buff[rdi], nbytes[rdx])
		mov rax, 0x2000003		; 0x2000003 = read function syscall
		syscall
		jc if_error				; jump if syscall got error
		ret

	if_error:
		mov rdx, rax			; save errno in rdx
		call ___error			; calling errno for get address in rax
		mov [rax], rdx			; save error in the correct address
		mov rax, -1				; save -1 in rax for return of read function
		ret