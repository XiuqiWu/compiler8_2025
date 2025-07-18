	.text
	.globl	a
	.data
	.align	3
	.type	a, @object
	.size	a, 4
a:
	.word	2
	.text
	.globl	b
	.data
	.align	3
	.type	b, @object
	.size	b, 4
b:
	.word	3
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)
	addi	s0, sp, 32
	li	t4, 4
	sw	t4, -20(s0)
	lw	t5, -20(s0)
	lui	t1, %hi(b)
	lw	t6, %lo(b)(t1)
	add t4, t5, t6
	sw	t4, -24(s0)
	lw	a0, -24(s0)
	j	.END_main
.END_main:
	ld	ra, 24(sp)
	ld	s0, 16(sp)
	addi	sp, sp, 32
	jr	ra
