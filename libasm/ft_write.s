segment .text
	global _ft_write

	_ft_write:							; fd(rdi), buffer(rsi), nbytes(rdx)
		mov rax, 0x200004				; function write -> syscall = 0x2000004 (macos) // 0x1 (linux)
		syscall
		ret