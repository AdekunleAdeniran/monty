#include "monty.h"

/**
 * op_push - push value to stack
 * @stack: pointer to stack
 * @line_number: unused
 */
void op_push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (check_val(gvars.value) == -1 || gvars.value == NULL)
	{
		printf("L%d: usage: push integer\n", gvars.line_number);
		gvars.ret_val = -1;
		exit(EXIT_FAILURE);
	}

	gvars.int_val = atoi(gvars.value);
	new->n = gvars.int_val;

	if (*stack != NULL)
	{
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
}
