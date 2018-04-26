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
		fprintf(stdout, "Error: malloc failed\n");
		gvars.ret_val = -1;
		return;
	}
	if (gvars.value == NULL || check_val(gvars.value) == -1)
	{
		fprintf(stdout, "L%d: usage: push integer\n", gvars.line_number);
		free(new);
		gvars.ret_val = -1;
		return;
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
