#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pint - pint
 * @stack: stack
 * @line_number: line_number
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
