#include "monty.h"
/**
 * queue_stack - function name
 * @n: int
 * Return: int
 */
int queue_stack(int n)
{
	static int mode = 1;

	if (n == 0)
		return (mode);
	mode = n;
	return (mode);
}

/**
 * stack - function name
 * @stack: stack list
 * @line_number: line number
*/
void stack(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		return;
	}
	rotl(stack, line_number);
}
/**
 * queue - function name
 * @stack: stack list
 * @line_number: line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	rotr(stack, line_number);
	queue_stack(2);
}
