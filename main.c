#include "monty.h"

/**
 * main - runs monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: return -1 if failed, else 1
 */
int main(int argc, char **argv)
{
	FILE *fp;
	stack_t *head = NULL;
	size_t len = 0;

	gvars.lineptr = NULL;
	gvars.line_number = 0;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&gvars.lineptr, &len, fp)) != -1)
	{
		gvars.line_number++;
		tokenizer(gvars.lineptr);
		find_op(&head);
		if (gvars.ret_val == -1)
			break;
	}
	free(gvars.lineptr);
	free_l(head);
	fclose(fp);
	return (gvars.ret_val);
}
