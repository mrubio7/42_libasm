segment .text
	global _ft_write
	extern ___error

	_ft_write:
		mov		rax, 0x2000004	; 0x200000 to mark it for the BSD layer
								; and the las t digit marks the call and it s
								; refrense is in <unistd.h>
		syscall					; syscall return number of chars wrriten or error code
		jc		error			; if syscall fails
		ret

	error:
		push	rax				; store return value of syscall
		call	___error		; get *errno
		pop		rdx
		mov		[rax], rdx		; *errno = return value
		mov		rax, -1			; return -1
		ret