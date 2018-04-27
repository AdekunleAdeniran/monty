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
	int i = 0, len = 0;
	stack_t *current, *back, *front, *front2nd;

	if (len < 1)
		return;

	while (current->next)
	{
		current = current->next;
	}
	current = *stack;
	front = *stack;
	len = list_len(stack);

	back = current;
	front2nd = front->next;
	front2nd->prev = NULL;
	front->prev = back;
	front->next = NULL;
	back->next = front;
	*stack = front2nd;
}
