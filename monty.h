#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;


void mypush(stack_t **stack, unsigned int line_number);
void mypall(stack_t **stack, unsigned int line_number);
void mypint(stack_t **doubly, unsigned int cline);
void mypop(stack_t **doubly, unsigned int cline);
void myswap(stack_t **doubly, unsigned int cline);
void myqueue(stack_t **doubly, unsigned int cline);
void mystack(stack_t **doubly, unsigned int cline);
void myadd(stack_t **doubly, unsigned int cline);
void mynop(stack_t **doubly, unsigned int cline);
void mysub(stack_t **doubly, unsigned int cline);
void mydiv(stack_t **doubly, unsigned int cline);
void mymul(stack_t **doubly, unsigned int cline);
void mymod(stack_t **doubly, unsigned int cline);
void mypchar(stack_t **doubly, unsigned int cline);
void mypstr(stack_t **doubly, unsigned int cline);
void myrotl(stack_t **doubly, unsigned int cline);
void myrotr(stack_t **doubly, unsigned int cline);
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void free_vglo(void);

#endif
