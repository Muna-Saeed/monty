#include "monty.h"

extern int mode;

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Set mode to stack (LIFO) */
	mode = STACK_MODE;
}

void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	/* Set mode to queue (FIFO) */
	mode = QUEUE_MODE;

	/* Swap elements to reflect queue behavior */
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *rear = *stack;
		while (rear->next != NULL)
			rear = rear->next;

		/* Swap top and rear */
		rear->next = *stack;
		(*stack)->prev = rear;
		*stack = rear;
		rear = rear->prev;
		(*stack)->prev = NULL;
		rear->next = NULL;
	}
}
