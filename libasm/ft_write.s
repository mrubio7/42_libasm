segment .text
	global _ft_write
	extern ___error

	_ft_write:							; fd(rdi), buffer(rsi), nbytes(rdx)
		mov 	rax, 0x2000004			; function read -> syscall = 0x2000003 (macos) // 0x0 (linux)
		syscall
		jc error_return					; jump error_return if cant use read
		jmp exit

	error_return:
		mov rdx, rax						; save errno
		call ___error					; calling errno for get address
		mov [rax], rdx
		mov rax, -1
		ret								; return
	
	exit:
		ret								; return 
