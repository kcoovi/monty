#ifndef MONTY_H
#define MONTY_H

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void mypush(stack_t **stack, unsigned int line_number);
void mypall(stack_t **stack, unsigned int line_number);
void mypint(stack_t **stack, unsigned int line_number);
void mypop(stack_t **stack, unsigned int line_number);
void myswap(stack_t **stack, unsigned int line_number);
void myadd(stack_t **stack, unsigned int line_number);
void mynop(stack_t **stack, unsigned int line_number);
void *custom_calloc(unsigned int num_elements, unsigned int element_size);
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void node(stack_t **stack, int n);
void (*get_codes(char *opc))(stack_t **stack, unsigned int line_number);
#endif
