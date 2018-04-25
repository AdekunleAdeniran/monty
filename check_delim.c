#include "monty.h"

/**
 * check_delim - checks if a char byte is one of the delimeters use for strtok
 * @string: takes a string
 * @Return: 1 if char is a delimeter, else 0
 */
int check_delim(char c)
{
	int i = 0;

	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		else
			i++;
	}
	return (0);
}
