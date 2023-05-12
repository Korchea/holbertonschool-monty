#include "monty.h"

char *num;

/**
 * Recive un string que contiene un numero,
 * tenemos que transformarlo de char * a int
 * y luego meterlo en el stack.
 */

void op_push(stack_t **stack, unsigned int line)
{
	stack_t *add, *aux;
	char *flag = "listo";

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
	/*while((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}*/
}

/**
 * Recibe un stack y lo imprime en LIFO,
 * con salto de linea luego de cada imprecion.
 */

void op_pall(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *aux = *stack;

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
	if (*inst[i].opcode != *op)
	{
		/*fprintf(stderr, "L%d: unknown instruction %s\n", line, op);*/
		exit(EXIT_FAILURE);
	}
	return (*inst[i].f);
}

/**
 * Lee el codigo que recive en el array de strings de 
 * nombre argv[1], lo recorre y busca el opcode,
 * cuando lo encuentra dependiendo del opcode busca
 * un entero hasta que encuentra un '$',
 * pasa a la siguiente linea.
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	char *txt, *token, *tok;
	int tr = 0, line = 1;
	stack_t *stack = NULL;

	if (argv[1] == NULL)
		return (0);
	tr = open(argv[1], O_RDONLY);
	if (tr == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
		/*if (strcmp(tok, "pall") == 0)
		{
			op_pall(&stack, 5);
		}*/
		token = strtok(NULL, " \n");
		num = token;
		get_opcode(tok)(&stack, line);
		if (!token)
			break;
		if (strcmp(num, "listo") == 0)
		{
			token = strtok(NULL, " \n");
			
		}
		line++;
	}
	close(tr);
	free(txt);
	return (0);
}

