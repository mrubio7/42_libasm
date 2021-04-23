segment .text
	global _ft_strcmp

_ft_strcmp:					; ft_strcmp(dest(rdi), src(rsi))
	mov r8, rdi
	or r8, rsi				; if (!s1 && !s2)
	cmp r8, 0				; comparing rdi char with \0
	je equal

cmp_loop:
	mov r8, [rdi]			; char rdi
	cmp r8, 0				; comparing rdi char with \0
	je bcmp					; if equal
	cmp byte [rsi], 0		; comparing rsi char with \0
	je bcmp					; if equal
	cmp r8b, byte [rsi]		; comparing rdi char with rsi char
	ja big					; >
	jb low					; <
	inc rdi					; *rdi++
	inc rsi					; *rsi++
	jmp cmp_loop

bcmp:
	cmp r8b, byte [rsi]		; comparing rdi char with rsi char
	ja big
	jb low
	je equal

equal:
	mov rax, 0				; ret 0
	ret

big:
	mov rax, 1				; ret 1
	ret

low:
	mov rax, -1				; ret -1
	ret