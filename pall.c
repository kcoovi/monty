#include "monty.h"
#include <stdio.h>
/**
 * mypall - pall
 * @stack: stack
 * @line_number: line number
 */
void mypall(stack_t **stack, unsigned int line_number)
{
(void)line_number;
stack_t *current;

current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
