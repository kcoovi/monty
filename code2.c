#include "monty.h"
/**
 * add_func - add
 * @stack: stack
 * @line_number: line number
 */
void add_func(stack_t **stack, unsigned int line_number)
{
int count = 0;
stack_t *current = *stack;

while (current)
{
current = current->next;
count++;
}

if (count < 2)

dprintf(2, "L%u: can't add\n", line_number);
free_global_data();
exit(EXIT_FAILURE);
}

current = (*stack)->next;
current->n += (*stack)->n;
pop_func(stack, line_number);
}
/**
 * nop_func - nop
 * @stack: stack
 * @line_number: line number
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
