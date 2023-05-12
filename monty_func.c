#include "monty.h"

/**
 *op_nop - function that doesn’t do anything
 *@stack: pointer to top of the stack
 *@num: number of line
 */

void op_nop(stack_t **stack, unsigned int num)
{
	(void)stack;
	(void)num;
}

/**
 *op_pint - prints the value at the top of the stack
 *@stack: pointer to top of the stack
 *@num: number of line
 */

void op_pint(stack_t **stack, unsigned int num)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 *op_pop - removes the top element of the stack
 *@stack: pointer to the head of the stack
 *@num: number of line
 */

void op_pop(stack_t **stack, unsigned int num)
{
	stack_t *aux = NULL;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	free(*stack);
	(*stack) = aux;
	(*stack)->prev;
}
