#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pop - pop
 * @stack: stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

stack_t *temp = *stack;
*stack = (*stack)->next;

if (*stack != NULL)
(*stack)->prev = NULL;

free(temp);
}
