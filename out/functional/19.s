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
	sw	t4, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
	li	t4, 0
	sw	t4, -24(s0)
.Label1:
	lw	t5, -20(s0)
	li	t6, 100
	blt	t5, t6, .Label3
	j	.Label2
.Label3:
	lw	t5, -20(s0)
	li	t6, 50
	beq	t5, t6, .Label5
	j	.Label4
.Label5:
	j	.Label2
	j	.Label4
.Label4:
	lw	t5, -24(s0)
	lw	t6, -20(s0)
	add t4, t5, t6
	sw	t4, -28(s0)
	lw	t4, -28(s0)
	sw	t4, -24(s0)
	lw	t5, -20(s0)
	li	t6, 1
	add t4, t5, t6
	sw	t4, -32(s0)
	lw	t4, -32(s0)
	sw	t4, -20(s0)
	j	.Label1
.Label2:
	lw	t5, -24(s0)
	li	t6, 256
	rem t4, t5, t6
	sw	t4, -36(s0)
	lw	a0, -36(s0)
	j	.END_main
.END_main:
	ld	ra, 40(sp)
	ld	s0, 32(sp)
	addi	sp, sp, 48
	jr	ra
