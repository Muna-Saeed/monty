#include "monty.h"
#include <string.h>

/**
 * push - function name
 * @stack: stack list
 * @line_number: line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char str[1000], *st = strtok(NULL, " ");
	int len;
	(void)line_number;
	_concat(str, st, 0);

	if (!stack)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Create a new stack node */

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}



	if (str == NULL)
		return;
	len = strlen(str);
	if (len > 0 && str[len - 1] == '$')
		str[len - 1] = '\0';
	new_node->n = atoi(str);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * pall - function name
 * @stack: stack list
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - function name
 * @stack: stack list
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * pop - function name
 * @stack: stack list
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
/**
 * swap - function name
 * @stack: stack list
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	top->next = second->next;
	if (second->next)
		second->next->prev = top;

	second->prev = NULL;
	second->next = top;
	top->prev = second;

	*stack = second;
}
