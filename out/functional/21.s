	.text
	.align	1
	.globl	whileIf
	.type	whileIf, @function
whileIf:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
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
	li	t6, 5
	beq	t5, t6, .Label5
	j	.Label6
.Label5:
	li	t4, 25
	sw	t4, -24(s0)
	j	.Label4
.Label6:
	lw	t5, -20(s0)
	li	t6, 10
	beq	t5, t6, .Label7
	j	.Label8
.Label7:
	li	t4, 42
	sw	t4, -24(s0)
	j	.Label4
.Label8:
	lw	t5, -20(s0)
	li	t6, 2
	mul t4, t5, t6
	sw	t4, -28(s0)
	lw	t4, -28(s0)
	sw	t4, -24(s0)
	j	.Label4
.Label4:
	lw	t5, -20(s0)
	li	t6, 1
	add t4, t5, t6
	sw	t4, -32(s0)
	lw	t4, -32(s0)
	sw	t4, -20(s0)
	j	.Label1
.Label2:
	lw	a0, -24(s0)
	j	.END_whileIf
.END_whileIf:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
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
	call	whileIf
	sw	a0, -20(s0)
	lw	a0, -20(s0)
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
