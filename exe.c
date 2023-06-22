#include "monty.h"

/**
 * get_codes - get opcodes
 * @opc: opcode
 * Return: pointer
 */
void (*get_codes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", mypush},
		{"pall", mypall},
		{"pint", mypint},
		{"pop", mypop},
		{"swap", myswap},
		{"add", myadd},
		{"nop", mynop},
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
