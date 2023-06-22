#include "monty.h"
/**
 * mypstr - pstr
 * @doubly: head
 * @cline: line
 */
void mypstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
