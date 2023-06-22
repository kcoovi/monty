#include "monty.h"

/**
 * get_opcodes - get codes
 * @opc: opcode
 * Return: return
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", mypush},
		{"pall", mypall},
		{"pint", mypint},
		{"pop", mypop},
		{"swap", myswap},
		{"queue", myqueue},
		{"stack", mystack},
		{"add", myadd},
		{"nop", mynop},
		{"sub", mysub},
		{"mul", mymul},
		{"div", mydiv},
		{"mod", mymod},
		{"pchar", mypchar},
		{"pstr", mypstr},
		{"rotl", myrotl},
		{"rotr", myrotr},
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
