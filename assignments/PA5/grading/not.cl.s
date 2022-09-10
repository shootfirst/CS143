# start of generated code
	.data
	.align	2
	.globl	class_nameTab
	.globl	Main_protObj
	.globl	Int_protObj
	.globl	String_protObj
	.globl	bool_const0
	.globl	bool_const1
	.globl	_int_tag
	.globl	_bool_tag
	.globl	_string_tag
_int_tag:
	.word	2
_bool_tag:
	.word	3
_string_tag:
	.word	4
	.globl	_MemMgr_INITIALIZER
_MemMgr_INITIALIZER:
	.word	_NoGC_Init
	.globl	_MemMgr_COLLECTOR
_MemMgr_COLLECTOR:
	.word	_NoGC_Collect
	.globl	_MemMgr_TEST
_MemMgr_TEST:
	.word	0
	.word	-1
str_const11:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const5
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const6
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const9
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const10
	.ascii	"./not.cl"
	.byte	0	
	.align	2
	.word	-1
int_const10:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const9:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const8:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const7:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const6:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const5:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const4:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const3:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const2:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const1:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	100
	.word	-1
int_const0:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
bool_const0:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	1
class_nameTab:
	.word	str_const5
	.word	str_const6
	.word	str_const7
	.word	str_const8
	.word	str_const9
	.word	str_const10
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	Int_protObj
	.word	Int_init
	.word	Bool_protObj
	.word	Bool_init
	.word	String_protObj
	.word	String_init
	.word	Main_protObj
	.word	Main_init
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	Main.main
String_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	String.length
	.word	String.concat
	.word	String.substr
Bool_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
Int_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
IO_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
Object_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	-1
Main_protObj:
	.word	5
	.word	3
	.word	Main_dispTab
	.word	-1
String_protObj:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0	
	.word	-1
Bool_protObj:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
Int_protObj:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
IO_protObj:
	.word	1
	.word	3
	.word	IO_dispTab
	.word	-1
Object_protObj:
	.word	0
	.word	3
	.word	Object_dispTab
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main
Main_init:
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	move	$a0 $s0
	jal	Object_init
	move	$s0 $a0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
String_init:
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	move	$a0 $s0
	jal	Object_init
	move	$s0 $a0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bool_init:
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	move	$a0 $s0
	jal	Object_init
	move	$s0 $a0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Int_init:
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	move	$a0 $s0
	jal	Object_init
	move	$s0 $a0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
IO_init:
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	move	$a0 $s0
	jal	Object_init
	move	$s0 $a0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Object_init:
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main.main:
	# now we start generate method code
	# add args
	# push fp, s0, ra
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	# fp points to the return address
	addiu	$fp $sp 12
	# s0 is a0
	move	$s0 $a0
	la	$a0 int_const0
	# now we push the value we creating into stack
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Bool_protObj
	jal	Object.copy
	# now we push the value we creating into stack
	sw	$a0 0($sp)
	addiu	$sp $sp -4
label0:
	# here we use fp as pointer
	lw	$a0 -12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	la	$a0 bool_const1
	blt	$t2 $t3 label2
	la	$a0 bool_const0
label2:
	lw	$t1 12($a0)
	beq	$zero $t1 label1
	# here we use fp as pointer
	lw	$a0 -16($fp)
	# e1 we push, because if we store it in a register, it will be covered in e2 code method
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -16($fp)
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label3
	la	$a0 bool_const0
label3:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label4
	la	$a0 bool_const0
label4:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label5
	la	$a0 bool_const0
label5:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label6
	la	$a0 bool_const0
label6:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label7
	la	$a0 bool_const0
label7:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label8
	la	$a0 bool_const0
label8:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label9
	la	$a0 bool_const0
label9:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label10
	la	$a0 bool_const0
label10:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label11
	la	$a0 bool_const0
label11:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label12
	la	$a0 bool_const0
label12:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label13
	la	$a0 bool_const0
label13:
	# e2 in T2
	move	$t2 $a0
	# e1 in T1
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	# here we use fp as pointer
	lw	$a0 -16($fp)
	# e1 we push, because if we store it in a register, it will be covered in e2 code method
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -16($fp)
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label15
	la	$a0 bool_const0
label15:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label16
	la	$a0 bool_const0
label16:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label17
	la	$a0 bool_const0
label17:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label18
	la	$a0 bool_const0
label18:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label19
	la	$a0 bool_const0
label19:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label20
	la	$a0 bool_const0
label20:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label21
	la	$a0 bool_const0
label21:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label22
	la	$a0 bool_const0
label22:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label23
	la	$a0 bool_const0
label23:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label24
	la	$a0 bool_const0
label24:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label25
	la	$a0 bool_const0
label25:
	# e2 in T2
	move	$t2 $a0
	# e1 in T1
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	# here we use fp as pointer
	lw	$a0 -16($fp)
	# e1 we push, because if we store it in a register, it will be covered in e2 code method
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -16($fp)
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label27
	la	$a0 bool_const0
label27:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label28
	la	$a0 bool_const0
label28:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label29
	la	$a0 bool_const0
label29:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label30
	la	$a0 bool_const0
label30:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label31
	la	$a0 bool_const0
label31:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label32
	la	$a0 bool_const0
label32:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label33
	la	$a0 bool_const0
label33:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label34
	la	$a0 bool_const0
label34:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label35
	la	$a0 bool_const0
label35:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label36
	la	$a0 bool_const0
label36:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label37
	la	$a0 bool_const0
label37:
	# e2 in T2
	move	$t2 $a0
	# e1 in T1
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	# here we use fp as pointer
	lw	$a0 -16($fp)
	# e1 we push, because if we store it in a register, it will be covered in e2 code method
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -16($fp)
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label39
	la	$a0 bool_const0
label39:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label40
	la	$a0 bool_const0
label40:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label41
	la	$a0 bool_const0
label41:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label42
	la	$a0 bool_const0
label42:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label43
	la	$a0 bool_const0
label43:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label44
	la	$a0 bool_const0
label44:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label45
	la	$a0 bool_const0
label45:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label46
	la	$a0 bool_const0
label46:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label47
	la	$a0 bool_const0
label47:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label48
	la	$a0 bool_const0
label48:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label49
	la	$a0 bool_const0
label49:
	# e2 in T2
	move	$t2 $a0
	# e1 in T1
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	# here we use fp as pointer
	lw	$a0 -16($fp)
	# e1 we push, because if we store it in a register, it will be covered in e2 code method
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -16($fp)
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label51
	la	$a0 bool_const0
label51:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label52
	la	$a0 bool_const0
label52:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label53
	la	$a0 bool_const0
label53:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label54
	la	$a0 bool_const0
label54:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label55
	la	$a0 bool_const0
label55:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label56
	la	$a0 bool_const0
label56:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label57
	la	$a0 bool_const0
label57:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label58
	la	$a0 bool_const0
label58:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label59
	la	$a0 bool_const0
label59:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label60
	la	$a0 bool_const0
label60:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beq	$t1 $zero label61
	la	$a0 bool_const0
label61:
	# e2 in T2
	move	$t2 $a0
	# e1 in T1
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	# here we use fp as pointer
	lw	$a0 -12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 -12($fp)
	# jump to start
	b	label0
label1:
	# return result is void
	move	$a0 $zero
	# here we use fp as pointer
	lw	$a0 -16($fp)
	lw	$t1 12($a0)
	beq	$zero $t1 label63
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label65
	la	$a0 str_const0
	li	$t1 18
	jal	_dispatch_abort
label65:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	b	label64
label63:
	la	$a0 int_const0
label64:
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	

# end of generated code
