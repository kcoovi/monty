#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * mypush - push
 * @stack: stack
 * @line_number: line number
 */

void mypush(stack_t **stack, unsigned int line_number)
{
char *value;
int num;
stack_t *new_node;

value = strtok(NULL, " \n\t\r");

if (value == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

num = atoi(value);
new_node = malloc(sizeof(stack_t));

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
