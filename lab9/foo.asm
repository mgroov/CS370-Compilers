.data 

_L1:	 .asciiz	"2 + 3"
_L2:	 .asciiz	"3 * 2"
_L3:	 .asciiz	"4 + 7 * 2 - 8 / 4 (should be 16)"
_L4:	 .asciiz	"6 / 2"
_L5:	 .asciiz	"5 - 4"
_L6:	 .asciiz	"Testing NOT"
_L11:	 .asciiz	"Testing AND"
_L16:	 .asciiz	"Testing OR"
_L21:	 .asciiz	"Testing =="
_L26:	 .asciiz	"Testing !="
_L31:	 .asciiz	"Testing <"
_L38:	 .asciiz	"Testing >"
_L45:	 .asciiz	"Testing <="
_L52:	 .asciiz	"Testing >="
_L59:	 .asciiz	"Testing while (expecting 6 writes)"
_L61:	 .asciiz	"Loop landed!"
_L60:	 .asciiz	"Look ma, I'ma loop!"
_L57:	 .asciiz	"!= passed"
_L58:	 .asciiz	"!= failed"
_L55:	 .asciiz	"!= failed"
_L56:	 .asciiz	"!= passed"
_L53:	 .asciiz	"!= passed"
_L54:	 .asciiz	"!= failed"
_L50:	 .asciiz	"!= passes"
_L51:	 .asciiz	"!= failed"
_L48:	 .asciiz	"!= failed"
_L49:	 .asciiz	"!= passed"
_L46:	 .asciiz	"!= passed"
_L47:	 .asciiz	"!= failed"
_L43:	 .asciiz	"!= failed"
_L44:	 .asciiz	"!= passed"
_L41:	 .asciiz	"!= failed"
_L42:	 .asciiz	"!= passed"
_L39:	 .asciiz	"!= passed"
_L40:	 .asciiz	"!= failed"
_L36:	 .asciiz	"!= failed"
_L37:	 .asciiz	"!= passed"
_L34:	 .asciiz	"!= failed"
_L35:	 .asciiz	"!= passed"
_L32:	 .asciiz	"!= passed"
_L33:	 .asciiz	"!= failed"
_L29:	 .asciiz	"!= failed"
_L30:	 .asciiz	"!= passed"
_L27:	 .asciiz	"!= passed"
_L28:	 .asciiz	"!= failed"
_L24:	 .asciiz	"== failed"
_L25:	 .asciiz	"== passed"
_L22:	 .asciiz	"== passed"
_L23:	 .asciiz	"== failed"
_L19:	 .asciiz	"or failed"
_L20:	 .asciiz	"or passed"
_L17:	 .asciiz	"or passed"
_L18:	 .asciiz	"or failed"
_L14:	 .asciiz	"and passed"
_L15:	 .asciiz	"and failed"
_L12:	 .asciiz	"and failed"
_L13:	 .asciiz	"and passed"
_L9:	 .asciiz	"not passed"
_L10:	 .asciiz	"not failed"
_L7:	 .asciiz	"not failed"
_L8:	 .asciiz	"not passed"
_L0:	 .asciiz	"function reached with val"
_NL:	 .asciiz	"\n"

.align 2 

x:	 .space	4
p:	 .space	28
t:	 .space	4
f:	 .space	4
y:	 .space	4
z:	 .space	4

.text


.globl main

fail:				#start of Function
		subu $a0, $sp, 12		#adjust the stack pointer for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		#adjust the stack pointer
				
		li $v0, 4		#print the string
		la $a0, _L0		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
				
		lw $ra, 4($sp)		#restore RA
		lw $sp, ($sp)		#restore SP
				
		jr $ra		# jump back to RA
				
				
		lw $ra, 4($sp)		#restore RA
		lw $sp, ($sp)		#restore SP
				
		jr $ra		# jump back to RA
				
