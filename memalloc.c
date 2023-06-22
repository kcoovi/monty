#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * custom_calloc - allocate and initialize memory
 * @num_elements: number of elements
 * @element_size: size of each element
 * Return: pointer to allocated memory
 */
void *custom_calloc(unsigned int num_elements, unsigned int element_size)
{
void *ptr = NULL;
unsigned int total_size = num_elements * element_size;

if (num_elements == 0 || element_size == 0)
{
return (NULL);
}

ptr = malloc(total_size);
if (ptr == NULL)
{
return (NULL);
}

char *char_ptr = ptr;
for (unsigned int i = 0; i < total_size; i++)
{
char_ptr[i] = 0;
}

return (ptr);
}

/**
 * custom_realloc - reallocate memory with content copy
 * @ptr: pointer to reallocate
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * Return: pointer to reallocated memory
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
if (new_size == old_size)
return (ptr);

if (ptr == NULL)
{
void *new_ptr = malloc(new_size);
if (!new_ptr)
return (NULL);
return (new_ptr);
}

if (new_size == 0)
{
free(ptr);
return (NULL);
}

void *new_ptr = malloc(new_size);
if (!new_ptr)
return (NULL);

char *char_ptr = ptr;
char *new_char_ptr = new_ptr;

unsigned int copy_size = (old_size < new_size) ? old_size : new_size;
for (unsigned int i = 0; i < copy_size; i++)
{
new_char_ptr[i] = char_ptr[i];
}

free(ptr);

return (new_ptr);
}
