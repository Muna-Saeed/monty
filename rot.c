#include "monty.h"
/**
 * stack_len - return number of el
 * @stack: teh stack
 * Return: number
 */
int stack_len(stack_t *stack)
{
	int n = 0;

	if (stack == NULL)
		return (0);
	while (stack != NULL)
		stack = stack->prev;
	while (stack != NULL)
	{
		n++;
		stack = stack->prev;
	}
	return (n);
}
/**
 * rotl - function name
 * @stack: stack list
 * @line_number: line number
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *nd, *t, *len = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	if (stack_len(len) == 2)
	{
		swap(stack, line_number);
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
	stack_t *temp = *stack, *nd, *t, *len = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	if (stack_len(len) == 2)
	{
		swap(stack, line_number);
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
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
