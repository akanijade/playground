global rev_array_asm

section .text

;prologue
rev_array_asm:
    	cmp rdx, 0                 ;comparing if size = 0
    	je rexit                   ;jump to exit 
	mov r11, rdx
	mov r12, rsi
    	sub rdx, 1                 ;subtract one from size to get length
	mov eax, 4
	mul edx	
    	add rdi, rax               ;get the last address
    
next:
    	mov eax, dword [rdi]              ;mov first param
	mov dword [rsi], eax
	dec r11
	cmp r11, 0
	jne next
	sub rdi, 4
	add rsi, 4

rexit: ;epilogue
	sub rsi, 16
	mov rax, rsi
ret
