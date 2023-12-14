#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *h;
typedef void (*opcode_function)(stack_t **stck, unsigned int num);

void file_opening(char *file);
int arg_parse(char *buff, int num, int form);
void file_reading(FILE *fild);
void error1(int code, ...);
void error2(int code, ...);
stack_t *node_cr(int n);
void nodes_free(void);
void stack_printing(stack_t **stk, unsigned int num);
void stack_add(stack_t **node, __attribute__((unused))unsigned int len);
void queue_add(stack_t **, unsigned int);
void top_printing(stack_t **stk, unsigned int num);
void top_pop(stack_t **stk, unsigned int num);
void nop(stack_t **stk, unsigned int num);
void node_swaping(stack_t **stk, unsigned int num);
void node_add(stack_t **stk, unsigned int num);
void node_mod(stack_t **stk, unsigned int num);
void node_mul(stack_t **stk, unsigned int num);
void node_div(stack_t **stk, unsigned int num);
void node_sub(stack_t **stk, unsigned int num);
void function_calling(opcode_function f, char *op, char *value,
		int len, int format);
void function_find(char *op, char *v, int len, int format);
#endif
