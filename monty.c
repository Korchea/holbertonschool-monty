#include "monty.h"

/**
 * Lee el codigo que recive en el array de strings de 
 * nombre argv[1], lo recorre y busca el opcode,
 * cuando lo encuentra dependiendo del opcode busca
 * un entero hasta que encuentra un '$',
 * pasa a la siguiente linea.
 */

int main(__attribute__((unused))int argc, char *argv[])
{
	char *txt, *token;
	ssize_t ps = 0;
	int tr = 0;
    stack_t *stack;

	if (argv[1] == NULL)
		return (0);
	tr = open(argv[1], O_RDONLY);
	if (tr == -1)
		return (0);
	txt = malloc(sizeof(char) * 1024);
	if (txt == NULL)
		return (0);
	read(tr, txt, 1024);
    token = strtok(txt, "\n");
    while (token != NULL)
		{
            get_opcode(token)(&stack, 5);
			token = strtok(NULL, "\n");
		}
	//ps = write(STDOUT_FILENO, txt, rl);

	close(tr);
	free(txt);
	return (ps);
}

/**
 * get_opcode - 'Selects the correct function to perform the operation asked.'
 * @op: Is the operator passed as argument to the program.
 * Return: A pointer to the punction the corresponds to the operator given.
 */

int (*get_opcode(char *op))(stack_t **, unsigned int)
{
    instruction_t inst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};
	int i = 0;

	while (inst[i].opcode != NULL && *inst[i].opcode != *op)
		i++;
	if (*inst[i].opcode != *op)
		return (NULL);
	return (*inst[i].f);
}

/**
 * Recive un string que contiene un numero,
 * tenemos que transformarlo de char * a int
 * y luego meterlo en el stack.
 */

stack_t *op_push(stack_t **stack, char *opcode, int line)
{
	stack_t *add, *aux;
    char *token, **tok;

    while (token != NULL)
		{
            *tok = token;
			token = strtok(NULL, "\n");
		}
	add = malloc(sizeof(stack_t));
	if (add == NULL)
	{
		printf("L<%d>: usage: push integer", line);
		return (EXIT_FAILURE);
	}
	add->n = atoi(*tok);
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
			aux = aux->next;
		aux->next = add;
		add->prev = aux;
	}
	return (add);
}

/**
 * Recibe un stack y lo imprime en LIFO,
 * con salto de linea luego de cada imprecion.
 */
stack_t *op_pall(stack_t **stack, __attribute__((unused))char *opcode, __attribute__((unused))int line)
{
    while ((*stack)->n != NULL)
    {
        printf("%d\n", (*stack)->n);
        if ((*stack)->next != NULL)
        {
            //stack = stack.next;
            free((*stack)->prev);
        }
        else
            break;
    }
    while ((*stack)->n != NULL)
    {
        printf("%d\n", (*stack)->n);
        if ((*stack)->prev != NULL)
        {
            //stack = stack.prev;
            free((*stack)->next);
        }
        else
            break;
    }
    free((*stack));
    /*DEPENDE DE COMO ESTE HECHO EL STACK ES UNO U OTRO WHILE.*/
}
