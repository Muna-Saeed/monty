#include "monty.h"
/**
 * rotl - function name
 * @stack: stack list
 * @line_number: line number
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *nd, *t;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		return;
	nd->n = temp->n;
	nd->next = NULL;
	t = temp;
	temp = temp->next;
	free(t);
	if (temp == NULL)
	{
		free(nd);
		return;
	}
	*stack = temp;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = nd;
	nd->prev = temp;
	nd->next = NULL;
}
/**
 * rotr - function name
 * @stack: stack list
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *nd, *t;
	int n = 0;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		n++;
	}
	if (n < 2)
		return;
	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		return;
	nd->n = temp->n;
	nd->next = *stack;
	t = temp;
	temp = temp->prev;
	temp->next = NULL;
	(*stack)->prev = nd;
	*stack = nd;
	free(t);
}
