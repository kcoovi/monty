#include "monty.h"
global_t global_data;

/**
 * free_global_data - free global
 */

void free_global_data(void)
{
free_doubly_linked_list(global_data.head);
free(global_data.buffer);
fclose(global_data.fd);
}
/**
 * initialize_global_data - initialize
 * @file: file
 */
void initialize_global_data(FILE *file)
{
global_data.lifo = 1;
global_data.cont = 1;
global_data.arg = NULL;
global_data.head = NULL;
global_data.fd = file;
global_data.buffer = NULL;
}

FILE *check_input(int argc, char *argv[])
{
FILE *file;

if (argc == 1 || argc > 2)
{
dprintf(2, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");

if (file == NULL)
{
dprintf(2, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

return (file);
}
/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: return
 */
int main(int argc, char *argv[])
{
void (*func)(stack_t **stack, unsigned int line_number);
FILE *file;
size_t buffer_size = 256;
ssize_t line_size = 0;
char *line_tokens[2] = {NULL, NULL};

file = check_input(argc, argv);
initialize_global_data(file);
line_size = getline(&global_data.buffer, &buffer_size, file);

while (line_size != -1)
{
line_tokens[0] = _strtoky(global_data.buffer, " \t\n");

if (line_tokens[0] && line_tokens[0][0] != '#')
{
func = get_codes(line_tokens[0]);

if (!func)
{
dprintf(2, "L%u: ", global_data.cont);
dprintf(2, "Error %s\n", line_tokens[0]);
free_global_data();
exit(EXIT_FAILURE);
}

global_data.arg = _strtoky(NULL, " \t\n");
func(&global_data.head, global_data.cont);
}

line_size = getline(&global_data.buffer, &buffer_size, file);
global_data.cont++;
}

free_global_data();

return (0);
}
