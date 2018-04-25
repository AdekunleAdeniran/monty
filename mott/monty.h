#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
<<<<<<< HEAD:mott/monty.h
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

=======
#include <sys/stat.h>
#include <fcntl.h>

#define delim "\n\r "
>>>>>>> 5b5644ac8d0f43988061938018a9ead25018de69:monty.h

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

<<<<<<< HEAD:mott/monty.h
void op_push(stack_t **stack, unsigned int line_number);

void op_pall(stack_t **stack, unsigned int line_number);

void op_pint(stack_t **stack, unsigned int line_number);

void op_pop(stack_t **stack, unsigned int line_number);

void op_swap(stack_t **stack, unsigned int line_number);

void op_add(stack_t **stack, unsigned int line_number);

void op_add(stack_t **stack, unsigned int line_number);
=======
typedef struct variables
{
	char *lineptr;
	char **tokens;
	int *liner_len;
} vars;

int check_delim(char c);
int tok_num(char *string);
char **tokenizer(char *string);
>>>>>>> 5b5644ac8d0f43988061938018a9ead25018de69:monty.h

#endif
