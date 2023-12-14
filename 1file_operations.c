#include "monty.h"

/**
 * file_reading - function to read a file
 *
 * @fild: file descriptors
 * Return: nothing
*/
void file_reading(FILE *fild)
{
	char *buff = NULL;
	int num, format = 0;
	size_t length = 0;

	for (num = 1; getline(&buff, &length, fild) != -1; num++)
	{
		format = arg_parse(buff, num, format);
	}
	free(buff);
}
/**
 * file_opening - function to open a file
 * @file: file name
 * Return: nothing
*/
void file_opening(char *file)
{
	FILE *fild = fopen(file, "r");

	if (fild == NULL || file == NULL)
		error1(2, file);
	file_reading(fild);
	fclose(fild);
}
