	.file	"Tetris.c"
	.comm	orig_termios,60,32
	.text
	.globl	die
	.type	die, @function
die:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	perror
	movl	$1, %edi
	call	exit
	.cfi_endproc
.LFE2:
	.size	die, .-die
	.globl	disableRawMode
	.type	disableRawMode, @function
disableRawMode:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$orig_termios, %edx
	movl	$2, %esi
	movl	$0, %edi
	call	tcsetattr
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	disableRawMode, .-disableRawMode
	.globl	enableRawMode
	.type	enableRawMode, @function
enableRawMode:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$orig_termios, %esi
	movl	$0, %edi
	call	tcgetattr
	movl	$disableRawMode, %edi
	call	atexit
	movq	orig_termios(%rip), %rax
	movq	%rax, -80(%rbp)
	movq	orig_termios+8(%rip), %rax
	movq	%rax, -72(%rbp)
	movq	orig_termios+16(%rip), %rax
	movq	%rax, -64(%rbp)
	movq	orig_termios+24(%rip), %rax
	movq	%rax, -56(%rbp)
	movq	orig_termios+32(%rip), %rax
	movq	%rax, -48(%rbp)
	movq	orig_termios+40(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	orig_termios+48(%rip), %rax
	movq	%rax, -32(%rbp)
	movl	orig_termios+56(%rip), %eax
	movl	%eax, -24(%rbp)
	movl	-68(%rbp), %eax
	andl	$-11, %eax
	movl	%eax, -68(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rdx
	movl	$2, %esi
	movl	$0, %edi
	call	tcsetattr
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L4
	call	__stack_chk_fail
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	enableRawMode, .-enableRawMode
	.section	.rodata
.LC0:
	.string	"read"
	.text
	.globl	editorReadKey
	.type	editorReadKey, @function
editorReadKey:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	jmp	.L6
.L7:
	cmpl	$-1, -12(%rbp)
	jne	.L6
	call	__errno_location
	movl	(%rax), %eax
	cmpl	$11, %eax
	je	.L6
	movl	$.LC0, %edi
	call	die
.L6:
	leaq	-13(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	jne	.L7
	movzbl	-13(%rbp), %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	editorReadKey, .-editorReadKey
	.globl	wait
	.type	wait, @function
wait:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	usleep
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	wait, .-wait
	.section	.rodata
.LC1:
	.string	""
	.text
	.globl	printArr
	.type	printArr, @function
printArr:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L13
.L16:
	movl	$0, -4(%rbp)
	jmp	.L14
.L15:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	addl	$1, -4(%rbp)
.L14:
	cmpl	$24, -4(%rbp)
	jle	.L15
	movl	$.LC1, %edi
	call	puts
	addl	$1, -8(%rbp)
.L13:
	cmpl	$24, -8(%rbp)
	jle	.L16
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	printArr, .-printArr
	.globl	insertBox
	.type	insertBox, @function
insertBox:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movb	$35, (%rdx,%rax)
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$35, (%rdx,%rax)
	movl	-12(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	movb	$35, (%rdx,%rax)
	movl	-12(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$35, (%rdx,%rax)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	insertBox, .-insertBox
	.globl	initMap
	.type	initMap, @function
initMap:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L21
.L29:
	movl	$0, -4(%rbp)
	jmp	.L22
.L28:
	cmpl	$0, -8(%rbp)
	je	.L23
	cmpl	$24, -8(%rbp)
	jne	.L24
.L23:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movb	$45, (%rdx,%rax)
	jmp	.L25
.L24:
	cmpl	$0, -4(%rbp)
	je	.L26
	cmpl	$24, -4(%rbp)
	jne	.L27
.L26:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movb	$124, (%rdx,%rax)
	jmp	.L25
.L27:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movb	$32, (%rdx,%rax)
.L25:
	addl	$1, -4(%rbp)
.L22:
	cmpl	$24, -4(%rbp)
	jle	.L28
	addl	$1, -8(%rbp)
.L21:
	cmpl	$24, -8(%rbp)
	jle	.L29
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	initMap, .-initMap
	.globl	input
	.type	input, @function
input:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpl	$97, -4(%rbp)
	jne	.L31
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	$0, %eax
	jmp	.L32
.L31:
	cmpl	$115, -4(%rbp)
	jne	.L33
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movl	$0, %eax
	jmp	.L32
.L33:
	cmpl	$100, -4(%rbp)
	jne	.L34
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	$0, %eax
	jmp	.L32
.L34:
	movl	$1, %eax
.L32:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	input, .-input
	.section	.rodata
.LC2:
	.string	"Char is: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$688, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	call	enableRawMode
	movl	$0, -668(%rbp)
	movl	$10, -676(%rbp)
	movl	$10, -672(%rbp)
	movl	$-1, -664(%rbp)
	movl	$1000000, -660(%rbp)
	movb	$1, -678(%rbp)
	movl	$1634036835, -16(%rbp)
	movw	$114, -12(%rbp)
	movb	$1, -677(%rbp)
	jmp	.L36
.L37:
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	system
	leaq	-656(%rbp), %rax
	movq	%rax, %rdi
	call	initMap
	movl	-672(%rbp), %edx
	movl	-676(%rbp), %ecx
	leaq	-656(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	insertBox
	leaq	-656(%rbp), %rax
	movq	%rax, %rdi
	call	printArr
	leaq	-672(%rbp), %rdx
	leaq	-676(%rbp), %rax
	movq	%rax, %rsi
	movl	$115, %edi
	call	input
	call	initscr
	movq	stdscr(%rip), %rax
	movl	$-1, %esi
	movq	%rax, %rdi
	call	wtimeout
	movq	stdscr(%rip), %rax
	movq	%rax, %rdi
	call	wgetch
	movl	%eax, -668(%rbp)
	call	endwin
	movl	-668(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC1, %edi
	call	puts
	leaq	-672(%rbp), %rdx
	leaq	-676(%rbp), %rcx
	movl	-668(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	input
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	system
	leaq	-656(%rbp), %rax
	movq	%rax, %rdi
	call	printArr
	movl	-660(%rbp), %eax
	movl	%eax, %edi
	call	wait
.L36:
	cmpb	$0, -678(%rbp)
	jne	.L37
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L39
	call	__stack_chk_fail
.L39:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
