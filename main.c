#include "monty.h"
stack_t *h = NULL;
/**
 * main - enrty point
 * @argc: argument count
 * @argv: arguments
 * Return: integer
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_opening(argv[1]);
	nodes_free();
	return (0);
}
