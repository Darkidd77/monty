#include "monty.h"



/**
 * mod_n - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mod_n(stacknode_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		extra_err(8, line_num, "mod");


	if ((*stack)->x == 0)
		extra_err(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->x % (*stack)->prev->x;
	(*stack)->x = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mul_n - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mul_n(stacknode_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extra_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->x * (*stack)->prev->x;
	(*stack)->x = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
