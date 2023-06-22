#include "monty.h"
/**
 * free_memory - free mem
 */
stack_t *head = NULL;
char *buffer = NULL;

void free_memory(void)
{
free_dlistint(head);
free(buffer);
}
/**
 * initialize - init
 * @fd: fd
 */
void initialize(FILE *fd)
{
head = NULL;
buffer = NULL;
start_vglo(fd);
}
/**
 * validate_input - validation
 * @argc: argc
 * @argv: argc
 * Return: fd
 */
FILE *validate_input(int argc, char *argv[])
{
FILE *fd;

if (argc != 2)
{
dprintf(2, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fd = fopen(argv[1], "r");

if (fd == NULL)
{
dprintf(2, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

return (fd);
}
/**
 * main - main
 * @argc: argc
 * @argv: argc
 * Return: return
 */
int main(int argc, char *argv[])
{
void (*f)(stack_t **stack, unsigned int line_number);
FILE *fd;
size_t size = 256;
ssize_t nlines = 0;
char *lines[2] = {NULL, NULL};

fd = validate_input(argc, argv);
initialize(fd);
nlines = getline(&buffer, &size, fd);
while (nlines != -1)
{
lines[0] = _strtoky(buffer, " \t\n");
if (lines[0] && lines[0][0] != '#')
{
f = get_opcodes(lines[0]);
if (!f)
{
dprintf(2, "L%u: ", vglo.cont);
dprintf(2, "unknown instruction %s\n", lines[0]);
free_memory();
exit(EXIT_FAILURE);
}
vglo.arg = _strtoky(NULL, " \t\n");
f(&head, vglo.cont);
}
nlines = getline(&buffer, &size, fd);
vglo.cont++;
}

free_memory();

return (0);
}
