section    .data
	nline	db	10,10
	nline_len	equ	$-nline
	
	arr64	dq	-21H, 5FH, -33H, -12H, 62H
	n		equ	5   ;variable which stores number of elements in array

	pmsg		db	10,10,"Positive numbers in 64-bit array :	"
	pmsg_len	equ	$-pmsg

	nmsg		db	10,10,"Negative numbers in 64-bit array :	"
	nmsg_len	equ	$-nmsg

;---------------------------------------------------------------------
Section   .bss
	p_count	resq	1		;reserves a quadword
	n_count	resq	1	        ;

	char_ans	resb	16
;---------------------------------------------------------------------
%macro  Print   2
	mov   rax, 1
	mov   rdi, 1
	mov   rsi, %1
	mov   rdx, %2
	syscall
%endmacro

%macro  Read   2
	mov   rax, 0
	mov   rdi, 0
	mov   rsi, %1
	mov   rdx, %2
	syscall
%endmacro

%macro	Exit	0
	mov  rax, 60
	mov  rdi, 0
	syscall
%endmacro

;---------------------------------------------------------------------
section    .text
	global   _start
_start:

	mov		rsi, arr64	
	mov		rcx, n          ; n is the counter for 5 numbers

	mov		rbx,0;		; counter for 	+ve nos.
	mov		rdx,0;		; counter for	-ve nos.

next_num:
	mov		rax,[rsi]		; take no. in RAX
	Rol		rax,1		; rotate left 1 bit to check for sign bit in the CF 
	jc		negative

positive:
	inc		rbx			; no carry, so no. is +ve, hence increment
	jmp		next

negative:
	inc		rdx			; carry, so no. is -ve, hence increment

next:
	add 		rsi,8		; 64 bit nos i.e. 8 bytes
	dec 		rcx
	jnz  	next_num

	mov		[p_count], rbx		; store positive count
	mov		[n_count], rdx		; store negative count

	Print	pmsg, pmsg_len
	mov 		rax,[p_count]		; load value of p_count in rax
	call 	disp64_proc		; display p_count

	Print	nmsg, nmsg_len
	mov 		rax,[n_count]		; load value of n_count in rax
	call 	disp64_proc		; display n_count

	Print	nline, nline_len
	Exit
;--------------------------------------------------------------------	
disp64_proc:
	mov 		rbx,16			; divisor=16 for hex
	mov 		rcx,2			; number of digits 
	mov 		rsi,char_ans+1		; load last byte address of char_ans buffer in rsi

cnt:	mov 		rdx,0			; make rdx=0 (as in div instruction rdx:rax/rbx)
	div 		rbx

	cmp 		dl, 09h			; check for remainder in rdx
	jbe  	add30
	add  	dl, 07h 
add30:
	add 		dl,30h			; calculate ASCII code
	mov 		[rsi],dl			; store it in buffer
	dec 		rsi				; point to one byte back

	dec 		rcx				; decrement count
	jnz 		cnt				; if not zero repeat
	
	Print 	char_ans,2		; display result on screen
ret
;----------------------------------------------------------------
