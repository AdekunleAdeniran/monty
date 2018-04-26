#include "monty.h"

/**
 * main - runs monty interpreter
 * @argc: argument count
 * @argv: argument vector
 */
int main(int argc, char **argv)
{
	FILE *fp;
	int fd;
	stack_t *head = NULL;

	gvars.lineptr = NULL;
	gvars.len = 0;
	gvars.line_number = 0;
	gvars.ret_val = 1;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((getline(&gvars.lineptr, &gvars.len, fp)) != -1)
	{
		gvars.line_number++;
		tokenizer(gvars.lineptr);
		find_op(&head);
		if (gvars.ret_val == -1)
			break;
	}
	free (gvars.lineptr);
	free_l(head);
	fclose(fp);
	return (gvars.ret_val);
}
