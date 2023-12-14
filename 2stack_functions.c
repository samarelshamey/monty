#include "monty.h"

/**
 * stack_printing - print stack
 *
 * @stk: pointer to the top of stack
 * @num: line number
 * Return: nothing
*/
void stack_printing(stack_t **stk, unsigned int num)
{
	stack_t *ptr;

	(void)num;
	if (stk == NULL)
		exit(EXIT_FAILURE);
	ptr = *stk;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * top_printing - print top
 * @stk: pointer to the top of stack
 * @num: line number
 * Return: nothing
*/
void top_printing(stack_t **stk, unsigned int num)
{
	if (*stk == NULL || stk == NULL)
		error2(2, num);
	printf("%d\n", (*stk)->n);
}
/**
 * queue_add - add node to queue
 * @node: node to be added
 * @len: line number
 * Return: nothing
*/
void queue_add(stack_t **node, __attribute__((unused))unsigned int len)
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
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = *node;
	(*node)->prev = ptr;
}
