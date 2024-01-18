#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>



/**
 * struct stacknode - doubly linked list of a stack or queue
 * @data: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stacknode
{
	int data;
	struct stacknode *prev;
	struct stacknode *next;
} stacknode;








/**
 * struct instruction - opcode and function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction
{
	char *opcode;
	void (*func)(stacknode**, unsigned int);
} instruction;

extern stacknode *stackhead;

typedef void (*operationfunc)(stacknode **, unsigned int);

void open_mfile(char *filename);
int parse_mline(char *buffer, int line_num, int format);
void read_f(FILE *file);
int getchr_count(FILE *file);
void find_op(char *opcode, char *arg, int line_num, int format);

stacknode *create_stack_node(int data);
void freestacknodes(void);
void printstack(stacknode **stack, unsigned int line_num);
void push_to_stack(stacknode **stack, unsigned int line_num);
void enqueue(stacknode **stack, unsigned int line_num);

void execute_op(op_func operation, char *opcode, char *arg,
		int line_num, int format);

void handle_err(int errorcode, ...);
void extra_err(int errorcode, ...);
void str_err(int errorcode, ...);

#endif
