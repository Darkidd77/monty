#include "monty.h"
i

/**
 * sub_n - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void sub_n(stacknode_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		extra_err(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->x - (*stack)->prev->x;
	(*stack)->x = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_n - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_n(stacknode_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extra_err(8, line_num, "div");

	if ((*stack)->x == 0)
		extra_err(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->x / (*stack)->prev->x;
	(*stack)->x = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



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


/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_n(stacknode_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extra_err(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->x + (*stack)->prev->x;
	(*stack)->x = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
