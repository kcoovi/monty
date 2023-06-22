#include "monty.h"
/**
 * add_node_at_end - node
 * @head: head
 * @data: data
 * Return: return
 */
stack_t *add_node_at_end(stack_t **head, const int data)
{
stack_t *new_node, *temp;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(stack_t));

if (!new_node)
{
dprintf(2, "Error\n");
free_vglo();
exit(EXIT_FAILURE);
}

new_node->n = data;

if (*head == NULL)
{
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
return (*head);
}

temp = *head;

while (temp->next != NULL)
temp = temp->next;

new_node->next = temp->next;
new_node->prev = temp;
temp->next = new_node;

return (new_node);
}

/**
 * add_node_at_beginning - node
 * @head: head
 * @data: data
 * Return: return
 */
stack_t *add_node_at_beginning(stack_t **head, const int data)
{
stack_t *new_node;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(stack_t));

if (!new_node)
{
dprintf(2, "Error\n");
free_global_data();
exit(EXIT_FAILURE);
}

new_node->n = data;

if (*head == NULL)
{
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
return (*head);
}

(*head)->prev = new_node;
new_node->next = (*head);
new_node->prev = NULL;
*head = new_node;

return (*head);
}
/**
 * free_doubly_linked_list - node
 * @head: head
 */
void free_doubly_linked_list(stack_t *head)
{
stack_t *temp;

while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}
