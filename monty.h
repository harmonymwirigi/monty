#ifndef __MONTY_H__
#define __MONTY_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \t\n\b"


/* global opcd token */
extern char **opcd_token;

/**
 * struct stack_s - doubly linkled list
 * @n: integer
 * @prev: points to the previous element of a queue or stack
 * @next: points to the next element of a queue ir stack
 *
 * Description: doubly linked list structure
 * for stack, queue, LIFO, FIFO for this project
 **/
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
 * for stack and queues
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTION  */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);


#endif
