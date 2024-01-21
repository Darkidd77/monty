#include "monty.h"

/**
 * parse_mline - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @line_num: line number
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_mline(char *buf, int line_num, int form)
{
	char *ocode, *value;
	const char *delim = "\n ";

	if (buf == NULL)
		error(4);

	ocode = strtok(buf, delim);
	if (ocode == NULL)
		return (form);

	value = strtok(NULL, delim);

	if (strcmp(ocode, "stack") == 0)
		return (0);
	if (strcmp(ocode, "queue") == 0)
		return (1);

	find_fun1(ocode, value, line_num, form);
	return (form);
}


/**
 * find_fun1 - find the appropriate function for the opcode
 * @ocode: opcode
 * @value: argument of opcode
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_fun1(char *ocode, char *value, int ln, int form)
{
	int i;
	int flag;

	inst_t func_list[] = {
		{"push", push_stack},
		{"pall", print_s},
		{"pint", print_up},
		{"pop", pop_up},
		{"nop", no_op},
		{"swap", swap_n},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotm},
		{"rotr", rote},
		{"add", add_n},
		{"sub", sub_n},
		{"div", div_n},
		{"mul", mul_n},
		{"mod", mod_n},
		{NULL, NULL}
	};

	if (ocode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].ocode != NULL; i++)
	{
		if (strcmp(ocode, func_list[i].ocode) == 0)
		{
			call_func1(func_list[i].fun1, ocode, value, ln, form);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, ln, ocode);
}


/**
 * open_mfile - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void open_mfile(char *f_name)
{
	FILE *file = fopen(f_name, "r");

	if (f_name == NULL || file == NULL)
		error(2, f_name);

	read_mfile(file);
	fclose(file);
}

/**
 * read_mfile - reads a file
 * @file: pointer to file descriptor
 * Return: void
 */

void read_mfile(FILE *file)
{
	int line_num, form = 0;
	char *buf = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buf, &len, file) != -1; line_num++)
	{
		form = parse_mline(buf, line_num, form);
	}

	free(buf);
}

/**
 * call_func1 - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @form: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func1(op_func func, char *op, char *val, int ln, int form)
{
	stacknode_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (form == 0)
			func(&node, ln);
		if (form == 1)
			push_que(&node, ln);
	}
	else
		func(&head, ln);
}
