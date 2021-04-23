section .text
	global _ft_strcpy

	_ft_strcpy:						; 1arg(dest)[rdi]   2arg(src)[rsi]
		mov rax, rdi				; mov rdi to rax
		xor rcx, rcx				; rcx to 0

	loop:
		cmp byte [rsi + rcx], 0		; compare rsi == \0
		je exit						; jump if equal 0
		mov r8b, [rsi + rcx]		; copy char of rsi to r8b
		mov [rcx + rax], r8b		; copy r8b to rax
		inc rcx
		jmp loop

	exit:
		mov byte[rcx + rax], 0		; set \0 to end of rcx
		ret