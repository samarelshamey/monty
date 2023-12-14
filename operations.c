#include "monty.h"

/**
 * node_add - add node
 * @stk: pointer to top of stack
 * @num: line number
 * Return: nothing
*/
void node_add(stack_t **stk, unsigned int num)
{
	int summ;

	if (*stk == NULL || stk == NULL || (*stk)->next == NULL)
		error2(4, num, "add");
	(*stk) = (*stk)->next;
	summ = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = summ;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * node_sub - sub operation
 * @stk: pointer to top of stack
 * @num: line number
 * Return: nothing
*/
void node_sub(stack_t **stk, unsigned int num)
{
	int result;

	if (*stk == NULL || stk == NULL || (*stk)->next == NULL)
		error2(4, num, "add");
	(*stk) = (*stk)->next;
	result = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = result;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * node_div - division operation
 * @stk: pointer to top of stak
 * @num: line number
 * Return: nothing
*/
void node_div(stack_t **stk, unsigned int num)
{
	int div;

	if (*stk == NULL || stk == NULL || (*stk)->next == NULL)
		error2(4, num, "add");
	if ((*stk)->n == 0)
		error2(5, num);
	(*stk) = (*stk)->next;
	div = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = div;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * node_mul - multiplication operation
 * @stk: pointer to top of stak
 * @num: line number
 * Return: nothing
*/
void node_mul(stack_t **stk, unsigned int num)
{
	int mul;

	if (*stk == NULL || stk == NULL || (*stk)->next == NULL)
		error2(4, num, "mul");
	(*stk) = (*stk)->next;
	mul = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = mul;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * node_mod - module operation
 * @stk: pointer to top of stak
 * @num: line number
 * Return: nothing
*/
void node_mod(stack_t **stk, unsigned int num)
{
	int mod;

	if (*stk == NULL || stk == NULL || (*stk)->next == NULL)
		error2(4, num, "mod");
	if ((*stk)->n == 0)
		error2(5, num);
	(*stk) = (*stk)->next;
	mod = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = mod;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
