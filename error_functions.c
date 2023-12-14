#include "monty.h"
#include <stdio.h>

/**
 * error1 - function to print error msg
 *
 * @code: error code
 *
 * Return: nothing
*/
void error1(int code, ...)
{
	int num;
	char *opcode;
	va_list arg;

	va_start(arg, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
			break;
		case 3:
			opcode = va_arg(arg, char *);
			num = va_arg(arg, int);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * error2 - print error msg
 * @code: error code
 * Return: nothing
*/
void error2(int code, ...)
{
	va_list arg;
	int num;
	char *opcode;

	va_start(arg, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		case 2:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
			break;
		case 3:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arg, int));
			break;
		case 4:
			num = va_arg(arg, unsigned int);
			opcode = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, opcode);
			break;
		case 5:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}
