#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and function
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, content
 * @arg: value
 * @file: pointer to monty file
 * @content: content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;
extern bus_t t_bus;

int exec(char *content, stack_t **head, unsigned int counter, FILE *file);
char *clean_line(char *content);
void func_push(stack_t **head, unsigned int number);
void func_pall(stack_t **head, unsigned int number);
void func_pint(stack_t **head, unsigned int number);
void free_stack(stack_t *head);
void func_pop(stack_t **head, unsigned int counter);
void func_add(stack_t **head, unsigned int counter);
void func_nop(stack_t **head, unsigned int counter);
void func_swap(stack_t **head, unsigned int counter);
void func_div(stack_t **head, unsigned int counter);
void func_sub(stack_t **head, unsigned int counter);
void func_mod(stack_t **head, unsigned int counter);
void func_mul(stack_t **head, unsigned int counter);
void func_pstr(stack_t **head, unsigned int counter);
void func_pchar(stack_t **head, unsigned int counter);
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void func_rotl(stack_t **head, unsigned int counter);
void func_stack(stack_t **head, unsigned int counter);
void func_queue(stack_t **head, unsigned int counter);
void add_queue(stack_t **head, int n);
void add_node(stack_t **head, int n);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);

#endif
