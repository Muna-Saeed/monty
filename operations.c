#include <string.h>
#include <string.h>
#include "monty.h"
#include <unistd.h>
#include <stdio.h>

void sub(stack_t **stack, unsigned int line_number)
{
	char *err = "L%d: can't sub, stack too short\n";
	if (!stack || !(*stack) || !(*stack)->next)
	{
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;

	pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
	char *err = "L%d: can't mul, stack too short\n";
	if (!stack || !(*stack) || !(*stack)->next)
	{
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;

	pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
	char *err = "L%d: can't mod, stack too short\n";
	if (!stack || !(*stack) || !(*stack)->next)
	{
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;

	pop(stack, line_number);
}

void divide(stack_t **stack, unsigned int line_number)
{
	char *err = "L%d: can't div, stack too short\n";
	if (!stack || !(*stack) || !(*stack)->next)
	{
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n != 0)
		(*stack)->next->n /= (*stack)->n;
	else
	{
		err = "L<line_number>: division by zero\n";
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
}
