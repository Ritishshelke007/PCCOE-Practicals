section .data
	msg1 db 10,13,"Enter 5 numbers : ",10
	len1 equ $-msg1
	msg2 db 10,13,"Entered 5 numbers are : ",10
	len2 equ $-msg2

section .bss
	array resd 200
	counter resb 1
	
	
%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro exit 0
mov rax,60
mov rdi,0
syscall
%endmacro


section .text
	global _start
	
_start:

print msg1,len1

call accept

print msg2,len2

call display

exit


accept:

mov byte[counter],05
mov rbx,00

		loop1:
			mov rax,0                  ; 0 for read
			mov rdi,0                  ; 0 for keyboard   
			mov rsi, array             ;move pointer to start of array
			add rsi,rbx               
			mov rdx,17                 ;16 bit +1 for enter 
			syscall
			
         		add rbx,17                 ;to move counter
			dec byte[counter]
			JNZ loop1
			
		ret
		
display: 

mov byte[counter],05
mov rbx,00
		loop2: 
			mov rax,1                   ;1 for write 
			mov rdi, 1                  ;1 for monitor
			mov rsi, array                
			add rsi,rbx
			mov rdx,17                  ;16 bit +1 for enter 
			syscall
			
			add rbx,17
			dec byte[counter]
			JNZ loop2
		ret
		
