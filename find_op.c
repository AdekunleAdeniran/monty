#include "monty.h"

/**
 * find_op - looks for the operator
 * @head: pointer to stack
 * Return: 1 on success
 */

int find_op(stack_t **head)
{
	int i = 0;

	instruction_t f_ope[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL},
	};

	while (f_ope[i].opcode != NULL)
	{
		if (strcmp(gvars.cmd, f_ope[i].opcode) == 0)
		{
			f_ope[i].f(head, gvars.line_number);
			gvars.ret_val = 1;
			return (1);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", gvars.line_number, gvars.cmd);
	gvars.ret_val = -1;
	exit(EXIT_FAILURE);
}
