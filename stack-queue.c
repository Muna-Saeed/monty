#include "monty.h"


/**
 * stack - function name
 * @stack: stack list
 * @line_number: line number
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Set mode to stack (LIFO) */

}
/**
 * queue - function name
 * @stack: stack list
 * @line_number: line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	/* Set mode to queue (FIFO) */


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
