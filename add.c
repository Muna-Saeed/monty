#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	pop(stack, line_number);
}
