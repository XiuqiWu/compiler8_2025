	.text
	.globl	a
	.data
	.align	3
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.text
	.globl	b
	.data
	.align	3
	.type	b, @object
	.size	b, 4
b:
	.zero	4
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	call	get_int
	sw	a0, -20(s0)
	lw	t4, -20(s0)
	lui	t1, %hi(a)
	sw	t4, %lo(a)(t1)
	call	get_int
	sw	a0, -24(s0)
	lw	t4, -24(s0)
	lui	t1, %hi(b)
	sw	t4, %lo(b)(t1)
	li	t4, 0
	sw	t4, -28(s0)
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	lui	t1, %hi(b)
	lw	t6, %lo(b)(t1)
	beq	t5, t6, .Label4
	j	.Label3
.Label4:
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	li	t6, 3
	beq	t5, t6, .Label3
	j	.Label2
.Label2:
	li	t4, 1
	sw	t4, -28(s0)
	j	.Label1
.Label3:
	li	t4, 0
	sw	t4, -28(s0)
	j	.Label1
.Label1:
	lw	a0, -28(s0)
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
