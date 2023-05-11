section .data
	msg1 db 10,10,"Assignment no 4  : Conversion of 1)HEX TO BCD 2)BCD TO HEX"
	msg1_len equ $-msg1
	
	msg2 db 10,10,"Menu : 1) HEX TO BCD 2)BCD TO HEX  :  "
	msg2_len equ $-msg2
	
	msg3 db 10,10,"Selected 1)HEX TO BCD"
	msg3_len equ $-msg3
	
	msg4 db 10,10,"Selected 2)BCD TO HEX"
	msg4_len equ $-msg4
	
	msg5 db 10,10,"Enter 5 digit BCD number : "
	msg5_len equ $-msg5
	
	msg6 db 10,10,"Equivalent HEX number : "
	msg6_len equ $-msg6 
	
	msg7 db 10,10, "invalid input "
	msg7_len equ $-msg7
	
	msg8 db 10,10, "Enter HEX number : "
	msg8_len equ $-msg8
	
	msg9 db 10,10, "Equivalent BCD number is : ";
	msg9_len equ $-msg9
	
	
	
	
	
section .bss
	inputno resb 50
	inputno_len equ $-inputno 
	
	buf resb 6
	ans resw 1
	char_ans resb 4

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
	call BCD_TO_HEX
	Exit
	
	L1: 
	print msg3,msg3_len
	call HEX_TO_BCD
	Exit	
		
	
	mov rax,60
	mov rdi,0
	syscall
	
	
;--------------------------------------------------------
HEX_TO_BCD:
	print msg8,msg8_len
	call accept_16    ; accept hex number from procedure
	
	mov ax,bx     ; move bx data in ax ( hex number)
	
	mov bx,10 	; divide by 10 
	xor bp,bp  	; counter
	
back:
	xor dx,dx	; remainder is stored in dx
	div bx		; divide ax by 10 store quotient in ax and remainder in dx
	push dx		; push remainder on stack
	inc bp		; increment counter 
	
	cmp ax,0	; check quotient is 0 if 0 means number end 
	jne back
	
	print msg9,msg9_len
	

back1:	pop	dx			;pop last digit pushed on stack
	add	dl,30h			;add 30 to digit to make them decimal
	mov	[char_ans],dl		;print digit
	print	char_ans,1

	dec	bp	
	jnz	back1			;mov to next digit


RET
;--------------------------------------------------------



;-----------------------------------------------------------
	
BCD_TO_HEX:
	print msg5,msg5_len
	Read buf,6 
	
	mov rsi,buf    ; point to first ele of buf
	xor ax,ax      ; initial ax to 0
	mov rbp,5      ; counter
	mov rbx,10     ; multiply by 10 
	
next:   xor cx,cx      ; store prev result in next iteration
	mul bx         ; (ax*bx)
	mov cl,[rsi]   ; 
	sub cl,30h     ; hex number
	add ax,cx      ; (ax*bx)+cx
	
	inc rsi	       ; point to next number
	dec rbp        ; decrement counter
	jnz next       ; loop
	mov [ans],ax	;store ax in ans because ax get change in Print macro
	print msg6,msg6_len
	
	mov ax,[ans]
	call Disp_hex		;display hex number
	
	


RET
;--------------------------------------------------------
Disp_hex:				;Hex to Ascii(character) display
	MOV	RSI,char_ans+3
	MOV	RCX,4           	;counter
	MOV	RBX,16			;Hex no
	
next_digit:
	XOR	RDX,RDX
	DIV	RBX

	CMP	DL,9	
	JBE	add30
	ADD	DL,07H

add30:
	ADD	DL,30H
	MOV	[RSI],DL

	DEC	RSI
	DEC	RCX
	JNZ	next_digit

	print	char_ans,4
ret
;--------------------------------------------------------
accept_16:
	Read buf,5     ;read 4 digit + 1 enter key
	
	mov rcx,4      ;counter
	mov rsi,buf    ; rsi points to 1st number in buffer
	xor bx,bx      ;store 0 in bx
	
next_byte:
	shl bx,4
	mov al,[rsi]
	
	
	cmp al,'0'
	jb error
	cmp al,'9'
	jbe sub30
	
	cmp al,'A'
	jb error
	cmp al,'F'
	jbe sub37
	
	cmp al,'a'
	jb error
	cmp al,'f'
	jbe sub57
	
	
error:
	print msg7,msg7_len
	Exit
	
sub57: sub al,20h 
sub37: sub al,07h
sub30: sub al,30h

add  bx,ax
inc rsi
dec rcx
jnz next_byte

ret
