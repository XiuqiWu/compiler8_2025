	.text
	.globl	a
	.data
	.align	3
	.type	a, @object
	.size	a, 4
a:
	.word	1
	.text
	.globl	b
	.data
	.align	3
	.type	b, @object
	.size	b, 4
b:
	.word	0
	.text
	.globl	c
	.data
	.align	3
	.type	c, @object
	.size	c, 4
c:
	.word	1
	.text
	.globl	d
	.data
	.align	3
	.type	d, @object
	.size	d, 4
d:
	.word	2
	.text
	.globl	e
	.data
	.align	3
	.type	e, @object
	.size	e, 4
e:
	.word	4
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -64
	sd	ra, 56(sp)
	sd	s0, 48(sp)
	addi	s0, sp, 64
	li	t4, 0
	sw	t4, -20(s0)
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	lui	t1, %hi(b)
	lw	t6, %lo(b)(t1)
	mul t4, t5, t6
	sw	t4, -24(s0)
	lw	t5, -24(s0)
	lui	t1, %hi(c)
	lw	t6, %lo(c)(t1)
	div t4, t5, t6
	sw	t4, -28(s0)
	lui	t1, %hi(e)
	lw	t5, %lo(e)(t1)
	lui	t1, %hi(d)
	lw	t6, %lo(d)(t1)
	add t4, t5, t6
	sw	t4, -32(s0)
	lw	t5, -28(s0)
	lw	t6, -32(s0)
	beq	t5, t6, .Label4
	j	.Label3
.Label4:
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	lui	t1, %hi(b)
	lw	t6, %lo(b)(t1)
	add t4, t5, t6
	sw	t4, -36(s0)
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	lw	t6, -36(s0)
	mul t4, t5, t6
	sw	t4, -40(s0)
	lw	t5, -40(s0)
	lui	t1, %hi(c)
	lw	t6, %lo(c)(t1)
	add t4, t5, t6
	sw	t4, -44(s0)
	lui	t1, %hi(d)
	lw	t5, %lo(d)(t1)
	lui	t1, %hi(e)
	lw	t6, %lo(e)(t1)
	add t4, t5, t6
	sw	t4, -48(s0)
	lw	t5, -44(s0)
	lw	t6, -48(s0)
	ble	t5, t6, .Label2
	j	.Label3
.Label3:
	lui	t1, %hi(b)
	lw	t5, %lo(b)(t1)
	lui	t1, %hi(c)
	lw	t6, %lo(c)(t1)
	mul t4, t5, t6
	sw	t4, -52(s0)
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	lw	t6, -52(s0)
	sub t4, t5, t6
	sw	t4, -56(s0)
	lui	t1, %hi(a)
	lw	t5, %lo(a)(t1)
	lui	t1, %hi(c)
	lw	t6, %lo(c)(t1)
	div t4, t5, t6
	sw	t4, -60(s0)
	lui	t1, %hi(d)
	lw	t5, %lo(d)(t1)
	lw	t6, -60(s0)
	sub t4, t5, t6
	sw	t4, -64(s0)
	lw	t5, -56(s0)
	lw	t6, -64(s0)
	beq	t5, t6, .Label2
	j	.Label1
.Label2:
	li	t4, 1
	sw	t4, -20(s0)
	j	.Label1
.Label1:
	lw	a0, -20(s0)
	call	print_int
	lw	a0, -20(s0)
	j	.END_main
.END_main:
	ld	ra, 56(sp)
	ld	s0, 48(sp)
	addi	sp, sp, 64
	jr	ra
