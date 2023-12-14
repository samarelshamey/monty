#include "monty.h"

/**
 * arg_parse - separate arguments
 *
 * @buff: buffer
 * @num: line number
 * @form: format
 * Return: integer
*/
int arg_parse(char *buff, int num, int form)
{
	const char *deli = "\n ";
	char *op, *v;

	if (buff == NULL)
		error1(4);
	op = strtok(buff, deli);
	if (op == NULL)
		return (form);
	v = strtok(NULL, deli);
	if (strcmp(op, "queue") == 0)
		return (1);
	if (strcmp(op, "stack") == 0)
		return (0);
	function_find(op, v, num, form);
	return (form);
}
