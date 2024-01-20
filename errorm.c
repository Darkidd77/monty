#include "monty.h"

/**
 * error - Prints error messages by their error code.
 * @ecode: The error codes are:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */

void error(int ecode, ...)
{
	va_list args;

	va_start(args, ecode);

	switch (ecode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n",
				va_arg(args, int), va_arg(args, char *));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}

	free_n();
	exit(EXIT_FAILURE);
}

/**
 * extra_err - handles errors.
 * @ecode: The error codes are:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */

void extra_err(int ecode, ...)
{
	va_list args;

	va_start(args, ecode);

	switch (ecode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't %s, stack too short\n",
				va_arg(args, int), va_arg(args, char *));
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
			break;
		default:
			break;
	}

	free_n();
	exit(EXIT_FAILURE);
}

/**
 * str_err - handles errors.
 * @ecode: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */

void str_err(int ecode, ...)
{
	va_list args;

	va_start(args, ecode);

	int line_n = va_arg(args, int);

	switch (ecode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}

	free_n();
	exit(EXIT_FAILURE);
}
