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
	.word	6
_bool_tag:
	.word	7
_string_tag:
	.word	8
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
str_const16:
	.word	8
	.word	5
	.word	String_dispTab
	.word	int_const2
	.byte	0	
	.align	2
	.word	-1
str_const15:
	.word	8
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const14:
	.word	8
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Bazz"
	.byte	0	
	.align	2
	.word	-1
str_const13:
	.word	8
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Razz"
	.byte	0	
	.align	2
	.word	-1
str_const12:
	.word	8
	.word	5
	.word	String_dispTab
	.word	int_const4
	.ascii	"Bar"
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	8
	.word	5
	.word	String_dispTab
	.word	int_const4
	.ascii	"Foo"
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	8
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	8
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	8
	.word	5
	.word	String_dispTab
	.word	int_const4
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	8
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	8
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	8
	.word	7
	.word	String_dispTab
	.word	int_const6
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	8
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	8
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	8
	.word	8
	.word	String_dispTab
	.word	int_const8
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	8
	.word	7
	.word	String_dispTab
	.word	int_const6
	.ascii	"do nothing"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	8
	.word	8
	.word	String_dispTab
	.word	int_const9
	.ascii	"./hairyscary.cl"
	.byte	0	
	.align	2
	.word	-1
int_const9:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	15
	.word	-1
int_const8:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const7:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const6:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const5:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const4:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const3:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const2:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
int_const1:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const0:
	.word	6
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
bool_const0:
	.word	7
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	7
	.word	4
	.word	Bool_dispTab
	.word	1
class_nameTab:
	.word	str_const6
	.word	str_const7
	.word	str_const14
	.word	str_const11
	.word	str_const13
	.word	str_const12
	.word	str_const8
	.word	str_const9
	.word	str_const10
	.word	str_const15
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	Bazz_protObj
	.word	Bazz_init
	.word	Foo_protObj
	.word	Foo_init
	.word	Razz_protObj
	.word	Razz_init
	.word	Bar_protObj
	.word	Bar_init
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
Bazz_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Bazz.printh
	.word	Bazz.doh
Razz_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Bazz.printh
	.word	Foo.doh
Bar_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Bazz.printh
	.word	Foo.doh
Foo_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Bazz.printh
	.word	Foo.doh
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
	.word	9
	.word	7
	.word	Main_dispTab
	.word	0
	.word	0
	.word	0
	.word	0
	.word	-1
Bazz_protObj:
	.word	2
	.word	6
	.word	Bazz_dispTab
	.word	Int_protObj
	.word	0
	.word	0
	.word	-1
Razz_protObj:
	.word	4
	.word	10
	.word	Razz_dispTab
	.word	Int_protObj
	.word	0
	.word	0
	.word	0
	.word	Int_protObj
	.word	0
	.word	Int_protObj
	.word	-1
Bar_protObj:
	.word	5
	.word	12
	.word	Bar_dispTab
	.word	Int_protObj
	.word	0
	.word	0
	.word	0
	.word	Int_protObj
	.word	0
	.word	Int_protObj
	.word	Int_protObj
	.word	0
	.word	-1
Foo_protObj:
	.word	3
	.word	8
	.word	Foo_dispTab
	.word	Int_protObj
	.word	0
	.word	0
	.word	0
	.word	Int_protObj
	.word	-1
String_protObj:
	.word	8
	.word	5
	.word	String_dispTab
	.word	int_const2
	.byte	0	
	.word	-1
Bool_protObj:
	.word	7
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
Int_protObj:
	.word	6
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
	la	$a0 Bazz_protObj
	jal	Object.copy
	jal	Bazz_init
	# assign init value to the offset of self
	sw	$a0 12($s0)
	move	$a0 $s0
	la	$a0 Foo_protObj
	jal	Object.copy
	jal	Foo_init
	# assign init value to the offset of self
	sw	$a0 16($s0)
	move	$a0 $s0
	la	$a0 Razz_protObj
	jal	Object.copy
	jal	Razz_init
	# assign init value to the offset of self
	sw	$a0 20($s0)
	move	$a0 $s0
	la	$a0 Bar_protObj
	jal	Object.copy
	jal	Bar_init
	# assign init value to the offset of self
	sw	$a0 24($s0)
	move	$a0 $s0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bazz_init:
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
	jal	IO_init
	move	$s0 $a0
	la	$a0 int_const1
	# assign init value to the offset of self
	sw	$a0 12($s0)
	move	$a0 $s0
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	# void expression, we call abort
	bne	$a0 $zero label1
	la	$a0 str_const0
	li	$t1 39
	jal	_case_abort2
label1:
	lw	$t1 0($a0)
	# check if match
	blt	$t1 5 label3
	bgt	$t1 5 label3
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -12($fp)
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label0
	# we do not fit it, so generate next lable
label3:
	# check if match
	blt	$t1 4 label4
	bgt	$t1 5 label4
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Bar_protObj
	jal	Object.copy
	jal	Bar_init
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label0
	# we do not fit it, so generate next lable
label4:
	# check if match
	blt	$t1 3 label5
	bgt	$t1 5 label5
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Razz_protObj
	jal	Object.copy
	jal	Razz_init
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label0
	# we do not fit it, so generate next lable
label5:
	# check if match
	blt	$t1 2 label6
	bgt	$t1 5 label6
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Foo_protObj
	jal	Object.copy
	jal	Foo_init
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label0
	# we do not fit it, so generate next lable
label6:
	# we do not match, we call abort
label2:
	jal	_case_abort
	# successfully match !
