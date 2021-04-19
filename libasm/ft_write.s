segment .text
	global _ft_write
	extern ___error

	_ft_write:					; ft_write(fd[rsi], buff[rdi], nbytes[rdx])
		mov rax, 0x2000004		; 0x2000004 = write function syscall
		syscall
		jc if_error				; jump if syscall got error
		ret

	if_error:
		mov rdx, rax			; save errno in rdx
		call ___error			; calling errno for get address in rax
		mov [rax], rdx			; save error in the correct address
		mov rax, -1				; save -1 in rax for return of read function
		ret