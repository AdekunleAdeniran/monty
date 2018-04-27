#include "monty.h"

/**
 * op_rotl - rotates the stack to the top
 * The top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @stack: pointer to porint
 * @line_number: line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	int len = 0;
	stack_t *front, *end;

	len = list_len(stack);
	if (len < 2)
		return;
	end = *stack;
	while (end->next)
		end = end->next;

	front = *stack;
	*stack = front->next;
	(*stack)->prev = NULL;
	front->next = NULL;
	front->prev = end;
	end->next = front;
}