main:				#start of Function
		subu $a0, $sp, 188		#adjust the stack pointer for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		#adjust the stack pointer
				
		li $a0, 123		# expression is a NUM
		sw $a0, 12($sp)		#store right hand side into node
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $t0 , 12($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 16($sp)		#store left side of expr
		li $a0, 45		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 16($sp)		#load back left side of expr
		sub $a0,$a0,$a2		#subtract the left and right
		sw $a0, 20($sp)		#store right hand side into node
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $t0 , 20($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		add $a0, $sp , 8		#identifier is a local scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $v0, 4		#print the string
		la $a0, _L1		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 2		# expression is a NUM
		sw $a0, 24($sp)		#store left side of expr
		li $a0, 3		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 24($sp)		#load back left side of expr
		add $a0,$a0,$a2		#add the left and right hand side
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 1		# expression is a NUM
		sw $a0, 28($sp)		#store right hand side into node
		la $a0,t		#identifier is a global scalar
				
		lw $t0 , 28($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $a0, 0		# expression is a NUM
		sw $a0, 32($sp)		#store right hand side into node
		la $a0,f		#identifier is a global scalar
				
		lw $t0 , 32($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $a0, 3		# expression is a NUM
		sw $a0, 36($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 36($sp)		#load back left side of expr
		mult $a0, $a2		#multiply the left and right
		mflo $a0		#grabs the multuplication product from the low bit
		sw $a0, 40($sp)		#store right hand side into node
		la $a0,x		#identifier is a global scalar
				
		lw $t0 , 40($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $v0, 4		#print the string
		la $a0, _L2		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		la $a0,x		#identifier is a global scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $v0, 4		#print the string
		la $a0, _L3		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 4		# expression is a NUM
		sw $a0, 48($sp)		#store left side of expr
		li $a0, 7		# expression is a NUM
		sw $a0, 44($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 44($sp)		#load back left side of expr
		mult $a0, $a2		#multiply the left and right
		mflo $a0		#grabs the multuplication product from the low bit
		move $a2, $a0		#storing right hand side
		lw $a0, 48($sp)		#load back left side of expr
		add $a0,$a0,$a2		#add the left and right hand side
		sw $a0, 56($sp)		#store left side of expr
		li $a0, 8		# expression is a NUM
		sw $a0, 52($sp)		#store left side of expr
		li $a0, 4		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 52($sp)		#load back left side of expr
		div $a0, $a2		#divide the left and right hand side
		mflo $a0		#grabs the division product from the low bit
		move $a2, $a0		#storing right hand side
		lw $a0, 56($sp)		#load back left side of expr
		sub $a0,$a0,$a2		#subtract the left and right
		sw $a0, 60($sp)		#store right hand side into node
		li $a0, 3		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $t0 , 60($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $a0, 3		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 6		# expression is a NUM
		sw $a0, 64($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 64($sp)		#load back left side of expr
		div $a0, $a2		#divide the left and right hand side
		mflo $a0		#grabs the division product from the low bit
		sw $a0, 68($sp)		#store right hand side into node
		la $a0,y		#identifier is a global scalar
				
		lw $t0 , 68($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $v0, 4		#print the string
		la $a0, _L4		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		la $a0,y		#identifier is a global scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 5		# expression is a NUM
		sw $a0, 72($sp)		#store left side of expr
		li $a0, 4		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 72($sp)		#load back left side of expr
		sub $a0,$a0,$a2		#subtract the left and right
		sw $a0, 76($sp)		#store right hand side into node
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $t0 , 76($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $v0, 4		#print the string
		la $a0, _L5		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 80($sp)		#store right hand side into node
		li $a0, 1		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $t0 , 80($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $a0, 0		# expression is a NUM
		sw $a0, 84($sp)		#store right hand side into node
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $t0 , 84($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $v0, 4		#print the string
		la $a0, _L6		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		la $a0,t		#identifier is a global scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 88($sp)		#store left side of expr
		lw $a0, 88($sp)		#load back left side of expr
		sltiu $a0, $a0, 1		# the not
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L62		#check if not true
		li $v0, 4		#print the string
		la $a0, _L7		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L63		#jump to end
_L62:				#else part
		li $v0, 4		#print the string
		la $a0, _L8		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L63:				#end of if statment
		la $a0,f		#identifier is a global scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 92($sp)		#store left side of expr
		lw $a0, 92($sp)		#load back left side of expr
		sltiu $a0, $a0, 1		# the not
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L64		#check if not true
		li $v0, 4		#print the string
		la $a0, _L9		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L65		#jump to end
_L64:				#else part
		li $v0, 4		#print the string
		la $a0, _L10		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L65:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L11		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 96($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 96($sp)		#load back left side of expr
		and $a0, $a2,$a0		#ands the left and the right hand side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L66		#check if not true
		li $v0, 4		#print the string
		la $a0, _L12		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L67		#jump to end
_L66:				#else part
		li $v0, 4		#print the string
		la $a0, _L13		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L67:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 100($sp)		#store left side of expr
		li $a0, 1		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 100($sp)		#load back left side of expr
		and $a0, $a2,$a0		#ands the left and the right hand side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L68		#check if not true
		li $v0, 4		#print the string
		la $a0, _L14		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L69		#jump to end
_L68:				#else part
		li $v0, 4		#print the string
		la $a0, _L15		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L69:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L16		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 104($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 104($sp)		#load back left side of expr
		or $a0, $a2, $a0		#ors the left and the right hand side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L70		#check if not true
		li $v0, 4		#print the string
		la $a0, _L17		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L71		#jump to end
_L70:				#else part
		li $v0, 4		#print the string
		la $a0, _L18		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L71:				#end of if statment
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 108($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 108($sp)		#load back left side of expr
		or $a0, $a2, $a0		#ors the left and the right hand side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L72		#check if not true
		li $v0, 4		#print the string
		la $a0, _L19		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L73		#jump to end
_L72:				#else part
		li $v0, 4		#print the string
		la $a0, _L20		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L73:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L21		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 112($sp)		#store left side of expr
		li $a0, 1		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 112($sp)		#load back left side of expr
		seq $a0, $a0, $a2		#equal equals for left and right hand side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L74		#check if not true
		li $v0, 4		#print the string
		la $a0, _L22		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L75		#jump to end
_L74:				#else part
		li $v0, 4		#print the string
		la $a0, _L23		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L75:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 116($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 116($sp)		#load back left side of expr
		seq $a0, $a0, $a2		#equal equals for left and right hand side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L76		#check if not true
		li $v0, 4		#print the string
		la $a0, _L24		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L77		#jump to end
_L76:				#else part
		li $v0, 4		#print the string
		la $a0, _L25		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L77:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L26		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 120($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 120($sp)		#load back left side of expr
		seq $a0, $a0, $a2		# equals equals expression
		sltiu $a0, $a0, 1		# the not for the not equals
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L78		#check if not true
		li $v0, 4		#print the string
		la $a0, _L27		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L79		#jump to end
_L78:				#else part
		li $v0, 4		#print the string
		la $a0, _L28		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L79:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 124($sp)		#store left side of expr
		li $a0, 1		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 124($sp)		#load back left side of expr
		seq $a0, $a0, $a2		# equals equals expression
		sltiu $a0, $a0, 1		# the not for the not equals
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L80		#check if not true
		li $v0, 4		#print the string
		la $a0, _L29		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L81		#jump to end
_L80:				#else part
		li $v0, 4		#print the string
		la $a0, _L30		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L81:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L31		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 128($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 128($sp)		#load back left side of expr
		slt $a0, $a0, $a2		#less than for left and right side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L82		#check if not true
		li $v0, 4		#print the string
		la $a0, _L32		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L83		#jump to end
_L82:				#else part
		li $v0, 4		#print the string
		la $a0, _L33		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L83:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 132($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 132($sp)		#load back left side of expr
		slt $a0, $a0, $a2		#less than for left and right side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L84		#check if not true
		li $v0, 4		#print the string
		la $a0, _L34		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L85		#jump to end
_L84:				#else part
		li $v0, 4		#print the string
		la $a0, _L35		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L85:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 136($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 136($sp)		#load back left side of expr
		slt $a0, $a0, $a2		#less than for left and right side
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L86		#check if not true
		li $v0, 4		#print the string
		la $a0, _L36		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L87		#jump to end
_L86:				#else part
		li $v0, 4		#print the string
		la $a0, _L37		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L87:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L38		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 140($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 140($sp)		#load back left side of expr
		sgt $a0, $a0, $a2		#greater than for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L88		#check if not true
		li $v0, 4		#print the string
		la $a0, _L39		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L89		#jump to end
_L88:				#else part
		li $v0, 4		#print the string
		la $a0, _L40		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L89:				#end of if statment
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 144($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 144($sp)		#load back left side of expr
		sgt $a0, $a0, $a2		#greater than for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L90		#check if not true
		li $v0, 4		#print the string
		la $a0, _L41		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L91		#jump to end
_L90:				#else part
		li $v0, 4		#print the string
		la $a0, _L42		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L91:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 148($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 148($sp)		#load back left side of expr
		sgt $a0, $a0, $a2		#greater than for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L92		#check if not true
		li $v0, 4		#print the string
		la $a0, _L43		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L93		#jump to end
_L92:				#else part
		li $v0, 4		#print the string
		la $a0, _L44		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L93:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L45		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 152($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 152($sp)		#load back left side of expr
		sle $a0, $a0, $a2		#less than or equal for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L94		#check if not true
		li $v0, 4		#print the string
		la $a0, _L46		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L95		#jump to end
_L94:				#else part
		li $v0, 4		#print the string
		la $a0, _L47		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L95:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 156($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 156($sp)		#load back left side of expr
		sle $a0, $a0, $a2		#less than or equal for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L96		#check if not true
		li $v0, 4		#print the string
		la $a0, _L48		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L97		#jump to end
_L96:				#else part
		li $v0, 4		#print the string
		la $a0, _L49		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L97:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 160($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 160($sp)		#load back left side of expr
		sle $a0, $a0, $a2		#less than or equal for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L98		#check if not true
		li $v0, 4		#print the string
		la $a0, _L50		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L99		#jump to end
_L98:				#else part
		li $v0, 4		#print the string
		la $a0, _L51		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L99:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L52		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 164($sp)		#store left side of expr
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 164($sp)		#load back left side of expr
		sge $a0, $a0, $a2		#greater than or equal for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L100		#check if not true
		li $v0, 4		#print the string
		la $a0, _L53		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L101		#jump to end
_L100:				#else part
		li $v0, 4		#print the string
		la $a0, _L54		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L101:				#end of if statment
		li $a0, 2		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 168($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 168($sp)		#load back left side of expr
		sge $a0, $a0, $a2		#greater than or equal for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L102		#check if not true
		li $v0, 4		#print the string
		la $a0, _L55		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L103		#jump to end
_L102:				#else part
		li $v0, 4		#print the string
		la $a0, _L56		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L103:				#end of if statment
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 172($sp)		#store left side of expr
		li $a0, 0		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		move $a2, $a0		#storing right hand side
		lw $a0, 172($sp)		#load back left side of expr
		sge $a0, $a0, $a2		#greater than or equal for left and right
		li $t0 ,0		#sets t0 to zero
		beq $a0, $t0 _L104		#check if not true
		li $v0, 4		#print the string
		la $a0, _L57		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		j _L105		#jump to end
_L104:				#else part
		li $v0, 4		#print the string
		la $a0, _L58		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L105:				#end of if statment
		li $v0, 4		#print the string
		la $a0, _L59		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
_L106:				#while
		la $a0,x		#identifier is a global scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		beq $a0, $0 _L108		#if while condition no longer true
		li $v0, 4		#print the string
		la $a0, _L60		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		la $a0,x		#identifier is a global scalar
				
		lw $a0, ($a0)		#fetch value for ident from memory
		sw $a0, 176($sp)		#store left side of expr
		li $a0, 1		# expression is a NUM
		move $a2, $a0		#storing right hand side
		lw $a0, 176($sp)		#load back left side of expr
		sub $a0,$a0,$a2		#subtract the left and right
		sw $a0, 180($sp)		#store right hand side into node
		la $a0,x		#identifier is a global scalar
				
		lw $t0 , 180($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		j _L106		#jump back to check while condition
_L108:				#end of while
		li $v0, 4		#print the string
		la $a0, _L61		#the label to be printed
		syscall		#system call for printing the string
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 42		# expression is a NUM
		sw $a0, 176($sp)		#store right hand side into node
		li $a0, 7		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $t0 , 176($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $a0, 7		# expression is a NUM
		sw $a0, 180($sp)		#store right hand side into node
		li $a0, 3		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $t0 , 180($sp)		#store right hand side into register
		sw $t0,($a0)		#store the right hand side in a0
		li $a0, 3		# expression is a NUM
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		la $t0, p		#getting array adress
		li $t1, 4		#loading size into a temp to multiply
		mult $a0,$t1		#multiplying internal offset by 4
		mflo $a0		#grab the product
		add $a0, $t0,$a0		#adding internal offset ident is a global array
				
		lw $a0, ($a0)		#fetch value for ident from memory
		li $v0, 1		#print the number
		syscall		#system call for printing the number
				
		li $v0, 4		#print the new line
		la $a0,_NL		#the new line
		syscall		#system call for printing the string
		li $a0, 5		# expression is a NUM
		sw $a0 , 184($sp)		#stores arg list
		subu $t2 ,$sp, 12		#subtracting size of function from stack pointer
		lw $t0, 184($sp)		#re grabbing values from temp nodes
		sw $t0, 8($t2)		#putting values back into fparams adress
		jal fail		#jumps and links the function call
				
		lw $ra, 4($sp)		#restore RA
		lw $sp, ($sp)		#restore SP
				
		li $v0, 10		#Leave main program
		syscall		# leave main
				
