#ifndef __monty_h__
#define __monty_h__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
void op_push(stack_t **stack, unsigned int line);
void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line);
void (*get_opcode(char *op))(stack_t **, unsigned int);
void op_pop(stack_t **stack, unsigned int line);
void op_pint(stack_t **stack, unsigned int line);
void op_nop(stack_t **stack, unsigned int line);
void op_swap(stack_t **stack, unsigned int line);
void op_add(stack_t **stack, unsigned int line);
extern char *num;

#endif
