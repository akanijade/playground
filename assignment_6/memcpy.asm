global foo
SECTION .text
foo:
	mov rax, [rsi]
	mov [rdi], rax
	add rdi, 8
	add rsi, 8
	sub rdx, 8
	cmp rdx, 0
	jne foo
ret
