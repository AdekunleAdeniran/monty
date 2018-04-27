#include "monty.h"

/**
 * op_add - function to add top two elements of a stack
 * @stack: double pointer of stack_t type to head of stack
 * @line_number: unsigned int type
 * Return: stack with new sum and removed node
 *
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	if (!*stack || !(*stack)->next)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		free_l(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	
	temp->n += (*stack)->n;
	free(*stack);
	*stack = temp;
}
