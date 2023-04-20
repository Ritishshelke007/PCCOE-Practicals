section .data
	msg1 db 10,10,"Assignment no 4  : Conversion of 1)HEX TO BCD 2)BCD TO HEX"
	msg1_len equ $-msg1
	
	msg2 db 10,10,"Menu : 1) HEX TO BCD 2)BCD TO HEX  :  "
	msg2_len equ $-msg2
	
	msg3 db 10,10,"Selected 1)HEX TO BCD"
	msg3_len equ $-msg3
	
	msg4 db 10,10,"Selected 2)BCD TO HEX"
	msg4_len equ $-msg4
	
	
	
	
	
	
section .bss
	inputno resb 50
	inputno_len equ $-inputno 

%macro Read 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro print 2
mov rax ,1
mov rdi ,1
mov rsi ,%1
mov rdx ,%2
syscall
%endmacro

%macro Exit 0
	mov rax,60
	mov rdi,0
	syscall
%endmacro



section .text
	global _start
	
_start:
	print msg1,msg1_len
	print msg2,msg2_len
	Read inputno,inputno_len
	
	mov bl,byte [inputno]
	cmp bl,'2'
	je L2
	
	mov bl,byte [inputno]
	cmp bl,'1'
	je L1
	
	
	L2: 
	print msg4, msg4_len
	Exit
	
	L1: 
	print msg3,msg3_len
	Exit	
		
	
	mov rax,60
	mov rdi,0
	syscall
