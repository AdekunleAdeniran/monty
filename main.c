#include "monty.h"

/**
 * main - runs monty interpreter
 * @argc: argument count
 * @argv: argument vector
 */
int main(int argc, char **argv)
{
	FILE *fp;
	int fd, read_file, line_number = 0;
	char *lineptr = NULL, **lines;
	ssize_t read;
	size_t len = 0;

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
	while ((getline(&lineptr, &len, fp)) != -1)
	{
		line_number++;
		lines = tokenizer(lineptr);
		printf("Line Number: %d\n", line_number);
		printf("token1: line[0] %s\n", lines[0]);
		printf("token2: line[1] %s\n", lines[1]);
	}

	free (lineptr);
}
