#include "monty.h"

/**
 * function_find - find function
 *
 * @op: opcode
 * @v: argument
 * @len: line number
 * @format: format
 * Return: nothing
*/
void function_find(char *op, char *v, int len, int format)
{
	int flag;
	int x;

	instruction_t fuction_list[] = {
		{"push", stack_add},
		{"pall", stack_printing},
		{"pint", top_printing},
		{"pop", top_pop},
		{"swap", node_swaping},
		{"add", node_add},
		{"nop",  nop},
		{"sub", node_sub},
		{"div", node_div},
		{"mul", node_mul},
		{"mod", node_mod},
		{NULL, NULL}
	};
	if (op[0] == '#')
		return;
	for (flag = 1, x = 0; fuction_list[x].opcode != NULL; x++)
	{
		if (strcmp(op, fuction_list[x].opcode) == 0)
		{
			function_calling(fuction_list[x].f, op, v, len, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error1(3, len, op);
}
/**
 * function_calling - call a function
 * @f: function
 * @op: opcode
 * @value: argument
 * @len: line number
 * @format: format
 * Return: nothing
*/

void function_calling(opcode_function f,
		char *op, char *value, int len, int format)
{
	int x;
	int flag;
	stack_t *node;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value[0] == '-' && value != NULL)
		{
			value += 1;
			flag = -1;
		}
		if (value == NULL)
			error2(1, len);
		for (x = 0; value[x] != '\0'; x++)
		{
			if (isdigit(value[x]) == 0)
				error2(1, len);
		}
		node = node_cr(atoi(value) * flag);
		if (format == 0)
			f(&node, len);
		if (format == 1)
			queue_add(&node, len);
	}
	else
		f(&h, len);
}
