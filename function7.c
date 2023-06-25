#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Frees memory after it is used
 * @stack: point to the top of a stack or the bottom of a queue
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - set the initial contents of a stack and queue
 * @stack: point to an uninitialied stack
 *
 * Return: success or failure
 */
int init_stack(stack_t **stack)
{
	stack_t *p;

	p = malloc(sizeof(stack_t));
	if (p == NULL)
		return (malloc_error());

	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - confirm if list is a stack or a queue
 * @stack: point to the top  of a stack or the bottom of a queue
 *
 * Return: the corresponding values for the the mode
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
