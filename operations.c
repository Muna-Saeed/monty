#include <string.h>
#include <string.h>
#include "monty.h"
#include <unistd.h>
#include <stdio.h>

void sub(stack_t **stack, unsigned int line_number)
{
	char err[10000], digit[1000], *str;


	string_digit(line_number, digit);
	_concat(err, "L:", 0);
	_concat(err, digit, strlen(digit));

	if (!stack || !(*stack) || !(*stack)->next)
	{
		str = ": can't sub, stack too short\n";
		_concat(err, str, strlen(err));
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;

	pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
	char err[10000], digit[1000], *str;

	string_digit(line_number, digit);
	_concat(err, "L:", 0);
	_concat(err, digit, strlen(digit));

	if (!stack || !(*stack) || !(*stack)->next)
	{
		str = ": can't mul, stack too short\n";
		_concat(err, str, strlen(err));
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;

	pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
	char err[10000], digit[1000], *str;
	int n;

	string_digit(line_number, digit);
	_concat(err, "L:", 0);
	_concat(err, digit, strlen(digit));
	if (!stack || !(*stack) || !(*stack)->next)
	{
		str = ": can't mod, stack too short\n";
		_concat(err, str, strlen(err));
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n != 0)
	{
		n = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n % n;
	}
	else
	{
		str = ": division by zero\n";
		_concat(err, str, strlen(err));
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	
}

void divide(stack_t **stack, unsigned int line_number)
{
	char err[10000], digit[1000], *str;
	int n;

	string_digit(line_number, digit);
	_concat(err, "L:", 0);
	_concat(err, digit, strlen(digit));
	if (!stack || !(*stack) || !(*stack)->next)
	{
		str = ": can't div, stack too short\n";
		_concat(err, str, strlen(err));
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n != 0)
	{
		n = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n / n;
	}
	else
	{
		str = ": division by zero\n";
		_concat(err, str, strlen(err));
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}

}
