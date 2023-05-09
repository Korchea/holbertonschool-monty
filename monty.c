#include "monty.h"

/**
 * Lee el codigo que recive en el array de strings de 
 * nombre argv[1], lo recorre y busca el opcode,
 * cuando lo encuentra dependiendo del opcode busca
 * un entero hasta que encuentra un '$',
 * pasa a la siguiente linea.
 */

int main(int argc, char *argv[])
{

}

/**
 * Llama a la funcion correspondiente.
 */

int get_opcode(stack_t stack, char *opcode, char *n)
{

}

/**
 * Recive un string que contiene un numero,
 * tenemos que transformarlo de char * a int
 * y luego meterlo en el stack.
 */

void push(char *num, stack_t stack)
{

}

/**
 * Recibe un stack y lo imprime en LIFO,
 * con salto de linea luego de cada imprecion.
 */
void pall(stack_t stack)
{
    while (stack.n != NULL)
    {
        printf("%d\n", stack.n);
        if (stack.next != NULL)
        {
            //stack = stack.next;
            free(stack.prev);
        }
        else
            break;
    }
    while (stack.n != NULL)
    {
        printf("%d\n", stack.n);
        if (stack.prev != NULL)
        {
            //stack = stack.prev;
            free(stack.next);
        }
        else
            break;
    }
    free(stack);
    /*DEPENDE DE COMO ESTE HECHO EL STACK ES UNO U OTRO WHILE.*/
}

