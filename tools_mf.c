#include "monty.h"

/**
 * open_mfile - opens a file
 * @filename: the file namepath
 * Return: void
 */

void open_mfile(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (filename == NULL || file == NULL)
		handle_err(2, filename);

	readfile(file);
	fclose(file);
}

/**
 * read_f - reads a file
 * @file: pointer to file descriptor
 * Return: void
 */

void read_f(FILE *file)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, file) != -1; line_num++)
	{
		format = parse_mline(buffer, line_num, format);
	}

	free(buffer);
}

/**
 * parse_mline - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_mline(char *buffer, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		handle_err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);

	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_op(opcode, value, line_num, format);
	return (format);
}

/**
 * find_op - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void find_op(char *opcode, char *value, int line_num, int format)
{
	int i, flag;

	Instruction instructionList[] = {
		{"push", push_to_stack},
		{"pall", printstack},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; instruction_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instruction_list[i].opcode) == 0)
		{
			execute_op(instruction_list[i].func, opcode, value, line_num, format);
			flag = 0;
		}
	}

	if (flag == 1)
		handle_err(3, line_num, opcode);
}

void execute_op(op_func operation, char *opcode,
		char *value, int lin_enum, int format
