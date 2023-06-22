#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - swap
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = (*stack)->next;
(*stack)->prev = tmp;
(*stack)->next = tmp->next;

if (tmp->next != NULL)
tmp->next->prev = *stack;

tmp->prev = NULL;
tmp->next = *stack;
*stack = tmp;
}
