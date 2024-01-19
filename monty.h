#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define NPTRS(n) (n * sizeof(void *))
#define NCHARS(n) (n * sizeof(char))
#define bool int
#define true 1
#define false 0
#define STACK 1
#define QUEUE 0
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct ada - all my clobal variables
 *
 * @mode: the mode
 * @result: the result
 * @status: the status
 * @string: the string
 * @arguments: the arguments
 */
typedef struct ada
{
	int mode;
	char **result;
	char **arguments;
	char *string;
	int status;
} a;
/* GLOBAL VARIABLES */
extern int mode;
extern char **result;
extern int status;
extern char *string;
extern char **arguments;

/* OPCODES */
void op_push(stack_t **head, unsigned int line_no);
void op_pall(stack_t **head, unsigned int line_no);
void op_pint(stack_t **head, unsigned int line_no);
void op_pop(stack_t **head, unsigned int line_no);
void op_swap(stack_t **head, unsigned int line_no);
void op_add(stack_t **head, unsigned int line_no);
void op_nop(stack_t **head, unsigned int line_no);
void op_sub(stack_t **head, unsigned int line_no);
void op_div(stack_t **head, unsigned int line_no);
void op_mul(stack_t **head, unsigned int line_no);
void op_mod(stack_t **head, unsigned int line_no);
void op_pchar(stack_t **head, unsigned int line_no);
void op_pstr(stack_t **head, unsigned int line_no);
void op_rotr(stack_t **head, unsigned int line_no);
void op_rotl(stack_t **head, unsigned int line_no);
void op_stack(stack_t **head, unsigned int line_no);
void op_queue(stack_t **head, unsigned int line_no);

/* UTILITIES */
bool appendStr(char ***arr, size_t *size, char *str, int index);
char **split(char *string, char *delimiter);
void *_realloc(void *ptr, size_t osize, size_t nsize);
char *pen(char *filename);
void (*get_opcode(char *s))(stack_t **, unsigned int);
void free_stack(stack_t *h);
void cleanup(stack_t *h);
int check(char *s);
int checkatoi(char *s);

#endif /*MONTY_H */
