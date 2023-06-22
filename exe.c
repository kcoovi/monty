#include "monty.h"
/**
 * get_codes - Get codes
 * @opc: opc
 * Return: return
 */
void (*get_codes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
	{"push", push_func},
	{"pall", pall_func},
	{"pint", pint_func},
	{"pop", pop_func},
	{"swap", swap_func},
	{"add", add_func},
	{"nop", nop_func},
	{NULL, NULL}
	};

int i;

for (i = 0; instruct[i].opcode; i++)
{
if (_strcmp(instruct[i].opcode, opc) == 0)
break;
}

return (instruct[i].f);
}