label0:
	# assign init value to the offset of self
	sw	$a0 16($s0)
	move	$a0 $s0
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label7
	la	$a0 str_const0
	li	$t1 46
	jal	_dispatch_abort
label7:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	# assign init value to the offset of self
	sw	$a0 20($s0)
	move	$a0 $s0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Razz_init:
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
	jal	Foo_init
	move	$s0 $a0
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	# void expression, we call abort
	bne	$a0 $zero label9
	la	$a0 str_const0
	li	$t1 26
	jal	_case_abort2
label9:
	lw	$t1 0($a0)
	# check if match
	blt	$t1 5 label11
	bgt	$t1 5 label11
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -12($fp)
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label8
	# we do not fit it, so generate next lable
label11:
	# check if match
	blt	$t1 4 label12
	bgt	$t1 5 label12
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Bar_protObj
	jal	Object.copy
	jal	Bar_init
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label8
	# we do not fit it, so generate next lable
label12:
	# we do not match, we call abort
label10:
	jal	_case_abort
	# successfully match !
label8:
	# assign init value to the offset of self
	sw	$a0 32($s0)
	move	$a0 $s0
	# push args
	# here we use self as pointer
	lw	$a0 24($s0)
	# check if void
	bne	$a0 $zero label13
	# prepare arg to call abort
	la	$a0 str_const0
	li	$t1 31
	jal	_dispatch_abort
label13:
	la	$t1 Bazz_dispTab
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# here we use self as pointer
	lw	$a0 16($s0)
	bne	$a0 $zero label14
	la	$a0 str_const0
	li	$t1 31
	jal	_dispatch_abort
label14:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# here we use self as pointer
	lw	$a0 32($s0)
	bne	$a0 $zero label15
	la	$a0 str_const0
	li	$t1 31
	jal	_dispatch_abort
label15:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label16
	la	$a0 str_const0
	li	$t1 31
	jal	_dispatch_abort
label16:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label17
	la	$a0 str_const0
	li	$t1 31
	jal	_dispatch_abort
label17:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	# assign init value to the offset of self
	sw	$a0 36($s0)
	move	$a0 $s0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bar_init:
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
	jal	Razz_init
	move	$s0 $a0
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label18
	la	$a0 str_const0
	li	$t1 18
	jal	_dispatch_abort
label18:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	# assign init value to the offset of self
	sw	$a0 40($s0)
	move	$a0 $s0
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label19
	la	$a0 str_const0
	li	$t1 20
	jal	_dispatch_abort
label19:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	# assign init value to the offset of self
	sw	$a0 44($s0)
	move	$a0 $s0
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Foo_init:
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
	jal	Bazz_init
	move	$s0 $a0
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	# void expression, we call abort
	bne	$a0 $zero label21
	la	$a0 str_const0
	li	$t1 4
	jal	_case_abort2
label21:
	lw	$t1 0($a0)
	# check if match
	blt	$t1 5 label23
	bgt	$t1 5 label23
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use fp as pointer
	lw	$a0 -12($fp)
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label20
	# we do not fit it, so generate next lable
label23:
	# check if match
	blt	$t1 4 label24
	bgt	$t1 5 label24
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Bar_protObj
	jal	Object.copy
	jal	Bar_init
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label20
	# we do not fit it, so generate next lable
label24:
	# check if match
	blt	$t1 3 label25
	bgt	$t1 5 label25
	# new scope
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Razz_protObj
	jal	Object.copy
	jal	Razz_init
	addiu	$sp $sp 4
	# exit new scope
	# if we fit, we get to the end
	b	label20
	# we do not fit it, so generate next lable
label25:
	# we do not match, we call abort
label22:
	jal	_case_abort
	# successfully match !
label20:
	# assign init value to the offset of self
	sw	$a0 24($s0)
	move	$a0 $s0
	# push args
	# here we use self as pointer
	lw	$a0 24($s0)
	bne	$a0 $zero label26
	la	$a0 str_const0
	li	$t1 10
	jal	_dispatch_abort
label26:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# here we use self as pointer
	lw	$a0 16($s0)
	bne	$a0 $zero label27
	la	$a0 str_const0
	li	$t1 10
	jal	_dispatch_abort
label27:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label28
	la	$a0 str_const0
	li	$t1 10
	jal	_dispatch_abort
label28:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# push args
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label29
	la	$a0 str_const0
	li	$t1 10
	jal	_dispatch_abort
label29:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	# assign init value to the offset of self
	sw	$a0 28($s0)
	move	$a0 $s0
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
	la	$a0 str_const1
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bazz.printh:
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
	# push args
	# here we use self as pointer
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# the lable is self, so we load s0 to a0, s0 store the address of self
	move	$a0 $s0
	bne	$a0 $zero label30
	la	$a0 str_const0
	li	$t1 48
	jal	_dispatch_abort
label30:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	la	$a0 int_const2
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bazz.doh:
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
	# here we use self as pointer
	lw	$a0 12($s0)
	# now we push the value we creating into stack
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use self as pointer
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 12($s0)
	# here we use fp as pointer
	lw	$a0 -12($fp)
	addiu	$sp $sp 4
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Foo.doh:
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
	# here we use self as pointer
	lw	$a0 12($s0)
	# now we push the value we creating into stack
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	# here we use self as pointer
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	lw	$t1 4($sp)
	addiu	$sp $sp 4
	lw	$t2 12($t1)
	lw	$t3 12($a0)
	add	$t2 $t2 $t3
	sw	$t2 12($a0)
	sw	$a0 12($s0)
	# here we use fp as pointer
	lw	$a0 -12($fp)
	addiu	$sp $sp 4
	# restore register
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	

# end of generated code
