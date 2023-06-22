#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * node - node
 * @stack: stack
 * @n: n
*/
void node(stack_t **stack, int n)
{

	stack_t *new_node, *a;

	a = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (a)
	a->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*stack = new_node;
}
