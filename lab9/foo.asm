.data 

_NL:	 .asciiz	"\n"

.align 2 


.text


.globl main

f:				#start of Function
		subu $a0, $sp, 12		#adjust the stack pointer for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		#adjust the stack pointer
				
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
				
		lw $ra, 4($sp)		#restore RA
		lw $sp, ($sp)		#restore SP
				
		jr $ra		# jump back to RA
				
main:				#start of Function
		subu $a0, $sp, 12		#adjust the stack pointer for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		#adjust the stack pointer
				
		li $a0, 5		# expression is a NUM
		sw $a0 , 8($sp)		#stores arg list
		subu $t2 ,$sp, 12		#subtracting size of function from stack pointer
		lw $t0, 8($sp)		#re grabbing values from temp nodes
		sw $t0, 8($t2)		#putting values back into fparams adress
		jal f		#jumps and links the function call
				
		lw $ra, 4($sp)		#restore RA
		lw $sp, ($sp)		#restore SP
				
		li $v0, 10		#Leave main program
		syscall		# leave main
				
