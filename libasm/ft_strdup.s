segment .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

	_ft_strdup:
		mov rbx, rdi		; Pasamos el arg1 (str) al rbx
		call _ft_strlen		; Llamamos a ft_strlen que se guarda en eax
		mov edi, eax		; Pasamos eax a edi por que malloc lo lea
		call _malloc		; Llamamos a malloc que usa edi para saber cuanto asignar
		mov rax, rbx		; Pasamos rbx(str) al registro de salida
		jmp ret

	ret:
		ret