section .text
global  convertToDouble

convertToDouble:
	mov   eax, r8d
	imul  eax, r9d
	xor   r10d, r10d
	movsd xmm1, [rel divisor]

.loop:
	cmp      r10d, eax
	jge      .done
	movzx    r11d, byte [rcx + r10]
	cvtsi2sd xmm0, r11d
	divsd    xmm0, xmm1

	movsd [rdx + r10*8], xmm0

	inc r10d
	jmp .loop

.done:
	ret

section .rodata
align   8

divisor:
	dq 255.0
