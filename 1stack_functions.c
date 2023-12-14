#include "monty.h"

/**
 * stack_add - add node to stack
 * @node: node to be added
 * @len: line number
 * Return: nothing
*/
void stack_add(stack_t **node, __attribute__((unused))unsigned int len)
{
	stack_t *ptr;

	if (*node == NULL || node == NULL)
		exit(EXIT_FAILURE);
	if (h == NULL)
	{
		h = *node;
		return;
	}
	ptr = h;
	h = *node;
	h->next = ptr;
	ptr->prev = h;
}
/**
 * top_pop - pop top node of stack
 *
 * @stk: pointer to top of the stack
 * @num: line number
 * Return: nothing
*/
void top_pop(stack_t **stk, unsigned int num)
{
	stack_t *ptr;

	if (*stk == NULL || stk == NULL)
		error2(3, num);
	ptr = *stk;
	*stk = ptr->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(ptr);
}
/**
 * nop - function perfrom nothing
 * @stk: pointer
 * @num: line number
 * Return: nothing
*/
void nop(stack_t **stk, unsigned int num)
{
	(void)stk;
	(void)num;
}
