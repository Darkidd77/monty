#include "monty.h"
stacknode_t *head = NULL;



/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_mfile(argv[1]);
	free_n();
	return (0);
}




/**
 * free_n - Frees nodes in the stack.
 */
void free_n(void)
{
	stacknode_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * push_que - Adds a node to the queue.
 * @new_n: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void push_queue(stacknode_t **new_n, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_n;
	(*new_n)->prev = tmp;

}



/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stacknode_t *create_node(int n)
{
	stacknode_t *node;

	node = malloc(sizeof(stacknode_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->x = x;
	return (node);
}
