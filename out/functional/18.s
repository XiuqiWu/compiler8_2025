	.text
	.align	1
	.globl	ifElseIf
	.type	ifElseIf, @function
ifElseIf:
	addi	sp, sp, -48
	sd	ra, 40(sp)
	sd	s0, 32(sp)
	addi	s0, sp, 48
	li	t4, 0
	sw	t4, -20(s0)
	li	t4, 5
	sw	t4, -20(s0)
	li	t4, 0
	sw	t4, -24(s0)
	li	t4, 10
	sw	t4, -24(s0)
	lw	t5, -20(s0)
	li	t6, 6
	beq	t5, t6, .Label2
	j	.Label4
.Label4:
	lw	t5, -24(s0)
	li	t6, 0xb
	beq	t5, t6, .Label2
	j	.Label3
.Label2:
	lw	a0, -20(s0)
	j	.END_ifElseIf
	j	.Label1
.Label3:
	lw	t5, -24(s0)
	li	t6, 10
	beq	t5, t6, .Label8
	j	.Label7
.Label8:
	lw	t5, -20(s0)
	li	t6, 1
	beq	t5, t6, .Label6
	j	.Label7
.Label6:
	li	t4, 25
	sw	t4, -20(s0)
	j	.Label5
.Label7:
	lw	t5, -24(s0)
	li	t6, 10
	beq	t5, t6, .Label11
	j	.Label10
.Label11:
	li	t5, 5
	neg t4, t5
	sw	t4, -28(s0)
	lw	t5, -20(s0)
	lw	t6, -28(s0)
	beq	t5, t6, .Label9
	j	.Label10
.Label9:
	lw	t5, -20(s0)
	li	t6, 15
	add t4, t5, t6
	sw	t4, -32(s0)
	lw	t4, -32(s0)
	sw	t4, -20(s0)
	j	.Label5
.Label10:
	lw	t5, -20(s0)
	neg t4, t5
	sw	t4, -36(s0)
	lw	t4, -36(s0)
	sw	t4, -20(s0)
	j	.Label5
.Label5:
	j	.Label1
.Label1:
	lw	a0, -20(s0)
	j	.END_ifElseIf
.END_ifElseIf:
	ld	ra, 40(sp)
	ld	s0, 32(sp)
	addi	sp, sp, 48
	jr	ra
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	call	ifElseIf
	sw	a0, -20(s0)
	lw	a0, -20(s0)
	call	print_int
	li	a0, 0
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
