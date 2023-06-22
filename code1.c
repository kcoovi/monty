#include "monty.h"

/**
 * push_func - pushes an element to the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!global_data.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_global_data();
		exit(EXIT_FAILURE);
	}

	num = atoi(global_data.arg);

	if (global_data.lifo == 1)
		add_node_at_beginning(stack, data);
	else
		add_node_at_end(stack, data);
}

/**
 * pall_func - prints all values on the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * pint_func - prints the value at the top of the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_global_data();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_func - removes the top element of the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_global_data();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap_func - swaps the top two elements of the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_global_data();
		exit(EXIT_FAILURE);
	}

	top = (*stack)->next;
	(*stack)->prev = top;
	(*stack)->next = top->next;

	if (top->next != NULL)
	top->next->prev = *stack;

	top->prev = NULL;
	top->next = *stack;
	*stack = top;
}
