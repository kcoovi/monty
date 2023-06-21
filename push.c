#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * push - push
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
char *value = strtok(NULL, " \n\t\r");

if (value == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

int num = atoi(value);
stack_t *new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = num;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}