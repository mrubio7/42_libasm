segment .text
	global _ft_read

	_ft_read:							; fd(rdi), buffer(rsi), nbytes(rdx)
		mov rax, 0x200005				; function read -> syscall = 0x2000005 (macos) // 0x0 (linux)
		syscall
		ret