#include "monty.h"

/**
 * node_cr - create a node
 * @num: data
 * Return: pointer to node
*/
stack_t *node_cr(int num)
{
	stack_t *n;

	n = malloc(sizeof(stack_t));
	if (n == NULL)
		error1(4);
	n->next = NULL;
	n->n = num;
	n->prev = NULL;
	return (n);
}
/**
 * nodes_free - free nodes
 * Return: nothing
*/
void nodes_free(void)
{
	stack_t *ptr;

	if (h == NULL)
		return;
	while (h != NULL)
	{
		ptr = h;
		h = h->next;
		free(ptr);
	}
}

/**
 * node_swaping - swap nodes
 * @stk: pointer to top of stack
 * @num: line number
 * Return: nothing
*/
void node_swaping(stack_t **stk, unsigned int num)
{
	stack_t *ptr;

	if (*stk == NULL || stk == NULL || (*stk)->next == NULL)
		error2(4, num);
	ptr = (*stk)->next;
	(*stk)->next = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = *stk;
	ptr->next = *stk;
	(*stk)->prev = ptr;
	ptr->prev = NULL;
	*stk = ptr;
}
