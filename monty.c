#include "monty.h"

char *num;

/**
 * op_push - 'Push a number to the stack
 * @stack: Is the stack of numbers.
 * @line: Is the line of the operation.
 */

void op_push(stack_t **stack, unsigned int line)
{
	stack_t *add, *aux;
	char *flag = "listo";
	int i = 0;

	if (num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (isdigit(num[i]) == 0 && num[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	add = malloc(sizeof(stack_t));
	if (add == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	add->n = atoi(num);
	num = flag;
	add->next = NULL;
	if (*stack == NULL)
	{
		add->prev = NULL;
		*stack = add;
	}
	else
	{
		aux = *stack;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = add;
		add->prev = aux;
	}
}

/**
 * op_pall - 'Prints the stack in LIFO.'
 * @stack: Is the stack of numbers.
 * @line: Is the line of the operation.
 */

void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *aux = *stack;

	if (aux != NULL)
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		while (aux != NULL)
		{
			printf("%d\n", aux->n);
			if (aux->prev != NULL)
			{
				aux = aux->prev;
			}
			else
			{
				break;
			}
		}
	}
}

/**
 * get_opcode - 'Selects the correct function to perform the operation asked.'
 * @op: Is the operator passed as argument to the program.
 * Return: A pointer to the punction the corresponds to the operator given.
 */

void (*get_opcode(char *op))(stack_t **, unsigned int)
{
	instruction_t inst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"nop", op_nop},
		{"pint", op_pint},
		{"pop", op_pop},
		{NULL, NULL}};
	int i = 0;

	while (inst[i].opcode != NULL && strcmp(op, inst[i].opcode))
		i++;
	if (inst[i].opcode == NULL)
	{
		fprintf(stderr, "L2: unknown instruction %s\n", op);
		exit(EXIT_FAILURE);
	}
	return (*inst[i].f);
}

/**
 * main - 'Read a file and make an operation.'
 * @argc: Is the number of arguments.
 * @argv: The arguments.
 * Return: 0 if success, else 1.
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	char *txt = NULL, *token = NULL, *tok = NULL;
	int tr = 0, line = 0;
	stack_t *stack = NULL, *del_stack = NULL;

	if (argv[1] == NULL)
		return (EXIT_FAILURE);
	tr = open(argv[1], O_RDONLY);
	txt = malloc(sizeof(char) * 1024);
	if (txt == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read(tr, txt, 1024);
	token = strtok(txt, " \n");
	while (token != NULL)
	{
		tok = token;
		line++;
		token = strtok(NULL, " \n");
		num = token;
		get_opcode(tok)(&stack, line);
		if (!token)
			break;
		if (strcmp(num, "listo") == 0)
			token = strtok(NULL, " \n");
	}
	while (stack != NULL)
	{
		del_stack = stack;
		stack = stack->next;
		free(del_stack);
	}
	close(tr);
	free(txt);
	return (EXIT_SUCCESS);
}
