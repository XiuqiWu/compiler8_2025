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
	li	t4, 8
	sw	t4, -24(s0)
	li	t4, 12
	sw	t4, -28(s0)
	lw	t5, -24(s0)
	lw	t6, -28(s0)
	add t4, t5, t6
	sw	t4, -32(s0)
	lw	t4, -32(s0)
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	j	.END_main
	li	t4, 9
	sw	t4, -36(s0)
	lw	t5, -20(s0)
	lw	t6, -36(s0)
	mul t4, t5, t6
	sw	t4, -40(s0)
	lw	t4, -40(s0)
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	j	.END_main
	li	t4, 4
	sw	t4, -44(s0)
	lw	t5, -44(s0)
	lw	t6, -24(s0)
	sub t4, t5, t6
	sw	t4, -48(s0)
	lw	t5, -48(s0)
	lw	t6, -28(s0)
	mul t4, t5, t6
	sw	t4, -52(s0)
	lw	t4, -52(s0)
	sw	t4, -20(s0)
	lw	a0, -20(s0)
	j	.END_main
	lw	a0, -20(s0)
	j	.END_main
.END_main:
	ld	ra, 56(sp)
	ld	s0, 48(sp)
	addi	sp, sp, 64
	jr	ra
