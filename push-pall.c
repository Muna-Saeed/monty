#include "monty.h"
#include <string.h>
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;
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

	/* remove line_number replace it to  strtok */
	new_node->n = atoi(strtok(NULL, " "));
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

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

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

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
