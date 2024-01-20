#include "monty.h"



/**
 * swap_n - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void swap_n(stacknode_t **stack, unsigned int line_num)
{
	stacknode_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extra_err(8, line_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}




/**
 * no_op - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void no_op(stacknode_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
