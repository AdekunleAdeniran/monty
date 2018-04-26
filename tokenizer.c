#include "monty.h"

/**
 * tokenizer - create tokens for command and value
 * @str: takes a string
 * Return: 1 on success
 */
int tokenizer(char *str)
{
	gvars.cmd = strtok(str, delim);
	gvars.value = strtok(NULL, delim);
	if (gvars.value != NULL)
		gvars.int_val = atoi(gvars.value);
	return (1);
}
