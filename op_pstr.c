#include "monty.h"

/**
 * check_ascii - checks if int in range of ascii value except 0
 * @num: takes an int
 * Return: 1 if in range else 0
 */
int check_ascii(int num)
{
	if (num >= 1 && num <= 127)
		return (1);
	else
		return (0);
}

/**
 * op_pstr - function to print all elements in a stack
 * @stack: double pointer of type stack_t to head of doubly linked list
 * @line_number: unsigned int for line number(void in this function)
 * Return: no return, print list
 */
void op_pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;
	int num, len;

	if (*stack == NULL || stack == NULL)
	{
		putchar('\n');
		return;
	}
	len = list_len(stack);
	current = *stack;
	if (len == 1 && check_ascii(current->n) == 1)
	{
		num = current->n;
		putchar(num);
		putchar('\n');
		return;
	}
	if (check_ascii(current->n) != 1)
		return;
	while (current != NULL)
	{
		num = current->n;
		if (check_ascii(num) == 1)
		{
			putchar(num);
			current = current->next;
		}
		else
		{
			num = current->prev->n;
			break;
		}
	}
	if (check_ascii(num) == 1)
		putchar('\n');
}
