#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>



/**
 * struct inst_s - opcode & function
 * @ocode: the opcode
 * @fun1: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct inst_s
{
	char *ocode;
	void (*fun1)(stacknode_t **stack, unsigned int line_num);
} inst_t;

extern stacknode_t *head;
typedef void (*op_func)(stacknode_t **, unsigned int);



/**
 * struct stacknode_s - doubly linked list of a stack or queue
 * @x: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stacknode_s
{
	int x;
	struct stacknode_s *prev;
	struct stacknode_s *next;
} stacknode_t;



void print_up(stacknode_t **, unsigned int);
void pop_up(stacknode_t **, unsigned int);
void nop(stacknode_t **, unsigned int);
void swap_n(stacknode_t **, unsigned int);

void pchar(stacknode_t **, unsigned int);
void print_str(stacknode_t **, unsigned int);
void rotm(stacknode_t **, unsigned int);

void error(int ecode, ...);
void extra_err(int ecode, ...);
void str_err(int ecode, ...);

void rote(stacknode_t **, unsigned int);



void open_mfile(char *f_name);
int parse_mline(char *buf, int line_num, int form);
void read_mfile(FILE *);
int len_chr(FILE *);
void find_fun1(char *, char *, int, int);

stacknode_t *create_node(int n);
void free_n(void);
void print_s(stack_t **, unsigned int);
void push_stack(stack_t **, unsigned int);
void push_que(stack_t **, unsigned int);

void call_func1(op_func, char *, char *, int, int);


#endif
