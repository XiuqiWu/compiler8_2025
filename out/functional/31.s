	.text
	.globl	k
	.data
	.align	3
	.type	k, @object
	.size	k, 4
k:
	.zero	4
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -64
	sd	ra, 56(sp)
	sd	s0, 48(sp)
	addi	s0, sp, 64
	li	t4, 3389
	lui	t1, %hi(k)
	sw	t4, %lo(k)(t1)
	lui	t1, %hi(k)
	lw	t5, %lo(k)(t1)
	li	t6, 10000
	blt	t5, t6, .Label2
	j	.Label1
.Label2:
	lui	t1, %hi(k)
	lw	t5, %lo(k)(t1)
	li	t6, 1
	add t4, t5, t6
	sw	t4, -20(s0)
	lw	t4, -20(s0)
	lui	t1, %hi(k)
	sw	t4, %lo(k)(t1)
	li	t4, 112
	sw	t4, -24(s0)
.Label3:
	lw	t5, -24(s0)
	li	t6, 10
	bgt	t5, t6, .Label5
	j	.Label4
.Label5:
	lw	t5, -24(s0)
	li	t6, 88
	sub t4, t5, t6
	sw	t4, -28(s0)
	lw	t4, -28(s0)
	sw	t4, -24(s0)
	lw	t5, -24(s0)
	li	t6, 1000
	blt	t5, t6, .Label7
	j	.Label6
.Label7:
	li	t4, 9
	sw	t4, -32(s0)
	li	t4, 11
	sw	t4, -36(s0)
	li	t4, 10
	sw	t4, -32(s0)
	lw	t5, -24(s0)
	lw	t6, -32(s0)
	sub t4, t5, t6
	sw	t4, -40(s0)
	lw	t4, -40(s0)
	sw	t4, -24(s0)
	li	t4, 11
	sw	t4, -44(s0)
	lw	t5, -24(s0)
	lw	t6, -44(s0)
	add t4, t5, t6
	sw	t4, -48(s0)
	lw	t5, -48(s0)
	lw	t6, -36(s0)
	add t4, t5, t6
	sw	t4, -52(s0)
	lw	t4, -52(s0)
	sw	t4, -24(s0)
	j	.Label6
.Label6:
	j	.Label3
.Label4:
	lw	a0, -24(s0)
	call	print_int
	j	.Label1
.Label1:
	lui	t1, %hi(k)
	lw	a0, %lo(k)(t1)
	j	.END_main
.END_main:
	ld	ra, 56(sp)
	ld	s0, 48(sp)
	addi	sp, sp, 64
	jr	ra
