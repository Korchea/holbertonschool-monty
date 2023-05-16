#include "monty.h"

/**
 *op_nop - function that doesn’t do anything.
 *@stack: pointer to top of the stack.
 *@line: number of line.
 */

void op_nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 *op_pint - prints the value at the top of the stack.
 *@stack: pointer to top of the stack.
 *@line: number of line.
 */

void op_pint(stack_t **stack, unsigned int line)
{
	stack_t *aux = (*stack);

	if (!aux)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	printf("%d\n", aux->n);
}

/**
 *op_pop - removes the top element of the stack.
 *@stack: pointer to the head of the stack.
 *@line: number of line.
 */

void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *aux = (*stack);

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
	}
	(*stack) = (*stack)->prev;
	free((*stack)->next);
	(*stack) = aux;
}

/**
 *op_swap - 'Swaps the top two elements of the stack.'
 *@stack: Pointer to the head of the stack.
 *@line: Pumber of line.
 */

void op_swap(stack_t **stack, unsigned int line)
{
	stack_t *aux = (*stack);
	int swap, i = 0;

	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		i++;
	}
	if (i < 1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = swap;
	(*stack) = aux;
}

/**
 *op_add - 'Adds the top two elements of the stack.'
 *@stack: Pointer to the head of the stack.
 *@line: Pumber of line.
 */

void op_add(stack_t **stack, unsigned int line)
{
	stack_t *aux = (*stack);
	int sum, i = 0;

	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		i++;
	}
	if (i < 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	(*stack) = (*stack)->prev;
	free((*stack)->next);
	(*stack)->n += sum;
	(*stack)->next = NULL;
	(*stack) = aux;
}
