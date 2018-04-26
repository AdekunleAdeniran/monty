#include "monty.h"
/**
 * op_add - function to add top two elements of a stack
 * @stack: double pointer of stack_t type to head of stack
 * @line_number: unsigned int type
 * Return: stack with new sum and removed node
 *
 */
void op_add(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't add, stack too short", gvars.line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->next == NULL)
	{
		printf("L%d: can't add, stack too short", gvars.line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}