#include "monty.h"

/**
 * mypall - pall
 * @doubly: head
 * @cline: line
 */
void mypall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
	printf("%d\n", aux->n);
	aux = aux->next;
	}
}
