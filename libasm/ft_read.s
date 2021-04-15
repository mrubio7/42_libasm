segment .text
global _ft_read
extern	__errno_location

	_ft_read:							; fd(rdi), buffer(rsi), nbytes(rdx)
		mov 	rax, 0x2000003			; function read -> syscall = 0x2000003 (macos) // 0x0 (linux)
		syscall
		jc error_return					; jump error_return if cant use read
		jmp exit

	error_return:
		mov rax, -1
		ret								; return
	
	exit:
		ret								; return 
