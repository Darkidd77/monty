#include "monty.h"


/**
 * print_s - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of  the opcode.
 */
void print_s(stack_t **stack, unsigned int line_num)
{
	stacknode_t *tmp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_up - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void pop_up(stacknode_t **stack, unsigned int line_num)
{
	stacknode_t *tmp;

	if (stack == NULL || *stack == NULL)
		extra_err(7, line_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_up - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void print_up(stacknode_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		extra_err(6, line_num);
	printf("%d\n", (*stack)->n);
}

/**
 * push_stack - Adds a node to the stack.
 * @new_n: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void push_stack(stack_t **new_n, __attribute__((unused))unsigned int ln)
{
	stacknode_t *tmp;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
