	.text
	.globl	arr
	.data
	.align	3
	.type	arr, @object
	.size	arr, 24
arr:
	.word	1
	.word	2
	.word	33
	.word	4
	.word	5
	.word	6
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -48
	sd	ra, 40(sp)
	sd	s0, 32(sp)
	addi	s0, sp, 48
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
.Label1:
	lw	t5, -20(s0)
	li	t6, 6
	blt	t5, t6, .Label3
	j	.Label2
.Label3:
	li	t5, 4
	lw	t6, -20(s0)
	mul t4, t5, t6
	sw	t4, -28(s0)
	lui	t5, %hi(arr)
	addi	t5, t5, %lo(arr)
	lw	t6, -28(s0)
	add	t5, t5, t6
	lw t4, 0(t5)
	sw	t4, -32(s0)
	lw	t5, -24(s0)
	lw	t6, -32(s0)
	add t4, t5, t6
	sw	t4, -36(s0)
	lw	t4, -36(s0)
	sw	t4, -24(s0)
	lw	t5, -20(s0)
	li	t6, 1
	add t4, t5, t6
	sw	t4, -40(s0)
	lw	t4, -40(s0)
	sw	t4, -20(s0)
	j	.Label1
.Label2:
	lw	a0, -24(s0)
	j	.END_main
.END_main:
	ld	ra, 40(sp)
	ld	s0, 32(sp)
	addi	sp, sp, 48
	jr	ra
