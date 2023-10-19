#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * head - function gets the head
 * @stack: the list
 * Return: stack
 */

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

/**
 * top - function gets the head
 * @stack: the list
 * Return: stack
 */
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

/**
 * pchar - function name
 * @stack: stack list
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *topp = top(*stack);
	int n;
	char s[2];

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = topp->n;
	if (n >= 0 && n <= 127)
	{
		s[0] = (char)n;
		s[1] = '\n';
		write(STDOUT_FILENO, s, strlen(s));
		return;
	}
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pstr - function name
 * @stack: stack list
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char s[10000], c;
	int n = 0, num = 0;

	if (*stack == NULL || stack == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	(void)line_number;
	while (current != NULL)
	{
		num = current->n;
		if (num == 0)
			break;
		if (num >= 0 && num <= 127)
		{
			c = (char)num;
			s[n] = c;
			n++;
			current = current->next;
		}
		else
			break;
	}
	s[n] = '\0';
	write(STDOUT_FILENO, s, strlen(s));
	write(STDOUT_FILENO, "\n", 1);
}
