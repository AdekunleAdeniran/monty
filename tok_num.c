#include "monty.h"

/**
 * tok_num - calculate how many tokens in a string
 * @string: takes a string
 * Return: Number of tokens
 */
int tok_num(char *string)
{
	int len = 0, i = 0;

	while (string[i])
	{
		if (check_delim(string[i]) == 1)
			i++;
		else if (check_delim(string[i]) == 0)
		{
			len++;
			while (check_delim(string[i]) != 1)
				i++;
			i++;
		}
	}
	return (len);
}
