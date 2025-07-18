	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -80
	sd	ra, 72(sp)
	sd	s0, 64(sp)
	addi	s0, sp, 80
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
	li	t4, 0
	sw	t4, -28(s0)
	li	t4, 0
	sw	t4, -32(s0)
	li	t4, 0
	sw	t4, -36(s0)
	li	t4, 5
	sw	t4, -20(s0)
	li	t4, 5
	sw	t4, -24(s0)
	li	t4, 1
	sw	t4, -28(s0)
	li	t5, 2
	neg t4, t5
	sw	t4, -40(s0)
	lw	t4, -40(s0)
	sw	t4, -32(s0)
	li	t4, 2
	sw	t4, -36(s0)
	lw	t5, -32(s0)
	li	t6, 1
	mul t4, t5, t6
	sw	t4, -44(s0)
	lw	t5, -44(s0)
	li	t6, 2
	div t4, t5, t6
	sw	t4, -48(s0)
	lw	t5, -48(s0)
	li	t6, 0
	blt	t5, t6, .Label2
	j	.Label3
.Label3:
	lw	t5, -20(s0)
	lw	t6, -24(s0)
	sub t4, t5, t6
	sw	t4, -52(s0)
	lw	t5, -52(s0)
	li	t6, 0
	beq	t5, t6, .Label1
	j	.Label4
.Label4:
	lw	t5, -28(s0)
	li	t6, 3
	add t4, t5, t6
	sw	t4, -56(s0)
	lw	t5, -56(s0)
	li	t6, 2
	rem t4, t5, t6
	sw	t4, -60(s0)
	lw	t5, -60(s0)
	li	t6, 0
	beq	t5, t6, .Label1
	j	.Label2
.Label2:
	lw	a0, -36(s0)
	call	print_int
	j	.Label1
.Label1:
	lw	t5, -32(s0)
	li	t6, 2
	rem t4, t5, t6
	sw	t4, -64(s0)
	lw	t5, -64(s0)
	li	t6, 67
	add t4, t5, t6
	sw	t4, -68(s0)
	lw	t5, -68(s0)
	li	t6, 0
	blt	t5, t6, .Label6
	j	.Label7
.Label7:
	lw	t5, -20(s0)
	lw	t6, -24(s0)
	sub t4, t5, t6
	sw	t4, -72(s0)
	lw	t5, -72(s0)
	li	t6, 0
	beq	t5, t6, .Label5
	j	.Label8
.Label8:
	lw	t5, -28(s0)
	li	t6, 2
	add t4, t5, t6
	sw	t4, -76(s0)
	lw	t5, -76(s0)
	li	t6, 2
	rem t4, t5, t6
	sw	t4, -80(s0)
	lw	t5, -80(s0)
	li	t6, 0
	beq	t5, t6, .Label5
	j	.Label6
.Label6:
	li	t4, 4
	sw	t4, -36(s0)
	lw	a0, -36(s0)
	call	print_int
	j	.Label5
.Label5:
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 72(sp)
	ld	s0, 64(sp)
	addi	sp, sp, 80
	jr	ra
