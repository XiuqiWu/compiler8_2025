	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
	li	t4, 0
	sw	t4, -28(s0)
	li	t4, 1
	sw	t4, -20(s0)
	li	t4, 2
	sw	t4, -24(s0)
	li	t4, 3
	sw	t4, -28(s0)
	lw	t5, -24(s0)
	lw	t6, -28(s0)
	add t4, t5, t6
	sw	t4, -32(s0)
	lw	a0, -32(s0)
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
