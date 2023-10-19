#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

stack_t *head(stack_t *stack)
{
	stack_t *ptr = stack;

	if (!ptr)
		return (NULL);

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

stack_t *top(stack_t *stack)
{
	stack_t *ptr = stack;

	if (!ptr)
		return (NULL);

	while (ptr->prev != NULL)
	{
		ptr = ptr->prev;
	}
	return (ptr);
}


void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *topp = top(*stack);
	int n;
	char s[2];

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = topp->n;
	if (n >= 48 && n <= 127)
	{
		s[0] = (char)n;
		s[1] = '\n';
		write(STDOUT_FILENO, s, strlen(s));
		return;
	}
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}


void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char s[10000], c;
	int n = 0;

	if (line_number == 0 || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
	if (stack == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	while(current != NULL)
	{
		c = (char)current->n;
		s[n] = c;
		n++;
		current = current->next;
	}
	s[n] = '\0';
	write(STDOUT_FILENO, s, strlen(s));
	write(STDOUT_FILENO, "\n", 1);
}
